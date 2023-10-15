#include "Memento.h"
#include "ImageControl.h"
using namespace std;
class ImageControlMemento : public Memento
{
private:
    int16_t mX;
    int16_t mY;
    uint16_t mRotation;
    uint16_t mWidth;
    uint16_t mHeight;
    ImageControl *mpImageControl = nullptr;

public:
    ImageControlMemento(ImageControl *pImgControl, int16_t x, int16_t y, uint16_t rotation, uint16_t width, uint16_t height)
    {
        this->mpImageControl = pImgControl;
        this->mX = x;
        this->mY = y;
        this->mWidth = width;
        this->mHeight = height;
        this->mRotation = rotation;
    }
    Memento *restore()
    {
        Memento *pImageControlSnapshot = mpImageControl->createSnapshot();
        mpImageControl->setX(this->mX);
        mpImageControl->setX(this->mY);
        mpImageControl->setX(this->mHeight);
        mpImageControl->setX(this->mWidth);
        mpImageControl->setX(this->mRotation);
        return pImageControlSnapshot;
    }
};