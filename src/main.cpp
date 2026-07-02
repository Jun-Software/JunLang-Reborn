#include "init.hpp"
#include "read.hpp"
void load();
#include "identifiers.hpp"
int main(int argc, char* argv[]) {
    // No script file means we only print usage and exit.
    if (argc == 1) {
        std::cout << "JunLang Reborn " << _VERSION_ << endl;
        std::cout << "Usage: " << argv[0] << " [filename]" << endl;
        exit(0);
    }
    std::cout << std::fixed;
    load();
    // Parse and execute the script passed on the command line.
    read(argv[1]);
    return 0;
}
