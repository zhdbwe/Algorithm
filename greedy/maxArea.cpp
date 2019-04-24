/*
Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). 
n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). 
Find two lines, which together with x-axis forms a container, such that the container contains the most water.

tips:
1.from first to last maybe good candidate, because it has longest width.
2.others dont have longest width, must have higher water.
3.how to remove? the smaller is more tended to be removed.
*/
#include<bits/stdc++.h>

using namespace std;

int maxArea(vector<int>& height) {
        int i = 0,j = height.size()-1;
        int max_area = 0;
        while(i<j){
            max_area = max(max_area, min(height[j],height[i]) * (j-i));
            if(height[i]<height[j]) i++;
            else j--;
        }
        return max_area;
    }
};

int main(){
  vector<int> height({1,2,3,4,5});
  cout<<maxArea(height)<<endl;
  return 0;
}
