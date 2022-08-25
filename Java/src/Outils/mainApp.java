package Outils;

/**
 * Class : hérite de Frame
 * @author  KOUSSA Rayan KADRI Islem
 * @brief : Permet d'excuter le serveur
 */

import java.net.InetAddress;
import java.net.ServerSocket;
import java.net.Socket;
import Geome.Cercle;
import Geome.Forme;
import Geome.FormeComplexe;
import Geome.Polygone;
import Geome.Segment;

public class mainApp {
	public static Forme geo;

	public static void main(String[] args) throws Exception
	{
		initialisationGeo();
		ServerSocket server;
		server = new ServerSocket(8888);
		System.out.println("Serveur Paint ON : " + server);
		InetAddress localMachine;
		int localPort;
		ThreadGroup groupe;
		localPort = server.getLocalPort();
		localMachine = InetAddress.getLocalHost();
		System.out.println("Adresse IP du serveur Paint : " + localMachine.getHostAddress());
		System.out.println("Port du serveur obtenu : " + localPort);
		groupe = new ThreadGroup("ClientsSockets");
		int connexionId = 0;
		while (true) {
			Socket newClientSocket;
			PaintServer dessineur;
			newClientSocket = server.accept();
			++connexionId;
			System.out.println("Connexion n° :" + connexionId + " réussi");
			dessineur = new PaintServer(newClientSocket, groupe, connexionId);
			dessineur.start();
		}
	}
	/* initialise la chaine de résponsabilité parseuse de Forme */
	public static void initialisationGeo() {
		geo = new Segment(null);
		geo = new Cercle(geo);
		geo = new Polygone(geo);
		geo = new FormeComplexe(geo);
	}
	
	

}
