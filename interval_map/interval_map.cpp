#include <map>
#include <iostream>
#include <string>
#include <string_view>
template<typename K, typename V>
class interval_map {
    friend void IntervalMapTest();
    V m_valBegin;
    
public:
    std::map<K, V> m_map;
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
        // !(keyBegin < keyEnd) indicates an empty interval, so the function simply returns
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
};

void print_map(const interval_map<int, char>& m)
{
	bool comma = false;
	std::cout << '{';
	for (const auto& p : m.m_map)
	{
		if (comma) std::cout << ',';
		std::cout << '{' << p.first << ',' << p.second << '}';
		comma = true;
	}
	std::cout << "}\n";
}

//void print(const interval_map<int, char>& m, int lo, int hi)
//{
//	print_map(m);
//	m.m_valBegin(lo,"A");
//	for (const auto& [key, value] : m.m_map) {
//		std::cout << key << " = " << value << "; ";
//	}
//	std::cout << "\n";
//	for (int i = lo; i <= hi; ++i)
//		std::cout  << i << ' ' << m[i] << '\n';
//	std::cout << "\n\n";
//}

int main()
{
	interval_map<int, char> m('A');
	m.assign(1, 3, 'B');
	m.assign(4, 6, 'C');
	for (int i = -1; i <= 8; ++i)
		std::cout <<  i << ' ' << m[i] << '\n';
}