/**
 * if function
 * By lemonorangeapple
**/
void _if(vector<string>::iterator it, vector<vector<string> > lines, int &line) {
    string next = *(it + 1);
    if (!(lines.size() - line)) {
        cerr << "[Error, " << line << "] END IF not found." << endl;
        exit(0);
    }
    bool endFlag = true;
    stack<bool> newIf;
    int ifLine = line;
    while (lines.size() - line) {
        line++;
        if (lines[line][0] == "if") {
            newIf.push(true);
        }
        else if (lines[line][0] == "end" && lines[line][1] == "if"){
            if (newIf.empty()) {
                endFlag = false;
                break;
            }
            else {
                newIf.pop();
            }
        }
    }
    if (endFlag) {
        cerr << "[Error, " << line << "] END IF not found." << endl;
        exit(0);
    }
    if (variables.find(next) != variables.end()) {
        if (variables[next]) {
            for (int tmp = ifLine + 1; tmp <= line; tmp++) {
                interpreter(lines[tmp], lines, tmp);
            }
            return;
        }
    }
    else {
        cerr << "[Error, " << line << "] Unknown variables: " << next << endl;
    }
    return;
}