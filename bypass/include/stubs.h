#pragma once

namespace libprint {
    void println(const char *) { std::cout << "Bypassed a call to " << __FUNCTION__ << '\n';}
}