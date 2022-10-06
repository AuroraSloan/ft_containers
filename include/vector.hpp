#pragma once
#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>          // std::allocator
# include <iterator>        // std::iterator
# include <cstddef>         // ptrdiff_t, size_t
# include <iostream>        // std::cout
# include <stdexcept>
# include "iterator.hpp"

# include "type_traits.hpp"
# include "algorithm.hpp"

namespace ft {
    template<typename T, class Alloc = std::allocator <T> >
    class vector {
    public:

        // MEMBER TYPES
        typedef T                                           value_type;
        typedef Alloc                                       allocator_type;
        typedef typename allocator_type::reference          reference;
        typedef typename allocator_type::const_reference    const_reference;
        typedef typename allocator_type::pointer            pointer;
        typedef typename allocator_type::const_pointer      const_pointer;
        typedef typename ft::random_access_iterator<T>      iterator;
        typedef typename ft::reverse_iterator<iterator>     reverse_iterator;
        typedef const iterator                              const_iterator;
        typedef const reverse_iterator                      const_reverse_iterator;
        typedef ptrdiff_t                                   difference_type;
        typedef size_t                                      size_type;

    private:
        pointer _begin;
        size_t _size;
        size_t _capacity;
        allocator_type _alloc;

    public:
        // CONSTRUCTORS / DESTRUCTOR
        explicit vector(allocator_type const &alloc = allocator_type()) : _begin(), _size(0), _capacity(0), _alloc(alloc) {}
        explicit vector(size_type n, value_type const &val = value_type(),
                        allocator_type const &alloc = allocator_type()) : _alloc(alloc) {
            _allocate(n);
            _construct(_begin, n, val);
        }
        template<class InputIterator>
        vector(InputIterator first, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type last,
               allocator_type const &alloc = allocator_type()) : _alloc(alloc) {
            size_type n = static_cast<size_type>(std::distance(first, last));
            _allocate(n);
            _construct(_begin, n, first);
        }
        vector(vector const &x) : _alloc(allocator_type()) {
            _allocate(x._capacity);
            _construct(_begin, x._size, x._begin);
        }
        ~vector() {
            _dealoc();
        }

        // OPERATOR=
        vector &operator=(const vector &rhs) {
            if (this != &rhs) {
                _dealoc();
                _size = 0;
                _allocate(rhs.capacity());
                _construct(_begin, rhs.size(), rhs._begin);
            }
            return (*this);
        }

        // ITERATORS
        iterator begin() { return (iterator(_begin)); }
        const_iterator begin() const { return (const_iterator(_begin)); }

        iterator end() { return (iterator(_begin + _size)); }
        const_iterator end() const { return (const_iterator(_begin + _size)); }

        reverse_iterator rbegin() { return (reverse_iterator(_begin + _size)); }
        const_reverse_iterator rbegin() const { return (const_reverse_iterator(_begin + _size)); }

        reverse_iterator rend() { return (reverse_iterator(_begin)); }
        const_reverse_iterator rend() const { return (const_reverse_iterator(_begin)); }


        // CAPACITY
        size_type size() const { return (_size); }

        size_type max_size() { return (_alloc.max_size()); }

        void resize(size_type n, value_type val = value_type()) {
            if (n > _capacity)
                reserve(n);
            while(_size < n) {
                push_back();
                /*_alloc.construct(_begin + _size, val);
                _size++;*/
            }
            while(n < _size) {
                pop_back();
                /*--_size;
                _alloc.destroy(_begin + _size);*/
            }
        }

        size_type capacity() const { return (_capacity); }

        bool empty() const { return (!size()); }

        void reserve(size_type n) {
            if (n > max_size()) {
                throw std::length_error("fix these words later");
            }
            if (n > _capacity) {
                pointer _newBegin = _alloc.allocate(n);
                size_type tmpSize = _size;

                _construct(_newBegin, _size, _begin);
                _dealoc();
                _begin = _newBegin;
                _size = tmpSize;
                _capacity = n;
                return;
            }
        }


        // ELEMENT ACCESS
        reference operator[](size_type n) { return (*(_begin + n)); }
        const_reference operator[](size_type n) const { return (*(_begin + n)); }

        reference at(size_type n) {
            if (n >= size())
                throw std::out_of_range("vector");
            return (_begin[n]);
        }
        const_reference at(size_type n) const {
            if (n >= size())
                throw std::out_of_range("vector");
            return (_begin[n]);
        }

        reference front() { return (*_begin); }
        const_reference front() const { return (*_begin); }

        reference back() { return (*(_begin + _size - 1)); }
        const_reference back() const { return (*(_begin + _size - 1)); }

        value_type* data() {
            return (_begin);
        }
        const value_type* data() const {
            return (_begin);
        }

        // MODIFIERS
        template<class InputIterator>
        void assign(InputIterator first, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type last) {
            size_type size = static_cast<size_type>(std::distance(first, last));
            if (size > _capacity) {
                _dealoc();
                _capacity = size * 2;
                _allocate(_capacity);
            } else {
                clear();
            }
            _construct(_begin, size, first);
        }

        void assign(size_type n, value_type const &val) {
            if (n > _capacity) {
                _dealoc();
                _capacity = n * 2;
                _allocate(_capacity);
            } else {
                clear();
            }
            _construct(_begin, n, val);
        }

        void push_back(value_type const &val) {
            if (_size == _capacity)
                reserve((size() == 0 ? 1 : size()) * 2);
            _alloc.construct(_begin + _size, val);
            //*(_begin + _size) = val;
            _size++;
        }

        void pop_back() {
            if (!empty()) {
                --_size;
                _alloc.destroy(_begin + _size);
            }
        }

        iterator insert(iterator position, value_type const &val) {
            size_type pos = static_cast<size_type>(std::distance(begin(), position));

            if (_size == _capacity)
                reserve((size() == 0 ? 1 : size()) * 2);
            _construct_from_end(pos, 0);
            _alloc.construct(_begin + pos, val);
            ++_size;
            return (iterator(_begin + pos));
        }

        void insert(iterator position, size_type n, value_type const &val) {
            size_type pos = static_cast<size_type>(std::distance(begin(), position));

            if (_size + n > _capacity)
                reserve((_size + n) * 2);
            _construct_from_end(pos + n, n - 1);
            for (size_type i = 0; i < n; i++) {
                _alloc.destroy(_pbegin + i);
                _alloc.construct(_pbegin + i, val);
                _size++;
            }
        }

        template<class InputIterator>
        void insert(iterator position,
                    typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type first,
                    InputIterator last) {
            pointer _pbegin, _pend;
            size_type location = static_cast<size_type>(std::distance(begin(), position));
            size_type n = static_cast<size_type>(std::distance(first, last));

            if (_passedMaxCapacity(_size + n))
                reserve((_size + n) * 2);
            _pbegin = _begin + location;
            _pend = _begin + location + n;
            _construct_from_end(_pend, n);
            for (size_type i = 0; i < n; i++) {
                _alloc.destroy(_pbegin + i);
                _alloc.construct(_pbegin + i, *(first + i));
                _size++;
            }
        }

        iterator erase(iterator position) {
            return (_erase(position, 1));
        }
        iterator erase(iterator first, iterator last) {
            return (_erase(first, static_cast<size_type>(std::distance(first, last))));
        }

        void swap(vector &x) {
            _swap(_begin, x._begin);
            _swap(_size, x._size);
            _swap(_capacity, x._cap);
            _swap(_alloc, x._alloc);
        }

        void clear() {
            size_t size = 0;
            while (size < _size) {
                _alloc.destroy(_begin + size);
                ++size;
            }
            _size = 0;
        }


        // ALLOCATOR
        allocator_type get_allocator() const { return (_alloc); }


    private:

        void _dealoc(void) {
            clear();
            _alloc.deallocate(_begin, capacity());
        }

        void _allocate(size_type n) {
            _begin = _alloc.allocate(n);
            _capacity = n;
            _size = 0;
        }

        void _construct(pointer start, size_type n, value_type val) {
            for (size_type i = 0; i < n; i++) {
                _alloc.construct(start + i, val);
                _size++;
            }
        }
        void _construct(pointer start, size_type n, pointer src) {
            for (size_type i = 0; i < n; i++) {
                _alloc.construct(start + i, *(src + i));
                _size++;
            }
        }
        /*void _construct(pointer &start, size_type n, value_type val) {
            for (size_type i = 0; i < n; i++) {
                _alloc.construct(start++, val);
                _size++;
            }
        }

        void _construct(pointer &start, size_type n, pointer src) {
            for (size_type i = 0; i < n; i++) {
                _alloc.construct(start++, *(src + i));
                _size++;
            }
        }

        void _construct(pointer &start, pointer src) {
            for (size_type i = 0; i < _size; i++)
                _alloc.construct(start++, *(src + i));
        }

        void _construct(pointer &start, size_type n, iterator src) {
            for (size_type i = 0; i < n; i++) {
                _alloc.construct(start++, *(src + i));
                _size++;
            }
        }*/

        void _construct_from_end(size_type index, size_type extra) {
            size_t new_last_pos = _size + extra;
            for (; new_last_pos - 1 > index; new_last_pos--) {
                _alloc.construct(_begin + new_last_pos, *(_begin + new_last_pos - 1));
                _alloc.destroy(_begin + new_last_pos - 1);
            }
        }

        iterator _erase(iterator position, size_type n) {
            pointer start = _begin + static_cast<size_type>(std::distance(begin(), position));
            size_type j = 0;

            for (; j < n; j++) {
                _alloc.destroy(start + j);
                _size--;
            }
            for (size_type i = 0; start + j != _end; i++) {
                _alloc.destroy(start + i);
                _alloc.construct(start + i, *(start + j));
                j++;
            }
            _end = _begin + _size;
            _alloc.destroy(_end);

            return (iterator(start));
        }

        template<typename S>
        void _swap(S &a, S &b) {
            S tmp = a;
            a = b;
            b = tmp;
        }

    };

    template<typename T, class Alloc>
    bool operator==(ft::vector<T, Alloc> const &lhs, ft::vector<T, Alloc> const &rhs) {
        return (lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
    }

    template<typename T, class Alloc>
    bool operator!=(ft::vector<T, Alloc> const &lhs, ft::vector<T, Alloc> const &rhs) {
        return (!(lhs == rhs));
    }

    template<typename T, class Alloc>
    bool operator<(ft::vector<T, Alloc> const &lhs, ft::vector<T, Alloc> const &rhs) {
        return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
    }

    template<typename T, class Alloc>
    bool operator>(ft::vector<T, Alloc> const &lhs, ft::vector<T, Alloc> const &rhs) {
        return (rhs < lhs);
    }

    template<typename T, class Alloc>
    bool operator<=(ft::vector<T, Alloc> const &lhs, ft::vector<T, Alloc> const &rhs) {
        return (!(rhs < lhs));
    }

    template<typename T, class Alloc>
    bool operator>=(ft::vector<T, Alloc> const &lhs, ft::vector<T, Alloc> const &rhs) {
        return (!(lhs < rhs));
    }

    template<typename T, class Alloc>
    void swap(vector<T, Alloc> & lhs, vector<T, Alloc> &rhs) {
        lhs.swap(rhs);
    }
}

#endif
