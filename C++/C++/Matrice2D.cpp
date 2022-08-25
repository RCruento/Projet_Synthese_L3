/**
*\file Erreur.cpp
* @author KOUSSA Rayan KADRI Islem
*/


#include "Matrice2D.h"

const Matrice2D Matrice2D::creeRotationD(const double & alpha)
{
	double cosAlpha = cos(alpha);
	double sinAlpha = sin(alpha);

	return Matrice2D(
					Vecteur2D(cosAlpha, -sinAlpha), 
					Vecteur2D(sinAlpha, cosAlpha)
					);
}

const Matrice2D Matrice2D::creeRotationMultiplePi(const double & coef)
{
	return creeRotationD(coef*M_PI);
}

const Vecteur2D Matrice2D::operator*(const Vecteur2D & v) const
{
	return Vecteur2D(ligneHaut*v, ligneBas*v);
}
