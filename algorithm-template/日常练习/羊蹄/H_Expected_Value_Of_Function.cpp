//  H. Expected Value Of Function

#include<bits/stdc++.h>

#pragma GCC optimize("O3,Ofast,unroll-loops")

using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t, mod = 1e9 + 7;
    cin >> t;

    while (t --) {
        int n;
        cin >> n;

        int total = 0;
        for (int i = 0; i < n; i ++) {
            int x;
            cin >> x;
            total += x;
            if (total >= mod) total -= mod;
        }

        int times = 0;
        for (int i = 0; i < n; i ++) {
            times += n / gcd(i, n);
            if (times >= mod) times -= mod;
        }

        int revn = quickPow(n, mod - 2, mod);
        cout << 1ll * total * times % mod * revn % mod * revn % mod << '\n';
    }

    return 0;
}