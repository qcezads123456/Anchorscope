#ifndef KMER_ENCODER_H
#define KMER_ENCODER_H

#include "Fasta_reader.h"
#include "decoder.h"
#include <string>
#include <iostream>
#include <unordered_map>
#include <sstream>
#include <cstdint>

std::unordered_map <uint64_t, uint64_t> KmerCounter(const std::vector <DNA_info_t> &genome_isolate,const int kmer_size);
std::unordered_map <uint64_t, uint64_t> mutant_KmerCounter  
(const DNA_info_t &genome_mutant, int kmer_size,const std::unordered_map<uint64_t,uint64_t> &kmer_count,int isolate_amount);
#endif
