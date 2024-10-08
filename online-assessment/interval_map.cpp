#include <map>
template<typename K, typename V>
class interval_map {
	friend void IntervalMapTest();
	V m_valBegin;
	std::map<K,V> m_map;
public:
	// constructor associates whole range of K with val
	template<typename V_forward>
	interval_map(V_forward&& val)
	: m_valBegin(std::forward<V_forward>(val))
	{}

	// Assign value val to interval [keyBegin, keyEnd).
	// Overwrite previous values in this interval.
	// Conforming to the C++ Standard Library conventions, the interval
	// includes keyBegin, but excludes keyEnd.
	// If !( keyBegin < keyEnd ), this designates an empty interval,
	// and assign must do nothing.
	template<typename V_forward>
    void assign(K const& keyBegin, K const& keyEnd, V_forward&& val) 
        requires (std::is_same<std::remove_cvref_t<V_forward>, V>::value) 
    {
        // If keyBegin is not less than keyEnd, the interval is empty, do nothing
        if (!(keyBegin < keyEnd)) {
            return;
        }
    
        // Find the position where keyBegin would be inserted
        auto itBegin = m_map.lower_bound(keyBegin);
        auto itEnd = m_map.lower_bound(keyEnd);
    
        itBegin = m_map.insert_or_assign(itBegin, keyBegin, std::forward<V_forward>(val));
        // Remove any intermediate keys between keyBegin and keyEnd
        m_map.erase(std::next(itBegin), itEnd);

        if (std::prev(itBegin) == m_map.begin())
            m_map.insert(m_map.begin(), m_valBegin);
        

        // // Get the value at keyEnd (or m_valBegin if keyEnd is less than the first key)
        // V valAtEnd = (itEnd != m_map.begin()) ? std::prev(itEnd)->second : m_valBegin;
    
        // // If the value at keyEnd is not the same as val, we need to insert keyEnd with valAtEnd
        // if (val != valAtEnd) {
        //     m_map.insert_or_assign(itEnd, keyEnd, std::move(valAtEnd));
        // }
    
    }

	// look-up of the value associated with key
	V const& operator[]( K const& key ) const {
		auto it=m_map.upper_bound(key);
		if(it==m_map.begin()) {
			return m_valBegin;
		} else {
			return (--it)->second;
		}
	}
};

#include <iostream>
#include <cassert>
#include <map>

// Define a simple test function for the interval_map class
void IntervalMapTest() {
    // Test Case 1: Basic assignment within an empty map
    interval_map<int, char> imap('A'); // Default all values to 'A'
    imap.assign(1, 5, 'B'); // Assign 'B' to the range [1, 5)
    
    // Check the expected values
    assert(imap[0] == 'A');  // Values before 1 should remain 'A'
    assert(imap[1] == 'B');  // [1, 5) should be 'B'
    assert(imap[2] == 'B');
    assert(imap[4] == 'B');
    std::cout << imap[5] << '\n';
    assert(imap[5] == 'A');  // After 5, it should be 'A'

    // Test Case 2: Overlap and partial overwrite
    imap.assign(3, 7, 'C'); // Assign 'C' to the range [3, 7)
    
    // Check the expected values
    assert(imap[2] == 'B');  // Still 'B' before 3
    assert(imap[3] == 'C');  // [3, 7) should be 'C'
    assert(imap[6] == 'C');
    assert(imap[7] == 'A');  // After 7, it should be 'A'

    // Test Case 3: Assigning a range that resets part of the interval
    imap.assign(5, 6, 'A');  // Reset [5, 6) back to 'A'
    
    // Check the expected values
    assert(imap[4] == 'B');  // Check if [1, 5) is still 'B'
    assert(imap[5] == 'A');  // [5, 6) reset back to 'A'
    assert(imap[6] == 'C');  // [6, 7) is still 'C'

    // Test Case 4: Assign an empty interval (keyBegin >= keyEnd)
    imap.assign(5, 5, 'D');  // Empty interval, should do nothing
    assert(imap[5] == 'A');  // Values should remain unchanged

    // // Test Case 5: Overwriting the whole map with a single value
    // imap.assign(-100, 100, 'Z'); // All values should now be 'Z'
    
    // // Check the expected values
    // assert(imap[-50] == 'Z');
    // assert(imap[0] == 'Z');
    // assert(imap[50] == 'Z');
    
    // // Test Case 6: Assign a small interval inside the larger one
    // imap.assign(10, 20, 'Y'); // [10, 20) should be 'Y'
    
    // // Check the expected values
    // assert(imap[9] == 'Z');
    // assert(imap[10] == 'Y');
    // assert(imap[19] == 'Y');
    // assert(imap[20] == 'Z');
    
    // // Test Case 7: Assign a single value to an already set range
    // imap.assign(10, 20, 'Y'); // Same value, should not change the map structure

    // // Check the expected values
    // assert(imap[10] == 'Y');
    // assert(imap[19] == 'Y');
    // assert(imap[20] == 'Z');

    std::cout << "All test cases passed!" << std::endl;
}

int main() {
    IntervalMapTest();
    return 0;
}

// Many solutions we receive are incorrect. Consider using a randomized test
// to discover the cases that your implementation does not handle correctly.
// We recommend to implement a test function that tests the functionality of
// the interval_map, for example using a map of int intervals to char.