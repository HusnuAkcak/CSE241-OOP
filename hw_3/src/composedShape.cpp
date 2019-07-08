#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include "base.h"
#include "circle.h"
#include "rectangle.h"
#include "triangle.h"
#include "composedShape.h"

using namespace std;

int ComposedShape::outputCounter = 0;

ComposedShape::ComposedShape(ComposedShape::ShapeElem newContainer, ComposedShape::ShapeElem newSmallShape) {
  setContainer(newContainer);
  setSampleSmallShape(newSmallShape);
  ++outputCounter;
}

void
ComposedShape::setContainer(ComposedShape::ShapeElem newContainer) {
  container = newContainer;
  // cout << "in setContainer\n";
  return;
}

void
ComposedShape::setSmallShapeVector(vector<ShapeElem> newSmallShape) {
  smallShape = newSmallShape;
  return;
}

void
ComposedShape::setSampleSmallShape(ComposedShape::ShapeElem newSampleSmallShape) {
  sampleSmallShape=newSampleSmallShape;
  return;
}

void
ComposedShape::setCounter(int newCounter) {
  if(newCounter>=0)
    outputCounter=newCounter;
  else
    cout << "Invalid count value!\n";

  return;
}

void
ComposedShape::input() {

  inputContainerData();
  inputSmallShapeData();
  return;
}

void
ComposedShape::inputContainerData() {
  inputShapeData(container, "Please enter the main container shape\n");
  return;
}

void
ComposedShape::inputSmallShapeData() {
  inputShapeData(sampleSmallShape, "Please enter the small shape\n");
  return;
}

void
ComposedShape::inputShapeData(ComposedShape::ShapeElem & newShape, string message) {

  char selection;

  cout  << endl
        << message << endl
        << "Circle    : C\n"
        << "Rectangle : R\n"
        << "Triangle  : T\n"
        << endl;

  // User's choice is being received.
  selection='\0';
  do {
    if(selection != '\0') { //if user makes an invalid choice.
      cout  << message << endl
            << "Circle    : C\n"
            << "Rectangle : R\n"
            << "Triangle  : T\n"
            << endl;

      cin >> selection;
    }
    else {
      cin >> selection;
    }
  } // loop goes on until user make a valid selection.
  while(
      selection!='c' && selection != 'C' &&
      selection!='r' && selection != 'R' &&
      selection!='t' && selection != 'T'
  );


  // According to user's selection, different operations are performed.
  switch ( selection ) {
    case 'c':
    case 'C':
      newShape.setShapeName(Shape_name :: circle);
      inputCircleData(newShape);
      break;

    case 'r':
    case 'R':
      newShape.setShapeName(Shape_name :: rectangle);
      inputRectangleData(newShape);
      break;

    case 't':
    case 'T':
      newShape.setShapeName(Shape_name :: triangle);
      inputTriangleData(newShape);
      break;
    default :
      cout << "There is a problem in \"get_shape\" function.\n";
  }
  return;
}

void
ComposedShape::inputCircleData(ComposedShape::ShapeElem & newShape) {
  int newRadius;
  ShapeElem temp(Shape_name::circle); //shape's void pointer is pointin to a circle.

  newShape=temp;
  cout << "Please enter the radius: ";
  cin >> newRadius;
  newShape.setCircleRadius(newRadius);

  return;
}

void
ComposedShape::inputRectangleData(ComposedShape::ShapeElem & newShape) {
  int newWidth, newHeight;

  cout << "Please enter the width: ";
  cin >> newWidth;
  cout << "Please enter the height: ";
  cin >> newHeight;

  newShape.setRectWidth(newWidth);
  newShape.setRectHeight(newHeight);
  return;
}

void
ComposedShape::inputTriangleData(ComposedShape::ShapeElem & newShape) {
  int newEdge;

  cout << "Please enter the edge of the equilateral triangle: ";
  cin >> newEdge;
  newShape.setTriangleEdge(newEdge);
  newShape.setTriangleRotationAngle(0);
  return;
}

void
ComposedShape::drawContainer(ostream& filePtr, int width, int height) {
  filePtr  << "<svg version=\"1.1\" baseProfile=\"full\" "
        << " width= \"" << width*1.5 << "\""
        << " height= \"" << height*1.5  << "\""
        << " xmlns=\"http://www.w3.org/2000/svg\"> "
        << endl << endl;
  return;
}

void
ComposedShape::initSvgFile(ostream& filePtr) {

  Point tPeakNode, tLeftBtmNode, tRightBtmNode;  //  triangle nodes
  int circleRad, rectWidth, rectHeight, triangleEdge;
  switch ( container.getShapeName() ) {

    //svg file is initialized.
    case Shape_name :: circle :
      circleRad = container.getCircleRadius();
      container.setCircleCenter(circleRad, circleRad);
      drawContainer(filePtr, circleRad*2, circleRad*2);
      filePtr<< container.getCircle();
      break;

    case Shape_name :: rectangle :
      rectWidth = container.getRectWidth();
      rectHeight= container.getRectHeight();
      container.setRectStartPoint(0,0);
      drawContainer(filePtr, rectWidth, rectHeight);
      filePtr << container.getRectangle();
      break;
    case Shape_name :: triangle :
      triangleEdge = container.getTriangleEdge();
      container.setTrianglePeakPoint((triangleEdge/2),0);
      container.setTriangleRotationAngle(0);
      drawContainer(filePtr, triangleEdge, triangleEdge);
      filePtr << container.getTriangle();
      break;
  }
  return ;
}

void
ComposedShape::optimalFit() {
  // cout << "I am in \n";

  switch(container.getShapeName()) {

    case Shape_name::circle :
      // cout << "I am in circle\n";
      switch( sampleSmallShape.getShapeName()) {
        case Shape_name::circle :
          fillCircleWithCircle();
          break;
        case Shape_name::rectangle :
          fillCircleWithRectangle();
          break;
        case Shape_name::triangle :
          fillCircleWithTriangle();
          break;
      }
      break;

    case Shape_name::rectangle :
      // cout << "I am in rectangle\n";
      switch( sampleSmallShape.getShapeName()) {
        case Shape_name::circle :
          fillRectangleWithCircle();
          break;
        case Shape_name::rectangle :
          // cout << "I am in insideREctangle\n";
          fillRectangleWithRectangle();
          break;
        case Shape_name::triangle :
          fillRectangleWithTriangle();
          break;
      }
      break;

    case Shape_name::triangle :
      // cout << "I am in triangle\n";
      switch( sampleSmallShape.getShapeName()) {
        case Shape_name::circle :
          fillTriangleWithCircle();
          break;
        case Shape_name::rectangle :
          fillTriangleWithRectangle();
          break;
        case Shape_name::triangle :
          fillTriangleWithTriangle();
          break;
      }
      break;
    default :
      cout << "There is a problem, control optimalFit function.\n";
  }
}

void
ComposedShape::fillCircleWithCircle( ) {

  double theta, totalArea, coveredArea;
  int count,
      containerRad, smallShapeRad,
      tempPosCol, tempPosRow, // pos of applicant small circle.
      designRadius;           // to determine pos of small circles.

  count=0;
  containerRad=container.getCircleRadius();
  smallShapeRad=sampleSmallShape.getCircleRadius();
  cout << "It is being calculated..." << endl;
  for ( designRadius = (containerRad - smallShapeRad);
        designRadius >= smallShapeRad;
        designRadius -= (smallShapeRad*2)
      ) {
    for ( theta=0; theta <= (2*PI); theta+=(DEG/1000)) {
      // Possible small circle center is calculated.
      tempPosCol =  (containerRad +(designRadius) * cos(theta));
      tempPosRow =  (containerRad +(designRadius) * sin(theta));
      if (isCircleIntersectWithOtherCircles(tempPosCol, tempPosRow) == false) {
        sampleSmallShape.setCircleCenter(tempPosCol, tempPosRow);
        smallShape.push_back(sampleSmallShape);
        ++count;
      }
    }
  }
  totalArea = (PI * containerRad * containerRad );
  coveredArea = (count* PI * (smallShapeRad*smallShapeRad) );

  showCalcResults(count, totalArea, coveredArea);
  return;
}

void
ComposedShape::fillCircleWithRectangle() {
  Point newRect;      //  applicant small rect start pos.
  double theta, totalArea, coveredArea;
  int count,
      circleRad,
      tolerance;  // some free space btw rect and circle to prevent intersection.

  cout << "It is being calculated...\n";
  count=0;
  tolerance = 2;
  circleRad = container.getCircleRadius();
  for ( theta=(3*PI/2.0); theta >(PI/2.0) ; theta-=(DEG/100) ) { //from 8th to 7th octant of circle
    //applicant rectangle's top-left point.
    newRect.setRow(circleRad + tolerance +(circleRad * sin(theta)));
    newRect.setCol(circleRad + tolerance +(circleRad * cos(theta)));

    if(theta <= PI ) {  //lowerside of the circle (SVG direction is reverse)
      newRect.setRow(newRect.getRow()- sampleSmallShape.getRectHeight()*2 + tolerance);
      // it is shifted inside of circle.
    }

    if(smallShape.size() == 0 ||
       ((abs(sampleSmallShape.getRectStartPointRow() - newRect.getRow()) >=
                                        (sampleSmallShape.getRectHeight()) ) &&
        isRectInCircle(newRect) == true &&
        isRectIntersectToTheOthers(newRect) == false )) {

      sampleSmallShape.setRectStartPoint(newRect.getCol(), newRect.getRow());
      smallShape.push_back(sampleSmallShape);
      ++count;

      //applicant rectangle's top-left point.
      newRect.setRow(sampleSmallShape.getRectStartPointRow());
      newRect.setCol(sampleSmallShape.getRectStartPointCol() + sampleSmallShape.getRectWidth());
      // then it is started to add rectangles next to prev one as much as possible.
      while ( isRectInCircle(newRect) ==true &&
                              isRectIntersectToTheOthers(newRect) == false ) {

        sampleSmallShape.setRectStartPoint(newRect.getCol(), newRect.getRow());
        smallShape.push_back(sampleSmallShape);
        ++count;

        //applicant rectangle's top-left point.
        newRect.setRow(sampleSmallShape.getRectStartPointRow());
        newRect.setCol(sampleSmallShape.getRectStartPointCol() + sampleSmallShape.getRectWidth());
      }
    }
  }

  totalArea = (PI * circleRad * circleRad);
  coveredArea = (count*sampleSmallShape.getRectWidth()*sampleSmallShape.getRectHeight());
  showCalcResults(count, totalArea, coveredArea);
  return;
}

void
ComposedShape::fillCircleWithTriangle() {

  Point newTri;      // last added small triangle.
  double theta, totalArea, coveredArea, height;
  bool reversed;
  int count, circleRad, triEdge,
      tolerance;// some free space btw triangle and circle to prevent intersection.

  cout << "It is being calculated...\n";
  circleRad = container.getCircleRadius();
  triEdge = sampleSmallShape.getTriangleEdge();
  height = sqrt(3.0)*triEdge/2.0;
  count=0;
  tolerance=triEdge/2;

  for ( theta=(3*PI/2.0); theta >=(PI/2) ; theta-=(DEG/100) ) { //from 8th to 7th octant of circle

    //applicant triangle's top-left point.
    newTri.setRow(circleRad+(circleRad * sin(theta)));
    if(theta>PI)//upside of the circle
      newTri.setCol(circleRad +tolerance + (circleRad * cos(theta)) );
    else  //underside of the circle
      newTri.setCol(circleRad +(tolerance*1.5) + (circleRad * cos(theta)) );

    //following if statement is a temporary solution and should be improved.
    if(isTriInCircle(newTri)==false )
      newTri.setCol(newTri.getCol()+(1.5*triEdge));

    // isTriInCirce function should be made strong and then it will be enought
    // to call only inTriInCircle in this statement.
    if((smallShape.size()== 0 ||
        (abs(sampleSmallShape.getTrianglePeakPointRow() - (newTri.getRow())) >= height)) &&
        isTriInCircle(newTri) ==true){

      sampleSmallShape.setTrianglePeakPoint(newTri.getCol(), newTri.getRow());
      smallShape.push_back(sampleSmallShape);
      //applicant's top-left point.
      newTri.setRow(newTri.getRow() );
      newTri.setCol(newTri.getCol()+triEdge );
      // then it is started to add triangles next to prev one as much as possible.
      while ( isTriInCircle(newTri) ==true) {

        sampleSmallShape.setTrianglePeakPoint(newTri.getCol(), newTri.getRow());
        smallShape.push_back(sampleSmallShape);
        ++count;

        //applicant triangle's top-left point.
        newTri.setRow(newTri.getRow());
        newTri.setCol(newTri.getCol() + triEdge);
      }
    }
  }
  totalArea = (PI * circleRad * circleRad);
  coveredArea = count*(sqrt(3.0)*(triEdge*triEdge)/4.0);
  showCalcResults(count, totalArea, coveredArea);
  return;
}

void
ComposedShape::fillRectangleWithCircle() {
  double totalArea, coveredArea;
  int count,
      horizSmallCircleNum, vertSmallCircleNum, //expected values
      r, c,       //  loop variables
      circleRad;  //  radius of the small circle

  circleRad = sampleSmallShape.getCircleRadius();
  count=0;
  //  small circle numbers are calculated in horizontal and vertical.
  if(( container.getRectWidth() < circleRad*2) || (container.getRectHeight() < circleRad*2)) {
    cout << "Unfortunately, any circle could not be fit to the main container.\n";
    return;
  }
  else  {
      horizSmallCircleNum  = container.getRectWidth()/ (circleRad*2);
      vertSmallCircleNum = container.getRectHeight()/ (circleRad*2);
  }
  cout << "It is being calculated...\n";
  //  center of circles are determined.
  for (r=0;  r < vertSmallCircleNum; ++r) {
    for (c = 0; c < horizSmallCircleNum; ++c) {
      sampleSmallShape.setCircleCenter(c*(circleRad*2)+circleRad, r*(circleRad*2)+circleRad);
      smallShape.push_back(sampleSmallShape);
      ++count;
    }
  }
  totalArea = (container.getRectHeight()*container.getRectWidth());
  coveredArea = (count * PI*circleRad*circleRad );
  showCalcResults(count, totalArea, coveredArea);
  return;
}

//This function could be seperated two function.
void
ComposedShape::fillRectangleWithRectangle() {

   ShapeElem vertSmallShape;   //  height and width of small shape are swapped
   double totalArea, coveredArea;
   int smallRectWidth, smallRectHeight, containerWidth, containerHeight;
   int count,              //  counter
       r, c;               //  loop variables

    smallRectWidth = sampleSmallShape.getRectWidth();
    smallRectHeight = sampleSmallShape.getRectHeight();
    containerWidth = container.getRectWidth();
    containerHeight = container.getRectHeight();

   if( (smallRectWidth * smallRectHeight) > (containerWidth*containerHeight) ){
     cout<< "Unfortunately, any small rectangle can not be fit to the main Container.\n";
     return;
   }

   vertSmallShape.setShapeName(sampleSmallShape.getShapeName());
   vertSmallShape.setRectWidth(sampleSmallShape.getRectHeight());
   vertSmallShape.setRectHeight(sampleSmallShape.getRectWidth());

   count=0;
   // It is wanted to keep as less as possible unused area at the top of stack.
   if((containerHeight % smallRectHeight) <= (containerHeight % smallRectWidth)){
     cout << "It is being calculated...\n";

     // cout <<"mh,mw: "
     //      <<(containerHeight % smallRectHeight) << ", "
     //      << (containerHeight % smallRectWidth)
     //      <<endl<<endl;

     // if normal form of smallShape is more efficient.
     for( r=0; r<=(containerHeight - smallRectHeight); r+= smallRectHeight){
       for ( c=0; c<= (containerWidth- smallRectWidth); c+= smallRectWidth ) {
         sampleSmallShape.setRectStartPoint(c, r);
         smallShape.push_back(sampleSmallShape);
         ++count;
       }
     }

     //if we still have some area to fit rotated rectangle.
     if(   ((smallShape.back().getRectStartPointCol() + vertSmallShape.getRectWidth()) <=
           (containerWidth) ) &&
           (containerHeight >= vertSmallShape.getRectHeight())
       ) {
           for ( c = (smallShape.back().getRectStartPointCol()) + smallRectWidth;
                 vertSmallShape.getRectWidth() <= (containerWidth - c);
                 c += vertSmallShape.getRectWidth()
            ) {
              for ( r = 0;
                    vertSmallShape.getRectHeight() <= (containerHeight- r);
                    r += vertSmallShape.getRectHeight()
              ){
                vertSmallShape.setRectStartPoint(c, r);
                smallShape.push_back(vertSmallShape);
                ++count;
           }
         }
     }

     totalArea = (containerWidth * containerHeight);
     coveredArea =count*(smallRectWidth * smallRectHeight);
     showCalcResults(count, totalArea, coveredArea);
   }
   else {
     // if vertical version of small shape is more efficient "width" and
     // "height" are swapped then this function is recalled.
     sampleSmallShape = vertSmallShape;
     fillRectangleWithRectangle();
   }
   return;
}

void
ComposedShape::fillRectangleWithTriangle() {
  double totalArea, coveredArea;
  int triEdge, containerWidth, containerHeight,
      count,  //  counter
      h,      //  height of the triangle
      r,c;    //  loop variables

  count = 0;
  triEdge=sampleSmallShape.getTriangleEdge();
  containerWidth=container.getRectWidth();
  containerHeight = container.getRectHeight();
  h = (double(triEdge)/2.0) * (sqrt(3.0));

  //  plain triangles
  for( r=0; r<=(containerHeight - h); r+=h ) {
   for(c = double(triEdge)/ 2.0; c<=(containerWidth-(triEdge/2)); c += triEdge){
       sampleSmallShape.setTrianglePeakPoint(c,r);
       smallShape.push_back(sampleSmallShape);
       ++count;
   }
  }

  //  reverse triangles
  for( r= h; r<= (containerHeight); r+= h ) {
   for( c= triEdge; c<= (containerWidth- triEdge); c+= triEdge ) {
     sampleSmallShape.setTrianglePeakPoint(c,r);
     sampleSmallShape.setTriangleRotationAngle(180);
     smallShape.push_back(sampleSmallShape);
     ++count;
   }
  }

  totalArea = (containerWidth * containerHeight);
  coveredArea =count* (double(triEdge* triEdge* sqrt(3))/ 4.0);
  showCalcResults(count, totalArea, coveredArea);
  return;
}

void
ComposedShape::fillTriangleWithCircle() {

  double radius, height, totalArea, coveredArea;
  int containerEdge,count, i, c, r;

  cout << "It is being calculated.\n";
  count =0;
  i=0;
  containerEdge = container.getTriangleEdge();
  container.setTrianglePeakPoint(containerEdge/2, 0);
  radius = sampleSmallShape.getCircleRadius();
  height = double(containerEdge)/2.0*(sqrt(3.0));
  for ( r =  height-radius; r >= (radius*2.0); r -= radius/sqrt(3.0)   ){
    for ( c= (2.0*radius) +(2.0*i*sqrt(3.0));
          c< (containerEdge - (sqrt(3)*radius) - (2*i*sqrt(3.0)));
          c+= radius/(sqrt(3.0))){
      if(isCircleIntersectWithOtherCircles(c,r)==false){
        sampleSmallShape.setCircleCenter(c,r);
        smallShape.push_back(sampleSmallShape);
        ++count;
      }
    }
    ++i;
  }

  totalArea = (containerEdge*containerEdge)*sqrt(3)/4.0;
  coveredArea = count *( PI * radius* radius);
  showCalcResults(count, totalArea, coveredArea);
  return;
}

void
ComposedShape::fillTriangleWithRectangle() {
  double tHeight, r, c, i, totalArea, coveredArea;
  int count, triEdge, rectWidth, rectHeight;

  cout << "It is being calculated.\n";
  i=1;
  count=0;
  rectWidth = sampleSmallShape.getRectWidth();
  rectHeight  = sampleSmallShape.getRectHeight();
  triEdge = container.getTriangleEdge();
  container.setTrianglePeakPoint(triEdge/2, 0);
  tHeight  = double(triEdge/2.0)*sqrt(3);
  for(r= tHeight- rectHeight; r>= (rectWidth/2.0)*sqrt(3.0); r-= rectHeight){
    for ( c = i*(rectHeight/sqrt(3.0));
          c <= triEdge-(i/sqrt(3.0)*rectHeight)-rectWidth;
          c += rectWidth
        ) {
          sampleSmallShape.setRectStartPoint(c, r);
          smallShape.push_back(sampleSmallShape);
          ++count;
        }
        ++i;
      }

  totalArea = (triEdge*triEdge)*sqrt(3)/4.0;
  coveredArea = count*(rectWidth* rectHeight);
  showCalcResults(count, totalArea, coveredArea);
  return;
}

void
ComposedShape::fillTriangleWithTriangle() {
  double  mainHeight, smallHeight,
          containerEdge, smallShapeEdge,
          totalArea, coveredArea, r, c, i;
  int count;

  cout << "It is being calculated.\n";
  i=1;
  count=0;
  containerEdge =container.getTriangleEdge();
  smallShapeEdge =sampleSmallShape.getTriangleEdge();
  container.setTrianglePeakPoint(containerEdge/2, 0);
  mainHeight  = double(containerEdge /2.0)*sqrt(3);
  smallHeight = double(smallShapeEdge / 2.0)*sqrt(3);

  for(r=mainHeight-smallHeight; r >= -smallHeight; r-=smallHeight ){
    //  plain small triangles are being determined.
    for ( c = i*((smallShapeEdge)/2.0);
          c <= (containerEdge - ((i/2.0)*smallShapeEdge));
          c += (smallShapeEdge)
    ) {
      sampleSmallShape.setTrianglePeakPoint(c,r);
      sampleSmallShape.setTriangleRotationAngle(0);
      smallShape.push_back(sampleSmallShape);
      ++count;
    }

    // reverse small triangles are being determined.
    for ( c = (i+1)*smallShapeEdge/2.0;
          c <= (containerEdge- ((i+1)*smallShapeEdge)/2);
          c += (smallShapeEdge)
    ) {
      sampleSmallShape.setTrianglePeakPoint(c,(r+smallHeight));
      sampleSmallShape.setTriangleRotationAngle(180);
      smallShape.push_back(sampleSmallShape);
      ++count;
    }
    ++i;
  }

  totalArea = (containerEdge*containerEdge)*sqrt(3)/4.0;
  coveredArea = count*((smallShapeEdge*smallShapeEdge)*sqrt(3)/4.0);
  showCalcResults(count, totalArea, coveredArea);
  return;
}

bool
ComposedShape::isCircleIntersectWithOtherCircles(int smallCircleCenterCol, int smallCircleCenterRow) {
  bool intersect;
  double distance;
  int i;

  i=0;
  intersect = false;
  while ( intersect == false && i< smallShape.size() ) {
    distance = sqrt( pow((smallShape[i].getCircleCenterCol() - smallCircleCenterCol), 2) +
                    pow((smallShape[i].getCircleCenterRow() - smallCircleCenterRow), 2) );
    if ( distance < (smallShape[i].getCircleRadius()*2) )
      intersect = true;

    ++i;
  }
  return intersect;
}

bool
ComposedShape::isTriInCircle(Point &newTri){
  bool fit;
  double dist1, dist2, dist3;
  int circleRad;
  Point up, rightDown, leftDown;

  circleRad= container.getCircleRadius();
  // applicant rectangle vertices.
  up     = newTri;
  leftDown.setRow(newTri.getRow() + sqrt(3.0)/2.0*sampleSmallShape.getTriangleEdge());
  leftDown.setCol(newTri.getCol() - sampleSmallShape.getTriangleEdge()/2 );
  rightDown.setRow(newTri.getRow() + sqrt(3.0)/2.0*sampleSmallShape.getTriangleEdge());
  rightDown.setCol(newTri.getCol() + sampleSmallShape.getTriangleEdge()/2 );

  // dist between new final point and main container center.
  dist1 =  calcDistBtwTwoPoint(up.getCol(), circleRad, up.getRow(), circleRad);
  dist2 =  calcDistBtwTwoPoint(leftDown.getCol(), circleRad, leftDown.getRow(), circleRad);
  dist3 =  calcDistBtwTwoPoint(rightDown.getCol(), circleRad, rightDown.getRow(), circleRad);

  if ( (dist1 >= circleRad) || (dist2 >= circleRad) || (dist3 >= circleRad) )
    return false;
  else
    return true;
}

bool
ComposedShape::isRectInCircle(Point &newRect) {

  double dist1, dist2, dist3, dist4;
  int radius;
  Point rightUp, rightDown, leftUp, leftDown;

  radius = container.getCircleRadius();
  // applicant rectangle vertices.
  leftUp     = newRect;
  leftDown.setRow(newRect.getRow() + sampleSmallShape.getRectHeight());
  leftDown.setCol(newRect.getCol());
  rightUp.setRow(newRect.getRow());
  rightUp.setCol(newRect.getCol() + sampleSmallShape.getRectWidth());
  rightDown.setRow(newRect.getRow() + sampleSmallShape.getRectHeight());
  rightDown.setCol(newRect.getCol() + sampleSmallShape.getRectWidth());

  // dist between new final point and main container center.
  dist1 = calcDistBtwTwoPoint(leftUp.getCol(), radius, leftUp.getRow(), radius);
  dist2 = calcDistBtwTwoPoint(leftDown.getCol(), radius, leftDown.getRow(), radius);
  dist3 = calcDistBtwTwoPoint(rightUp.getCol(), radius, rightUp.getRow(), radius);
  dist4 = calcDistBtwTwoPoint(rightDown.getCol(), radius, rightDown.getRow(), radius);


  if ((dist1 >= radius) || (dist2 >= radius) || (dist3 >= radius) || (dist4 >= radius))
    return false;
  else
    return true;
}

bool
ComposedShape::isRectIntersectToTheOthers(Point & newRect) {

  bool intersect;
  int i;
  double distVert, distHoriz;

  intersect = false;
  i=0;
  while ( intersect == false && i<smallShape.size() ) {
    distVert  = abs((smallShape[i].getRectStartPointRow()) - newRect.getRow());
    distHoriz = abs((smallShape[i].getRectStartPointCol()) - newRect.getCol());

    if( distVert < sampleSmallShape.getRectHeight() &&
        distHoriz < sampleSmallShape.getRectWidth()    ){
      intersect = true;
    }
    ++i;
  }
  return intersect;
}

ostream&
operator << (ostream& outputStream, ComposedShape& cs) {

  cs.initSvgFile(outputStream);
  switch (cs.sampleSmallShape.getShapeName()) {
   case Shape_name :: circle :
     for (auto i=0; i<cs.smallShape.size(); ++i){
       outputStream << cs.smallShape[i].getCircle();
     }
     break;

   case Shape_name :: rectangle :
     for (auto i=0; i<cs.smallShape.size(); ++i)
       outputStream << cs.smallShape[i].getRectangle();
     break;

   case Shape_name :: triangle :
     for (auto i=0; i<cs.smallShape.size(); ++i)
       outputStream << cs.smallShape[i].getTriangle();
     break;
   default:
     cout << "There is a problem with ComposedShape::drawShape function.\n";
  }

  outputStream << "</svg>";
  cs.smallShape.clear();
}

void
ComposedShape::showCalcResults(int count, int totalArea, int coveredArea) {
  cout  << "\nResults...\n"
        << count<< " number small shape is fitted to main container.\n"
        << "Main container area : " << totalArea << endl
        << "Covered area : "        << coveredArea << endl
        << "Left empty space :" << totalArea - coveredArea << endl <<endl;
  return;
}

ComposedShape::ShapeElem::ShapeElem () {
  name = Shape_name::circle;
  shape =new Circle;
}

ComposedShape::ShapeElem::ShapeElem (Shape_name sName) {
  // cout << "I am in shape elem constructor\n";
  switch(sName){
    case Shape_name::circle :
      shape = new Circle;
      name =sName;
    break;

    case Shape_name::rectangle :
      shape = new Rectangle;
      name =sName;
    break;

    case Shape_name::triangle :
      shape = new Triangle;
      name =sName;
    break;
    default :
      cout<< "There is something wrong in ShapeElem constructor\n";
  }
}

ComposedShape::ShapeElem::ShapeElem (const ComposedShape::ShapeElem &obj){
  if(this != &obj) {
    switch(obj.name){
      case Shape_name::circle     :
        delete (Circle*)shape; shape =nullptr;
        shape =new Circle;
        *((Circle*)shape)=*((Circle*)obj.shape);  break;
      case Shape_name::rectangle  :
        delete (Rectangle*)shape; shape =nullptr;
        shape =new Rectangle;
        *((Rectangle*)shape)=*((Rectangle*)obj.shape);  break;
      case Shape_name::triangle   :
        delete (Triangle*)shape; shape =nullptr;
        shape =new Triangle;
        *((Triangle*)shape)=*((Triangle*)obj.shape); break;
      default : cout << "There is a problem in ShapeElem copy constructor\n";
    }
    name=obj.name;
  }
}

ComposedShape::ShapeElem::~ShapeElem () {
  if(shape!=nullptr){
    // cout << "I am in destructor\n";
    switch(name){
      case Shape_name::circle     : delete (Circle*)shape; break;
      case Shape_name::rectangle  : delete (Rectangle*)shape; break;
      case Shape_name::triangle   : delete (Triangle*)shape; break;
      default : cout << "There is a problem in ShapeElem destructor\n";
    }
    shape= nullptr;
  }
}

ComposedShape::ShapeElem
ComposedShape::ShapeElem:: operator =(const ComposedShape::ShapeElem &obj) {
  // cout << "inside = operator \n";
  if(this == &obj){
    return *this;
  }
  else{
    switch(obj.name){
      case Shape_name::circle     :
        delete (Circle*)shape; shape =nullptr;
        shape =new Circle;
        *((Circle*)shape)=*((Circle*)obj.shape);  break;
      case Shape_name::rectangle  :
        delete (Rectangle*)shape; shape =nullptr;
        shape =new Rectangle;
        *((Rectangle*)shape)=*((Rectangle*)obj.shape);  break;
      case Shape_name::triangle   :
        delete (Triangle*)shape; shape =nullptr;
        shape =new Triangle;
        *((Triangle*)shape)=*((Triangle*)obj.shape); break;
      default : cout << "There is a problem in ShapeElem copy constructor\n";
    }
    name=obj.name;
  }
  return *this;
}

void
ComposedShape::ShapeElem::setCircle(const Circle& obj) {
  *this=ShapeElem(Shape_name::circle);
  *(static_cast<Circle*>(shape))=obj;
  return;
}

void
ComposedShape::ShapeElem::setRectangle(const Rectangle& obj) {
  *this=ShapeElem(Shape_name::rectangle);
  *(static_cast<Rectangle*>(shape))=obj;
  return;
}

void
ComposedShape::ShapeElem::setTriangle(const Triangle& obj) {
  *this=ShapeElem(Shape_name::triangle);
  *(static_cast<Triangle*>(shape))=obj;
  return;
}

void
ComposedShape::ShapeElem::setShapeName(Shape_name newName) {
  name=newName; return;
}

void
ComposedShape::ShapeElem::setCircleRadius(int newRadius) {
  ((Circle*)shape)->setRadius(newRadius);   return;
}

void
ComposedShape::ShapeElem::setCircleCenter(int newCol, int newRow) {
  ((Circle*)shape)->setCenter(newCol, newRow);  return;
}

void
ComposedShape::ShapeElem::setRectStartPoint(int newCol, int newRow) {
  ((Rectangle*)shape)->setStartPoint(newCol, newRow); return;
}

void
ComposedShape::ShapeElem::setRectWidth(int newWidth) {
  ((Rectangle*)shape)->setWidth(newWidth); return;
}

void
ComposedShape::ShapeElem::setRectHeight(int newHeight) {
  ((Rectangle*)shape)->setHeight(newHeight); return;
}


void
ComposedShape::ShapeElem::setTrianglePeakPoint(int newCol, int newRow) {
  ((Triangle*)shape)->setPeakPoint(newCol, newRow); return;
}

void
ComposedShape::ShapeElem::setTriangleEdge(int newEdge) {
  ((Triangle*)shape)->setEdge(newEdge); return;
}

void
ComposedShape::ShapeElem::setTriangleRotationAngle(int newRotationAngle) {
  ((Triangle*)shape)->setRotationAngle(newRotationAngle); return;
}

int
ComposedShape::ShapeElem::getCircleCenterCol() {
  return (static_cast<Circle*>(shape))->getCenterCol();
}

int
ComposedShape::ShapeElem::getCircleCenterRow() {
  return (static_cast<Circle*>(shape))->getCenterRow();
}

int
ComposedShape::ShapeElem::getCircleRadius() {
  return (static_cast<Circle*>(shape))->getRadius();
}

int
ComposedShape::ShapeElem::getRectStartPointCol() {
  return (static_cast<Rectangle*>(shape))->getStartPointCol();
}

int
ComposedShape::ShapeElem::getRectStartPointRow() {
  return (static_cast<Rectangle*>(shape))->getStartPointRow();
}

int
ComposedShape::ShapeElem::getRectWidth() {
  return (static_cast<Rectangle*>(shape))->getWidth();
}

int
ComposedShape::ShapeElem::getRectHeight() {
  return (static_cast<Rectangle*>(shape))->getHeight();
}

int
ComposedShape::ShapeElem::getTrianglePeakPointCol() {
  return (static_cast<Triangle*>(shape))->getPeakPointCol();
}

int
ComposedShape::ShapeElem::getTrianglePeakPointRow() {
  return (static_cast<Triangle*>(shape))->getPeakPointRow();
}

Point
ComposedShape::ShapeElem::getTrianglePeakPoint()  {
  return (static_cast<Triangle*>(shape))->getPeakPoint();
}

int
ComposedShape::ShapeElem::getTriangleEdge()         {
  return (static_cast<Triangle*>(shape))->getEdge();
}

int
ComposedShape::ShapeElem::getTriangleRotationAngle(){
  return (static_cast<Triangle*>(shape))->getRotationAngle();
}
