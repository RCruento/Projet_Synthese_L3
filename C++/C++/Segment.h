/**
*\file Segment.h
* @author KOUSSA Rayan KADRI Islem
*/
#pragma once
#include "FormeSimple.h"
class Transformation;
class Segment :	public FormeSimple
{
	Vecteur2D depart;
	Vecteur2D fin;

public:

	/**
	* Constructeur de Segment
	* @param couleur : la couleur de la forme
	* @param depart : le point 2D de depart
	* @param fin : le point 2D de fin
	*/
	Segment(unsigned int couleur, const Vecteur2D & depart, const Vecteur2D & fin);

	/**
	* Clone le Segment
	* @return Forme * un nouveau Segment identique = clone
	*/
	Forme* Clone() const;

	/**
	* Destructeur 
	*/
	 ~Segment();

	/**
	* retourne le point2D de depart
	*  @return const Vecteur2D& 
	*/
	const  Vecteur2D&  getDepart()const; 

	/**
	* retourne le point2D de depart
	*  @return const Vecteur2D&
	*/
	const Vecteur2D& getFin()const;

	/**
	* modifie le point de depart par le point recu en parametre
	* @param d : le point de depart
	*/
	void setDepart(const Vecteur2D & d);

	/**
	* modifie le point de fin par le point recu en parametre
	* @param f : le point de depart
	*/
	void setFin(const Vecteur2D & f);

	/**
	* affecte le Segment s au segment appelant
	* @param s : le Segment a recopie
	* @return Segement : le Segment apres affectation
	*/
	const Segment & operator=(const Segment & s);

	/**
	* calcule l'aire du Segement 0
	* @return 0
	*/
	double CalculeAire() const;

	/**
	* cast le Segment en String
	*/
	 operator string()const;
	
	 Forme* transforme(const Transformation & t)const;

	 /**
	 * renvoie le Segement en format String
	 */
	 string print() const;
	

	
};

