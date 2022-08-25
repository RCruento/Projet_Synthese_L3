#include "ParseurForme.h"


ParseurForme::ParseurForme(ParseurForme * s)
	: suivant(s)
{
}

ParseurForme::~ParseurForme()
{
	delete suivant;
}

Forme * ParseurForme::resoudre(const string & c) const
{
	Forme *f = this->resoudre1(c);        // cet expert tente de résoudre le
										  //  problème
	if (f != NULL) 			// cet expert a trouvé une solution 
		return f;
	else            			// échec de cet expert
		if (this->suivant != NULL)  		// le problème est transmis à   
											// l’expert suivant
			return this->suivant->resoudre(c);
		else    // cet expert est le dernier de la chaîne
			return NULL;// donc échec de la chaîne
}


vector <string> ParseurForme::split(string chaine, char delim) {
	vector<string> tab;
	istringstream f(chaine.c_str());
	string s;
	while (getline(f, s, delim)) {
		tab.push_back(s);
	}
	return tab;
}