#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <algorithm>
#define ll	long long
#define pii	pair<int,int>
#define pll pair<ll, ll>
#define LINF 0x0fffffffffffffff // ~= 1e18
#define INF 0x7fffffff
using namespace std;

ll T, N, M, ans, temp;
vector<ll> m;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (ll t = 1; t <= T; t++) {
		ans = 0;

		string s;
		cin >> s;
		m.clear(); m.resize(s.size());
		ll toggle = 0, cnt = 0;
		for (ll i = 0; i < s.size(); i++) {
			if (s[i] - '0' == toggle || s[i] == '?') {
				m[i] = 1;
				cnt++;
			}
			else {
				ans += cnt * (cnt + 1) / 2;

				cnt = 0;
			}
			
			toggle = !toggle;
		}
		ans += cnt * (cnt + 1) / 2;

		ll rcnt = 0;
		toggle = 1, cnt = 0;
		for (ll i = 0; i < s.size(); i++) {
			if (s[i] - '0' == toggle || s[i] == '?') {
				cnt++;
			}
			else {
				ans += cnt * (cnt + 1) / 2;

				cnt = 0;
			}

			if (cnt) {
				if (s[i] - '0' != toggle || s[i] == '?') {
					rcnt++;
				}
				else {
					ans -= rcnt * (rcnt + 1) / 2;

					rcnt = 0;
				}
			}
			else {
				if (rcnt) {
					ans -= rcnt * (rcnt + 1) / 2;
				}
				rcnt = 0;
			}

			toggle = !toggle;
		}

		if(cnt) {
			ans += cnt * (cnt + 1) / 2;
			if (rcnt) {
				ans -= rcnt * (rcnt + 1) / 2;
			}
		}

		cout << ans << '\n';
	}

	return 0;
}

/*
0. Enough array size? Enough array size? Integer overflow?

1. Think TWICE, Code ONCE!
Are there any counterexamples to your algo?

2. Be careful about the BOUNDARIES!
N=1? P=1? Something about 0?

3. Do not make STUPID MISTAKES!
Time complexity? Memory usage? Precision error?

4. Be careful to wrong variable.
*/