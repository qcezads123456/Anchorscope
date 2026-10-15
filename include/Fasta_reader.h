#ifndef FASTA_READER_H
#define FASTA_READER_H

#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include <filesystem>
#include <vector>

typedef struct DNA_info_t{
    std::string title;
    std::string seq;
}DNA_info_t;

std::vector <DNA_info_t> FastaReader(const std::filesystem::path entry);

#endif

