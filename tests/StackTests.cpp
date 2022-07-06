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
    ft::stack<int> stack;

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
