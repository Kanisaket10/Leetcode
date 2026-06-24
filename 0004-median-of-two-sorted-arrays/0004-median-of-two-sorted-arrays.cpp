class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double ans;
        int m = nums1.size(); 
        int n = nums2.size();

        vector<int> temp(m + n);

        for(int i=0; i<m; i++) temp[i] = nums1[i];
        for(int i=m; i<m+n; i++) temp[i] = nums2[i-m];

        sort(temp.begin(), temp.end());
        int ind = temp.size();

        if(ind % 2 == 1){
            ans = temp[ind/2];
        }
        else{
            ans = (temp[ind/2] + temp[ind/2 -1])/2.00000; 
        }
        return ans;
    }
};