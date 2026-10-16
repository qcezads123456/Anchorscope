#include "main.h"
using namespace std;
namespace fs=std::filesystem;
int main(){
    vector <DNA_info_t> genome_isolate,genome_mutant;
    fs::path entry="./data/demo/sequence.fasta";
    genome_isolate=FastaReader(entry);
    entry="./data/demo/sequence_mutant.fasta";
    genome_mutant=FastaReader(entry);
    int kmer_size=21;
    unordered_map <uint64_t, uint64_t> kmer_count;
    unordered_map <uint64_t, uint64_t> low_frequency_kmer;
    kmer_count=KmerCounter(genome_isolate,kmer_size);
    low_frequency_kmer=mutant_KmerCounter(genome_mutant[0],kmer_size,kmer_count,genome_isolate.size());
    for(auto &[kmer,key] : low_frequency_kmer){
        //if(index_decode(genome_isolate.size(),key)>16){
          //  cout<<kmer_decode(kmer_size,kmer)<<endl;
        //}
        cout<<kmer_decode(kmer_size,kmer)<<" "<<key<<endl;
    }
    return 0;
}