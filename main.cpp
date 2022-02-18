#include "vector.hpp"
#include "map.hpp"
#include "stack.hpp"
#include <iostream>
#include <vector>

int main(void)
{
    ft::vector<int> vec;
    std::vector<int> stdvec;
    std::cout << stdvec.max_size() << '\n';
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
