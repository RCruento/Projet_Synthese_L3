/**
*\file Erreur.cpp
* @author KOUSSA Rayan KADRI Islem
*/


#include "ParseurTriangle.h"
#include <regex>
#include "Triangle.h"
#include "Vecteur2D.h"


ParseurTriangle::ParseurTriangle(ParseurForme *s)
	:ParseurForme(s)
{
}

ParseurTriangle::~ParseurTriangle()
{
}

Forme * ParseurTriangle::resoudre1(const string & d) const
{
	int indiceTriangle = d.find("Triangle", 0);

	if (indiceTriangle == std::string::npos)
		return NULL;
	else {
		double x1, y1, x2, y2, x3, y3;
		int couleur;
		int indiceCouleur = d.find("couleur", 0);
		int indiceAccolade = d.find("}", indiceCouleur + 1);
		string chaine = d.substr(indiceCouleur, indiceAccolade -1);
		const char * c = chaine.c_str();
	
		sscanf_s(c, "couleur %d {(%lf,%lf);(%lf,%lf);(%lf,%lf)}", &couleur, &x1, &x2, &x3, &y1, &y2, &y3);
		return new Triangle(couleur, Vecteur2D(x1, y1), Vecteur2D(x2, y2), Vecteur2D(x3, y3));
	}
}
