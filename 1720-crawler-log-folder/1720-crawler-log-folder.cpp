class Solution {
public:
    int minOperations(vector<string>& logs) {
        int count{};
        for(auto s:logs){
            if(s=="../"){
                if(count!=0)count--;
            }
            else if(s=="./")continue;
            else count++;
            // cout<<count<<" ";
        }
        return count;
    }
};