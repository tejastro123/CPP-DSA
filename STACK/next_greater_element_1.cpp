/*You are given two distinct 0-indexed integer arrays nums1 and nums2, where nums1 is a subset of nums2.
For each 0 <= i < nums1.length, find the index j such that nums1[i] == nums2[j] and determine the next greater 
element of nums2[j] in nums2. If there is no next greater element, then the answer for this query is -1.
Return an array ans of length nums1.length such that ans[i] is the next greater element as described above.*/
#include<iostream>
#include<vector>
#include<stack>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> s;
        unordered_map<int,int> map;
        for(int i = nums2.size()-1; i >= 0; i--){
            while(!s.empty() && nums2[i] > s.top()){
                s.pop();
            }
            if(s.empty()){
                map[nums2[i]] = -1;
            }
            else{
                map[nums2[i]] = s.top();
            }
            s.push(nums2[i]);
        }
        vector<int> ans;
        for(int i = 0; i < nums1.size(); i++){
            ans.push_back(map[nums1[i]]);
        }
        return ans;
    }
}; //Time complexity: O(m+n) and space complexity: O(m)

int main(){
    Solution s;
    vector<int> nums1 = {4,1,2};
    vector<int> nums2 = {1,3,4,2};
    vector<int> ans = s.nextGreaterElement(nums1, nums2);
    for(int i = 0; i < ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    return 0;
} 