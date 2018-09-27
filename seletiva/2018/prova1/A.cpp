
#include <bits/stdc++.h>
#define fst first
#define snd second
#define pb push_back
#define mp make_pair
#define ms(x, v) memset(x, v, sizeof x)
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
///////////////0123456789
const int  N = 10004;
const ll MOD = 1000000007;
const int OO = INT_MAX;
inline ll mod(ll x) { return x % MOD; }

int main(){
    std::ios::sync_with_stdio(false);
    ll n, t;
    int test = 1;
    while(cin >> n >> t, n != 0) {
        vector<ll> nums;
        for(int i = 0; i < n; i++) {
            int x;
            cin >> x;
            nums.pb(x);
        }
        sort(nums.begin(), nums.end());
        ll success = 0;
        for(ll x : nums) {
            ll target;
            ll acc;

            //Is there not a better way?
            if(x == 0) {
                if(t < 0) success += n;
            }
            else if(t < 0 && x < 0) {
                target = (t + x + 1) / x - 1;
                acc = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
                success += acc;
            }
            else if(t >= 0 && x < 0) {
                target = t / x - 1;
                acc = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
                success += acc;
            }
            else if(t < 0 && x > 0) {
                target = (t - x + 1) / x;
                acc = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
                success += n - acc;
            }
            else {
                target = t / x;
                acc = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
                success += n - acc;
            }
        }
        ll total = n*n;

        ll d = 2;
        while(d <= 30000) {
            while(success % d == 0 && total % d == 0) {
                success /= d;
                total /= d;
            }
            d++;
        }

        cout << "Case " << test << ": " << success << "/" << total << endl;
        test++;
    }
}
