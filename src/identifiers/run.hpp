/**
 * run function
 * By lemonorangeapple
**/
void run(vector<string>::iterator it, vector<vector<string> > lines, int &line) {
    string next = *(it + 1);
    vector<string> vec = split(next);
    if (vec[0] == "func") {
        if (funcs.find(vec[1]) != funcs.end()) {
            funcSta.push({line, ""});
            line = funcs[vec[1]] - 1;
        }
        else {
            cerr << "[Error, " << line << "] Unknown function: " << vec[1] << endl;
        }
    }
    else if (vec[0] == "prog") {
        read(vec[1].c_str());
    }
    return;
}