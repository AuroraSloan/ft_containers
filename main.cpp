#include "tests/VectorTests.cpp"
#include "tests/IteratorTests.cpp"
#include "tests/AlgorithmTests.cpp"
#include "tests/UtilityTests.cpp"
#include "ft_containers.hpp"
#include <iostream>
#include <cstring> //strcmp // find better way

bool    str_equal(char *A, std::string B) {
    return (strcmp(A, B.c_str()) == 0 || strcmp(A, "all") == 0);
}

bool    valid_arg(std::string arg) {
    return (arg == "vector" || arg == "stack" || arg == "map" || arg == "iterator" || arg == "all");
}

void print_usage(void) {
    std::cout << "usage: ./ft_containers <test name>\n"
    << "available tests:\nvector\nstack\nmap\n";

    exit(EXIT_FAILURE);
}


/*int main(void) {
    ft::pair<std::string, double> A("abc", 33.5);
    ft::pair<std::string, double> B("abc", 33.5);
    ft::pair<std::string, double> C("abc", 1.1);
    ft::pair<std::string, double> D("cba", 1.1);
    ft::pair<std::string, double> E("cba", 33.5);

    if (A == B && !(A==B) && A != D && !(A != B)
    && A > C && A > D && A > E && E > A) {
        std::cout << "Okay\n";
    } else {
        std::cout << "not okay\n";
    }
}*/

int main(int argc, char **argv)
{
    // check args
    if (argc != 2 || !valid_arg(argv[1]))
        print_usage();

    // iterator tests
    if (str_equal(argv[1], "iterator")) {
        IteratorTests iterator;
        iterator.test();
    }

    // vector tests
    if (str_equal(argv[1], "vector")) {
        VectorTests vector;
        vector.test();
    }

    // algorithm tests
    if (str_equal(argv[1], "algorithm")) {
        AlgorithmTests algorithm;
        algorithm.test();
    }

    // utility tests
    if (str_equal(argv[1], "utility")) {
        UtilityTests utility;
        utility.test();
    }
    exit(EXIT_SUCCESS);
}
