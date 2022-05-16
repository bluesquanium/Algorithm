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
		cin >> N;
		m.clear(); m.resize(N);
		ll check = 0;
		for (ll i = 0; i < N; i++) {
			cin >> m[i];
			if (m[i]) {
				check = 1;
			}
		}

		sort(m.begin(), m.end());
		ll diff = m[N - 1] - m[N - 2];
		for (ll i = 0; i < N - 2; i++) {
			diff -= m[i];
		}

		if (diff <= 0) {
			ans = 1;
		}
		else {
			ans = diff;
		}

		if (check == 0) {
			ans = 0;
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