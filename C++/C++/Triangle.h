/**
*\file Triangle.h
* @author KOUSSA Rayan KADRI Islem
*/
#pragma once
#include "Polygone.h"
class Triangle :public Polygone
{
public:

	/**
	* Constructeur de Triangle
	* @param couleur : la couleur de la forme
	* @param p1 p2 p3 : les 3 points formant le triangle
	*/
	Triangle(unsigned int couleur ,const Vecteur2D & p1, const Vecteur2D & p2, const Vecteur2D & p3 );

	/**
	* Clone le Triangle
	* @return Forme* un nouveau Triangle identique = clone
	*/
	Forme*Clone()const;

	/**
	* Destructeur
	*/
	virtual ~Triangle();

	/**
	* calcule l'aire du Triangle
	* @return double
	*/
	double CalculeAire() const;

	/**
	* affecte le Triangle s au Triangle appelant
	* @param s : le Triangle a recopie
	* @return Triangle : le Triangle apres affecation
	*/
	const Triangle * operator=(const Triangle & s);

	/**
	* cast le Triangle en String
	*/
	operator string()const;

	Forme* transforme(const Transformation & t)const;
	
};


