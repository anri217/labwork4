#include "Square.h"

Square::Square()
{
	a = 0;
	b = 0;
	x = 0;
	y = 0;
}

Square::~Square() {}

Square::Square(const Square & a)
{
	this->a = a.a;
	this->b = a.b;
	this->x = a.x;
	this->y = a.y;
}

Square::Square(const std::pair<double, double>& a, const std::pair<double, double>& b)
{
	centre(a, b);
}

void Square::centre(const std::pair<double, double>& a, const std::pair<double, double>& b)
{
	if (a.second == b.second)
	{
		this->a = b.first - a.first;
		this->b = this->a;
		this->x = a.first + this->a / 2;
		this->y = a.second - this->a / 2;
	}
	else
	{
		std::cout << "ОШИБКА: введены некорректные данные" << std::endl;
		this->b = 0;
		this->a = 0;
		this->x = 0;
		this->y = 0;
	}
}

double Square::area() const { return a * a; }

double Square::perimeter() const { return 4 * a; }

std::ostream & operator<<(std::ostream & out, Square & sq)
{
	std::cout << "Координаты центра (" << sq.x << ", " << sq.y << ")" << std::endl;
	std::cout << "Сторона квадрата " << sq.a << std::endl;

	return out;
}

std::istream & operator>>(std::istream & in, Square & sq)
{

	std::cout << "ВВЕДИТЕ КООРДИНАТЫ КВАДРАТА" << std::endl;

	std::cout << "Левая верхняя координата:" << std::endl;
	std::cout << "x: ";
	double x1;
	in >> x1;
	std::cout << "y: ";
	double y1;
	in >> y1;

	std::cout << "Правая верхняя координата:" << std::endl;
	std::cout << "x: ";
	double x2;
	in >> x2;
	std::cout << "y: ";
	double y2;
	in >> y2;

	std::pair <double, double> a, b;

	a.first = x1;
	a.second = y1;
	b.first = x2;
	b.second = y2;

	Square squ(a, b);
	sq = squ;

	return in;
}