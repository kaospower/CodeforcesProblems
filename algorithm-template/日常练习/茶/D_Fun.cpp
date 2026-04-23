//  D. Fun

#include<bits/stdc++.h>

#pragma GCC optimize("O3,Ofast,unroll-loops")

using namespace std;
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

void solve() {
    int n,x,ans=0;
    cin >> n>>x;
    for (int a=1;a<min(x-1,n);a++){
        for (int b = 1; b <min(n/a,x-a) ; b++) {
            ans+=min((n-a*b)/(a+b),x-a-b);
        }
    }
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}
