#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <math.h>
#include <cstdlib>
#include <utility>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	int x = 0;
	int y = 0;
	int result = 0;
	int c = n / 5;

	while (1) {
		x = c * 5;
		y = (n - x) % 3;
		if (y == 0) {
			result = c;
			result += (n - x) / 3;
			break;
		}
		else if (c == 0) {
			result = -1;
			break;
		}
		else {
			c--;
		}
	}

	cout << result;

	return 0;
}