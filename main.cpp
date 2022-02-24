#include "vector.hpp"
#include "map.hpp"
#include "stack.hpp"
#include <iostream>
#include <vector>

int main(void)
{
    ft::vector<int> vec(4, 100);
    std::vector<int> stdvec(4, 100);
    std::cout << "std size: " << stdvec.size() << std::endl;
    std::cout << "ft size: " << vec.size() << std::endl;
    std::cout << "std capacity: " << stdvec.capacity() << std::endl;
    std::cout << "ft capacity: " << vec.capacity() << std::endl;
    for (std::vector<int>::iterator stdit = stdvec.begin(); stdit != stdvec.end(); stdit++)
        std::cout << "stdit: " << *stdit << '\n';
    for (ft::vector<int>::iterator ftit = vec.begin(); ftit != vec.end(); ftit++)
        std::cout << "ftit: " << *ftit << '\n';
    //std::cout << *vec._vec << std::endl;
    //std::cout << stdvec.max_size() << '\n';
//    std::cout << vec.var << std::endl;

    //std::allocator<int> j = std::allocator<int>();
    //int* arr = j.allocate(1);
    //j.construct(arr, 0);
    ft::map<int, int> map;
    std::cout << map.var << std::endl;
    ft::stack<int> stack;
    std::cout << stack.var << std::endl;


    return (0);
}
