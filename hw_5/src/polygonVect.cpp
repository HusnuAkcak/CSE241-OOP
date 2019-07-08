#include <iostream>
#include "polygon.h"
#include "polygonVect.h"
#include "point2d.h"
#include "math.h"
// #include "circle.h"
// #include "rectangle.h"
// #include "triangle.h"


using namespace std;

namespace {
  #define CIRCLE_POINT_COUNT 100.0
}

namespace geometrical {
    double
    PolygonVect::area()const {
        double x[points.size()];
        double y[points.size()];
        for(int i=0; i<points.size(); i++){
            x[i]=points[i].getCol();
            y[i]=points[i].getRow();
        }
        double totalArea=0;
        int j=points.size()-1;
        for (int i=0; i<points.size(); ++i) {
            totalArea+=((y[j]-y[i])*(x[i]+x[j]));
            j=i;
        }
        totalArea = abs(totalArea/2);
        return totalArea;
    }

    double
    PolygonVect::perimeter()const {
        double totalPerimeter=0;
        for(int i=0; i<points.size()-1; ++i) {
            totalPerimeter += calcDistBtwTwoPoint(points[i].getCol(), points[i+1].getCol(),
                                    points[i].getRow(),points[i+1].getRow());
        }
        totalPerimeter += calcDistBtwTwoPoint(points[points.size()-1].getCol(), points[0].getCol(),
                                        points[points.size()-1].getRow(),points[0].getRow());
        return totalPerimeter;
    }

    PolygonVect&
    PolygonVect::operator ++() noexcept {
        // cout<< size<<endl;
        for(int i=0; i<points.size(); ++i){
            // cout << "first::"<< points[i].getRow()<<endl;
            ++(points[i]);
            // cout << "sec::"<< points[i].getRow()<<endl;
        }
        return *this;
    }
    PolygonVect&
    PolygonVect::operator --() noexcept {
        for(int i=0; i<points.size(); ++i)
            ++(points[i]);
        return *this;
    }
    PolygonVect&
    PolygonVect::operator ++(int) noexcept {
        PolygonVect *temp = new PolygonVect(*this);
        for(int i=0; i<points.size(); ++i)
            ++(points[i]);
        return *temp;
    }
    PolygonVect&
    PolygonVect::operator --(int) noexcept {
        PolygonVect *temp = new PolygonVect(*this);
        for(int i=0; i<points.size(); ++i)
            ++(points[i]);
        return *temp;
    }

    //OPERATOR OVERLOADINGS
    bool
    PolygonVect::operator ==(const Shape& polygon2)const noexcept {
        return(area() == polygon2.area());
    }

    bool
    PolygonVect::operator !=(const Shape& polygon2)const noexcept {
        return (area() != polygon2.area());
    }

    bool
    PolygonVect::operator <  (const Shape& s2)const noexcept {
        return (area() < s2.area());
    }
    bool
    PolygonVect::operator <= (const Shape& s2)const noexcept {
        return (area() <= s2.area());
    }
    bool
    PolygonVect::operator >  (const Shape& s2)const noexcept {
        return (area() > s2.area());
    }
    bool
    PolygonVect::operator >= (const Shape& s2)const noexcept {
        return (area() >= s2.area());
    }

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

    /* Polgon class codes starts...                                             */

    PolygonVect::PolygonVect(const vector<Point2D>& newPoints) {
        setPolygonVect(newPoints);
    }

    PolygonVect::PolygonVect(const Point2D& newPoint) {
        setPoint(newPoint);
    }

    PolygonVect::PolygonVect(Shape *newShape) {
        setShape(newShape);
    }

    PolygonVect::PolygonVect( ) {
        /*intentionally empty */
    }

    void
    PolygonVect::setPolygonVect(const vector<Point2D>& newPoints) {
        points = newPoints;
        return;
    }

    void
    PolygonVect::setPoint(const Point2D newPoint) {
        points.push_back(newPoint);
        return;
    }

    void
    PolygonVect::setShape(Shape* newShape) {
        if(dynamic_cast<Circle*>(newShape)!=nullptr){
            setCircle(*(dynamic_cast<Circle*>(newShape)));
        }
        else if(dynamic_cast<Rectangle*>(newShape)!=nullptr){
            setRectangle(*(dynamic_cast<Rectangle*>(newShape)));
        }
        else if(dynamic_cast<Triangle*>(newShape)!=nullptr){
            setTriangle(*(dynamic_cast<Triangle*>(newShape)));
        }
    }

    void
    PolygonVect::setCircle(Circle& newCircle) {

        double radius = newCircle.getRadius();   // radius of the circle
        newCircle.setCenter(radius, radius);
        Point2D temp;

        int i=0;
        for ( double d =360.0/CIRCLE_POINT_COUNT;
            d<=360.1;
            d+=(360.0/CIRCLE_POINT_COUNT) ){

            temp.setCol(newCircle.getCenterCol() + radius*cos(d/RAD));
            temp.setRow(newCircle.getCenterRow() + radius*sin(d/RAD));
            points.push_back(temp);
            ++i;
        }
        return;
    }

    void
    PolygonVect::setRectangle(Rectangle& newRectangle) {

        Point2D temp;
        // for vertice of the rectangle is calculated and set.
        temp.setCol(newRectangle.getStartPointCol());
        temp.setRow(newRectangle.getStartPointRow());
        points.push_back(temp);
        temp.setCol(points[0].getCol() + newRectangle.getWidth());
        temp.setRow(points[0].getRow());
        points.push_back(temp);
        temp.setCol(points[1].getCol());
        temp.setRow(points[1].getRow() + newRectangle.getHeight());
        points.push_back(temp);
        temp.setCol(points[2].getCol() - newRectangle.getWidth());
        temp.setRow(points[2].getRow());
        points.push_back(temp);

        return;
    }

    void
    PolygonVect::setTriangle(Triangle& newTriangle) {

        Point2D temp,
                leftBtmNode, rightBtmNode; //left and right bottom node of triangle
        newTriangle.setPeakPoint(newTriangle.getEdge()/2, 0);


        newTriangle.calcTriangleBottomNodes(leftBtmNode, rightBtmNode);

        temp = newTriangle.getPeakPoint();
        temp.setRotation(newTriangle.getRotationAngle());
        points.push_back(temp);
        temp= leftBtmNode;
        points.push_back(temp);
        temp= rightBtmNode;
        points.push_back(temp);

        return;
    }

    const vector<Point2D>&
    PolygonVect::getPolygon() const {
        return points;
    }

    int
    PolygonVect::getSize() const {
        return points.size();
    }

    ostream&
    PolygonVect::initSvgFile(ostream& outputStream) {
        Point2D maxPoint;

        for(int i=0; i<points.size(); ++i) {
            if(points[i].getCol()>maxPoint.getCol())
                maxPoint.setCol(points[i].getCol());

            if(points[i].getRow()>maxPoint.getRow())
                maxPoint.setRow(points[i].getRow());
        }

        outputStream  << "<svg version=\"1.1\" baseProfile=\"full\" "
            << " width= \"" << maxPoint.getCol()*(1.5) << "\""
            << " height= \"" <<  maxPoint.getRow()*(1.5) << "\""
            << " xmlns=\"http://www.w3.org/2000/svg\"> "
            << endl << endl;

        return outputStream;
    }

    const Point2D&
    PolygonVect::operator [] (int index) const throw(out_of_range) {
        if(points.size()>= index){
            return points[index];
        }
        else{
            throw out_of_range("out of PolygonVect array\n");
        }
    }

    Point2D&
    PolygonVect::operator [] (int index) throw(out_of_range) {
        if(points.size()>= index){
            return points[index];
        }
        else{
            throw out_of_range("out of PolygonVect array\n");
        }
    }


    PolygonVect
    PolygonVect::operator +(const PolygonVect& polygon2) noexcept {
        PolygonVect temp;
        temp = points;

        for(int i = 0; i<polygon2.points.size(); ++i)
            temp.points.push_back(polygon2[i]);

        return temp;
    }

    ostream&
    operator <<(ostream& outputStream, PolygonVect& polygon) {
        polygon.initSvgFile(outputStream);
        polygon.print(outputStream);
        outputStream << "</svg>";
        return outputStream;
    }

    // print function, prints the shape in a svg file
    ostream&
    PolygonVect::print(ostream& outputStream) noexcept {
        Point2D rotationPoint; //we assume there is only one point to use as a pivot while rotation
        // cout << "I am in print, size :"<<size<<endl;
        outputStream << "  <polygon points= \"";
        for (int i=0; i< points.size(); ++i) {
            outputStream << points[i].getCol()<< ", "<< points[i].getRow()<< " ";

            if(points[i].getRotation()>0) // if it is rotation point.
                rotationPoint = points[i];
        }

        outputStream  << "\" transform = \"rotate("
                      << rotationPoint.getRotation() << " "
                      << rotationPoint.getCol()      << " "
                      << rotationPoint.getRow()      << ")\""
                      << " stroke = \"black\" stroke-width=\"1\" ";
        if(points.size()>=3){
            outputStream << " fill=\"rgb(" << points[0].getCol()%255
                                     << ", " << points[1].getCol()%155
                                     << ", " << points[2].getCol()%55 <<")\"/> \n";
        }
        else {
            outputStream << "fill = \"rgb(240,50,120)\"/> \n";
        }
        return outputStream;
    }

  /* Polgon class codes ends...                                               */
}
