/**
*\file ParseurExpert.h
* @author KOUSSA Rayan KADRI Islem
* @brief class mère de tout les autres parseurs, DP COR
* @brief \class ParseurSegment \class ParseurCercle \class ParseurPolygone \class ParseurTriangle \class ParseurFormeComplexe
*/
#pragma once
#include "ParseurExpert.h"




class ParseurForme :public ParseurExpert
{
protected :
	ParseurForme * suivant;

public:

	/**
	* @brief Constructeur de ParseurForme en le chainant au ParseurForme s 
	* @param s : le parseur suivant
	*/
	ParseurForme(ParseurForme * s);

	/**
	* @brief Destructeur
	*/
	virtual ~ParseurForme();

	/**
	* @brief methode qui fait le lien entre les maillons de la liste, renvoie une forme*
	* @param s : la chaine a parser
	*/
	 Forme*  resoudre(const string& s) const ;
	 
	 virtual Forme* resoudre1(const string& d) const = 0;


	 static vector <string> split(string chaine, char delim);
};

