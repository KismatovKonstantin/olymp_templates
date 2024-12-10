int gauss (vector < vector<double> > a, vector<double> & ans) {
	int n = (int) a.size();
	int m = (int) a[0].size() - 1;
	vector<int> where (m, -1);
	for (int col=0, row=0; col<m && row<n; ++col) {
		int sel = row;
		fi(row, n - 1) {
			if (abs (a[i][col]) > abs (a[sel][col]))
				sel = i;
		}
		if (abs (a[sel][col]) < EPS)
			continue;
		fi(col, m) {
			swap (a[sel][i], a[row][i]);
		}
		where[col] = row;
		fi(0, n - 1) {
			if (i != row) {
				double c = a[i][col] / a[row][col];
				fj(col, m) {
					a[i][j] -= a[row][j] * c;
				}
			}
		}
		++row;
	}
	ans.assign (m, 0);
	fi(0, m - 1) {
		if (where[i] != -1)
			ans[i] = a[where[i]][m] / a[where[i]][i];
	}
	fi(0, n - 1) {
		double sum = 0;
		fj(0, m - 1) {
			sum += ans[j] * a[i][j];
		}	
		if (abs (sum - a[i][m]) > EPS)
			return 0;
	}
	fi(0, m - 1) {
		if (where[i] == -1) return INF;
	}
	
	return 1;
}
