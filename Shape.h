/***************************************************************
 * Name:      Shape.h
 * Purpose:   The class is intended for the creation of tetris figures
 * Author:    Kondratyuk Vadim (kvadiml256@gmail.com)
 * Created:   2019-03-15
 * Copyright: Kondratyuk Vadim (github.com/vadim256)
 * License:   GNU General Public License 3.0
 **************************************************************/

#pragma once
#include <array>

struct Shape {
    enum class Tetrominoes : unsigned {
        NoShape = 0, ZShape, SShape, LineShape, 
        TShape, SquareShape, LShape, MirroredLShape
    };
    static const int Rows = 4,
                     Cols = 2,
                     NShapes = 8;

    using IntArr = std::array<int, Cols>;
    using Array2d = std::array<IntArr, Rows>;
    
    Shape();
    ~Shape() = default;

    void SetShape(Tetrominoes shape);
    void SetRandomShape();
    Tetrominoes GetShape() const;

    int x(int index) const;
    int y(int index) const;

    int MinX() const;
    int MaxX() const;
    int MinY() const;
    int MaxY() const;

    Shape RotateLeft() const;
    Shape RotateRight() const;
    
    private:
    void SetX(int index, int x);
    void SetY(int index, int y);

    Tetrominoes pieceShape;
    Array2d coord;

};