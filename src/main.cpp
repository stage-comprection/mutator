#include "readator.h"

int main(int argc, char *argv[]) {

    if (argc < 4 or argc > 6){

        std::cout << "Usage : mutator reference_file output_file mutation_rate (coverage read_size) " << std::endl;
        return -1;
    }

    std::string rf = argv[1];
    std::string of = argv[2];
    float mu = std::stof(argv[3]);
    uint s = 0;
    uint c = 0;

    if (argc == 6){

        c = std::stoi(argv[4]);
        s = std::stoi(argv[5]);

    } else {

        c = 1;
        s = 0;
    }


    Readator readator(rf, of, s, c, mu);

    readator.fillContigs();

//    for (uint i=0; i<readator.contigs.size(); ++i) std::cout<<readator.contigs[i] << "\n";

    readator.readate();

    return 0;
}
