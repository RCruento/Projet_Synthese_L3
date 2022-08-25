/**
*\file Erreur.cpp
* @author KOUSSA Rayan KADRI Islem
*/

#include "Transformation.h"



Transformation::~Transformation()
{
}

Forme * Transformation::visitor(const Polygone& p) const
{
	vector<Vecteur2D>::const_iterator it;
	vector<Vecteur2D> nouveauPoints;
	for (it = p.getPoints().begin(); it != p.getPoints().end(); it++) {
		nouveauPoints.push_back(visitor(*it));
	}
	return new Polygone(p.getCouleur(), nouveauPoints);
}

Forme * Transformation::visitor(const Triangle & p) const
{
	vector<Vecteur2D>::const_iterator it;
	vector<Vecteur2D> nouveauPoints;
	for (it = p.getPoints().begin(); it != p.getPoints().end(); it++) {
		nouveauPoints.push_back(visitor(*it));
	}
	return new Triangle(p.getCouleur(), nouveauPoints[0],nouveauPoints[1],nouveauPoints[2]);
}

Forme * Transformation::visitor(const Segment & s) const
{
	return new Segment(s.getCouleur(), visitor(s.getDepart()), visitor(s.getFin()));
}

Forme * Transformation::visitor(const Cercle & c) const
{
	return new Cercle(c.getCouleur(), visitor(c.getCentre()), c.getRayon());
}

Forme * Transformation::visitor(const FormeComplexe & f) const
{
	FormeComplexe * res = new FormeComplexe();
	res->setCouleur(f.getCouleur());

	vector<Forme*>::const_iterator it;

	for (it = f.getFormes().begin(); it != f.getFormes().end(); it++)
	{
		res->addForme(*((*it)->transforme(*this)));
	}
	return res;
}
