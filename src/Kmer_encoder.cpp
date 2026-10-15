#include "Kmer_encoder.h"
using namespace std;

static int parser(char nucleotide){
    switch(nucleotide){
        case 'A': return 0b00;
        case 'C': return 0b01;
        case 'G': return 0b10;
        case 'T': return 0b11;
        default : return 0b00;
    }
}

unordered_map <uint64_t, uint64_t> KmerCounter(vector <DNA_info_t> genome_isolate, int kmer_size){
    unordered_map <uint64_t, uint64_t> kmer_count;
    uint64_t kmer_mask=(kmer_mask<<(kmer_size*2))-1;
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
    
}

