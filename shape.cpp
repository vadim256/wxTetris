#include "shape.h"
#include <cstdlib>
#include <algorithm>

Shape::Shape() {
    SetShape(Tetrominoes::NoShape);
}

Shape::~Shape(){ }

Shape::Tetrominoes Shape::GetShape() const {
    return pieceShape;
}

void Shape::SetShape(Tetrominoes shape) {
    using std::array;
    static const array<array<array<short, 2>, 4>, 8> coordsTable {
        array<array<short, 2>, 4>({0,0}, {0,0}, {0,0}, {0,0}),
        array<array<short, 2>, 4>({0,-1}, {0,0}, {-1,0}, {-1,1}),
        array<array<short, 2>, 4>({0,-1}, {0,0}, {1,0}, {1,1}),
        array<array<short, 2>, 4>({0,-1}, {0,0}, {0,1}, {0,1}),
        array<array<short, 2>, 4>({-1,0}, {0,0}, {1,0}, {0,1}),
        array<array<short, 2>, 4>({0, 0}, {1,0}, {0,1}, {1,1}),
        array<array<short, 2>, 4>({-1,-1}, {0,-1}, {0,0}, {0,1}),
        array<array<short, 2>, 4>({1,-1}, {0,-1}, {0,0}, {0,1})
    };
    for(int i = 0; i < 4; ++i){
        for(int j = 0; j < 2; ++j){
            coord[i][j] = coordsTable[static_cast<int>(shape)][i][j];
        }
    }
    pieceShape = shape;
}

void Shape::SetRandomShape(){
    auto index = std::rand()%7+1;
    this->SetShape(Tetrominoes(index));
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