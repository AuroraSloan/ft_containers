#include "include/UtilityTests.hpp"
#include "include/TestClass.hpp"
#include "../ft_containers.hpp"


UtilityTests::UtilityTests() : TestClass() {}
UtilityTests::~UtilityTests() {}

void UtilityTests::testOutput(void) {
    print_test_result("pair_construction - ", pair_construction());
    //print_test_result("make_pair - ", make_pair());
}

void UtilityTests::testPerformance(void) {
    ftTime = timeTests();
    namespace ft = std;
    stdTime = timeTests();
    print_time_results(stdTime, ftTime);
}

double UtilityTests::timeTests(void) {
    clock_t begin, end;

    begin = clock();

    //utility
    pair_construction();
    //make_pair();

    end = clock();
    return ((double) (end - begin) / CLOCKS_PER_SEC);
}

//============================================================================//
//                                                                            //
//                              UTILITY TESTS                                 //
//                                                                            //
//============================================================================//
//====================================//
//                PAIR                //
//====================================//
bool UtilityTests::pair_construction() {
    ft::pair<std::string, double> constructed_ft;
    ft::pair<std::string, double> value_constructed_ft("hugs", 33.5);
    ft::pair<std::string, double> copy_constructed_ft(value_constructed_ft);

    std::pair<std::string, double> constructed_std;
    std::pair<std::string, double> value_constructed_std("hugs", 33.5);
    std::pair<std::string, double> copy_constructed_std(value_constructed_std);

    if (constructed_ft.first != constructed_std.first
    || constructed_ft.second != constructed_std.second
    || value_constructed_ft.first != value_constructed_std.first
    || value_constructed_ft.second != value_constructed_std.second
    || copy_constructed_ft.first != copy_constructed_std.first
    || copy_constructed_ft.second != copy_constructed_std.second) {
        return (false);
    }
    return (true);
}


UtilityTests::UtilityTests(const UtilityTests& src) : TestClass(src) {}
const UtilityTests& UtilityTests::operator=(const UtilityTests & rhs) {
    if (this != &rhs) {
        this->stdTime = rhs.stdTime;
        this->ftTime = rhs.ftTime;
    }
    return (*this);
}
