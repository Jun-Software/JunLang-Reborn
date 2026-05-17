/**
 * loop function
 * By lemonorangeapple
**/
void loop(vector<string>::iterator it, vector<string>::iterator end, vector<vector<string> > &lines, int &line) {
    if (it + 1 == end) {
        cerr << "[Error, " << line << "] Missing argument" << endl;
        exit(0);
    }
    string next = *(it + 1);
    int tmp = line;
    if (!eval(next, line)) {
        while (!(lines[line][0] == "end" && lines[line][1] == "loop")) {
            line++;
            if (line == lines.size()) {
                cerr << "[Error, " << tmp << "] END LOOP not found" << endl;
                exit(0);
            }
        }
    }
    else {
        loopSta.push({line, next});
        return;
    }
    return;
}