/**
*\file Erreur.cpp
* @author KOUSSA Rayan KADRI Islem
*/


#include "ParseurSegment.h"
#include <regex>
#include "Segment.h"
#include "Vecteur2D.h"




ParseurSegment::ParseurSegment(ParseurForme * f)
	:ParseurForme(f)
{
}

ParseurSegment::~ParseurSegment()
{
}

Forme * ParseurSegment::resoudre1(const string & d) const
{
	if (!regex_match(d, regex("^[0-9]* *-* *Segment couleur [0-9]* \\(-?[0-9]*.[0-9]*,-?[0-9]*.[0-9]*\\);\\(-?[0-9]*.[0-9]*,-?[0-9]*.[0-9]*\\)$")))
			return NULL;


		int indiceCouleur = d.find("couleur", 0);
	
		string chaine = d.substr(indiceCouleur);
		const char * c = chaine.c_str();
		double x1, x2, y1, y2;
		int couleur;
		sscanf_s(c, "couleur %d (%lf,%lf);(%lf,%lf)", &couleur,&x1,&y1,&x2,&y2);
		


		return  new Segment(couleur, Vecteur2D(x1, y1), Vecteur2D(x2, y2));
}
