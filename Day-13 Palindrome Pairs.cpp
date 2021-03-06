class Solution {
public:
    
    bool isPal(string &s) {
	for(int i = 0, j = s.size() - 1; i < j; i++, j--) 
		if(s[i] != s[j]) 
			return false;
	return true;
    }
    
    vector<vector<int>> palindromePairs(vector<string>& words) {
        	unordered_map<string, int> mp;
	for(int i = 0; i < words.size(); i++) 
		mp[string(rbegin(words[i]), rend(words[i]))] = i;

	vector<vector<int>> res;
	if(mp.count("")) 
		for(int i = 0; i < words.size(); i++) 
			if(words[i] != "" && isPal(words[i]))
				res.push_back({mp[""], i});

	for(int i = 0; i < words.size(); i++)
		for(int j = 0; j < words[i].size(); j++) {
			string l = words[i].substr(0, j), r = words[i].substr(j);
			if(mp.count(l) && isPal(r) && mp[l] != i) res.push_back({i, mp[l]});
			if(mp.count(r) && isPal(l) && mp[r] != i) res.push_back({mp[r], i});
		}
	return res;
    }
};
