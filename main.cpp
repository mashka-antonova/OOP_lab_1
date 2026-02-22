#include "application.h"
#include "console_io.h"

#include <iostream>

int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;

    ConsoleIo console(std::cin, std::cout);
    Application application(console);
    return application.run();

}
