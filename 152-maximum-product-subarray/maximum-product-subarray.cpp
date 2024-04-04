// Utility function to find minimum of two numbers
int min(int x, int y) {
	return (x < y) ? x : y;
}

// Utility function to find maximum of two numbers
int max(int x, int y) {
	return (x > y) ? x : y;
}


class Solution {
public:
    int maxProduct(vector<int>& arr) {
        // maintain two variables to store maximum and minimum product
	// ending at current index
	long max_ending = arr[0];
    
    long min_ending = arr[0];

	// to store maximum product sub-array found so far
	long max_so_far = arr[0];

	// traverse the given array
	for (int i = 1; i < arr.size(); i++)
	{
		long temp = max_ending;

		// update maximum product ending at current index
		max_ending = max(arr[i], max(arr[i] * max_ending, arr[i] * min_ending));

		// update minimum product ending at current index
		min_ending = min(arr[i], min(arr[i] * temp, arr[i] * min_ending));

		max_so_far = max(max_so_far, max_ending);
	}

	// return maximum product
	return (int)max_so_far;

    }
};