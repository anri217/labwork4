#include "Rectangle.h"
#include "Square.h"
#include <vector>

int main()
{
	setlocale(LC_ALL, "Russian");

	Rectangle rectangle, rectangle1;
	Square square, square1;
	
	std::ifstream in("input.txt");

	in >> rectangle;
	std::cout << rectangle;

	in >> square;
	std::cout << square;

	in >> square1;
	std::cout << square1;

	in >> rectangle1;
	std::cout << rectangle1;

	in.close();

	std::cout << "Сумма двух прямоугольников " << rectangle + rectangle1 << std::endl;
	std::cout << "Сумма двух квадратов " << square + square1 << std::endl;

	std::cout << "Первый квадрат больше второго " << (square < square1) << std::endl;
	std::cout << "Первый прямоугольник больше второго " << (rectangle < rectangle1) << std::endl;

	system("pause");
	return 0;
}