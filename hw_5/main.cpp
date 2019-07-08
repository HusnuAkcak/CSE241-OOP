/////////////////////////////
// CSE 241 - HW5/////////////
// Hüsnü AKÇAK   ////////////
// 161044112     ////////////
/////////////////////////////
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "src/shape.h"
#include "src/circle.h"
#include "src/rectangle.h"
#include "src/triangle.h"
#include "src/composedShape.h"
#include "src/polygon.h"
#include "src/polygonDyn.h"
#include "src/polygonVect.h"


#define ARR_SIZE 4
using namespace std;
using namespace geometrical;

int main () {

  srand (time(NULL));

  string fileName;
  ofstream filePtr;
  int i,
      contCircleRad=150,
      contRectWidth=1000,
      contRectHeight=800,
      contTriEdge=1000,
      smallCircleRad=70,
      smallRectWidth=20,
      smallRectHeight=30,
      smallTriEdge=30;

  ComposedShape cmpShape1 [ARR_SIZE], cmpShape2 [ARR_SIZE], cmpShape3 [ARR_SIZE];

  Circle contCircle [ARR_SIZE];
  Circle smallCircle [ARR_SIZE];
  Rectangle contRect [ARR_SIZE];
  Rectangle smallRect [ARR_SIZE];
  Triangle contTri [ARR_SIZE];
  Triangle smallTri [ARR_SIZE];

  ComposedShape attemp1 =cmpShape2[0]; //assignment contsructor test
  ComposedShape attemp2(cmpShape1[0]); //copy contsructor test

  for (i=0; i<ARR_SIZE; ++i) {
    try{
      smallCircle[i].setRadius((i+1)/1.5*smallCircleRad);
      smallRect[i].setWidth((i+1)*smallRectWidth);
      smallRect[i].setHeight((i+1)*smallRectHeight);
      smallTri[i].setEdge((i+1)*smallTriEdge);

      contCircle[i].setRadius(contCircleRad);
      contRect[i].setWidth(contRectWidth);
      contRect[i].setHeight(contRectHeight);
      contTri[i].setEdge(contTriEdge);
    } catch(invalid_argument e){
      cout << "Some given arguments are invalid, program is terminating.\n";
      return 0;
    }
  }

  for (i =0; i< ARR_SIZE; ++i) {
    try {
      Circle contCircleT=contCircle[i];
      Rectangle contRectT=contRect[i];
      Triangle contTriT=contTri[i];
      Circle smallCircleT=smallCircle[i];

      ++cmpShape1[i];
      cmpShape1[i].setContainer(&contCircleT);
      cmpShape1[i].setSmallShape(&smallCircleT);
      cmpShape1[i].optimalFit();
      fileName = "results/"+to_string((i+1))+"-circle_in_cicrle-shape.svg";
      filePtr.open(fileName);
      filePtr<<cmpShape1[i];
      filePtr.close();
      filePtr.clear();

      cmpShape2[i].setContainer(&contRectT);
      cmpShape2[i].setSmallShape(&smallCircleT);
      cmpShape2[i].optimalFit();
      fileName = "results/"+to_string((i+1))+"-circle_in_rect-shape.svg";
      filePtr.open(fileName);
      filePtr<<cmpShape2[i];
      filePtr.close();
      filePtr.clear();

      cmpShape3[i].setContainer(&contTriT);
      cmpShape3[i].setSmallShape(&smallCircleT);
      cmpShape3[i].optimalFit();
      fileName = "results/"+to_string((i+1))+"-circle_in_tri-shape.svg";
      filePtr.open(fileName);
      filePtr<<cmpShape3[i];
      filePtr.close();
      filePtr.clear();
    }
    catch (container_unavailable){
      cout << "container is unavailable\n";
    }
    catch(smallShape_unavailable){
      cout<<"small shape is unavailable\n";
    }
  }

  for (i =0; i< ARR_SIZE; ++i) {
    try {
      Circle contCircleT=contCircle[i];
      Rectangle contRectT=contRect[i];
      Triangle contTriT=contTri[i];
      Rectangle smallRectT =smallRect[i];

      cmpShape1[i]++;
      cmpShape1[i].setContainer(&(contCircleT));
      cmpShape1[i].setSmallShape(&smallRectT);
      cmpShape1[i].optimalFit();
      fileName = "results/"+to_string((i+1))+"-rect_in_cicle-shape.svg";
      filePtr.open(fileName);
      filePtr<<cmpShape1[i];
      filePtr.close();
      filePtr.clear();


      cmpShape2[i].setContainer(&contRectT);
      cmpShape2[i].setSmallShape(&smallRectT);
      cmpShape2[i].optimalFit();
      fileName = "results/"+to_string((i+1))+"-rect_in_rect-shape.svg";
      filePtr.open(fileName);
      filePtr<<cmpShape2[i];
      filePtr.close();
      filePtr.clear();

      cmpShape3[i].setContainer(&contTriT);
      cmpShape3[i].setSmallShape(&smallRectT);
      cmpShape3[i].optimalFit();
      fileName = "results/"+to_string((i+1))+"-rect_in_tri-shape.svg";
      filePtr.open(fileName);
      filePtr<<cmpShape3[i];
      filePtr.close();
      filePtr.clear();
    }
    catch(container_unavailable) {
      cout << "container is unavailable\n";
    }
    catch(smallShape_unavailable){
      cout<<"small shape is unavailable\n";
    }
  }

  for (i =0; i< ARR_SIZE; ++i) {
    try {
      Circle contCircleT=contCircle[i];
      Rectangle contRectT=contRect[i];
      Triangle contTriT=contTri[i];
      Triangle smallTriT =smallTri[i];

      ++++++cmpShape1[i];
      --cmpShape1[i];
      cmpShape1[i].setContainer(&(contCircleT));
      cmpShape1[i].setSmallShape(&smallTriT);
      cmpShape1[i].optimalFit();
      fileName = "results/"+to_string((i+1))+"-tri_in_cicle-shape.svg";
      filePtr.open(fileName);
      filePtr<<cmpShape1[i];
      filePtr.close();
      filePtr.clear();

      cmpShape2[i].setContainer(&contRectT);
      cmpShape2[i].setSmallShape(&smallTriT);
      cmpShape2[i].optimalFit();
      fileName = "results/"+to_string((i+1))+"-tri_in_rect-shape.svg";
      filePtr.open(fileName);
      filePtr<<cmpShape2[i];
      filePtr.close();
      filePtr.clear();

      cmpShape3[i].setContainer(&contTriT);
      cmpShape3[i].setSmallShape(&smallTriT);
      cmpShape3[i].optimalFit();
      fileName = "results/"+to_string((i+1))+"-tri_in_tri-shape.svg";
      filePtr.open(fileName);
      filePtr<<cmpShape3[i];
      filePtr.close();
      filePtr.clear();
    }
    catch(container_unavailable){
      cout<< "container is unavailable\n";
    }
    catch(smallShape_unavailable){
      cout<<"small shape is unavailable\n";
    }
  }
  cout << "Autamatic shape generation is finished...\n\n";

  ////POSFIX & PREFIX TEST
  cout <<"POSFIX & PREFIX TEST\n";
  contCircle[0].setCenter(contCircle[0].getRadius(), contCircle[0].getRadius());
  contCircle[0]++++;
  contCircle[0]--;
  fileName = "results/"+to_string((i+1))+"-circle_postfix_prefix.svg";
  filePtr.open(fileName);
  filePtr << "<svg version=\"1.1\" baseProfile=\"full\" "<< " width= \"" << 1000 << "\""<< " height= \"" <<  1000 << "\""<< " xmlns=\"http://www.w3.org/2000/svg\"> "<< endl << endl;
  filePtr<<contCircle[0];
  filePtr << "</svg>";
  filePtr.close();
  filePtr.clear();

  contTri[0].setPeakPoint((contTri[0].getEdge()/2)+10, 10);
  ++contTri[0]++;
  fileName = "results/"+to_string((i+1))+"-Tri_postfix_prefix.svg";
  filePtr.open(fileName);
  filePtr << "<svg version=\"1.1\" baseProfile=\"full\" "<< " width= \"" << 1000 << "\""<< " height= \"" <<  1000 << "\""<< " xmlns=\"http://www.w3.org/2000/svg\"> "<< endl << endl;
  filePtr<<contTri[0];
  filePtr << "</svg>";
  filePtr.close();
  filePtr.clear();

  contRect[0].setStartPoint(10,10);
  ++++contRect[0];
  fileName = "results/"+to_string((i+1))+"-Rect_postfix_prefix.svg";
  filePtr.open(fileName);
  filePtr << "<svg version=\"1.1\" baseProfile=\"full\" "<< " width= \"" << 1000 << "\""<< " height= \"" <<  1000 << "\""<< " xmlns=\"http://www.w3.org/2000/svg\"> "<< endl << endl;
  filePtr<<contRect[0];
  filePtr << "</svg>";
  filePtr.close();
  filePtr.clear();

  contTri[0].setPeakPoint((contTri[0].getEdge()/2)+10, 10);
  ++contTri[0]++;
  --contTri[0]--;
  fileName = "results/"+to_string((i+1))+"-Tri_postfix_prefix.svg";
  filePtr.open(fileName);
  filePtr << "<svg version=\"1.1\" baseProfile=\"full\" "<< " width= \"" << 1000 << "\""<< " height= \"" <<  1000 << "\""<< " xmlns=\"http://www.w3.org/2000/svg\"> "<< endl << endl;
  filePtr<<contTri[0];
  filePtr << "</svg>";
  filePtr.close();
  filePtr.clear();
  cout <<"POSFIX & PREFIX TEST ENDS\n\n";
  ////END OF POSFIX & PREFIX TEST

  cout<< "COMPERISON operator tests start\n";
  /// comperison operator overloading
  if (cmpShape1[0] == cmpShape1[0])
    cout << "composed shapes are equal\n";
  if (cmpShape1[0] != cmpShape1[1])
    cout << "composed shapes are not equal\n";
  if (cmpShape1[0] < cmpShape1[1])
    cout << "first composed shape is smaller than second one\n";
  if (cmpShape1[0] <= cmpShape1[0])
    cout << "first composed shape is smaller than or equal to second one\n";
  if (cmpShape1[2] > cmpShape1[3])
    cout << "second composed shape is smaller than to first one\n";
  if (cmpShape1[0] >= cmpShape1[3])
    cout << "second composed shape is smaller than or equal to first one\n";
  // comperison operator tests end
  cout<< "COMPERISON operator tests end\n\n";



  //POLYGON DYNMAIC CLASS TEST STARTS
  cout << "POLYGON DYNMAIC CLASS TEST\n";

  //circle pointer to polygon dynamic
  try{
    Circle *dynPolyCircle;
    fileName = "results/_polygonDyn_circlePtr.svg";
    filePtr.open(fileName);
    dynPolyCircle = dynamic_cast<Circle*>(&(contCircle[0]));
    PolygonDyn pd1(dynPolyCircle);
    pd1++++++++++++++++++++++;
    --pd1;
    ++pd1;
    pd1--;
    filePtr<<pd1;
    cout << "polygon dyn circle dimension(radius) :"<<contCircle[0].getRadius()<<endl;
    cout << "polygon dyn circle's area :" << pd1.area()<<endl;
    cout << "polygon dyn circle's perimeter :" << pd1.perimeter()<<endl;
    filePtr.close();
    filePtr.clear();

    //rect ptr to polygon dynamic
    Rectangle *dynPolyRect;
    fileName = "results/_polygonDyn_rectPtr.svg";
    filePtr.open(fileName);
    dynPolyRect = dynamic_cast<Rectangle*>(&(contRect[0]));
    PolygonDyn pd2(dynPolyRect);
    ++++++++++++++++++++++pd2;
    filePtr<<pd2;
    cout << "polygon dyn rect dimension :"<<contRect[0].getHeight()<<","
                                          <<contRect[0].getWidth()<<endl;
    cout << "polygon dyn rect's area :" << pd2.area()<<endl;
    cout << "polygon dyn rect's perimeter :" << pd2.perimeter()<<endl;
    filePtr.close();
    filePtr.clear();

    //rect ptr to polygon dynamic
    Triangle *dynPolyTri;
    fileName = "results/_polygonDyn_triPtr.svg";
    filePtr.open(fileName);
    dynPolyTri = dynamic_cast<Triangle*>(&(contTri[0]));
    PolygonDyn pd3(dynPolyTri);
    filePtr<<pd3;
    cout << "polygon dyn triangle dimension(edge) :"<<contTri[0].getEdge()<<endl;
    cout << "polygon dyn triangle's area :" << pd3.area()<<endl;
    cout << "polygon dyn triangle's perimeter :" << pd3.perimeter()<<endl;
    filePtr.close();
    filePtr.clear();
    cout << "POLYGON DYNAMIC CLASS TEST ENDS\n\n";


    //POLYGON VECTOR CLASS TEST
    cout << "POLYGON VECTOR CLASS TEST\n";
    Circle *vectPolyCircle;
    fileName = "results/_polygonVect_circlePtr.svg";
    filePtr.open(fileName);
    vectPolyCircle = dynamic_cast<Circle*>(&(contCircle[3]));
    PolygonVect pv1(vectPolyCircle);
    pv1++++++++++++++++++++++;
    --pv1;
    ++pv1;
    pv1--;
    filePtr<<pv1;
    filePtr.close();
    filePtr.clear();

    //rect ptr to polygon dynamic
    Rectangle *vectPolyRect;
    fileName = "results/_polygonDyn_rectPtr.svg";
    filePtr.open(fileName);
    vectPolyRect = dynamic_cast<Rectangle*>(&(contRect[0]));
    PolygonVect pv2(vectPolyRect);
    ++++++++++++++++++++++pv2;
    filePtr<<pv2;
    cout << "polygon vect rect dimension :"<<contRect[0].getHeight()<<","
                                          <<contRect[0].getWidth()<<endl;
    cout << "polygon vect rect's area :" << pv2.area()<<endl;
    cout << "polygon vect rect's perimeter :" << pv2.perimeter()<<endl;
    filePtr.close();
    filePtr.clear();

    //rect ptr to polygon dynamic
    Triangle *vectPolyTri;
    fileName = "results/_polygonDyn_triPtr.svg";
    filePtr.open(fileName);
    vectPolyTri = dynamic_cast<Triangle*>(&(contTri[0]));
    PolygonVect pv3(vectPolyTri);
    filePtr<<pv3;
    cout << "polygon vect triangle dimension(edge) :"<<contTri[0].getEdge()<<endl;
    cout << "polygon vect triangle's area :" << pv3.area()<<endl;
    cout << "polygon vect triangle's perimeter :" << pv3.perimeter()<<endl;
    filePtr.close();
    filePtr.clear();
    cout << "POLYGON VECTOR CLASS TEST ENDS\n\n";

    /// addition
    cout << "ADDITION \n";
    pv2= pv2+pv3;
    fileName = "results/_pv1+pv2 .svg";
    filePtr.open(fileName);
    filePtr<<pv2;
    filePtr.close();
    filePtr.clear();
    cout << "ADDITION ENDS..\n";

    //areas are being calculating
    cout << "===========================================\n";
    cout << "areas are being calculating\n";
    cout << "composed shape 1 area: "<<cmpShape1[0].area() <<endl;
    cout << "circle area: "<<contCircle[0].area() <<endl;
    cout << "rectangle area: "<<contRect[0].area() <<endl;
    cout << "triangle area: "<<contTri[0].area() <<endl;
    cout << "polygon vector area:"<<pv1.area() <<endl;
    cout << "polygon dynamic area:"<<pd1.area() <<endl;
    cout << "areas are tested." <<endl;
    cout << "===========================================\n";
    //areas are tested.

    //perimeters are being calculating
    cout << "===========================================\n";
    cout << "perimeters are being calculating\n";
    cout << "composed shape 1 perimeter: "<<cmpShape1[0].perimeter() <<endl;
    cout << "circle perimeter: "<<contCircle[0].perimeter() <<endl;
    cout << "rectangle perimeter: "<<contRect[0].perimeter() <<endl;
    cout << "triangle perimeter: "<<contTri[0].perimeter() <<endl;
    cout << "polygon vector perimeter:"<<pv2.perimeter() <<endl;
    cout << "polygon dynamic perimeter:"<<pd3.perimeter() <<endl;
    cout << "perimeters are tested." <<endl;
    cout << "===========================================\n";
  }
  catch(bad_cast) {
    cout << "Bad casting\n";
    return 0;
  }
  //perimeters are tested.

  //GLOBAL FUNCTIONS TESTS STARTS

  // printAll func. takes a vector of a shape pointer and prints all shapes
  //that is indicated by pointers.
  cout<< "-----------------------------\n";
  cout << "printAll FUCNTION IS TESTED\n";
  printAll(cmpShape1[0].getShape());

  //"sortShapes" function is being tested.
  cout << "sortShapes FUCNTION IS BEING TESTED\n";
  vector<Shape*> sortTestShape;
  sortTestShape.push_back(dynamic_cast<Shape*>(&contCircle[3]));
  sortTestShape.push_back(dynamic_cast<Shape*>(&contCircle[1]));
  sortTestShape.push_back(dynamic_cast<Shape*>(&contCircle[2]));
  sortTestShape.push_back(dynamic_cast<Shape*>(&contRect[0]));
  sortTestShape.push_back(dynamic_cast<Shape*>(&contTri[0]));

  cout << "::::BEFORE SORTING \n";
  for(auto i : sortTestShape){
    cout << (i->area())<<endl;
  }
  sortShapes(sortTestShape);
  cout << "::::AFTER SORTING \n";
  for(auto i : sortTestShape){
    cout << i->area()<<endl;
  }
  cout<< "-----------------------------\n";

  // convertAll FUNCTION TEST STARTS
  cout<< "convertAll FUNCTION TEST STARTS \n";
  vector<Shape*> convertedPol;
  convertedPol = convertAll(cmpShape1[0].getShape());
  cout<< "convertAll FUNCTION TEST ENDS \n";
  cout<< "-----------------------------\n";

  // convertAll FUNCTION TEST ENDS

  // printPoly FUNCTION TEST STARTS
  cout << "printPoly FUCNTION IS TESTED\n";
  vector<Shape*> polyShapes;
  PolygonVect pvt1(&(contCircle[0]));
  contRect[0].setStartPoint(250,250);
  PolygonDyn pdt1(&(contRect[0]));
  PolygonDyn pdt2(&(contTri[0]));

  polyShapes.push_back(&pvt1);
  polyShapes.push_back(&pdt1);
  polyShapes.push_back(&pdt2);
  polyShapes = polyShapes;
  printPoly(polyShapes);
  printPoly(convertedPol);
  // printPoly FUNCTION TEST ENDS

  //GLOBAL FUNCTIONS TESTS ENDS

  return 0;
}
