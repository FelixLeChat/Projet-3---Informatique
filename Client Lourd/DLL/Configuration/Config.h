//////////////////////////////////////////////////////////////////////////////
/// @file Config.h
/// @author Ghislaine Menaceur, Blanche Paiement
/// @date 2015-03-10
/// @version 1.0
///
/// @addtogroup inf2990 INF2990
/// @{
//////////////////////////////////////////////////////////////////////////////
#ifndef __CONFIGURATION_CONFIG_H__
#define __CONFIGURATION_CONFIG_H__

#include "singleton.h"

///////////////////////////////////////////////////////////////////////////
/// @class Config
/// @brief Les variables de configuration.
///        C'est une classe singleton.
///
/// @author Ghislaine Menaceur, Blanche Paiement
/// @date 2015-03-10
///////////////////////////////////////////////////////////////////////////
class Config : public Singleton<Config>
{
	SINGLETON_DECLARATION_CLASSE(Config);

public:

	/////////////////////////////////////////////////////////
	/// Cr�er le fichier de config avec les valeurs.
	/////////////////////////////////////////////////////////
	bool creerConfig(char* nomFichier, int longueur) const;

	/////////////////////////////////////////////////////////
	/// Lire les valeurs de la config.
	/////////////////////////////////////////////////////////
	bool lireConfig(char* nomFichier, int longueur, bool tout);

	/////////////////////////////////////////////////////////
	/// Obtenir les diff�rents �l�ments de configuration
	/////////////////////////////////////////////////////////
	
	/// Obtenir la touche de contr�le de la palette gauche du joueur 1
	const int getPg1();
	/// Obtenir la touche de contr�le de la palette droite du joueur 1
	const int getPd1();
	/// Obtenir la touche de contr�le de la palette gauche du joueur 2
	const int getPg2();
	/// Obtenir la touche de contr�le de la palette droite du joueur 2
	const int getPd2();
	/// Obtenir la touche de contr�le du ressort
	const int getRes();
	/// Obtenir le nombre de billes pour une partie
	const int getNbBilles();
	/// Obtenir si le mode double billes est activ�e
	const bool getMode2Billes();
	/// Obtenir si la force de rebond suppl�mentaire des butoirs est activ�e
	const bool getForceRebond();
	/// Obtenir l'affichage de d�bogage
	const bool getDebog();
	/// Obtenir l'affichage de la g�n�ration de bille
	const bool getGenBille();
	/// Obtenir l'affichage de la vitesse des billes apr�s collision
	const bool getVitBilles();
	/// Obtenir l'affichage de l'activation ou non de l'�clairage 
	const bool getEclairage();
	/// Obtenir l'affichage de la limite d'attraction des portails
	const bool getLimitesPortails();

	/////////////////////////////////////////////////////////
	/// Assigner les diff�rents �l�ments de configuration
	/////////////////////////////////////////////////////////
	
	/// Assigner la touche de contr�le de la palette gauche du joueur 1
	void setPg1(const int);
	/// Assigner la touche de contr�le de la palette droite du joueur 1
	void setPd1(const int);
	/// Assigner la touche de contr�le de la palette gauche du joueur 2
	void setPg2(const int);
	/// Assigner la touche de contr�le de la palette droite du joueur 2
	void setPd2(const int);
	/// Assigner la touche de contr�le du ressort
	void setRes(const int);
	/// Assigner le nombre de billes pour une partie
	void setNbBilles(const int);
	/// Assigner si le mode double billes est activ�e
	void setMode2Billes(const bool);
	/// Assigner si la force de rebond suppl�mentaire des butoirs est activ�e
	void setForceRebond(const bool);
	/// Assigner l'affichage de d�bogage
	void setDebog(const bool);
	/// Assigner l'affichage de la g�n�ration de bille
	void setGenBille(const bool);
	/// Assigner l'affichage de la vitesse des billes apr�s collision
	void setVitBilles(const bool);
	/// Assigner l'affichage de l'activation ou non de l'�clairage 
	void setEclairage(const bool);
	/// Assigner l'affichage de la limite d'attraction des portails
	void setLimitesPortails(const bool);

	/// Mise � jour de la configuration
	void mettreAJourConfiguration(int, int, int, int, int, int, bool, bool, bool, bool, bool, bool, bool);

	/// Valeurs de touche de contr�le par d�faut
	void toucheDefaut();

private:
	
	/////////////////////////////////////////////////////////
	/// Touches du clavier
	////////////////////////////////////////////////////////
	
	/// Palette gauche J1
	int pg1_;
	/// Palette droite J1
	int pd1_;
	/// Palette gauche J2
	int pg2_;
	/// Palette droite J2
	int pd2_;
	/// Ressort
	int res_;

	/// Nombre de billes pour une partie
	int nbBilles_;
	/// Mode double billes
	bool mode2Billes_;
	/// Force de rebond suppl�mentaire des butoirs
	bool forceRebond_;

	/////////////////////////////////////////////////////////
	/// Affichages
	////////////////////////////////////////////////////////

	/// Affichage de d�bogage
	bool debog_;
	/// Affichage de la g�n�ration de bille
	bool genBille_;
	/// Affichage de la vitesse des billes apr�s collision
	bool vitBilles_;
	/// Affichage de l'activation ou non de l'�clairage 
	bool eclairage_;
	/// Affichage de la limite d'attraction des portails
	bool limitesPortails_;

};


#endif // __CONFIGURATION_CONFIG_H__


///////////////////////////////////////////////////////////////////////////////
/// @}
///////////////////////////////////////////////////////////////////////////////
