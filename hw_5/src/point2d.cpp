#include <iostream>
#include <stdexcept>
#include "point2d.h"

using namespace std;

namespace geometrical {
    Point2D::Point2D(int newC, int newR) noexcept {
        setCol(newC);
        setRow(newR);
    }
    Point2D::Point2D()noexcept : c(0),r(0) {/*intentionally empty. */}

    //getters
    int 
    Point2D::getCol()const noexcept {
        return c;
    }
    int 
    Point2D::getRow()const noexcept {
        return r;
    }
    int 
    Point2D::getRotation() const noexcept {
        return rotation;
    }
    
    //setters
    void 
    Point2D::setCol(int newC) noexcept {
       newC>=0 ? c=newC : c=0;
    }
    void 
    Point2D::setRow(int newR) noexcept {
        newR>=0 ? r=newR : r=0;
    }
    void 
    Point2D::setRotation(int newRotation) noexcept {
        // newRotation is processec and it is gotten a degree btw 0 and 360;
        if(newRotation < 0) {
            newRotation = newRotation % 360;
            newRotation+=360;
        }
        else {
            newRotation = newRotation % 360;
        }

        rotation = newRotation;
        return;
    }

    // comperison operator overloadings.
    bool
    Point2D::operator ==(const Point2D& secPoint) noexcept{
        if(r == secPoint.r && c==secPoint.c)
            return true;
        else
            return false;
    }

    bool
    Point2D::operator !=(const Point2D& secPoint) noexcept{
        if((*this == secPoint) ==false)
            return true;
        else
            return false;
    }
    
    //post and pre increment, decrement operator overloadings.
    Point2D& 
    Point2D::operator ++ () noexcept { //prefix
        ++c;
        ++r;
        return *this;
    }
    Point2D 
    Point2D::operator ++ (int) noexcept { //postfix
        Point2D temp = *this; 
        ++(*this);
        return temp;
    }
    Point2D& 
    Point2D::operator -- () noexcept { //prefix
        if(c>0) 
            --c;
        if(r>0) 
            --r; 
        return *this;
    }
    Point2D 
    Point2D::operator -- (int) noexcept { //postfix
        Point2D temp = *this;
        --(*this);
        return temp;
    }
}