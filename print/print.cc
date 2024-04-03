#include <iostream>

namespace libprint {

    void println(const std::string_view& str) {
        std::cout << str << std::endl;
    }

}