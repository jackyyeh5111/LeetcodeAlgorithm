class PhoneDirectory {
public:
    /** Initialize your data structure here
        @param maxNumbers - The maximum numbers that can be stored in the phone directory. */
    int cur=-1, maxNum=-1;
    unordered_set<int> available;
    PhoneDirectory(int maxNumbers) {
        maxNum=maxNumbers;
    }

    /** Provide a number which is not assigned to anyone.
        @return - Return an available number. Return -1 if none is available. */
    int get() {
        if (available.empty()&&cur<maxNum-1) return ++cur;
        else if (!available.empty()) {
            auto ret=available.begin();
            int ans=*ret;
            available.erase(ret);
            return ans;
        }
        else return -1;
    }

    /** Check if a number is available or not. */
    bool check(int number) {
        if (number<=cur) return available.count(number)!=0;
        else return number<maxNum;
    }

    /** Recycle or release a number. */
    void release(int number) {
        if (number<=cur) available.insert(number);
    }
};

/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * PhoneDirectory* obj = new PhoneDirectory(maxNumbers);
 * int param_1 = obj->get();
 * bool param_2 = obj->check(number);
 * obj->release(number);
 */
