#include<iostream>
#include "./Memento.h"
#include "./ImageControl.h"
#include "ImageControlMemento.h"
using namespace std;

class Image{
private:
    ImageControl* mpImageControl = nullptr;
    string mGuid = "";
    string mPath = "";
public:
    Image(string path)
    {
        this->mPath = path;
        mpImageControl = new ImageControl
    }
}

int main()
{
    Image* images
}