package Geome;

/**
 * Class : Forme
 * @author KOUSSA Rayan KADRI Islem
 */
import Outils.FrameEcran;

public abstract class Forme implements Expert {

	private Forme suivant = null;

	/**
	 * Constructeur d'une Liste de Forme
	 * @param suivant : le Forme suivant
	 */
	public Forme(Forme suivant) {
		this.suivant = suivant;
	}

	/**
	 * renvoi le Forme Suivant
	 * @return Forme le maillon suivant
	 */
	public Forme getSuivant() {
		return suivant;

	}

	/**
	 * Compare la description du maillon actuel avec le premier mot de la chaine s
	 * @param s :la chaine qui contient la forme a dessiner exemple "Cercle..."
	 * @return vraie si la description du maillon est identique au premier mot de s
	 */

	public boolean saitDessiner(String s) {
		String premierMotDeLaChaineS = s.split(" ")[0];
		return getDescription().equals(premierMotDeLaChaineS);
	}

	/**
	 * @return : renvoie la description du maillon
	 */

	public abstract String getDescription();

	/**
	 * dessine la forme geometrique sur la frame
	 * @param s : la forme a dessiner au format string
	 * @param f : la frame sur laquelle Dessine
	 */
	public abstract void dessine(String s, FrameEcran f);

	/**
	 * methode qui switch entre les maillons pour voir lequel peut dessiner
	 */
	public void dessiner(String chaine, FrameEcran f) {

		// si le maillon actuel sait dessiner alors Dessine
		if (saitDessiner(chaine)) {
			dessine(chaine, f);
		} else { // sinon on regarde si le maillon suivant n'est pas nul on lui délégue la tache
				// sinon aucun maillon ne peut dessiner
			if (suivant != null) {
				suivant.dessiner(chaine, f);
			}
		}
	}
}