#ifndef TYPE_TRAITS_HPP
# define TYPE_TRAITS_HPP

# include "iterator.hpp"

namespace ft {

    template <typename> struct is_integral { static const bool value = false; };
    template <> struct is_integral<char> { static const bool value = true; };
    template <> struct is_integral<short int> { static const bool value = true; };
    template <> struct is_integral<int> { static const bool value = true; };
    template <> struct is_integral<long int> { static const bool value = true; };
    template <> struct is_integral<bool> { static const bool value = true; };
    template <> struct is_integral<wchar_t> { static const bool value = true; };

    template <bool Cond, typename T = void> struct  enable_if {};
    template <typename T> struct enable_if<true, T> { typedef T type; };

    template <typename InputIterator, typename T = void> struct is_random_access_iterator { static const bool value = false; };
    template <typename T> struct is_random_access_iterator<ft::random_access_iterator<T> > { static const bool value = true; };

/*    template <typename> struct is_integral { static const bool value = false; };
    template <> struct is_integral<bool> { static const bool value = true; };
    template <> struct is_integral<char> { static const bool value = true; };
    template <> struct is_integral<char16_t> { static const bool value = true; };
    template <> struct is_integral<char32_t> { static const bool value = true; };
    template <> struct is_integral<wchar_t> { static const bool value = true; };
    template <> struct is_integral<signed char> { static const bool value = true; };
    template <> struct is_integral<short int> { static const bool value = true; };
    template <> struct is_integral<int> { static const bool value = true; };
    template <> struct is_integral<long int> { static const bool value = true; };
    template <> struct is_integral<long long int> { static const bool value = true; };
    template <> struct is_integral<unsigned char> { static const bool value = true; };
    template <> struct is_integral<unsigned short int> { static const bool value = true; };
    template <> struct is_integral<unsigned int> { static const bool value = true; };
    template <> struct is_integral<unsigned long int> { static const bool value = true; };
    template <> struct is_integral<unsigned long long int> { static const bool value = true; };*/



}

#endif
