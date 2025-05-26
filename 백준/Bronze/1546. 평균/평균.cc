#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int* a = new int[n];
	float sum = 0;
	int max = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (max < a[i]) {
			max = a[i];
		}
	}
	for (int i = 0; i < n; i++) {
		sum += (float)a[i] / max * 100;
	}
	float e;
	e = sum / (float)n;
	cout << e;
}