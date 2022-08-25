package Outils;

/**
 * Classe : h�rite de Frame
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

		/* R�cup�ration dimensions �cran */
		Dimension dim = java.awt.Toolkit.getDefaultToolkit().getScreenSize();

		// int h = (int) dim.getHeight();
		int w = (int) dim.getWidth();

		/* d�finit les dimensions de la fen�tre */
		setBounds(0, 0, w / 4, w / 4);

		/* Fenetre visible */
		setVisible(true);

		/* Interdiction de redimention fenetre pour l'utilisateur */
		setResizable(false);

		/* d�sactive/Ignore l'appel automatique � Pain() */
		setIgnoreRepaint(true);

		/* l'ajout de l'�venement fermeture fenetre ==> bouton X */
		addWindowListener(new WindowAdapter() {
			public void windowClosing(WindowEvent windowEvent) {
				dispose();
			}
		});

		/* Cr�ation d'un nouveau Buffer */
		createBufferStrategy(1);

		Thread.sleep(150);

		/* Tra�age d'un rep�re orthonorm� */
		getBufferStrategy().getDrawGraphics().drawLine(getWidth() / 2,0,
													   			getWidth() / 2, getHeight());
		getBufferStrategy().getDrawGraphics().drawLine(0, getHeight() / 2,
													  			 getWidth(), getHeight() / 2);

		
	}

	/* m�thode qui permet d'avoir les rep�res (x,y) du centre de la fen�tre */
	public Point getCenter() {
		return new Point(getWidth() / 2, getHeight() / 2);
	}

	public Graphics2D getGraphics2D() {
		// R�cup�ration du buffer de la frame
		Graphics g = this.getBufferStrategy().getDrawGraphics();
		// on le cast en Graphics2D pour pouvoir dessiner avec des coordon�es doubles
		Graphics2D g2D = (Graphics2D) g;
		return g2D;
	}

}
