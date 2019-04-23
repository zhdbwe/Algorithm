/*
give a sort array rotated.like[4,5,6,7,0,1,2].find target in rotated array.
*/
#include <bits/stdc++.h>

using namespace std;

int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size()-1;
        while(low <= high)
        {
            int mid = low + ((high-low)>>1);//floor(low+high)
            if(nums[mid] == target) return mid;
            if(nums[low] <= nums[mid]){//left is sorted
                if(target >= nums[low] && target < nums[mid])
                    high = mid - 1;
                else
                    low = mid + 1;
            }
            else{//right is sorted
                if(target > nums[mid] && target <= nums[high])
                    low = mid + 1;
                else
                    high = mid -1;
            }
        }
        return -1;
    }
int main()
{

    vector<int> nums({4,5,6,7,0,1,2});
    cout<<search(nums,1)<<endl;
}
