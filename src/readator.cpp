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

    std::mt19937 gen((std::random_device())());

    uint s = this->readSize;

    for (uint i=0; i<contigs.size(); ++i) {

        uint n = this->contigs[i].size();

        if (this->readSize == 0) {

            s = n;
        }

        uint nReads =  n * this->coverage / s ;
        std::uniform_int_distribution<> readDistribution(0, n - s);

        uint startPos = 0;
        std::string read;

        for (uint j=0; j<nReads; j++) {

            startPos = readDistribution(gen);

            read = this->contigs[i].substr(startPos, s);
            this->outputFile << ">" << this->readCounter << "\n" << this->mutator.mutate(read) << "\n";
            this->outputFile_noError << ">" << this->readCounter << "\n" << read << "\n";
            ++this->readCounter;
        }

    }

}
