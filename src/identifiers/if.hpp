/**
 * if function
 * By lemonorangeapple
**/
void _if(vector<string>::iterator it, vector<vector<string> > lines, int &line) {
    string next = *(it + 1);
    int tmp = line;
    if (variables.find(next) != variables.end()) {
        if (variables[next]) {
            return;
        }
    }
    else {
        cerr << "[Error, " << line << "] Unknown variables: " << next << endl;
        exit(0);
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