class Solution {
    void solve(string src,unordered_map<string,multiset<string>> &edges,vector<string> &ans){
        while(edges[src].size()){
            string nbr=*(edges[src].begin());
            edges[src].erase(edges[src].begin());
            solve(nbr,edges,ans);
        }
        ans.push_back(src);
    }
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string,multiset<string>> edges;
        for(auto i:tickets){
            edges[i[0]].insert(i[1]);
        }
        vector<string> ans;
        solve("JFK",edges,ans);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
