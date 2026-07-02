// Dispatch one tokenized line to either a built-in identifier or an exported function.
void interpreter(vector<string> vec, vector<vector<string> > &lines, int &line) {
    for (vector<string>::iterator it = vec.begin(); it != vec.end(); ++it) {
        string currentIdentifier = (*it);
        if ((currentIdentifier) == "") {
            return;
        }
        unordered_map <string, int>::iterator efIt = exportedFuncs.find(currentIdentifier);
        if (efIt != exportedFuncs.end()) {
            // Jump into an exported function and remember where to return.
            uStr tmp;
            tmp.line = line;
            line = (efIt -> second) - 1;
            funcSta.push(tmp);
            return;
        }
        unordered_map <string, void (*)(vector<string>::iterator, vector<string>::iterator, vector<vector<string> > &, int &)>::iterator idIt = identifiers.find(currentIdentifier);
        if (idIt != identifiers.end()) {
            (idIt -> second)(it, vec.end(), lines, line);
            return;
        }
        else {
            cerr << "[Error] Unknown identifier: " << currentIdentifier << endl;
            exit(0);
            return;
        }
    }
}
