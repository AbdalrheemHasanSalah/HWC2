

#include <iostream>
#include<math.h>
using namespace std;

class shape {
private:
	int raduies;
	int height_triangle;
	int area_base_triangle;
public:
	shape() {
		set_raduies(1);
		set_height_triangle(1);
		set_area_base_triangle(1);
	}
	shape(int r, int h, int base_area) {
		set_raduies(r);
		set_height_triangle(h);
		set_area_base_triangle(base_area);
	}
	shape(int r, int h) {
		set_raduies(r);
		set_height_triangle(h);
		set_area_base_triangle(1);
	}
	shape(int r) {
		set_raduies(r);
		set_height_triangle(1);
		set_area_base_triangle(1);
	}
	
	
	int get_raduies() {
		return raduies;
	}
	int get_height_triangle() {
		return height_triangle;
	}
	int get_area_base_triangle() {
		return area_base_triangle;
	}

	void set_area_base_triangle(int base_area) {
		area_base_triangle = base_area;
	}
	void set_raduies(int r) {
		raduies = r;
	}
	void set_height_triangle(int h) {
		height_triangle = h;
	}
	~shape() {

	}
	/*virtual double area_circle()=0;
	virtual double area_Triangle() = 0;*/

protected:


};

class circle :public shape {
public:

	circle()
	{
		set_raduies(1);
	}
  circle(int r)
	{
		set_raduies(r);
	}
	  double area_circle() {
		return (3.14 * pow(get_raduies(), 2));
	}
	~circle() {

	}
};
class Triangle :public shape {
public:
	Triangle() {
		set_height_triangle(1);
		set_area_base_triangle(1);
	}
	Triangle(int height, int base) {
		set_height_triangle(height);
		set_area_base_triangle(base);
	}
	 double area_triangle() {
		return (.5 * get_area_base_triangle() * get_height_triangle());
	}
	~Triangle() {

	}
};
int main()
{
	int rad = 1, height = 1, area_base = 1;
	cout << "raduies is :";
	cin >> rad;
	cout << endl;
	cout << "height is :";
	cin >> height;
	cout << endl;

	cout << "area_base is :";
	cin >> area_base;
	cout << endl;

	circle c;
	Triangle t;
	c.set_raduies(rad);
	cout << "area of circle :" << c.area_circle() << endl;
	t.set_height_triangle(height);
	t.set_area_base_triangle(area_base);
	cout << "area of triangle :" << t.area_triangle();
	
	/*shape a = { new circle(rad),new Triangle(height,area_base) };
	cout << "area of circle :" << a.area_circle() << endl;
	cout << "area of circle :" << a.area_triangle();*/

}

