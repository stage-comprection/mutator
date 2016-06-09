#include "readator.h"


void Readator::fillContigs() {

    std::string line;

    while(std::getline(this->referenceFile, line)){

        if (line[0] != '>') {

            this->contigs.push_back(line);

        }
    }
}


void Readator::readate() {

    std::cout << " - Initializing random device" << std::endl;

    uint s = this->readSize;
    std::string mutatedContig;

    std::cout << " - Looping through contigs (total : " << contigs.size() << ")" << std::endl;

    for (uint i=0; i<contigs.size(); ++i) {

        std::cout << "   * Contig " << i << std::endl;
        uint n = this->contigs[i].size();
        std::cout << "      + Size = " << n << std::endl;
        std::cout << "      + Generating reads" << std::endl;

        for (uint j=0; j<this->coverage; ++j){

            mutatedContig = this->mutator.mutate(contigs[i]);

            if (this->readSize == 0) {

                s = n;
            }

            uint nReads =  (uint) n / s ;

            std::uniform_int_distribution<> readDistribution(0, n - s);

            uint startPos = 0;
            std::string read, mutatedRead;

            for (uint j=0; j<nReads; j++) {

                startPos = readDistribution(this->gen);

                read = this->contigs[i].substr(startPos, s);

                mutatedRead = mutatedContig.substr(startPos, s);

                this->outputFile << ">" << this->readCounter << "\n" << mutatedRead << "\n";

                this->outputFile_noError << ">" << this->readCounter << "\n" << read << "\n";

                ++this->readCounter;
            }


        }

    }

    std::cout << "Done" << std::endl;

}
