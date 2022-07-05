#ifndef FT_CONTAINERS_HPP
# define FT_CONTAINERS_HPP

# include <vector>

// test variables/ arguments
# define INT /* INT / STRING */

// Test output
# define LONG /* SHORT / LONG */

// 1 for testing ft === 0 for testing std
# if 1
#  define TEST
#  include "include/vector.hpp"
#  include "include/algorithm.hpp"
#  include "include/utility.hpp"
# else
   namespace ft = std;
# endif

#endif
