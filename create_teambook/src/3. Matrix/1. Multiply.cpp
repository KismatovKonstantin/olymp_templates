Matrix mult_mtr(Matrix A, Matrix B, ll MOD) {
	vector<vll>res;
	ll n2, m2;
	n2 = A.n;
	m2 = B.m;
	res = vector<vll>(n2+1,vll(m2+1));
	fi(1, n2) {
		fj(1, m2) {
			ll cur = 0;
			fo(1, A.m) {
				cur = cur + A.mtr[i][o] * B.mtr[o][j];
			}
			res[i][j] = cur;
		}
	}
	return Matrix{n2,m2,res};
}
