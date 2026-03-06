#include<iostream>
#include<algorithm>
#include<vector>
#include<deque>
#include<queue>

std::pair<int, int> operator+
(const std::pair<int, int>& a, const std::pair<int, int>& b)
{
	return { a.first + b.first,a.second + b.second };
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	int second = 0;
	int moveidx = 0;
	std::vector<std::pair<int, int>> move{ {0,1},{1,0},{0,-1},{-1,0} };

	int boardSize; // 보드 크기
	int appleCount; // 사과 개수
	int snakeTurnCount; // 뱀 회전 횟수
	std::deque<std::pair<int, int>> snake; // 뱀 위치
	snake.push_back({ 1,1 });

	std::vector<std::vector<int>> board; // 보드판
	std::deque<std::pair<int,int>> appleQueue; // 사과 위치
	std::queue<std::pair<int, char>> snakeTurnQueue; // 턴 하는 시점
	
	std::cin >> boardSize;
	board.resize(boardSize + 2);
	
	std::cin >> appleCount;
	for (int i = 0; i < appleCount; ++i)
	{
		int row, col;
		std::cin >> row >> col;
		appleQueue.push_back({ row,col });
	}

	std::cin >> snakeTurnCount;
	for (int i = 0; i < snakeTurnCount; ++i)
	{
		int x; char y;
		std::cin >> x >> y;
		snakeTurnQueue.push({ x,y });
	}

	while (true)
	{
		second += 1; // 초 증가
		snake.push_back(snake.back() + move[moveidx]); // 뱀 이동

		// 맵 범위 체크
		if (snake.back().first == 0 || snake.back().first == boardSize + 1 ||
			snake.back().second == 0 || snake.back().second == boardSize + 1)
		{
			break;
		}

		// 충돌 체크
		if (snake.size() > 1)
		{
			auto snake_it = std::find(snake.begin(), snake.end() - 1, snake.back());
			if (snake_it != snake.end() - 1)
			{
				break; // 충돌 시 게임 오버
			}
		}

		// 사과 판별
		auto apple_it = std::find(appleQueue.begin(), appleQueue.end(), snake.back());
		if (apple_it != appleQueue.end())
		{
			appleQueue.erase(apple_it);
		}
		else
		{
			snake.pop_front();
		}

		// 회전 판별
		if (snakeTurnQueue.empty() != true && second == snakeTurnQueue.front().first)
		{
			// 회전 방향 설정
			if (snakeTurnQueue.front().second == 'D')
			{
				moveidx = (moveidx + 1) % 4;
			}
			else if (snakeTurnQueue.front().second == 'L')
			{
				moveidx = (moveidx + 3) % 4;
			}
			snakeTurnQueue.pop();
		}
	}

	std::cout << second;

	return 0;
}