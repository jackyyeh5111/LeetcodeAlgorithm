/*
    2 500 000 000
*/
class SnapshotArray {
public:
    vector<vector<pair<int,int>>> db; // pair<snap_id, value>
    int snap_id=1;
    // 1-index of snap_id
    // T:O(n)
    SnapshotArray(int length) {
        db=vector<vector<pair<int,int>>>(length,vector<pair<int,int>>{make_pair(0,0)});
    }

    // T:O(1)
    void set(int index, int val) {
        if (db[index].back().first==snap_id)
            db[index].back().second=val;
        else db[index].push_back(make_pair(snap_id,val));
    }

    // T:O(1)
    int snap() {
        snap_id++;
        return snap_id-2;
    }

    /*
        [{0,0} {1,5}]
    */
    int get(int index, int snap_id) {
        snap_id+=1;
        auto changes=db[index];
        int l=0,r=changes.size()-1;
        while (l<=r) {
            int mid=(l+r)/2;
            if (changes[mid].first==snap_id) return changes[mid].second;
            else if (changes[mid].first>snap_id) r=mid-1;
            else l=mid+1;
        }
        return changes[r].second;
    }
};
