#include "ft_containers.hpp"
#include "tests/VectorTests.cpp"
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

void print_header(std::string header) {
    std::cout << MAGENTA << HDR << header << HDR << RESET << '\n';
}


/*int main(void) {

//    ft::vector<int> vec;
    int  array[100];
    int* array_end = array + 100;

    std::vector<int> comp(array, array_end);
    ft::vector<int> vec(array, array_end);
    return (0);
}*/

int main(int argc, char **argv)
{
    if (argc != 2 || !valid_arg(argv[1]))
        print_usage();
    if (str_equal(argv[1], "iterator")) {
        print_header(" Iterator Tests ");
       // iterator_tests();
    }
    if (str_equal(argv[1], "vector")) {
        print_header(" Vector Tests ");
        VectorTests vector;
        vector.testOutput();

#ifdef TEST
        vector.testPerformance();
#endif
    }
    exit(EXIT_SUCCESS);
}


    /*std::cout << "int vector\n";
    std::cout << *it << '\n';
    std::cout << *it + 1 << '\n';
    std::cout << *it << '\n';
    std::cout << *--e << '\n';
    std::cout << *it + *e << '\n';
    std::cout << (it - e) << '\n';;
    std::cout << *(it + 1) << '\n';
    std::cout << "str vector\n";
std::cout << *sit << '\n';
std::cout << *sit + "yes" << '\n';
std::cout << *sit << '\n';
std::cout << *--se << '\n';
std::cout << *sit + *se << '\n';
std::cout << (it + e) << '\n';*/
