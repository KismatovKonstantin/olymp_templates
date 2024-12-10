vll lcm(n + 1);
ll k = 0;
fi(1, n) {
    ll x = rev[i] - 1;
    ll cnt = max(k - 1, (ll)0);
    fj(cnt, 1e5 + 10) {
        if (s[i + j] == s[arr[x] + j]) cnt++;
        else break;
    }
    if (x == 0) cnt = 0;
    lcm[x] = cnt;
    k = cnt;
}
