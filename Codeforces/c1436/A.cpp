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
#define LINF 0x7fffffffffffffff
#define INF 0x7fffffff
using namespace std;

ll T, N, M, ans, temp;
vector<ll> m;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (ll t = 1; t <= T; t++) {
		cin >> N >> M;
		m.clear(); m.resize(N);
		ans = 0;
		for (ll i = 0; i < N; i++) {
			cin >> m[i];
			ans += m[i];
		}

		if (ans == M) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}

	return 0;
}
