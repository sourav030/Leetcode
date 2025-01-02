class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> combine;
        int n1 = nums1.size();
        int n2 = nums2.size();
        int i = 0, j = 0;

        // Merge nums1 and nums2 into a sorted array
        while (i < n1 && j < n2) {
            if (nums1[i] < nums2[j]) {
                combine.push_back(nums1[i]);
                i++;
            } else {
                combine.push_back(nums2[j]);
                j++;
            }
        }

        // Add remaining elements from nums1
        while (i < n1) {
            combine.push_back(nums1[i]);
            i++;
        }

        // Add remaining elements from nums2
        while (j < n2) {
            combine.push_back(nums2[j]);
            j++;
        }

        int n3 = combine.size();

        // Calculate the median
        if (n3 % 2 == 1) {
            return (double)combine[n3 / 2];
        } else {
            int sum = combine[n3 / 2] + combine[n3 / 2 - 1];
            return (double)sum / 2.0;
        }
    }
};
