#include "include/StackTests.hpp"
#include "include/TestClass.hpp"
#include "../ft_containers.hpp"
#include <stack>

#include <ctime>

// Canonical methods
StackTests::StackTests(void) : TestClass() {}
StackTests::~StackTests(void) {}

// Inherited pure methods
void StackTests::printLongResults(void) {
    print_header(" Stack Tests ");

    print_subheader("Construction Tests");
    print_test_result("construction - ", construction());

}
void    StackTests::printShortResults(void) {
    std::cout << "Stack tests - ";
    if (construction()) {
        print_result(true);
    } else {
        print_result(false);
    }
}
double  StackTests::timerTest(void) {
    clock_t begin, end;

    begin = clock();

    // construction
    construction();

    end = clock();
    return ((double) (end - begin) / CLOCKS_PER_SEC);
}


//============================================================================//
//                                                                            //
//                              CONSTRUCTOR TESTS                             //
//                                                                            //
//============================================================================//
//====================================//
//         STACK CONSTRUCTION         //
//====================================//
bool    StackTests::construction() {
    ft::stack<int> constructedA;
    ft::stack<int, ft::vector<int> > constructedB;
    if (!constructedA.empty() || !constructedB.empty()) {
        return (false);
    }

    constructedA.push(111);
    ft::stack<int> copy_constructed(constructedA);
    if (!(stacks_equal(constructedA, copy_constructed))) {
        return (false);
    }

    ft::vector<int> vector(32, 999);
    ft::stack<int, ft::vector<int> > constructed_from_vector(vector);
    ft::stack<int> check;
    for (int i = 1; i <= 32; i++) {
       check.push(999);
    }
    if (!(stacks_equal(constructed_from_vector, check))) {
        return (false);
    }
    return (true);
}


StackTests::StackTests(const StackTests& src) : TestClass(src) {}
const StackTests& StackTests::operator=(const StackTests& rhs) {
    if (this != &rhs) {
        this->stdTime = rhs.stdTime;
        this->ftTime = rhs.ftTime;
    }
    return (*this);
}
