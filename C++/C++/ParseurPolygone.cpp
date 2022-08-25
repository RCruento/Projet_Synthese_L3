/**
*\file Erreur.cpp
* @author KOUSSA Rayan KADRI Islem
*/


#include "ParseurPolygone.h"
#include <regex>
#include "Polygone.h"
#include "Vecteur2D.h"
#include <cstring>
#include <iostream>




ParseurPolygone::ParseurPolygone(ParseurForme *s)
	:ParseurForme(s)
{
}

ParseurPolygone::~ParseurPolygone()
{
}

Forme * ParseurPolygone::resoudre1(const string & d) const
{

	int indicePolygone = d.find("Polygone", 0);

	if (indicePolygone == std::string::npos)
		return NULL;
	else {	
		const char * chaine = d.c_str();
		// récupération de la couleur
		int couleur;
		sscanf_s(chaine, "Polygone couleur %d", &couleur);

		int indiceAccolladeO = d.find("{");

		int indiceAccolladeF = d.find("}");

		string ligne = d.substr(indiceAccolladeO + 1,indiceAccolladeF-indiceAccolladeO-1);

		vector<Vecteur2D> v;
		vector<string> res = split(ligne, ';');
		for (unsigned int i = 0; i < res.size(); i++)
		{
			v.push_back(Vecteur2D(res[i].c_str()));
		}
		
	

		return new Polygone(couleur, v);
	}
}

