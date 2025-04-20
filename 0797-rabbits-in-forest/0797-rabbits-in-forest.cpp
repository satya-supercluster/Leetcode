class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> m;
        int ans = 0;
        for(int i=0;i<answers.size();i++){
            if(m.find(answers[i]) == m.end() || m[answers[i]] == 0){
                ans += answers[i] + 1;
                m[answers[i]] = answers[i];
            }
            else m[answers[i]]--;
        }
        return ans;
    }
};