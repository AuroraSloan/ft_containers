#include "tests/VectorTests.cpp"
#include "tests/IteratorTests.cpp"
#include "tests/AlgorithmTests.cpp"
#include "tests/UtilityTests.cpp"
#include "tests/StackTests.cpp"
#include "tests/TreeTests.cpp"
#include "tests/MapTests.cpp"
#include "ft_containers.hpp"
#include <iostream>
#include <cstring> //strcmp // find better way
//#include "include/map.hpp"

bool    str_equal(const char *A, const std::string& B) {
    return (strcmp(A, B.c_str()) == 0 || strcmp(A, "all") == 0);
}

bool    valid_arg(const std::string& arg) {
    return (arg == "vector" || arg == "stack" || arg == "tree" || arg == "map" || arg == "iterator"
    || arg == "algorithm" || arg == "utility" || arg == "all");
}

void print_usage() {
    std::cout << "usage: ./ft_containers <test name>\n"
    << "available tests:\nall\nvector\nstack\nmap\nalgorithm\nutility\n";

    exit(EXIT_FAILURE);
}

/*class test {
public:
    int a;
    test() : a() {
        std::cerr << "dflt const\n";
    }
    test(int val) : a(val) {
        std::cerr << "dflt const\n";
    }
    test(const test& src) : a(src.a) {
        std::cerr << "cpy const\n";
    }
    test& operator=(const test& rhs) {
        a = rhs.a;
        std::cerr << "eq overload const\n";
        return (*this);
    }
    ~test() {
        std::cerr << "dest: " << a << '\n';
    }
};

int main() {

   test dflt;
   test dfltVal(5);
   test cpy(dfltVal);
   test eq;
   eq = cpy;

   return (0);
}*/

int main(int argc, char **argv)
{
    // check args

    if (argc != 2 || !valid_arg(argv[1]))
        print_usage();

    // iterator tests
    /*if (str_equal(argv[1], "iterator")) {
        IteratorTests iterator;
        iterator.test();
    }

    // vector tests
    if (str_equal(argv[1], "vector")) {
        VectorTests vector;
        vector.test();
    }

    // stack tests
    if (str_equal(argv[1], "stack")) {
        StackTests stack;
        stack.test();
    }*/

    // tree tests
    if (str_equal(argv[1], "tree")) {
        TreeTests tree;
        tree.test();
    }

    // algorithm tests
    /*if (str_equal(argv[1], "algorithm")) {
        AlgorithmTests algorithm;
        algorithm.test();
    }

    // utility tests
    if (str_equal(argv[1], "utility")) {
        UtilityTests utility;
        utility.test();
    }*/

    exit(EXIT_SUCCESS);
}

// map tests
/*if (str_equal(argv[1], "map")) {
MapTests map;
map.test();
}*/
