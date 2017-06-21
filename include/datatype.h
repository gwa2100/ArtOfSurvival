#ifndef DATATYPE_H_INCLUDED
#define DATATYPE_H_INCLUDED

enum GameEvents:unsigned int { moveUp, moveDown, moveLeft, moveRight, exitGame, die, show, hide};

class Int2D
{
public:
    Int2D()
    {

    };
    Int2D(int pX, int pY)
    {
        x = pX;
        y = pY;
    };
    Int2D operator=(const Int2D& b)
    {
        Int2D int2d;
        int2d.x = this->x;
        int2d.y = this->y;
        return int2d;
    };
    Int2D operator+(const Int2D& b)
    {
        Int2D int2d;
        int2d.x = this->x + b.x;
        int2d.y = this->y + b.y;
        return int2d;
    };
    Int2D operator-(const Int2D& b)
    {
        Int2D int2d;
        int2d.x = this->x - b.x;
        int2d.y = this->y - b.y;
        return int2d;
    };
    int x;
    int y;
};

class Float2D
{
public:
    Float2D();
    Float2D(float pX, float pY)
    {
        x = pX;
        y = pY;
    }

    float x;
    float y;
};


#endif // DATATYPE_H_INCLUDED
