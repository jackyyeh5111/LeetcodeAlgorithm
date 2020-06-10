class Solution {
public:
    /*
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
    {
        int start_pointer = gas.size()-1;
        int end_pointer = 0;
        int running_gas = gas[start_pointer] - cost[start_pointer];
        while(end_pointer<start_pointer){
            cout<<running_gas<<endl;
            // insufficient gas, get more from start idx
            if(running_gas<0){
                start_pointer--;
                running_gas += gas[start_pointer] - cost[start_pointer];
            }
            // sufficient gas, travel to next end idx
            else {
                running_gas += gas[end_pointer] - cost[end_pointer];
                end_pointer++;
            }
        }
        return running_gas >= 0 ? start_pointer : -1;
    }
    */

    int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
    {
        // always start from the bottom most.
        int min_gas = 0;
        int run_gas = 0;
        int index = 0;
        for (int i=0; i<gas.size(); ++i){
            run_gas += gas[i]-cost[i];
            if(run_gas<min_gas){
                min_gas=run_gas;
                index = (index+1)%gas.size();
            }
        }
        return run_gas >= 0 ? index : -1;
    }
};
