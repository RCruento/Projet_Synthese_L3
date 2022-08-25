
#pragma region FichierPrecompileEtIO

#include <iostream>
#pragma endregion FichierPrecompileEtIO

#pragma region GestionMemoire 
#define _CRTDBG_MAP_ALLOC 
#include <stdlib.h> 
#include <crtdbg.h> 
#pragma endregion GestionMemoire 

#pragma region Forme 
#include "Vecteur2D.h"
#include "Forme.h"
#include "Segment.h"
#include "Polygone.h"
#include "Triangle.h"
#include "Cercle.h"
#include "FormeComplexe.h"
#pragma endregion Forme 

#pragma region Transformation 
#include "Translation.h"
#include "Rotation.h"
#include "Homotetie.h"
#pragma endregion Transformation 

#pragma region Parseurs 
#include "ParseurCercle.h"
#include "ParseurTriangle.h"
#include "ParseurSegment.h"
#include "ParseurPolygone.h"
#include "ParseurFormeComplexe.h"
#pragma endregion Parseurs 

#pragma region Dessinateur&Socket 
#include "Socket.h"
#include "DessinateurJava.h"
#pragma endregion Dessinateur&Socket  

#pragma region Chargeur&Save
#include "ChargementFichier.h"
#include "SaveTxt.h"
#pragma endregion Chargeur&Save
using namespace std;
void initialisationWSA();



int main()
{
	string ipAddress = "127.0.0.1";
	int port = 8888;


	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	initialisationWSA();
	DessinateurJava  dessinateur = DessinateurJava(ipAddress, port);

	/**COULEURS*/

	const int BLACK = 0;
	const int CYAN = 255;
	const int GREEN = 65280;
	const int RED = 16711680;
	const int YELLOW = 16776960;

	try {
		cout << "*************|____Test des Formes____|*************" << endl;


		Homotetie homotetie = Homotetie(Vecteur2D(5, 7), 10);

		Vecteur2D p1(1, -1);
		Vecteur2D p2(5, -1);
		Vecteur2D p3(5, 1);
		Vecteur2D p4(1, 1);

		vector<Vecteur2D> points;
		points.push_back(p1);
		points.push_back(p2);
		points.push_back(p3);
		points.push_back(p4);

		Polygone R1(CYAN, points);
		//cout << "l'air du Rectangle R1 = " << R1.CalculeAire() << endl;
		//cout << "Dessin Rectangle en cours d'envoie" << endl;
		//R1.dessine(dessinateur);
		
		//Forme* R1Prime = R1.transforme(homotetie);


		Vecteur2D p7(6, -1);
		Vecteur2D p5(8, 0);
		Vecteur2D p6(6, 1);

		vector<Vecteur2D> pointsT1;
		pointsT1.push_back(p7);
		pointsT1.push_back(p5);
		pointsT1.push_back(p6);
		
		
	
		
		Polygone T1(GREEN, pointsT1);
		cout << "l'air du Triangle T1 = " << T1.CalculeAire() << endl;
		cout << "Dessin Triangle en cours d'envoie" << endl;
		//T1.dessine(dessinateur);

		//! Pas encore résolu
		//Forme  * T1Prime = T1.transforme(homotetie);
		//T1Prime->dessine(dessinateur);


		Cercle C1(YELLOW, Vecteur2D(11, 0), 2);
		cout << "l'air du Cercle C1 = " << C1.CalculeAire() << endl;
		cout << "Dessin Cercle en cours d'envoie" << endl;
		//C1.dessine(dessinateur);

		//! Pas encore résolu
		//Forme * C1Prime = C1.transforme(homotetie);
		//C1Prime->dessine(dessinateur);


		FormeComplexe  G1;
		G1.addForme(R1).addForme(T1).addForme(C1);
	
		Translation translation(Vecteur2D(-1, 0));
		Forme * G2Prime=  G1.transforme(translation);
		G2Prime->transforme(homotetie);
		cout << "Dessin en cours de Translation" << endl;
		G2Prime->dessine(dessinateur);

		Rotation rotation(3.14/4, Vecteur2D(0, 0));
		Forme * G3Prime = G2Prime->transforme(rotation);
		G3Prime->transforme(homotetie);
		cout << "Dessin en cours de Rotation" << endl;
		G3Prime->dessine(dessinateur);
		cout << "l'air du Groupe G1 = " << G3Prime->CalculeAire() << endl;

		
		Forme  * G1Prime = G1.transforme(homotetie);
		G1Prime->dessine(dessinateur);

		
		
		
		
		SaveTxt Save =  SaveTxt("mabellefigure1.txt");
		G1.save(Save);


		delete G3Prime;


		ChargementFichier * chargeur = ChargementFichier::getInstance();

		ParseurForme * parseur = new ParseurSegment(NULL);
		parseur = new ParseurCercle(parseur);
		parseur = new ParseurPolygone(parseur);
		parseur = new ParseurFormeComplexe(parseur); 
		vector<Forme*> v = chargeur->charge("mabellefigure1.txt", parseur);
		FormeComplexe G2;
		//G2.addForme(v[1]);

	
	}
	catch (Erreur e)
	{
		cout << e.what() << endl;
		
	}
	system("pause");

	return 0;
}

void initialisationWSA() {
	WSADATA WSAData;
	WORD version = MAKEWORD(2, 0);
	int wsResult = WSAStartup(version, &WSAData);
	if (wsResult) // 0 no erreur else erreur
	{
		throw Erreur("can't start winsock, Err #" + wsResult);
		
	}
	cout << "initialisation OF WSA succeded" << endl;

}

