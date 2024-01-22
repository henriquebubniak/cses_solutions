#include <bits/stdc++.h>
using namespace std;
#define INF LLONG_MAX - INT32_MAX
#define int long long
using wv = pair<int, int>;
using graph = vector<vector<wv>>;
using vi = vector<int>;

int ncv = -1;

bool search(graph* g, vi* nc, int s, vector<bool>* vis) {
    if ((*vis)[s] == true) {
        return false;
    }
    (*vis)[s] = true;
    if ((*nc)[s] == 1) {
        ncv = s;
        return true;
    }
    for (auto[_, v] : (*g)[s]) {
        if (search(g,nc,v, vis)) {
            return true;
        }
    }
    return false;
}
bool search2(graph* g, int s, vector<bool>* vis) {
    if ((*vis)[s] == true) {
        return false;
    }
    (*vis)[s] = true;
    if (s == ncv) {
        return true;
    }
    for (auto[_, v] : (*g)[s]) {
        if (search2(g, v, vis)) {
            return true;
        }
    }
    return false;
}

vi bellman_ford(int s, graph* adj, vi* nc) {
    int n = adj->size();
    vi d(n, INF);
    d[s] = 0;
    for (int i = 0; i < n-1; i++) {
        for (int u = 0; u < n; u++) {
            for (auto [w, v] : (*adj)[u]) {
                if (d[u] + w < d[v]) {
                    d[v] = d[u] + w;
                }
            }

        }
    }
    for (int u = 0; u < n; u++) {
        for (auto [w, v] : (*adj)[u]) {
            if (d[u] + w < d[v]) {
                (*nc)[v] = 1;
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
    vi nc(n, 0);
    for (int i = 0; i < m; i++) {
        int a,b,c;
        cin >> a >> b >> c;
        g[a-1].push_back(wv(c*-1, b-1));
    }
    vi d = bellman_ford(0, &g, &nc);
    graph gt(n);
    for (int u = 0; u < g.size(); u++) {
        for (auto [w, v] : g[u]) {
            gt[v].push_back(wv(w, u));
        }
    }
    vector<bool> vis(n,false);
    vector<bool> vis2(n,false);
    bool ar = search(&gt, &nc, n-1, &vis);
    if (ar) {
        ar = search2(&g, 0, &vis2);
    }
    cout << (ar ? -1 : d[n-1]*-1) << "\n";
    return 0;
}
