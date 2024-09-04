/*
https://www.naukri.com/code360/problems/implement-upper-bound_8165383
*/

int upperBound(vector<int> &arr, int x, int n){
	int low = 0;
	int high = n-1;
	int ans = n;

	while (low<=high){
		int mid = low + (high - low)/2;

		if (arr[mid]>x){
			ans = mid;
			high = mid -1;
		}
		else{
			low = mid + 1;
		}
	}
	return ans;
}