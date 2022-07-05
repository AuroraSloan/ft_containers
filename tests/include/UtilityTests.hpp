#ifndef UTILITYTESTS_HPP
# define UTILITYTESTS_HPP

# include "TestClass.hpp"

class UtilityTests : public TestClass {

public:

    UtilityTests(void);
    ~UtilityTests(void);

    void testOutput(void);
    void testPerformance(void);

private:

    double timeTests(void);

    // Test functions
    bool pair_construction(void);
    bool pair_relational_operators(void);
    bool make_pair(void);

    // canonical functions
    UtilityTests(const UtilityTests& src);
    const UtilityTests& operator=(const UtilityTests & rhs);
};

#endif
