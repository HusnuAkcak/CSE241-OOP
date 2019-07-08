#include <iostream>
#include <vector>
#include "polygon.h"
#include "point2d.h"
#include "shape.h"
#include "circle.h"
#include "rectangle.h"
#include "triangle.h"

namespace geometrical {
    class PolygonVect:public Polygon {
    public:

        //CONSTRUCTORS
        PolygonVect(const vector<Point2D>& newPoints);
        PolygonVect(const Point2D& newPoint);
        PolygonVect(Shape* newShape);
        PolygonVect();

        //SETTERS AND GETTERS
        void setPolygonVect(const vector<Point2D>& newPoints);
        void setShape(Shape* newShape);
        void setPoint(const Point2D newPoint);
        void setCircle(Circle& newCircle);
        void setRectangle(Rectangle& newRectangle);
        void setTriangle(Triangle& newTriangle);
        const vector<Point2D>& getPolygon() const;
        int getSize() const;

        ostream& initSvgFile(ostream& outputStream);

        //OPERATOR OVERLOADINGS
        const Point2D& operator [] (int index) const throw(out_of_range);
        Point2D& operator [] (int index) throw(out_of_range);
        /////////////////////////////////////////////////////////////////////
        virtual double area()const override;     // area calculation.
        virtual double perimeter()const override;// perimeter calculation.
        
        virtual PolygonVect& operator ++() noexcept override;   // incr. shape pos. by 1
        virtual PolygonVect& operator --() noexcept override;   // decr. shape pos. by 1 
        virtual PolygonVect& operator ++(int) noexcept override;// incr. shape pos. by 1  
        virtual PolygonVect& operator --(int) noexcept override;// decr. shape pos. by 1          

        // print function, prints the shape in a svg file
        virtual ostream& print(ostream& outputStream) noexcept override; 
        friend ostream& operator <<(ostream& outputStream, PolygonVect& polygon);
        PolygonVect operator +(const PolygonVect& polygon2)noexcept;
        //OPERATOR OVERLOADINGS
        virtual bool operator == (const Shape& s2)const noexcept override;
        virtual bool operator != (const Shape& s2)const noexcept override;
        virtual bool operator <  (const Shape& s2)const noexcept override;
        virtual bool operator <= (const Shape& s2)const noexcept override;
        virtual bool operator >  (const Shape& s2)const noexcept override;
        virtual bool operator >= (const Shape& s2)const noexcept override;

    private:
        vector<Point2D>points;
    };
}// end of geometrical namespace