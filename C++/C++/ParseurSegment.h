/**
*\file ParseurCercle.h
* @author KOUSSA Rayan KADRI Islem
* @brief prend une chaine ,verifie si elle contien le mot Segment puis renvoi soit Forme * ou bien null
*/

#pragma once
#include "ParseurForme.h"
class ParseurSegment :
	public ParseurForme
{
public:
	/**
	* @brief Constructeur de ParseurSegment en le chainant au ParseurForme s
	* @param s : le parseur suivant
	*/
	ParseurSegment(ParseurForme* f);
	/**
	* @brief Destructeur
	*/
	~ParseurSegment();

	/**
	* @brief renvoi une forme* (Segment*) si la  @param chaine contient un Segment
	* @param chaine : la chaine a convertir en forme
	*/
	Forme* resoudre1(const string& chaine) const;
};

