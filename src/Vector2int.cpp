#include "Vector2int.hpp"

Vector2int::Vector2int() : Vector2int(0, 0) {}

Vector2int::Vector2int(int x, int y) : x(x), y(y) {}

Vector2int &Vector2int::Add(const Vector2int &v) {
	x += v.x;
	y += v.y;
	return *this;
}

Vector2int &Vector2int::Subtract(const Vector2int &v) {
	x -= v.x;
	y -= v.y;
	return *this;
}

Vector2int &Vector2int::Multiply(int i) {
	x *= i;
	y *= i;
	return *this;
}

Vector2int &Vector2int::Divide(int i) {
	x /= i;
	y /= i;
	return *this;
}

Vector2int &operator+(Vector2int v1, Vector2int v2) {
	return v1.Add(v2);
}

Vector2int &operator-(Vector2int v1, Vector2int v2) {
	return v1.Subtract(v2);
}

Vector2int &operator*(int i, Vector2int v) {
	return v.Multiply(i);
}

Vector2int &operator/(int i, Vector2int v) {
	return v.Divide(i);
}

Vector2int &Vector2int::operator+=(Vector2int v2) {
	return Add(v2);
}

Vector2int &Vector2int::operator-=(Vector2int v2) {
	return Subtract(v2);
}

Vector2int &Vector2int::operator*=(int i) {
	return Multiply(i);
}

Vector2int &Vector2int::operator/=(int i) {
	return Divide(i);
}

std::ostream &operator<<(std::ostream &stream, Vector2int v) {
	return stream << "(" << v.x << ", " << v.y << ")";
}
