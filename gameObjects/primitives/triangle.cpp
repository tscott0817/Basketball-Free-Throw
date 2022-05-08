#include "../../main.h"
#include "triangle.h"
#include <iostream>
using namespace std;

/********************* triangleDimensions Struct ********************/

triangleDimensions::triangleDimensions() : base(0), height(0){}

triangleDimensions::triangleDimensions(double b, double h) : base(b), height(h) {}

ostream& operator << (ostream& outs, const triangleDimensions &d) {
    outs << "[" << d.base << ", " << d.height <<  "]";
    return outs;
}

Triangle::Triangle() : Shape(), size({0, 0}) {
}

Triangle::Triangle(triangleDimensions size) : Shape() {
    setSize(size);
}

Triangle::Triangle(color fill) : Shape(fill), size({0, 0}) {
}

Triangle::Triangle(point2D center) : Shape(center), size({0, 0}) {
}

Triangle::Triangle(color fill, point2D center) : Shape(fill, center), size({0, 0}) {
}

//Triangle::Triangle(color red, double green, double blue, double alpha) : Shape(red, green, blue, alpha), size({0, 0}) {
//}

Triangle::Triangle(double x, double y) : Shape(x, y), size({0, 0}) {
}

Triangle::Triangle(double red, double green, double blue, double alpha, double x, double y) : Shape(red, green, blue, alpha, x, y), size({0, 0}) {
}

Triangle::Triangle(color fill, double x, double y) : Shape(fill, x, y), size({0, 0}) {
}

Triangle::Triangle(double red, double green, double blue, double alpha, point2D center) : Shape(red, green, blue, alpha, center), size({0, 0}) {
}

Triangle::Triangle(color fill, triangleDimensions size) : Shape(fill) {
    setSize(size);
}

Triangle::Triangle(point2D center, triangleDimensions size) : Shape(center) {
    setSize(size);
}

Triangle::Triangle(color fill, point2D center, triangleDimensions size) : Shape(fill, center) {
    setSize(size);
}

Triangle::Triangle(double red, double green, double blue, double alpha, triangleDimensions size) : Shape(red, green, blue, alpha) {
    setSize(size);
}

Triangle::Triangle(double x, double y, triangleDimensions size) : Shape(x, y) {
    setSize(size);
}

Triangle::Triangle(double red, double green, double blue, double alpha, double x, double y, triangleDimensions size) : Shape(red, green, blue, alpha, x, y) {
    setSize(size);
}

Triangle::Triangle(color fill, double x, double y, triangleDimensions size) : Shape(fill, x, y) {
    setSize(size);
}

Triangle::Triangle(double red, double green, double blue, double alpha, point2D center, triangleDimensions size) : Shape(red, green, blue, alpha, center) {
    setSize(size);
}

triangleDimensions Triangle::getSize() const {
    return size;
}

double Triangle::getBase() const {
    return size.base;
}

double Triangle::getHeight() const {
    return size.height;
}

double Triangle::getLeftX() const {
    return center.x - (size.base / 2.0);
}

double Triangle::getRightX() const {
    return center.x + (size.base / 2.0);
}

double Triangle::getTopY() const {
    return center.y - (size.height / 2.0);
}

double Triangle::getBottomY() const {
    return center.y + (size.height / 2.0);
}

void Triangle::setSize(triangleDimensions size) {
    if (size.base >= 0 && size.height >= 0) {
        this->size = size;
    }
}

void Triangle::setSize(double width, double height) {
    setSize({width, height});
}

void Triangle::setBase(double width) {
    setSize({width, size.height});
}

void Triangle::setHeight(double height) {
    setSize({size.base, height});
}

void Triangle::changeSize(double deltaWidth, double deltaHeight) {
    setSize({size.base + deltaWidth, size.height + deltaHeight});
}

void Triangle::changeWidth(double delta) {
    setSize({size.base + delta, size.height});
}

void Triangle::changeHeight(double delta) {
    setSize({size.base, size.height + delta});
}

void Triangle::draw() const {

    // Enables transparency
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glColor4f(fill.red, fill.green, fill.blue, fill.alpha);
    glBegin(GL_TRIANGLES);
    glVertex2i(center.x, getTopY()); // Top Center
    glVertex2i(getRightX(), center.y); // Bottom Right
    glVertex2i(getLeftX(), center.y); // Bottom Left

    glEnd();
}