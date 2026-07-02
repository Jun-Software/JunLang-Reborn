/**
 * Print either an evaluated expression or a string literal.
**/
void output(vector<string>::iterator it, vector<string>::iterator end, vector<vector<string> > &lines, int &line) {
    if (it + 1 == end) {
        cerr << "[Error, " << line << "] Missing argument" << endl;
        exit(0);
    }
    string next = *(it + 1);
    if (next[0] != '"') {
        std::cout << eval(next, line);
    }
    else {
        // Strip the surrounding quotes before printing.
        std::cout << next.substr(1, next.length() - 2);
    }
    return;
}
