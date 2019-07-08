#ifndef _POINT2D_H_
#define _POINT2D_H_
#include <stdexcept>


namespace geometrical { 
    class Point2D {
    public:
        //constructors.
        Point2D(int newC, int newR) noexcept;
        Point2D() noexcept;

        //getters
        int getCol()const noexcept;
        int getRow()const noexcept;
        int getRotation() const noexcept;

        //setters
        void setCol(int newC) noexcept;
        void setRow(int newR) noexcept;
        void setRotation(int newRotation) noexcept;

        // post and pre increment, decrement operator overloadings        
        Point2D& operator ++ () noexcept; //prefix
        Point2D operator ++ (int) noexcept; //postfix
        Point2D& operator -- () noexcept; //prefix
        Point2D operator -- (int) noexcept; //postfix

        bool operator ==(const Point2D& secPoint)noexcept;  
        bool operator !=(const Point2D& secPoint)noexcept;
    private:
        int r=0,c=0;    // position as row and column.
        int rotation =0;//rotaiton degree about the point.
    };
}
#endif // end of Point2d class 