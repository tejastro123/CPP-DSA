#include <bits/stdc++.h>
using namespace std;

// brute fore method = O(n^2)

// int trap(vector<int>& height) {
//     int n = height.size();
//     int water = 0;
//     for(int i=0; i<n; i++){
//         int leftMax = 0;
//         int rightMax = 0;
//         for(int j=0; j<i; j++){
//             leftMax = max(leftMax, height[j]);
//         }
//         for(int j=i+1; j<n; j++){
//             rightMax = max(rightMax, height[j]);
//         }
//         water += min(leftMax, rightMax) - height[i];
//     }
//     return water;
// }

// optimal method = O(n)

// int trap(vector<int>& height) {
//     int n = height.size();
//     vector<int> lmax(n,0);
//     vector<int> rmax(n,0);

//     lmax[0] = height[0];
//     rmax[n-1] = height[n-1];

//     for(int i=1; i<n; i++){
//         lmax[i] = max(lmax[i-1],height[i]);
//     }

//     for(int i=n-2; i>=0; i--){
//         rmax[i] = max(rmax[i+1],height[i]);
//     }

//     int ans = 0;
//     for(int i=0; i<n; i++){
//         ans += min(lmax[i], rmax[i]) - height[i];
//     }

//     return ans;
// }

// most optimal method with two pointer = O(n)
// space complexity = O(1)

int trap(vector<int>& height) {
    int n = height.size();
    int left = 0;
    int right = n-1;
    int leftMax = 0;
    int rightMax = 0;
    int water = 0;
    while(left <= right){
        if(height[left] <= height[right]){
            if(height[left] >= leftMax){
                leftMax = height[left];
            }
            else{
                water += leftMax - height[left];
            }
            left++;
        }
        else{
            if(height[right] >= rightMax){
                rightMax = height[right];
            }
            else{
                water += rightMax - height[right];
            }
            right--;
        }
    }
    return water;
}
int main() {
    vector<int> height = {4,2,0,3,2,5};
    int ans = trap(height);
    cout << ans << endl;
    return 0;
}

