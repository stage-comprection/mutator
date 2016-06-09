#include "readator.h"


void Readator::fillContigs() {

    std::string line;

    while(std::getline(this->referenceFile, line)){

        if (line[0] != '>') {

            this->contigs.push_back(line);

        }
    }
}



void Readator::mutate(std::string& r) {

    char b;

    for (uint i=0; i<r.size(); ++i){

        if (this->errorDistribution(this->gen) == 0){

            do {

                b = this->bases[this->baseDistribution(this->gen)];

            } while(b == r.at(i));

            r.at(i) = b;
        }
    }

}



void Readator::readate() {

    std::cout << " - Initializing random device" << std::endl;

    uint s = this->readSize;

    std::cout << " - Looping through contigs (total : " << contigs.size() << ")" << std::endl;

    for (uint i=0; i<contigs.size(); ++i) {

        std::cout << "   * Contig " << i << std::endl;
        uint n = this->contigs[i].size();
        std::cout << "      + Size = " << n << std::endl;
        std::cout << "      + Generating reads" << std::endl;

        if (this->readSize == 0) {

            s = n;
        }

        uint nReads =  (uint) this->coverage * n / s ; // number of reads = coverage * ref size / read size

        std::uniform_int_distribution<> readDistribution(0, n - s);

        uint startPos = 0;
        std::string read;

        for (uint j=0; j<nReads; j++) {

            startPos = readDistribution(this->gen);

            read = this->contigs[i].substr(startPos, s);

            this->outputFile_noError << ">" << this->readCounter << "\n" << read << "\n";

            this->mutate(read);

            this->outputFile << ">" << this->readCounter << "\n" << read << "\n";

            ++this->readCounter;

        }

    }

    std::cout << "Done" << std::endl;

}
