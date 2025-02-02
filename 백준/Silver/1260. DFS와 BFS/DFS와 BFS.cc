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

int N, M, V;
const int MAX = 1001;
int arr[MAX][MAX]{};
bool visited[MAX]{};

void set() {
	for (int i = 1; i <= N; i++) {
		visited[i] = false;
	}
}

void DFS(int v) {
	visited[v] = true;
	cout << v << " ";

	for (int i = 1; i <= N; i++) {
		if (arr[v][i] == 1 && visited[i] == false) {
			DFS(i);
		}
	}
}

void BFS(int v) {
	visited[v] = true;
	cout << v << " ";

	queue<int> q;
	q.push(v);
	while (!q.empty()) {
		v = q.front();
		q.pop();
		for (int i = 1; i <= N; i++) {
			if (arr[v][i] == 1 && visited[i] == false) {
				visited[i] = true;
				cout << i << " ";
				q.push(i);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M >> V;
	
	int x, y;
	for (int i = 0; i < M; i++) {
		cin >> x >> y;
		arr[x][y] = 1;
		arr[y][x] = 1;
	}

	set();
	DFS(V);

	cout << "\n";

	set();
	BFS(V);

	return 0;
}