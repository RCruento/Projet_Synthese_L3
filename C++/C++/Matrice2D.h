/**
*\file Matrice2D.h
* @author KOUSSA Rayan KADRI Islem
* @brief class intermediaire
*/
#pragma once
#include "Vecteur2D.h"
class Matrice2D
{
private:
	Vecteur2D ligneHaut;
	Vecteur2D ligneBas;
public:
	Matrice2D(const Vecteur2D & lh , const Vecteur2D & lb )
		:ligneHaut(lh),ligneBas(lb)
	{
	}
	/**
	* @param alpha : radian
	*/
	static const Matrice2D creeRotationD(const double & alpha);
	
	/**
	*Création de la rotation d'ongle coef*pi
	*le coef < > 0
	*si coef = +0.25 crée la rotation d'ongle directe 45° // Pi/4
	*/
	static const Matrice2D creeRotationMultiplePi(const double & coef);

	const Vecteur2D operator*(const Vecteur2D & v)const;

	Vecteur2D getLigneHaut()const {
		return ligneHaut;
	}

	Vecteur2D getLigneBas()const {
		return ligneBas;
	}


};

