#include "include/TreeTests.hpp"
#include "include/TestClass.hpp"
#include "../ft_containers.hpp"
#include <map>
#include <ctime>
#ifdef TEST
# include "../include/_rb_tree.hpp"
# include "../include/utility.hpp"
# include <set>
# include <cstdlib>
// Canonical methods
TreeTests::TreeTests() : TestClass() {}
TreeTests::~TreeTests() {}

// Inherited pure methods
void TreeTests::printLongResults() {
    print_header(" Tree Tests ");

    print_subheader("Construction Tests");
    print_test_result("construction - ", construction());

    print_subheader("Iterator Tests");
    print_test_result("iterator - ", iterator());
    print_test_result("reverse iterator - ", reverse_iterator());

    print_subheader("Modifiers Tests");
    print_test_result("insert - ", insert());
    /*print_test_result("push_back - ", push_back());
    print_test_result("pop_back - ", pop_back());
    print_test_result("insert - ", insert());
    print_test_result("erase - ", erase());
    print_test_result("swap - ", swap());
    print_test_result("clear - ", clear());


    print_subheader("Capacity Tests");
    print_test_result("size - ", size());
    print_test_result("resize - ", resize());
    print_test_result("capacity - ", capacity());
    print_test_result("reserve - ", reserve());

    print_subheader("Element Access Tests");
    print_test_result("operator[], at, front, back - ", element_access());

    print_subheader("Relational operator tests");
    print_test_result("relational operators and swap - ", relational_operators());*/
}
void    TreeTests::printShortResults() {
    std::cout << "Tree tests - ";
    if (construction()) {
        print_result(true);
    } else {
        print_result(false);
    }
}
double  TreeTests::timerTest() {
    clock_t begin, end;

    begin = clock();

    // construction
    //construction();



    end = clock();
    return ((double) (end - begin) / CLOCKS_PER_SEC);
}


//============================================================================//
//                                                                            //
//                              CONSTRUCTOR TESTS                             //
//                                                                            //
//============================================================================//
//====================================//
//        TREE CONSTRUCTION         //
//====================================//
bool    TreeTests::construction()
{
    typedef ft::_rb_map_tree<ft::pair<int, char> > TreeClass;

    // Default construction
    TreeClass dflt;
    // Copy Construction
    TreeClass toCpy;
    toCpy.tree_insert(ft::make_pair(100, 'a'));
    toCpy.tree_insert(ft::make_pair(17, 'c'));
    toCpy.tree_insert(ft::make_pair(1, 'z'));
    toCpy.tree_insert(ft::make_pair(900, '5'));
    toCpy.tree_insert(ft::make_pair(55, 'i'));
    TreeClass cpy_const(toCpy);

    // Equal operator overload
    TreeClass dfltEQ, cpy_constEQ;

    dfltEQ = dflt;
    cpy_constEQ = cpy_const;
    if (!trees_equal(cpy_const, toCpy)
        || !trees_equal(dfltEQ, dflt)
        || !trees_equal(cpy_constEQ, cpy_const)
        || !trees_equal(cpy_constEQ, toCpy)) {
        return (false);
    }
    return (true);
}


//============================================================================//
//                                                                            //
//                              ITERATOR TESTS                                //
//                                                                            //
//============================================================================//
bool    TreeTests::iterator() {
    typedef ft::_rb_map_tree<ft::pair<int, char> >::iterator tree_it;
    typedef std::set<ft::pair<int, char> >::iterator         set_it;
    srand (time(NULL));

    ft::_rb_map_tree<ft::pair<int, char> >  tree;
    std::set<ft::pair<int, char> >          set;
    int                                     random_number;
    char                                    character;

    character = 'A';
    for (int i = 0; i < 25; i++, character++) {
        random_number = rand();
        tree.tree_insert(ft::make_pair(random_number, character));
        set.insert(ft::make_pair(random_number, character));
    }

    tree_it itA = tree.begin();
    set_it compitA = set.begin();

    // quick check begin and end
    if (*--tree.end() != *set.rbegin()) {
        return (false);
    }

    // ++ begin - end
    // std::cerr << "++\n";
    for (; itA != tree.end(); itA++, compitA++) {
       //std::cerr << *itA << " \n";
       if ((*itA).first != (*compitA).first || (*itA).second != (*compitA).second) {
           return (false);
       }
    }

    // -- end to begin
    // std::cerr << "--\n";
    itA--;
    compitA--;
    for (; itA != tree.begin(); itA--, compitA--) {
        //std::cerr << *itA << " \n";
        if ((*itA).first != (*compitA).first || (*itA).second != (*compitA).second) {
            return (false);
        }
    }
    //std::cerr << *itA << " \n";
    if ((*itA).first != (*compitA).first || (*itA).second != (*compitA).second) {
        return (false);
    }
    return (true);
}

bool    TreeTests::reverse_iterator(void) {
    typedef ft::_rb_map_tree<ft::pair<int, char> >::reverse_iterator tree_it;
    typedef std::set<ft::pair<int, char> >::reverse_iterator         set_it;
    srand (time(NULL));

    ft::_rb_map_tree<ft::pair<int, char> >  tree;
    std::set<ft::pair<int, char> >          set;
    int                                     random_number;
    char                                    character;

    character = 'A';
    for (int i = 0; i < 25; i++, character++) {
        random_number = rand();
        tree.tree_insert(ft::make_pair(random_number, character));
        set.insert(ft::make_pair(random_number, character));
    }

    tree_it ritA = tree.rbegin();
    set_it compritA = set.rbegin();

    // quick check begin and end

    if (*--tree.rend() != *set.begin()) {
        return (false);
    }

    // ++ begin - end
    // std::cerr << "++\n";
    for (; ritA != tree.rend(); ritA++, compritA++) {
        //std::cerr << *ritA << " \n";
        if ((*ritA).first != (*compritA).first || (*ritA).second != (*compritA).second) {
            return (false);
        }
    }

    // -- end to begin
    // std::cerr << "--\n";
    ritA--;
    compritA--;
    for (; ritA != tree.rbegin(); ritA--, compritA--) {
        //std::cerr << *ritA << " \n";
        if ((*ritA).first != (*compritA).first || (*ritA).second != (*compritA).second) {
            return (false);
        }
    }
    //std::cerr << *ritA << " \n";
    if (*compritA != *ritA) {
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
//               ASSIGN               //
//====================================//
bool    TreeTests::insert() {

    ft::_rb_map_tree<ft::pair<int, char> > tree;

    tree.tree_insert(ft::make_pair(4, 'a'));
    tree.tree_insert(ft::make_pair(4, 'a'));
    tree.tree_insert(ft::make_pair(5, 'b'));
    tree.tree_insert(ft::make_pair(4, 'c'));
    tree.inOrderWalk(tree.getRoot());
    return (true);
}

//====================================//
//            PUSH_BACK               //
//====================================//
/*bool    VectorTests::push_back() {
    ft::vector<int>     myvec;
    ft::vector<int>     myvec2(10, 555);
    std::vector<int>    comp;
    std::vector<int>    comp2(10, 555);

    myvec.push_back(-4444);
    comp.push_back(-4444);
    if (!containers_equal(myvec, comp))
        return (false);
    for (int i = 0; i < 50; i++) {
        myvec.push_back(i);
        comp.push_back(i);
    }
    if (!containers_equal(myvec, comp))
        return (false);
    myvec2.push_back(987654);
    comp2.push_back(987654);
    if (!containers_equal(myvec2, comp2))
        return (false);

    return (true);
}

//====================================//
//             POP_BACK               //
//====================================//
bool    VectorTests::pop_back() {
    ft::vector<int>     myvec(30, 999);
    ft::vector<int>     myvec2;
    std::vector<int>    comp(30, 999);

    myvec.pop_back();
    comp.pop_back();
    if (!containers_equal(myvec, comp))
        return (false);

    for (int i = 0; i < 29; i++) {
        myvec.pop_back();
        comp.pop_back();
    }
    if (!containers_equal(myvec, comp))
        return (false);
    myvec2.pop_back();
    if (!containers_equal(myvec, comp))
        return (false);

    return (true);
}

//====================================//
//              INSERT                //
//====================================//
bool    VectorTests::insert() {

    ft::vector<int>     myvec(30, 5);
    std::vector<int>    comp(30, 5);

    // ==== Insert one val ==== //
    ft::vector<int>::iterator   vecCheck;
    std::vector<int>::iterator  compCheck;
    // reallocate
    vecCheck = myvec.insert((myvec.begin() + 5), 7);
    compCheck = comp.insert((comp.begin() + 5), 7);
    if (!containers_equal(myvec, comp) || *vecCheck != *compCheck)
        return (false);
    // No reallocate
    vecCheck = myvec.insert((myvec.begin() + 5), 30);
    compCheck = comp.insert((comp.begin() + 5), 30);
    if (!containers_equal(myvec, comp) || *vecCheck != *compCheck)
        return (false);

    // ==== Insert Mult val ==== //
    // reallocate
    myvec.insert(myvec.begin() + 20, 50, 44);
    comp.insert(comp.begin() + 20, 50, 44);
    if (!containers_equal(myvec, comp))
        return (false);
    // No reallocate
    myvec.insert((myvec.begin() + 30), 3, 900);
    comp.insert((comp.begin() + 30), 3, 900);
    if (!containers_equal(myvec, comp))
        return (false);

    // ==== Insert iterators ==== //
    // reallocate
    ft::vector<int>     tmpvec(100);
    std::vector<int>    tmpcomp(100);

    ft::vector<int>::iterator   firstvec = tmpvec.begin();
    std::vector<int>::iterator  firstcomp = tmpcomp.begin();
    ft::vector<int>::iterator   lastvec = tmpvec.end() - 1;
    std::vector<int>::iterator  lastcomp = tmpcomp.end() - 1;
    myvec.insert(myvec.begin() + 10, firstvec, lastvec);
    comp.insert(comp.begin() + 10, firstcomp, lastcomp);
    if (!containers_equal(myvec, comp))
        return (false);

    // No reallocation
    firstvec = tmpvec.begin() + 8;
    lastvec = tmpvec.begin() + 45;
    firstcomp = tmpcomp.begin() + 8;
    lastcomp = tmpcomp.begin() + 45;
    myvec.insert(myvec.begin() + 44, firstvec, lastvec);
    comp.insert(comp.begin() + 44, firstcomp, lastcomp);
    if (!containers_equal(myvec, comp))
        return (false);

    // ==== Edge casees ==== //
    myvec.insert(myvec.end(), 7);
    comp.insert(comp.end(), 7);
    if (!containers_equal(myvec, comp))
        return (false);
    myvec.insert(myvec.end(), 4, 555);
    comp.insert(comp.end(), 4, 555);
    if (!containers_equal(myvec, comp))
        return (false);
    myvec.insert(myvec.end(), myvec.begin(), myvec.end() - 1);
    comp.insert(comp.end(), comp.begin(), comp.end() - 1);
    if (!containers_equal(myvec, comp))
        return (false);
    myvec.insert(myvec.begin(), myvec.begin(), myvec.end());
    comp.insert(comp.begin(), comp.begin(), comp.end());
    if (!containers_equal(myvec, comp))
        return (false);

    return (true);
}

//====================================//
//               ERASE                //
//====================================//
bool    VectorTests::erase() {
    typedef ft::vector<int>::iterator   vecIterator;
    typedef std::vector<int>::iterator  compIterator;

    ft::vector<int>     vec;
    vecIterator         vecIt;
    std::vector<int>    comp;
    compIterator        compIt;

    for(size_t i = 0; i < 20; i++) {
        vec.push_back(i);
        comp.push_back(i);
    }

    vecIt = vec.erase(vec.begin());
    compIt = comp.erase(comp.begin());
    if (!containers_equal(vec, comp) || *vecIt != *compIt)
        return (false);

    vecIt = vec.erase(vec.begin() + 6, vec.end());
    compIt = comp.erase(comp.begin() + 6, comp.end());
    if (!containers_equal(vec, comp) || *vecIt != *compIt)
        return (false);

    vecIt = vec.erase(vec.end() - 1);
    compIt = comp.erase(comp.end() - 1);
    if (!containers_equal(vec, comp) || *vecIt != *compIt)
        return (false);

    vecIt = vec.erase(vec.begin(), vec.end());
    compIt = comp.erase(comp.begin(), comp.end());
    if (!containers_equal(vec, comp) || *vecIt != *compIt)
        return (false);

    return (true);
}

//====================================//
//               SWAP                 //
//====================================//
bool    VectorTests::swap() {
    ft::vector<int>     vecA(50, 155);
    ft::vector<int>     vecB;
    ft::vector<int>     vecC;
    std::vector<int>    compA(50, 155);
    std::vector<int>    compB;
    std::vector<int>    compC;

    for(size_t i = 0; i < 30; i++) {
        vecB.push_back(i);
        compB.push_back(i);
    }

    vecA.swap(vecB);
    compA.swap(compB);
    if (!containers_equal(vecA, compA) || !containers_equal(vecB, compB))
        return (false);

    vecA.swap(vecC);
    compA.swap(compC);
    if (!containers_equal(vecA, compA) || !containers_equal(vecC, compC))
        return (false);

    return (true);
}

//====================================//
//              CLEAR                 //
//====================================//
bool    VectorTests::clear() {
    ft::vector<int>     vecA(50, 155);
    ft::vector<int>     vecB;
    ft::vector<int>     vecC;
    std::vector<int>    compA(50, 155);
    std::vector<int>    compB;
    std::vector<int>    compC;

    for(size_t i = 0; i < 30; i++) {
        vecB.push_back(i);
        compB.push_back(i);
    }

    vecA.clear();
    compA.clear();
    if (!containers_equal(vecA, compA))
        return (false);

    vecB.clear();
    compB.clear();
    if (!containers_equal(vecB, compB))
        return (false);

    vecC.clear();
    compC.clear();
    if (!containers_equal(vecC, compC))
        return (false);

    return (true);
}



//============================================================================//
//                                                                            //
//                              CAPACITY TESTS                                //
//                                                                            //
//============================================================================//

//====================================//
//         SIZE & MAX SIZE            //
//====================================//
bool    VectorTests::size(void)
{
    ft::vector<int>     vec;
    std::vector<int>    comp;

    if (!containers_equal(vec, comp) || vec.size() != comp.size())
        return (false);
    for (size_t i = 0; i < 30; i++) {
        vec.push_back(i);
        comp.push_back(i);
    }
    if (!containers_equal(vec, comp) || vec.size() != comp.size())
        return (false);
    if (vec.max_size() != comp.max_size())
        std::cout << YELLOW << "max size differs\nstl: " << comp.max_size() << "\nft: " << vec.max_size() << RESET << '\n';

    vec.insert(vec.begin() + 7, 8, 550);
    comp.insert(comp.begin() + 7, 8, 550);
    if (!containers_equal(vec, comp) || vec.size() != comp.size())
        return (false);
    if (vec.max_size() != comp.max_size())
        std::cout << YELLOW << "max size differs\nstl: " << comp.max_size() << "\nft: " << vec.max_size() << RESET << '\n';

    for (size_t i = 0; i < 4; i++) {
        vec.pop_back();
        comp.pop_back();
    }
    if (!containers_equal(vec, comp) || vec.size() != comp.size())
        return (false);
    if (vec.max_size() != comp.max_size())
        std::cout << YELLOW << "max size differs\nstl: " << comp.max_size() << "\nft: " << vec.max_size() << RESET << '\n';

    return (true);
}

//====================================//
//               RESIZE               //
//====================================//
bool    VectorTests::resize(void)
{
    ft::vector<int>     vec(50, 300);
    std::vector<int>    comp(50, 300);

    vec.resize(2);
    comp.resize(2);
    if (!containers_equal(vec, comp))
        return (false);

    vec.resize(30, 80);
    comp.resize(30, 80);
    if (!containers_equal(vec, comp))
        return (false);

    vec.resize(60);
    comp.resize(60);
    if (!containers_equal(vec, comp))
        return (false);

    return (true);
}

//====================================//
//         CAPACITY & EMPTY           //
//====================================//
bool    VectorTests::capacity(void)
{
    ft::vector<int>     vec(50, 300);
    std::vector<int>    comp(50, 300);

    if (vec.capacity() != comp.capacity())
        return (false);

    vec.reserve(100);
    comp.reserve(100);
    if (vec.capacity() != comp.capacity())
        return (false);

    if (vec.empty() != comp.empty())
        return (false);

    vec.clear();
    comp.clear();
    if (vec.empty() != comp.empty())
        return (false);

    return (true);
}
//====================================//
//               RESERVE              //
//====================================//
bool    VectorTests::reserve(void)
{
    ft::vector<int>     vec(50, 300);
    std::vector<int>    comp(50, 300);

    vec.reserve(0);
    comp.reserve(0);
    if (!containers_equal(vec, comp))
        return (false);

    vec.reserve(133);
    comp.reserve(133);
    if (!containers_equal(vec, comp))
        return (false);

    return (true);
}

//============================================================================//
//                                                                            //
//                          ELEMENT ACCESS TESTS                              //
//                                                                            //
//============================================================================//

//====================================//
//    opeerator[], at, front, back    //
//====================================//
bool    VectorTests::element_access(void)
{
    ft::vector<int>      vec;
    std::vector<int>    comp;

    for (size_t i = 0; i < 25; i++) {
        vec.push_back(i);
        comp.push_back(i);
    }

    // OPERATOR []
    if (vec[0] != comp[0] || vec[20] != comp[20] || vec[24] != comp[24])
        return (false);

    // AT
    if (vec.at(4) != comp.at(4) || vec.at(0) != comp.at(0) || vec.at(24) != comp.at(24))
        return (false);

    // FRONT
    if (vec.front() != comp.front())
        return (false);

    // BACK
    if (vec.back() != comp.back())
        return (false);

    bool thrownExcpeption = false;
    try
    {
        vec.at(50);
    }
    catch(...)
    {
        thrownExcpeption = true;
    }
    if (!thrownExcpeption) {
        std::cout << RED << "no thrown exception for at() \n" << RESET;
        return (false);
    }

    return (true);
}

//============================================================================//
//                                                                            //
//                      RELATIONAL OPERATORS TESTS                            //
//                                                                            //
//============================================================================//

//====================================//
//   relational operators and swap    //
//====================================//
bool    VectorTests::relational_operators(void)
{
    ft::vector<int>     vec1;
    ft::vector<int>     vec2;

    // RELATIONAL OPERATORS
    if (!(vec1 == vec2) || vec1 != vec2 || vec1 < vec2 || vec1 > vec2 || !(vec1 <= vec2) || !(vec1 >= vec2))
        return (false);

    for (size_t i = 0; i < 25; i++) {
        vec1.push_back(i);
        vec2.push_back(i);
    }

    if (!(vec1 == vec2) || vec1 != vec2 || vec1 < vec2 || vec1 > vec2 || !(vec1 <= vec2) || !(vec1 >= vec2))
        return (false);

    vec1.pop_back();
    if (vec1 == vec2 || !(vec1 != vec2) || !(vec1 < vec2) || vec2 < vec1 || vec1 > vec2 || !(vec2 > vec1))
        return (false);
    if (!(vec1 <= vec2) || vec2 <= vec1 || vec1 >= vec2 || !(vec2 >= vec1))
        return (false);

    // SWAP && RELATIONAL OPERATORS
    ft::vector<int>     swapA(vec1);
    ft::vector<int>     swapB;

    ft::swap(vec1, swapB);
    if (swapA != swapB || !(swapA == swapB) || !vec1.empty())
        return (false);

    return (true);
}*/




TreeTests::TreeTests(const TreeTests& src) : TestClass(src) {}
const TreeTests& TreeTests::operator=(const TreeTests& rhs) {
    if (this != &rhs) {
        this->stdTime = rhs.stdTime;
        this->ftTime = rhs.ftTime;
    }
    return (*this);
}

#endif
