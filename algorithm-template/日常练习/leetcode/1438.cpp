#include<bits/stdc++.h>

using namespace std;
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        multiset<int>s;
        int l=0,ans=0;
        for (int r=0;r<nums.size();r++){
            s.insert(nums[r]);
            while (*s.rbegin()-*s.begin()>limit){
                s.erase(nums[l]);
                l++;
            }
            ans=max(ans,r-l+1);
        }
        return ans;
    }
};