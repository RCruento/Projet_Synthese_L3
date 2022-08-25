/**
*\file Erreur.cpp
* @author KOUSSA Rayan KADRI Islem
*/



#include "Cercle.h"
#include "Transformation.h"


Cercle::Cercle():FormeSimple(), centre(0, 0), rayon(0)
{

}

Cercle::Cercle(unsigned int couleur,const Vecteur2D& c, double r)
	: FormeSimple(couleur), centre(c)
{
	setRayon(r);
}


Forme* Cercle::Clone() const
{
	return new Cercle(*this);

}


Cercle::~Cercle() {

}

const Vecteur2D& Cercle::getCentre()const
{
	return centre;
}


void Cercle::setCentre(const Vecteur2D &c) {

	centre = c;
}

double Cercle::getRayon()const {
	return rayon;
}
void Cercle::setRayon(const double r)
{
	if (r < 0)
		throw Erreur("Rayon du Cercle < 0 ");
	rayon = r;
}


double Cercle::CalculeAire()const
{
	return  M_PI*rayon*rayon;
}

Cercle::operator string() const {
	ostringstream os;
	os << FormeSimple::operator string() << " de type Cercle [centre " << centre << " ,rayon " << rayon << "]";
	return os.str();

}

const Cercle & Cercle:: operator= (const Cercle &c)
{
	rayon = c.rayon;
	centre = c.centre;
	couleur = c.couleur;
	return *this;
}

Forme * Cercle::transforme(const Transformation & t) const
{
	return t.visitor(*this);
}

string Cercle::print() const
{
	
		ostringstream os;
		os << "Cercle rayon " << rayon << " couleur " << couleur << " "<< centre;
		return os.str();
	
}



