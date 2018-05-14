#ifndef SDLGAME_VECTOR2INT_HPP
#define SDLGAME_VECTOR2INT_HPP

#include <iostream>

class Vector2int {
public:
	int x, y;

	Vector2int();
	Vector2int(int x, int y);

	friend Vector2int &operator+(Vector2int v1, Vector2int v2);
	friend Vector2int &operator-(Vector2int v1, Vector2int v2);

	friend Vector2int &operator*(int i, Vector2int v);
	friend Vector2int &operator/(int i, Vector2int v);

	Vector2int &operator+=(Vector2int v2);
	Vector2int &operator-=(Vector2int v2);

	Vector2int &operator*=(int i);
	Vector2int &operator/=(int i);

	friend std::ostream &operator<<(std::ostream &stream, Vector2int v);

private:
	Vector2int &Add(const Vector2int &v);
	Vector2int &Subtract(const Vector2int &v);

	Vector2int &Multiply(int i);
	Vector2int &Divide(int i);
};

#endif //SDLGAME_VECTOR2INT_HPP
