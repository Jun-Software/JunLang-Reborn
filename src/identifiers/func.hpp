/**
 * Register a function body and jump past it during normal execution.
**/
void func(vector<string>::iterator it, vector<string>::iterator end, vector<vector<string> > &lines, int &line) {
    if (it + 1 == end) {
        cerr << "[Error, " << line << "] Missing argument" << endl;
        exit(0);
    }
    string next = *(it + 1);
    int tmp = line;
    funcs.insert_or_assign(next, line + 1);
    // Skip the function body until the matching terminator.
    while (!(lines[line][0] == "end" && lines[line][1] == "func")) {
        line++;
        if (line == lines.size()) {
            cerr << "[Error, " << tmp << "] END FUNC not found" << endl;
            exit(0);
        }
    }
    funcSta.push({tmp, ""});
    return;
}
