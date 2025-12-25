#include "point2d.hpp"

class Circle
{
private:
    Point2d m_ref;
    float m_ratio;

public:
    //getters and setters
    void SetCircle(float ratio, Point2d ref);
    void SetCircle(float ratio, int xref, int yref);

    int GetRatio();
    Point2d GetReference();

};
