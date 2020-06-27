class Solution {
public:
    bool isPS(int num) {
        int sqroot = sqrt(num);
        return (num==(sqroot*sqroot));
    }
    int numSquares(int num) {
        while(num%4==0) num = num/4;
        if(num%8 == 7) return 4;
        if(isPS(num)) return 1;
        for(int i=1;i*i<=num;i++) if(isPS(num-i*i)) return 2;
        return 3;
    }
};
