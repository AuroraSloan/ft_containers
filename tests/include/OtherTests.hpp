#ifndef OTHERTESTS_HPP
# define OTHERTESTS_HPP

# include "TestClass.hpp"

class OtherTests : public TestClass {

public:

    OtherTests(void);
    ~OtherTests(void);

    void testOutput(void);
    void testPerformance(void);

private:

    double timeTests(void);

    bool algorithms(void);
    template <typename T>
    bool equal_to(T a, T b) {
        return (a == b);
    }
    template <typename T>
    bool greater_than(T a, T b) {
        return (a > b);
    }
    template <typename T>
    bool less_than(T a, T b) {
        return (a < b);
    }


    OtherTests(const OtherTests& src);
    const OtherTests& operator=(const OtherTests & rhs);


};

#endif
