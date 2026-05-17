/**
 * Out function
 * By lemonorangeapple
**/
void output(vector<string>::iterator it, vector<string>::iterator end, vector<vector<string> > &lines, int &line) {
    if (it + 1 == end) {
        cerr << "[Error, " << line << "] Missing argument" << endl;
        exit(0);
    }
    string next = *(it + 1);
    if (next[0] != '"') {
        cout << eval(next, line);
    }
    // If the next token is a string, print the string
    else {
        cout << next.substr(1, next.length() - 2);
    }
    return;
}