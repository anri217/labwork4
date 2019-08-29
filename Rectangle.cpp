#include "Rectangle.h"
#include <algorithm>

Rectangle::Rectangle()
{
	a = 0;
	b = 0;
	x = 0;
	y = 0;
}

void Rectangle::centre(const std::pair<double, double>& a, const std::pair<double, double>& b, const std::pair<double, double>& c, const std::pair<double, double>& d)
{
	if (a.second == b.second && a.first == d.first && b.first == c.first && c.second == d.second)
	{
		this->b = a.second - c.second;
		this->a = b.first - a.first;
		this->x = a.first + this->a / 2;
		this->y = a.second - this->b / 2;
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

Rectangle::~Rectangle() {}

Rectangle::Rectangle(const Rectangle& other)
{
	a = other.a;
	b = other.b;
}

Rectangle::Rectangle(const std::pair<double, double>& a, const std::pair<double, double>& b, const std::pair<double, double>& c, const std::pair<double, double>& d)
{
	centre(a, b, c, d);
}

void Rectangle::length(const double& a)
{
	this->a = a;
}

void Rectangle::width(const double& b)
{
	this->b = b;
}

const double Rectangle::operator+(const Rectangle& rec)
{
	std::pair <double, double> a, b, c, d;

	a.first = x - this->a / 2;
	a.second = y - this->b / 2;

	b.first = this->x + this->a / 2;
	b.second = this->y + this->b / 2;

	c.first = rec.x - rec.a / 2;
	c.second = rec.y - rec.b / 2;

	d.first = rec.x + rec.a / 2;
	d.second = rec.y + rec.b / 2;

	double left = std::max(a.first, c.first);
	double top = std::min(b.second, d.second);
	double right = std::min(b.first, d.first);
	double bottom = std::max(a.second, c.second);

	double width = right - left;
	double height = top - bottom;

	if ((width < 0) || (height < 0))
		return 0;

	return width * height;
}

Rectangle& Rectangle::operator=(const Rectangle& rec)
{
	if (this != &rec)
	{
		a = rec.a;
		b = rec.b;
		x = rec.x;
		y = rec.y;
	}
	return *this;
}

double Rectangle::perimeter() const { return 2 * (a + b); }

double Rectangle::area() const { return a * b; }

std::istream & operator>> (std::istream & in, Rectangle & rec)
{
	std::cout << "ВВЕДИТЕ КООРДИНАТЫ ПРЯМОУГОЛЬНИКА" << std::endl;

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

	std::cout << "Правая нижняя координата:" << std::endl;
	std::cout << "x: ";
	double x3;
	in >> x3;
	std::cout << "y: ";
	double y3;
	in >> y3;

	std::cout << "Левая нижняя координата:" << std::endl;
	std::cout << "x: ";
	double x4;
	in >> x4;
	std::cout << "y: ";
	double y4;
	in >> y4;

	std::pair <double, double> a, b, c, d;

	a.first = x1;
	a.second = y1;
	b.first = x2;
	b.second = y2;
	c.first = x3;
	c.second = y3;
	d.first = x4;
	d.second = y4;

	Rectangle rec1(a, b, c, d);
	rec = rec1;

	return in;
}

std::ostream & operator<<(std::ostream & out, Rectangle & rec)
{
	out << "Координаты центра (" << rec.x << ", " << rec.y << ")" << std::endl;
	out << "Длина " << rec.a << std::endl << "Ширина " << rec.b << std::endl;
	return out;
}

bool operator==(const Rectangle & rec1, const Rectangle & rec2)
{
	return (rec1.area() == rec2.area());
}

bool operator<(const Rectangle & rec1, const Rectangle & rec2)
{
	return (rec1.area() < rec2.area());
}

bool operator>(const Rectangle & rec1, const Rectangle & rec2)
{
	return (rec1.area() > rec2.area());
}

bool operator<=(const Rectangle & rec1, const Rectangle & rec2)
{
	return (rec1 == rec2) || (rec1 < rec2);
}

bool operator>=(const Rectangle & rec1, const Rectangle & rec2)
{
	return (rec1 == rec2) || (rec1 > rec2);
}