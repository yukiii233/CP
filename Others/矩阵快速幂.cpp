
struct Martix {
    int x, y, f[5][5];
    Martix(int X, int Y) {
        x = X, y = Y;
        memset(f, 0, sizeof f);
    }
    Martix operator * (const Martix &q) const {
        Martix t(x, q.y);

        for (int i = 1; i <= t.x; i++)
            for (int j = 1; j <= t.y; j++)
                for (int k = 1; k <= y; k++)
                    t.f[i][j] = (t.f[i][j] + f[i][k] * 1ll * q.f[k][j] % MOD) % MOD;

        return t;
    }
};

Martix fpow(Martix a, ll b) {
    Martix e(4, 4);

    for (int i = 1; i <= 4; i++)
        e.f[i][i] = 1;

    for (; b; b >>= 1, a = a * a)
        if (b & 1)
            e = e * a;

    return e;
}
