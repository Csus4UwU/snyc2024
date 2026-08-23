#include <bits/stdc++.h>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

namespace rgs = std::ranges;

constexpr i64 sum2(i64 x) {
    return x * (x + 1) / 2 * (2 * x + 1) / 3;
}

constexpr int inf = 1e9;

constexpr int dx[] {0, 0, 1, -1};
constexpr int dy[] {1, -1, 0, 0};

void solve() {
    int n, m;
    std::cin >> n >> m;

    std::string s;
    std::cin >> s;

    std::vector<std::string> g(n);
    for (int i = 0; i < n; i++) {
        std::cin >> g[i];
    }

    std::vector dp(n, std::vector<std::array<int, 3>>(m, {-1, -1, -1}));
    dp[n - 1][m - 1] = {};

    std::queue<std::tuple<int, int, int>> q;
    q.emplace(n - 1, m - 1, 0);
    q.emplace(n - 1, m - 1, 1);
    q.emplace(n - 1, m - 1, 2);

    while (not q.empty()) {
        auto [x, y, r] = q.front();
        q.pop();

        int nr = (r + 2) % 3;

        // std::cerr << r << " " << nr << "\n";

        for (int k = 1; k <= 3; k++) {
            // std::cerr << ((nr + k - 1) % 3) << "\n";
            if (s[(nr + k - 1) % 3] != g[x][y]) {
                continue;
            }
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i] * k;
                int ny = y + dy[i] * k;
    
                if (nx < 0 or nx >= n or ny < 0 or ny >= m) {
                    continue;
                }

                if (dp[nx][ny][nr] == -1) {
                    dp[nx][ny][nr] = dp[x][y][r] + 1;
                    q.emplace(nx, ny, nr);
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // int ans = rgs::min(dp[i][j]);
            int ans = dp[i][j][0];
            std::cout << ans << " \n"[j == m - 1];
        }
    }
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
