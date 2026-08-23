#include <bits/stdc++.h>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

namespace rgs = std::ranges;

void solve() {
    int n, W;
    std::cin >> n >> W;
    
    std::vector<int> c(n);
    for (int i = 0; i < n; i++) {
        std::cin >> c[i];
        c[i]--;
    }

    std::vector<std::vector<int>> adj(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        std::cin >> u >> v;
        u--;
        v--;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    const int logn = std::__lg(n);

    std::vector p(logn + 1, std::vector<int>(n));
    std::vector<int> dep(n);
    int tot = 0;
    
    dep[0] = 1;
    auto init = [&](auto &&self, int x) -> void {
        for (auto y : adj[x]) {
            if (p[0][x] == y) {
                continue;
            }
            p[0][y] = x;
            
            dep[y] = dep[x] + 1;
            self(self, y);
        }
    };
    init(init, 0);

    for (int j = 0; j < logn; j++) {
        for (int i = 0; i < n; i++) {
            p[j + 1][i] = p[j][p[j][i]];
        }
    }
    
    auto lca = [&](int x, int y) {
        if (dep[x] < dep[y]) {
            std::swap(x, y);
        }
        while (dep[x] > dep[y]) {
            x = p[std::__lg(dep[x] - dep[y])][x];
        }
        if (x == y) {
            return x;
        }
        for (int i = std::__lg(dep[x]); i >= 0; i--) {
            if (p[i][x] != p[i][y]) {
                x = p[i][x];
                y = p[i][y];
            }
        }
        return p[0][x];
    };

    std::vector<int> X(n, -1), weight(n);
    for (int i = 0; i < n; i++) {
        if (X[c[i]] == -1) {
            X[c[i]] = i;
        } else {
            X[c[i]] = lca(X[c[i]], i);
        }
        weight[c[i]]++;
    }
    
    std::vector<std::priority_queue<int>> q(n);
    std::vector<i64> sum(n);
    for (int i = 0; i < n; i++) {
        if (X[i] != -1) {
            q[X[i]].emplace(weight[i]);
            sum[X[i]] += weight[i];
        }
    }

    i64 ans = 0;
    auto dfs = [&](auto &&self, int x) -> void {
        for (auto y : adj[x]) {
            if (y == p[0][x]) {
                continue;
            }
            self(self, y);
            if (q[x].size() < q[y].size()) {
                std::swap(q[x], q[y]);
                std::swap(sum[x], sum[y]);
            }
            while (not q[y].empty()) {
                int w = q[y].top();
                q[y].pop();

                q[x].emplace(w);
                sum[x] += w;
            }
        }
        while (sum[x] > W and not q[x].empty()) {
            sum[x] -= q[x].top();
            q[x].pop();
        }
        ans = std::max(ans, i64(q[x].size()) * dep[x]);
    };
    dfs(dfs, 0);

    std::cout << ans << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;

    while (t--) {
        solve();
    }
}