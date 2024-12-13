ll n;
vvi e;
vi color;
vvi e2;
vvi _num;
int id = 1;
 
int num(int v,int t){
	if(!_num[v][t] )_num[v][t] = id++;
	return _num[v][t];
}
vvi e2r;
vi u;
vi ord;
void dfs2(int v){
	if(u[v])return;
	u[v] = 1;
	fz(e2[v]){
		dfs2(z);
	}
	ord.pb(v);
}
int comp = 0;
vi component;
void dfs3(int v){
	if(component[v])return;
	component[v] = comp;
	fz(e2r[v]){
		dfs3(z);
	}	
}
vi ans;
bool can(){
	ord.clear();
	ans.clear();
	e2r = vvi(4*n + 1);
	comp = 1;
	fi(1,4*n){
		fz(e2[i]){
			e2r[z].pb(i);
		}
	}
 
	u = vi(4*n + 1);
	fi(1,4*n){
		dfs2(i);
	}
	dbg("S");
	component = vi(4*n  + 1);
	
	fdi(sz(ord) -1,0){
		if(!component[ord[i]]){
			dfs3(ord[i]);
			comp++;
		}
	}
	dbg("D");
	fi(1,2*n){
		if(component[num(i,1)] == component[num(i,2)])return false;
		if(component[num(i,1)] > component[num(i,2)])ans.pb(i);
	}
	return true;	
}
