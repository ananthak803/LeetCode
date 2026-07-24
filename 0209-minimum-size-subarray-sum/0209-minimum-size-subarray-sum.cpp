class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l=0,sum=0,len=INT_MAX;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            while(sum>=target){
                len=min(len,i-l+1);
                sum-=nums[l++];
            }
        }
        if(len==INT_MAX)len=0;
        return len;
    }
};