/**
 * Set function
 * By lemonorangeapple
**/
void set(vector<string>::iterator it, vector<vector<string> > lines, int &line) {
    string next = *(it + 1);
    vector<string> vec = split(next);
    for (int index = 0; index < vec.size(); index++) {
        variables.insert_or_assign(vec[index], stold(vec[index + 1]));
    }
    return;
}