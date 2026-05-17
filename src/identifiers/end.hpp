/**
 * end function
 * By lemonorangeapple
**/
void end(vector<string>::iterator it, vector<string>::iterator end, vector<vector<string> > &lines, int &line) {
    if (it + 1 == end) {
        cerr << "[Error, " << line << "] Missing argument" << endl;
        exit(0);
    }
    string next = *(it + 1);
    if (next == "if") {}
    else if (next == "loop") {
        if (!loopSta.empty()) {
            uStr tmp = loopSta.top();
            if (variables[tmp.name]) {
                line = tmp.line;
                return;
            }
            loopSta.pop();
        }
    }
    else if (next == "func") {
        if (!funcSta.empty()) {
            line = funcSta.top().line;
            funcSta.pop();
            return;
        }
    }
    else if (next == "line") {
        cout << endl;
    }
    else if (next == "prog") {
        exit(0);
    }
    else {
        cerr << "[Error, " << line << "] Unknown END identifier: " << next << endl;
    }
    return;
}