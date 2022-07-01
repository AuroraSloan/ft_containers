#include "../ft_containers.hpp"
#include "include/OtherTests.hpp"
#include "include/TestClass.hpp"
#include "../include/algorithm.hpp"



OtherTests::OtherTests() : TestClass() {}
OtherTests::~OtherTests() {}

void OtherTests::testOutput(void) {
    print_subheader("Algorithm Tests");
    print_test_result("algorithms - ", algorithms());

    /*print_subheader("Utility Tests");
    print_test_result("utility - ", utility());*/
}

void OtherTests::testPerformance(void) {
    ftTime = timeTests();
    namespace ft = std;
    stdTime = timeTests();
    print_time_results(stdTime, ftTime);
}

double OtherTests::timeTests(void) {
    clock_t begin, end;

    begin = clock();

    algorithms();
    //utility();

    end = clock();
    return ((double) (end - begin) / CLOCKS_PER_SEC);
}

template <typename T>
bool equal_toPredicate(T a, T b) {
    return (a == b);
}
bool OtherTests::algorithms(void) {
    ft::vector<int> vecA;
    ft::vector<int> vecB;
    ft::vector<int>::iterator it;

    for (int i = 0; i < 40; i++) {
        vecA.push_back(i);
        vecB.push_back(i);
    }

    // begin, end, begin
    if (!ft::equal(vecA.begin(), vecA.end(), vecB.begin())) {
        return (false);
    }
    if (ft::equal(++vecA.begin(), vecA.end(), vecB.begin())) {
        return (false);
    }

    // begin, end, begin, predicate
    /*if (!ft::equal(vecA.begin(), vecA.end(), vecB.begin(), equal_toPredicate)) {
        return (false);
    }
    if (ft::equal(++vecA.begin(), vecA.end(), vecB.begin(), equal_toPredicate)) {
        return (false);
    }*/
    return (true);
}


OtherTests::OtherTests(const OtherTests& src) : TestClass(src) {}
const OtherTests& OtherTests::operator=(const OtherTests & rhs) {
    if (this != &rhs) {
        this->stdTime = rhs.stdTime;
        this->ftTime = rhs.ftTime;
    }
    return (*this);
}
