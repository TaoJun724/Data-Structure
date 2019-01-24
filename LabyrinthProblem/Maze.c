#include "Maze.h"


int map[MAX_ROW][MAX_COL] = {
	{ 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 1, 1, 1, 0 },
	{ 0, 0, 1, 0, 1, 0 },
	{ 0, 0, 1, 1, 1, 0 },
	{ 0, 0, 1, 0, 1, 1 },
	{ 0, 0, 1, 0, 0, 0 },
};

int size = 0;


void  InitMaze(Maze* m)
{
	int i = 0;
	int j = 0;
	assert(m);
	for (i = 0; i < MAX_ROW; i++)
	{
		for (j = 0; j < MAX_COL; j++)
		{
			m->map[i][j] = map[i][j];
		}
	}
}

void  PrintfMaze(Maze* m)
{
	int i = 0;
	int j = 0;
	assert(m);
	for (i = 0; i < MAX_ROW; i++)
	{
		for (j = 0; j < MAX_COL; j++)
		{
			printf("%2d ", m->map[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}


int IsPass(Maze* m, Pos cur, Pos next)
{
	assert(m);
	if (((next.row >= 0 && next.row < MAX_COL) && (next.col >= 0 && next.col<MAX_COL)) &&
		((m->map[next.row][next.col] == 1) || (m->map[next.row][next.col] - 1 > m->map[cur.row][cur.col])))
	{
		return 1;
	}
	return 0;
}



void GetMazePath(Maze* m, Pos entry, Pos exit)
{
	Stack path;
	StackInit(&path);
	StackPush(&path, entry);
	m->map[entry.row][entry.col] = 2;
	while (StackEmpty(&path) != 0)
	{
		Pos cur = StackTop(&path);
		if (cur.col == MAX_COL - 1)
		{
			if (StackSize(&path) < size || size == 0)
			{
				size = StackSize(&path);
			}
		}
		Pos next;
		//上
		next = cur;
		next.row -= 1;
		if (IsPass(m, cur, next))
		{
			m->map[next.row][next.col] = m->map[cur.row][cur.col] + 1;
			StackPush(&path, next);
			continue;
		}
		//右
		next = cur;
		next.col += 1;
		if (IsPass(m, cur, next))
		{
			m->map[next.row][next.col] = m->map[cur.row][cur.col] + 1;
			StackPush(&path, next);
			continue;
		}

		//下
		next = cur;
		next.row += 1;
		if (IsPass(m, cur, next))
		{
			m->map[next.row][next.col] = m->map[cur.row][cur.col] + 1;
			StackPush(&path, next);
			continue;
		}
		//左
		next = cur;
		next.col -= 1;
		if (IsPass(m, cur, next))
		{
			m->map[next.row][next.col] = m->map[cur.row][cur.col] + 1;
			StackPush(&path, next);
			continue;
		}


		//回溯
		StackPop(&path);
	}

}


#include "Maze.h"


int main()
{
	Pos  enter, exit;
	enter.row = 5;
	enter.col = 2;
	exit.row = 4;
	exit.col = 5;
	Maze m;
	InitMaze(&m);
	PrintfMaze(&m);
	GetMazePath(&m, enter, exit);
	printf("最短迷宫的长度为%d\n", size);
	PrintfMaze(&m);
	system("pause");
	return 0;
}

