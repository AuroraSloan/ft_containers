#pragma once
#ifndef STACKTESTS_HPP
# define STACKTESTS_HPP

# include "TestClass.hpp"

class StackTests : public TestClass {

public:
    // Canonical methods
    StackTests();
    ~StackTests();

private:

    // Inherited pure methods
    void printLongResults();
    void printShortResults();
    double  timerTest();

    // Tests
    bool construction();
    bool all_methods();
    bool relational_operators();

    // Helper methods
    template <typename stackA, typename stackB>
    bool stacks_equal(stackA A, stackB B) {
        if (A.empty() != B.empty() || A.size() != B.size() || A.top() != B.top()) {
            return (false);
        }
        while (A.empty() != 0) {
            if (B.empty() == 0) {
                return (false);
            }
            A.pop();
            B.pop();
            if (A.top() != B.top()) {
                return (false);
            }
        }
        return (true);
    }

    // canonical methods
    StackTests(const StackTests& src);
    const StackTests& operator=(const StackTests& rhs);

};

#endif
