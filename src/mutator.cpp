#include "mutator.h"

#define LOGPRINT (this->logsFile <<  __FILE__ << " : " << __LINE__ << "\n");

std::string Mutator::mutate(std::string& seq){

    std::string seqMutated = seq;

    uint64_t b;
    char c;

    uint n = seq.size();

    std::cout << n << std::endl;

    std::uniform_int_distribution<> errorDistribution(0, n-1);

    std::vector<uint64_t> mutatedBases;
    mutatedBases.resize(n*this->mu);

    for (uint i=0; i < mutatedBases.size(); ++i){

        do {

            b = errorDistribution(this->gen);

        } while(std::find(mutatedBases.begin(), mutatedBases.end(), b) != mutatedBases.end());

        mutatedBases.at(i) = b;

        do {

            c = this->bases[this->baseDistribution(gen)];

        } while(c == seq.at(b));

        seqMutated.at(b) = c;
    }

    mutatedBases.resize(0);

    return seqMutated;
}
