/**
 * Run a function or a system command.
**/
void run(vector<string>::iterator it, vector<string>::iterator end, vector<vector<string> > &lines, int &line) {
    if (it + 1 == end) {
        cerr << "[Error, " << line << "] Missing argument" << endl;
        exit(0);
    }
    string next = *(it + 1);
    vector<string> vec = split(next);
    if (vec[0] == "func") {
        if (funcs.find(vec[1]) != funcs.end()) {
            // Function calls behave like jumps with a saved return point.
            funcSta.push({line, ""});
            line = funcs[vec[1]] - 1;
        }
        else {
            cerr << "[Error, " << line << "] Unknown function: " << vec[1] << endl;
        }
    }
    else if (vec[0] == "sys") {
        // Pass the raw command string to the host shell.
        system(vec[1].c_str());
    }
    return;
}
