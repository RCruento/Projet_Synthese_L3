/**
*\file Erreur.cpp
* @author KOUSSA Rayan KADRI Islem
*/


#include "ChargementFichier.h"
#include <fstream>
static   ChargementFichier * chargeur = ChargementFichier::getInstance();

ChargementFichier * ChargementFichier::getInstance()
{
	return chargeur;
}



vector<Forme*> ChargementFichier::charge(const string filename, const ParseurForme * p)
{

	vector<Forme *> vecteurForme;
	ifstream myfile;
	myfile.open(filename, std::fstream::in);
	if (myfile.is_open()) {
		string  s;


		while (getline(myfile, s)) {

			Forme * f = NULL;

			try {
				f = p->resoudre(s);
			}
			catch (exception e) {
				cout << e.what();
			}
			if (f != NULL)
			{
				vecteurForme.push_back(f);

			}
		}
	}
	else
		throw Erreur("Openening File");

	return vecteurForme;
}
