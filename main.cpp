#include "vector.hpp"
#include "map.hpp"
#include "stack.hpp"
#include <iostream>

int main(void)
{
    ft::vector<int> vec;
    std::cout << vec.var << std::endl;
    ft::map<int, int> map;
    std::cout << map.var << std::endl;
    ft::stack<int> stack;
    std::cout << stack.var << std::endl;

    return (0);
}
