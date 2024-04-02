#include "Vector.h"
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <cmath>
using namespace std;

Vector3D::Vector3D() : x(0), y(0), z(0) {}

Vector3D::Vector3D(double x, double y, double z) : Object(), x(x), y(y), z(z) {}

Vector3D::Vector3D(const Vector3D& other) : Object(other), x(other.x), y(other.y), z(other.z) {}


Vector3D::~Vector3D() {}

Vector3D& Vector3D::operator = (const Vector3D& other)
{
	if (this != &other) {
		Object::operator=(other);
		x = other.x;
		y = other.y;
		z = other.z;
	}
	return *this;
}

Vector3D::operator string() const
{
	stringstream sout;
	sout << "( " << x << +", " << y << ", " << z << ")";
	return sout.str();
}

istream& operator >> (istream& input, Vector3D& vec)
{
	cout << "x: ";
	input >> vec.x;
	cout << "y: ";
	input >> vec.y;
	cout << "z: ";
	input >> vec.z;
	return input;
}

ostream& operator << (ostream& output, const Vector3D& vec)
{
	output << string(vec) << endl;
	return output;
}

Vector3D operator*(double scalar, const Vector3D& vec) {
	return Vector3D(scalar * vec.x, scalar * vec.y, scalar * vec.z);
}

bool operator!=(const Vector3D& vec1, const Vector3D& vec2) {
	return !(vec1 == vec2);
}

double Vector3D::operator()() const {
	return sqrt(x * x + y * y + z * z);
}


bool operator==(const Vector3D& vec1, const Vector3D& vec2) {
	return vec1.x == vec2.x && vec1.y == vec2.y && vec1.z == vec2.z;
}

bool operator ^ (const Vector3D& vec1, const Vector3D& vec2)
{
	return vec1() == vec2();
}

Vector3D& Vector3D::operator++() {
	++x;
	++y;
	++z;
	return *this;
}

Vector3D& Vector3D::operator--() {
	--x;
	--y;
	--z;
	return *this;
}

Vector3D Vector3D::operator++(int) {
	Vector3D temp(*this);
	++(*this);
	return temp;
}

Vector3D Vector3D::operator--(int) {
	Vector3D temp(*this);
	--(*this);
	return temp;
}