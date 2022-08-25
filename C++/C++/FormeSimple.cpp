/**
*\file Erreur.cpp
* @author KOUSSA Rayan KADRI Islem
*/

#include "FormeSimple.h"



FormeSimple::FormeSimple()
	:Forme()
{
}

FormeSimple::FormeSimple(unsigned int couleur)
	:Forme(couleur)
{
}

FormeSimple::~FormeSimple()
{
}

FormeSimple::operator string() const
{
	ostringstream os;
	os << "FormeSimple [" << Forme::operator string() << "]";

	return os.str();
}
