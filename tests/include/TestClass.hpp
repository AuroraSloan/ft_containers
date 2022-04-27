#ifndef TESTCLASS_HPP
# define TESTCLASS_HPP

# define HDR "=========="
# define SUBHDR "--"
# define RED "\x1b[31m"
# define GREEN "\x1b[32m"
# define YELLOW "\x1b[33m"
# define MAGENTA "\x1b[35m"
# define CYAN "\x1b[36m"
# define RESET "\x1b[0m"


# include <iostream>

class TestClass {
public:

    TestClass();
    virtual ~TestClass();

    virtual void testOutput() = 0;
    virtual void testPerformance() = 0;

protected:
    /*template <typename Function>
    double timer(Function f) {
      clock_t begin, end;

        begin = clock();
        f();
        end = clock();
        return ((double) (end - begin) / CLOCKS_PER_SEC);
    }*/

    template <typename ContainerA, typename ContainerB>
    bool    containers_equal(ContainerA & A, ContainerB & B) {

        typename ContainerA::iterator   IteratorA;
        typename ContainerB::iterator   IteratorB;

        //check size
        size_t ASize, BSize;
        ASize = A.size();
        BSize = B.size();
        if (ASize != BSize)
            return (false);

        IteratorA = A.begin();
        IteratorB = B.begin();
        for (size_t i = 0; i < ASize; i++) {
            if (*(IteratorA + i) != *(IteratorB + i))
                return (false);
        }
        while (IteratorA != A.end() || IteratorB != B.end()) {
            if ((*(IteratorA) != *(IteratorB)) || IteratorA == A.end() || IteratorB == B.end())
                return (false);
            IteratorA++;
            IteratorB++;
        }
        return (true);
    }


    template <typename Container>
    bool    containers_equal(Container & A, Container & B, Container & C) {

        typedef typename Container::size_type size_type;
        typedef typename Container::iterator  iterator;

        //check size
        size_type Asize, Bsize, Csize;

        Asize = A.size();
        Bsize = B.size();
        Csize = C.size();
        if (Asize != Bsize || Asize != Csize || Bsize != Csize)
            return (false);

        //check items
        iterator Aiterator, Biterator, Citerator;
        Aiterator = A.begin();
        Biterator = B.begin();
        Citerator = C.begin();
        for (size_type i = 0; i < Asize; i++) {
            if (*(Aiterator + i) != *(Biterator + i)
                || *(Aiterator + i) != *(Citerator + i)
                || *(Biterator + i) != *(Citerator + i))
                return (false);
        }
        return (true);
    }


    template <typename Container>
    void    print_container(Container container, std::string name) {
        typedef typename Container::iterator iterator;

        std::cout << name << '\n';
        for(iterator it = container.begin(); it != container.end(); it++) {
            std::cout << *it << ' ';
        }
        std::cout << '\n';
    }

    void    print_test_result(std::string testName, bool success);
    void    print_time_results(double stdtime, double fttime);
    void    print_subheader(std::string subHeader);

    double stdTime;
    double ftTime;

    TestClass(const TestClass& src);

private:

    const TestClass& operator=(const TestClass& rhs);

};
#endif
