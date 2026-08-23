#include <bits/stdc++.h>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

namespace rgs = std::ranges;

void solve() {
    int n;
    i64 ax, ay, bx, by;
    std::cin >> n >> ax >> ay >> bx >> by;

    std::string s;
    std::cin >> s;

    std::cout << std::abs(ax - bx) + std::abs(ay - by) + n << "\n";

    for (auto c : s) {
        bool alice = false;
        if (c == 'L' and ax <= bx) {
            alice = true;
        }
        if (c == 'R' and ax > bx) {
            alice = true;
        }
        if (c == 'U' and ay >= by) {
            alice = true;
        }
        if (c == 'D' and ay < by) {
            alice = true;
        }

        std::cout << "BA"[alice];
    }
    std::cout << "\n";
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
