class MyCalendar {
public:

	map<int, int> map;
	MyCalendar() {

	}
    
	bool book(int start, int end) {
		for(auto itr : map){
			if(start < itr.second && end > itr.first)
				return false;
		}
		map.insert({start, end});
		return true;

	}
};
