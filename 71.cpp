class Solution {
public:
    string simplifyPath(string path) {
        deque<string> dirnames;
        splitDirname(path, dirnames);
        return getCanonicalPath(dirnames);
    }
    string getCanonicalPath(deque<string> &dirnames) {
        string path = "/";
        while(!dirnames.empty()) {
            path += dirnames.front() + "/";
            dirnames.pop_front();
        }
        if (path.size() > 1)
            path.pop_back();
        return path;
    }
    void splitDirname(const string &path, deque<string> &dirnames) {
        int end = 0;
        while(end < path.size()) {
            int start = end;
            while(end < path.size() && path[end] != '/')
                end++;
            // ignore empty dirname
            if (start < end) {
                string dirname = path.substr(start, end - start);
                if (dirname == "."){} // do nothing
                else if (dirname == "..") {
                    if (!dirnames.empty()) 
                        dirnames.pop_back();
                }
                else{
                    dirnames.push_back(dirname);
                }
            }
            end++;
        }
    }
};

/*
    /a/.../b/

    [b, ...]
    /b 
 */