#include "main.h"

using namespace std;
namespace fs=std::filesystem;
int main(int argc,char* argv[]){
    vector <DNA_info_t> genome_isolate,genome_mutant;
    cli_parameter parameter_set;
    if(help_parser(argc,argv)){
        cerr<<help_line;
        return 0;
    }
    if (!cli_parser(argc, argv, parameter_set)) {
        cerr<<"ERROR: Invalid arguments.\n\n";
        cerr<<help_line;

        return EXIT_FAILURE;
    }
    genome_isolate=Fasta_reader(parameter_set.ref_des);
    if(genome_isolate.empty()) return EXIT_FAILURE;
    genome_mutant=Fasta_reader(parameter_set.mutant_des);
    if(genome_mutant.empty()) return EXIT_FAILURE;
    unordered_map <uint64_t, uint64_t> kmer_count;
    unordered_map <uint64_t, vector<uint64_t>> rare_kmer_position;
    kmer_count=build_kmers_index(genome_isolate,parameter_set.kmer_size);
    rare_kmer_position=find_rare_kmers(genome_mutant[0],parameter_set.kmer_size,kmer_count,genome_isolate.size(),parameter_set);

    const string& seq = genome_mutant[0].seq;
    int size = seq.length();
    vector<int> frequent(size, 0);
    for (const auto& [kmer, position] : rare_kmer_position) {
        for(auto & pos : position){
            int start = pos - parameter_set.kmer_size;
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
        bool selected = (i < size && frequent[i] >= parameter_set.kmer_size);
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
    return 0;
}