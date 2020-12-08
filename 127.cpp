/***** Second Visit *****/
class Solution {
public:
    unordered_map<string,vector<string>> graph;
    unordered_map<string,bool> visited;
    int ladderLength(string beginWord, string endWord, vector<string>& wordList)
    {
        unordered_set<string> words(wordList.begin(),wordList.end());
        if(words.count(endWord)==0) return 0;
        words.insert(beginWord);
        words.insert(endWord);
        for (string word:words) {
            visited[word]=false;
            graph[word]=vector<string>{};
            for (int j=0; j<word.length(); ++j) {
                for (int i=0; i<26; ++i) {
                    if (word[j]==i+'a') continue;
                    string new_word=word;
                    new_word[j]='a'+i;
                    if (words.count(new_word)!=0)
                        graph[word].push_back(new_word);
                }
            }
        }

        int ans=1;
        queue<string> q;
        q.push(beginWord);
        visited[beginWord]=true;
        bool found=false;
        while (!q.empty()&&!found) {
            int k=q.size();
            for (int i=0; i<k; ++i) {
                string u=q.front(); q.pop();
                for (string v:graph[u]) {
                    if (visited[v]) continue;
                    if (v==endWord) return ans+1;
                    q.push(v);
                    visited[v]=true;
                }
            }
            ans++;
        }
        return 0;
    }
};

/***** First Visit *****/
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
