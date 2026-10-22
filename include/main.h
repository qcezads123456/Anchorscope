#ifndef MAIN_H
#define MAIN_H

#include <iostream>
#include <fstream>
#include <filesystem>
#include <vector>
#include <stdexcept>
#include "Fasta_reader.h"
#include "result_processor.h"
#include "decoder.h"
#include "cli.h"
#define help_line \
             "Usage:\n"\
             "  project_name -r <reference.fasta> -m <mutant.fasta> [options] \n\n"\
             "Required:\n"\
             "  -r, --reference        Reference FASTA file \n"\
             "  -m, --mutant           Target FASTA file\n\n"\
             "Options:\n"\
             "  -k, --kmer-size        K-mer size (1-31)\n"\
             "  -mrf, --max-ref-freq   Maximum reference frequency [0.0, 1.0)\n"\
             "  -ct, --coverage        Minimum rare k-mer coverage (1 to k-mer size)\n";
#endif