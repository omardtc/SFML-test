#ifndef grid_h
#define grid_h
#include <SFML/Graphics.hpp>
#include <vector>
using namespace std;
using namespace sf;

class Grid
{

private:
    vector<vector<int>> grid;
    vector<vector<int>> next;
    int rows, cols;
    int sizeX, sizeY;


public:
    Grid(int rows, int cols);
    Grid(int rows, int cols, int sizeX, int sizeY);
    
    void drawTo(RenderWindow &window);
    void click(int x, int y);
    void update();
    int contarVecinos(int x, int y);

};

#endif