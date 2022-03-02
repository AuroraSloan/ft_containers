#include "include/vector.hpp"
#include "include/map.hpp"
#include "include/stack.hpp"
#include "include/utils.hpp"
#include "tests/vectorTests.hpp"
#include <iostream>
#include <vector>


void print_results(double stdtime, double fttime)
{
    if (stdtime < fttime)
    {
        int ratio = (int)(fttime/stdtime);
        std::string color = ratio > 20 ? RED : YELLOW;
        ft::write(color + std::string("std is "), ratio, "x faster\n");
    }
    else
        ft::write(GREEN + std::string("ft is "), (int)(stdtime/fttime), "x faster\n");
}

void vector_tests(std::string testName)
{
    double stdtime, fttime;

    ft::write(MAGENTA, HDR + testName + HDR + RESET + '\n');

    // CONSTRUCTION TESTS

    // ITERATOR TESTS
    ft::write(SUBHDR + std::string(" Iterator Tests ") + SUBHDR + '\n');
    stdtime = vector_iterator_tests<std::vector<int> >(CYAN, "\tDST\n");
    fttime = vector_iterator_tests<ft::vector<int> >(CYAN, "\tFT\n");
    print_results(stdtime, fttime);

    // CAPACITY TESTS

    // ELEMENT ACCESS TESTS

    // MODIFIER TESTS

    // ALLOCATOR AND NON-MEMBER FUNCTION OVERLOAD TESTS

}

int main(void)
{
    vector_tests(" Vector Tests ");
    //stack_tests(" Stack Tests ");
    //map_tests(" Map Tests ");

 //   vector_iterator_example(4, "hey");


/*    std::cout << "int vector\n";
    std::cout << *it << '\n';
    std::cout << *it + 1 << '\n';
    std::cout << *it << '\n';
    std::cout << *--e << '\n';
    std::cout << *it + *e << '\n';
    std::cout << (it - e) << '\n';;
    std::cout << *(it + 1) << '\n';
    std::cout << "str vector\n";*/
    std::vector<std::string> sstdvec(4, "hey");
    sstdvec.push_back("bye");
    std::vector<std::string>::iterator sit = sstdvec.begin();
    std::vector<std::string>::iterator se = sstdvec.end();
    std::cout << *sit << '\n';
    std::cout << *sit + "yes" << '\n';
    std::cout << *sit << '\n';
    std::cout << *--se << '\n';
    std::cout << *sit + *se << '\n';

   // std::cout << (it + e) << '\n';
    //std::cout << "std size: " << stdvec.size() << std::endl;
    //std::cout << "ft size: " << vec.size() << std::endl;
    //std::cout << "std capacity: " << stdvec.capacity() << std::endl;
    //std::cout << "ft capacity: " << vec.capacity() << std::endl;
//    for (std::vector<int>::iterator stdit = stdvec.begin(); stdit != stdvec.end(); stdit++)
 //       std::cout << "stdit: " << *stdit << '\n';
    //for (ft::vector<int>::iterator ftit = vec.begin(); ftit != vec.end(); ftit++)
    //    std::cout << "ftit: " << *ftit << '\n';
    //std::cout << *vec._vec << std::endl;
    //std::cout << stdvec.max_size() << '\n';
//    std::cout << vec.var << std::endl;

    //std::allocator<int> j = std::allocator<int>();
    //int* arr = j.allocate(1);
    //j.construct(arr, 0);
    /*ft::map<int, int> map;
    std::cout << map.var << std::endl;
    ft::stack<int> stack;
    std::cout << stack.var << std::endl;*/


    return (0);
}
