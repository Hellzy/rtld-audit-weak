#include <string>

#include "print.h"

int main(int argc, char const *argv[])
{
    for (auto i = 0; i < argc; ++i)
        libprint::println(argv[i]);

    return 0;
}

