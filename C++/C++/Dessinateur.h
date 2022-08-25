/**
*\file Dessinateur.h
* @author KOUSSA Rayan KADRI Islem
* @brief Class Abstraite qui prend une forme et la dessine
*/

#pragma once
#include "Forme.h"
class Dessinateur
{
public:
	virtual ~Dessinateur() {};
	virtual void visitor(const Forme& f)const = 0;
	
};

