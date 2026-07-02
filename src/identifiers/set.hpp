/**
 * Assign a value to a variable.
**/
void set(vector<string>::iterator it, vector<string>::iterator end, vector<vector<string> > &lines, int &line) {
    if (it + 1 == end) {
        cerr << "[Error, " << line << "] Missing argument" << endl;
        exit(0);
    }
    string next = *(it + 1);
    vector<string> vec = split(next);
    // The payload is "name expression".
    variables.insert_or_assign(vec[0], eval(vec[1], line));
    return;
}
