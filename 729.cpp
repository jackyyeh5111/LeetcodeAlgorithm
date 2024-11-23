class MyCalendar {
    map<int,int>mp;
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        auto next=mp.upper_bound(start);
        if(next!=mp.end() && (*next).second<end)return false;
        mp.insert({end,start});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */

 /* 
    這題用 lower_bound 會出錯！！

    falure case:
        [33,41],
        [47,50],

        [33,42], <- 
  */
class MyCalendar {
public:
    map<int, int> calendar;
    MyCalendar() {
        
    }
    
    bool book(int startTime, int endTime) {
        // check right portion
        auto it = calendar.lower_bound(startTime);
        if (it != calendar.end()) {            
            if (endTime >= it->first && endTime < it->second)
                return false;
        }
        // check left portion
        if (it != calendar.begin()) {
            auto prev_it = prev(it);
            if (startTime >= prev_it->first && startTime < prev_it->second)
                return false;
        }
        calendar[startTime] = endTime;
        return true;
    }
};
