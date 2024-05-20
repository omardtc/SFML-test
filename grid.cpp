#include "grid.hpp"

Grid::Grid(int rows, int cols)
{
    for(int i = 0; i < rows; i++)
    {
        this->rows = rows;
        this->cols = cols;
        
        this->grid.push_back({});
        for (int j = 0; j < cols; j++)
        {
            this->grid[i].push_back(0);
        }
    }
    this->next = vector<vector<int>>(rows, vector<int>(cols, 0));
}

Grid::Grid(int rows, int cols, int sizeX, int sizeY)
{
    for(int i = 0; i < rows; i++)
    {
        this->rows = rows;
        this->cols = cols;
        this->sizeX = sizeX / cols;
        this->sizeY = sizeY / rows;

        this->grid.push_back({});
        for (int j = 0; j < cols; j++)
        {
            this->grid[i].push_back(0);
        }
    }
    this->next = vector<vector<int>>(rows, vector<int>(cols, 0));


}

void Grid::drawTo(RenderWindow &window)
{
    for(int i = 0; i < rows; i++)
    {
        
        for (int j = 0; j < cols; j++)
        {
            
            RectangleShape rect(Vector2f(this->sizeX, this->sizeY));
            rect.setOutlineColor(Color::Black);
            rect.setFillColor(Color::Blue);
            rect.setOutlineThickness(1);
            rect.setPosition(Vector2f(j*this->sizeX, i*this->sizeY));
            if(grid[j][i]==0)
                rect.setFillColor(Color::Blue);
            if(grid[j][i]==1)
                rect.setFillColor(Color::Cyan);
            window.draw(rect);
            /**
             * crear cuadrado (RectangleShape)
             * Outline thickness y color
             * Posicion en lugar correspondiente
             * 
            */
           
        }
    }
}

void Grid::click(int x, int y)
{
    int indexX = x /this->sizeX;
    int indexY = y /this->sizeY;
    grid[indexX][indexY] = (grid[indexX][indexY]+1)%2;

    
}

void Grid::update()
{
    for (int i = 0; i < this->rows; i ++)
    {
        for (int j = 0; j < this->cols; j++)
        {
            //si esta activa
            if (this->grid[i][j] == 1)
            {
                if(j == this->cols-1) //si esta abajo
                {
                    this->next[i][j] = 1;
                }

                else

                {
                    if(this->grid[i][j+1] == 0)
                    {
                        this->next[i][j+1] = 1;
                        this->next[i][j] = 0;
                    }

                    else
                    
                    {
                        this->next[i][j] = 1;
                    }
                }
                

            }
        }
    }
    this->grid = this->next;
}