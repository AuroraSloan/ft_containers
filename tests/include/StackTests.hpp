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

    // Tests
    bool construction(void);
    bool all_methods(void);
    bool relational_operators(void);

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
