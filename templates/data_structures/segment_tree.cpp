
vll st;
void build(int tl = 1, int tr = n, int x = 1) {
	if (tl == tr) {
		st[x] = a[tl];
		return;
	}
	int th = (tl + tr) / 2;
	build(tl, th, x * 2);
	build(th + 1, tr, x * 2 + 1);
	st[x] = st[x * 2] + st[x * 2 + 1];
}
void update(int p, int val, int tl = 1, int tr = n, int x = 1) {
	if (tl > p) return;
	if (tr < p) return;
	if (tl == p && tr == p) {
		st[x] = val;
		return;
	}
	int th = (tl + tr) / 2;
	update(p, val, tl, th, x * 2);
	update(p, val, th + 1, tr, x * 2 + 1);
	st[x] = st[x * 2] + st[x * 2 + 1];
}
ll get(int l, int r, int tl = 1, int tr = n, int x = 1) {
	if (tl > r) return 0;
	if (tr < l) return 0;
	if (l <= tl && tr <= r) return st[x];
	int th = (tl + tr) / 2;
	return get(l, r, tl, th, x * 2) + get(l, r, th + 1, tr, x * 2 + 1);
}
void init() {
	st = vll(4 * n);
	build();
}
