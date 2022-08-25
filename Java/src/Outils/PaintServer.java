package Outils;

/**
 * Class : PaintServer est un Thread qui déssine la forme récupérée depuis un Socket
 * @author  KOUSSA Rayan KADRI Islem
 * @see Thread
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

import java.net.Socket;

public class PaintServer extends Thread {
	private Socket socket;
	private int noConnexion;
	private BufferedReader fluxEntrant;

	public PaintServer(Socket s, ThreadGroup g, int connexion) throws IOException {
		super(g, "Paint Server");
		socket = s;
		noConnexion = connexion;
		fluxEntrant = new BufferedReader(new InputStreamReader(this.socket.getInputStream()));
	}

	public void run() {

		String ligne;
		try {
			while (!isInterrupted()) {
				ligne = fluxEntrant.readLine();
				if (ligne != null) {
					System.out.println(" le client n° " + this.noConnexion + " a envoyé : ");
					System.out.println(ligne);
					FrameEcran f = new FrameEcran(noConnexion, ligne);
					mainApp.geo.dessiner(ligne, f);

					f.getBufferStrategy().show();
					f.getBufferStrategy().getDrawGraphics().dispose();

					sleep(5);
				}
			}
		} catch (InterruptedException e) {}
		catch (IOException e) {
			System.err.println(" on ne peut lire sur le socket provenant du client");
		}
	}// run

}// Paint
