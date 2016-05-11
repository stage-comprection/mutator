#pragma once

#include <iostream>
#include <random>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>



class Mutator {

    public:

        float mu;
        std::mt19937 gen;

        std::ofstream logsFile;

        const char bases[4] {'A', 'C', 'G', 'T'};
        std::uniform_int_distribution<> baseDistribution;

        Mutator(float m): gen((std::random_device())()), baseDistribution(0,3) { mu = m; logsFile.open("mutator.log"); }

        std::string mutate(std::string& seq);

};
