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

ll n, m;
ll bounty, inc, dmg;

struct Char {
    ll id;
    ll maxi;
    ll reg;
    ll lki;
    ll dead;
    ll last_health;

    Char(ll id, ll maxi, ll cur, ll reg) : id(id), maxi(maxi), reg(reg), lki(0), dead(0), last_health(cur) {};
};

struct Event {
    ll t;
    ll info;
    ll cid;
    ll type;

    Event(ll t, ll info, ll cid, ll type) : t(t), info(info), cid(cid), type(type) {};
    bool operator<(const Event& e) const {
        if(t == e.t) return type < e.type;
        return t < e.t;
    };
};

vector<Char> chars;
vector<Event> events;

ll cbounty;
ll dead;

void optimise(ll t) {
    cbounty = max(cbounty, dead * (bounty + inc * t));
}

int main(){
    std::ios::sync_with_stdio(false);
    cin >> n >> m;
    cin >> bounty >> inc >> dmg;
    bool inf = false;

    dead = 0;
    for(int i = 0; i < n; i++) {
        ll mh, sh, reg;
        cin >> mh >> sh >> reg;
        chars.pb(Char(i, mh, sh, reg));

        inf = inf || (inc > 0 && (mh <= dmg));

        if(sh <= dmg) {
            dead++;
            chars[i].dead = 1;
            if(reg > 0) {
                ll t = (dmg - sh)/reg + 1;
                events.pb(Event(t, 0, i, -1));
            }
        }
    }
    cbounty = dead * bounty;

    for(int i = 0; i < m; i++) {
        ll time, enemy, health;
        cin >> time >> enemy >> health;

        chars[--enemy].last_health = health;

        if(health <= dmg) {
            events.pb(Event(time, time, enemy, 1));
            if(chars[enemy].reg > 0) {
                ll t = (dmg - health)/chars[enemy].reg + 1;
                events.pb(Event(t + time, time, enemy, -1));
            }
        }
        else {
            events.pb(Event(time, time, enemy, -1));
        }
    }

    for(int i = 0; i < n; i++) inf = inf || (inc > 0 && chars[i].last_health <= dmg && chars[i].reg == 0);
    if(inf) goto infinity;

    sort(events.begin(), events.end());
    for(auto e : events) {
        auto &c = chars[e.cid];
        if(e.type == 1) {
            if(!c.dead) {
                dead++;
                optimise(e.t);
                c.dead = 1;
            }
            c.lki = e.t;
        }
        else {
            if(c.dead && e.info >= c.lki) {
                optimise(e.t - 1);
                dead--;
                c.dead = 0;
                c.lki = e.t;
            }
        }
    }

    cout << cbounty << endl;
    return 0;

infinity:
    cout << -1 << endl;
}
