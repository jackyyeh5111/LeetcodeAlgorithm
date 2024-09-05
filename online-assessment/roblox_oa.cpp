void finalizeStr(vector<string> &output, int width) {
    string line = "+" + string(width, '*') + "+";
    output.insert(output.begin(), line);
    output.push_back(line);
}

string makeOutputMsg(string word, string user, int width) {
    string line(width, ' ');
    if (user == "1") {
        for (int i = 0; i < word.size(); i++)
            line[i] = word[i];
    }
    else {
        for (int i = 0; i < word.size(); i++)
            line[width - i - 1] = word[word.size() - i - 1];
    }
    return "|" + line + "|";
}

vector<string> solution(vector<vector<string>> messages, int width, int userWidth) {
    vector<string> output;
    
    for (const auto &message : messages) {
        string user = message[0];
        string str = message[1];
        
        int start = 0;
        string line = "";
        for (int end = 0; end < str.size(); end++) {   
            if (str[end] == ' ') {
                string word = str.substr(start, end - start);
                if (line.size() == 0)
                    line += word;
                else {    
                    int word_len = end - start;
                    if (line.size() + word_len + 1 > userWidth) {
                        output.push_back(makeOutputMsg(line, user, width));
                        line = word;
                    }
                    else {
                        line += " " + word;
                    }
                }
                start = end + 1;
            }
        }
        string 
        if (.size() > 0)
            output.push_back(makeOutputMsg(line, user, width));
    }
    
    finalizeStr(output, width);
    return output;
}