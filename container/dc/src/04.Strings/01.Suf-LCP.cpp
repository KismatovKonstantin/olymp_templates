string s;
vi p, c, rc;
int x = 1;
int gett(int a, int x) {
    if (a > x) return a - x;
    return sz(s) - 1 - (x - a) % (sz(s) - 1);
}
int gett2(int a, int x) {
    if (a + x < sz(s))
        return a + x;
    return 1 + (a + x) % sz(s);
}
bool comp1(int a, int b) {
    return (s[a] < s[b]);
}
int n, S;
vvi e;
void Sort(vector<int> &p) {
    fi(1, n) {
        int t = gett(p[i], x);
        e[rc[t]].pb(t);
    }
    p.clear();
    p.pb(0);
    fi(0, n) {
        fz(e[i]) {
            p.pb(z);
        }
        e[i].clear();
    }
}
void init() {
    n = sz(s) + 1;
    s = "#" + s + (char)31;
    c = vi(n + 1);
    rc = vi(n + 1);
    fi(0, n) p.pb(i);
    sort(Allf(p), comp1);
    c[1] = 0;
    fi(2, n) {
        if (s[p[i]] == s[p[i - 1]]) c[i] = c[i - 1];
        else c[i] = c[i - 1] + 1;
    }
    fi(1, n) {
        rc[p[i]] = c[i];
    }
    e = vvi(n + 1);
    x = 1;
    while (x < n) {
        Sort(p);
        c[1] = 0;
        fi(2, n) {
            if (rc[p[i]] == rc[p[i - 1]] && rc[gett2(p[i], x)] == rc[gett2(p[i - 1], x)]) {
                c[i] = c[i - 1];
            } else {
                c[i] = c[i - 1] + 1;
            }
        }
        fi(1, n) {
            rc[p[i]] = c[i];
        }
        x *= 2;
    }
}
