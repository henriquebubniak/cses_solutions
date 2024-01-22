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
    vi amount(x+1,-1);
    for (int i = 0; i < n; i++) {
        int c;
        cin >> c;
        coins.emplace_back(c);
        if (c <= x) {
            amount[c] = 1;
        }
    }
    for (int i = 0; i <= x; i++) {
        if (amount[i] != -1) {
            continue;
        }
        int min = INF;
        for (auto j : coins) {
            if (i - j >= 0 && amount[i-j] != -1) {
                if (amount[i-j] + 1 < min) {
                    min = amount[i-j] + 1;
                }
            }
        }
        amount[i] = (min == INF ? -1 : min);
    }
        cout << amount[x] << "\n";
    return 0;
}
