class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList)
    {
        unordered_set<string> wordSet(wordList.begin(),wordList.end());
        if (wordSet.find(beginWord)==wordSet.end()) wordSet.insert(beginWord);
        unordered_map<string,bool> visited;
        unordered_map<string,vector<string>> graph;
        // build graph
        for (string word:wordSet) {
            visited[word]=false;
            for (int i=0; i<word.length(); ++i) {
                for (int x=0; x<26; ++x) {
                    if(word[i]==x) continue;
                    string newWord=word;
                    newWord[i]='a'+x;
                    if(wordSet.find(newWord)!=wordSet.end())
                        graph[word].push_back(newWord);
                }
            }
        }
        // do BFS
        queue<string> q;
        q.push(beginWord);
        visited[beginWord]=true;
        int path=1;
        while(!q.empty()) {
            int size=q.size();
            // cout<<"----"<<size<<endl;
            for (int i=0; i<size; ++i) {
                string src=q.front(); q.pop();
                // cout<<"src: "<<src<<" dst: ";
                for (string dst:graph[src]) {
                    if (visited[dst]) continue;
                    // cout<<dst<<",";
                    if(dst==endWord) return path+1;
                    visited[dst]=true;
                    q.push(dst);
                }
                // cout<<endl;
            }
            path++;
        }
        return 0;
    }
};
