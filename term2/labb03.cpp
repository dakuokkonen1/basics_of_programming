#include <iostream>
#include <cmath>

// ����� ��� ����. ������
class Shape {
public:
    virtual void draw() const = 0;           // ����� ��� ����������� ������
    virtual void erase() = 0;                //           �������� ������
    virtual void move(double dx, double dy); //           ����������� ������
    virtual void rotate(double angle) = 0;   //           �������� ������
    virtual ~Shape() {}                      // ����. ����������
};

// ����� ��� �����
class Point : public Shape {
protected:
    double x;
    double y;

public:
    Point(double xCoord, double yCoord) : x(xCoord), y(yCoord) {}

    void draw() const override {
        std::cout << "����� (" << x << ", " << y << ")" << std::endl;
    }

    void erase() override {
        std::cout << "����. ����� (" << x << ", " << y << ")" << std::endl;
        // ������ ��������� �� �������� �����
    }

    void move(double dx, double dy) override {
        x += dx;
        y += dy;
        std::cout << "�������. ����� �� (" << dx << ", " << dy << ").  ���������� �����: (" << x << ", " << y << ")" << std::endl;
    }

    void rotate(double angle) override {
        // ������� ����� �� ������(��� ������)
        std::cout << "������� ����� �� " << angle << " ����." << std::endl;
    }
};

// ����� ��� ����� 
class Line : public Shape {
protected:
    Point startPoint;
    Point endPoint;

public:
    Line(const Point& start, const Point& end) : startPoint(start), endPoint(end) {}

    void draw() const override {
        std::cout << "����� �� (" << startPoint.x << ", " << startPoint.y << ") �� (" << endPoint.x << ", " << endPoint.y << ")" << std::endl;
    }

    void erase() override {
        std::cout << "����. ����� �� (" << startPoint.x << ", " << startPoint.y << ") �� (" << endPoint.x << ", " << endPoint.y << ")" << std::endl;
        // ������� �����
    }

    void move(double dx, double dy) override {
        startPoint.move(dx, dy);
        endPoint.move(dx, dy);
        std::cout << "�������. ����� �� (" << dx << ", " << dy << ")." << std::endl;
    }

    void rotate(double angle) override {
        // ����� ��� ������, ��� � � ������
        std::cout << "������� ����� �� " << angle << " ��������" << std::endl;
    }
};

// ����� ��� �������� 
class Square : public Shape {
protected:
    Point topLeft;
    double sideLength;

public:
    Square(const Point& topLeftCorner, double length) : topLeft(topLeftCorner), sideLength(length) {}

    void draw() const override {
        std::cout << "������� � ������� ����� ����� � ����� (" << topLeft.x << ", " << topLeft.y << ") � ������ ������� " << sideLength << std::endl;
    }

    void erase() override {
        std::cout << "����. �������� � ������� ����� ����� � ����� (" << topLeft.x << ", " << topLeft.y << ")" << std::endl;
        // ������� �������
    }

    void move(double dx, double dy) override {
        topLeft.move(dx, dy);
        std::cout << "�������. �������� �� (" << dx << ", " << dy << ")." << std::endl;
    }

    void rotate(double angle) override {
        std::cout << "������� �������� �� " << angle << " ��������." << std::endl;
    }
};

// ����� ��� ��������������
class Rectangle : public Shape {
private:
    double x;       //  x �������� ������ ����
    double y;       //  y �������� ������ ����
    double width;   // ������ ��������������
    double height;  // ������ ��������������

public:
    Rectangle(double startX, double startY, double w, double h) : x(startX), y(startY), width(w), height(h) {}
    // ����������� ��������������
    void draw() const override {
        std::cout << "������������� � ������� ����� ����� � ����� (" << x << ", " << y << "), ������: " << width << ", ������: " << height << std::endl;
    }
    // �������� ��������������
    void erase() override {
        std::cout << "�������� �������������� � ������� ����� ����� � ����� (" << x << ", " << y << ")" << std::endl;
    }
    // ����������� �������������� �� �������� �������� dx � dy
    void move(double dx, double dy) override {
        x += dx;
        y += dy;
        std::cout << "����������� �������������� �� (" << dx << ", " << dy << "). ����� ������� ����� ����: (" << x << ", " << y << ")" << std::endl;
    }

    // ������� �������������� �� �������� ����
    void rotate(double angle) override {
        std::cout << "������� �������������� �� " << angle << " ��������." << std::endl;
    }
};

// ����� ��� ����� 
class Rhombus : public Shape {
protected:
    double sideLength;  // ����� �������
    double angle;       // ���� ����� ��������� ����� (� ��������)

public:
    Rhombus(double length, double ang) : sideLength(length), angle(ang) {}

    // ����������� �����
    void draw() const override {
        std::cout << "���� � ������ ������� " << sideLength << " � ����� ����� ��������� " << angle << " ������" << std::endl;
    }

    // �������� �����
    void erase() override {
        std::cout << "�������� �����" << std::endl;
    }

    // ����������� ����� �� �������� �������� (dx, dy)
    void move(double dx, double dy) override {
        std::cout << "����������� ����� �� (" << dx << ", " << dy << ")" << std::endl;

    }

    // ������� ����� �� �������� ���� (� ��������)
    void rotate(double rotAngle) override {
        std::cout << "������� ����� �� " << rotAngle << " ������" << std::endl;
    }
};

// ����� ��� ��������������� 
class Parallelogram : public Shape {
protected:
    Point topLeft;      // ������� ����� ����
    double width;       // ������ ���������������
    double height;      // ������ ���������������
    double angle;       // ���� ����� ���������� � ������� �������� ���������������

public:
    Parallelogram(const Point& topLeftCorner, double w, double h, double ang)
        : topLeft(topLeftCorner), width(w), height(h), angle(ang) {}

    // ����������� ���������������
    void draw() const override {
        std::cout << "�������������� � ������� ����� ����� � ����� (" << topLeft.x << ", " << topLeft.y
            << "), ������: " << width << ", ������: " << height << ", ����: " << angle << " ������" << std::endl;
    }

    // �������� ���������������
    void erase() override {
        std::cout << "����. ��������������� � ������� ����� ����� � ����� (" << topLeft.x << ", " << topLeft.y << ")" << std::endl;
    }

    // ����������� ��������������� �� �������� �������� (dx, dy)
    void move(double dx, double dy) override {
        topLeft.move(dx, dy);
        std::cout << "�������. ��������������� �� (" << dx << ", " << dy << "). ����� ������� ����� ����: (" << topLeft.x << ", " << topLeft.y << ")" << std::endl;
    }

    // ������� ��������������� �� �������� ���� (� ��������)
    void rotate(double rotAngle) override {
        std::cout << "������� ��������������� �� " << rotAngle << " ������" << std::endl;

    }
};

int main() {

    // �����
    Point point(3.0, 4.0);
    point.draw();
    point.move(1.0, -2.0);
    std::cout << std::endl;

    // �����
    Point startPoint(1.0, 1.0);
    Point endPoint(5.0, 5.0);
    Line line(startPoint, endPoint);
    line.draw();
    line.move(-1.0, 2.0);
    std::cout << std::endl;

    // �������
    Point squareTopLeft(2.0, 2.0);
    Square square(squareTopLeft, 4.0);
    square.draw();
    square.move(3.0, 1.5);
    std::cout << std::endl;

    // �������������
    Point rectangleTopLeft(1.0, 1.0);
    Rectangle rectangle(rectangleTopLeft, 3.0, 5.0);
    rectangle.draw();
    rectangle.move(-2.0, 3.0);
    std::cout << std::endl;

    // ����
    Rhombus rhombus(4.0, M_PI / 3);
    rhombus.draw();
    rhombus.move(2.0, -1.0);
    std::cout << std::endl;

    // ��������������
    Point parallelogramTopLeft(0.0, 0.0);
    Parallelogram parallelogram(parallelogramTopLeft, 4.0, 3.0, M_PI / 4);
    parallelogram.draw();
    parallelogram.rotate(M_PI / 6);
    std::cout << std::endl;

    return 0;
}