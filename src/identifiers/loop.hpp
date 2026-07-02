/**
 * Start a loop block or skip it when the condition is false.
**/
void loop(vector<string>::iterator it, vector<string>::iterator end, vector<vector<string> > &lines, int &line) {
    if (it + 1 == end) {
        cerr << "[Error, " << line << "] Missing argument" << endl;
        exit(0);
    }
    string next = *(it + 1);
    int tmp = line;
    if (!eval(next, line)) {
        // Fast-forward to the matching "end loop" when the condition fails.
        while (!(lines[line][0] == "end" && lines[line][1] == "loop")) {
            line++;
            if (line == lines.size()) {
                cerr << "[Error, " << tmp << "] END LOOP not found" << endl;
                exit(0);
            }
        }
    }
    else {
        // Remember the loop head so "end loop" can jump back here.
        loopSta.push({line, next});
        return;
    }
    return;
}
