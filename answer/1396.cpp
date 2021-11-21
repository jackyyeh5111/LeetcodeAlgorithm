/*
    unordered_map<string,unordered_map<int,int>> start
        start station -> id -> time
    unordered_map<string,unordered_map<string,pair<double,int>>> mean;
        start station -> end station -> <mean, count>
*/
class UndergroundSystem {
public:
    unordered_map<string,unordered_map<int,int>> start;
    unordered_map<int,string> table;
    unordered_map<string,unordered_map<string,pair<double,int>>> mean;
    UndergroundSystem() {

    }

    void checkIn(int id, string stationName, int t) {
        start[stationName][id]=t;
        table[id]=stationName;
    }

    void checkOut(int id, string stationName, int t) {
        string startStation=table[id];
        double cmean=mean[startStation][stationName].first;
        double cnt=mean[startStation][stationName].second;
        mean[startStation][stationName].first=(cmean*(cnt++)+t-start[startStation][id])/cnt;
        mean[startStation][stationName].second=cnt;
        start[startStation].erase(id);
        table.erase(id);
    }

    double getAverageTime(string startStation, string endStation) {
        return mean[startStation][endStation].first;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
