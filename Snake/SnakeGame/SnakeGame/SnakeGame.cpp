//я люблю димочку
//print('hello world')
#include "Snake.h"

using namespace std;

int main()
{
    Snake games{};
    while (!games.getGameOver())
    {
        games.getDraw();
        games.getInput();
        games.getLogic();
    }
    return 0;
}
