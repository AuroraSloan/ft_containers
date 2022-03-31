#ifndef TESTUTILS_HPP
# define TESTUTILS_HPP

# include <iostream>

void print_time_results(double stdtime, double fttime)
{
    std::string winner, loser, color;
    int         ratio;

    if (stdtime < fttime) {
        winner = "STL is ";
        loser = "FT is ";
        ratio = (int)(fttime/stdtime);
        color = ratio > 20 ? RED : YELLOW;
    }
    else {
        winner = "FT is ";
        loser = "STL is ";
        ratio = (int)(stdtime/fttime);
        color = GREEN;
    }
    std::cout << color << winner << (ratio == 1 ? 0 : ratio) << "x faster: " << RESET;
    std::cout << " [std: " << stdtime * 1000 << "ms] " << "[ft: " << fttime * 1000 << "ms]\n";
}

#endif
