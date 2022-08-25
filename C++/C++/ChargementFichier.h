
/**
*\file ChargementFichier.h
* @author KOUSSA Rayan KADRI Islem
* @brief class singleton qui parcour un fichier et parse chaque ligne pour renvoyer un vector de formes
*/


#pragma once
#include <string>
#include <vector>
#include "Forme.h"
#include "ParseurForme.h"
using namespace std;

class ChargementFichier
{
	/**
	* @brief Constructeur de ChargementFichier
	*/
	ChargementFichier();

public:

	/**
	* @brief renvoi un pointeur sur le ChargementFichier creer si il a deja ete instancier sinon renvoi un nouveau
	* @return static ChargementFichier * un nouveau ChargementFichier
	*/
	static ChargementFichier* getInstance();

	/**
	* @brief ce chargeur parcour un 'fichier' grace a un 'Parseur' et retourne un vector de Forme*
	* @param filename : le nom du fichier 
	* @param parseur : le parseur de forme
	* @return static vector<Forme *> 
	*/
	static vector<Forme *> charge(const string filename, const ParseurForme *p);

};

