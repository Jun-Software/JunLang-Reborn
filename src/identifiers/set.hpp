/**
 * Set function
 * By lemonorangeapple
**/
void set(vector<string>::iterator it, vector<vector<string> > lines, int &line) {
    string next = *(it + 1);
    vector<string> vec = split(next);
    variables.insert_or_assign(vec[0], stold(vec[1]));
    return;
}