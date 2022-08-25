/**
*\file CompareFormesPtr.h
* @author KOUSSA Rayan KADRI Islem
* @brief Foncteur qui prend 2 formes et compare leurs string()
*/

#pragma once
#include "Forme.h"

class CompareFormesPtr
{
	Forme * original;

public:

	/**
	* @brief Constructeur de CompareFormesPtr 
	* @param f : la forme à comparé
	*/
	CompareFormesPtr(const Forme * f)
	{
		original = const_cast <Forme *> (f);
	}

	/**
	*\Destructeur
	*/
	~CompareFormesPtr() {};

	/**
	* @brief compare le forme string de deux chaines
	* @param chaine : la chaine a convertir en forme
	*/
	bool operator()(const Forme * f)const {
		return (string(*f)) == (string(*original));			
	}

	
};

