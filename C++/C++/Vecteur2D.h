/**
*\file Vecteur2D.h
* @author Kadri Islem Koussa Rayen
* @brief Vecteur2D est un point2D (double x , double y)
*/

#pragma once
#include<string>
#include <sstream>
#define _USE_MATH_DEFINES
#include <math.h>
class Transformation;

using namespace std;


template <class T>
inline const T operator - (const T & u, const T & v) {
	return u + -v;
}

class Vecteur2D
{
public:
	double x, y;

	 Vecteur2D(const double & x = 0, const double & y = 0);

	 Vecteur2D(const Vecteur2D & v);

	 Vecteur2D(const char* s);

	virtual ~Vecteur2D();


	/*Setter*/
	void setX(const double a) { x = a; };

	void setY(const double b) { x = b; };

	/*Getter*/
	double getX() { return x; };

	double getY() { return y; };

	/**
	*DONNEES:s respectant le format "(nombre reel ,nombre reel)"
	**/
	 const Vecteur2D operator +(const Vecteur2D & u)const;

	 const Vecteur2D operator*(const double & a)const {
		 return Vecteur2D(x*a, y*a);
	 }

	 
	 const Vecteur2D operator -()const;

	 double operator * (const Vecteur2D & b)const {
		 return x * b.x + y * b.y;
	 }

	 bool operator==(const Vecteur2D & v)const ;

	 bool operator!=(const Vecteur2D & v)const { return !(*this == v); };

	operator string()const;

	friend	ostream & operator <<(ostream & os, const Vecteur2D &u);
	
	static double determiner(const Vecteur2D & a, const Vecteur2D & b, const Vecteur2D & c);

	Vecteur2D transforme(const Transformation & f) const;

	
	
};

inline const Vecteur2D Vecteur2D::operator+(const Vecteur2D &u)const
{
	return Vecteur2D(x + u.x, y + u.y);
}