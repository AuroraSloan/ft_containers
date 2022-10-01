#include "include/MapTests.hpp"
#include "include/TestClass.hpp"
#include "../ft_containers.hpp"
#include <map>
#include <ctime>
#include <cstdlib>
#include <utility>
#ifdef TEST
# include "../include/map.hpp"
# else
namespace ft = std;
#endif
// Canonical methods
MapTests::MapTests() : TestClass() {}
MapTests::~MapTests() {}

// Inherited pure methods
void MapTests::printLongResults() {
    print_header(" Map Tests ");

    print_subheader("Construction Tests");
    print_test_result("construction - ", construction());

    print_subheader("Iterator Tests");
    print_test_result("iterator - ", iterator());
    print_test_result("reverse iterator - ", reverse_iterator());

    print_subheader("Capacity Tests");
    print_test_result("capacity - ", capacity());

    print_subheader("Element Access Tests");
    print_test_result("Bracket Operator - ", bracketOperator());
    print_test_result("at - ", at());

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
void    MapTests::printShortResults() {
    std::cout << "Map tests - ";

    if (construction() && iterator() && reverse_iterator() && capacity() && bracketOperator() && at() && insert()
    && erase() && clear() && swap() && find() && count() && bounds_range()) {
        print_result(true);
    } else {
        print_result(false);
    }
}
double  MapTests::timerTest() {
    clock_t begin, end;

    begin = clock();

    // construction
    construction();

    // iterator
    iterator();
    reverse_iterator();

    //capacity
    capacity();

    // element access
    bracketOperator();
    at();

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
//          MAP CONSTRUCTION          //
//====================================//
bool    MapTests::construction()
{
    typedef ft::map<int, char> Map;
    typedef std::map<int, char> Comp;

    // Copy Construction
    Map toCpy;
    Comp comp_toCpy;

    _generate_random_maps(toCpy, comp_toCpy, 10);

    Map cpy_const(toCpy);
    Comp comp_cpy_const(comp_toCpy);

    // Iterator constructor
    Map itConst(toCpy.begin(), toCpy.end());
    Comp comp_itConst(comp_toCpy.begin(), comp_toCpy.end());

    // Equal operator overload
    Map cpy_constEQ = cpy_const;
    Comp comp_cpy_constEQ = comp_cpy_const;

    if (!maps_equal(cpy_const, toCpy, comp_cpy_const)
        || !maps_equal(cpy_constEQ, cpy_const, comp_cpy_constEQ)
        || !maps_equal(cpy_constEQ, toCpy)
        || !maps_equal(toCpy, itConst, comp_itConst)) {
        return (false);
    }

    // Range Constructor
    Map range;
    _generate_random_maps(range, 30);

    Map range_constructed(range.begin(), range.end());
    if (!maps_equal(range, range_constructed)) {
        return (false);
    }

    return (true);
}


//============================================================================//
//                                                                            //
//                              ITERATOR TESTS                                //
//                                                                            //
//============================================================================//
bool    MapTests::iterator() {
    ft::map<int, char>              map;
    std::map<int, char>             comp;
    ft::map<int, char>::iterator    map_it;
    std::map<int, char>::iterator   comp_it;


    _generate_random_maps(map, comp, 60);

    map_it = map.begin();
    comp_it = comp.begin();

    // ++ begin - end
    for (; map_it != map.end(); map_it++, comp_it++) {
        if ((*map_it).first != (*comp_it).first || (*map_it).second != (*comp_it).second || comp_it == comp.end()) {
            return (false);
        }
    }

    // -- end to begin
    map_it--;
    comp_it--;
    for (; map_it != map.begin(); map_it--, comp_it--) {
        if ((*map_it).first != (*comp_it).first || (*map_it).second != (*comp_it).second || comp_it == comp.begin()) {
            return (false);
        }
    }
    if ((*map_it).first != (*comp_it).first || (*map_it).second != (*comp_it).second) {
        return (false);
    }
    return (true);
}

bool    MapTests::reverse_iterator() {
    ft::map<int, char>                      map;
    std::map<int, char>                     comp;
    ft::map<int, char>::reverse_iterator    map_rit;
    std::map<int, char>::reverse_iterator   comp_rit;

    _generate_random_maps(map, comp, 60);
    map_rit = map.rbegin();
    comp_rit = comp.rbegin();

    // ++ rbegin - rend
    for (; map_rit != map.rend(); map_rit++, comp_rit++) {
        if ((*map_rit).first != (*comp_rit).first || (*map_rit).second != (*comp_rit).second || comp_rit == comp.rend()) {
            return (false);
        }
    }

    // -- rend to rbegin
    map_rit--;
    comp_rit--;
    for (; map_rit != map.rbegin(); map_rit--, comp_rit--) {
        if ((*map_rit).first != (*comp_rit).first || (*map_rit).second != (*comp_rit).second || comp_rit == comp.rbegin()) {
            return (false);
        }
    }
    if ((*map_rit).first != (*comp_rit).first || (*map_rit).second != (*comp_rit).second) {
        return (false);
    }
    return (true);
}

//============================================================================//
//                                                                            //
//                              CAPACITY TESTS                                //
//                                                                            //
//============================================================================//
bool    MapTests::capacity() {
    // ADD MORE TESTS ONCE DELETE AND CLEAR ETC ARE DONE
    ft::map<int, int> map;
    std::map<int, int> std;

    if (map.max_size() != std.max_size()) {
        std::cerr << YELLOW << "m: " << map.max_size() << "s: " << std.max_size() << RESET << std::endl;
    }

    if (!map.empty()) {
        return (false);
    }

    map.insert(ft::make_pair(65412, 'z'));
    if (map.empty()) {
        return (false);
    }

    for (int i = 0; i < 1000; i++) {
        map.insert(ft::make_pair(i, 'a'));
    }
    if (map.size() != 1001 || map.empty()) {
        return (false);
    }


    return (true);
}
//============================================================================//
//                                                                            //
//                          ELEMENT ACCESS TESTS                              //
//                                                                            //
//============================================================================//
//====================================//
//          BRACKET OPERATOR          //
//====================================//
bool    MapTests::bracketOperator() {
    ft::map<int, char> map;
    std::map<int, char> comp;

    map[4] = 'L';
    comp[4] = 'L';
    map[17] = 'M';
    comp[17] = 'M';
    map[17] = 'Z';
    comp[17] = 'Z';
    map[1];
    comp[1];


    if (!maps_equal(map, comp)) {
        return (false);
    }
    return (true);
}
//====================================//
//                 AT                 //
//====================================//
bool    MapTests::at() {
    ft::map<int, char> map;
    std::map<int, char> comp;


    _generate_ordered_maps(map, comp, 50);
    map.at(17) = 'Z';
    comp.at(17) = 'Z';
    map.at(49) = 'F';
    comp.at(49) = 'F';

    const ft::map<int, char> constMap(map);
    const std::map<int, char> constComp(comp);
    const char mapC = constMap.at(2);
    const char compC = constComp.at(2);

    int errorsCaught = 0;
    try {
        map.at(50);
    } catch (const std::exception& ex){
        errorsCaught++;
    }
    try {
        comp.at(50);
    } catch (const std::exception& ex){
        errorsCaught++;
    }

    if (!maps_equal(map, comp) || errorsCaught != 2 || mapC != compC) {
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
bool    MapTests::insert() {

    // INSERT PAIR VALUE
    ft::map<int, char> map;
    std::map<int, char> comp;

    _generate_random_maps(map, comp, 50);
    map.insert(ft::make_pair(4, 'a'));
    comp.insert(std::make_pair(4, 'a'));
    map.insert(ft::make_pair(4, 'z'));
    comp.insert(std::make_pair(4, 'z'));

    if (!maps_equal(map, comp)) {
        return (false);
    }

    // INSERT POSITION AND PAIR VALUE
    ft::map<int, char> map2;
    std::map<int, char> comp2;

    // Good Hint
    for (int i = 0; i < 25; i++) {
        if (i == 7) {
            continue ;
        }
        map2.insert(ft::make_pair(i, 'l'));
        comp2.insert(std::make_pair(i, 'l'));
    }
        // middle of
    ft::map<int, char>::iterator mapIt2 = map2.begin();
    std::map<int, char>::iterator compIt2 = comp2.begin();
    for (int i = 1; i < 7; i++) {
        mapIt2++;
        compIt2++;
    }
    map2.insert(mapIt2, ft::make_pair(7, 'b'));
    comp2.insert(compIt2, std::make_pair(7, 'b'));
        // end of
    ft::map<int, char>::iterator mapLast = map2.end();
    std::map<int, char>::iterator compLast = comp2.end();
    map2.insert(--mapLast, ft::make_pair(28, 'z'));
    comp2.insert(--compLast, std::make_pair(28, 'z'));
    if (!maps_equal(map2, comp2)) {
        return (false);
    }

    // Bad Hint
    map2.insert(map2.begin(), ft::make_pair(7777, 'R'));
    comp2.insert(comp2.begin(), std::make_pair(7777, 'R'));

    if (!maps_equal(map2, comp2)) {
        return (false);
    }

    // INSERT BY ITERATORS
    _generate_random_maps(map2, comp2, 50);
    map2.insert(map.begin(), map.end());
    comp2.insert(comp.begin(), comp.end());
    if (!maps_equal(map2, comp2)) {
        return (false);
    }

    return (true);
}
//====================================//
//               ERASE                //
//====================================//
bool    MapTests::erase() {
    ft::map<int, char> map;
    std::map<int, char> comp;

    // ERASE BY KEY
    _generate_ordered_maps(map, comp, 30);
    map.erase(10);
    comp.erase(10);
    map.erase(27);
    comp.erase(27);
    map.erase(0);
    comp.erase(0);
    map.erase(29);
    comp.erase(29);

    // edge case
    map.erase(0);
    comp.erase(0);
    map.erase(29);
    comp.erase(29);
    for (int i = 0; i < 30; i++) {
        map.erase(i);
        comp.erase(i);
    }

    _generate_random_maps(map, comp, 100);

    ft::map<int, char>::iterator mapIt = map.begin();
    std::map<int, char>::iterator compIt = comp.begin();

    for (int i = 0; i < 13; i++, ++mapIt, ++compIt) {}
    map.erase(mapIt);
    comp.erase(compIt);

    map.erase(map.begin());
    comp.erase(comp.begin());

    mapIt = map.begin();
    compIt = comp.begin();
    for (int i = 0; i < 88; i++, ++mapIt, ++compIt) {}
    map.erase(mapIt);
    comp.erase(compIt);

    map.erase(--(map.end()));
    comp.erase(--(comp.end()));
    if (!maps_equal(map, comp)) {
        return (false);
    }

    _generate_ordered_maps(map, comp, 30);
    // range
    map.erase(map.begin(), map.end());
    comp.erase(comp.begin(), comp.end());

    if (!maps_equal(map, comp)) {
        return (false);
    }
    return (true);
}

//====================================//
//              CLEAR                 //
//====================================//
bool    MapTests::clear() {
    ft::map<int, char> map;
    std::map<int, char> comp;

    _generate_random_maps(map, comp, 1000);
    map.clear();
    comp.clear();

    if (!maps_equal(map, comp)) {
        return (false);
    }

    return (true);
}

//====================================//
//              SWAP                 //
//====================================//
bool    MapTests::swap() {
    ft::map<int, char> mapA;
    ft::map<int, char> mapB;
    ft::map<int, char>::iterator mapIt;
    std::map<int, char> compA;
    std::map<int, char> compB;
    std::map<int, char>::iterator compIt;

    _generate_ordered_maps(mapA, compA, 100);
    _generate_random_maps(mapB, compB, 200);

    mapIt = mapB.begin();
    compIt = compB.begin();
    for(int i = 0; i < 40; i++) {
        mapIt++;
        compIt++;
    }
    int mapInt = (*mapIt).first;
    int compInt = (*compIt).first;


    mapA.swap(mapB);
    compA.swap(compB);

    if (!maps_equal(mapA, compA) || !maps_equal(mapB, compB)
        || mapInt != (*mapIt).first || compInt != (*compIt).first) {
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
bool    MapTests::find() {
    ft::map<int, char> map;
    std::map<int, char> comp;

    for (int i = 0; i < 50; i++) {
        map.insert(ft::make_pair(i, 'D'));
        comp.insert(std::make_pair(i, 'D'));
    }

    if ((*map.find(7)).first != (*comp.find(7)).first) {
        return (false);
    }
    if ((*map.find(0)).first != (*comp.find(0)).first) {
        return (false);
    }

    if (map.find(52) != map.end() || comp.find(52) != comp.end()) {
        return (false);
    }

    const ft::map<int, char> constMap(map);
    const std::map<int, char> constComp(comp);
    ft::map<int, char>::const_iterator mapIt = map.find(14);
    std::map<int, char>::const_iterator compIt = comp.find(14);
    if ((*mapIt).first != (*compIt).first) {
        return (false);
    }

    return (true);
}
//====================================//
//               Count                 //
//====================================//
bool    MapTests::count() {
    ft::map<int, char> map;
    std::map<int, char> comp;

    _generate_ordered_maps(map, comp, 30);

    if (map.count(29) != comp.count(29) || map.count(50) != comp.count(50)) {
        return (false);
    }
    return (true);
}
//====================================//
//          LOWER_BOUND               //
//====================================//
bool    MapTests::bounds_range() {
    ft::map<int, char> map;
    std::map<int, char> comp;

    _generate_ordered_maps(map, comp, 10);
    map.erase(8);
    comp.erase(8);

    const ft::map<int, char> constMap(map);
    const std::map<int, char> constComp(comp);


    // LOWER
    if ((*map.lower_bound(6)).first != (*comp.lower_bound(6)).first
        || (*map.lower_bound(8)).first != (*comp.lower_bound(8)).first
        || (*map.lower_bound(9)).first != (*comp.lower_bound(9)).first
        || (*constMap.lower_bound(2)).first != (*constComp.lower_bound(2)).first) {
        return (false);
    }
    // UPPER
    if ((*map.upper_bound(6)).first != (*comp.upper_bound(6)).first
        || (*map.upper_bound(8)).first != (*comp.upper_bound(8)).first
        || (*map.upper_bound(0)).first != (*comp.upper_bound(0)).first
        || (*constMap.upper_bound(2)).first != (*constComp.upper_bound(2)).first) {
        return (false);
    }
    // EDGE
    if (map.lower_bound(13) != map.end() || comp.lower_bound(13) != comp.end()
        || map.upper_bound(13) != map.end() || comp.upper_bound(13) != comp.end()) {
        return (false);
    }
    // RANGE
    if (map.equal_range(0).first->first != comp.equal_range(0).first->first
        || map.equal_range(0).second->first != comp.equal_range(0).second->first
        || map.equal_range(3).first->first != comp.equal_range(3).first->first
        || map.equal_range(3).second->first != comp.equal_range(3).second->first
        || map.equal_range(8).first->first != comp.equal_range(8).first->first
        || map.equal_range(8).second->first != comp.equal_range(8).second->first
        || constMap.equal_range(3).first->first != constComp.equal_range(3).first->first
        || constMap.equal_range(3).second->first != constComp.equal_range(3).second->first) {
        return (false);
    }
    return (true);
}

MapTests::MapTests(const MapTests& src) : TestClass(src) {}
const MapTests& MapTests::operator=(const MapTests& rhs) {
    if (this != &rhs) {
        this->stdTime = rhs.stdTime;
        this->ftTime = rhs.ftTime;
    }
    return (*this);
}
