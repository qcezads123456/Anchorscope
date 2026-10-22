#ifndef FASTA_READER_H
#define FASTA_READER_H

#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <vector>

typedef struct DNA_info_t{
    std::string header;
    std::string seq;
}DNA_info_t;

std::vector <DNA_info_t> Fasta_reader(const std::filesystem::path entry);

#endif

