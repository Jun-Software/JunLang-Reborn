/**
 * load function
 * By lemonorangeapple
 * Load Packages(.DLL/.SO)
**/
void load(vector<string>::iterator it, vector<vector<string> > &lines, int &line) {
    string next = *(it + 1);
    string packageType = split(next)[0];
    string packageId = split(next)[1];
    if (packageType != "lib" && packageType != "whl") {
        cerr << "[Error, " << line << "] Invalid package type: " << packageType << endl;
        exit(0);
    }
    if (!libload) {
        cerr << "[Error, " << line << "] Your device is not support to load library" << endl;
        exit(0);
    }
    string libPath = "packages/" + packageId + ".jun" + packageType;
    if (packageType == "whl") {
        string fileName = string(libPath);
        ifstream file(fileName);
        if (!file.is_open()) {
            cerr << "[ERROR] File " << fileName << " cannot open.\n";
            exit(0);
        }
        vector<vector<string> > tmp;
        while (file.good()) {
            file.getline(buffer, sizeof(buffer));
            vector<string> vec(split(cleanString(buffer)));
            tmp.push_back(vec);
        }
        lines.insert(lines.begin() + line + 1, tmp.begin(), tmp.end());
        return;
    }
#ifdef _WIN32
    HMODULE hDll = LoadLibrary(libPath.c_str());
    if (hDll == NULL) {
        cerr << "[Error, " << line << "] Load " << packageId << ": " << GetLastError() << endl;
        exit(0);
    }
#elif __linux__
    void* hDll = dlopen(libPath.c_str(), RTLD_LAZY);
    if (!hDll) {
        cerr << "[Error, " << line << "] Load " << packageId << ": " << dlerror() << endl;
        exit(0);
    }
#endif
    typedef unordered_map <string, void (*)(vector<string>::iterator, vector<vector<string> > &, int &)> (*loadFunc)();
    typedef unordered_map <string, void (*)(vector<string>::iterator, vector<vector<string> > &, int &)> mapType;
#ifdef _WIN32
    loadFunc pAdd = (loadFunc)GetProcAddress(hDll, "load");
    if (pAdd == NULL) {
        cerr << "[Error, " << line << "] Load " << packageId << ": " << GetLastError() << endl;
        FreeLibrary(hDll);
        exit(0);
    }
#elif __linux__
    loadFunc pAdd = (loadFunc)dlsym(hDll, "load");
    const char* error = dlerror();
    if (error != NULL) {
        cerr << "[Error, " << line << "] Load " << packageId << ": " << error << endl;
        dlclose(hDll);
        exit(0);
    }
#endif
    mapType tmp = pAdd();
    identifiers.insert(tmp.begin(), tmp.end());
    return;
}