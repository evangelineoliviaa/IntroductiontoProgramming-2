#include <iostream>
#include <string>
#include <cmath>
using namespace std;

namespace oj
{
	class Shape 
	{	
	public:
		double getArea();
		double getPerimeter();
	
	protected:
		void setArea(double a);
		void setPerimeter(double p);
			
	private:
		double area;
		double perimeter;
	};

	class Triangle : public Shape
	{
	public:
		Triangle(double edge1, double edge2, double edge3);
		
	private:
		double edge1;
		double edge2;
		double edge3;
		
	};
    Triangle :: Triangle (double a, double b, double c)
    {
        this->edge1 = a;
        this->edge2 = b;
        this->edge3 = c;

        if(a+b>c && b+c > a && a+c > b && a>0 && b>0 && c>0)
        {
            double s = (a+b+c)/2;
            setArea(sqrt(s*(s-a)*(s-b)*(s-c)));
            setPerimeter(2*s);
        }else{
            setArea(0);
            setPerimeter(0);
        }
    }
	class Rectangle : public Shape
	{
	public:
		Rectangle(double width, double height);
		
	private:
		double width;
		double height;
	};
    Rectangle :: Rectangle (double width, double height)
    {
        this->width = width;
        this->height = height;
        if(width<=0||height<=0)
        {
            setArea(0);
            setPerimeter(0);
        }else{
            setArea(width*height);
            setPerimeter(2*(width+height));
        }
    }
	class Circle : public Shape
	{
	public:
		Circle(double radius, double pi);
		
	private:
		double radius;
		double pi;
	};
    Circle :: Circle (double radius, double pi)
    {
        this->radius = radius;
        this->pi = pi;
        if(radius<=0)
        {
            setArea(0);
            setPerimeter(0);
        }else{
            setArea(pi*radius*radius);
            setPerimeter(2*pi*radius);
        }
    }
}

int main(void)
{   
    using namespace oj;

    string s;
    double a, b, c;
    double totalArea = 0.0, totalPerimeter = 0.0;

    while(cin >> s) {
        if(s == "Triangle") {
            cin >> a >> b >> c;
            Triangle T(a, b, c);
            totalArea += T.getArea();
            totalPerimeter += T.getPerimeter();
        }
        if(s == "Rectangle") {
            cin >> a >> b;
            Rectangle R(a, b);
            totalArea += R.getArea();
            totalPerimeter += R.getPerimeter();
        }
        if(s == "Circle") {
            cin >> a >> b;
            Circle C(a, b);
            totalArea += C.getArea();
            totalPerimeter += C.getPerimeter();
        }
    }

    cout << totalArea << endl;
    cout << totalPerimeter << endl;


    return 0;
}
