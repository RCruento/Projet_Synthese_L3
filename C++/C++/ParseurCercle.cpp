/**
*\file Erreur.cpp
* @author KOUSSA Rayan KADRI Islem
*/


#include "ParseurCercle.h"
#include <regex>
#include "Cercle.h"
#include "Vecteur2D.h"




ParseurCercle::ParseurCercle(ParseurForme * f)
	:ParseurForme(f)
{
}

ParseurCercle::~ParseurCercle()
{
}

Forme * ParseurCercle::resoudre1(const string & d) const
{
	
	int indiceCercle = d.find("Cercle", 0);
	if (indiceCercle == std::string::npos)
		return NULL;
	else {
		const char * c = d.c_str();
		double r, x, y;
		int couleur;
		sscanf_s(c, "Cercle rayon %lf couleur %d (%lf,%lf)", &r, &couleur, &x, &y);
		return new Cercle(couleur, Vecteur2D(x, y), r);
	}
}
