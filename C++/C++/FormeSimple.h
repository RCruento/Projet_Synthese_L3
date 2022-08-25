/**
*\file formeSimple.h
* @author KOUSSA Rayan KADRI Islem
* @brief class mère de toute les formes Simple
* @brief \class Segment,\class Polygone,\class Cercle
*/
#pragma once
#include "Forme.h"
class FormeSimple :public Forme
{
public:

	/**
	* Constructeur de formeSimple
	*/
	FormeSimple();

	/**
	* Constructeur de formeSimple
	* @param couelur : la couleur de la forme
	*/
	FormeSimple(unsigned int couleur);

	/**
	* Destructeur
	*/
	virtual ~FormeSimple();

	virtual operator string()const;
};

