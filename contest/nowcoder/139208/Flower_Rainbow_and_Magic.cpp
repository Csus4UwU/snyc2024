#include <bits/stdc++.h>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

namespace rgs = std::ranges;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int x, y, z;
    std::cin >> x >> y >> z;

    if (x == 0 and y == 0 and z == 0) {
        std::cout << 1 << " " << y << " " << z << " " << -1 << " " << y << " " << z << "\n";
    } else {
        std::cout << 2 * x << " " << 2 * y << " " << 2 * z << " " << 0 << " " << 0 << " " << 0 << "\n";
    }

}