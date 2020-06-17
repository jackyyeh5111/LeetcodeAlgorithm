class Solution {
public:
    string validIPAddress(string IP)
    {
        if (checkIPv4(IP)) return "IPv4";
        else if (checkIPv6(IP)) return "IPv6";
        else return "Neither";
    }

    bool checkIPv4(string IP)
    {
        // separate by '.', and get each string
        // check the range of each entry, which is 0<ip<255 or not.
        vector<string> nums;
        string num="";
        for (int idx=0; idx<IP.length(); ++idx){
            if (IP[idx]=='.') {nums.push_back(num); num="";}
            else num+=IP[idx];
        }
        nums.push_back(num);
        if (nums.size()!=4) return false;
        for (string num:nums) {
            if (num.size()>3||num.size()==0) return false;
            int x=0;
            for (int i=0; i<num.size(); i++){
                if (num[i]>'9'||num[i]<'0') return false;
                x=x*10+num[i]-'0';
            }
            // std::cout<<x<<std::endl;
            if (x<0||x>255||(num[0]=='0'&&num.size()!=1)) return false;
        }
        return true;
    }

    bool checkIPv6(string IP)
    {
        vector<string> nums;
        string num="";
        for (int idx=0; idx<IP.length(); ++idx){
            if (IP[idx]==':') {nums.push_back(num); num="";}
            else num+=IP[idx];
        }
        nums.push_back(num);

        if (nums.size()!=8) return false;
        for (string num:nums) {
            // std::cout<<num<<std::endl;
            if (num.size()>4||num.size()==0) return false;
            for (char c:num) {
                if (!(c<='9'&&c>='0')&&!(c<='f'&&c>='a')&&!(c<='F'&&c>='A')) return false;
            }
        }
        return true;
    }
};
