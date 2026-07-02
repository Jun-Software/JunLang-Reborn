/**
 * Publish a previously declared function as callable from other files or packages.
**/
void _export(vector<string>::iterator it, vector<string>::iterator end, vector<vector<string> > &lines, int &line) {
    if (it + 1 == end) {
        cerr << "[Error, " << line << "] Missing argument" << endl;
        exit(0);
    }
    string next = *(it + 1);
    unordered_map <string, int>::iterator efIt = funcs.find(next);
    if (efIt != funcs.end()) {
        // Export by name, reusing the function entry point stored earlier.
        exportedFuncs[next] = (efIt -> second);
    }
    else {
        cerr << "[Error, " << line << "] Unknown function: " << next << endl;
    }
    return;
}
