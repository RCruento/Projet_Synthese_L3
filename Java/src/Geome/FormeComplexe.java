package Geome;

import Outils.FrameEcran;
import Outils.mainApp;

/**
 * Class : FormeComplexe
 * @author KOUSSA Rayan KADRI Islem
 */

public class FormeComplexe extends Forme {

	public FormeComplexe(Forme suivant) {
		super(suivant);
	}

	public void dessine(String s, FrameEcran f) {
		// si la chaine s est bien Dessine sinon rien
		if (s.matches("^FormeComplexe couleur [0-9]+ .*")) {
			// Récupération les formes qui sont dans la formeCompose
			s = s.substring(s.indexOf("[") + 1, s.lastIndexOf("]"));
			// Décomposition en sous forme
			if (s.indexOf("|") != -1) {
				String[] tab = s.split("\\|");
				for (String forme : tab) {
					mainApp.geo.dessiner(forme, f);
				}
			} else {
				mainApp.geo.dessiner(s, f);
			}
		}
	}

	/**
	 * renvoie la chaine FormeComplexe etant donner qu'on est dans le maillon
	 * @return : "FormeComplexe"
	 */

	public String getDescription() {
		return "FormeComplexe";
	}
};