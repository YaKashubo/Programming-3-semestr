#pragma once
#include<iostream>
#include<cmath>

class Q
{
public:
	double re, i, j, k;
	Q(double re = 0.0, double i = 0.0, double j = 0.0, double k = 0.0);
	Q(const Q& q);
	~Q();

	Q con();
	void swap(Q& q1, Q& q2);
	double abs();

	friend Q operator+(const Q& q1, const Q& q2);
	friend Q operator+(const Q& q, const double summ);
	friend Q operator+(const double summ, const Q& q);

	friend Q operator-(const Q& q1, const Q& q2);
	friend Q operator-(const Q& q, const double summ);
	friend Q operator-(const double summ, const Q& q);

	friend Q operator*(const Q& q1, const Q& q2);
	friend Q operator*(const Q& q, const double summ);
	friend Q operator*(const double k, const Q& q);

	friend Q operator/(Q& q1, Q& q2);
	friend Q operator/(const Q& q, const double summ);
	friend Q operator/(const double summ, Q& q);

	Q& operator=(const Q& q);
	Q  operator-();
	Q& operator+=(const Q& q);
	Q& operator+=(const double summ);
	Q& operator*=(const Q& q);
	Q& operator*=(const double k);
	Q& operator-=(const Q& q);
	Q& operator-=(const double summ);
	Q& operator/=(const Q& q);
	Q& operator/=(const double div);



	friend std::ostream& operator<<(std::ostream& stream, const Q& q);
	friend std::istream& operator>>(std::istream& stream, Q& q);
};

