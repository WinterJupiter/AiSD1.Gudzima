#pragma once
#include <iostream>
#include <string>

class Vector {
private:
	size_t size;
	double* data;
public:
	Vector();
	Vector(const size_t size);
	Vector(const Vector& v);
	void Add(double value);
	void Change(size_t index, double value);
	size_t Size() const;
	double operator[] (const size_t index) const;
	Vector operator+ (const Vector& v);
	Vector& operator= (const Vector& v);
	Vector operator- (const Vector& v);
	Vector operator* (const Vector& v);
	Vector operator* (const double à);
	Vector operator/ (const double à);
	~Vector();
	friend std::istream& operator>> (std::istream& is, Vector& v);
	friend std::ostream& operator<< (std::ostream& os, const Vector& v);
};

#pragma once
