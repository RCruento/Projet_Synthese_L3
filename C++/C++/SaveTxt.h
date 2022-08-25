/**
*\file SaveTxt.h
* @author KOUSSA Rayan KADRI Islem
* @brief class  qui prend une forme et la sauve sous un format particulier TXT
*/

#pragma once
#include "Save.h"
class SaveTxt :public Save
{
public:

	/*
	* @brief Constructeur de SaveTxt
	* @param filename : le nom du fichier dans lequel on veut enregistrer
	*/
	SaveTxt(const string & f);

	/*
	* @brief Destructeur
	*/
	virtual ~SaveTxt();

	/*
	* @brief Constructeur de SaveTxt
	* @param filename : le nom du fichier dans lequel on veut enregistrer
	*/
	void visitor(const Forme & f)const;
};

