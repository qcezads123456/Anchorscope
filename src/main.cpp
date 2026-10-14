#include "main.h"
using namespace std;
namespace fs=std::filesystem;
int main(){
    DNA_info_t origin;
    //DNA_info_t origin_var;
    fs::path entry="./data/demo/sequence.fasta";
    origin=FastaReader(entry);
    cout<<origin.seq<<endl;
    return 0;
}