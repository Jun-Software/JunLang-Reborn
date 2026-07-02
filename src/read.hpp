/**
 * Read a script file, normalize each line, and feed it to the interpreter.
**/
#include "interpreter.hpp"
void read(const char* filePath) {
    string fileName = string(filePath);
    std::ifstream file(fileName);
    if (!file.is_open()) {
        cerr << "[ERROR] File " << fileName << " cannot open.\n";
        exit(0);
    }
    // Keep a blank sentinel at both ends so line-based jumps stay safe.
    vector<vector<string> > lines;
    lines.push_back({""});
    while (file.good()) {
        file.getline(buffer, sizeof(buffer));
        vector<string> vec(split(cleanString(buffer)));
        lines.push_back(vec);
    }
    lines.push_back({""});
    for (int line = 0; line < lines.size(); line++) {
        interpreter(lines[line], lines, line);
    }
}
