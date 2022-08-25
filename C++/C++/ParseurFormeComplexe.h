/**
*\file ParseurCercle.h
* @author KOUSSA Rayan KADRI Islem
* @brief prend une chaine ,verifie si elle contien le mot FormeComplexe puis renvoi soit Forme * ou bien null
*/


#pragma once
#include "ParseurForme.h"
class ParseurFormeComplexe :
	public ParseurForme
{
public:
	
	/**
	* @brief Constructeur de ParseurFormeComplexe en le chainant au ParseurForme p
	* @param s : le parseur suivant
	*/
	ParseurFormeComplexe(ParseurForme * p);

	/**
	* @brief Destructeur
	*/
	~ParseurFormeComplexe();

	/**
	* @brief renvoie une forme* (FormeComplexe*) si la  @param chaine contient une FormeComplexe
	* @param chaine : la chaine a convertir en forme
	*/
	Forme* resoudre1(const string& chaine) const;

};

