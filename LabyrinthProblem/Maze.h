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
//判断当前这步能否走通
int IsPass(Maze* m, Pos cur, Pos next);
//走迷宫
void MazePath(Maze* m, Pos enter, Pos exit);
void text();


#endif
