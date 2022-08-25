/**
* @file Transformation.h
* @author KOUSSA Rayan KADRI Islem
* @brief Class Abstraite applique une transformation Geome trique sur une Forme
*/

#pragma once
#include<string>

#include"Polygone.h"
#include"Cercle.h"
#include"segment.h"
#include"FormeComplexe.h"
#include "Triangle.h"

using namespace std;

class Transformation
{
public:

	/**
	*Destructeur	
	*/
	virtual ~Transformation();

	/**
	* @brief : applique la transformation sur un polygone
	* @param p : le polygone en question
	*/
	 Forme* visitor(const Polygone & p)const;

	/**
	* @brief applique la transformation sur un Triangle
	* @param t : le Triangle en question
	*/
	 Forme* visitor(const Triangle & t)const;

	/**
	* @brief applique la transformation sur un Segment
	* @param s : le Segment en question
	*/
	 Forme* visitor(const Segment & s)const;

	 /**
	 * @brief applique la transformation sur un Cercle
	 * @param c : le Cercle en question
	 */
	virtual Forme* visitor(const Cercle & c)const;

	/**
    * @brief applique la transformation sur la FormeComplexe
    * @param f : la FormeComplexe en question
    */
	Forme* visitor(const FormeComplexe& f)const;

	virtual Vecteur2D visitor(const Vecteur2D& f)const=0;

};

