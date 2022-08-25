/**
* @file Cercle.h
* @author KOUSSA Rayan KADRI Islem
*/
#pragma once
#include "FormeSimple.h"
class Transformation;
class Cercle :public FormeSimple
{

	Vecteur2D centre;
	double rayon;

public:
	/**
	* Constructeur  Cercle
	* 
	**/
	Cercle();
	
	/**
	*Constructeur de Cercle
	* @param couleur : couleur de la forme
	* @param centre : centre du Cercle 
	*/
	Cercle(unsigned int couleur, const Vecteur2D &centre, double rayon);

	/**
	* Clone le Cercle
	* @return Forme* un clone de Cercle
	*/
	Forme* Clone() const;

	/**
	* Destructeur
	*/
	~Cercle();

	/**
	* retourne le centre
	* @return const Vecteur2D&
	*/
	const Vecteur2D& getCentre()const;

	/**
	* modifie le centre du cercle par le centre recu en parametre
	* @param c : le nouveau centre
	*/
	void setCentre(const Vecteur2D &c);

	/**
	* retourne le rayon du Cercle
	* @return double : le rayon du cercle 
	*/
	double getRayon()const;

	/**
	* modifie le rayon du cercle par le rayon r recu en parametre
	* @param r : le nouveau rayon
	*/
	void setRayon(const double r);

	/**
	* retourne l'air du cercle
	* @return double l'air du cercle
	*/
	double CalculeAire()const;

	/**
	* transforme le Cercle en String
	*/
	operator string() const;

	/**
	* Compare le Cercle s au Cercle appelant
	* @param c : le Cercle a recopié
	* @return Cercle : le Cercle apr�s affecation
	*/
	const Cercle & operator= (const Cercle &c);

	/*
	* Transforme la Forme Cercle en une autre forme
	* @param t
	*/

	Forme* transforme(const Transformation & t)const;

	/**
	* renvoi le Cercle en format String
	* @return : le  Cercle en string
	*/
	string print() const;


};


