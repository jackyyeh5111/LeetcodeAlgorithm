/***** Second Visit *****/
/*
    catalan number: 1/(n+1) C^2n_n
    B0
    B1 ()
    B2 ()() (())
    B3 B1B2 B2B1
    T:O(3^n)/S:O(catalab number)
    refers: https://stackoverflow.com/questions/27371612/catalan-numbers-recursive-function-time-complexity
    ...
*/
class Solution {
public:
    vector<string> generateParenthesis(int n)
    {
        static vector<vector<string>> table(2);
        table[0]=vector<string>{""};
        table[1]=vector<string>{"()"};
        if (n<=1) return table[n];
        for (int i=2; i<=n; ++i) {
            if (i<table.size()) continue;
            else if (i==table.size()) table.push_back(vector<string>{});
            for (int j=0; j<i; ++j) {
                for (auto l:table[j]) {
                    for (auto r:table[i-1-j]) {
                        table[i].push_back("("+l+")"+r);
                    }
                }
            }
        }
        return table[n];
    }
};

/***** First Visit *****/
class Solution {
public:
    vector<string> generateParenthesis(int n)
    {
        // DP T:((1/n+1)(C^2n_n)), S:O(n)
        // Bn = B0Bn-1+...+Bn-1B0

        if(n<0) return vector<string>{};
        unordered_map<int, vector<string>> table;
        table[0] = vector<string>{""};
        table[1] = vector<string>{"()"};
        table[2] = vector<string>{"()()","(())"};
        if (n<=2) return table[n];
        else {
            for (int i=3; i<=n; ++i) {
                vector<string> ans;
                for(int j=0; j<i; ++j) {
                    vector<string> left = table[j];
                    vector<string> right = table[i-j-1];
                    for (string leftComb:left) {
                        for (string rightComb:right) {
                            ans.push_back(leftComb+"("+rightComb+")");
                        }
                    }
                }
                table[i] = ans;
            }
        }
        return table[n];
    }
};

// T:((1/n+1)(C^2n_n)), S:O((1/n+1)(C^2n_n)) if count recursive times as space or S:O(1) if not.

vector<string> result;
vector<string> generateParenthesis(int n) {
    helper("", n, 0);
    return result;
}

/*  this hepler function insert result strings to "vector<string> result"
	When number of '(' less than "n", can append '(';
	When number of '(' is more than number of ')', can append ')';

	string s : current string;
	int leftpare_need : number of '(' that have not put into "string s";
	int moreleft : number of '(' minus number of ')' in the "string s";
*/

void helper(string s, int leftpare_need, int moreleft)
{
	if(leftpare_need == 0 && moreleft == 0)
	{
	    result.push_back(s);
	    return;
	}
	if(leftpare_need > 0)
		helper(s + "(", leftpare_need - 1, moreleft+1);
	if(moreleft > 0)
		helper(s + ")", leftpare_need, moreleft - 1);
}
