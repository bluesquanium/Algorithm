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

class SegTree {
public:
	ll DEFAULT = -INF;
	ll numElement;
	ll segTreeSize;
	vector<ll> tree;
	vector<ll> lazy;
	vector<ll> treeIdxTable;

	void init(vector<ll> &a) {
		numElement = a.size();
		ll height = (ll)ceil(log2(numElement));
		segTreeSize = (1 << (height + 1));
		tree.resize(segTreeSize, DEFAULT);
		lazy.resize(segTreeSize, 0);
		treeIdxTable.resize(numElement);

		initTree(a, 1, 0, numElement - 1);
	}

	ll query(ll left, ll right) {
		return queryTree(1, 0, numElement - 1, left, right);
	}

	void update_range(int treeIdx, int start, int end, int left, int right, long long diff) {
		update_lazy(treeIdx, start, end);
		if (left > end || right < start) {
			return;
		}
		if (left <= start && end <= right) {
			tree[treeIdx] += (end - start + 1)*diff;
			if (start != end) {
				lazy[treeIdx * 2] += diff;
				lazy[treeIdx * 2 + 1] += diff;
			}
			return;
		}
		update_range(treeIdx * 2, start, (start + end) / 2, left, right, diff);
		update_range(treeIdx * 2 + 1, (start + end) / 2 + 1, end, left, right, diff);
		tree[treeIdx] = tree[treeIdx * 2] + tree[treeIdx * 2 + 1];
	}

private:
	void update_lazy(int treeIdx, int start, int end) {
		if (lazy[treeIdx] != 0) {
			tree[treeIdx] += (end - start + 1)*lazy[treeIdx];
			// leaf�� �ƴϸ�
			if (start != end) {
				if (tree[treeIdx * 2] != DEFAULT) {
					lazy[treeIdx * 2] += lazy[treeIdx];
				}
				if (tree[treeIdx * 2 + 1] != DEFAULT) {
					lazy[treeIdx * 2 + 1] += lazy[treeIdx];
				}
			}
			lazy[treeIdx] = 0;
		}
	}

	ll initTree(vector<ll> &a, ll treeIdx, ll start, ll end) {
		if (start == end) {
			treeIdxTable[start] = treeIdx;
			return tree[treeIdx] = a[start];
		}
		else {
			return tree[treeIdx] = cal(initTree(a, treeIdx * 2, start, (start + end) / 2), initTree(a, treeIdx * 2 + 1, (start + end) / 2 + 1, end));
		}
	}

	ll queryTree(ll treeIdx, ll start, ll end, ll left, ll right) {
		update_lazy(treeIdx, start, end);
		if (left > end || right < start) {
			return 0;
		}
		if (left <= start && end <= right) {
			return tree[treeIdx];
		}
		return cal(queryTree(treeIdx * 2, start, (start + end) / 2, left, right), queryTree(treeIdx * 2 + 1, (start + end) / 2 + 1, end, left, right));
	}

	inline ll convertToTreeIdx(ll idx) {
		return treeIdxTable[idx];
	}

	inline ll cal(ll x, ll y) {
		return x + y;
	}

	inline ll updateCal(ll treeVal, ll diff) {
		return treeVal + diff;
	}
} segTree;

ll N, M, K, ans, temp;
vector<ll> m;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N >> M >> K;
	m.resize(N);
	for (ll i = 0; i < N; i++) {
		cin >> m[i];
	}

	segTree.init(m);

	for (ll q = 0; q < M + K; q++) {
		ll a, b, c, d;
		cin >> a;
		if (a == 1) {
			cin >> b >> c >> d;
			b--; c--;
			segTree.update_range(1, 0, N - 1, b, c, d);
		}
		else {
			cin >> b >> c;
			b--; c--;
			cout << segTree.query(b, c) << '\n';
		}
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
