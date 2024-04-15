#ifndef PCOLOR_HPP
#define PCOLOR_HPP

using namespace std;

#include <ostream>
#include <iostream>

// Define color codes
#define RED "\033[31m"
#define GREEN "\033[32m"
#define BLUE "\033[34m"
#define NORMAL "\033[0m"

class PColor {
public:
    static ostream& red(std::ostream &out) {
        return out << RED;
    }

    static ostream& green(std::ostream &out) {
        return out << GREEN;
    }

    static ostream& blue(std::ostream &out) {
        return out << BLUE;
    }

    static ostream& normal(std::ostream &out) {
        return out << NORMAL;
    }

    // Define a new type for color functions
    typedef std::ostream& (*ColorFunc)(std::ostream&);

    // Overload << operator for color functions
    friend std::ostream& operator<<(std::ostream &out, ColorFunc func) {
        return func(out);
    }
};

#endif