package Geome;

import java.awt.Color;
import java.awt.Graphics2D;
import java.awt.geom.Line2D;
import Outils.FrameEcran;
import Outils.Point;

/**
 * Class : Segment
 * @author KOUSSA Rayan KADRI Islem
 */

public class Segment extends Forme {

	public Segment(Forme suivant) {
		super(suivant);
	}

	public void dessine(String s, FrameEcran f) {
		// si la chaine s passe Dessine sinon rien
		if (s.matches(
				"^Segment couleur [0-9]+ \\(-?[0-9]+\\.[0-9]+,-?[0-9]+\\.[0-9]+\\);\\(-?[0-9]+\\.[0-9]+,-?[0-9]+\\.[0-9]+\\)$")) {

			// Récupération la chaine en morceau
			String[] chaineEnMorceau = s.split(" ");
			// Récupération la couleur
			String couleur = chaineEnMorceau[2];
			// Récupération les points2D
			String[] tab = chaineEnMorceau[3].split(";");
			Point p1 = new Point(tab[0]);
			Point p2 = new Point(tab[1]);
			// Récupération le graphics2D de notre Frame
			Graphics2D g2D = f.getGraphics2D();
			// Modification la couleur du pinceau
			g2D.setColor(new Color(Integer.parseInt(couleur)));
			// Dessine la ligne
			g2D.draw(new Line2D.Double(p1.getX() + f.getCenter().getX(),
									   p1.getY() + f.getCenter().getY(),
									   p2.getX() + f.getCenter().getX(),
									   p2.getY() + f.getCenter().getY()));
		}
	}

	/**
	 * renvoie la chaine Segment etant donner qu'on est dans le maillon Segment
	 * @return "Segment"
	 */
	public String getDescription() {
		return "Segment";
	}
}