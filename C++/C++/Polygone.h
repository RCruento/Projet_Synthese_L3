/**
*\file Polygone.h
* @author KOUSSA Rayan KADRI Islem
* @brief class m�re de Triangle
* @brief \class Triangle
*/
#pragma once
#include "FormeSimple.h"
#include <vector>
class Transformation;

class Polygone :public FormeSimple
{
protected :
	vector<Vecteur2D> points;

	/**
	* Constructeur de Polygone
	* @param couleur : la couleur de la forme
	* @param p1,p2,p3 : les 3 premiers points
	*/
	Polygone(unsigned int couleur, const Vecteur2D & p1, const Vecteur2D & p2, const Vecteur2D & p3);
public:

	/**
	* Constructeur de Segment
	* @param couleur : la couleur de la forme
	* @param v : tableau de points 
	*/
	Polygone(unsigned int couleur, const vector<Vecteur2D> & v);

	/**
	* Clone le Segment
	* @return Forme * un nouveau Segment identique = un clone
	*/
	Forme* Clone() const;

	/**
	* Destructeur
	*/
	virtual ~Polygone();

	/**
	* les points qui forment le Polygone
	* @return const vector<Vecteur2D>& : le tableau des points qui compose le polygone
	*/
	const vector<Vecteur2D>& getPoints()const;

	/**
	* les points qui forment le Polygone
	* @return const Vecteur2D & : le point numero i
	*/
	const Vecteur2D & operator[](unsigned int index)const;

	/**
	* ajoute un nouveau point au tableau de points du Polygone
	* @param p : le point a ajouter au polygone
	*\throw Erreur : si l'objet est un Triangle il ne peut pas avoir un point en plus que 3
	*/
	 void addPoint(const Vecteur2D & p);

	/**
	* supprime le n-eme  point du tableau de points du Polygone
	* @param index : l'indice du point a supprimer du polygone
	*\throw Erreur : si l'objet est un Triangle on ne peut pas lui enlever un point
	*/
	 void supPoint(unsigned int index);

	/**
	* supprime le point p  du tableau de points du Polygone , si ce point la fait partie des points du Polygone
	* @param p : le point a supprimer du polygone
	*\throw Erreur : si l'objet est un Triangle on ne peut pas lui enlever un point
	*/
	 void supPoint(const Vecteur2D & p);

	/**
	* affecte le Polygone p au Polygone appelant
	* @param p : le Polygone a recopi�
	* @return Polygone : le Polygone apr�s affecation
	*/
	const Polygone & operator=(const Polygone & p);

	/**
	* calcule l'air du Polygone
	* @return double
	*/
	virtual double CalculeAire() const;

	/**
	* cast le Polygone en String
	*/
	virtual operator string()const;

	Forme* transforme(const Transformation & t)const;

	/**
	* renvoie le Polygone en format String
	*/
	string print() const;

};

