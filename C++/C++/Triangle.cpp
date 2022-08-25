#include "Triangle.h"
#include "Transformation.h"





Triangle::Triangle(unsigned int couleur, const Vecteur2D & p1, const Vecteur2D & p2, const Vecteur2D & p3)
	: Polygone(couleur,p1,p2,p3)
{

}


Forme * Triangle::Clone() const
{
	return new Triangle(*this);
}

Triangle::~Triangle()
{
}

double Triangle::CalculeAire() const
{
	return  Vecteur2D::determiner(points[0], points[1], points[2]) * 0.5;
}

const Triangle * Triangle::operator=(const Triangle & s)
{
	couleur = s.couleur;
	points = s.points;
	return this;
}

Triangle::operator string() const
{
	ostringstream os;
	os << FormeSimple::operator string() + " de type Triangle [points : ";

	for (unsigned int i = 0; i < points.size() -1 ; i++)
		os << "p" << i << points[i] << ",";

	os << "p" << points.size() - 1 <<  points[points.size() - 1] << "]";


	return os.str();
}

Forme * Triangle::transforme(const Transformation & t) const
{
	return t.visitor(*this);
}



