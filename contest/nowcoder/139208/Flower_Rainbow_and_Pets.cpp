#include <bits/stdc++.h>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

namespace rgs = std::ranges;

void solve() {
    int n, m, x, y, k;
    std::cin >> n >> m >> x >> y >> k;
    
    int c1 = n / 3;
    int c2 = m / 4;
    
    int u1 = 0, u2 = 0;
    if (x >= y) {
        u1 = std::min(k, c1);
        u2 = std::min(k - u1, c2);
    } else {
        u2 = std::min(k, c2);
        u1 = std::min(k - u2, c1);
    }
    
    if (x < y) {
        // std::cerr << u1 << " " << u2 << "\n";
    }
    
    int ans = (n - u1) * x + (m - u2) * y;
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
