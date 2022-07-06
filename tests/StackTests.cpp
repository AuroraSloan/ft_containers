#include "../ft_containers.hpp"
#include "include/StackTests.hpp"
#include <ctime>

// Canonical methods
StackTests::StackTests(void) : TestClass() {}
StackTests::~StackTests(void) {}

// Inherited pure methods
void StackTests::printLongResults(void) {
    print_header(" Stack Tests ");

    //print_subheader("Construction Tests");
    //print_test_result("construction - ", construction());

}
void    StackTests::printShortResults(void) {
    std::cout << "Stack tests - ";
    if (1) {
        print_result(true);
    } else {
        print_result(false);
    }
}
double  StackTests::timerTest(void) {
    clock_t begin, end;

    begin = clock();

    // construction
    //construction();

    end = clock();
    return ((double) (end - begin) / CLOCKS_PER_SEC);
}


//============================================================================//
//                                                                            //
//                              CONSTRUCTOR TESTS                             //
//                                                                            //
//============================================================================//
//====================================//
//        VECTOR CONSTRUCTION         //
//====================================//



StackTests::StackTests(const StackTests& src) : TestClass(src) {}
const StackTests& StackTests::operator=(const StackTests& rhs) {
    if (this != &rhs) {
        this->stdTime = rhs.stdTime;
        this->ftTime = rhs.ftTime;
    }
    return (*this);
}
