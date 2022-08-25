package Outils;

/**
 * Classe : hérite de Frame
 * @author  KOUSSA Rayan KADRI Islem
 * @see awt.Frame
 */

import java.awt.Frame;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.Dimension;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

public class FrameEcran extends Frame {

	public FrameEcran(int noClient, String chaine) throws InterruptedException {
		super("Dessin Client numero : " + noClient + chaine);

		/* Récupération dimensions écran */
		Dimension dim = java.awt.Toolkit.getDefaultToolkit().getScreenSize();

		// int h = (int) dim.getHeight();
		int w = (int) dim.getWidth();

		/* définit les dimensions de la fenêtre */
		setBounds(0, 0, w / 4, w / 4);

		/* Fenetre visible */
		setVisible(true);

		/* Interdiction de redimention fenetre pour l'utilisateur */
		setResizable(false);

		/* désactive/Ignore l'appel automatique à Pain() */
		setIgnoreRepaint(true);

		/* l'ajout de l'évenement fermeture fenetre ==> bouton X */
		addWindowListener(new WindowAdapter() {
			public void windowClosing(WindowEvent windowEvent) {
				dispose();
			}
		});

		/* Création d'un nouveau Buffer */
		createBufferStrategy(1);

		Thread.sleep(150);

		/* Traçage d'un repère orthonormé */
		getBufferStrategy().getDrawGraphics().drawLine(getWidth() / 2,0,
													   			getWidth() / 2, getHeight());
		getBufferStrategy().getDrawGraphics().drawLine(0, getHeight() / 2,
													  			 getWidth(), getHeight() / 2);

		
	}

	/* mèthode qui permet d'avoir les repères (x,y) du centre de la fenêtre */
	public Point getCenter() {
		return new Point(getWidth() / 2, getHeight() / 2);
	}

	public Graphics2D getGraphics2D() {
		// Récupération du buffer de la frame
		Graphics g = this.getBufferStrategy().getDrawGraphics();
		// on le cast en Graphics2D pour pouvoir dessiner avec des coordonées doubles
		Graphics2D g2D = (Graphics2D) g;
		return g2D;
	}

}
