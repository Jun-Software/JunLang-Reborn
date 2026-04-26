/**
 * if function
 * By lemonorangeapple
**/
void _if(vector<string>::iterator it, vector<vector<string> > &lines, int &line) {
    string next = *(it + 1);
    int tmp = line;
    if (eval(next, line)) {
        return;
    }
    while (!(lines[line][0] == "end" && lines[line][1] == "if")) {
        line++;
        if (line == lines.size()) {
            cerr << "[Error, " << tmp << "] END IF not found" << endl;
            exit(0);
        }
    }
    return;
}