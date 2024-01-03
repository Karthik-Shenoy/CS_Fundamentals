#include "./IShape.h"

class Square : public IShape {
    int mX = 0, mY = 0;
    int mW = 0, mH = 0;
public:
    Square(int x, int y, int w, int h)
    {
        mX = x;
        mY = y;
        mW = w;
        mH = h;
    }
    void draw()
    {
        // copying to variables with simple names
        int x = mX, y = mY;
        cout << "\nDRAWING THE SQUARE in ANTI CLOCKWISE DIRECTION";
        cout << "\n-------------------------------------------------\n"
        cout << "drawing line from (" << x << ", " << y << "} to (" << x << ", " << y + h << ")\n";
        cout << "drawing line from (" << x << ", " << y+h << "} to (" << x + w << ", " << y + h << ")\n";
        cout << "drawing line from (" << x + w << ", " << y + h << "} to (" << x + w << ", " << y << ")\n";
        cout << "drawing line from (" << x + w << ", " << y  << "} to (" << x << ", " << y << ")\n";
    }
    void moveTo(int x, int y)
    {
        cout << "\nErasing The Square";
        cout << "\n-------------------------------------------------\n"
        cout << "erasing the area (" << x << ", " << y << "} to (" << x + w << ", " << y + h << ")\n";
        cout << "\n-------------------------------------------------\n"
        this->mX = x;
        this->my = y
        this->draw();
    }
    void acceptAndVisit(IVisitor visitor)
    {
        visitor.visitSquare(this)
    }

};