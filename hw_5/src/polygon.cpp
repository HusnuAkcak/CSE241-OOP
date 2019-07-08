#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <string>
#include <fstream>
#include "polygon.h"
#include "point2d.h"
#include "circle.h"
#include "rectangle.h"
#include "triangle.h"
#include "polygonDyn.h"
#include "polygonVect.h"

namespace {
  #define CIRCLE_POINT_COUNT 100.0
}

using namespace std;

namespace geometrical {

  // GLOBAL FUNCTION IMPLEMENTATIONS STARTS (TWO OF FOUR FUNCTION).
  // printPoly GLOBAL FUNCTION.
  void
  printPoly(vector<Shape*>& polygons) {
        string fileName;
        ofstream filePtr;

        fileName="results/printPoly_Shapes::"+to_string(rand()%1000)+".svg";
        filePtr.open(fileName); //open file pointer

        //init the svg file
        filePtr << "<svg version=\"1.1\" baseProfile=\"full\" "
                << " width= \"" << 2000 << "\""
                << " height= \"" <<  2000 << "\""
                << " xmlns=\"http://www.w3.org/2000/svg\"> "
                << endl << endl;

        for(int i=0; i<polygons.size(); ++i) {
            // prints only polygon shapes
            if(dynamic_cast<Polygon*>(polygons[i])!=nullptr)
            polygons[i]->print(filePtr);
        }

        filePtr << "</svg>"; // svg is closed.

        cout << "output svg file name: "<< fileName<<endl;
        cout << "--------------------------------------\n";

        filePtr.close();
        filePtr.clear();
    return;
  }

  //convertAll GLOBAL FUNCTION.
  vector<Shape*>
  convertAll(const vector<Shape*>& shapes) {
    vector<Shape*> newVector;
    for(auto i: shapes) {
      if(dynamic_cast<Circle*>(i)!=nullptr){
         // in this case, I prefer to use dynPolygon
        PolygonDyn *polygon= new PolygonDyn(i);
        newVector.push_back(polygon);
      }
      else if(dynamic_cast<Rectangle*>(i)!=nullptr){
         // in this case, I prefer to use vectPolygon
        PolygonVect *polygon= new PolygonVect(i);
        newVector.push_back(polygon);
      }
      else if(dynamic_cast<Rectangle*>(i)!=nullptr){
         // in this case, I prefer to use dynPolygon
        PolygonDyn *polygon= new PolygonDyn(i);
        newVector.push_back(polygon);
      }
      else if(dynamic_cast<Polygon*>(i)!=nullptr){
        newVector.push_back(i);
      }
    }
    return newVector;
  }
  // GLOBAL FUNCTION IMPLEMENTATIONS ENDS.
  // comperisons
  bool
  Polygon::operator == (const Shape& s2)const noexcept {
    return (area() == s2.area());
  }
  bool
  Polygon::operator != (const Shape& s2)const noexcept {
    return (area() != s2.area());
  }
  bool
  Polygon::operator <  (const Shape& s2)const noexcept {
    return (area() < s2.area());
  }
  bool
  Polygon::operator <= (const Shape& s2)const noexcept {
    return (area() <= s2.area());
  }
  bool
  Polygon::operator >  (const Shape& s2)const noexcept {
    return (area() > s2.area());
  }
  bool
  Polygon::operator >= (const Shape& s2)const noexcept {
    return (area() >= s2.area());
  }

  ostream&
  Polygon::print(ostream& outputStream) noexcept {

    return outputStream;
  }

  /* Polgon class codes ends...                                               */
}//end svg namespace
