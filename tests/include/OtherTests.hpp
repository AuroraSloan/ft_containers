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

    // Algorithm tests
    bool equal(void);
    bool lexicographical_compare(void);

    // Uility tests
    bool pair(void);

    OtherTests(const OtherTests& src);
    const OtherTests& operator=(const OtherTests & rhs);


};

#endif
