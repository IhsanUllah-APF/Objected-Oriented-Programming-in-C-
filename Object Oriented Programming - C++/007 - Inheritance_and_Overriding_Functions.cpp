#include<iostream>
#include<string>
using namespace std;

class Point
{
    public:
        int x;
        int y;
        
        void print_point();
};

void Point::print_point() // A function defined outside of it's class should carry class name and ::
{
    cout << "(" << x << "," << y << ")" << endl;
}

class Shape
{
    public:
        int num_points;
        Point * points;

        Shape();

        void set_points( Point *p);
        float get_area();
};

Shape::Shape() // A constructor defined outside of it's class should carry class name and ::
{
    cout <<"In shape constructor ... " << endl;
    points = NULL;
    num_points = 0;
}

float Shape :: get_area() // A function defined outside of it's class should carry class name and ::
{
    return -1.0;
}

class Triangle : public Shape // A child class should carry : public parent class name
{
    public:
        Triangle();
        void set_points(Point *p);
        void show_shape();
        float get_area();
};

Triangle :: Triangle()
{
    cout << "In Triangle constructor ... " << endl;
    num_points = 3;
}

void Triangle :: set_points(Point *p) // A function defined outside of it's class should carry class name and ::
{
    points = p;
}

void Triangle :: show_shape() // A function defined outside of it's class should carry class name and ::
{
    Point *temp;
    temp = points;
    
    for(int i = 0; i < num_points; i++)
    {
        temp -> print_point(); // No class name and :: are used when calling a function.
        temp ++;
    }
}
float Triangle :: get_area() // A function defined outside of it's class should carry class name and ::
{
    int x0, y0, x1, y1, x2, y2;
    
    Point *t;
    t = points;

    x0 = t -> x;
    y0 = t -> y;
    t++;

    x1 = t -> x;
    y1 = t -> y;
    t++;

    x2 = t -> x;
    y2 = t -> y;

    return abs(x0 * (y1 - y2) + x1 * (y2 - y0) + x2 * (y0 - y1) / 2); 
}

void create_shape()
{
    //shape *s;
    //s = new shape;
    //cout <<"Area of s: " <<s -> get_area() <<endl;

    Triangle *t;
    t = new Triangle;
    
    Point p1, p2, p3;
    
    p1.x = p1.y = 0;
    p2.x = p2.y = 10;
    p3.x = p3.y = 25;

    Point *points_of_triangle;
    points_of_triangle = new Point[3];
    points_of_triangle[0] = p1;
    points_of_triangle[1] = p2;
    points_of_triangle[2] = p3;

    t -> set_points(points_of_triangle); // No class name and :: used when calling a function.
    t -> show_shape(); // No class name and :: used when calling a function.

    cout <<"Area of triangle = " <<t->get_area() <<endl; // No class name and :: used when calling a function.
}

int main()
{
    create_shape();

    return 0;
}



