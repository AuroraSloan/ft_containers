#pragma once
#ifndef TYPE_TRAITS_HPP
# define TYPE_TRAITS_HPP

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

}

#endif
