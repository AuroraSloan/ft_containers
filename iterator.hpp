#ifndef ITERATOR_HPP
# define ITERATOR_HPP

# include <iterator>
namespace ft {

    // ITERATOR TRAITS
    template <typename Iterator>
    class iterator_traits {

    };
    // RANDOM ACCESS ITERATOR
    template <typename T>
    class iterator : public std::iterator<std::random_access_iterator_tag, T> {
    public:
        T *data;

        iterator(T *x) : data(x) {}

        iterator(iterator const &mit) : data(mit.data) {}

        iterator &operator++() {
            ++data;
            return *this;
        }

        iterator operator++(T) {
            iterator tmp(*this);
            operator++();
            return tmp;
        }

        bool operator==(iterator const &rhs) const { return data == rhs.data; }

        bool operator!=(iterator const &rhs) const { return data != rhs.data; }

        T &operator*() { return *data; }
    };
}
#endif
