#ifndef M4OEP_GRAPHICS_TSCOTT5_TRIANGLE_H
#define M4OEP_GRAPHICS_TSCOTT5_TRIANGLE_H

#include "shape.h"

struct triangleDimensions {
    double base;
    double height;

    /* Constructors */
    triangleDimensions();
    triangleDimensions(double b, double h);

    /* Overloaded Operator */
    friend std::ostream& operator << (std::ostream& outs, const triangleDimensions &d);
};

class Triangle : public Shape {
private:
    triangleDimensions size;
public:
    /* Constructors */
    Triangle();
    explicit Triangle(triangleDimensions size);
    explicit Triangle(color fill);
    explicit Triangle(point2D center);
    Triangle(color fill, point2D center);
    Triangle(color red, double green, double blue, double alpha);
    Triangle(double x, double y);
    Triangle(double red, double green, double blue, double alpha, double x, double y);
    Triangle(color fill, double x, double y);
    Triangle(double red, double green, double blue, double alpha, point2D center);
    Triangle(color fill, triangleDimensions size);
    Triangle(point2D center, triangleDimensions size);
    Triangle(color fill, point2D center, triangleDimensions size);
    Triangle(double red, double green, double blue, double alpha, triangleDimensions size);
    Triangle(double x, double y, triangleDimensions size);
    Triangle(double red, double green, double blue, double alpha, double x, double y, triangleDimensions size);
    Triangle(color fill, double x, double y, triangleDimensions size);
    Triangle(double red, double green, double blue, double alpha, point2D center, triangleDimensions size);

    /* Destructor */
    virtual ~Triangle() = default;

    /* Getters */
    triangleDimensions getSize() const;
    double getBase() const;
    double getHeight() const;
    double getLeftX() const override;
    double getRightX() const override;
    double getTopY() const override;
    double getBottomY() const override;

    /* Setters */
    void setSize(triangleDimensions size);
    void setSize(double base, double height);
    void setBase(double base);
    void setHeight(double height);
    void changeSize(double deltaWidth, double deltaHeight);
    void changeWidth(double delta);
    void changeHeight(double delta);

    /* Check if two Triangle objects are overlapping */
    bool isOverlapping(const Triangle &r) const;

    /* Draw */
    void draw() const override;

};
#endif //M4OEP_GRAPHICS_TSCOTT5_TRIANGLE_H
