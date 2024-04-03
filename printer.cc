#include <string>

#include "print.h"

int main(int argc, char const *argv[])
{
    for (auto i = 0; i < argc; ++i)
        libprint::println(argv[1]);

    return 0;
}

