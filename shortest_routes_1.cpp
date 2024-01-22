#include <bits/stdc++.h>
using namespace std;
#define INF LLONG_MAX - INT32_MAX
#define int long long
using wv = pair<int, int>;
using graph = vector<vector<wv>>;
using vi = vector<int>;


vi djikstra(int s, graph adj) {
    vi d(adj.size(), INF);
    priority_queue<wv, vector<wv>, greater<wv>> heap;
    heap.emplace(wv(0,s));
    while(!heap.empty()) {
        int u = heap.top().second;
        int du = heap.top().first;
        heap.pop();
        if (du > d[u]) {
            continue;
        }
        d[u] = du;
        for (int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i].second;
            int w = adj[u][i].first;
            if (d[u] + w < d[v]) {
                heap.emplace(wv(d[u] + w, v));
            }
        }
    }
    return d;
}

signed main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    graph g(n);
    for (int i = 0; i < m; i++) {
        int a,b,c;
        cin >> a >> b >> c;
        g[a-1].push_back(wv(c, b-1));
    }
    vi d = djikstra(0, g);
    for (int i = 0; i < n; i++) {
        cout << d[i] << (i == n-1 ? "\n" : " ");
    }
    return 0;
}
