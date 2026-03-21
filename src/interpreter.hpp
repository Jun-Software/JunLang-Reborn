void interpreter(vector<string> vec, ifstream &file) {
    for (vector<string>::iterator it = vec.begin(); it != vec.end(); ++it) {
        string current_identifier = (*it);
        if ((current_identifier) == "" || (current_identifier[0]) == '#') {
            continue;
        }
        map <string, void (*)(vector<string>::iterator, ifstream &)>::iterator idIt = identifiers.find(current_identifier);
        if (idIt != identifiers.end()) {
            idIt -> second(it, file);
            return;
        }
        else {
            cerr << "[Error] Unknown identifier: " << current_identifier << endl;
            return;
        }
    }
}