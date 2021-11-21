class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2)
    {
        if (sentence2.length()<sentence1.length()) // make sentencce1 longer
            swap(sentence1,sentence2);
        else if (sentence1.length()==sentence2.length()) return sentence1==sentence2;
        deque<string> q;
        int m=sentence1.length(), n=sentence2.length(), i=0, j=0;
        while (i<m) {
            string word="";
            while (i<m&&sentence1[i]==' ') i++;
            while (i<m&&sentence1[i]!=' ') word+=sentence1[i++];
            q.push_back(word);
        }
        while (j<n) {
            string word="";
            while (j<n&&sentence2[j]==' ') j++;
            while (j<n&&sentence2[j]!=' ') word+=sentence2[j++];
            if (!q.empty()&&q.front()==word) q.pop_front();
            else break;
        }
        j=n-1;
        while (j>=0) {
            string word="";
            while (j>=0&&sentence2[j]==' ') j--;
            while (j>=0&&sentence2[j]!=' ') word+=sentence2[j--];
            reverse(word.begin(),word.end());
            if (!q.empty()&&q.back()==word) q.pop_back();
            else break;
        }

        return q.empty();
    }
};
