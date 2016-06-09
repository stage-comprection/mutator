#pragma once

#include <iostream>
#include <random>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>

class Readator {

    public:

        // File parameters
        std::ifstream referenceFile;
        std::ofstream outputFile;
        std::ofstream outputFile_noError;

        // Reads parameters
        uint readSize;
        uint coverage;

        // Storage
        std::vector<std::string> contigs;
        uint readCounter;

        // Alphabet for mutations
        const char bases[4] {'A', 'C', 'G', 'T'};

        // Random devices / distributions
        std::mt19937 gen;
        std::uniform_int_distribution<> errorDistribution;
        std::uniform_int_distribution<> baseDistribution;

        // Constructor
        Readator(std::string rf, std::string of, uint s, uint c, float mutationRate) :
            gen((std::random_device())()), errorDistribution(0, 1/mutationRate-1), baseDistribution(0,3) {

            referenceFile.open(rf);
            outputFile.open(of);
            outputFile_noError.open(of + "_noError");
            readSize = s;
            coverage = c;
            readCounter = 0;

        }

        void fillContigs();
        void readate();
        void mutate(std::string& r);
};
