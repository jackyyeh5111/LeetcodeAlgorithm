#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class FileSystem {
    class Dir {
    public:
        map<string, Dir*> dirs;
        map<string, string> files;
    };

    Dir* root;

public:
    FileSystem() {
        root = new Dir();
    }

    vector<string> ls(string path) {
        Dir* t = root;
        vector<string> result;
        if (path != "/") {
            vector<string> d = split(path, '/');
            for (int i = 1; i < d.size() - 1; i++) {
                t = t->dirs[d[i]];
            }
            if (t->files.find(d.back()) != t->files.end()) {
                result.push_back(d.back());
                return result;
            } else {
                t = t->dirs[d.back()];
            }
        }
        for (auto& p : t->dirs) result.push_back(p.first);
        for (auto& p : t->files) result.push_back(p.first);
        sort(result.begin(), result.end());
        return result;
    }

    void mkdir(string path) {
        Dir* t = root;
        vector<string> d = split(path, '/');
        for (int i = 1; i < d.size(); i++) {
            if (t->dirs.find(d[i]) == t->dirs.end())
                t->dirs[d[i]] = new Dir();
            t = t->dirs[d[i]];
        }
    }

    void addContentToFile(string filePath, string content) {
        Dir* t = root;
        vector<string> d = split(filePath, '/');
        for (int i = 1; i < d.size() - 1; i++) {
            t = t->dirs[d[i]];
        }
        t->files[d.back()] += content;
    }

    string readContentFromFile(string filePath) {
        Dir* t = root;
        vector<string> d = split(filePath, '/');
        for (int i = 1; i < d.size() - 1; i++) {
            t = t->dirs[d[i]];
        }
        return t->files[d.back()];
    }

private:
    vector<string> split(const string& s, char delimiter) {
        vector<string> tokens;
        string token;
        for (char c : s) {
            if (c == delimiter) {
                if (!token.empty()) tokens.push_back(token);
                token.clear();
            } else {
                token += c;
            }
        }
        if (!token.empty()) tokens.push_back(token);
        return tokens;
    }
};

int main() {
    FileSystem* obj = new FileSystem();
    vector<string> param_1 = obj->ls("/path");
    obj->mkdir("/path");
    obj->addContentToFile("/path/file.txt", "content");
    string param_4 = obj->readContentFromFile("/path/file.txt");

    // Output results for demonstration
    for (const auto& name : param_1) {
        cout << name << endl;
    }
    cout << param_4 << endl;

    delete obj;
    return 0;
}
