/**
*\file ParseurExpert.h
* @author KOUSSA Rayan KADRI Islem
* @brief prend une chaine de caractère et renvoi la forme adéquate
*/
#pragma once
#include <string>
#include "Forme.h"

class ParseurExpert
{
public:

	virtual Forme*  resoudre(const string& c) const = 0;
};
