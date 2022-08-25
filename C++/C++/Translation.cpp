/**
*\file Erreur.cpp
* @author KOUSSA Rayan KADRI Islem
*/


#include "Translation.h"
#include "Cercle.h"
#include "Polygone.h"
#include "FormeComplexe.h"
#include "segment.h"


Translation::Translation(const Vecteur2D &d)
	: u(d)
{};

Translation::~Translation()
{
}

const Vecteur2D & Translation::getU() const
{
	return u;
}


Vecteur2D Translation::visitor(const Vecteur2D & f) const
{
	return  f + getU();
}
