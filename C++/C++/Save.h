/**
*\file Save.h
* @author KOUSSA Rayan KADRI Islem
* @brief class Abstraite qui prend une forme et la sauve sous un format particulier (XML,BDD,TXT)
*/

#pragma once
#include "Forme.h"


class Save
{
protected :

	string nomFichier;

public:

	/*
	* @brief Constructeur du Save
	* @param filename : le nom du fichier dans le quel on veut enregistrer
	*/
	Save(const string & fileName);

	/*
	* @brief Destructeur
	*/
	virtual ~Save();

	virtual void visitor(const Forme & f)const = 0;


};

