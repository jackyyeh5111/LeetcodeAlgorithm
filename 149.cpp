/***** Second Visit *****/
/*
    Calculate thee gradient between each point to the original point.
    use a hashmap to count the same gradient points.
    y=ax+b
    b=y-ax
*/
class Solution {
public:
    int maxPoints(vector<vector<int>>& points)
    {
        int ans=1,n=points.size();
        if (n<=2) return n;
        unordered_map<string,int> table;
        for(int i=0; i<n; ++i) {
            string k=to_string(points[i][0])+"_"+to_string(points[i][1]);
            if (table.count(k)!=0) swap(points[i--],points[--n]);
            table[k]++;
        }
        if (n==1) {
            string k=to_string(points[0][0])+"_"+to_string(points[0][1]);
            return table[k];
        }
        unordered_map<long double,unordered_map<long double,int>> m;
        for (int i=0; i<n; ++i) {
            unordered_map<long double,unordered_set<long double>> visited;
            for (int j=0; j<n; ++j) {
                if (i==j) continue;
                long double dx=(long double)points[i][0]-(long double)points[j][0];
                long double dy=(long double)points[i][1]-(long double)points[j][1];
                long double g=dx==0?INT_MAX:(long double) dy/(long double) dx;
                if(abs(g)==0) g=0;
                double y_cross= (long double)dx==(long double)0?
                    points[i][0]:((long double) points[i][1]-g*(long double)points[i][0]);
                if (visited[g].count(y_cross)!=0) continue;
                string k=to_string(points[i][0])+"_"+to_string(points[i][1]);
                m[g][y_cross]+=table[k];
                visited[g].insert(y_cross);
                ans=max(ans,m[g][y_cross]);
            }
        }
        return ans;
    }
};

/***** First Visit *****/
class Solution {
public:
    int maxPoints(vector<vector<int>>& points)
    {
        /*
            First thought:
                find min/max x/y and conduct a matrix
                T:O(n^2),S:O(n^2), however sparse matrix make this inefficient
            same line -> same gradient, same intersection point on x/y axis
            use a double hashmap to record each gradient/b
            y1=ax1+b
            y2=ax2+b
            ----------------
            we need make gradient a unique hashkey.
            say we have dy,dx, we can do calculates:
                f=gcd(dy,dx)
                key="dy/f"+"_"+"dx/f"
        */
        if(points.size()==1) return 1;
        unordered_map<long double,unordered_map<long double,unordered_set<int>>> m;
        for (int i=0; i<points.size(); ++i) {
            for (int j=i+1; j<points.size(); ++j) {
                long double dx=points[i][0]-points[j][0];
                long double dy=points[i][1]-points[j][1];
                long double g= dx==0 ? INT_MAX:dy/dx;
                m[g][(long double)points[i][1]-g*(long double)points[i][0]].insert(i);
                m[g][(long double)points[i][1]-g*(long double)points[i][0]].insert(j);
            }

        }
        int ans=0;
        for (auto mit=m.begin();mit!=m.end();++mit){
            auto subm=mit->second;
            for (auto submit=subm.begin();submit!=subm.end();++submit){
                ans=max((int)(submit->second.size()),ans);
            }
        }
        return ans;
    }
};
