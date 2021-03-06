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

ll T, A, B, ans;
vector<ll> m;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (ll t = 1; t <= T; t++) {
		cin >> A >> B;
		if (B > A) {
			ll temp = A;
			A = B;
			B = temp;
		}
		ll num = min(A - B, B);
		ans = num;
		A -= num * 2;
		B -= num;
		ans += (B / 3) * 2;
		A -= (B / 3) * 3;
		B -= (B / 3) * 3;
		if (A >= 2 && B >= 1) {
			ans++;
			A -= 2;
			B -= 1;
		}
		if (A >= 2 && B >= 1) {
			ans++;
			A -= 2;
			B -= 1;
		}
		
		cout << ans << '\n';
	}

	return 0;
}
