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

    /*const string& seq = genome_mutant[0].seq;
    int size = seq.length();
    vector<int> frequent(size, 0);
    for (const auto& [kmer, position] : low_frequency_kmer) {
        int start = position - kmer_size;
        int end = position;
        if (start < 0 || end > size)
            continue;

        for (int i = start; i < end; i++) {
            frequent[i]++;
        }
    }
    int start = -1;
    for (int i = 0; i <= size; i++) {
        bool selected = (i < size && frequent[i] >= 19);
        if (selected && start == -1) {
            start = i;
        }
        if (!selected && start != -1) {
            cout << start << "-" << i - 1 << " "
                << seq.substr(start, i - start)
                << endl;
            start = -1;
        }
    }
    for(int i=0;i<size;i++){
        cout<<frequent[i]<<" ";
    }
    cout<<endl;*/
    return 0;
}