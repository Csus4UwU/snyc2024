#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using ll = long long;

struct TwoSat {
    int n;
    std::vector<std::vector<int>> e;
    std::vector<bool> ans;
    TwoSat(int n) : n(n), e(2 * n), ans(n) {}
    void addClause(int u, bool f, int v, bool g) {
        e[2 * u + !f].push_back(2 * v + g);
        e[2 * v + !g].push_back(2 * u + f);
    }
    bool satisfiable() {
        std::vector<int> id(2 * n, -1), dfn(2 * n, -1), low(2 * n, -1);
        std::vector<int> stk;
        int now = 0, cnt = 0;
        std::function<void(int)> tarjan = [&](int u) {
            stk.push_back(u);
            dfn[u] = low[u] = now++;
            for (auto v : e[u]) {
                if (dfn[v] == -1) {
                    tarjan(v);
                    low[u] = std::min(low[u], low[v]);
                } else if (id[v] == -1) {
                    low[u] = std::min(low[u], dfn[v]);
                }
            }
            if (dfn[u] == low[u]) {
                int v;
                do {
                    v = stk.back();
                    stk.pop_back();
                    id[v] = cnt;
                } while (v != u);
                ++cnt;
            }
        };
        for (int i = 0; i < 2 * n; ++i) if (dfn[i] == -1) tarjan(i);
        for (int i = 0; i < n; ++i) {
            if (id[2 * i] == id[2 * i + 1]) return false;
            ans[i] = id[2 * i] > id[2 * i + 1];
        }
        return true;
    }
    std::vector<bool> answer() { return ans; }
};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int n, m;
    cin >> n >> m;

    TwoSat ts(2 * n);
    for (int i = 0; i < n; i++) {
        int u = 2 * i;
        int v = u + 1;
        ts.addClause(u, 1, v, 1);
        ts.addClause(u, 0, v, 0);
    }

    while (m--) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        ts.addClause(x, 0, y, 0);
    }
    if (ts.satisfiable()) {
        auto ans = ts.answer();
        for (int i = 0; i < 2 * n; i++) {
            if (ans[i]) {
                cout << i + 1 << endl;
            }
        }
    } else {
        cout << "NIE";
    }


    
    return 0;
}