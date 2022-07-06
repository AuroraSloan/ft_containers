#ifndef STACKTESTS_HPP
# define STACKTESTS_HPP

# include "TestClass.hpp"

class StackTests : public TestClass {

public:
    // Canonical methods
    StackTests(void);
    ~StackTests(void);

private:

    // Inherited pure methods
    void printLongResults(void);
    void printShortResults(void);
    double  timerTest(void);

    // Construction tests
    bool construction(void);

    // canonical methods
    StackTests(const StackTests& src);
    const StackTests& operator=(const StackTests& rhs);

};

#endif
