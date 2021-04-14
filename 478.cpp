/*
    Read the question description carefully, we are asked to generate uniform points in circle, we need to define what's uniform.

    refer: https://leetcode.com/problems/generate-random-point-in-a-circle/discuss/155650/Explanation-with-Graphs-why-using-Math.sqrt()
*/
class Solution {
public:
    double r=0,x=0,y=0;
    Solution(double radius, double x_center, double y_center) {
        this->r=radius;
        this->x=x_center;
        this->y=y_center;
    }

    vector<double> randPoint() {
        double len=sqrt((double)rand()/RAND_MAX)*r;
        double angle=((double)rand()/RAND_MAX*2-1)*M_PI;
        return {x+len*cos(angle),y+len*sin(angle)};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */
