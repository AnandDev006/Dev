ll binExp( ll a, ll b) {
    ll res = 1;
    while ( b > 0) {
        if ( b & 1) {
            res *= a;
        }
        a *= a;
        b >> 1;
    }
    return res;
}

ll binExpMod(ll a, ll b, ll m) {
    ll res = 1;
    while ( b > 0) {
        if ( b & 1) {
            res *= a;
            res %= m;
        }
        a *= a;
        a %= m;
        b >> 1;
    }
    return res;
}

ll GCD (ll a, ll b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

ll LCM (ll a, ll b) {
    return a / gcd(a, b) * b;
}

pair<ll, ll> fib (ll n) {
    if (n == 0)
        return {0, 1};

    auto p = fib(n >> 1);
    ll c = p.first * (2 * p.second - p.first);
    ll d = p.first * p.first + p.second * p.second;
    if (n & 1)
        return {d, c + d};
    else
        return {c, d};
}