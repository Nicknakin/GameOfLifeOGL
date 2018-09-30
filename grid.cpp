#include "grid.h"
#include <algorithm>

Grid::Grid(int width, int height, int side, sf::Color defaultColor): width{width}, height{height}, side{side}, defaultColor{defaultColor} {
    inChanged.resize(width*height);
    for(int i = 0; i < width*height; i++){
        cells.push_back(Cell{i%width, i/width, side, side, (float) defaultColor.r, (float) defaultColor.g, (float) defaultColor.b});
    }
}

Cell& Grid::getChangedCell(int i){
    return cells[changedCells[i]];
}

void Grid::popChangedCell(){
    if(changedCells[0] != NULL && changedCells[0] > 0 && changedCells[0] < size())
        inChanged[changedCells[0]] = false;
    changedCells.erase(changedCells.begin(), changedCells.begin()+1);
}

int Grid::getChangedCellSize(){
    return changedCells.size();
}

int Grid::size(){
    return height*width;
}

int Grid::getHeight(){
    return height;
}

int Grid::getWidth(){
    return width;
}

Cell& Grid::getCell(int x, int y){
    return cells[x+y*width];
}

Cell& Grid::getCell(int oneDIndex){
    return cells[oneDIndex];
}

sf::Color Grid::getDefaultColor(){
    return defaultColor;
}

std::vector<Cell>& Grid::getCells(){
    return cells;
}

void Grid::setColor(int x, int y, int r, int g, int b){
    cells[x+width*y].setFillColor(sf::Color{r,g,b});
}

void Grid::setColor(int x, int y, sf::Color color){
    cells[x+width*y].setFillColor(color);
}

std::vector<Cell> Grid::operator[](int i){
    return std::vector<Cell>{cells.begin()+i*width, cells.begin()+(i+1)*width};
}

void Grid::change(int x, int y){
    if(!changedCells.empty() || !inChanged[x+y*width]){
        changedCells.push_back(x+y*width);
        inChanged[x+y*width] = true;
    }
}

void Grid::change(int ind){
    if(changedCells.empty() || !inChanged[ind]){
        changedCells.push_back(ind);
        inChanged[ind] = true;
    }
}
