#include "main.h"
using namespace std;
namespace fs=std::filesystem;
int main(){
    vector <DNA_info_t> genome_isolate;
    fs::path entry="./data/demo/sequence.fasta";
    genome_isolate=FastaReader(entry);
    int kmer_size=21;
    unordered_map <uint64_t, uint64_t> kmer_count;
    kmer_count=KmerCounter(genome_isolate,kmer_size);
    return 0;
}