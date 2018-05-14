#include "Vector2.hpp"

Vector2::Vector2() : Vector2(0, 0) {}

Vector2::Vector2(float x, float y) : x(x), y(y) {}

Vector2::Vector2(Vector2int vector2int) : Vector2(vector2int.x, vector2int.y) {}

Vector2 &Vector2::Add(const Vector2 &v) {
	x += v.x;
	y += v.y;
	return *this;
}

Vector2 &Vector2::Subtract(const Vector2 &v) {
	x -= v.x;
	y -= v.y;
	return *this;
}

Vector2 &Vector2::Multiply(int i) {
	x *= i;
	y *= i;
	return *this;
}

Vector2 &Vector2::Divide(int i) {
	x /= i;
	y /= i;
	return *this;
}

Vector2 &Vector2::Multiply(double f) {
	x *= f;
	y *= f;
	return *this;
}

Vector2 &Vector2::Divide(double f) {
	x /= f;
	y /= f;
	return *this;
}

Vector2 &operator+(Vector2 v1, const Vector2 v2) {
	return v1.Add(v2);
}

Vector2 &operator-(Vector2 v1, const Vector2 v2) {
	return v1.Subtract(v2);
}

Vector2 &operator*(int i, Vector2 v) {
	return v.Multiply(i);
}

Vector2 &operator/(int i, Vector2 v) {
	return v.Divide(i);
}

Vector2 &operator*(double f, Vector2 v) {
	return v.Multiply(f);
}

Vector2 &operator/(double f, Vector2 v) {
	return v.Divide(f);
}

Vector2 &Vector2::operator+=(const Vector2 v2) {
	return Add(v2);
}

Vector2 &Vector2::operator-=(const Vector2 v2) {
	return Subtract(v2);
}

Vector2 &Vector2::operator*=(int i) {
	return Multiply(i);
}

Vector2 &Vector2::operator/=(int i) {
	return Divide(i);
}

Vector2 &Vector2::operator*=(double f) {
	return Multiply(f);
}

Vector2 &Vector2::operator/=(double f) {
	return this->Divide(f);
}

std::ostream &operator<<(std::ostream &stream, const Vector2 v) {
	return stream << "(" << v.x << ", " << v.y << ")";
}