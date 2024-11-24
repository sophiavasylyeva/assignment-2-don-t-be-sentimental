#include <iostream>
#include <cstdio>
#include "Training.h"
#include "Testing.h"
#include "Validation.h"

//main class - about 5 lines of code

int main(int argc, char** argv)
{  
    if (argc != 6) {
        std::cout << "Wrong number of command line arguments" << std::endl;
        exit(1);
    }
    //std::cout << "I will be a sentiment analyzer!" << std::endl;
    Training trainer(argv[1]);
    Testing tester(trainer.Train(), argv[2]);
    Validation validator(tester.Test(), argv[3], argv[4], argv[5]); //calls classes for execution
    return 0;
}