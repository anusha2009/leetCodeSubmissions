class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
       vector<vector<string>> res;
		map<string,vector<string>> m;
		for(auto& x:strs){

			auto tem=x;
			sort(tem.begin(),tem.end());
			m[tem].push_back(x);
		}
		for(auto v:m){

			res.push_back(v.second);
		}
        
		return res; 
    }
};