#include "include/SetTests.hpp"
#include "include/TestClass.hpp"
#include "../ft_containers.hpp"
#include <set>
#include <ctime>
#include <cstdlib>
#include <utility>
#ifdef TEST
# include "../include/set.hpp"
# else
namespace ft = std;
#endif
// Canonical methods
SetTests::SetTests() : TestClass() {}
SetTests::~SetTests() {}

// Inherited pure methods
void SetTests::printLongResults() {
    print_header(" Set Tests ");

    print_subheader("Construction Tests");
    print_test_result("construction - ", construction());

    print_subheader("Iterator Tests");
    print_test_result("iterator - ", iterator());
    print_test_result("reverse iterator - ", reverse_iterator());

    print_subheader("Capacity Tests");
    print_test_result("capacity - ", capacity());

    print_subheader("Modifiers Tests");
    print_test_result("insert - ", insert());
    print_test_result("erase - ", erase());
    print_test_result("clear - ", clear());
    print_test_result("swap - ", swap());

    print_subheader("Lookup Tests");
    print_test_result("find - ", find());
    print_test_result("count - ", count());
    print_test_result("bounds - ", bounds_range());
}
void    SetTests::printShortResults() {
    std::cout << "Set tests - ";
    if (construction() && iterator() && reverse_iterator() && capacity() &&insert() && erase() && clear() && swap()
        && find() && count() && bounds_range()) {
        print_result(true);
    } else {
        print_result(false);
    }
}
double  SetTests::timerTest() {
    clock_t begin, end;

    begin = clock();

    // construction
    construction();

    // iterator
    iterator();
    reverse_iterator();

    //capacity
    capacity();

    //modifier
    insert();
    erase();
    clear();

    // Operations
    find();
    count();
    bounds_range();

    end = clock();
    return ((double) (end - begin) / CLOCKS_PER_SEC);
}


//============================================================================//
//                                                                            //
//                              CONSTRUCTOR TESTS                             //
//                                                                            //
//============================================================================//
//====================================//
//          set CONSTRUCTION          //
//====================================//
bool    SetTests::construction()
{
    typedef ft::set<int> Set;
    typedef std::set<int> Comp;

    // Copy Construction
    Set toCpy;
    Comp comp_toCpy;

    _generate_random_sets(toCpy, comp_toCpy, 30);

    Set cpy_const(toCpy);
    Comp comp_cpy_const(comp_toCpy);

    // Iterator constructor
    Set itConst(toCpy.begin(), toCpy.end());
    Comp comp_itConst(comp_toCpy.begin(), comp_toCpy.end());

    // Equal operator overload

    Set cpy_constEQ = cpy_const;
    Comp comp_cpy_constEQ = comp_cpy_const;

    if (!sets_equal(cpy_const, toCpy, comp_cpy_const)
        || !sets_equal(cpy_constEQ, cpy_const, comp_cpy_constEQ)
        || !sets_equal(cpy_constEQ, toCpy)
        || !sets_equal(toCpy, itConst, comp_itConst)) {
        return (false);
    }

    // Range Constructor
    Set range;
    _generate_random_sets(range, 30);

    Set range_constructed(range.begin(), range.end());
    if (!sets_equal(range, range_constructed)) {
        return (false);
    }

    return (true);
}


//============================================================================//
//                                                                            //
//                              ITERATOR TESTS                                //
//                                                                            //
//============================================================================//
bool    SetTests::iterator() {
    ft::set<int>              set;
    std::set<int>             comp;
    ft::set<int>::iterator    set_it;
    std::set<int>::iterator   comp_it;


    _generate_random_sets(set, comp, 60);

    set_it = set.begin();
    comp_it = comp.begin();

    // ++ begin - end
    for (; set_it != set.end(); set_it++, comp_it++) {
        if (*set_it != *comp_it || comp_it == comp.end()) {
            return (false);
        }
    }

    // -- end to begin
    set_it--;
    comp_it--;
    for (; set_it != set.begin(); set_it--, comp_it--) {
        if (*set_it != *comp_it || comp_it == comp.begin()) {
            return (false);
        }
    }
    if (*set_it != *comp_it) {
        return (false);
    }
    return (true);
}

bool    SetTests::reverse_iterator() {
    ft::set<int>                      set;
    std::set<int>                     comp;
    ft::set<int>::reverse_iterator    set_rit;
    std::set<int>::reverse_iterator   comp_rit;

    _generate_random_sets(set, comp, 60);
    set_rit = set.rbegin();
    comp_rit = comp.rbegin();

    // ++ rbegin - rend
    for (; set_rit != set.rend(); set_rit++, comp_rit++) {
        if (*set_rit != *comp_rit || comp_rit == comp.rend()) {
            return (false);
        }
    }

    // -- rend to rbegin
    set_rit--;
    comp_rit--;
    for (; set_rit != set.rbegin(); set_rit--, comp_rit--) {
        if (*set_rit != *comp_rit || comp_rit == comp.rbegin()) {
            return (false);
        }
    }
    if (*set_rit != *comp_rit) {
        return (false);
    }
    return (true);
}

//============================================================================//
//                                                                            //
//                              CAPACITY TESTS                                //
//                                                                            //
//============================================================================//
bool    SetTests::capacity() {
    // ADD MORE TESTS ONCE DELETE AND CLEAR ETC ARE DONE
    ft::set<int> set;
    std::set<int> std;

    if (set.max_size() != std.max_size()) {
        //std::cerr << YELLOW << "m: " << set.max_size() << "s: " << std.max_size() << RESET << std::endl;
    }

    if (!set.empty()) {
        return (false);
    }

    set.insert(65412);
    if (set.empty()) {
        return (false);
    }

    for (int i = 0; i < 1000; i++) {
        set.insert(i);
    }
    if (set.size() != 1001 || set.empty()) {
        return (false);
    }


    return (true);
}

//============================================================================//
//                                                                            //
//                              MODIFIER TESTS                                //
//                                                                            //
//============================================================================//

//====================================//
//               INSERT               //
//====================================//
bool    SetTests::insert() {

    // INSERT PAIR VALUE
    ft::set<int> set;
    std::set<int> comp;

    _generate_ordered_sets(set, comp, 50);
    set.insert(4);
    comp.insert(4);

    if (!sets_equal(set, comp)) {
        return (false);
    }

    // INSERT POSITION AND PAIR VALUE
    ft::set<int> set2;
    std::set<int> comp2;

    // Good Hint
    for (int i = 0; i < 25; i++) {
        if (i == 7) {
            continue ;
        }
        set2.insert(i);
        comp2.insert(i);
    }
    // middle of
    ft::set<int>::iterator setIt2 = set2.begin();
    std::set<int>::iterator compIt2 = comp2.begin();
    for (int i = 1; i < 7; i++) {
        setIt2++;
        compIt2++;
    }
    set2.insert(setIt2,7);
    comp2.insert(compIt2,7);
    // end of
    ft::set<int>::iterator setLast = set2.end();
    std::set<int>::iterator compLast = comp2.end();
    set2.insert(--setLast,28);
    comp2.insert(--compLast, 28);
    if (!sets_equal(set2, comp2)) {
        return (false);
    }

    // Bad Hint
    set2.insert(set2.begin(), 7777);
    comp2.insert(comp2.begin(),7777);

    if (!sets_equal(set2, comp2)) {
        return (false);
    }

    // INSERT BY ITERATORS
    _generate_random_sets(set2, comp2, 50);
    set2.insert(set.begin(), set.end());
    comp2.insert(comp.begin(), comp.end());
    if (!sets_equal(set2, comp2)) {
        return (false);
    }

    return (true);
}
//====================================//
//               ERASE                //
//====================================//
bool    SetTests::erase() {
    ft::set<int> set;
    std::set<int> comp;

    // ERASE BY KEY
    _generate_ordered_sets(set, comp, 30);
    set.erase(10);
    comp.erase(10);
    set.erase(27);
    comp.erase(27);
    set.erase(0);
    comp.erase(0);
    set.erase(29);
    comp.erase(29);

    // edge case
    set.erase(0);
    comp.erase(0);
    set.erase(29);
    comp.erase(29);
    for (int i = 0; i < 30; i++) {
        set.erase(i);
        comp.erase(i);
    }

    _generate_random_sets(set, comp, 100);

    ft::set<int>::iterator setIt = set.begin();
    std::set<int>::iterator compIt = comp.begin();

    for (int i = 0; i < 13; i++, ++setIt, ++compIt) {}
    set.erase(setIt);
    comp.erase(compIt);

    set.erase(set.begin());
    comp.erase(comp.begin());

    setIt = set.begin();
    compIt = comp.begin();
    for (int i = 0; i < 88; i++, ++setIt, ++compIt) {}
    set.erase(setIt);
    comp.erase(compIt);

    set.erase(--(set.end()));
    comp.erase(--(comp.end()));
    if (!sets_equal(set, comp)) {
        return (false);
    }

    _generate_ordered_sets(set, comp, 50);
    // range
    set.erase(set.begin(), set.end());
    comp.erase(comp.begin(), comp.end());

    if (!sets_equal(set, comp)) {
        return (false);
    }

    return (true);
}

//====================================//
//              CLEAR                 //
//====================================//
bool    SetTests::clear() {
    ft::set<int> set;
    std::set<int> comp;

    _generate_random_sets(set, comp, 1000);
    set.clear();
    comp.clear();

    if (!sets_equal(set, comp)) {
        return (false);
    }

    return (true);
}

//====================================//
//              SWAP                 //
//====================================//
bool    SetTests::swap() {
    ft::set<int> setA;
    ft::set<int> setB;
    ft::set<int>::iterator setIt;
    std::set<int> compA;
    std::set<int> compB;
    std::set<int>::iterator compIt;

    _generate_ordered_sets(setA, compA, 100);
    _generate_random_sets(setB, compB, 200);

    setIt = setB.begin();
    compIt = compB.begin();
    for(int i = 0; i < 40; i++) {
        setIt++;
        compIt++;
    }
    int setInt = *setIt;
    int compInt = *compIt;


    setA.swap(setB);
    compA.swap(compB);

    if (!sets_equal(setA, compA) || !sets_equal(setB, compB)
        || setInt != *setIt || compInt != *compIt) {
        return (false);
    }
    return (true);
}

//============================================================================//
//                                                                            //
//                                OPERATIONS                                  //
//                                                                            //
//============================================================================//
//====================================//
//               find                 //
//====================================//
bool    SetTests::find() {
    ft::set<int> set;
    std::set<int> comp;

    for (int i = 0; i < 50; i++) {
        set.insert(i);
        comp.insert(i);
    }

    if (*set.find(7) != *comp.find(7)) {
        return (false);
    }
    if (*set.find(0) != *comp.find(0)) {
        return (false);
    }

    if (set.find(52) != set.end() || comp.find(52) != comp.end()) {
        return (false);
    }

    const ft::set<int> constset(set);
    const std::set<int> constComp(comp);
    ft::set<int, char>::const_iterator setIt = set.find(14);
    std::set<int, char>::const_iterator compIt = comp.find(14);
    if (*setIt != *compIt) {
        return (false);
    }

    return (true);
}
//====================================//
//               Count                 //
//====================================//
bool    SetTests::count() {
    ft::set<int> set;
    std::set<int> comp;

    _generate_ordered_sets(set, comp, 30);

    if (set.count(29) != comp.count(29) || set.count(50) != comp.count(50)) {
        return (false);
    }
    return (true);
}
//====================================//
//          LOWER_BOUND               //
//====================================//
bool    SetTests::bounds_range() {
    ft::set<int> set;
    std::set<int> comp;

    _generate_ordered_sets(set, comp, 10);
    set.erase(8);
    comp.erase(8);

    const ft::set<int> constset(set);
    const std::set<int> constComp(comp);


    // LOWER
    if (*set.lower_bound(6) != *comp.lower_bound(6)
        || *set.lower_bound(8) != *comp.lower_bound(8)
        || *set.lower_bound(9) != *comp.lower_bound(9)
        || *constset.lower_bound(2) != *constComp.lower_bound(2)) {
        return (false);
    }
    // UPPER
    if (*set.upper_bound(6) != *comp.upper_bound(6)
        || *set.upper_bound(8) != *comp.upper_bound(8)
        || *set.upper_bound(0) != *comp.upper_bound(0)
        || *constset.upper_bound(2) != *constComp.upper_bound(2)) {
        return (false);
    }
    // EDGE
    if (set.lower_bound(13) != set.end() || comp.lower_bound(13) != comp.end()
        || set.upper_bound(13) != set.end() || comp.upper_bound(13) != comp.end()) {
        return (false);
    }
    // RANGE
    if (*set.equal_range(0).first != *comp.equal_range(0).first
        || *set.equal_range(0).second != *comp.equal_range(0).second
        || *set.equal_range(3).first != *comp.equal_range(3).first
        || *set.equal_range(3).second != *comp.equal_range(3).second
        || *set.equal_range(8).first != *comp.equal_range(8).first
        || *set.equal_range(8).second != *comp.equal_range(8).second
        || *constset.equal_range(3).first != *constComp.equal_range(3).first
        || *constset.equal_range(3).second != *constComp.equal_range(3).second) {
        return (false);
    }
    return (true);
}

SetTests::SetTests(const SetTests& src) : TestClass(src) {}
const SetTests& SetTests::operator=(const SetTests& rhs) {
    if (this != &rhs) {
        this->stdTime = rhs.stdTime;
        this->ftTime = rhs.ftTime;
    }
    return (*this);
}
