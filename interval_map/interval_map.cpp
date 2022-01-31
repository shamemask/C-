#include <map>
#include <iostream>
template<typename K, typename V>
class interval_map {
    friend void IntervalMapTest();
    V m_valBegin;
	std::map<K, V> m_map;
public:
    // constructor associates whole range of K with val
    interval_map(V const& val)
        : m_valBegin(val)
    {}

    // Assign value val to interval [keyBegin, keyEnd).
    // Overwrite previous values in this interval.
    // Conforming to the C++ Standard Library conventions, the interval
    // includes keyBegin, but excludes keyEnd.
    // If !( keyBegin < keyEnd ), this designates an empty interval,
    // and assign must do nothing.

    void assign(K const& keyBegin, K const& keyEnd, V const& val) {
        if (!(keyBegin < keyEnd)) return;

		std::pair<K, V> begin;
		std::pair<K, V> end;
		bool beginHas = false;
		bool endHas = false;

		typename std::map<K, V>::const_iterator itBegin;
		itBegin = m_map.lower_bound(keyBegin);
		if (itBegin != m_map.end() && keyBegin < itBegin->first) {
			if (itBegin != m_map.begin()) {
				beginHas = true;
				--itBegin;
				begin = std::make_pair(itBegin->first, itBegin->second);
			}
			// openRange for erase is prevIterator
			// insert (prevIterator->first, prevIterator->second) as well!
		}

		typename std::map<K, V>::const_iterator itEnd;
		itEnd = m_map.lower_bound(keyEnd);
		if (itEnd != m_map.end() && keyEnd < itEnd->first) {
			endHas = true;
			typename std::map<K, V>::const_iterator extraIt = itEnd;
			--extraIt;
			end = std::make_pair(keyEnd, extraIt->second);
			// closeRange for erase is this iterator
			// insert (keyEnd, prevIterator->second) as well!
		}

		// 4 canonical conflicts:
		//	 begin w/ mid
		//	 before-mid w/ mid (beginHas==false)
		//	 mid w/ end
		//	 mid w/ after-mid (endHas==false)

		bool insertMid = true;
		if (beginHas) {
			if (begin.second == val)
				insertMid = false;
		}
		else {
			if (itBegin != m_map.begin()) {
				typename std::map<K, V>::const_iterator beforeMid = itBegin;
				--beforeMid;
				if (beforeMid->second == val)
					insertMid = false;
			}
		}


		if (endHas) {
			if ((insertMid && end.second == val) || (!insertMid && end.second == begin.second))
				endHas = false;
		}
		else {
			if ((insertMid && itEnd != m_map.end() && itEnd->second == val) || (!insertMid && itEnd != m_map.end() && itEnd->second == begin.second))
				itEnd = m_map.erase(itEnd);
		}

		itBegin = m_map.erase(itBegin, itEnd);
		if (beginHas)
			itBegin = m_map.insert(itBegin, begin);
		if (insertMid)
			itBegin = m_map.insert(itBegin, std::make_pair(keyBegin, val));
			itBegin = m_map.insert(itBegin, std::make_pair(keyEnd+1, m_valBegin));
		if (endHas)
			m_map.insert(itBegin, end);

		
	}

	// look-up of the value associated with key
	/*V const& operator[](K const& key) const {
		return (--m_map.upper_bound(key))->second;
	}*/
	V const& operator[](K const& key) const {
		auto it = m_map.upper_bound(key);
		if (it == m_map.begin()) {
			return m_valBegin;
		}
		else {
			return (--it)->second;
		}
	}
	void print() {
		std::cout << "###########" << std::endl;
		for (auto i : m_map)
			std::cout << i.first << ", " << i.second << std::endl;
	}
};

void IntervalMapTest() {
	interval_map<int, char> M{ 'A' };
	M.assign(1, 4, 'B');
	M.print();
	M.assign(4, 7, 'C');
	M.print();
	M.assign(7, 10, 'D');
	M.print();
	M.assign(10, 15, 'E');
	M.print();
	M.assign(3, 7, 'E');
	M.print();
	M.assign(-10, -5, 'F');
	M.print();
	M.assign(-15, -10, 'G');
	M.print();
	M.assign(11, 200, 'H');
	M.print();
	M.assign(-26, 3, 'K');
	M.print();
	M.assign(-25, 200, 'L');
	M.print();
	M.assign(-25, 20, 'S');
	M.print();
}

int main() {
	IntervalMapTest();
	return 0;
}
