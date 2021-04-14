/*
    expiration takes place before the other actions.
    currentTime across all the function calls will be strictly increasing.

    multiset<pair<int,int>> timeline -> to record each entry time. <time,id>
        idnexing: T:O(logn)
        insert/erase: T:O(logn)
    unordered_map<int,int> table, id <-> entry time

    additional function check(int currentTime) to erase all expired index.
*/
class AuthenticationManager {
public:
    int k=0;
    multiset<pair<int,string>> timeline; // entry time, id
    unordered_map<string,int> table; // id <-> entry time
    AuthenticationManager(int timeToLive) {
        k=timeToLive;
    }

    void generate(string tokenId, int currentTime) {
        check(currentTime);
        table[tokenId]=currentTime;
        timeline.insert({currentTime, tokenId});
    }

    void renew(string tokenId, int currentTime) {
        check(currentTime);
        if (table.count(tokenId)==0) return;
        timeline.erase(timeline.find({table[tokenId],tokenId}));
        generate(tokenId, currentTime);
    }

    int countUnexpiredTokens(int currentTime) {
        check(currentTime);
        return timeline.size();
    }

    void check(int ctime) {
        auto it=timeline.begin();
        while (it->first<=ctime-k&&it!=timeline.end()){
            auto cit=it++;
            string id=cit->second;
            table.erase(id);
            timeline.erase(cit);
        }
    }
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */
