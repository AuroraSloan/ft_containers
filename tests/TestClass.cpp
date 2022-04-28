#include "include/TestClass.hpp"

TestClass::TestClass() : stdTime(0), ftTime(0) {}
TestClass::~TestClass() {}

void    TestClass::print_test_result(std::string testName, bool success) {
    std::cout << testName;
    if (success)
        std::cout << GREEN << "SUCCESS\n" << RESET;
    else
        std::cout << RED << "FAILURE\n" << RESET;
}

void TestClass::print_time_results(double stdtime, double fttime)
{
    std::string winner, loser, color;
    int         ratio;

    if (stdtime < fttime) {
        winner = "STL is ";
        loser = "FT is ";
        ratio = (int)(fttime/stdtime);
        color = ratio > 20 ? RED : YELLOW;
    }
    else {
        winner = "FT is ";
        loser = "STL is ";
        ratio = (int)(stdtime/fttime);
        color = GREEN;
    }
    std::cout << color << winner << (ratio == 1 ? 0 : ratio) << "x faster: " << RESET;
    std::cout << " [std: " << stdtime * 1000 << "ms] " << "[ft: " << fttime * 1000 << "ms]\n";
}

void    TestClass::print_subheader(std::string subHeader) {
    std::cout << CYAN << SUBHDR << subHeader << SUBHDR << RESET << '\n';
}

TestClass::TestClass(const TestClass& src) : stdTime(src.stdTime), ftTime(src.ftTime) {}

const TestClass& TestClass::operator=(const TestClass& rhs) {
    if (this != &rhs) {
        this->stdTime = rhs.stdTime;
        this->ftTime = rhs.ftTime;
    }
    return (*this);
}
