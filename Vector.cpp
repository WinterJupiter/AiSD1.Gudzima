#include <iostream>
#include "Vector.h"


Vector::Vector()
{
	size = 0;
	data = NULL;
}

Vector::Vector(const size_t size)
{
	data = new double[size];
	for (int i = 0; i < size; i++)
		data[i] = 0;
}

Vector::Vector(const Vector& v)
{
	data = new double[v.size];
	size = v.size;
	for (int i = 0; i < size; i++)
		data[i] = v.data[i];
}


void Vector::Add(double value)
{
	size++;
	data[size-1] = value;
}

void Vector::Change(size_t index, double value)
{
	if ((index > size) || (index < 0)) throw ("Invalid index");
	data[index-1] = value;
}

size_t Vector::Size() const
{
	return size;
}

double Vector::operator[] (const size_t index) const
{
	if (index > size) throw("Invalid index");
	return data[index];
}

Vector& Vector::operator=(const Vector& v)
{
	size = v.size;
	delete[] data;
	data = new double[size];
	for (int i = 0; i < size; i++)
		data[i] = v.data[i];
	return *this;
}

Vector Vector::operator+(const Vector& v) 
{
	if (v.size != size) throw "Vectors aren't equal\n";
	Vector sum(v);
	for (int i = 0; i < size; i++)
		sum.data[i] += data[i];
	return sum;
}

Vector Vector::operator-(const Vector& v)
{
	if (v.size != size) throw "Vectors aren't equal\n";
	Vector sub(*this);
	for (int i = 0; i < size; i++)
		sub.data[i] = data[i] - v.data[i];
	return sub;
}


Vector Vector::operator* (const Vector& v)
{
	if (v.size != size) throw "Vectors aren't equal\n";
	Vector mul(v);
	for (int i = 0; i < size; i++)
		mul.data[i] *= data[i];
	return mul;
}

Vector Vector::operator*(const double a)
{
	Vector mul1(*this), mul2(*this);
	for (int i = 0; i < size; i++)
	{
		mul1.data[i] = a* mul1.data[i];
		mul2.data[i] *= a;
		if (mul1.data[i] != mul2.data[i]) throw "Not commutative\n";
	}
	return mul1;
}

Vector Vector::operator/ (const double a)
{
	if (a == 0) throw ("Divide to 0!");
	Vector div(*this);
	for (int i = 0; i < size; i++)
		div.data[i] /= a;
	return div;
}

Vector::~Vector()
{
	size = 0;
	delete[] data;
}

std::istream& operator>> (std::istream& is, Vector& v)
{
	std::cout << "\nSize: ";
	is >> v.size;
	v.data = new double[v.size];
	for (int i = 0; i < v.size; i++)
		is >> v.data[i];
	return is;
}

std::ostream& operator<< (std::ostream& os, const Vector& v)
{
	os << "Size:" << v.Size() << std::endl;
	for (int i = 0; i < v.Size(); i++)
		os << i + 1 << ": " << v[i] << std::endl;
	return os;
}