#include<bits/stdc++.h>

using namespace std;
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

const int N=5e4;
vector<bool>p(N+1,true);
auto init=[]{
    p[0]=p[1]=false;
    for (int i=2;i<=sqrt(N);i++){
        if (p[i]){
            for (int j=i*i;j<=N;j+=i){
                p[j]=false;
            }
        }
    }
    return 0;
}();

class Solution {
public:
    int primeSubarray(vector<int>& nums, int k) {
        deque<int>q;
        multiset<int>s;
        int ans=0,l=0;
        for (int r=0;r<nums.size();r++){
            if (p[nums[r]]){
                q.push_back(r);
                s.insert(nums[r]);
                while (*s.rbegin()-*s.begin()>k){
                    int i=q.front();
                    q.pop_front();
                    s.erase(s.find(nums[i]));
                    l=i+1;
                }
            }
            if (q.size()>=2){
                ans+=q[q.size()-2]-l+1;
            }
        }
        return ans;
    }
};