#ifndef MAPTESTS_HPP
# define MAPTESTS_HPP

# include "TestClass.hpp"

class MapTests : public TestClass {

public:
    // Canonical methods
    MapTests();
    ~MapTests();

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
    bool    insert(void);
    /*bool    erase(void);
    bool    swap(void);
    bool    clear(void);

    // Capacity Tests


    // Helper Methods*/
    template <typename Map>
    bool    maps_equal(Map & A, Map & B) {

        typedef typename Map::iterator   Iterator;

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
    MapTests(const MapTests& src);
    const MapTests& operator=(const MapTests& rhs);

};


#endif
