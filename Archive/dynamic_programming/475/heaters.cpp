class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        if(houses.size()==0) return 0;
        std::sort(houses.begin(),houses.end());
        std::sort(heaters.begin(),heaters.end());

        int heater_index = 0;
        int max_dist = 0;
        for (int i=0; i<houses.size();++i){
            // Find nearest heater
            while((heater_index+1)<heaters.size() && std::abs(houses[i]-heaters[heater_index])>=std::abs(houses[i]-heaters[heater_index+1]))
                heater_index++;
            // Calculate distance
            max_dist = std::max(std::abs(houses[i]-heaters[heater_index]),max_dist);
            if(max_dist!=0) {
                cout<<max_dist<<" "<<houses[i]<<" "<<heaters[heater_index]<<endl;
            }
        }
        return max_dist;

    }
};
