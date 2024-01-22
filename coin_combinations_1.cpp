#include <bits/stdc++.h>
using namespace std;
#define INF LONG_MAX - INT32_MAX
#define int long
using vi = vector<int>;

signed main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, x;
    cin >> n >> x;
    vi coins;
    vi ways(x+1,0);
    for (int i = 0; i < n; i++) {
        int c;
        cin >> c;
        coins.emplace_back(c);
        if (c <= x) {
            ways[c] = 1;
        }
    }
    for (int i = 0; i <= x; i++) {
        int sum = 0;
        for (auto j : coins) {
            if (i - j >= 0) {
                sum += ways[i-j];
            }
        }
        ways[i] += sum % ((int)1e9 + 7);
    }
        cout << ways[x] << "\n";
    return 0;
}
