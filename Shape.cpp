/***************************************************************
 * Name:      Shape.cpp
 * Purpose:   The class is intended for the creation of tetris figures
 * Author:    Kondratyuk Vadim (kvadiml256@gmail.com)
 * Created:   2019-03-15
 * Copyright: Kondratyuk Vadim (github.com/vadim256)
 * License:   GNU General Public License 3.0
 **************************************************************/

#include "Shape.h"
#include <cstdlib>
#include <algorithm>

const int Shape::Rows;
const int Shape::Cols;
const int Shape::NShapes;

Shape::Shape() {
    SetShape(Tetrominoes::NoShape);
}

Shape::Tetrominoes Shape::GetShape() const {
    return pieceShape;
}

void Shape::SetShape(Tetrominoes shape) {
    
    static const int coordsTable[NShapes][Rows][Cols] = {
        {{0,0},{0,0},{0,0},{0,0}},
        {{0,-1},{0,0},{-1,0},{-1,1}},
        {{0,-1},{0,0},{1,0},{1,1}},
        {{0,-1},{0,0},{0,1},{0,1}},
        {{-1,0},{0,0},{1,0},{0,1}},
        {{0,0},{1,0},{0,1},{1,1}},
        {{-1,-1},{0,-1},{0,0},{0,1}},
        {{1,-1},{0,-1},{0,0},{0,1}}
    };

    for(int x = 0; x < Rows; ++x){
        for(int y = 0; y < Cols; ++y){
            coord[x][y] = coordsTable[static_cast<int>(shape)][x][y];
        }
    }
    pieceShape = shape;
}

void Shape::SetRandomShape(){
    using std::rand;
    auto select_shape = rand()%7+1;
    this->SetShape(Tetrominoes(select_shape));
}

int Shape::x(int index) const {
    return coord[index][0];
}

int Shape::y(int index) const {
    return coord[index][1];
}

void Shape::SetX(int index, int x) {
    coord[index][0] = x;
}

void Shape::SetY(int index, int y) {
    coord[index][1] = y;
}

Shape Shape::RotateLeft() const {
    if(pieceShape == Tetrominoes::SquareShape)
        return *this;

    Shape result;
    result.pieceShape = this->pieceShape;
    for(int index = 0; index < 4; ++index){
        result.SetX(index, this->y(index));
        result.SetY(index, -(this->x(index)));
    }
    return result;
}

Shape Shape::RotateRight() const {
    if(pieceShape == Tetrominoes::SquareShape) 
        return *this;

    Shape result;
    result.pieceShape = this->pieceShape;
    for(int index = 0; index < 4; ++index){
        result.SetX(index, -(this->y(index)));
        result.SetY(index, this->x(index));
    }
    return result;
}

int Shape::MinX() const { 
    using std::min;
    auto tmp = coord[0][0];
    for(int index = 0; index < 4; ++index)
        tmp = min(tmp, coord[index][0]);
    return tmp;
}

int Shape::MaxX() const { 
    using std::max;
    auto tmp = coord[0][0];
    for(int index = 0; index < 4; ++index)
        tmp = max(tmp, coord[index][0]);
    return tmp;
}

int Shape::MinY() const { 
    using std::min;    
    auto tmp = coord[0][1];
    for(int index = 0; index < 4; ++index)
        tmp = min(tmp, coord[index][1]);
    return tmp;
}

int Shape::MaxY() const { 
    using std::max;
    auto tmp = coord[0][1];
    for(int index = 0; index < 4; ++index)
        tmp = max(tmp , coord[index][1]);
    return tmp;
}