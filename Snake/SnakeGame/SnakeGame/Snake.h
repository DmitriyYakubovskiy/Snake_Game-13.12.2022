#include <iostream>
#include <conio.h>
#include <thread>
#include <Windows.h>
#include <ctime>

using namespace std;

const int width = 20;
const int hight = 10;
enum eDerection { STOP = 0, LEFT, RIGHT, UP, DOWN };


class Snake
{		
private:
	bool gameOver;
	int x, y, fruitX, fruitY, score;
	int nTail;
	int tailX[100], tailY[100];
	eDerection dir;
public:
	Snake()
	{
		srand(time(0));
		gameOver = false;
		x = width / 2 - 1, y = hight / 2 - 1, fruitX = 1+rand() % (width-2),
			fruitY =1+rand() % (hight-2), score = 0;
		nTail = 0;
		tailX[0] = x;
		tailY[0] = y;
		dir = STOP;
	}

    void SetColor(int text, int bg);

    void getDraw();

    void getInput();

    void getLogic();

	int getGameOver();
};

