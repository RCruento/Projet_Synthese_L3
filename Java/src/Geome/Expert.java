package Geome;
/**
 * Class : Expert
 * @author KOUSSA Rayan KADRI Islem
 * @see awt.Frame
 */

import Outils.FrameEcran;

public interface Expert {

	/**
	 * methode qui passe une chaine et qui dessine le résultat sur une forme
	 * @param chaine : la chaine à parse
	 * @param f : la fenetre sur le quel dessiner
	 */
	public void dessiner(String chaine, FrameEcran f);
}
