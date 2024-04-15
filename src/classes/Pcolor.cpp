#include "PColor.hpp"


int main() {
    // Use PColor to color the output
    std::cout << PColor::red << "This is red text." << PColor::normal << std::endl;
    std::cout << PColor::green << "This is green text." << PColor::normal << std::endl;
    std::cout << PColor::blue << "This is blue text." << PColor::normal << std::endl;

    return 0;
}