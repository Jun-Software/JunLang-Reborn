/**
 * Skip forward to the matching end-if when the condition is false.
**/
void _if(vector<string>::iterator it, vector<string>::iterator end, vector<vector<string> > &lines, int &line) {
    if (it + 1 == end) {
        cerr << "[Error, " << line << "] Missing argument" << endl;
        exit(0);
    }
    string next = *(it + 1);
    int tmp = line;
    if (eval(next, line)) {
        return;
    }
    // Search for the matching "end if" in the current line stream.
    while (!(lines[line][0] == "end" && lines[line][1] == "if")) {
        line++;
        if (line == lines.size()) {
            cerr << "[Error, " << tmp << "] END IF not found" << endl;
            exit(0);
        }
    }
    return;
}
