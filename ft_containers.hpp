#ifndef FT_CONTAINERS_HPP
# define FT_CONTAINERS_HPP

// test variables/ arguments
# define INT /* INT / STRING */

// Test output
# define SHORT /* SHORT / LONG */

// 1 for testing ft === 0 for testing std
# if 1
#  define TEST
#  include "include/algorithm.hpp"
#  include "include/iterator.hpp"
#  include "include/stack.hpp"
#  include "include/utility.hpp"
#  include "include/vector.hpp"
#  include "include/map.hpp"
# else
   namespace ft = std;
# endif

#endif
