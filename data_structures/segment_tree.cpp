#define _CRT_SECURE_NO_WARNINGS
#define ln '\n'
#define All(x) (x).begin(), (x).end()
#define Allr(x) (x).rbegin(), (x).rend()
#define Allf(x) x.begin() + 1, x.end()

#define fi(a, b) for (int i = (a); i <= (b); i++)
#define fj(a, b) for (int j = (a); j <= (b); j++)
#define fo(a, b) for (int o = (a); o <= (b); o++)
#define fq(a, b) for (int q = (a); q <= (b); q++)
#define fe(a, b) for (int e = (a); e <= (b); e++)
#define fw(a, b) for (int w = (a); w <= (b); w++)

#define fri(a, b) for (int i = (a); i >= (b); i--)
#define frj(a, b) for (int j = (a); j >= (b); j--)
#define fro(a, b) for (int o = (a); o >= (b); o--)
#define frq(a, b) for (int q = (a); q >= (b); q--)
#define fre(a, b) for (int e = (a); e >= (b); e--)
#define frw(a, b) for (int w = (a); w >= (b); w--)

#define FI(a, b, c) for (int i = (a); i <= (b); i += (c))
#define FJ(a, b, c) for (int j = (a); j <= (b); j += (c))
#define FO(a, b, c) for (int o = (a); o <= (b); o += (c))
#define FQ(a, b, c) for (int q = (a); q <= (b); q += (c))
#define FE(a, b, c) for (int e = (a); e <= (b); e += (c))

#define FRI(a, b, c) for (int i = (a); i >= (b); i -= (c))
#define FRJ(a, b, c) for (int j = (a); j >= (b); j -= (c))
#define FRO(a, b, c) for (int o = (a); o >= (b); o -= (c))
#define FRQ(a, b, c) for (int q = (a); q >= (b); q -= (c))
#define FRE(a, b, c) for (int e = (a); e >= (b); e -= (c))

#define fx(A) for (auto &x : (A))
#define fy(A) for (auto &y : (A))
#define fz(A) for (auto &z : (A))

#define pb push_back
#define ins insert
#define mt empty
#define len(x) (int)(x).size()
#define Len(x) (int)(x).size()
#define sz(x) (int)x.size()

#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cmath>
#include <cstdarg>
#include <cassert>
#include <ctime>
#include <tuple>
#include <unordered_set>
#include <unordered_map>
#include <random>
#include <chrono>

using namespace std;

#ifdef _DEBUG
#define LOCAL
#endif

mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ld> vd;
typedef vector<char> vc;
typedef vector<string> vs;

typedef vector<vb> vvb;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<vc> vvc;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

template<typename A, typename B>
ostream& operator<<(ostream& os, pair<A, B> p) {
	os << "(" << p.first << ", " << p.second << ")";
	return os;
}
 
template<typename T>
ostream& operator<<(ostream& os, vector<T> v) {
	fi(0, sz(v) - 1) {
		os << v[i] << " ";
	}
	return os;
}
 
template<typename T>
ostream& operator<<(ostream& os, set<T> t) {
	for (auto z : t) {
		os << z << " ";
	}
	return os;
}
 
template<typename T1, typename T2>
ostream& operator<<(ostream& os, map<T1, T2> t) {
	cerr << endl;
	for (auto z : t) {
		os << "\t" << z.first << " -> " << z.second << endl;
	}
	return os;
}
 
#ifdef LOCAL
#define dbg(x) {cerr << __LINE__ << "\t" << #x << ": " << (x) << endl;}
#else
#define dbg(x) {}
#endif
 
#ifdef LOCAL
#define ass(x) if (!(x)) { cerr << __LINE__ << "\tassertion failed: " << #x << endl, abort(); }
#else
#define ass(x) assert(x)
#endif

int n;
vll a;
int tn;
vll st;

void update(int l, int r, ll val, int tl = 0, int tr = tn - 1, int x = 1) {
    if(tr < l || r < tl) {
        return;
    }
    if(tl == l && tr == r) {
        st[x] = val;
        return;
    }
    int th = (tl + tr) / 2;
    update(l, r, val, tl, th, x * 2);
    update(l, r, val, th + 1, tr, x * 2 + 1);
    st[x] = st[x * 2] + st[x * 2 + 1];
}

ll get_val(int l, int r, int tl = 0, int tr = tn - 1, int x = 1) {
    if(tr < l || r < tl) {
        return 0;
    }
	if(l <= tl && tr <= r) {
		return st[x];
	}
	
	int th = (tl + tr) / 2;
	return get_val(l, r, tl, th, x * 2) + get_val(l, r, th + 1, tr, x * 2 + 1);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    cin >> n;
    a = vll(n + 1);

    tn = 1;
    while(tn < n) {
        tn *= 2;
    }
    st = vll(tn * 2 + 1, 0);
}