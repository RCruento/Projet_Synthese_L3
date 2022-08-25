/**
*\file Erreur.cpp
* @author KOUSSA Rayan KADRI Islem
*/


#include "Socket.h"
#include <iostream>
#pragma warning(disable:4996) 



Socket::Socket()
{
	int familleAdresse = AF_INET; // AF_INET6
	int typeSocket = SOCK_STREAM;
	int protocole = IPPROTO_TCP;

	sock = socket(familleAdresse, typeSocket, protocole);

	if (sock == INVALID_SOCKET) {
		cerr << "can't create socket, Err#" << WSAGetLastError() << endl;
		WSACleanup();
		throw	Erreur("Socket creation failed");
	}
	cout << "Sockette creation succed " << endl;
}

Socket::~Socket()
{
	cout << "fermeture du socket " << endl;
	closesocket(sock);
	WSACleanup();
	
}



void Socket::connectTo(const string & Ip, int p)const
{
	SOCKADDR_IN hint;
	hint.sin_family = AF_INET;
	hint.sin_port = htons(p);
	hint.sin_addr.s_addr = inet_addr(Ip.c_str());

	int con = connect(sock, (SOCKADDR *)&hint, sizeof(hint));
	if (con == SOCKET_ERROR)
	{
		throw Erreur("Connexion echoue au serveur");
	}
	else
	{
		cout << "Connexion succeded " << endl;

	}

}
void Socket::envoyer(const string & msg) const
{
	int sent = send(sock, msg.c_str(), strlen(msg.c_str()), 0);

	if (sent == SOCKET_ERROR)
	{
		throw Erreur("can't send to the server, Err#" + WSAGetLastError()); 
		closesocket(sock);
		WSACleanup();
	}
	cout << "Envoi r�ussie " << endl;
	
}
void Socket::envoyer(const Forme & f) const
{
	 envoyer(f.print()+"\r\n");
}

