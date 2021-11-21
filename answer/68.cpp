class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth)
    {
        // iteratively grab max words n s.t. length of words+n-1<=maxWidth
        // complement space to match length maxWidth
        // change the last one to be left justified.
        vector<string> ans;
        for (int i=0; i<words.size();) {
            int sum=0;
            vector<string> candidate;
            while((i<words.size())&&(sum+words[i].length()<=maxWidth)){
                sum+=words[i].length();
                candidate.push_back(words[i]);
                if(sum<maxWidth){sum++;}
                i++;
            }
            if (i==words.size()) {
                string line=""; int tmp=0;
                for (string word:candidate){
                    tmp+=word.length();
                    line+=word;
                    if(tmp<maxWidth){
                        tmp++;
                        line+=" ";
                    }
                }
                line+=string(maxWidth-tmp, ' ');
                ans.push_back(line);
            }
            else {
                int tmp=candidate.size()-1;
                for (string word:candidate) tmp+=word.length();
                int numSpace = maxWidth-tmp;
                int divider = max((int)candidate.size()-1,1);
                string line=candidate[0];
                if (candidate.size()==1) line+=string(numSpace, ' ');
                int remainder = numSpace%divider;
                for (int j=1; j<candidate.size(); ++j) {
                    line+=string(numSpace/divider+1+(remainder>0), ' ')+candidate[j];
                    remainder--;
                }
                ans.push_back(line);
            }
        }
        return ans;
    }
};
