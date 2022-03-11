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
        ft::write(color + std::string("std is "), ratio, "x faster");
    }
    else
        ft::write(GREEN + std::string("ft is "), (int)(stdtime/fttime), "x faster");
    std::cout << "\t[std: " << stdtime * 1000 << "ms] " << "[ft: " << fttime * 1000 << "ms]\n";
}

void vector_tests(std::string testName)
{
    double stdtime, fttime;

    ft::write(MAGENTA, HDR + testName + HDR + RESET + '\n');

    // CONSTRUCTION TESTS
    std::cout << CYAN << '\t' << SUBHDR << "Construction Tests" << SUBHDR << RESET << '\n';
    vector_construction_tests();
    stdtime = vector_construction_timed_tests<std::vector<int> >();
    fttime = vector_construction_timed_tests<ft::vector<int> >();
    print_results(stdtime, fttime);

    // ITERATOR TESTS
    std::cout << CYAN << '\t' << SUBHDR << "Iterator Tests" << SUBHDR << RESET << '\n';
    vector_iterator_tests();
    stdtime = vector_iterator_timed_tests<std::vector<int> >();
    fttime = vector_iterator_timed_tests<ft::vector<int> >();
    print_results(stdtime, fttime);

    // CAPACITY TESTS

    // ELEMENT ACCESS TESTS

    // MODIFIER TESTS

    // ALLOCATOR AND NON-MEMBER FUNCTION OVERLOAD TESTS

}

void test_rev_it(void) {
    std::vector<int> vec;
    ft::vector<int> myvec(10, 10);
    vec.push_back(10);
    vec.push_back(11);
    vec.push_back(12);
    vec.push_back(13);
    vec.push_back(14);
    std::vector<int>::reverse_iterator begin = vec.rbegin();
    ft::vector<int>::reverse_iterator mybegin = myvec.rbegin();
    std::vector<int>::reverse_iterator tbegin(vec.begin());
    ft::vector<int>::reverse_iterator mytbegin(myvec.begin());
    std::cout << "begin: " << *begin << " tbegin: " << *tbegin << '\n';
    begin++;
    tbegin--;
    std::cout << "begin: " << *begin << " tbegin: " << *tbegin << '\n';
    begin++;
    tbegin--;
    std::cout << "begin: " << *begin << " tbegin: " << *tbegin << '\n';
    std::vector<int>::reverse_iterator end = vec.rend();
    std::cout << *end << '\n';
}

int main(void)
{
    vector_tests(" Vector Tests ");
    //test_rev_it();
    std::vector<int> stdvec;
    ft::vector<int> ftvec;
    ft::vector<int> ftvec2(1);
    std::vector<int> stdvec2(1);
    ft::vector<int> ftvec3(1, 1);
    std::vector<int> stdvec3(1, 1);
/*    std::cout << "std: " << stdvec.empty() << " ft: " << ftvec.empty() << '\n';
    std::cout << "std: " << stdvec2.empty() << " ft: " << ftvec2.empty() << '\n';
    std::cout << "std: " << stdvec3.empty() << " ft: " << ftvec3.empty() << '\n';
    std::cout << "stdsize: " << stdvec3.size() << " ftsize: " << ftvec3.size() << '\n';
    std::cout << "stdcap: " << stdvec3.capacity() << " ftcap: " << ftvec3.capacity() << '\n';
    stdvec3.reserve(100);
    ftvec3.reserve(100);
    std::cout << "stdsize: " << stdvec3.size() << " ft: " << ftvec3.size() << '\n';
    std::cout << "stdcap: " << stdvec3.capacity() << " ftcap: " << ftvec3.capacity() << '\n';*/
    try {
        std::cout << "std: " << ftvec3.at(50) << '\n';
    }
    catch (std::exception const & e) {
        std::cout << e.what() << '\n';
    }
    std::cout << "NEW TEST\n";
    stdvec.reserve(50);
    stdvec.push_back(1);
    stdvec.push_back(2);
    stdvec.push_back(3);
    std::vector<int>::iterator it = stdvec.begin();
    stdvec.pop_back();
    for (; it != stdvec.end(); it++)
        std::cout << "it: " << *it << '\n';
    it++;
    std::cout << "MAJOR TEST: " << *it << '\n';

//    std::cout << "ft: " << ftvec3[1] << '\n';
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


    /*std::vector<std::string> sstdvec(4, "hey");
    sstdvec.push_back("bye");
    std::vector<std::string>::iterator sit = sstdvec.begin();
    std::vector<std::string>::iterator se = sstdvec.end();
    std::cout << *sit << '\n';
    std::cout << *sit + "yes" << '\n';
    std::cout << *sit << '\n';
    std::cout << *--se << '\n';
    std::cout << *sit + *se << '\n';*/

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
