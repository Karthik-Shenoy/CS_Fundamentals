#include "IShape.h"

class IVisitor 
{
public:
    virtual void visit(IShape shape) = 0;
};