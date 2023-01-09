#include <iostream>
#include <string>
#include <boost/program_options.hpp>

namespace po = boost::program_options;

int main(int argc, char const *argv[])
{
    // Declare the supported options.
    po::options_description desc("Allowed options");
    desc.add_options()
        ("help,h", "produce help message")
        ("level", po::value<int>(), "set level of game 1-3")
        ("max", po::value<int>(), "set max value of a number for guess")
    ;

    po::variables_map vm;
    po::store(po::parse_command_line(argc, argv, desc), vm);
    po::notify(vm);  

    if (vm.count("help")) {
        std::cout << desc << "\n";
        return 1;
    }

    // if (vm.count("compression")) {
    //     std::cout << "Compression level was set to " << vm["compression"].as<int>() << ".\n";
    // } else {
    //     std::cout << "Compression level was not set.\n";
    // }

    return 0;
}

