/**
*\file ParseurCercle.h
* @author KOUSSA Rayan KADRI Islem
* @brief prend une chaine ,verifie si elle contien le mot Cercle puis renvoi soit Forme * ou bien null 
*/
#pragma once
#include "ParseurForme.h"
class ParseurCercle :public ParseurForme
{
public:

	/**
	* @brief Constructeur de ParseurSegment en le chainant au ParseurForme s
	* @param s : le parseur suivant
	*/
	ParseurCercle(ParseurForme* f);

	/**
	* @brief Destructeur
	*/
	~ParseurCercle();

	/**
	* @brief renvoi une forme* (Cercle*) si la  @param chaine contient un Cercle
	* @param chaine : la chaine a convertir en forme
	*/
	Forme* resoudre1(const string& chaine) const;
};

