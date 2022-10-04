#include "Quaternions.h"

std::ostream& operator<<(std::ostream& stream, const Q& q)
{
	if (q.re != 0) stream << q.re;
	if (q.i != 0) stream << (q.i > 0 ? "+" : "") << q.i << "i";
	if (q.j != 0) stream << (q.j > 0 ? "+" : "") << q.j << "j";
	if (q.k != 0) stream << (q.k > 0 ? "+" : "") << q.k << "k";
	return stream;
}

std::istream& operator>>(std::istream& stream, Q& q)
{
	stream >> q.re >> q.i >> q.j >> q.k;
	return stream;
}

Q::Q(double re, double i, double j, double k)
{
	this->re = re;
	this->i=i;
	this->j= j;
	this->k = k;
	
}

Q::Q(const Q& q) : re(q.re), i(q.i), j(q.j), k(q.k) {}

Q::~Q()
{
	this->re = 0.0;
	this->i = 0.0;
	this->j = 0.0;
	this->k = 0.0;
}

Q Q::con()
{
	return Q(this->re, -this->i, -this->j, -this->k);
}

void Q::swap(Q& q1, Q& q2)
{
	Q t;
	t = q1;
	q1 = q2;
	q2 = t;
}

double Q::abs()
{
	return sqrt(re * re + i * i + j * j + k * k);
}

Q& Q::operator=(const Q& q)
{
	this->re = q.re;
	this->i = q.i;
	this->j = q.j;
	this->k = q.k;
	return *this;
}

Q Q::operator-()
{
	return Q(-this->re, -this->i, -this->j, -this->k);
}

Q& Q::operator+=(const Q& q)
{
	this->re += q.re;
	this->i += q.i;
	this->j += q.j;
	this->k += q.k;
	return *this;
}

Q& Q::operator+=(const double summ)
{
	Q t;
	t.re = summ;
	*this += t;
	return *this;
}

Q& Q::operator*=(const Q& q)
{
	double re, i, j, k;
	re = this->re;
	i = this->i;
	j = this->j;
	k = this->k;
	this->re = re * q.re - i * q.i - j * q.j - k * q.k;
	this->i = re * q.i + q.re * i + j * q.k - k * q.j;
	this->j = re * q.j - i * q.k + j * q.re + k * q.i;
	this->k = re * q.k + i * q.j - j * q.i + k * q.re;
	return *this;
}

Q& Q::operator*=(const double k)
{
	Q t;
	t.re = k;
	*this *= t;
	return *this;
}

Q& Q::operator-=(const Q& q)
{
	this->re -= q.re;
	this->i -= q.i;
	this->j -= q.j;
	this->k -= q.k;
	return *this;
}

Q& Q::operator-=(const double summ)
{
	Q t;
	t.re = summ;
	*this -= t;
	return *this;
}

Q& Q::operator/=(const Q& q)
{
	Q t = q;
	(*this *= t.con()) /=(t.abs()*t.abs()) ;
	return *this;

}

Q& Q::operator/=(const double div)
{
	this->re /= div;
	this->i /= div;
	this->j /= div;
	this->k /= div;
	return *this;
}

Q operator+(const Q& q1, const Q& q2)
{
	Q t = q1;
	t += q2;
	return t;
}

Q operator+(const Q& q, const double summ)
{
	Q t;
	t = q;
	t += summ;
	return t;
}

Q operator+(const double summ, const Q& q)
{
	return q + summ;
}

Q operator-(const Q& q1, const Q& q2)
{
	Q t = q1;
	t -= q2;
	return t;
}

Q operator-(const Q& q, const double summ)
{
	Q t;
	t = q;
	t -= summ;
	return t;
}

Q operator-(const double summ, const Q& q)
{
	return q - summ;
}

Q operator*(const Q& q1, const Q& q2)
{
	Q t = q1;
	t *= q2;
	return t;
}

Q operator*(const Q& q, const double summ)
{
	Q t;
	t = q;
	t *= summ;
	return t;
}

Q operator*(const double summ, const Q& q)
{
	return q * summ;
}
Q operator/( Q& q1, Q& q2)
{
	Q t;
	t = (q1 * q2.con()) / (q2.abs() * q2.abs());
	return t;
}

Q operator/(const Q& q, const double summ)
{
	Q t;
	t = q;
	t /= summ;
	return t;
}

Q operator/(const double summ, Q& q)
{
	Q t;
	t = q.con() / (q.abs()*q.abs());
	return t;
}