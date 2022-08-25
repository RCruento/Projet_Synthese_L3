/**
*\file ParseurCercle.h
* @author KOUSSA Rayan KADRI Islem
* @brief prend une chaine ,verifie si elle contien le mot Triangle puis renvoi soit Forme * ou bien null
*/

#pragma once
#include "ParseurForme.h"
class ParseurTriangle :public ParseurForme
{
public:

	/**
	* @brief Constructeur de ParseurTriangle en le chainant au ParseurForme s
	* @param s : le parseur suivant
	*/
	ParseurTriangle(ParseurForme*);

	/**
	* @brief Destructeur
	*/
	~ParseurTriangle();

	/**
	* @brief renvoie une forme* (Triangle*) si la  @param chaine contient un Triangle
	* @param chaine : la chaine a convertir en forme
	*/
	Forme * resoudre1(const string & chaine) const;
};

