/**
*\file Erreur.cpp
* @author KOUSSA Rayan KADRI Islem
*/


#include "FormeComplexe.h"
#include <algorithm>
#include "CompareFormesPtr.h"
#include "Transformation.h"

using namespace std;

FormeComplexe::FormeComplexe()
	:Forme()
{
}

FormeComplexe::FormeComplexe(const FormeComplexe & f)
 : Forme(f.couleur)
{
	vector<Forme*>::const_iterator it;
	
	for (it = f.formes.begin(); it != f.formes.end(); it++)
		formes.push_back((*it)->Clone());
}


FormeComplexe::~FormeComplexe()
{
	
	unsigned int i;
	for (i=0; i < formes.size(); i++)
	{
		delete formes[i];
	}

	formes.clear();



}

Forme * FormeComplexe::Clone() const
{
	return new FormeComplexe(*this);
}

const vector<Forme*>& FormeComplexe::getFormes() const
{
	return formes;
}


FormeComplexe & FormeComplexe::addForme(const Forme & f)
{

	vector<Forme *>::const_iterator it = contient(&f);
	if (it == formes.end())
	{
		if (formes.size() == 0)
			setCouleur(f.getCouleur());


		Forme * f2 = f.Clone();
		if (formes.size() != 0)
			f2->setCouleur(getCouleur());
		
		formes.push_back(f2);
	}
	return *this;
}


vector<Forme*>::const_iterator FormeComplexe::contient(const Forme * f) const
{
	return find_if(formes.begin(), formes.end(), CompareFormesPtr(f));
}

const FormeComplexe & FormeComplexe::supForme(const Forme & f)
{
	vector<Forme *>::const_iterator it = contient(&f);
	if (it != formes.end())
	{
		delete *it;
		formes.erase(it);
	}

	return *this;
}

const FormeComplexe & FormeComplexe::supForme(const unsigned int i)
{
	if ( i >= formes.size())
		throw Erreur("index hors bornes dans supression dans formecomplexe");

	delete formes[i];
	formes.erase(formes.begin() + i);

	return *this;

}


const FormeComplexe & FormeComplexe::operator=(const FormeComplexe & f)
{
	couleur = f.couleur;
	vector<Forme*>::const_iterator it;

	for (it = f.formes.begin(); it != f.formes.end(); it++)
		formes.push_back((*it)->Clone());
		


	return *this;
}

double FormeComplexe::CalculeAire() const
{
	double airTotale=0;
	vector<Forme*>::const_iterator it;
	for (it = formes.begin(); it != formes.end(); it++)
		airTotale += (*it)->CalculeAire();

	return airTotale;
}

FormeComplexe::operator string() const
{
	ostringstream os;
	os << "FormeComplexe [" << Forme::operator string() << "] [" << endl ;


	for (unsigned int i = 0; i < formes.size(); i++)
		os <<"\t" << i << "-" << *(formes[i]) << endl;

	os <<"]" ;



	return os.str();
}

Forme * FormeComplexe::transforme(const Transformation & t) const
{
	return t.visitor(*this);
}

string FormeComplexe::print() const
{
	ostringstream os;
	os << "FormeComplexe couleur " << couleur << " [";
	for (unsigned int i = 0; i < formes.size() - 1; i++)
		os << formes[i]->print() << "|";
	os << formes[formes.size() - 1]->print();
	os << "]";
	return os.str();
}

