vector<int> dijkstra(int s){
	vector<int> d(n + 1, INF);
	d[s] = 0;
	set<pair<int, int>> t;
	t.insert(mp(d[s], s));
	vector<int> color(n + 1, 0);
	while(sz(t)) {
		auto[_, x] = *t.begin();
		t.erase(t.begin());
		if(color[x]) continue;
		color[x] = true;
		for(auto &[y, w] : e[x]) {
			if(d[y] > d[x] + w) {
				d[y] = d[x] + w;
				t.insert(mp(d[y], y));
			}
		}
	}
	return d;
}