#ifndef TESTUTILS_HPP
# define TESTUTILS_HPP

# include <iostream>

void print_time_results(double stdtime, double fttime)
{
    if (stdtime < fttime)
    {
        int ratio = (int)(fttime/stdtime);
        std::string color = ratio > 20 ? RED : YELLOW;
        ft::write(color + std::string("std is "), ratio, "x faster");
    }
    else
        ft::write(GREEN + std::string("ft is "), (int)(stdtime/fttime), "x faster");
    std::cout << "\t[std: " << stdtime * 1000 << "ms] " << "[ft: " << fttime * 1000 << "ms]\n";
}

#endif
