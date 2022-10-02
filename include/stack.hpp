#pragma once
#ifndef STACK_HPP
# define STACK_HPP

# include <cstddef>      // size_t
# include "vector.hpp"   // ft::vector

namespace ft {
    template<typename Type, class Container = ft::vector<Type> >
    class stack {
    public:
        // MEMBER TYPES
        typedef Type                       value_type;
        typedef typename ft::vector<Type>  container_type;
        typedef size_t                  size_type;

        // CONSTRUCTORS / DESTRUCTOR
        explicit stack (const container_type& ctnr = container_type()) : _ctnr(ctnr) {}
        stack( const stack& src) : _ctnr(src._ctnr) {}
        ~stack() {}
        stack& operator=(const stack& rhs) {
            _ctnr = rhs._ctnr;
        }

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
        template <typename T, class C>
        friend bool operator==(const stack<T,C>& lhs, const stack<T,C>& rhs);
        template <typename T, class C>
        friend bool operator!=(const stack<T,C>& lhs, const stack<T,C>& rhs);
        template <typename T, class C>
        friend bool operator<(const stack<T,C>& lhs, const stack<T,C>& rhs);
        template <typename T, class C>
        friend bool operator>(const stack<T,C>& lhs, const stack<T,C>& rhs);
        template <typename T, class C>
        friend bool operator<=(const stack<T,C>& lhs, const stack<T,C>& rhs);
        template <typename T, class C>
        friend bool operator>=(const stack<T,C>& lhs, const stack<T,C>& rhs);

    protected:
        container_type  _ctnr;
    };

    template <typename T, class C>
    bool operator==(const stack<T,C>& lhs, const stack<T,C>& rhs) {
        return (lhs._ctnr == rhs._ctnr);
    }
    template <typename T, class C>
    bool operator!=(const stack<T,C>& lhs, const stack<T,C>& rhs) {
        return (lhs._ctnr != rhs._ctnr);
    }
    template <typename T, class C>
    bool operator<(const stack<T,C>& lhs, const stack<T,C>& rhs) {
        return (lhs._ctnr < rhs._ctnr);
    }
    template <typename T, class C>
    bool operator>(const stack<T,C>& lhs, const stack<T,C>& rhs) {
        return (lhs._ctnr > rhs._ctnr);
    }
    template <typename T, class C>
    bool operator<=(const stack<T,C>& lhs, const stack<T,C>& rhs) {
        return (lhs._ctnr <= rhs._ctnr);
    }
    template <typename T, class C>
    bool operator>=(const stack<T,C>& lhs, const stack<T,C>& rhs) {
        return (lhs._ctnr >= rhs._ctnr);
    }
}

#endif
