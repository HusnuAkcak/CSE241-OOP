#include "polygon.h"

using namespace std;

namespace svg {
  class Polyline {
  public:
    Polyline (const Polygon& newPolygon);
    Polyline (const vector<Polygon::Point2D> newPoints);
    Polyline (const Circle& newCircle);
    Polyline (const Rectangle& newRectangle);
    Polyline (const Triangle& newTriangle);
    Polyline (const Polygon::Point2D& newPoint);
    Polyline ();

    void setPolygon(const Polygon& newPolygon);
    void setCircle(const Circle& newCircle);
    void setRectangle(const Rectangle& newRectangle);
    void setTriangle(const Triangle& newTriangle);
    void setVectorPoint(const vector<Polygon::Point2D> vektorPoint2D);
    void setPoint(const Polygon::Point2D& newPoint);
    Polygon getPolygon() const;

    ostream& initSvgFile(ostream& outputStream);

    //OPERATOR OVERLOADINGS
    const Polygon::Point2D& operator [] (int index) const;
    Polygon::Point2D& operator [] (int index);
    bool operator ==(const Polyline& polyline2);
    bool operator !=(const Polyline& polyline2);
    Polyline operator +(const Polyline& polyline2);
    friend ostream& operator <<(ostream& outputStream, const Polyline& polyline);
  private:
    Polygon polygon;
  };
};
