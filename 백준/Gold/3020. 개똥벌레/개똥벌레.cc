#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <utility>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	int h;
	cin >> h;
	int halfn = n / 2;

	int* top = new int[halfn];
	int* bottom = new int[halfn];
	for (int i = 0; i < halfn; i++) {
		cin >> bottom[i] >> top[i];
	}
	sort(bottom, bottom + halfn);
	sort(top, top + halfn);

	int sum = 0;
	int compare = halfn;
	int count = 0;
	for (int i = 1; i <= h; i++) {
		sum = halfn - (lower_bound(bottom, bottom + halfn, i) - bottom);
		sum += halfn - (lower_bound(top, top + halfn, h - i + 1) - top);
		if (compare > sum) {
			count = 0;
		}
		compare = min(sum, compare);
		if (sum == compare) {
			count++;
		}
	}
	cout << compare << " " << count;

	return 0;
}