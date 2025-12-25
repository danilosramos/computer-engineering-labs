#include "circle.hpp"
#include <vector>

int main()
{
    //teste de point anterior
    /*Point2d pt1, pt2, pt3;
    pt1.SetPoint2d(10,15);
    pt2 = pt1;
    pt3.SetPoint2d(20,35);

    vector<Point2d> vecPoints;
    vecPoints.push_back(pt1);
    vecPoints.push_back(pt2);
    vecPoints.push_back(pt3);

    for(size_t i=0; i<vecPoints.size(); i++)
    {
        cout << vecPoints.at(i).GetX() << "-" << vecPoints.at(i).GetY() << endl;
    }*/

    Point2d pt1, pt2, pt3;
    pt1.SetPoint2d(10,15);
    pt2 = pt1;
    pt3.SetPoint2d(20,35);

    Circle c1,c2,c3,c4;
    c1.SetCircle(10, pt1);
    c2.SetCircle(15, 5,5);
    c3.SetCircle(20, pt2);
    c4.SetCircle(30, pt3);

    vector<Circle> vecCircle;
    vecCircle.push_back(c1);
    vecCircle.push_back(c2);
    vecCircle.push_back(c3);
    vecCircle.push_back(c4);

    for(size_t i=0; i<vecCircle.size(); i++)
    {
        cout << "Ratio: " << vecCircle.at(i).GetRatio() << "-" << "PosXY: " << vecCircle.at(i).GetReference().GetX() << "-" << vecCircle.at(i).GetReference().GetY() << endl;
    }

    return 0;
}
