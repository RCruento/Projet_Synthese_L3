package Geome;

/**
 * Class : Cercle
 * @author KOUSSA Rayan KADRI Islem
 */

import java.awt.Color;
import java.awt.Graphics2D;
import java.awt.geom.Ellipse2D;
import Outils.FrameEcran;
import Outils.Point;

public class Cercle extends Forme {
	public Cercle(Forme suivant) {
		super(suivant);
	}

	public void dessine(String s, FrameEcran f) {
		// si la chaine s est bien passé alors Dessine sinon on fait rien
		if (s.matches("^Cercle rayon [0-9]+\\.?[0-9]+ couleur [0-9]+ \\(-?[0-9]+\\.[0-9]+,-?[0-9]+\\.[0-9]+\\)$")) {

			String[] tab = s.split(" ");
			// Récupération le rayon r
			double rayon = Double.parseDouble(tab[2]);
			// Récupération la couleur
			String couleur = tab[4];
			// Récupération le centre
			Point centre = new Point(tab[5]);

			// Récupération du graphics2D de notre Frame
			Graphics2D g2D = f.getGraphics2D();

			// Modification de la couleur du pinceau
			g2D.setColor(new Color(Integer.parseInt(couleur)));
			// Dessine le cercle avec un certain décalage pour bien ce centrer sur la fenetre
			g2D.draw(new Ellipse2D.Double(centre.getX() + f.getCenter().getX() - rayon * 0.5,
										  		centre.getY() + f.getCenter().getY() - rayon * 0.5, rayon, rayon)
					);

		}

	}

	/**
	 * renvoie la chaine Cercle etant donner qu'on est dans le maillon Cercle
	 */

	public String getDescription()

	{
		return "Cercle";

	}
}