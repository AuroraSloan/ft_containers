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
        typedef ptrdiff_t const                                     difference_type;
        typedef T const                                             value_type;
        typedef T* const                                            pointer;
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

        random_access_iterator(void) : _data(NULL) {}
        random_access_iterator(value_type *x) : _data(x) {}
        random_access_iterator(random_access_iterator const & src) : _data(src._data) {}
        ~random_access_iterator(void) {}

        bool operator==(random_access_iterator const &rhs) const { return (_data == rhs._data); }
        bool operator!=(random_access_iterator const &rhs) const { return (_data != rhs._data); }

        reference   operator*() { return (*_data); }
        pointer     operator->() { return (_data); }

        random_access_iterator const & operator=(random_access_iterator const &rhs) {
            if (this != &rhs)
                _data = rhs._data;
            return (*this);
        }

        random_access_iterator & operator++(void) {
            ++_data;
            return (*this);
        }

        random_access_iterator operator++(T) {
            random_access_iterator tmp(*this);
            _data++;
            //operator++();
            return tmp;
        }
        /*random_access_iterator * operator++(T*) {
            random_access_iterator tmp(*this);
            *_data++;
            //operator++();
            return tmp;
        }*/
        random_access_iterator & operator--(void) {
            --_data;
            return (*this);
        }

        random_access_iterator operator--(T) {
            random_access_iterator tmp(*this);
            _data--;
            //operator++();
            return tmp;
        }
        /*random_access_iterator * operator--(T*) {
            random_access_iterator tmp(*this);
            *_data--;
            //operator--();
            return tmp;
        }*/
        //       random_access_iterator operator

        random_access_iterator operator+(difference_type x) { return (_data + x); }
        difference_type operator+(random_access_iterator const & rhs) { return (_data + rhs._data); }
        random_access_iterator operator-(difference_type x) { return (_data - x); }
        //random_access_iterator operator-(random_access_iterator const & rhs) { return (*_data - *rhs._data); }
        //difference_type operator-(difference_type x) { return (_data - x); }
        difference_type operator-(random_access_iterator const & rhs) { return (_data - rhs._data); }

        bool operator<(random_access_iterator const & rhs) { return (*_data < *rhs._data); }
        bool operator>(random_access_iterator const & rhs) { return (*_data > *rhs._data); }
        bool operator<=(random_access_iterator const & rhs) { return (*_data <= *rhs._data); }
        bool operator>=(random_access_iterator const & rhs) { return (*_data >= *rhs._data); }

        random_access_iterator const & operator+=(random_access_iterator const &rhs) {
            _data += rhs._data;
            return (*this);
        }
        random_access_iterator const & operator-=(random_access_iterator const &rhs) {
            _data -= rhs._data;
            return (*this);
        }

        reference   operator[](difference_type i) const { return (*(_data + i)); }

    private:
        pointer _data;
    };


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
        iterator_type _it;

        // CONSTRUCTORS
        reverse_iterator(void) : _it(NULL) {}
        explicit reverse_iterator(iterator_type it) : _it(it) {}
        template <typename iter>
            reverse_iterator(reverse_iterator<iter> const & rev_it) : _it(rev_it.base()) {}

        iterator_type base() const { return (_it); }
        /*reference   operator*() {
            --_it;
            return (*_it._data);
        }

        random_access_iterator operator+(difference_type x) { return (_data + x); }
        random_access_iterator operator+(random_access_iterator const & rhs) { return (*_data + *rhs._data); }
        random_access_iterator & operator++(void) {
            ++_data;
            return (*this);
        }
        random_access_iterator operator++(T) {
            random_access_iterator tmp(*this);
            _data++;
            //operator++();
            return tmp;
        }
        random_access_iterator const & operator+=(random_access_iterator const &rhs) {
            _data += rhs._data;
            return (*this);
        }

        random_access_iterator operator-(difference_type x) { return (_data - x); }
        random_access_iterator operator-(random_access_iterator const & rhs) { return (*_data - *rhs._data); }
        random_access_iterator & operator--(void) {
            --_data;
            return (*this);
        }
        random_access_iterator operator--(T) {
            random_access_iterator tmp(*this);
            _data--;
            //operator++();
            return tmp;
        }
        random_access_iterator const & operator-=(random_access_iterator const &rhs) {
            _data -= rhs._data;
            return (*this);
        }

        pointer     operator->() { return (_data); }
        reference   operator[](difference_type i) const { return (*(_data + i)); }*/
    };
    /*bool operator==(random_access_iterator const &rhs) const { return (_data == rhs._data); }
    bool operator!=(random_access_iterator const &rhs) const { return (_data != rhs._data); }
    bool operator<(random_access_iterator const & rhs) { return (*_data < *rhs._data); }
    bool operator>(random_access_iterator const & rhs) { return (*_data > *rhs._data); }
    bool operator<=(random_access_iterator const & rhs) { return (*_data <= *rhs._data); }
    bool operator>=(random_access_iterator const & rhs) { return (*_data >= *rhs._data); }
     template <class Iterator>
  reverse_iterator<Iterator> operator+ (
             typename reverse_iterator<Iterator>::difference_type n,
             const reverse_iterator<Iterator>& rev_it);
            template <class Iterator>
  typename reverse_iterator<Iterator>::difference_type operator- (
    const reverse_iterator<Iterator>& lhs,
    const reverse_iterator<Iterator>& rhs);
             */

}

#endif
