
/**
*\file ParseurCercle.h
* @author KOUSSA Rayan KADRI Islem
* @brief prend une chaine ,verifie si elle contien le mot Polygone puis renvoi soit Forme * ou bien null
*/

#pragma once
#include "ParseurForme.h"
class ParseurPolygone :public ParseurForme
{
public:

	/**
	* @brief Constructeur de ParseurPolygone en le chainant au ParseurForme s
	* @param s : le parseur suivant
	*/
	ParseurPolygone(ParseurForme *);

	/**
	* @brief Destructeur
	*/
	~ParseurPolygone();

	/**
	* @brief renvoie une forme* (Polygone*) si la chaine contient un Polygone
	* @param chaine : la chaine a convertir en forme
	*/
	Forme* resoudre1(const string& chaine) const;


	
};


