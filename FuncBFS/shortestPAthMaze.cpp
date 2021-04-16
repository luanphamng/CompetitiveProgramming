#include <bits/stdc++.h>

using namespace std;

#define ROW 9
#define COL 10

struct Point
{
	int x;
	int y;
};

struct queueNode
{
	Point pt;
	int dist; // // cell's distance of from the source
};

bool isValid(int row, int col)
{
	return (row < ROW) && (row >= 0) && (col >= 0) && (col < COL);
}

int rowNum[] = {-1, 0, 0, 1};
int colNum[] = {0, -1, 1, 0};

int BFS(int mat[][COL], Point src, Point dest)
{
	/* check stop if no valid */
	if (mat[src.x][src.y] == 'X' || mat[dest.x][dest.y] == 'X') {
		return -1;
	}
	/* mark current source cell as visited */
	bool visited[ROW][COL];
	memset(visited, false, sizeof visited);
	visited[src.x][src.y] = true;

	queueNode s = {src, 0};
	queue<queueNode> q;
	q.push(s);

	/* while loop */
	while (!q.empty()) {
		queueNode curr = q.front();
		Point pt = curr.pt;

		if ((pt.x == dest.x) && (pt.y == dest.y)) {
			return curr.dist;
		}

		// remove it
		q.pop();

		// look at 4 neighbor 
		for (int i = 0; i < 4; i++) {
			int neighborRow = pt.x + rowNum[i];
			int neighborCol = pt.y + colNum[i];
			if (isValid(neighborCol, neighborCol) && (mat[neighborRow][neighborCol] == 1) && !visited[neighborRow][neighborCol]) {
				visited[neighborRow][neighborCol] = true;
				queueNode neighborCell = {{neighborRow, neighborCol}, curr.dist + 1};
				q.push(neighborCell);
			}
		}
	}
	return -1;
}

int main() {
	int mat[ROW][COL] =
    {
        { 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
        { 1, 0, 1, 0, 1, 1, 1, 0, 1, 1 },
        { 1, 1, 1, 0, 1, 1, 0, 1, 0, 1 },
        { 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 },
        { 1, 1, 1, 0, 1, 1, 1, 0, 1, 0 },
        { 1, 0, 1, 1, 1, 1, 0, 1, 0, 0 },
        { 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
        { 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
        { 1, 1, 0, 0, 0, 0, 1, 0, 0, 1 }
    };
 
    Point source = {0, 0};
    Point dest = {3, 4};
 
    int dist = BFS(mat, source, dest);
 
    if (dist != -1)
        cout << "Shortest Path is " << dist ;
    else
        cout << "Shortest Path doesn't exist";
 
    return 0;
}