/**
*\file Translation.h
* @author KOUSSA Rayan KADRI Islem
* @brief applique une Translation sur la forme
*/
#pragma once
#include "Transformation.h"
#include "Vecteur2D.h"
class Translation :public Transformation
{
	Vecteur2D u;

public:

	/**
	* @brief Construit une Translation a base d'un centre et un facteur f
	* @param v : le vecteur de translation 
	*/
	Translation( const Vecteur2D & v);

	/**
	*Destruction
	*/
	~Translation();

	const Vecteur2D & getU()const;

	/**
	* @brief applique la Translation sur un Point2D
	* @param point2D :le point qui subbit l'homotetie
	*/
	  Vecteur2D visitor(const Vecteur2D& f)const ;
};

