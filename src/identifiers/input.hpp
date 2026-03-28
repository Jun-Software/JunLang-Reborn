/**
 * Input function
 * By lemonorangeapple
**/
void input(vector<string>::iterator it, vector<vector<string> > lines, int &line) {
    long double temp;
    cin >> temp;
    variables[*(it + 1)] = temp;
}