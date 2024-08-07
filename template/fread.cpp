namespace QuickRead {
    char buf[1 << 21], *p1 = buf, *p2 = buf;
    inline int getc() {
        return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2) ? EOF : *p1++;
    }
    template <typename T> void Cin(T &a) {
        T ans = 0;
        bool f = 0;
        char c = getc();
        for (; c < '0' || c > '9'; c = getc()) {
            if (c == '-') f = 1;
        }
        for (; c >= '0' && c <= '9'; c = getc()) {
            ans = ans * 10 + c - '0';
        }
        a = f ? -ans : ans;
    }
    template <typename T, typename... Args> void Cin(T &a, Args &...args) {
        Cin(a), Cin(args...);
    }
    template <typename T> void write(T x) {
        if (x < 0) putchar('-'), x = -x;
        if (x > 9) write(x / 10);
        putchar(x % 10 + '0');
    }
}

using namespace QuickRead;