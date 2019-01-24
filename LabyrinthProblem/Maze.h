#ifndef   __MAZE_H__
#define   __MAZE_H__


#include "Stack.h"


#define MAX_ROW 6
#define MAX_COL 6


typedef  struct Maze
{
	int  map[MAX_ROW][MAX_COL];
}Maze;




void  InitMaze(Maze* m);
void  PrintfMaze(Maze* m);
//�жϵ�ǰ�ⲽ�ܷ���ͨ
int IsPass(Maze* m, Pos cur, Pos next);
//���Թ�
void MazePath(Maze* m, Pos enter, Pos exit);
void text();


#endif
