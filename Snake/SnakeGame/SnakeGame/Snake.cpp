#include "Snake.h"
#include <conio.h>
#include <thread>
#include <Windows.h>
#include <iostream>
#include <ctime>

using namespace std;

void Snake::SetColor(int text, int bg)
{
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdOut, (WORD)((bg << 4) | text));
}

void Snake::getDraw()
{
    system("cls");
    cout << endl;
    for (int i = 0; i < hight; i++)
    {
        for (int j = 0; j < width; j++)
        {            

           if (i == fruitY && j == fruitX)
            {
                SetColor(4, 0);
                cout << "O";
                SetColor(3, 0);
            }             
           else if (i == y && j == x)
            {
                SetColor(2, 0);
                cout << "0";
                SetColor(3, 0);
            }
            else if (j == 0 || j == width-1 || i == 0 || i == hight-1)
            {
                cout << "#";
            }
            else
            {
                bool print = false;
                for (int k = 0; k < nTail; k++)
                {
                    if (tailX[k] == j && tailY[k] == i)
                    {
                        SetColor(2, 0);
                        print = true;
                        cout << "o";
                        SetColor(3, 0);
                    }
                }
                if (!print)
                {
                    cout << " ";
                }
            }
        }
        cout << endl;
    }

    cout << endl << endl;
    SetColor(14, 0);
    cout << "Score: " << score << endl;
    SetColor(3, 0);
    this_thread::sleep_for(190ms);
}

void Snake::getInput()
{            
    if (_kbhit())
    {
        switch (_getch())
        {

        case 'a':
            if (dir != RIGHT)
                dir = LEFT;
            break;
        case 's':
            if (dir != UP)
                dir = DOWN;
            break;
        case 'd':
            if (dir != LEFT)
                dir = RIGHT;
            break;
        case 'w':
            if (dir != DOWN)
                dir = UP;
            break;
        case 'x':
            gameOver = true;
            break;
        }
    }
}

void Snake::getLogic()
{
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = x;
    tailY[0] = y;
    for (int i = 1; i < nTail; i++)
    {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }

    switch (dir)
    {
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    case UP:
        y--;
        break;
    case DOWN:
        y++;
        break;
    }

    if (x > width-2)
    {
        x = 1;
    }
    else if (x < 1)
    {
        x = width - 2;
    }
    if (y > hight-2)
    {
        y = 1;
    }
    else if (y <1)
    {
        y = hight - 2;
    }

    for (int i = 0; i < nTail; i++)
    {
        if (tailX[i] == x && tailY[i] == y)
        {
            gameOver = true;
        }
    }

    if (x == fruitX && y == fruitY)
    {

        score += 10;
        fruitX =1+ rand() % (width - 2);
        fruitY =1+ rand() % (hight - 2);
        for (int i = 0; i < nTail; i++)
        {
            if ((fruitX == tailX[i] && fruitY == tailY[i]) || (fruitX == x && fruitY == y))
            {
                fruitX = 1 + rand() % (width - 2);
                fruitY = 1 + rand() % (hight - 2);
                i = 0;
            }
        }
        nTail++;
    }
}


int Snake::getGameOver()
{
    return gameOver;
}
