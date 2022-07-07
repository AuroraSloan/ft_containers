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

    print_test_result("construction - ", construction());
    print_test_result("empty, size, top, push, pop - ", all_methods());
    print_test_result("relational operators - ", relational_operators());

}
void    StackTests::printShortResults(void) {
    std::cout << "Stack tests - ";
    if (construction() && all_methods() && relational_operators()) {
        print_result(true);
    } else {
        print_result(false);
    }
}
double  StackTests::timerTest(void) {
    clock_t begin, end;

    begin = clock();

    // tests
    construction();
    all_methods();

    end = clock();
    return ((double) (end - begin) / CLOCKS_PER_SEC);
}


//============================================================================//
//                                                                            //
//                                  TESTS                                     //
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
//====================================//
//             ALL METHODS            //
//====================================//
bool StackTests::all_methods(void) {
    // empty, size
    ft::stack<int> stack;
    if (!stack.empty() || stack.size() != 0) {
        return (false);
    }

    stack.push(345);
    stack.push(2);
    // push, top, empty, size
    if (stack.top() != 2 || stack.empty() || stack.size() != 2) {
        return (false);
    }

    stack.pop();
    stack.pop();
    // pop, empty, size
    if (!stack.empty() || stack.size() != 0) {
        return (false);
    }
    return (true);
}

//====================================//
//        RELATIONAL OPERATORS        //
//====================================//
bool StackTests::relational_operators() {
   ft::stack<int> A;
   ft::stack<int> B;
   ft::stack<int> C;

   for(int i = 1; i <= 9; i++) {
       A.push(i);
       B.push(i);
   }
    for(int i = 9; i >= 1; i--) {
        C.push(i);
    }

    return (A == B && A != C && B >= A && B <= A
    && A <= C && C == C && C != B && C >= B
    && B < C && C > A && !(B > C) && !(C < A));
}

// Canonical methods
StackTests::StackTests(const StackTests& src) : TestClass(src) {}
const StackTests& StackTests::operator=(const StackTests& rhs) {
    if (this != &rhs) {
        this->stdTime = rhs.stdTime;
        this->ftTime = rhs.ftTime;
    }
    return (*this);
}
