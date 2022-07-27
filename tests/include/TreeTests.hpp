#ifndef TREETESTS_HPP
# define TREETESTS_HPP

# include "TestClass.hpp"

class TreeTests : public TestClass {

public:
    // Canonical methods
    TreeTests();
    ~TreeTests();

private:

    // Inherited pure methods
    void printLongResults();
    void printShortResults();
    double  timerTest();

    // Construction tests
    bool    construction();

    // Iterator tests
    bool    iterator();
    bool    reverse_iterator();

    // Modifier tests
    bool    insert();
    /*bool    tree_transplant(void);
    bool    tree_delete(void);*/

    // Helper Methods
    template <typename Tree>
    bool    trees_equal(Tree & A, Tree & B) {

        typedef typename Tree::iterator   Iterator;

        //check size
        size_t ASize, BSize;
        ASize = A.size();
        BSize = B.size();
        if (ASize != BSize) {
            std::cerr << "ASize: " << ASize << "\nBSize: " << BSize << '\n';
            return (false);
        }

        Iterator iteratorA = A.begin();
        Iterator iteratorB = B.begin();

        for (size_t i = 0; i < ASize; i++, iteratorA++, iteratorB++) {
            if ((*iteratorA).first != (*iteratorB).first || (*iteratorA).second != (*iteratorB).second
            || iteratorA == A.end() || iteratorB == B.end()) {
                std::cerr << "iterator A not equal to iterator B\n";
                return (false);
            }
        }
        return (true);
    }
    // canonical methods
    TreeTests(const TreeTests& src);
    const TreeTests& operator=(const TreeTests& rhs);

};


#endif
