//O valor retornado eh gcd(a,b) = ax + by
ll gcd_extended(ll a, ll b, ll &x, ll &y) {
    if (a == 0) { x = 0, y = 1; return b; }
    ll xx, yy, d = gcd_extended(b%a, a, xx, yy);
    x = yy-(b/a)*xx, y=xx;
    if (d < 0) {d = -d; x = -x; y = -y; }
    return d;
}
