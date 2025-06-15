class Solution {
  public:
   int smallestDivisor(vector<int>& arr, int k) {
       int low = 1, high = *max_element(arr.begin(), arr.end());
	int res = -1;

	while (low <= high) {
		int mid = low + (high - low) / 2;
		int sum = 0;

	
		for (int ele : arr) {

			// Round off the quotient to the nearest greater integer
			sum += (ele + mid - 1) / mid;
		}

		if (sum <= k) {
			res = mid;
			high = mid - 1;
		}
		else
			low = mid + 1;
	}
	return res; 
       
    }
};
