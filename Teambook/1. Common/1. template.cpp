optional, complex, string, vector, list, map, set, deque, queue, stack, bitset,
algorithm, sstream, iostream, iomanip, cstdio, cstdlib, ctime, cstring, cmath,
cstdarg, cassert, ctime, tuple, unordered_set, unordered_map, random, chrono
using namespace std;

#define ln "\n"
#define pb push_back
#define mp make_pair
#define ins insert
#define sz(x) (int)x.size()

#define All(x) (x).begin(), (x).end()
#define fi(a, b) for (auto i = (a); i <= (b); i++)
#define fdi(a, b) for (auto i = (a); i >= (b); i--)
#define fx(A) for (auto &x : (A))

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;

template<typename T>
ostream& operator<<(ostream& os, vector<T> v) {
	fz(v) {
		os << z << " ";
	}
	return os;
}
 
#ifdef LOCAL
	#define dbg(x) {cerr << __LINE__ << "\t" << #x << ": " << (x) << ln;}
#else
	#define dbg(x) {}
#endif

#ifdef LOCAL
    #define ass(x) if (!(x)) { cerr << __LINE__ << "\tassertion failed: " << #x << ln; abort(); }
#else
    #define ass(x) assert(x)
#endif

mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
}