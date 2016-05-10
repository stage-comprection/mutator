#pragma once

#include "mutator.h"


class Readator {

    public:

        std::ifstream referenceFile;
        std::ofstream outputFile;
        std::ofstream outputFile_noError;

        uint readSize;
        uint coverage;

        std::vector<std::string> contigs;
        uint readCounter;

        Mutator mutator;

        Readator(std::string rf, std::string of, uint s, uint c, float mu) : mutator(mu) {

            referenceFile.open(rf);
            outputFile.open(of);
            outputFile_noError.open(of + "_noError");
            readSize = s;
            coverage = c;
            readCounter = 0;
        }

        void fillContigs();
        void readate();

};
