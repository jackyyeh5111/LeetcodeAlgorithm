/***** Fourth Visit *****/
/*
    bi-direction mono stack
    T:O(n)/S:O(n)
    -----
    2 ptr solution
    T:O(n)/S:O(n)
*/
class Solution {
public:
    int trap(vector<int>& height)
    {
        int l=0,r=height.size()-1,ans=0,cur=0;
        while (l<=r) {
            if (height[l]<height[r]) {
                ans+=max(0,cur-height[l]);
                cur=max(cur,height[l++]);
            }
            else {
                ans+=max(0,cur-height[r]);
                cur=max(cur,height[r--]);
            }
        }
        return ans;
    }
};

/***** Third Visit *****/
/*
    Graham's Scan w.o. sorting.
    Use a stack to record all convex points.
    concave: p1>p2 && p2 < p3
    T:O(n)/S:O(n)
    -----
    bi-direction checking since we dontt know the min restored rains are from left or right checking
    Try T:O(n)/S:O(1)
    -----
    Actually we can know it!! We just need to check the smaller one.
    T:O(n)/S:O(1)
*/

class Solution {
public:
    int trap(vector<int>& height)
    {
        int n=height.size(), ans=0;
        int lmax=0,rmax=0;
        vector<int> v(n,INT_MAX);
        for (int i=0; i<n; ++i) {
            lmax=max(lmax,height[i]);
            rmax=max(rmax,height[n-i-1]);
            v[i]=min(v[i],lmax-height[i]);
            v[n-i-1]=min(v[n-i-1],rmax-height[n-i-1]);
        }
        for (int num:v) ans+=num;
        return ans;
    }
};

class Solution {
public:
    int trap(vector<int>& height)
    {
        int n=height.size(), ans=0;
        int lmax=0,rmax=0,l=0,r=n-1;
        while (l<r) {
            if (height[l]<height[r]) {
                if (height[l]<=lmax) ans+=lmax-height[l++];
                else lmax=height[l++];
            }
            else {
                if (height[r]<=rmax) ans+=rmax-height[r--];
                else rmax=height[r--];
            }
        }
        return ans;
    }
};

/***** Second Visit *****/
/*
    Array:
    1. 2 ptr solution
    2. moving window
    3. could sorting help?
    -----
    graham's alg
    0 1 2 3 2 2 1
    find concav:
        a >=b&& c>=b
    T:2 pass O(n)/S:O(n)
    -----
    2 stack approach
    top-down & bottom up
    if height[i] < cur_max, push to stack
    else iteratively pop ou and add cur_max-pop(), then update cur_max.
    T:2 pass O(n)/S:O(n)
    -----
*/
// 2 stack approach
class Solution {
public:
    int trap(vector<int>& height)
    {
        int ans=0, cur_max=0,n=height.size();
        stack<int> s1,s2;
        for (int h:height) {
            if (h<cur_max) s1.push(h);
            else {
                while(!s1.empty()) {
                    ans+=cur_max-s1.top();
                    s1.pop();
                }
                cur_max=h;
            }
        }
        if (s1.size()==0) return ans;
        cur_max=0;
        for (int i=n-1; i>=n-(int)s1.size()-1; --i) {
            if (height[i]<cur_max) s2.push(height[i]);
            else {
                while(!s2.empty()) {
                    ans+=cur_max-s2.top();
                    s2.pop();
                }
                cur_max=height[i];
            }
        }
        return ans;
    }
};

// graham's alg
/*
    Array:
    1. 2 ptr solution
    2. moving window
    3. could sorting help?
    -----
    graham's alg
    0 1 2 3 2 2 1
    find concav:
        a >=b&& c>=b
    T:2 pass O(n)/S:O(n)
    -----
    2 stack approach
    top-down & bottom up
    if height[i] < cur_max, push to stack
    else iteratively pop ou and add cur_max-pop(), then update cur_max.
    T:2 pass O(n)/S:O(n)
    -----
*/
class Solution {
public:
    int trap(vector<int>& height)
    {
        int n=height.size(), i=2;
        if (n<=2) return 0;
        stack<int> s;
        s.push(0); s.push(1);
        while(i<n) {
            int b=s.top(); s.pop();
            int a=s.top(); s.pop();
            while(s.size()>=1&&!isConvex(height[a],height[b],height[i]))  {
                swap(a,b);
                a=s.top(); s.pop();
            }
            s.push(a);
            if (isConvex(height[a],height[b],height[i])) s.push(b);
            s.push(i++);
        }
        int sum=0;
        while(s.size()>=2) {
            int b=s.top(); s.pop();
            int a=s.top();
            int tmp=min(height[a],height[b]);
            a++;
            while(a<b) {
                sum+=max(tmp-height[a++],0);
            }
        }
        return sum;
    }

    bool isConvex(int a, int b, int c)
    {
        if (b<=a&&b<=c) return false;
        else return true;
    }
};


/***** First Visit *****/
// My soluction: Reduce to convex hull problem and use Graham's Scan Algorithm.
class Solution {
public:
    vector<int> s;
    int trap(vector<int>& height)
    {
        // T:O(n), S:O(n)
        if (height.size()<=2) return 0;

        s.push_back(0); s.push_back(1);
        for (int i=2; i<height.size(); ++i) {
            while (s.size()>1 &&
                   isConcave(height[s[s.size()-2]],height[s[s.size()-1]],height[i])) s.pop_back();
            s.push_back(i);
        }
        for (int c:s) cout<<c<<",";
        cout<<endl;

        int sum=0;
        for (int i=0; i<s.size()-1; ++i) {
            sum+=min(height[s[i]],height[s[i+1]])*(s[i+1]-s[i]-1);
            for (int j=s[i]+1; j<s[i+1]; ++j)
                sum -= height[j];
        }
        return sum;
    }

    bool isConcave(int a, int b, int c)
    {
        if (b<=a&&b<=c) return true;
        else return false;
    }
};

// Two pointers.
class Solution {
public:
    int trap(vector<int>& height)
    {
        int left = 0, right = height.size() - 1;
        int ans = 0;
        int left_max = 0, right_max = 0;
        while (left < right) {
            if (height[left] < height[right]) {
                height[left] >= left_max ? (left_max = height[left]) : ans += (left_max - height[left]);
                ++left;
            }
            else {
                height[right] >= right_max ? (right_max = height[right]) : ans += (right_max - height[right]);
                --right;
            }
        }
        return ans;
    }
};
