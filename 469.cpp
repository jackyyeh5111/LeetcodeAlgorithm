struct Vec {
    int x, y;
    int crossProd(const Vec& vec) const {
        return x * vec.y - y * vec.x;
    }
};
class Solution {
public:
    bool isConvex(vector<vector<int>>& points) {
        int size = points.size();
        bool sign = false;
        bool sign_assigned = false;
        Vec vec1, vec2;
        for (int idx = 0; idx < size; idx++) {
            int idx1 = (idx + 1) % size;
            int idx2 = (idx + 2) % size;
            if (idx == 0)
                vec1 = {points[idx1][0] - points[idx][0], points[idx1][1] - points[idx][1]};
            else
                vec1 = std::move(vec2);
            vec2 = {points[idx2][0] - points[idx1][0], points[idx2][1] - points[idx1][1]};

            int cp_val = vec1.crossProd(vec2);
            if (cp_val == 0) continue; // three points collinear
            if (!sign_assigned) {
                sign_assigned = true;
                sign = cp_val > 0; 
            }
            else if (sign != cp_val > 0) return false;
        }
        return true;
    }
};