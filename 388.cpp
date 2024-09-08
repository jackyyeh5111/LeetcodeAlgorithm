class Solution {
public:
    int lengthLongestPath(string input) {
        vector<int> len_each_layer;
        int cur_layer = 0;
        int max_file_len = 0;
        int start = 0, end = 0;
        /* 
            dir\n\tsubdir1
                ^
         */
        while(end < input.size()) {
            if (isSpecialChar(input[end])) {
                if (input[end] == '\t') cur_layer++;
                end++;
            }
            else {
                start = end;
                while(end < input.size() && !isSpecialChar(input[end]))
                    end++;
                string name = input.substr(start, end - start);
                if (isFile(name)) {
                    int path_len = getPathLen(len_each_layer, cur_layer, name);
                    max_file_len = max(path_len, max_file_len);
                }
                else {    
                    if (len_each_layer.size() == cur_layer)
                        len_each_layer.push_back(0);
                    len_each_layer[cur_layer] = end - start;
                }
                cur_layer = 0;
            }
        }
        return max_file_len;
    }
    int getPathLen(const vector<int> &len_each_layer, int cur_layer, string name) {
        int total_len = 0;
        for (int i = 0; i < cur_layer; i++)
            total_len += len_each_layer[i];
        total_len += cur_layer; // add number of / len
        total_len += name.size();
        return total_len;
    }
    bool isFile(const string &fname) {
        return fname.find('.') != string::npos;
    }
    bool isSpecialChar(char ch) {
        return ch == '\n' || ch == '\t';
    }
};

/* 
    rootdir
    input: 
        "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext"
    
    variables:
        1. len_each_layer = [3, 3+7, 3+7+10]
        2. max_file_len

    1. newline: new file or dir
    2. identify file: <name.ext>
    3. 

    dir
    ⟶ subdir1
    ⟶ ⟶ file1.ext
    ⟶ ⟶ subsubdir1
    ⟶ ⟶ ⟶ file2.ext
    ⟶ ⟶ subsubdir2
    ⟶ subdir2
    ...
 */