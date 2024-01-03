#include "../Visitors/IVisitor.h"

class IShape
{
public:
    virtual void moveTo(short x, short y) = 0;
    virtual void draw() = 0;
    virtual void acceptAndVisit(IVisitor visitor) = 0;
};