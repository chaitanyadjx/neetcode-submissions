class Solution {
   public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        span<int> v1; //small
        span<int> v2; //big
        if(m > n){
            v2 = nums1;
            v1 = nums2;
        } else{
            v1 = nums1;
            v2 = nums2;
        }

        int x = v1.size();
        int y = v2.size();
        int low = 0;
        int high = x;
        int d = (x + y + 1) / 2;
        while(low <= high){
            int k = low + (high - low) / 2;

            int l1 = k;
            int leftPart = d - l1;

            int left1 = (l1 != 0) ? v1[l1 - 1] : INT_MIN;
            int right1 = (l1 != x) ? v1[l1] : INT_MAX;       

            int left2 = (leftPart != 0) ? v2[leftPart - 1] : INT_MIN;
            int right2 = (leftPart != y) ? v2[leftPart] : INT_MAX;  

            if(left1 <= right2 && left2 <= right1){
                if( (x + y) % 2 != 0) return max(left1, left2);
                else {
                    return (max(left1, left2) + min(right1, right2) ) / 2.0;
                }
            } 
            if(left1 > right2){
                high = k - 1;
            } else {
                low = k + 1;
            }
        }
        return 0.0;
    }
};
