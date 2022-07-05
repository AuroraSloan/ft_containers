#include "include/TestClass.hpp"

// Canonical methods
TestClass::TestClass() : stdTime(0), ftTime(0) {}
TestClass::~TestClass() {}

// test for main.cpp
void    TestClass::test() {
#ifdef LONG
    printLongResults();
#endif

#ifdef SHORT
    printShortResults();
#endif

#ifdef TEST
    testPerformance();
#endif
}

// private methods used for test()
void TestClass::testPerformance(void) {
    ftTime = timerTest();
    namespace ft = std;
    stdTime = timerTest();
    print_time_results(stdTime, ftTime);
}
void TestClass::print_time_results(double stdtime, double fttime)
{
    std::string winner, loser, color;
    int         ratio;

    if (stdtime < fttime) {
        winner = "STL is ";
        ratio = (int)(fttime/stdtime);
        color = ratio > 20 ? RED : YELLOW;
    }
    else {
        winner = "FT is ";
        ratio = (int)(stdtime/fttime);
        color = GREEN;
    }
    std::cout << color << winner << (ratio == 1 ? 0 : ratio) << "x faster: " << RESET;
    std::cout << " [std: " << stdtime * 1000 << "ms] " << "[ft: " << fttime * 1000 << "ms]\n";
}

// protected methods used in inherited classes
void    TestClass::print_test_result(std::string testName, bool result) {
    std::cout << testName;
    print_result(result);
}

void    TestClass::print_result(bool success) {
    if (success)
        std::cout << GREEN << "SUCCESS\n" << RESET;
    else
        std::cout << RED << "FAILURE\n" << RESET;
}
void    TestClass::print_header(std::string header) {
    std::cout << MAGENTA << HDR << header << HDR << RESET << '\n';
}
void    TestClass::print_subheader(std::string subHeader) {
    std::cout << CYAN << SUBHDR << subHeader << SUBHDR << RESET << '\n';
}

// copy constructor
TestClass::TestClass(const TestClass& src) : stdTime(src.stdTime), ftTime(src.ftTime) {}

// private canonical methods
const TestClass& TestClass::operator=(const TestClass& rhs) {
    if (this != &rhs) {
        this->stdTime = rhs.stdTime;
        this->ftTime = rhs.ftTime;
    }
    return (*this);
}
