#pragma once
#include <utility>
#include <iostream>
#include <fstream>


class Rectangle
{
public:
	Rectangle();
	~Rectangle();
	Rectangle(const Rectangle& a);
	Rectangle(const std::pair<double, double>& a, const std::pair<double, double>& b, const std::pair<double, double>& c, const std::pair<double, double>& d);
	void centre (const std::pair <double, double>& a, const std::pair <double, double>& b, const std::pair <double, double>& c, const std::pair <double, double>& d);
	void length (const double& a);
	void width (const double& b);
	const double operator+ (const Rectangle& rec);
	Rectangle& operator= (const Rectangle& rec);
	friend std::ostream& operator<< (std::ostream& out, Rectangle& rec);
	virtual double perimeter() const;
	virtual double area() const;
protected:
	double a, b, x, y;
};

std::istream& operator>> (std::istream& in, Rectangle& rec);
std::ostream& operator<< (std::ostream& out, Rectangle& rec);

bool operator== (const Rectangle& rec1, const Rectangle& rec2);
bool operator< (const Rectangle& rec1, const Rectangle& rec2);
bool operator> (const Rectangle& rec1, const Rectangle& rec2);
bool operator<= (const Rectangle& rec1, const Rectangle& rec2);
bool operator>= (const Rectangle& rec1, const Rectangle& rec2);