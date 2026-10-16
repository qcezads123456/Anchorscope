#include "main.h"
using namespace std;
namespace fs=std::filesystem;
int main(){
    vector <DNA_info_t> genome_isolate,genome_mutant;
    fs::path entry="./data/demo/sequence.fasta";
    genome_isolate=Fasta_reader(entry);
    entry="./data/demo/sequence_mutant.fasta";
    genome_mutant=Fasta_reader(entry);
    int kmer_size=21;
    unordered_map <uint64_t, uint64_t> kmer_count;
    unordered_map <uint64_t, vector<uint64_t>> rare_kmer_position;
    kmer_count=build_kmers_index(genome_isolate,kmer_size);
    rare_kmer_position=find_rare_kmers(genome_mutant[0],kmer_size,kmer_count,genome_isolate.size());

    /*const string& seq = genome_mutant[0].seq;
    int size = seq.length();
    vector<int> frequent(size, 0);
    for (const auto& [kmer, position] : rare_kmer_position) {
        for(auto & pos : position){
            int start = pos - kmer_size;
            int end = pos;
            if (start < 0 || end > size)
            continue;

            for (int i = start; i < end; i++) {
                frequent[i]++;
            }
        }
    }
    int start = -1;
    for (int i = 0; i <= size; i++) {
        bool selected = (i < size && frequent[i] >= 21);
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
    cout<<endl;
    */
    return 0;
}