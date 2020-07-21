#include<iostream>
#include<string>
class Shape {
    public:
    Shape() {

    }

    virtual float area() =0;
    virtual int area(bool bFake) = 0;

    private:
    std::string shapeName;
};

class Rectangle { //: public Shape {
    public:
    Rectangle(int l, int b) {
        length.intSide = l;
        breadth.intSide = b;
    }

    Rectangle(float l, float b) {
        length.floatSide = l;
        breadth.floatSide = b;
    }

    virtual int area() {
        return length.intSide * breadth.intSide;
    }
    
    // can't override the return type
    // but this would fail during 
    virtual float area (bool bFake) {
        return length.floatSide * breadth.floatSide;
    }

    private:
    union {
        int intSide;
        float floatSide;
    } length, breadth;

};

int main(int argc, char **argv) {
    int areaInt=0; 
    float areaFloat=0;

    auto *rint = new Rectangle(10,30);
    auto *rfloat = new Rectangle(10.3f, 30.1f);
    areaInt = rint->area();
    areaFloat = rfloat->area(false);
    std::cout 
    << "Float Area " << areaFloat << "\n" 
    << "Area Int "   << areaInt << "\n";

    return 0;

}