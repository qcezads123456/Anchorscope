#include "Fasta_reader.h"
using namespace std;
namespace fs = std::filesystem;

DNA_info_t FastaReader(const fs::path entry){
    ifstream file(entry);
    if (!file.is_open()) {
        cerr << "Cannot open file!" << endl;
        return {};
    }
    DNA_info_t info;
    string line;
    getline(file, info.title);
    while(getline(file,line)){
        info.seq+=line;
    }
    return info;
}