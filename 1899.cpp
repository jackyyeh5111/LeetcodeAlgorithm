/* 
    Improve by chat GPT! Amazing!!!
 */
class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        // Track whether each target value is achievable
        bool found[3] = {false, false, false};
        
        for (const auto& triplet : triplets) {
            // If any value in the triplet exceeds the target, skip it
            if (triplet[0] > target[0] || triplet[1] > target[1] || triplet[2] > target[2]) {
                continue;
            }
            
            // Check each component of the triplet to see if it matches the target
            for (int i = 0; i < 3; i++) {
                if (triplet[i] == target[i]) {
                    found[i] = true;
                }
            }
        }
        
        // If all target values were found, return true, otherwise false
        return found[0] && found[1] && found[2];
    }
};


class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        /* 
            approach:
            1. check each position of triplets
            2. if value of the triplet <= target value, keep it to next iter
            3. for each iter, make sure at least one triplet that has 
                corresponding value equals to target
            4. In final round, if at least one triplet that has 
                corresponding value equals to target, then return true
         */
        vector<vector<int>> remaing_triplets = triplets;
         for (int i = 0; i < 3; i++) {
            if (!checkTriplet(target, remaing_triplets, i))
                return false;
         }
         return true;
    }
    bool checkTriplet(const vector<int>& target, vector<vector<int>>& triplets, int pos) {
        vector<vector<int>> re_triplets;
        bool has_value = false;
        for (int i = 0; i < triplets.size(); i++) {
            bool should_keep = true;
            for (int j = pos; j < 3; j++) {
                if (triplets[i][j] > target[j]) {
                    should_keep = false;
                    break;
                }
            }
            if (!should_keep) continue;

            re_triplets.push_back(triplets[i]);

            if (triplets[i][pos] == target[pos]) 
                has_value = true;
        }
        triplets = re_triplets;
        return has_value;
    }
};

/* 
    1 5 9
    3 1 7

            1 7 5
            1 8 4 
            2 5 3
            2 8 3    
            3 7 5

    target: 2 7 5
            (2, 5, 3) (3, 7, 5) -> (3, 7, 5)
   
            2 5 3  
            1 7 5
 */