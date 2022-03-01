#ifndef UTILS_HPP
# define UTILS_HPP

# include <iostream>

# define HDR "=========="
# define SUBHDR "--"
# define RED "\x1b[31m"
# define GREEN "\x1b[32m"
# define YELLOW "\x1b[33m"
# define MAGENTA "\x1b[35m"
# define CYAN "\x1b[36m"
# define RESET "\x1b[0m"
# define DISPLAY 1

namespace ft {
    void    display(std::string color, std::string message)
    {
        if (DISPLAY)
            std::cout << color + message + RESET;
        return ;
    }

    void    display(std::string color, int x, std::string delim)
    {
        if (DISPLAY)
            std::cout << color << x << RESET + delim;
        return ;
    }

    void    display(std::string message)
    {
        if (DISPLAY)
            std::cout << message;
        return ;
    }

    void    write(std::string color, std::string message)
    {
        std::cout << color + message + RESET;
        return ;
    }

    void    write(std::string color, int x, std::string delim)
    {
        std::cout << color << x << delim + RESET;
        return ;
    }

    void    write(std::string message)
    {
        std::cout << message;
        return ;
    }
}
#endif
