/***** Third Visit *****/
class PeekingIterator : public Iterator {
public:
    int P;
    bool HasNext;
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    P=Iterator::next();
        HasNext=true;
	}

	int peek() {
        return P;
	}

	int next() {
	    int ret=P;
        if (Iterator::hasNext()) P=Iterator::next();
        else HasNext=false;
        return ret;
	}

	bool hasNext() const {
	    return HasNext;
	}
};

/***** Second Visit *****/
class PeekingIterator : public Iterator {
public:
    int val;
    int *cache=0;
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	}

    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        if (!cache) {
            val=Iterator::next();
            cache=&val;
        }
        return *cache;
	}

	int next() {
        if (cache) {
            int ret=*cache;
            cache=0;
            return ret;
        }
        else return Iterator::next();
	}

	bool hasNext() const {
	    if (!Iterator::hasNext()&&!cache) return false;
        else return true;
	}
};

/***** First Visit *****/
/*
    1 2 3
        ^ ^
	2 flags to check true empty.
	T:O(1)/S:O(1)
	--------------
	JUST UTILIZE COPY CONSTRUCTOR HERE
	T:O(1)/S:O(1)
*/
// copy constructor
class PeekingIterator : public Iterator {
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	}

    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        return Iterator(*this).next();
	}
};

// 2 flag method
class PeekingIterator : public Iterator {
public:
    int num; bool p1=false, p2=false;
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
	    num=Iterator::next();
	}

    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        return num;
	}

	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
        int tmp=num;
	    if (Iterator::hasNext())
            num=Iterator::next();
        if (!Iterator::hasNext()&&!p1) p1=true;
        else if (!Iterator::hasNext()&&!p2) p2=true;
        return tmp;
	}

	bool hasNext() const {
	    return !(p1&&p2);
	}
};
