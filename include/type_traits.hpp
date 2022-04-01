#ifndef TYPE_TRAITS_HPP
# define TYPE_TRAITS_HPP

namespace ft {


    template <typename>
    struct is_integral {
        static const bool value = false;
    };

    template <>
    struct is_integral<int> {
        static const bool value = true;
    };

/*    template <bool Cond, typename T = void>
    struct  enable_if {

    };*/

}

#endif
