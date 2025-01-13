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

int N;
string input;
const int MAX = 101;
char arr[MAX][MAX]{};
bool visited[MAX][MAX]{};

int dx[4]{ 1,-1,0,0 };
int dy[4]{ 0,0,1,-1 };

void set() {
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j < input.length(); j++) {
			visited[i][j] = false;
		}
	}
}

void DFS(int x,int y) {
	if (visited[x][y]) return;
	visited[x][y] = true;

	for (int i = 0; i < 4; i++) {
		int X = dx[i] + x;
		int Y = dy[i] + y;
		if (arr[x][y] == arr[X][Y] && !visited[X][Y]) {
			DFS(X, Y);
		}
	}
	
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> input;
		for (int j = 0; j < input.length(); j++) {
			arr[i][j] = input[j];
		}
	}

	set();
	int result = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < input.length(); j++) {
			if (!visited[i][j]) { //방문하지 않은 위치
				DFS(i,j);
				result++;
			}
		}
	}
	cout << result << " ";

	set();
	result = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < input.length(); j++) {
			if (arr[i][j] == 'G') {
				arr[i][j] = 'R';
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < input.length(); j++) {
			if (!visited[i][j]) { //방문하지 않은 위치
				DFS(i, j);
				result++;
			}
		}
	}
	cout << result;

	return 0;
}