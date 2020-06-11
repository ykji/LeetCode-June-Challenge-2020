class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size()-1;
        // form 0 to low-1, 0s
        // from low to mid-1, 1s
        // from mid to high-1, unknowns
        // form high to last index, 2s
        int low=0,mid=0,high=n;
        for( ;mid<=high; ){
            if(nums[mid]==1)
                ++mid;
            else if(nums[mid]==0){
                swap(nums[mid],nums[low]);
                ++mid;
                ++low;
            }
            else{
                swap(nums[mid],nums[high]);
                --high;
            }
        }
    }
};
