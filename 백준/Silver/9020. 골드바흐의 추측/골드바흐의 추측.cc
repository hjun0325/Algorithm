#include <iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	int a;
	int sosu;
	int count = 0;
	for (int i = 0; i < n; i++) {
		cin >> a;
		for (int j = a/2; j >= 2; j--) {
			for (int k = 1; k <= j; k++) {
				if (j % k == 0) {
					count++;
				}
			}
			if (count == 2) {
				sosu = j;
				for (int k = 1; k <= (a - sosu); k++) {
					if ((a - sosu) % k == 0) {
						count++;
					}
				}
				if (count == 4) {
					cout << sosu << " " << a - sosu << endl;
					count = 0;
					break;
				}
			}
			count = 0;
		}
	}
}