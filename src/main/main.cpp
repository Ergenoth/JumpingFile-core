#include <iostream>
#include "testClass.h"
#include <boost/program_options.hpp>

namespace po = boost::program_options;

int main(int argc, char *argv[]) {
    po::options_description desc("Allowed options");
    desc.add_options()
        ("Help", "Show help message")
        ("Cobol path", "Path to a single cobol module or a directory of cobol modules"); 
        ("Cobol configuration", "Path to the configuration/implementation of the converter");

    std::cout << argc << std::endl;
    for (size_t i = 0; i < argc; i++)
    {
        std::cout << argv[i] << std::endl;
    }
    
    return EXIT_SUCCESS;
}