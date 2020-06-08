class Solution {
public:
    vector<int> prefix;
    Solution(vector<int>& w) {
        prefix.push_back(w[0]);
        for(int i=1;i<w.size();i++){
            prefix.push_back(prefix[i-1]+w[i]);
        }
    }

    int pickIndex() {
        int n=rand()%prefix.back(); ++n;
        auto lower=lower_bound(prefix.begin(),prefix.end(),n)-prefix.begin();
        return lower;
    }
};

/*
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
