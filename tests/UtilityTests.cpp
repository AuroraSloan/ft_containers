#include "include/UtilityTests.hpp"
#include "include/TestClass.hpp"
#include "../ft_containers.hpp"
#include <ctime>
#ifdef TEST
# include "../include/utility.hpp"
# else
namespace ft = std;
#endif

// Canonical methods
UtilityTests::UtilityTests(void) : TestClass() {}
UtilityTests::~UtilityTests(void) {}

// Inherited pure methods
void UtilityTests::printLongResults(void) {
    print_header("Utility tests");

    print_test_result("pair_construction - ", pair_construction());
    print_test_result("pair_relational_operators - ", pair_relational_operators());
    print_test_result("make_pair - ", make_pair());
}
void UtilityTests::printShortResults(void) {
    std::cout << "Utility tests - ";
    if (pair_construction() && pair_relational_operators() && make_pair()) {
        print_result(true);
    } else {
        print_result(false);
    }
}
double UtilityTests::timerTest(void) {
    clock_t begin, end;

    begin = clock();

    //tests
    pair_construction();
    pair_relational_operators();
    make_pair();

    end = clock();
    return ((double) (end - begin) / CLOCKS_PER_SEC);
}

//============================================================================//
//                                                                            //
//                              UTILITY TESTS                                 //
//                                                                            //
//============================================================================//
//====================================//
//         PAIR CONSTRUCTION          //
//====================================//
bool UtilityTests::pair_construction() {
    ft::pair<std::string, double> constructed_ft;
    ft::pair<std::string, double> value_constructed_ft("hugs", 33.5);
    ft::pair<std::string, double> copy_constructed_ft(value_constructed_ft);
    ft::pair<std::string, double> equal_operator_ft;
    equal_operator_ft = value_constructed_ft;

    std::pair<std::string, double> constructed_std;
    std::pair<std::string, double> value_constructed_std("hugs", 33.5);
    std::pair<std::string, double> copy_constructed_std(value_constructed_std);
    std::pair<std::string, double> equal_operator_std;
    equal_operator_std = value_constructed_std;

    return (constructed_ft.first == constructed_std.first
    && constructed_ft.second == constructed_std.second
    && value_constructed_ft.first == value_constructed_std.first
    && value_constructed_ft.second == value_constructed_std.second
    && copy_constructed_ft.first == copy_constructed_std.first
    && copy_constructed_ft.second == copy_constructed_std.second
    && equal_operator_ft.first == equal_operator_std.first
    && equal_operator_ft.second == equal_operator_std.second);
}

//====================================//
//     PAIR RELATIONAL OPERATORS      //
//====================================//
bool UtilityTests::pair_relational_operators(void) {
    ft::pair<std::string, double> A("abc", 33.5);
    ft::pair<std::string, double> B("abc", 33.5);
    ft::pair<std::string, double> C("abc", 1.1);
    ft::pair<std::string, double> D("cba", 1.1);
    ft::pair<std::string, double> E("cba", 33.5);

    return (A == B && !(A == C) && A != D && !(A != B)
    && A < E && C < A && A > C && E > B
    && D >= A && A <= B && D <= E && A >= B);
}

//====================================//
//              MAKE_PAIR             //
//====================================//
bool UtilityTests::make_pair(void) {
   ft::pair<char, int> char_int_pair;
   char_int_pair = ft::make_pair('a', 1);

   ft::pair<int, std::string> int_string_pair = ft::make_pair(75, "hello");

   return (char_int_pair.first == 'a' && char_int_pair.second == 1
   && int_string_pair.first == 75 && int_string_pair.second == "hello");
}

// canoncial methods
UtilityTests::UtilityTests(const UtilityTests& src) : TestClass(src) {}
const UtilityTests& UtilityTests::operator=(const UtilityTests & rhs) {
    if (this != &rhs) {
        this->stdTime = rhs.stdTime;
        this->ftTime = rhs.ftTime;
    }
    return (*this);
}
