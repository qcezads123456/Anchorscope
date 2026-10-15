#ifndef KMER_ENCODER_H
#define KMER_ENCODER_H

#include "Fasta_reader.h"
#include <string>
#include <iostream>
#include <unordered_map>
#include <sstream>
#include <cstdint>

std::unordered_map <uint64_t, uint64_t> KmerCounter(std::vector <DNA_info_t> genome_isolate, int kmer_size);

#endif
