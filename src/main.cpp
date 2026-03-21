#include "init.hpp"
#include "read.hpp"
void load();
#include "identifiers.hpp"
int main(int argc, char* argv[]) {
    // Check if there is a filename.
    if (argc == 1) {
        // Output usage.
        cout << "JunLang Reborn " << _VERSION_ << endl;
        cout << "Usage: " << argv[0] << " [filename]" << endl;
        exit(0);
    }
    load();
    // Read file.
    read(argv);
    return 0;
}