package Geome;

import java.awt.Color;

import java.awt.Graphics2D;

import java.awt.geom.Line2D;
import java.util.ArrayList;

import Outils.FrameEcran;
import Outils.Point;

/**
 * Class : Polygone
 * @author KOUSSA Rayan KADRI Islem
 */

public class Polygone extends Forme {

	public Polygone(Forme suivant) {
		super(suivant);
	}

	public void dessine(String s, FrameEcran f) {
		// si la chaine s est bien passé alors Dessine sinon on fait rien
		if (s.matches("^Polygone couleur [0-9]+ \\{(\\(-?[0-9]+\\.[0-9]+,-?[0-9]+\\.[0-9]+\\);*){1,}\\}$")) {

			// Récuperation de la couleur du polygone
			String couleur = s.split(" ")[2];

			// Récupération des n points qui composent le polygone
			s = s.substring(s.indexOf("{") + 1, s.indexOf("}"));

			String[] tableauDePointString = s.split(";");

			ArrayList<Double> tabX = new ArrayList<Double>();
			ArrayList<Double> tabY = new ArrayList<Double>();

			// Création des Point pour chaque case du tableau et récupération du x et y dans un ArrayList de double
			for (String element : tableauDePointString) {
				Point p = new Point(element);
				tabX.add(p.getX());
				tabY.add(p.getY());
			}

			// Ajoute le premier point a la fin du tableau pour former une boucle sur le Polygone
			tabX.add(tabX.get(0));
			tabY.add(tabY.get(0));
			int taille = tabX.size();

			// Récupération du graphics2D de notre Frame
			Graphics2D g2D = f.getGraphics2D();

			// Modification la couleur du pinceau
			g2D.setColor(new Color(Integer.parseInt(couleur)));

			// Dessine le polygone en dessinant des Lignes2D entre le point i et le
			// suivant
			for (int i = 0; i < taille - 1; i++) {
				g2D.draw(new Line2D.Double(tabX.get(i) + f.getCenter().getX(),
										   tabY.get(i) + f.getCenter().getY(),
										   tabX.get(i + 1) + f.getCenter().getX(),
										   tabY.get(i + 1) + f.getCenter().getY())
						);
			}

		}

	}

	/**
	 * renvoie la chaine Polygone puisqu'on est dans le maillon Polygone
	 * @return "Polygone"
	 */

	public String getDescription(){ return "Polygone";	}
}