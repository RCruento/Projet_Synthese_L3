/**
*\file Erreur.cpp
* @author KOUSSA Rayan KADRI Islem
*/

#include "Erreur.h"



Erreur::Erreur()
{
}

Erreur::Erreur(const string & m) :
	exception(m.c_str() , -1), msg(m)
{}

Erreur::Erreur(const Erreur & e)	: exception(e.what())
{
}


Erreur::~Erreur()
{
}

const char * Erreur::what() const
{
	return msg.c_str();
}
