/**
 * Input function
 * By lemonorangeapple
**/
void input(vector<string>::iterator it, vector<string>::iterator end, vector<vector<string> > &lines, int &line) {
    if (it + 1 == end) {
        cerr << "[Error, " << line << "] Missing argument" << endl;
        exit(0);
    }
    long double temp;
    cin >> temp;
    variables[*(it + 1)] = temp;
}