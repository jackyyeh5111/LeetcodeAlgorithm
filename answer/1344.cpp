class Solution {
public:
    double angleClock(int hour, int minutes)
    {
        /*
            According to the examples, we only need to return angle in range[0,180]
        */
        double m_angle=(double)(minutes%60)*6.0;
        double h_angle=(double)(hour%12)*30.0 + 30.0*(double)(minutes%60)/60.0;
        double clockwise_difference=abs(m_angle-h_angle);
        return clockwise_difference>180 ? 360-clockwise_difference:clockwise_difference;
    }
};
