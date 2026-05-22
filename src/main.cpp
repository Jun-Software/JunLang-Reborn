#include "init.hpp"
#include "read.hpp"
void load();
#include "identifiers.hpp"
int main(int argc, char* argv[]) {
    // Check if there is a filename.
    if (argc == 1) {
        // Output usage.
        std::cout << "JunLang Reborn " << _VERSION_ << endl;
        std::cout << "Usage: " << argv[0] << " [filename]" << endl;
        exit(0);
    }
    std::cout << std::fixed;
    load();
    // Read file.
    read(argv[1]);
    return 0;
}