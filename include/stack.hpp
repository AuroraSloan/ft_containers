#ifndef STACK_HPP
# define STACK_HPP

# include <cstddef>      // size_t
# include "vector.hpp"   // ft::vector

namespace ft {
    template<typename T, class Container = ft::vector<T> >
    class stack {
    public:
        // MEMBER TYPES
        typedef T                       value_type;
        typedef typename ft::vector<T>  container_type;
        typedef size_t                  size_type;

        // CONSTRUCTORS / DESTRUCTOR
        explicit stack (const container_type& ctnr = container_type()) : _ctnr(ctnr) {}
    private:
        container_type  _ctnr;
    };
}

#endif
