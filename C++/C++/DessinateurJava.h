/**
*\file DessinateurJava.h
* @author KOUSSA Rayan KADRI Islem
* @brief Class Abstraite qui prend une forme et la dessine avec Java
*/

#pragma once
#include "Dessinateur.h"
#include "Socket.h"

class DessinateurJava :public Dessinateur
{
	Socket sock;
public:

	/**
	*\Constructeur
	*cr�e un socket connect� � l'addresse IP & port donn�e en param�tre
	* @param ip Adresse Ip du serveur Dessinateur 
	* @param port port d'�coute du serveur Dessinateur
	*/
	DessinateurJava(const string & ip,const int port);

	virtual ~DessinateurJava();
	
	/**
	*\Constructeur
	*\cr�e un socket connect� � l'addresse IP & port donn�e en param�tre
	* @param f la forme a dessiner
	*/
	void visitor(const Forme& f)const ;
	
};

