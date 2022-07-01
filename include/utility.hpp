#ifndef UTILITY_HPP
# define UTILITY_HPP

namespace ft {

    template <typename T1, typename T2>
    struct pair {

    };
    template <typename T1, typename T2>
    std::pair<T1,T2>    make_pair(T1 x, T2 y) {
        return (std::pair<T1, T2>(x, y));
    }
}

#endif
