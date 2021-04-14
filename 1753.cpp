class Solution {
public:
    int maximumScore(int a, int b, int c)
    {
        vector<int> v={a,b,c};
        sort(v.begin(),v.end());
        return min((a+b+c)/2,v[0]+v[1]);
    }
};

class Solution {
public:
    bool check(int a,int b,int c)
    {
        return a&&b || b&&c || a&&c;
    }
    int maximumScore(int a, int b, int c) {
        int ans=0;
        while(check(a,b,c))
        {
            if(a<b) swap(a,b);
            if(a<c) swap(a,c);
            if(b<c) swap(b,c);
            a--; b--;
            ans++;
            // cout<<a<<" "<<b<<" "<<c<<endl;
        }
        return ans;
    }
};
