#include <bits/stdc++.h>
using namespace std;
#define INF LLONG_MAX - INT32_MAX
#define int long long
using vi = vector<int>;
using matrix = vector<vector<int>>;

signed main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, x;
    cin >> n >> x;
    set<int> coins;
    vi ways(x+1, 0);
    for (int i = 0 ; i < n; i++) {
        int a;
        cin >> a;
        if (a <= x) {
            coins.emplace(a);
        }
    }
    for (auto coin : coins) {
        ways[coin]++;
        for (int i = coin+1; i <= x; i++) {
            ways[i] += ways[i-coin];
            ways[i] = ways[i]%((int)1e9 + 7);
        }
    }
    cout << ways[x] << "\n";
    return 0;
}
