/**
*\file Erreur.cpp
* @author KOUSSA Rayan KADRI Islem
*/
#include "Homotetie.h"
#include "Vecteur2D.h"


Homotetie::Homotetie(const Vecteur2D & c, const double f): facteurConstant(c-c*f),facteur(f)
{
}

Homotetie::~Homotetie()
{
}


Vecteur2D Homotetie::visitor(const Vecteur2D & f) const
{
	return f * facteur + facteurConstant;
}

Forme * Homotetie::visitor(const Cercle & c) const
{
	return new Cercle(c.getCouleur(), visitor(c.getCentre()), c.getRayon()*facteur);
}

Forme * Homotetie::visitor(const Polygone & c) const
{
	Vecteur2D p1 = (c.operator[](0))*facteur;
	Vecteur2D p2 = (c.operator[](1))*facteur;
	Vecteur2D p3 = (c.operator[](2))*facteur;
	Vecteur2D p4 = (c.operator[](3))*facteur;

	vector<Vecteur2D> points;
	points.push_back(p1);
	points.push_back(p2);
	points.push_back(p3);
	points.push_back(p4);

	return new Polygone(255, points);
}



Forme * Homotetie::visitor(const Triangle & c) const
{
	Vecteur2D p1 = (c.operator[](0))*facteur;
	Vecteur2D p2 = (c.operator[](1))*facteur;
	Vecteur2D p3 = (c.operator[](2))*facteur;
	

	vector<Vecteur2D> points;
	points.push_back(p1);
	points.push_back(p2);
	points.push_back(p3);
	

	return new Polygone(65280, points);
}


