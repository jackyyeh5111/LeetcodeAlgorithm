/*********************** Compare in Set to avoid TLE ******************/
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList)
    {
        /*
            thought: is this a string editing(DP) question?
            bottom up
            cog log lot dot hot hit
                        hot hit
                    dog
                dog
            T:O(2^n) exponential time -> TLE on large test case
            ------------------------
            Build a graph and apply BFS!!, each connected node has hamming distance 1
        */
        if (find(wordList.begin(),wordList.end(),beginWord)==wordList.end())
            wordList.push_back(beginWord);
        unordered_map<string, vector<string>> graph;
        unordered_map<string, bool> visited;
        unordered_map<string, vector<vector<string>>> paths;
        unordered_set<string> wordSet(wordList.begin(),wordList.end());
        cout<<"start"<<endl;
        for (string a:wordList) {
            visited[a]=false;
            paths[a]=vector<vector<string>>{};
            for (int i=0; i<a.length(); ++i) {
                for (int x=0; x<26; ++x){
                    if (a[i]==x) continue;
                    string newA=a;
                    newA[i]='a'+x;
                    if(wordSet.find(newA)!=wordSet.end())
                        graph[a].push_back(newA);
                }
            }
        }
        cout<<"built"<<endl;
        queue<string> q;
        q.push(beginWord);
        bool found=false;
        paths[beginWord].push_back({beginWord});
        visited[beginWord]=true;
        while(!q.empty()&&!found) {
            int levelSize=q.size();
            // cout<<"--------"<<levelSize<<endl;
            unordered_set<string> record;
            for (int i=0; i<levelSize; ++i) {
                string src=q.front(); q.pop();
                // cout<<src<<":";
                for (string dst:graph[src]) {
                    if (visited[dst]) continue;

                    // cout<<dst<<",";
                    auto prevPaths=paths[src];
                    for(auto &path:prevPaths) path.push_back(dst);
                    paths[dst].insert(paths[dst].end(),prevPaths.begin(),prevPaths.end());
                    if (dst==endWord) found=true;
                    if (record.find(dst)==record.end()) {
                        q.push(dst);
                        record.insert(dst);
                    }
                }
                // cout<<endl;
            }
            for (string v:record) visited[v]=true;
        }
        return paths[endWord];
    }

    int hammingString(string a, string b)
    {
        int i=0; int count=0;
        while(a[i]!='\0') {
            if (a[i]!=b[i]) count++;
            i++;
        }
        return count;
    }
};

/*********************** Calculate Hamming Distance TLE ******************/
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList)
    {
        /*
            thought: is this a string editing(DP) question?
            bottom up
            cog log lot dot hot hit
                        hot hit
                    dog
                dog
            T:O(2^n) exponential time -> TLE on large test case
            ------------------------
            Build a graph and apply BFS!!, each connected node has hamming distance 1
        */
        if (find(wordList.begin(),wordList.end(),beginWord)==wordList.end())
            wordList.push_back(beginWord);
        unordered_map<string, vector<string>> graph;
        unordered_map<string, bool> visited;
        unordered_map<string, vector<vector<string>>> paths;
        cout<<"start"<<endl;
        for (string a:wordList) {
            visited[a]=false;
            paths[a]=vector<vector<string>>{};
            for (string b:wordList) {
                if (a==b) continue;
                int hamming=hammingString(a,b);
                if (hamming==1) graph[a].push_back(b);
            }
        }
        cout<<"built"<<endl;
        queue<string> q;
        q.push(beginWord);
        bool found=false;
        paths[beginWord].push_back({beginWord});
        visited[beginWord]=true;
        while(!q.empty()&&!found) {
            int levelSize=q.size();
            // cout<<"--------"<<levelSize<<endl;
            unordered_set<string> record;
            for (int i=0; i<levelSize; ++i) {
                string src=q.front(); q.pop();
                // cout<<src<<":";
                for (string dst:graph[src]) {
                    if (visited[dst]) continue;

                    // cout<<dst<<",";
                    auto prevPaths=paths[src];
                    for(auto &path:prevPaths) path.push_back(dst);
                    paths[dst].insert(paths[dst].end(),prevPaths.begin(),prevPaths.end());
                    if (dst==endWord) found=true;
                    if (record.find(dst)==record.end()) {
                        q.push(dst);
                        record.insert(dst);
                    }
                }
                // cout<<endl;
            }
            for (string v:record) visited[v]=true;
        }
        return paths[endWord];
    }

    int hammingString(string a, string b)
    {
        int i=0; int count=0;
        while(a[i]!='\0') {
            if (a[i]!=b[i]) count++;
            i++;
        }
        return count;
    }
};

/***************** Same BFS idea but no TLE *************************/

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> res;
        unordered_set<string> visit;  //notice we need to clear visited word in list after finish this level of BFS
        queue<vector<string>> q;
        unordered_set<string> wordlist(wordList.begin(),wordList.end());
        q.push({beginWord});
        bool flag= false; //to see if we find shortest path
        while(!q.empty()){
            int size= q.size();
            for(int i=0;i<size;i++){            //for this level
                vector<string> cur = q.front();
                q.pop();
                vector<string> newadd =  addWord(cur.back(),wordlist);
                for(int j=0;j<newadd.size();j++){   //add a word into path
                    vector<string> newline(cur.begin(),cur.end());
                    newline.push_back(newadd[j]);
                    if(newadd[j]==endWord){
                     flag=true;
                    res.push_back(newline);
                    }
                    visit.insert(newadd[j]);
                    q.push(newline);
                }
            }
            if(flag) break;  //do not BFS further
            for(auto it=visit.begin();it!=visit.end();it++) wordlist.erase(*it); //erase visited one
            visit.clear();
        }
        return res;
    }

    // find words with one char different in dict
    // hot->[dot,lot]
    vector<string> addWord( string word,unordered_set<string>& wordlist ){
        vector<string> res;
        for(int i=0;i<word.size();i++){
            char s =word[i];
            for(char c='a';c<='z';c++){
                word[i]=c;
                if(wordlist.count(word)) res.push_back(word);
            }
            word[i]=s;
        }
        return res;
    }
};
