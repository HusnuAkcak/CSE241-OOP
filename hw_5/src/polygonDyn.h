#include <iostream>
#include <vector>
#include "polygon.h"
#include "point2d.h"
#include "shape.h"
#include "circle.h"
#include "rectangle.h"
#include "triangle.h"

namespace geometrical {
    class PolygonDyn :public Polygon {
    public:

        //CONSTRUCTORS
        PolygonDyn(const vector<Point2D>& newPoints);
        PolygonDyn(const Point2D& newPoint);
        PolygonDyn(Shape* newShape);
        PolygonDyn();

        //BIG THREE
        PolygonDyn(const PolygonDyn &newPolygon);
        PolygonDyn& operator = (const PolygonDyn &newPolygon);
        ~PolygonDyn();

        //SETTERS AND GETTERS
        void setSize(int newSize);
        void setPolygonDyn(const vector<Point2D>& newPoints);
        void setShape(Shape* newShape);
        void setPoint(const Point2D newPoint);
        void setCircle(Circle& newCircle);
        void setRectangle(Rectangle& newRectangle);
        void setTriangle(Triangle& newTriangle);
        Point2D* getPolygon() const;
        int getSize() const;

        ostream& initSvgFile(ostream& outputStream);

        //OPERATOR OVERLOADINGS
        const Point2D& operator [] (int index) const throw(out_of_range);
        Point2D& operator [] (int index) throw(out_of_range);
        /////////////////////////////////////////////////////////////////////
        virtual double area()const override;     // area calculation.
        virtual double perimeter()const override;// perimeter calculation.

        virtual PolygonDyn& operator ++() noexcept override;   // incr. shape pos. by 1
        virtual PolygonDyn& operator --() noexcept override;   // decr. shape pos. by 1
        virtual PolygonDyn& operator ++(int) noexcept override;// incr. shape pos. by 1
        virtual PolygonDyn& operator --(int) noexcept override;// decr. shape pos. by 1

        // print function, prints the shape in a svg file
        virtual ostream& print(ostream& outputStream) noexcept override;
        friend ostream& operator <<(ostream& outputStream, PolygonDyn& polygon);
        PolygonDyn operator +(const PolygonDyn& polygon2)noexcept;
        //OPERATOR OVERLOADINGS
        virtual bool operator == (const Shape& s2)const noexcept override;
        virtual bool operator != (const Shape& s2)const noexcept override;
        virtual bool operator <  (const Shape& s2)const noexcept override;
        virtual bool operator <= (const Shape& s2)const noexcept override;
        virtual bool operator >  (const Shape& s2)const noexcept override;
        virtual bool operator >= (const Shape& s2)const noexcept override;

    private:
        Point2D *points=nullptr;
        int size=0;
    };
}// end of geometrical namespace
