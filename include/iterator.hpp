#pragma once
#ifndef ITERATOR_HPP
# define ITERATOR_HPP

# include <cstddef>         // ptrdiff_t, size_t

namespace ft {

    // ITERATOR TRAITS
    template <typename Iterator>
    struct iterator_traits {
        typedef typename Iterator::difference_type      difference_type;
        typedef typename Iterator::value_type           value_type;
        typedef typename Iterator::pointer              pointer;
        typedef typename Iterator::reference            reference;
        typedef typename Iterator::iterator_category    iterator_category;
    };

    // === if we make an iterator from a regular pointer we will have access to all the types we need....=== //
    template <typename T>
    struct iterator_traits<T*> {
        typedef ptrdiff_t                                   difference_type;
        typedef T                                           value_type;
        typedef T*                                          pointer;
        typedef T&                                          reference;
        typedef typename std::random_access_iterator_tag    iterator_category;
    };
    template <typename T>
    struct iterator_traits<const T*> {
        typedef const ptrdiff_t                                     difference_type;
        typedef const T                                             value_type;
        typedef const T*                                            pointer;
        typedef T&                                                  reference;
        typedef typename std::random_access_iterator_tag const      iterator_category;
    };

    // RANDOM ACCESS ITERATOR
    template <typename T>
    class random_access_iterator : public std::iterator<std::random_access_iterator_tag, T> {

    public:
        typedef typename ft::iterator_traits<T*>::difference_type       difference_type;
        typedef typename ft::iterator_traits<T*>::value_type            value_type;
        typedef typename ft::iterator_traits<T*>::pointer               pointer;
        typedef typename ft::iterator_traits<T*>::reference             reference;
        typedef typename ft::iterator_traits<T*>::iterator_category     iterator_category;

        random_access_iterator() : _data() {}
        random_access_iterator(value_type *x) : _data(x) {}
        random_access_iterator(random_access_iterator const & src) : _data(src._data) {}
        ~random_access_iterator() {}

        reference   operator*() const { return (*_data); }
        pointer     operator->() const { return (_data); }

        random_access_iterator const & operator=(random_access_iterator const &rhs) {
            if (this != &rhs)
                _data = rhs._data;
            return (*this);
        }

        random_access_iterator & operator++() {
            ++_data;
            return (*this);
        }

        random_access_iterator operator++(int) {
            random_access_iterator tmp(*this);
            _data++;
            return tmp;
        }

        random_access_iterator & operator--() {
            --_data;
            return (*this);
        }

        random_access_iterator operator--(int) {
            random_access_iterator tmp(*this);
            _data--;
            return tmp;
        }

        random_access_iterator operator+(difference_type x) const { return (random_access_iterator(_data + x)); }
        random_access_iterator operator-(difference_type x) const { return (random_access_iterator(_data - x)); }
        difference_type operator-(random_access_iterator const & rhs) { return (_data - rhs._data); }

        random_access_iterator & operator+=(difference_type x) {
            _data += x;
            return (*this);
        }
        random_access_iterator & operator-=(difference_type x) {
            _data -= x;
            return (*this);
        }

        reference   operator[](difference_type i) const { return (*(_data + i)); }
        pointer base() const { return (_data); }

    private:
        pointer _data;

    };
    template <typename T>
    typename ft::random_access_iterator<T> operator+(typename random_access_iterator<T>::difference_type lhs, ft::random_access_iterator<T> &rhs) { return (ft::random_access_iterator<T>(rhs + lhs)); }
    template <typename T>
    bool operator==(ft::random_access_iterator<T> const &lhs, ft::random_access_iterator<T> const &rhs) { return (lhs.base() == rhs.base()); }
    template <typename T>
    bool operator!=(ft::random_access_iterator<T> const &lhs, ft::random_access_iterator<T> const &rhs) { return (lhs.base() != rhs.base()); }
    template <typename T>
    bool operator<(ft::random_access_iterator<T> const &lhs, ft::random_access_iterator<T> const & rhs) { return (lhs.base() < rhs.base()); }
    template <typename T>
    bool operator>(ft::random_access_iterator<T> const &lhs, ft::random_access_iterator<T> const & rhs) { return (lhs.base() > rhs.base()); }
    template <typename T>
    bool operator<=(ft::random_access_iterator<T> const &lhs, ft::random_access_iterator<T> const & rhs) { return (lhs.base() <= rhs.base()); }
    template <typename T>
    bool operator>=(ft::random_access_iterator<T> const &lhs, ft::random_access_iterator<T> const & rhs) { return (lhs.base() >= rhs.base()); }


    // REVERSE_ITERATOR
    template <typename Iterator>
    class reverse_iterator {
    public:
        typedef Iterator                                                    iterator_type;
        typedef typename ft::iterator_traits<Iterator>::difference_type     difference_type;
        typedef typename ft::iterator_traits<Iterator>::value_type          value_type;
        typedef typename ft::iterator_traits<Iterator>::pointer             pointer;
        typedef typename ft::iterator_traits<Iterator>::reference           reference;
        typedef typename ft::iterator_traits<Iterator>::iterator_category   iterator_category;
        iterator_type _rit;

        // CONSTRUCTORS
        reverse_iterator() : _rit() {}
        explicit reverse_iterator(iterator_type it) : _rit(it) {}

        template <typename iter>
        reverse_iterator(reverse_iterator<iter> const & rev_it) : _rit(rev_it.base()) {}

        iterator_type base() const { return (_rit); }
        reference   operator*() const {
            iterator_type tmp = _rit.base();
            return (*--tmp);
        }
        pointer     operator->() const { return (&(*_rit)); }

        reverse_iterator operator+(difference_type n) const { return (reverse_iterator(_rit - n)); }
        reverse_iterator & operator++() {
            --_rit;
            return (*this);
        }
        reverse_iterator operator++(int) {
            reverse_iterator tmp(*this);
            _rit--;
            return tmp;
        }
        reverse_iterator operator-(difference_type n) const { return (reverse_iterator(_rit + n)); }
        reverse_iterator & operator--() {
            ++_rit;
            return (*this);
        }
        reverse_iterator operator--(int) {
            reverse_iterator tmp(*this);
            _rit++;
            return tmp;
        }
        reverse_iterator & operator+=(difference_type n) {
            _rit -= n;
            return (*this);
        }
        reverse_iterator & operator-=(difference_type n) {
            _rit += n;
            return (*this);
        }
        reference   operator[](difference_type n) const { return (*(_rit - n - 1)); }
    };
    template <typename Iterator>
    typename ft::reverse_iterator<Iterator> operator+(typename reverse_iterator<Iterator>::difference_type lhs, reverse_iterator<Iterator> & rhs) { return (ft::reverse_iterator<Iterator>(rhs + lhs)); }
    template <typename Iterator>
    typename ft::reverse_iterator<Iterator>::difference_type operator-(reverse_iterator<Iterator> const & lhs, reverse_iterator<Iterator> const & rhs) { return ((rhs.base() - lhs.base())); }
    template <typename Iterator>
    bool operator==(reverse_iterator<Iterator> const & lhs, reverse_iterator<Iterator> const & rhs) { return (lhs.base() == rhs.base()); }
    template <typename Iterator>
    bool operator!=(reverse_iterator<Iterator> const & lhs, reverse_iterator<Iterator> const & rhs) { return (lhs.base() != rhs.base()); }
    template <typename Iterator>
    bool operator<(reverse_iterator<Iterator> const & lhs, reverse_iterator<Iterator> const & rhs) { return (lhs.base() > rhs.base()); }
    template <typename Iterator>
    bool operator>(reverse_iterator<Iterator> const & lhs, reverse_iterator<Iterator> const & rhs) { return (lhs.base() < rhs.base()); }
    template <typename Iterator>
    bool operator<=(reverse_iterator<Iterator> const & lhs, reverse_iterator<Iterator> const & rhs) { return (lhs.base() >= rhs.base()); }
    template <typename Iterator>
    bool operator>=(reverse_iterator<Iterator> const & lhs, reverse_iterator<Iterator> const & rhs) { return (lhs.base() <= rhs.base()); }

}

#endif
