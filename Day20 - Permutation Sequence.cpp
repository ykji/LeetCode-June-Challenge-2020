class Solution {
public:
    string getPermutation(int n, int k) {
        string ans="";
        vector <int> v;
        for(int i=0;i<n;++i)
            v.push_back(i+1);
        int fact[n+1];
        fact[0]=1;
        for(int i=1;i<=n;++i)
            fact[i]=fact[i-1]*i;
        while(k!=1 ){
            int idx=k/fact[n-1];
            if((k%fact[n-1])==0)
                --idx;
            ans+=(to_string(v[idx]));
            k-=(idx*fact[n-1]);
            v.erase(v.begin()+idx);
            --n;
        }
        for(auto i:v)
            ans+=(to_string(i));
        return ans;
    }
};
