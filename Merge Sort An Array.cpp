class Solution {
public:
    void sorting(vector<int>&nums,int low,int mid,int high) {
        vector<int> temp;
        int left = low;
        int right = mid+1;
        while(left<=mid && right<=high) {
            if(nums[left]<=nums[right]) {
                temp.push_back(nums[left]);
                left++;
            }
            else {
                temp.push_back(nums[right]);
                right++;
            }
        }
        while(left<=mid) {
            temp.push_back(nums[left]);
            left++;
        }
        while(right<=high) {
            temp.push_back(nums[right]);
            right++;
        }
        for(int i=low;i<=high;i++) {
            nums[i]=temp[i-low];
        }
    }
    void mergeSort(vector<int>& nums,int low,int high){
        if(low==high) return;
        int mid=(low+high)/2;
        mergeSort(nums,low,mid);
        mergeSort(nums,mid+1,high);
        sorting(nums,low,mid,high);
    }
    vector<int> sortArray(vector<int>& nums) {
        int size = nums.size();
        mergeSort(nums,0,size-1);
        return nums;
    }
};
