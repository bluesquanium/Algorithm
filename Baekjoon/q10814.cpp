#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define ll	long long
#define pii	pair<int,int>
using namespace std;

int N, M, ans;
vector<pii> m;
string name[100001];

bool cmp(pii a, pii b) {
	if (a.first != b.first) {
		return a.first < b.first;
	}
	return a.second < b.second;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N;
	m.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> m[i].first >> name[i];
		m[i].second = i;
	}

	sort(m.begin(), m.end(), cmp);

	for (int i = 0; i < N; i++) {
		cout << m[i].first << ' ' << name[m[i].second] << '\n';
	}

	return 0;
}
