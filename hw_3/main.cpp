#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include "src/base.h"
#include "src/circle.h"
#include "src/rectangle.h"
#include "src/triangle.h"
#include "src/composedShape.h"

#define ARR_SIZE 4
using namespace std;

int main () {
  string fileName;
  ofstream filePtr;
  int i,
      contCircleRad=150,
      contRectWidth=1000,
      contRectHeight=800,
      contTriEdge=1000,
      smallCircleRad=45,
      smallRectWidth=20,
      smallRectHeight=30,
      smallTriEdge=30;

  ComposedShape cmpShape1 [ARR_SIZE], cmpShape2 [ARR_SIZE], cmpShape3 [ARR_SIZE];
  ComposedShape::ShapeElem contShape1 [ARR_SIZE];
  ComposedShape::ShapeElem smallShape1 [ARR_SIZE];
  ComposedShape::ShapeElem contShape2 [ARR_SIZE];
  ComposedShape::ShapeElem smallShape2 [ARR_SIZE];
  ComposedShape::ShapeElem contShape3 [ARR_SIZE];
  ComposedShape::ShapeElem smallShape3 [ARR_SIZE];

  Circle contCircle [ARR_SIZE];
  Circle smallCircle [ARR_SIZE];
  Rectangle contRect [ARR_SIZE];
  Rectangle smallRect [ARR_SIZE];
  Triangle contTri [ARR_SIZE];
  Triangle smallTri [ARR_SIZE];

  for (i=0; i<ARR_SIZE; ++i) {
    smallCircle[i].setRadius((i+1)/1.5*smallCircleRad);
    smallRect[i].setWidth((i+1)*smallRectWidth);
    smallRect[i].setHeight((i+1)*smallRectHeight);
    smallTri[i].setEdge((i+1)*smallTriEdge);

    contCircle[i].setRadius(contCircleRad);
    contRect[i].setWidth(contRectWidth);
    contRect[i].setHeight(contRectHeight);
    contTri[i].setEdge(contTriEdge);
  }

  for (i =0; i< ARR_SIZE; ++i) {

    contShape1[i].setCircle(contCircle[i]);
    smallShape1[i].setCircle(smallCircle[i]);
    cmpShape1[i].setContainer(contShape1[i]);
    cmpShape1[i].setSampleSmallShape(smallShape1[i]);
    cmpShape1[i].optimalFit();
    fileName = "results/"+to_string((i+1))+"-circle_in_cicrle-shape.svg";
    filePtr.open(fileName);
    filePtr<<cmpShape1[i];
    filePtr.close();
    filePtr.clear();

    contShape2[i].setRectangle(contRect[i]);
    smallShape2[i].setCircle(smallCircle[i]);
    cmpShape2[i].setContainer(contShape2[i]);
    cmpShape2[i].setSampleSmallShape(smallShape2[i]);
    cmpShape2[i].optimalFit();
    fileName = "results/"+to_string((i+1))+"-circle_in_rect-shape.svg";
    filePtr.open(fileName);
    filePtr<<cmpShape2[i];
    filePtr.close();
    filePtr.clear();

    contShape3[i].setTriangle(contTri[i]);
    smallShape3[i].setCircle(smallCircle[i]);
    cmpShape3[i].setContainer(contShape3[i]);
    cmpShape3[i].setSampleSmallShape(smallShape3[i]);
    cmpShape3[i].optimalFit();
    fileName = "results/"+to_string((i+1))+"-circle_in_tri-shape.svg";
    filePtr.open(fileName);
    filePtr<<cmpShape3[i];
    filePtr.close();
    filePtr.clear();
  }

  for (i =0; i< ARR_SIZE; ++i) {

    contShape1[i].setCircle(contCircle[i]);
    smallShape1[i].setRectangle(smallRect[i]);
    cmpShape1[i].setContainer(contShape1[i]);
    cmpShape1[i].setSampleSmallShape(smallShape1[i]);
    cmpShape1[i].optimalFit();
    fileName = "results/"+to_string((i+1))+"-rect_in_cicle-shape.svg";
    filePtr.open(fileName);
    filePtr<<cmpShape1[i];
    filePtr.close();
    filePtr.clear();

    contShape2[i].setRectangle(contRect[i]);
    smallShape2[i].setRectangle(smallRect[i]);
    cmpShape2[i].setContainer(contShape2[i]);
    cmpShape2[i].setSampleSmallShape(smallShape2[i]);
    cmpShape2[i].optimalFit();
    fileName = "results/"+to_string((i+1))+"-rect_in_rect-shape.svg";
    filePtr.open(fileName);
    filePtr<<cmpShape2[i];
    filePtr.close();
    filePtr.clear();

    contShape3[i].setTriangle(contTri[i]);
    smallShape3[i].setRectangle(smallRect[i]);
    cmpShape3[i].setContainer(contShape3[i]);
    cmpShape3[i].setSampleSmallShape(smallShape3[i]);
    cmpShape3[i].optimalFit();
    fileName = "results/"+to_string((i+1))+"-rect_in_tri-shape.svg";
    filePtr.open(fileName);
    filePtr<<cmpShape3[i];
    filePtr.close();
    filePtr.clear();
  }

  for (i =0; i< ARR_SIZE; ++i) {

    contShape1[i].setCircle(contCircle[i]);
    smallShape1[i].setTriangle(smallTri[i]);
    cmpShape1[i].setContainer(contShape1[i]);
    cmpShape1[i].setSampleSmallShape(smallShape1[i]);
    cmpShape1[i].optimalFit();
    fileName = "results/"+to_string((i+1))+"-tri_in_cicle-shape.svg";
    filePtr.open(fileName);
    filePtr<<cmpShape1[i];
    filePtr.close();
    filePtr.clear();

    contShape2[i].setRectangle(contRect[i]);
    smallShape2[i].setTriangle(smallTri[i]);
    cmpShape2[i].setContainer(contShape2[i]);
    cmpShape2[i].setSampleSmallShape(smallShape2[i]);
    cmpShape2[i].optimalFit();
    fileName = "results/"+to_string((i+1))+"-tri_in_rect-shape.svg";
    filePtr.open(fileName);
    filePtr<<cmpShape2[i];
    filePtr.close();
    filePtr.clear();

    contShape3[i].setTriangle(contTri[i]);
    smallShape3[i].setTriangle(smallTri[i]);
    cmpShape3[i].setContainer(contShape3[i]);
    cmpShape3[i].setSampleSmallShape(smallShape3[i]);
    cmpShape3[i].optimalFit();
    fileName = "results/"+to_string((i+1))+"-tri_in_tri-shape.svg";
    filePtr.open(fileName);
    filePtr<<cmpShape3[i];
    filePtr.close();
    filePtr.clear();
  }
  cout << "Automatic shape generation is finished...\n\n";

  Triangle t1 (100, 0, 100, 0);
  Triangle t2 (100, 0, 100, 0);
  Triangle t3 (10);

  Rectangle r1 (0,0,10,50);
  Rectangle r2 (100, 50, 10, 20);
  Rectangle r3;

  Circle c1 (250, 250, 200);
  Circle c2 (500, 250, 200);
  Circle c3;


  //EXPLONATION : += and [] operator of the composedShape exist but, do not shown here.
  c3 = c1 + c2 +5;
  r3 = 10 + r2;
  t3 = t1 + t2 + t3;

  c1++; c2--; ++c1; --c2;
  r1++; r2--; ++r1; --r2;
  t1++; t2--; ++t1; --t2;

  t1.setEdge(50);
  t3.setEdge(50);
  cout  << "Triangle total count:"<<Triangle::getTotalCount()<< ",  "
        << "Triangle total perimeter:"<<Triangle::getTotalPerimeter() << ", "
        << "Triangle total area:"<<Triangle::getTotalArea() << endl;

  cout << "tri 1 :"<<t1 << "tri 2:" <<t2<<endl;

  r1.setWidth(20);
  cout  << "Rectangele total count: "<<Rectangle::getTotalCount() <<",  "
        << "Rectangele total area: "<<Rectangle::getTotalArea() <<",  "
        << "Rectangele total perimeter: "<<Rectangle::getTotalPerimeter() <<endl;

  cout << "rect 1 :"<<r1 << "rect 2:" <<r2<<endl;

  cout  << "circle total area:"<<Circle::getTotalArea()<< ",  "
  << "circle total count:"<< Circle::getTotalCount()<<",  "
  << "circle total perimeter:"<< Circle::getTotalPerimeter()<<endl<<endl;

  c2.setRadius( c2.getRadius() -100 );
  cout  << "circle1:"<<c1 << "circle2:"<<c2 <<endl;


  if(c1 != c2 )
    cout << "the circles are not equal\n";
  else if(c1==c2)
    cout << "circles are equal\n";

  if(r1 != r2 )
    cout << "the rects are not equal\n";
  else if(r1== r2)
    cout << "rects are equal\n";

  if(t1 != t2 )
    cout << "the triangles are not equal\n";
  else if(t1==t2)
    cout << "triangles are equal\n";


  cout << c1;
  c1= c1-50;
  cout << "===================================================\n";
  cout << c1<<c2;
  c1= c1-c2+10-3;
  cout << "====================================================\n";
  cout << c1<<c2;
  c1= 405-c2;
  cout << "====================================================\n";
  cout << c1<<c2;

  cout<< "If you want to see the result of user input enter 'y', otherwise give another entry.\n";
  char selection;
  cin >> selection;
  if(selection=='y' || selection =='Y'){
    ComposedShape cmp1;
    cmp1.input();
    cmp1.optimalFit();
    fileName = "results/user_input.svg";
    filePtr.open(fileName);
    filePtr << cmp1;
  }
  return 0;
}
