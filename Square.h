#pragma once
#include "Rectangle.h"

class Square : public Rectangle
{
public:
	Square();
	~Square();
	Square(const Square& a);
	Square(const std::pair<double, double>& a, const std::pair<double, double>& b);
	void centre(const std::pair <double, double>& a, const std::pair <double, double>& b);
	friend std::ostream& operator<< (std::ostream& out, Square& sq);
	double area() const override;
	double perimeter() const override;
};

std::ostream& operator<< (std::ostream& out, Square& sq);
std::istream& operator>> (std::istream& in, Square& sq);