#include "Kmer_encoder.h"
using namespace std;

static int parser(char nucleotide){
    switch(nucleotide){
        case 'A': return 0b00;
        case 'C': return 0b01;
        case 'G': return 0b10;
        case 'T': return 0b11;
        default : return 0b111;
    }
}

/*unordered_map <uint64_t, uint64_t> KmerCounter(vector <DNA_info_t> genome_isolate, int kmer_size){
    unordered_map <uint64_t, uint64_t> kmer_count;
    uint64_t kmer_mask=1ULL;
    kmer_mask=(kmer_mask<<(kmer_size*2))-1;
    for(size_t i=0;i<genome_isolate.size();i++){
        uint64_t encode_DNA=0;
        for(int s=0; s<kmer_size; s++){
            if(s>0){
                encode_DNA<<=2;
            }
            encode_DNA|=parser(genome_isolate[i].seq[s]);
        }
        uint64_t isolate_index=1ULL<<i;
        kmer_count[encode_DNA] |= isolate_index;
        stringstream ss(genome_isolate[i].seq.substr(kmer_size));
        char ch;
        while(ss >> ch) {
            encode_DNA <<= 2;
            encode_DNA |= parser(ch);
            encode_DNA &=kmer_mask;
            kmer_count[encode_DNA] |= isolate_index;
        }
    }
    return kmer_count;
    
}*/

unordered_map <uint64_t, uint64_t> KmerCounter   
(const vector <DNA_info_t> &genome_isolate,const int kmer_size){
    unordered_map <uint64_t, uint64_t> kmer_count;
    uint64_t kmer_mask=1ULL;
    kmer_mask=(kmer_mask<<(kmer_size*2))-1;
    for(size_t i=0;i<genome_isolate.size();i++){
        stringstream ss(genome_isolate[i].seq);
        char ch;
        int count=0;
        uint64_t encode_DNA=0;
        uint64_t isolate_index=1ULL<<i;
        while(!ss.eof()){
            if(count!= kmer_size){
                
                while(count!=kmer_size && ss>>ch ){
                    if(parser(ch)!=0b111){
                        count++;
                        if(count>0){
                            encode_DNA<<=2;
                        }
                        encode_DNA|=parser(ch);
                    }
                    else{                   //skip nucleotide which can't encode
                        count=0;
                        encode_DNA=0;
                        break;
                    }
                }
                if(count==kmer_size){
                    uint64_t isolate_index=1ULL<<i;
                    kmer_count[encode_DNA] |= isolate_index;
                }
            }
            else{
                while(ss>>ch){
                    if(parser(ch)==0b111){
                        count=0;
                        encode_DNA=0;
                        break;
                    }
                    encode_DNA <<= 2;
                    encode_DNA |= parser(ch);
                    encode_DNA &=kmer_mask;
                    kmer_count[encode_DNA] |= isolate_index;
                }
            }
        }
    }
    return kmer_count;
}

unordered_map <uint64_t, uint64_t> mutant_KmerCounter   //[kmer_encode, position(actual value)]
(const DNA_info_t &genome_mutant, int kmer_size,const unordered_map<uint64_t,uint64_t> &kmer_count,int isolate_amount){  
    unordered_map <uint64_t, uint64_t> low_frequency_kmer;
    uint64_t kmer_mask=1ULL;
    kmer_mask=(kmer_mask<<(kmer_size*2))-1;
    int count=0;
    uint64_t encode_DNA=0;
    stringstream ss(genome_mutant.seq);
    char ch;
    uint64_t position=0;
    while(!ss.eof()){
        if(count!= kmer_size){    
            while(count!=kmer_size && ss>>ch){
                if(parser(ch)!=0b111){
                    count++;
                    position++;
                    if(count>0){
                        encode_DNA<<=2;
                    }
                    encode_DNA|=parser(ch);
                }
                else{                   //skip nucleotide which can't encode
                    count=0;
                    encode_DNA=0;
                    position++;
                    break;
                }
            }
            if(count==kmer_size){
                if(kmer_count.find(encode_DNA)!=kmer_count.end()){
                    if(index_decode(isolate_amount,encode_DNA)<=0){
                        low_frequency_kmer[encode_DNA]=position;
                    }
                }
                else{
                    low_frequency_kmer[encode_DNA]=position;
                }
            }
        }
        else{
            while(ss>>ch){
                if(parser(ch)==0b111){
                    count=0;
                    encode_DNA=0;
                    position++;
                    break;
                }
                encode_DNA <<= 2;
                encode_DNA |= parser(ch);
                encode_DNA &=kmer_mask;
                position++;
                if(kmer_count.find(encode_DNA)!=kmer_count.end()){
                    if(index_decode(isolate_amount,encode_DNA)<=0){
                        low_frequency_kmer[encode_DNA]=position;
                    }
                }
                else{
                    low_frequency_kmer[encode_DNA]=position;
                }
            }
        }
    }
    return low_frequency_kmer;
}