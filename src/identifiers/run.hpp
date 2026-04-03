/**
 * run function
 * By lemonorangeapple
**/
void run(vector<string>::iterator it, vector<vector<string> > lines, int &line) {
    string next = *(it + 1);
    if (funcs.find(next) != funcs.end()) {
        funcSta.push({line, ""});
        line = funcs[next] - 1;
    }
    return;
}