#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>d;
        for (int i=0;i<nums.size();i++){
            auto it=d.find(target-nums[i]);
            if (it!=d.end()){
                return {it->second,i};
            }
            d[nums[i]]=i;
        }
    }
};