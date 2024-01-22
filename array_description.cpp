#include <bits/stdc++.h>
using namespace std;
#define INF LLONG_MAX - INT32_MAX
#define int long long
using vi = vector<int>;
using matrix = vector<vector<int>>;

signed main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    vi x;
    cin >> n >> m;
    vi ult;
    vi q;
    int last = 0;
    for (int i = 0; i < n; i++) {
        int aux;
        cin >> aux;
        x.push_back(aux);
    }
    if (x[0] == 0) {
        for (int i = 1; i <= m; i++) {
            ult.push_back(i);
        }
        q.push_back(m);
        int i;
        for (i = 1; x[i] == 0 && i < n; i++) {
            for (auto y : ult) {
                if (y > 1)
                    ult.push_back(y-1);
                if (y < m)
                    ult.push_back(y+1);
            }
            q.push_back(ult.size());
        }
        int cont = 0;
        for (auto y : ult) {
            if (abs(x[i]-y) > 1) {
                cont++;
            }
        }
        q.push_back(q[i-1]-cont);
        ult.clear();
        ult.push_back(x[i]);
        last = i;
    } else {
        ult.push_back(x[0]);
        q.push_back(1);
        last = 0;
    }
    for (int i = last+1; i < n; i++) {
        if (x[i] != 0) {
            int cont = 0;
            for (auto y : ult) {
                if (abs(x[i]-y) > 1) {
                    cont++;
                }
            }
            q.push_back(q[i-1]-cont);
            ult.clear();
            ult.push_back(x[i]);
            last = i;
        } else {
            for (auto y : ult) {
                if (y > 1)
                    ult.push_back(y-1);
                if (y < m)
                    ult.push_back(y+1);
            }
            q.push_back(q[last]*ult.size());
        }
    }
    cout << q[n-1] << "\n";


    return 0;
}
