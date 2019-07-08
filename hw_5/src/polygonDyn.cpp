#include <iostream>
#include "polygon.h"
#include "polygonDyn.h"
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
    PolygonDyn::area()const {
        double x[size];
        double y[size];
        for(int i=0; i<size; i++){
            x[i]=points[i].getCol();
            y[i]=points[i].getRow();
        }
        double totalArea=0;
        int j=size-1;
        for (int i=0; i<size; ++i) {
            totalArea+=((y[j]-y[i])*(x[i]+x[j]));
            j=i;
        }
        totalArea = abs(totalArea/2);
        return totalArea;
    }

    double
    PolygonDyn::perimeter()const {
        double totalPerimeter=0;
        for(int i=0; i<size-1; ++i) {
            totalPerimeter += calcDistBtwTwoPoint(points[i].getCol(), points[i+1].getCol(),
                                        points[i].getRow(),points[i+1].getRow());
        }
        totalPerimeter += calcDistBtwTwoPoint(points[size-1].getCol(), points[0].getCol(),
                                        points[size-1].getRow(),points[0].getRow());
        return totalPerimeter;
    }

    PolygonDyn&
    PolygonDyn::operator ++() noexcept {
        // cout<< size<<endl;
        for(int i=0; i<size; ++i){
            // cout << "first::"<< points[i].getRow()<<endl;
            ++(points[i]);
            // cout << "sec::"<< points[i].getRow()<<endl;
        }
        return *this;
    }
    PolygonDyn&
    PolygonDyn::operator --() noexcept {
        for(int i=0; i<size; ++i)
            ++(points[i]);
        return *this;
    }
    PolygonDyn&
    PolygonDyn::operator ++(int) noexcept {
        PolygonDyn *temp = new PolygonDyn(*this);
        for(int i=0; i<size; ++i)
            ++(points[i]);
        return *temp;
    }
    PolygonDyn&
    PolygonDyn::operator --(int) noexcept {
        PolygonDyn *temp = new PolygonDyn(*this);
        for(int i=0; i<size; ++i)
            ++(points[i]);
        return *temp;
    }

    //OPERATOR OVERLOADINGS
    bool
    PolygonDyn::operator ==(const Shape& polygon2)const noexcept {
        return(area() == polygon2.area());
    }

    bool
    PolygonDyn::operator !=(const Shape& polygon2)const noexcept {
        return (area() != polygon2.area());
    }

    bool
    PolygonDyn::operator <  (const Shape& s2)const noexcept {
        return (area() < s2.area());
    }
    bool
    PolygonDyn::operator <= (const Shape& s2)const noexcept {
        return (area() <= s2.area());
    }
    bool
    PolygonDyn::operator >  (const Shape& s2)const noexcept {
        return (area() > s2.area());
    }
    bool
    PolygonDyn::operator >= (const Shape& s2)const noexcept {
        return (area() >= s2.area());
    }

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

    /* Polgon class codes starts...                                             */

    PolygonDyn::PolygonDyn(const vector<Point2D>& newPoints) {
        setPolygonDyn(newPoints);
    }

    PolygonDyn::PolygonDyn(const Point2D& newPoint) {
        setPoint(newPoint);
    }

    PolygonDyn::PolygonDyn(Shape *newShape) {
        setShape(newShape);
    }

    PolygonDyn::PolygonDyn( ) {
        /*intentionally empty */
    }

    /*BIG THERE OF POLYGON IS STARTED.                                          */
    PolygonDyn::PolygonDyn(const PolygonDyn &newPolygon) { //COPY CONSTRUCTOR

        size = newPolygon.size;
        points = new Point2D[size];

        for(int i=0; i< size; ++i) {
        points[i] = newPolygon[i];
        }
    }

    PolygonDyn&
    PolygonDyn::operator = (const PolygonDyn &newPolygon) {  //ASSIGNMET OPERATOR

        if(&newPolygon != this) {
        if(points !=nullptr) {
            delete [] points; // dynamic array of this obj is deleted
            points = nullptr;
        }
        size=newPolygon.size;
        points = new Point2D[size]; // reallocation

        for(int i=0; i< size; ++i) {
            points[i] = newPolygon[i];
        }
        }
        return *this;
    }

    PolygonDyn::~PolygonDyn() { //DESTRUCTOR
        if(points!=nullptr) {
            delete [] points;
            points = nullptr;
        }
    }
    /*BIG THERE OF POLYGON IS ENDED.                                            */

    void
    PolygonDyn::setSize(int newSize) {
        size = newSize;
        return;
    }

    void
    PolygonDyn::setPolygonDyn(const vector<Point2D>& newPoints) {
        if(points != nullptr){
        delete [] points; //free dynamic array
        points = nullptr;
        }
        size = newPoints.size();
        points = new Point2D[size]; // allocation according to new size

        for(int i=0; i<size; ++i) {
        points[i]=newPoints[i];
        }
        return;
    }

    void
    PolygonDyn::setPoint(const Point2D newPoint) {
        if(points != nullptr) {
        delete [] points;
        points = nullptr;
        }
        size=1;
        points = new Point2D[1];

        points[0]=newPoint;
        return;
    }

    void
    PolygonDyn::setShape(Shape* newShape) {
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
    PolygonDyn::setCircle(Circle& newCircle) {

        double radius = newCircle.getRadius();   // radius of the circle
        newCircle.setCenter(radius, radius);
        if(points != nullptr) {
            delete [] points;
            points = nullptr;
        }

        size = CIRCLE_POINT_COUNT;
        points = new Point2D[size];

        // cout << "I am in the polygon constructor that takes circle\n";
        // cout << "radius :"<<radius<<endl;
        // cout << RAD<<","<< CIRCLE_POINT_COUNT<<endl;
        int i=0;
        for ( double d =360.0/CIRCLE_POINT_COUNT;
            d<=360.1;
            d+=(360.0/CIRCLE_POINT_COUNT) ){
            if(i>=size) break;
            points[i].setCol(newCircle.getCenterCol() + radius*cos(d/RAD));
            points[i].setRow(newCircle.getCenterRow() + radius*sin(d/RAD));
            ++i;
        }
        return;
    }

    void
    PolygonDyn::setRectangle(Rectangle& newRectangle) {

        if(points != nullptr) {
            delete [] points;
            points = nullptr;
        }
        size =4;
        points = new Point2D[size];

        // for vertice of the rectangle is calculated and set.
        points[0].setCol(newRectangle.getStartPointCol());
        points[0].setRow(newRectangle.getStartPointRow());
        points[1].setCol(points[0].getCol() + newRectangle.getWidth());
        points[1].setRow(points[0].getRow());
        points[2].setCol(points[1].getCol());
        points[2].setRow(points[1].getRow() + newRectangle.getHeight());
        points[3].setCol(points[2].getCol() - newRectangle.getWidth());
        points[3].setRow(points[2].getRow());

        return;
    }

    void
    PolygonDyn::setTriangle(Triangle& newTriangle) {

        Point2D leftBtmNode, rightBtmNode; //left and right bottom node of triangle
        newTriangle.setPeakPoint(newTriangle.getEdge()/2, 0);
            if(points != nullptr) {
            delete [] points;
            points = nullptr;
        }

        size =3;
        points = new Point2D[size];

        newTriangle.calcTriangleBottomNodes(leftBtmNode, rightBtmNode);

        points[0] = newTriangle.getPeakPoint();
        points[0].setRotation(newTriangle.getRotationAngle());
        points[1] = leftBtmNode;
        points[2] = rightBtmNode;

        return;
    }

    Point2D*
    PolygonDyn::getPolygon() const {
        return points;
    }

    int
    PolygonDyn::getSize() const {
        return size;
    }

    ostream&
    PolygonDyn::initSvgFile(ostream& outputStream) {
        Point2D maxPoint(0,0);

        for(int i=0; i<size; ++i) {
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
    PolygonDyn::operator [] (int index) const throw(out_of_range) {
        if(size>= index){
            return points[index];
        }
        else{
            throw out_of_range("out of polygondyn array\n");
        }
    }

    Point2D&
    PolygonDyn::operator [] (int index) throw(out_of_range) {
        if(size>= index){
            return points[index];
        }
        else{
            throw out_of_range("out of polygondyn array\n");
        }
    }


    PolygonDyn
    PolygonDyn::operator +(const PolygonDyn& polygon2) noexcept {
        PolygonDyn newPolygon;
        int i;

        newPolygon.size = size + polygon2.size;
        newPolygon.points = new Point2D[newPolygon.size];

        for(i = 0; i<size; ++i)
        newPolygon.points[i] = points[i];

        for(i=size; i<newPolygon.size; ++i)
        newPolygon.points[i] = polygon2[i-size];

        return newPolygon;
    }

    ostream&
    operator <<(ostream& outputStream, PolygonDyn& polygon) {
        polygon.initSvgFile(outputStream);
        polygon.print(outputStream);
        outputStream << "</svg>";
        return outputStream;
    }

    // print function, prints the shape in a svg file
    ostream&
    PolygonDyn::print(ostream& outputStream) noexcept {
        Point2D rotationPoint; //we assume there is only one point to use as a pivot while rotation
        // cout << "I am in print, size :"<<size<<endl;
        outputStream << "  <polygon points= \"";
        for (int i=0; i< size; ++i) {
            outputStream << points[i].getCol()<< ", "<< points[i].getRow()<< " ";

            if(points[i].getRotation()>0) // if it is rotation point.
                rotationPoint = points[i];
        }

        outputStream  << "\" transform = \"rotate("
                      << rotationPoint.getRotation() << " "
                      << rotationPoint.getCol()      << " "
                      << rotationPoint.getRow()      << ")\""
                      << " stroke = \"black\" stroke-width=\"1\" ";
        if(size>=3){
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
