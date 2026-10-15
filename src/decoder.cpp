#include "decoder.h"
using namespace std;

int index_decode(int isolate_amount,uint64_t key){
    uint64_t mask=1ULL;
    int count=0;
    for(int i=0;i<isolate_amount;i++){
        if(i>0) key>>=1;
        count+=(key&mask);
    }
    return count;
}

string kmer_decode(int kmer_size,uint64_t kmer){
    uint64_t mask=1ULL;
    mask=(mask<<1)+1;
    string return_kmer;
    for(int i=kmer_size;i>0;i--){
        char ch;
        if(i!=kmer_size) kmer>>=2;
        switch(kmer& mask){
            case 0b00 :
                ch= 'A';
                break;
            case 0b01:
                ch= 'C';
                break;
            case 0b10:
                ch= 'G';
                break;
            case 0b11:
                ch= 'T';
                break;
            default:
                break;
        }
        return_kmer+=ch;
    }
    return return_kmer;   
}