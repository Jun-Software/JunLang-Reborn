/**
 * Set function
 * By lemonorangeapple
**/
void set(vector<string>::iterator it, ifstream &file) {
    string next = *(it + 1);
    vector<string> vec = split(next);
    for (int index = 0; index < vec.size(); index++) {
        variables[vec[index]] = atoi((vec[index + 1]).c_str());
    }
    return;
}