/**
*\file Erreur.cpp
* @author KOUSSA Rayan KADRI Islem
*/


#include "Segment.h"
#include "Transformation.h"



Segment::Segment(unsigned int c, const Vecteur2D & d,const  Vecteur2D & f)
	: FormeSimple(c), depart(d), fin(f)
{
}



Forme * Segment::Clone() const
{
	return new Segment(*this);
}


Segment::~Segment()
{
}

const  Vecteur2D&  Segment::getDepart() const
{
	return depart;
}

const Vecteur2D& Segment::getFin() const
{
	return fin;
}

void Segment::setDepart(const Vecteur2D & d)
{
	depart = d;
}

void Segment::setFin(const Vecteur2D & f)
{
	fin = f;
}



const Segment & Segment::operator=(const Segment & s)
{
	couleur = s.couleur;
	depart = s.depart;
	fin = s.fin;
	return *this;
}

double Segment::CalculeAire() const
{
	return 0.0;
}

Segment::operator string() const
{
	ostringstream os;
	os << FormeSimple::operator string() << " de type Segment [depart : " << depart << " , fin : " << fin << "]";
	return os.str();
}

Forme * Segment::transforme(const Transformation & t) const
{
	return t.visitor(*this);
}

string Segment::print() const
{

	ostringstream os;
	os << "Segment couleur " << couleur << " ";
	os << depart << ";" << fin ;

		return os.str();
	
}

