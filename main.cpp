#include <iostream>
#include <string>
using namespace std;

bool gameOver;
int height, width, px, py;
int GameMap[8][15] = {
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,1,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,1,0,1},
    {1,0,0,0,0,0,0,0,1,0,0,0,1,0,1},
    {1,0,0,1,0,0,0,0,1,0,0,0,0,0,1},
    {1,0,0,1,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,1,0,0,0,0,0,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

void lowerCase(string& strToConvert)
{
    for (unsigned int i = 0; i < strToConvert.length(); i++)
    {
        strToConvert[i] = tolower(strToConvert[i]);
    }
}
void Startup()
{
    gameOver = false;
    height = 8;
    width = 15;
    px = 3;
    py = 3;
}
void Print()
{
    // windows
    //system("cls");
    // unix
    system("clear");

    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            if (GameMap[y][x] == 1)
                cout << "#";
            else if (x == 0 || x == width-1)
                cout << "#";
            else if (y == py && x == px)
                cout << "P";
            else
                cout << " ";
        }
        cout << endl;
    }
}
bool Colission(int _y, int _x)
{
    if (GameMap[_y][_x] == 1)
    { return true; }
    else
    { return false; }
}
void Logic()
{
    string userInput;
    cout << "To move type W, A, S, or D. press Q to quit. Dont forget to press ENTER" << endl << ">  ";
    cin >> userInput;
    lowerCase(userInput);

    if (userInput == "q")
    { gameOver = true; }
    else if (userInput == "w")
    {
        if (!Colission(py-1, px))
        { py--; }
    }
    else if (userInput == "s")
    {
        if (!Colission(py+1, px))
        { py++; }
    }
    else if (userInput == "a")
    {
        if (!Colission(py, px-1))
        { px--; }
    }
    else if (userInput == "d")
    {
        if (!Colission(py, px+1))
        { px++; }
    }
}
int main()
{
    Startup();
    while (!gameOver)
    {
        Print();
        Logic();
    }
    exit(0);
}
