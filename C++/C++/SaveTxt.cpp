/**
*\file Erreur.cpp
* @author KOUSSA Rayan KADRI Islem
*/


#include "SaveTxt.h"
#include <fstream>
#include "Erreur.h"


using namespace std;
SaveTxt::SaveTxt(const string & f):Save(f)
{
}

SaveTxt::~SaveTxt()
{
}

void SaveTxt::visitor(const Forme & f) const
{


	ofstream fichier(nomFichier, ios::out | ios::app);


	if (fichier) {
		fichier << f.print() << endl;
		fichier.close();
	}
	else
	{
		throw Erreur("impossible d'ouvrir le fichier ");
	}


}
