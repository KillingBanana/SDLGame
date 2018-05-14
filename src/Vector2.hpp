#ifndef SDLGAME_VECTOR2_HPP
#define SDLGAME_VECTOR2_HPP

#include <iostream>
#include "Vector2int.hpp"

class Vector2 {
public:
	float x, y;

	Vector2();
	Vector2(float x, float y);
	explicit Vector2(Vector2int vector2int);

	friend Vector2 &operator+(Vector2 v1, Vector2 v2);
	friend Vector2 &operator-(Vector2 v1, Vector2 v2);

	friend Vector2 &operator*(double f, Vector2 v);
	friend Vector2 &operator/(double f, Vector2 v);

	friend Vector2 &operator*(int i, Vector2 v);
	friend Vector2 &operator/(int i, Vector2 v);

	Vector2 &operator+=(Vector2 v2);
	Vector2 &operator-=(Vector2 v2);

	Vector2 &operator*=(double f);
	Vector2 &operator/=(double f);

	Vector2 &operator*=(int i);
	Vector2 &operator/=(int i);

	friend std::ostream &operator<<(std::ostream &stream, Vector2 v);

private:
	Vector2 &Add(const Vector2 &v);
	Vector2 &Subtract(const Vector2 &v);

	Vector2 &Multiply(int i);
	Vector2 &Divide(int i);

	Vector2 &Multiply(double f);
	Vector2 &Divide(double f);
};

#endif //SDLGAME_VECTOR2_HPP
