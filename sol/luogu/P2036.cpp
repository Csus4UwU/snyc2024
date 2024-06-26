// https://www.luogu.com.cn/problem/P2036
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define enter putchar('\n')
const int N = 1e3 + 100;

inline char nc()
{
    static char buf[100000], *p1 = buf, *p2 = buf;
    return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2) ? EOF : *p1++;
}
inline ll read()
{
    int x = 0, f = 1;
    char ch = nc();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = nc();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = x * 10 + (ch ^ 48);
        ch = nc();
    }
    return x * f;
}
void write(ll x)
{
    if (x < 0)
        putchar('-'), x = -x;
    if (x >= 10)
        write(x / 10);
    putchar(x % 10 + '0');
}

struct node
{
    int s, b;
} g[N];

int n;
int res;
bool vis[N];

void dfs(int fa, int so, int bi)
{
    vis[fa] = true;
    int nso = so * g[fa].s, nbi = bi + g[fa].b;
    res = min(res, abs(nso - nbi));
    for (int i = 1; i <= n; i++)
        if (!vis[i])
        {
            dfs(i, nso, nbi);
            vis[i] = false;
        }
    vis[fa] = false;
}

void solve()
{
    res = 0x7fffffff;
    n = read();
    for (int i = 1; i <= n; i++)
        g[i].s = read(), g[i].b = read();
    for (int i = 1; i <= n; i++)
    {
        memset(vis, 0, sizeof(vis));
        dfs(i, 1, 0);
    }
    write(res);
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}