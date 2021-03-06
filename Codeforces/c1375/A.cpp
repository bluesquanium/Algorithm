#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#define ll	long long
#define pii	pair<int,int>
#define pll pair<ll, ll>
#define LINF 0x7fffffffffffffff
#define INF 0x7fffffff
using namespace std;

ll T, N, ans;
vector<ll> m;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (ll t = 1; t <= T; t++) {
		cin >> N;
		m.clear(); m.resize(N);
		for (ll i = 0; i < N; i++) {
			cin >> m[i];
			if (i % 2 == 0) {
				if (m[i] > 0) {
					m[i] *= -1;
				}
			}
			else {
				if (m[i] < 0) {
					m[i] *= -1;
				}
			}
			cout << m[i] << ' ';
		}
		cout << '\n';
	}

	return 0;
}
