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


/*int main() {
    ft::_rb_tree<int> tree;
    //ft::_rb_node<int> one(1);
    //ft::_rb_node<int> thirtythree(33);
    //ft::_rb_node<int> seventeen(17);

    //tree.insert(one);
    //tree.insert(thirtythree);
    //tree.insert(seventeen);
    tree.tree_insert(1);
    tree.tree_insert(33);
    tree.tree_insert(17);
    tree.tree_insert(2);

    tree.inOrderWalk(tree.getRoot());
    tree.inOrderWalk(tree.getRoot());

    ft::_rb_tree<int>::iterator i(tree.begin());
    std::cout << i->key << '\n';
    i++;
    i++;
    std::cout << i->key << '\n';

    //i = tree.begin();

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

    // stack tests
    if (str_equal(argv[1], "stack")) {
        StackTests stack;
        stack.test();
    }

    // tree tests
    if (str_equal(argv[1], "tree")) {
        TreeTests tree;
        tree.test();
    }
    // map tests
    /*if (str_equal(argv[1], "map")) {
        MapTests map;
        map.test();
    }*/

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
