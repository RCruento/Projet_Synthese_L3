/**
*\file forme.h
* @author KOUSSA Rayan KADRI Islem
* @brief class abstraite m�re de toute la formes	
*/

#pragma once
#define _USE_MATH_DEFINES
#include <string>
#include <vector>
#include <sstream>
#include "Vecteur2D.h"
#include <iostream>
#include <math.h>
#include "Erreur.h"

class Dessinateur;
class Save;
class Transformation;
class ParseurForme;
using namespace std;

class Forme
{
protected:
	unsigned	int couleur;
public:


	/**
	* Constructeur de forme
	*/
	Forme();

	/**
	* Constructeur de forme
	* @param couleur : la couleur de la forme
	*/
	Forme(unsigned int couleur);
	
	/**
	* Constructeur par recopie d'une forme
	* @param f : la forme a recopie
	*/
	Forme(const Forme& f);
	
	/**
	* clone la forme 
	* @return Forme * : une nouvelle forme identique a la forme appelante	
	*/
	virtual Forme* Clone() const = 0;

	/**
	* Destructeur
	*/
	virtual ~Forme();
	
	/**
	* renvoi l'entier correspondant a la couleur de la forme
	* @return  unsigned int
	*/
	unsigned int getCouleur() const;
	
	/**
	* dzfinit la couleur de la forme
	* @param c : la nouvelle couleur 
	*/
	void setCouleur(const unsigned int c) ;

	friend ostream & operator <<(ostream & f, const Forme & o);

	/**
	* imprime la couleur de la forme sous forme Text
	*/
	virtual operator string()const;
	
	/**
	* calcule l'air d'une forme
	* @return   en double
	*/
	virtual double CalculeAire() const = 0;

	/**
	* transforme  une forme
	* @return une forme
	* @param t : la transformation a appliquer a la forme
	*/
	virtual Forme* transforme(const Transformation & t)const = 0;
	
	/**
	*  Dessine une forme 
	*  @param d : le Dessinateur de la forme
	*/
	void dessine(const Dessinateur & d)const;
	
	/**
	*  sauvgarde une forme sous Forme Text
	*  @param s : le Save
	*/
	void save(const Save & s)const;
	
	/**
	*  imprime la forme sous un forme sp�cifique
	*/
	virtual string print() const = 0;
	
};

