/**
*\file Socket.h
* @author KOUSSA Rayan KADRI Islem
* @brief class Socket pour communiquer avec un
*/
#pragma once
#include <string>
#include <WinSock2.h>
#include "Forme.h"

#pragma comment(lib, "ws2_32.lib")
using namespace std;

class Socket
{

	SOCKET sock;

	/**
	* @param msg : le message a envoy� au serveur
	* @brief prend un message et l'envoi en format text au serveur via le socket
	*/
	void envoyer(const string & msg)const;

public:

	/**
	* @brief Constructeur d'un socket
	*/
	Socket();

	/**
	* @brief Destructeur
	*/
	~Socket();

	/**
	* @brief se connecte au Serveur (Ip, port)
	* @param Ip : l'adresse 
	*/
	void connectTo(const string & Ip, int port)const;

	/**
	* @param f la forme a dessine
	* @brief prend une forme et l'envoi en format text au serveur via le socket
	*/
	void envoyer(const Forme& f)const;
	
};

