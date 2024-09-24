class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int l=0,r=0,maxlen=0,zeros=0;
        while(r<n)
        {
            if(nums[r]==0)
                zeros++;
            if(zeros>k)      //place if in place of while to decrease TC from O(2n) to O(n).
            {
                if(nums[l]==0)
                  zeros--;
                l++;
            }
            if(zeros<=k)
            {
                int len=r-l+1;
                maxlen=max(len,maxlen);
            }
            r++;
        }
        return maxlen;

        // while(r<n)
        // {
        //     if(nums[r]==0)
        //         zeros++;
        //     while(zeros>k)
        //     {
        //         if(nums[l]==0)
        //             zeros--;
        //         l++;
        //     }
        //     if(zeros<=k)
        //     {
        //         int len=r-l+1;
        //         maxlen=max(maxlen,len);
        //     }
        //     r++;
        // }
        // return maxlen;
    }
};