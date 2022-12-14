/**
*\file ParseurExpert.h
* @author KOUSSA Rayan KADRI Islem
* @brief prend une chaine de caract?re et renvoi la forme ad?quate
*/
#pragma once
#include <string>
#include "Forme.h"

class ParseurExpert
{
public:

	virtual Forme*  resoudre(const string& c) const = 0;
};
