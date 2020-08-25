/*
    Combination:
        1 2 3 4
        12/13/14/23/24/34
*/

/************** Recursive with call by vale **************/
class CombinationIterator {
public:
    vector<string> perms;
    int idx;
    CombinationIterator(string characters, int combinationLength) {
        perm(characters,combinationLength,0,"");
        idx=0;
    }

    void perm(string &characters, int combinationLength, int cur, string sofar)
    {
        // cout<< cur << ","<<sofar<<endl;
        if (sofar.length()==combinationLength) {
            perms.push_back(sofar);
            return;
        }

        for (int i=cur; i<characters.length(); ++i) {
            string tmp=sofar;
            tmp += characters[i];
            perm(characters,combinationLength,i+1,tmp);
        }
    }

    string next() {
        return perms[idx++];
    }

    bool hasNext() {
        return idx<perms.size();
    }
};

/************** 2 ptr with find next comb dynamically **************/
 class CombinationIterator {
public:
    string chars;
    int n; // combo size
    int nchars; // chars size
    string res; // last returned result
    vector<int> combo; // size=n; at start set to 1st chars, eg 0,1,2 for n=3
    CombinationIterator(string characters, int combinationLength) {
        res="";
        n=combinationLength;
        chars=characters;
        nchars=chars.size();
        combo.resize(n);
        for(int i=0;i<n;i++) combo[i]=i; // initial N chars match the beginning of "chars"
    }

    string next() {
        if(res.size()==0) {
            res=chars.substr(0,n);
            return res;
        }
        for(int i=n-1;i>=0;i--) { // find the last symbol we can increase
            if(combo[i]!=nchars-1) {
                if (i==n-1 || combo[i]+1<combo[i+1]) {
                    combo[i++]++; // take next char and set remaining chars to the nearest
                    for(;i<n;i++) { // e.g. "abcde",3: abe -> acd
                        combo[i]=combo[i-1]+1;
                    }
                    break;
                }
            }
        }
        res="";
        for(int i:combo)  res+=chars[i]; // compose string
        return res;
    }

    bool hasNext() {
        return res.size()==0||res[0]!=chars[chars.size()-n]; // e.g. chars=abCd, res=Cd
    }
};
