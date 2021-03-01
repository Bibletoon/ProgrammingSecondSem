#include <cassert>
#include <iostream>

#include "Point.h"
#include "PolygonalChain.h"
#include "ClosedPolygonalChain.h"
#include "Polygon.h"
#include "RegularPolygon.h"
#include "Trapezoid.h"
#include "Triangle.h"

const double EPS = 1e-9;

void PointCheck() {
    const Point p1;
    assert(p1.GetX() == 0 && p1.GetY() == 0);
    const Point p2(3, 4);
    assert(p2.GetX() == 3 && p2.GetY() == 4);
}

void InheritancePolygonalChainCheck(const PolygonalChain* pc, const PolygonalChain* cpc) {
    assert(pc->GetPerimeter() == 9);
    assert(cpc->GetPerimeter() == 12);
}

void PolygonsCheck() {
    Point* a = new Point[3]{ Point(0, 0), Point(3, 4), Point(3, 0) };
    Point* b = new Point[4]{ Point(0, 0), Point(1, 4), Point(3, 4), Point(3, 0) };
    const Polygon p(3, a);
    const Triangle t(3, a);
    const Trapezoid tr(4, b);
    const PolygonalChain pc(3, a);
    assert(pc.GetNumberOfPoints() == 3 && pc.GetPoint(1).GetX() == 3 && pc.GetPoint(1).GetY() == 4);
    assert(pc.GetPerimeter() == 9);
    const ClosedPolygonalChain cpc(3, a);
    a[1] = Point();
    assert(cpc.GetNumberOfPoints() == 3 && cpc.GetPoint(1).GetX() == 3 && cpc.GetPoint(1).GetY() == 4);
    assert(cpc.GetPerimeter() == 12);
    InheritancePolygonalChainCheck(&pc, &cpc);
    assert(p.GetArea() == 6);
    assert(t.IsRight());
    Triangle trSharpestAsMyHand(3, new Point[3]{ Point(0, 0), Point(1, 1), Point(0, 100) });
    assert(!trSharpestAsMyHand.IsRight());
    RegularPolygon rp(4, new Point[4]{ Point(0, 0), Point(0, 2), Point(2, 2), Point(2, 0) });
    assert(abs(rp.GetArea() - 4) < EPS && abs(rp.GetPerimeter() - 8) < EPS);
    Trapezoid tra(4, b);
    tra = tr;
    Trapezoid* trap = new Trapezoid(4, b);
    Trapezoid trCopy(*trap);
    delete trap;
    assert(abs(trCopy.GetArea() - 10) < EPS);
}

void checkPolymorphArea(int count,const Polygon* polygons)
{
	for (int i=0;i<count;i++)
	{
        assert(abs(polygons[i].GetArea() - 16) < EPS);
	}
}

void checkPolymorph()
{
    Point* pointsPolygon = new Point[6]{ Point(0,0),Point(1,4),Point(3,4),Point(6,2),Point(3,0) };
    Point* pointsTriangle = new Point[3]{ Point(0,0),Point(4,0),Point(0,8) };
    Point* pointsTrapezoid = new Point[4]{ Point(0,0),Point(2,2),Point(8,2),Point(10,0) };
    Point* pointsRegularPolygon = new Point[4]{ Point(0,0),Point(0,4),Point(4,4),Point(4,0) };

    Polygon* areaCalculatable = new Polygon[4]{ Polygon(5,pointsPolygon), Triangle(pointsTriangle), Trapezoid(pointsTrapezoid), RegularPolygon(4,pointsRegularPolygon) };

    checkPolymorphArea(4, areaCalculatable);
}

int main() {
    std::cout << "Starting \"tests\"" << std::endl;
    PointCheck();
    PolygonsCheck();
    std::cout << "All \"tests\" passed" << std::endl;

    Point* pointsTrapezoid = new Point[4]{ Point(1, 1), Point(3, 3), Point(5, 3), Point(6, 1) };
    Point* pointsSquare = new Point[4]{ Point(1, 1), Point(3, 3), Point(5, 1), Point(3, -1) };

    RegularPolygon square(4, pointsSquare);
    Trapezoid trapezoid(pointsTrapezoid);
    std::cout << "Trapezoid points: ";
	for (int i=0;i<4;i++)
	{
        std::cout << "(" << pointsTrapezoid[i].GetX() << ";" << pointsTrapezoid[i].GetY() << ") ";
	}
    std::cout << std::endl;

    std::cout << "Square points: ";
    for (int i = 0; i < 4; i++)
    {
        std::cout << "(" << pointsSquare[i].GetX() << ";" << pointsSquare[i].GetY() << ") ";
    }
    std::cout << std::endl;

    std::cout << "Perimeters: Trapezoid " << trapezoid.GetPerimeter() << " Square " << square.GetPerimeter() << std::endl;
    std::cout << "Areas: Trapezoid " << trapezoid.GetArea() << " Square " << square.GetArea() << std::endl;
}