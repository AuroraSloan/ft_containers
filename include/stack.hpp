#ifndef STACK_HPP
# define STACK_HPP

# include <cstddef>      // size_t
# include "vector.hpp"   // ft::vector

namespace ft {
    template<typename T>
    class stack {
        public:
            stack(void) : var(5) {}
            int var;

            // MEMBER TYPES
            typedef T                       value_type;
            typedef typename ft::vector<T>  container_type;
            typedef size_t                  size_type;

            // CONSTRUCTORS / DESTRUCTOR

    };
}

#endif
