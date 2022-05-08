#include "include/OtherTests.hpp"

#include "TestClass.cpp"

OtherTests::OtherTests(void) : TestClass() {}
OtherTests::~OtherTests(void) {}

void OtherTests::testOutput(void) {

}
void OtherTests::testPerformance(void) {

}

double OtherTests::timeTests(void) {

}

bool OtherTests::algorithms(void) {

}


OtherTests::OtherTests(const OtherTests& src) : TestClass(src) {}
const OtherTests& OtherTests::operator=(const OtherTests & rhs) {
    if (this != &rhs) {
        this->stdTime = rhs.stdTime;
        this->ftTime = rhs.ftTime;
    }
    return (*this);
}
