class Solution {
public:
    bool isSubsequence(string s, string t) {
        int s_length=s.length();
        int t_length=t.length();
        int i=0,j=0;
        for(;i<s_length,j<t_length;++j){
            if(s[i]==t[j])
                ++i;
        }
        return (i==s_length);
    }
};
