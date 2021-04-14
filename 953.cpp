
/*
    words = ["hello","leetcode"],
    order = "hlabcdefgijkmnopqrstuvwxyz"

    A typical sorting algorithm
    Make a index table from the given order.
    sort by customized compare function
    maintain a global variable if there's any change

    quick sort as default -> T:O(nlogn*m)/S:O(1)
    Actually we dont need to sort it, just utilize the concept of bubble sort for only one iteration. If there's any change, return false, else return true.
    T:O(nm)/S:O(1)
*/
class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char,int> table;
        int m=order.length();
        for (int i=0; i<m; ++i)
            table[order[i]]=i;
        int n=words.size();
        for (int i=0; i<n-1; ++i) {
            // bubble floating by comparinng words[i]/words[i+1]
            int x=0,y=0,p=words[i].length(),q=words[i+1].length();
            bool change=false;
            while (x<p&&y<q){
                if (table[words[i][x]]>table[words[i+1][y]])
                    {change=true; break;}
                else if (table[words[i][x]]<table[words[i+1][y]])
                    break;
                else {x++; y++;}
            }
            if (change||y==q&&x<p) return false;
        }
        return true;
    }
};
