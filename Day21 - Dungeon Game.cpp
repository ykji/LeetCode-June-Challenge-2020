class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int rows=dungeon.size();
        int columns=dungeon[0].size();
        int t[rows+1][columns+1];
        for(int i=0;i<=columns;++i)
            t[rows][i]=INT_MAX;
        for(int i=0;i<=rows;++i)
            t[i][columns]=INT_MAX;
        t[rows-1][columns] = 1;
        t[rows][columns-1] = 1;
        for(int i=rows-1;i>=0;--i){
            for(int j=columns-1;j>=0;--j){
                int mini=min(t[i+1][j],t[i][j+1]);
                t[i][j]=max(mini-dungeon[i][j],1);
            }
        }
        return t[0][0];
    }
};
