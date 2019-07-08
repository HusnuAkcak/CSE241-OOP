#ifndef _SHAPE_H_
#define _SHAPE_H_

#include <iostream>
#include <memory>
#include <vector>

using namespace std;

// two of global functions are at the end of this file (printAll, sortShapes).
namespace geometrical {
    #define PI 3.14159265359
    #define RAD 57.2958
    #define DEG 1/RAD

    class container_unavailable: public exception {/*intentionally empty*/};
    class smallShape_unavailable: public exception {/*intentionally empty*/};

    class Shape {
    public:
        // I do not declare a constructor, because there is no member variable.


        // print function, prints the shape in a svg file
        virtual ostream& print(ostream& outputStream)noexcept=0;
        virtual Shape& operator ++() noexcept =0;   // incr shape pos by 1
        virtual Shape& operator --() noexcept =0;   // decr shape pos by 1
        virtual Shape& operator ++(int) noexcept =0;// incr shape pos by 1
        virtual Shape& operator --(int) noexcept =0;// decr shape pos by 1

        virtual double area()const=0;       // area calculation.
        virtual double perimeter()const=0;  // perimeter calculation.

        // comperison operators.
        virtual bool operator == (const Shape& s2)const noexcept;
        virtual bool operator != (const Shape& s2)const noexcept;
        virtual bool operator <  (const Shape& s2)const noexcept;
        virtual bool operator <= (const Shape& s2)const noexcept;
        virtual bool operator >  (const Shape& s2)const noexcept;
        virtual bool operator >= (const Shape& s2)const noexcept;
    };

    //GLOBAL FUNCTIONS (TWO OF THEM) STARTS
    void printAll(const vector<Shape*>& shapes) noexcept;
    void sortShapes(vector<Shape*>& shapes)noexcept;
    //GLOBAL FUNCTIONS (TWO OF THEM) ENDS
}
#endif
