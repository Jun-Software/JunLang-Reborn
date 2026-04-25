/**
 * Out function
 * By lemonorangeapple
**/
void output(vector<string>::iterator it, vector<vector<string> > &lines, int &line) {
    // Check if the next token is a variable
    string next = *(it + 1);
    if (next[0] != '"') {
        if (variables.find(next) != variables.end()) {
            cout << variables[next];
        }
        else {
            cerr << "[Error, " << line << "] Unknown variables: " << next << endl;
        }
    }
    // If the next token is a string, print the string
    else {
        cout << next.substr(1, next.length() - 2);
    }
    return;
}