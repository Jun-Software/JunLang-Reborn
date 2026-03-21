/**
 * Output function
 * By lemonorangeapple
**/
void output(vector<string>::iterator it, ifstream &file) {
    // Check if the next token is a variable
    string next = *(it + 1);
    if (next[0] != '"') {
        cout << variables[next];
    }
    // If the next token is a string, print the string
    else {
        cout << next.substr(1, next.length() - 2);
    }
    cout << endl;
    return;
}