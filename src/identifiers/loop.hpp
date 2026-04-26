/**
 * loop function
 * By lemonorangeapple
**/
void loop(vector<string>::iterator it, vector<vector<string> > &lines, int &line) {
    string next = *(it + 1);
    int tmp = line;
    if (!eval(next, line)) {
        loopSta.pop();
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