#include<bits/stdc++.h>

using namespace std;
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>q;
        vector<int>ans;
        for (int r=0;r<nums.size();r++){
            while (!q.empty() && nums[r]>=nums[q.back()]){
                q.pop_back();
            }
            q.push_back(r);
            if (r-q.front()>=k){
                q.pop_front();
            }
            if (r>=k-1){
                ans.push_back(nums[q.front()]);
            }
        }
        return ans;
    }
};