void interpreter(vector<string> vec, vector<vector<string> > lines, int &line) {
    for (vector<string>::iterator it = vec.begin(); it != vec.end(); ++it) {
        string currentIdentifier = (*it);
        if ((currentIdentifier) == "") {
            return;
        }
        unordered_map <string, void (*)(vector<string>::iterator, vector<vector<string> >, int &)>::iterator idIt = identifiers.find(currentIdentifier);
        if (idIt != identifiers.end()) {
            (idIt -> second)(it, lines, line);
            return;
        }
        else {
            cerr << "[Error] Unknown identifier: " << currentIdentifier << endl;
            exit(0);
            return;
        }
    }
}