#include <bits/stdc++.h>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

namespace rgs = std::ranges;

int P;

constexpr int N = 18;
using Mat = std::array<std::array<u64, N>, N>;
Mat operator*(const Mat &a, const Mat &b) {
    Mat c {};
    for (int i = 0; i < N; i++) {
        for (int k = 0; k < N; k++) {
            for (int j = 0; j < N; j++) {
                c[i][j] += a[i][k] * b[k][j];
                if ((k & 15) == 15 or k == N - 1) {
                    c[i][j] %= P;
                }
            }
        }
    }
    return c;
}
Mat power(Mat a, u64 b) {
    Mat res {};
    for (int i = 0; i < N; i++) {
        res[i][i] = 1;
    }
    for (; b != 0; b /= 2, a = a * a) {
        if (b & 1) {
            res = res * a;
        }
    }
    return res;
}

Mat M {};

void solve() {
    int a, b;
    std::cin >> a >> b >> P;

    Mat ans = M;
    for (int i = 0; i < b; i++) {
        ans = power(ans, a);
    }

    std::cout << ans[0][9] % P << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    for (int i = 0; i < 9; i++) {
        M[0][i] = 10;
        M[9][i] = 0;
    }
    for (int i = 9; i < 18; i++) {
        M[0][i] = i - 8;
        M[9][i] = 1;
    }
    for (int i = 1; i < 9; i++) {
        M[i][i - 1] = 1;
    }
    for (int i = 10; i < 18; i++) {
        M[i][i - 1] = 1;
    }

    int t;
    std::cin >> t;

    while (t--) {
        solve();
    }
}