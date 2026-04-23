//  C. Cool Partition

#include<bits/stdc++.h>

using namespace std;
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin>>a[i];
    set<int>s,t;
    int ans=0;
    for (int i=0;i<n;i++){
        int x=a[i];
        s.insert(x);
        t.insert(x);
        if (s.size()==t.size()){
            ans++;
            t.clear();
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
