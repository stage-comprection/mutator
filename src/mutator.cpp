#include "mutator.h"


std::string Mutator::mutate(std::string seq){

    uint b;
    char c;

    uint n = seq.size();

    std::vector<uint> mutatedBases;
    std::uniform_int_distribution<> errorDistribution(0, n-1);

    mutatedBases.resize(n*this->mu);

    for (uint i=0; i<n*this->mu; ++i){

        do {

            b = errorDistribution(this->gen);

        } while(std::find(mutatedBases.begin(), mutatedBases.end(), b) != mutatedBases.end());

        mutatedBases[i] = b;

        do {

            c = this->bases[this->baseDistribution(gen)];

        } while(c == seq[b]);

        seq[b] = c;
    }

    return seq;
}
