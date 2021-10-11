#include <iostream>
#include <queue>
using namespace std;

#define TOP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3

void initialize(char*, int);
int index(int, int, int);
int checkBoard(int, int, int);
void draw(char*, int n);
void generateMaze(char* ,int, int, int);
void findPathBFS(char*, int);

void createMaze2D(int);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	srand((unsigned)time(NULL));

	int n = 13;
	createMaze2D(n);

	return 0;
}

void initialize(char* board, int n)
{
	for (int i = 0; i < n * n; i++)
	{
		board[i] = '*';
	}
}

int index(int x, int y, int n)
{
	return y * n + x;
}

int checkBoard(int x, int y, int n)
{
	if (x < 0 || x >= n) return false;
	if (y < 0 || y >= n) return false;
	return true;
}

void draw(char* board, int n)
{
	for (int y = 0; y < n; ++y)
	{
		for (int x = 0; x < n; ++x)
		{
			cout << board[index(x, y, n)];
		}
		cout << "\n";
	}
}

void generateMaze(char* board, int n, int x, int y)
{
	board[index(x, y, n)] = ' ';

	int direction[4];
	direction[0] = TOP;
	direction[1] = RIGHT;
	direction[2] = DOWN;
	direction[3] = LEFT;

	for (int i = 0; i < 4; ++i)
	{
		int random = rand() % 4;
		int temp = direction[random];
		direction[random] = direction[i];
		direction[i] = temp;
	}

	for (int i = 0; i < 4; ++i)
	{
		int dx = 0, dy = 0;
		switch (direction[i])
		{
		case TOP: dy = -1; break;
		case DOWN: dy = 1; break;
		case RIGHT: dx = 1; break;
		case LEFT: dx = -1; break;
		}

		int x2 = x + (dx << 1);
		int y2 = y + (dy << 1);

		if (checkBoard(x2, y2, n) && board[index(x2, y2, n)] == '*')
		{
			board[index(x2 - dx, y2 - dy, n)] = ' ';
			generateMaze(board, n, x2, y2);
		}
	}
}

void findPathBFS(char* board, int n)
{
	queue<pair<int, int>> _queue;
	pair<int, int> current;

	_queue.push({ 1,1 });
	board[index(1, 1, n)] = 'A';

	bool* visited = new bool[(n * n)]();
	for (int i = 0; i < n * n; i++) visited[i] = false;
	
	const int dx[4] = { 0, 0, 1, -1 };
	const int dy[4] = { 1, -1, 0, 0 };

	while (!_queue.empty())
	{
		current = _queue.front();
		_queue.pop();

		visited[index(current.first, current.second, n)] = true;
		for (int i = 0; i < 4; ++i)
		{
			int nx = dx[i] + current.first;
			int ny = dy[i] + current.second;

			if (nx >= 0 && nx < n && ny >= 0 && ny < n && visited[index(nx, ny, n)] == false && board[index(nx, ny, n)] != '*')
			{
				_queue.push({ nx, ny });
			}
		}
	}

	board[index(current.first, current.second, n)] = 'B';

}

void createMaze2D(int n)
{
	if (n % 2 == 0) n++;
	char* board = new char[(n * n)]();

	initialize(board, n);
	generateMaze(board, n, 1, 1);
	findPathBFS(board, n);
	draw(board, n);
}
