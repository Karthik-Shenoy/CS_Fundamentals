#include "./IShape.h"
#include "../Visitors/IVisitor.h"
#include <iostream>
using namespace std;

class Circle : public IShape
{
    int mX, mY, mR;
public:
    Circle(int x, int y, int r)
    {
        this->mX = x;
        this->mY = y;
        this->mR = r;
    }
    void draw()
    {
        // copying to variables with simple names
        int x = mX, y = mY;
        cout << "\nDRAWING THE Circle in CLOCKWISE DIRECTION";
        cout << "\n-------------------------------------------------\n"
        cout << "drawing a circle with (" << x << ", " << y << ") as the center and " << this->mR << "as the radius";
    }
    void moveTo(int x, int y)
    {
        cout << "\nErasing The Circle";
        cout << "\n-------------------------------------------------\n"
        cout << "erasing the area (" << x - r << ", " << y - r << "} to (" << x + r << ", " << y + r << ")\n";
        cout << "\n-------------------------------------------------\n"
        this->mX = x;
        this->my = y
        this->draw();
    }
    void acceptAndVisit(IVisitor visitor)
    {
        visitor.visitCircle(this);
    }
};
