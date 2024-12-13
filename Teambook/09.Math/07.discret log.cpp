int solve (int a, int b, int m) {
	int n = (int) sqrt (m + .0) + 1;
 	int cur;
	int an = 1;
	fi(0, n - 1) {
		an = (an * a) % m;
	}
 
	map<int,int> vals;
	
	cur = an;
	fi(1, n) {
		if (!vals.count(cur))
			vals[cur] = i;
		cur = (cur * an) % m;
	}
	cur = b;
	fi(0, n) {
		if (vals.count(cur)) {
			int ans = vals[cur] * n - i;
			if (ans < m) return ans;
		}
		cur = (cur * a) % m;
	}
	return -1;
}