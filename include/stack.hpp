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

        bool empty(void) const {
            return (_ctnr.empty());
        }

        size_t size(void) const {
            return (_ctnr.size());
        }

        value_type& top(void) {
            return (_ctnr.back());
        }
        const value_type& top(void) const {
            return (_ctnr.back());
        }

        void push (const value_type& val) {
            _ctnr.push_back(val);
        }

        void pop(void) {
            _ctnr.pop_back();
        }

    private:
        container_type  _ctnr;
    };

    template <typename T, class Container>
    bool operator==(const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
        return (lhs == rhs);
    }
    template <typename T, class Container>
    bool operator!=(const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
        return (lhs != rhs);
    }
    template <typename T, class Container>
    bool operator<(const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
        return (lhs < rhs);
    }
    template <typename T, class Container>
    bool operator>(const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
        return (lhs > rhs);
    }
    template <typename T, class Container>
    bool operator<=(const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
        return (lhs <= rhs);
    }
    template <typename T, class Container>
    bool operator>=(const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
        return (lhs >= rhs);
    }
}

#endif
