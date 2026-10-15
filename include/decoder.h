#ifndef DECODER_H
#define DECODER_H

#include <string>
#include <iostream>
#include <cstdint>

int index_decode(int isolate_amount,uint64_t key);
std::string kmer_decode(int kmer_size,uint64_t kmer);

#endif