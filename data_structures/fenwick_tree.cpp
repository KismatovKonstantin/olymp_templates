
vll fen;
void add(int p, ll val) {
    for(int i = p; i <= n; i = (i | (i + 1))) {
        fen[i] += val;
    }
}
ll sum(int p) {
    ll res = 0;
    for(int i = p; i >= 0; i = (i & (i + 1)) - 1) {
        res += fen[i];
    }
    return res;
}
