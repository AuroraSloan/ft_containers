#include "include/vector.hpp"
#include "include/map.hpp"
#include "include/stack.hpp"
#include "include/utils.hpp"
#include "tests/vectorTests.hpp"
#include <iostream>
#include <vector>
#include <cstring> //strcmp


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

bool    valid_arg(std::string arg) {
    return (arg == "vector" || arg == "stack" || arg == "map");
}

void print_usage(void) {
    std::cout << "usage: ./ft_containers <test name>\n"
    << "available tests:\nvector\nstack\nmap\n";

    exit(EXIT_FAILURE);
}

/*int main(void) {
    std::vector<int>    comp(10);
    ft::vector<int>     vec(10);

    std::cout << "vec\n";
    for(ft::vector<int>::iterator vi = vec.begin(); vi != vec.end(); vi++)
        std::cout << *vi << " ";
    std::cout << "\ncomp\n";
    for(std::vector<int>::iterator i = comp.begin(); i != comp.end(); i++)
        std::cout << *i << " ";
    return (0);
}*/
int main(int argc, char **argv)
{
    if (argc != 2 || !valid_arg(argv[1]))
        print_usage();
    if (strcmp(argv[1], "vector") == 0) {
        std::cout << MAGENTA << HDR << " Vector Tests " << HDR << RESET << '\n';
        vector_construction_tests();
        vector_modifier_tests();
        //vector_iterator_tests();
        //vector_capacity_tests();
        //vector_elementAccess_tests();
        //vector_other_tests();
    }
    exit(EXIT_SUCCESS);
}

//test_rev_it();
/*std::vector<int> stdvec;
ft::vector<int> ftvec;
ft::vector<int> ftvec2(1);
std::vector<int> stdvec2(1);
ft::vector<int> ftvec3(1, 1);
std::vector<int> stdvec3(1, 1);*/
/*    std::cout << "std: " << stdvec.empty() << " ft: " << ftvec.empty() << '\n';
    std::cout << "std: " << stdvec2.empty() << " ft: " << ftvec2.empty() << '\n';
    std::cout << "std: " << stdvec3.empty() << " ft: " << ftvec3.empty() << '\n';
    std::cout << "stdsize: " << stdvec3.size() << " ftsize: " << ftvec3.size() << '\n';
    std::cout << "stdcap: " << stdvec3.capacity() << " ftcap: " << ftvec3.capacity() << '\n';
    stdvec3.reserve(100);
    ftvec3.reserve(100);
    std::cout << "stdsize: " << stdvec3.size() << " ft: " << ftvec3.size() << '\n';
    std::cout << "stdcap: " << stdvec3.capacity() << " ftcap: " << ftvec3.capacity() << '\n';*/
/*try {
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
std::cout << "MAJOR TEST: " << *it << '\n';*/

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
