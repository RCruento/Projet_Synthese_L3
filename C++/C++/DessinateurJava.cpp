/**
*\file Erreur.cpp
* @author KOUSSA Rayan KADRI Islem
*/


#include "DessinateurJava.h"



DessinateurJava::DessinateurJava(const string & ip, const int port):Dessinateur()
{

	sock.connectTo(ip, port);
}


DessinateurJava::~DessinateurJava()
{
}

void DessinateurJava::visitor(const Forme & f) const
{

	sock.envoyer(f);

}

