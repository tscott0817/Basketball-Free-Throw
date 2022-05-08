#ifndef GRAPHICSEXAMPLES_CIRCLE_H
#define GRAPHICSEXAMPLES_CIRCLE_H

#include "shape.h"
#include "rect.h"

class Circle : public Shape {
private:
    double radius;
    bool scored;
public:
    /* Constructors */
    Circle();
    explicit Circle(double radius);
    explicit Circle(color fill);
    explicit Circle(point2D center);
    Circle(color fill, point2D center);
    Circle(double red, double green, double blue, double alpha);
    Circle(double x, double y);
    Circle(double red, double green, double blue, double alpha, double x, double y);
    Circle(color fill, double x, double y);
    Circle(double red, double green, double blue, double alpha, point2D center);
    Circle(color fill, double radius);
    Circle(point2D center, double radius);
    Circle(color fill, point2D center, double radius);
    Circle(double red, double green, double blue, double alpha, double radius);
    Circle(double x, double y, double radius);
    Circle(double red, double green, double blue, double alpha, double x, double y, double radius);
    Circle(color fill, double x, double y, double radius);
    Circle(double red, double green, double blue, double alpha, point2D center, double radius);

    /* Destructor */
    virtual ~Circle() = default;

    /* Getters */
    double getRadius() const;
    double getLeftX() const override;
    double getRightX() const override;
    double getTopY() const override;
    double getBottomY() const override;
    bool getScored();

    /* Setter */
    void setScored(bool scored);
    void setRadius(double r);
    void changeRadius(double delta);

    /* Overlapping */
    bool isOverlapping(const Circle &c) const;

    /* Collision */
    void collide(Circle &c);
    void collideRect(Rect &r);

    /* Draw */
    void draw() const override;

};

#endif //GRAPHICSEXAMPLES_CIRCLE_H
