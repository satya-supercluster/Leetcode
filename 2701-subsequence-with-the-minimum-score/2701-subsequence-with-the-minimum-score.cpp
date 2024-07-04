class Solution {
public:
	int minimumScore(string s, string t) {
		int n = s.size();
		int m = t.size();
		deque<int> rmatch;
		int si = n - 1;
		int ti = m - 1;
		while(si >= 0 && ti >= 0){
			while(si >= 0 && ti >= 0 && s[si] == t[ti]){
				rmatch.push_front(si);
				si--;
				ti--;
			}
			si--;
		}
		deque<int> lmatch;
		si = 0;
		ti = 0;
		while(si < n && ti < m){
			while(si < n && ti < m && s[si] == t[ti]){
				lmatch.push_back(si);
				si++;
				ti++;
			}
			si++;
		}
		if(lmatch.size() == m) return 0;
		int ans = min(m, m - (int)rmatch.size());
		for(int i = 0; i < lmatch.size(); i++){
			int left = i + 1;
			while(!rmatch.empty() && rmatch.front() <= lmatch[i]){
				rmatch.pop_front();
			} 
			int right = m - 1 - rmatch.size();
			ans = min(ans, right - left + 1);
		}
		return ans;
	}
};