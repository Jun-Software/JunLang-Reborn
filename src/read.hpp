/**
 * Read file
**/
#include "interpreter.hpp"
void read(char* argv[]) {
    string fileName = string(argv[1]);
    ifstream file(fileName);
    if (!file.is_open()) {
        cerr << "[ERROR] File cannot open.\n";
        exit(0);
    }
    // Read file.
    vector<vector<string> > lines;
    while (file.good()) {
        file.getline(buffer, sizeof(buffer));
        vector<string> vec(split(string(buffer)));
        lines.push_back(vec);
    }
    for (int line = 0; line < lines.size(); line++) {
        interpreter(lines[line], lines, line);
    }
}