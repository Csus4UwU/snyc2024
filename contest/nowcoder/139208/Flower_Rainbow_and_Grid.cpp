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

void solve() {
    i64 n, m, k;
    std::cin >> n >> m >> k;

    auto check = [&](i64 x) {
        i64 cnt = 0;
        for (i64 i = 1; i <= n; i++) {
            i64 v = i * i - x;
            if (v < 0) {
                continue;
            }
            i64 mj = std::sqrt(v);

            cnt += std::min(mj, m);
        }
        return cnt >= k;
    };

    i64 lo = -m * m, hi = n * n - 1;
    while (lo < hi) {
        i64 x = std::midpoint(lo, hi + 1);
        if (check(x)) {
            lo = x;
        } else {
            hi = x - 1;
        }
    }

    i64 ans = 0;
    i64 rest = k;
    for (i64 i = 1; i <= n; i++) {
        i64 v = i * i - lo - 1;
        if (v < 0) {
            continue;
        }

        i64 mj = std::sqrt(v);
        mj = std::min(mj, m);
        rest -= mj;
        ans += mj * i * i - sum2(mj);
    }
    ans += rest * lo;

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
