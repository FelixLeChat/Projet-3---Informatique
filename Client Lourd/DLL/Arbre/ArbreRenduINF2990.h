	///////////////////////////////////////////////////////////////////////////
/// @file ArbreRenduINF2990.h
/// @author Martin Bisson
/// @date 2007-03-23
/// @version 1.0
///
/// @addtogroup inf2990 INF2990
/// @{
///////////////////////////////////////////////////////////////////////////
#ifndef __ARBRE_ARBRERENDUINF2990_H__
#define __ARBRE_ARBRERENDUINF2990_H__


#include "ArbreRendu.h"


///////////////////////////////////////////////////////////////////////////
/// @class ArbreRenduINF2990
/// @brief Classe qui repr�sente l'arbre de rendu sp�cifique au projet de
///        INF2990.
///
///        Cette classe s'occupe de configurer les usines des noeuds qui
///        seront utilis�s par le projet.
///
/// @author Martin Bisson
/// @date 2007-03-23
///////////////////////////////////////////////////////////////////////////
class ArbreRenduINF2990 : public ArbreRendu
{
public:
   /// Constructeur par d�faut.
   ArbreRenduINF2990();
   /// Destructeur.
   virtual ~ArbreRenduINF2990();

   /// Initialise l'arbre de rendu � son �tat initial.
   void initialiser();


	/// La cha�ne repr�sentant le type de la zone de jeu.
	static const std::string NOM_ZONEDEJEU;
	/// La cha�ne repr�sentant le type du trou.
	static const std::string NOM_TROU;
	/// La cha�ne repr�sentant le type du ressort.
	static const std::string NOM_RESSORT;
	/// La cha�ne repr�sentant le type du g�n�rateur de bille.
	static const std::string NOM_GENERATEURBILLE;
	/// La cha�ne repr�sentant le type du butoir circulaire.
	static const std::string NOM_BUTOIRCIRCULAIRE;
	/// La cha�ne repr�sentant le type du butoir triangulaire gauche.
	static const std::string NOM_BUTOIRTRIANGULAIREGAUCHE;	
	/// La cha�ne repr�sentant le type du butoir triangulaire droit.
	static const std::string NOM_BUTOIRTRIANGULAIREDROIT;	
	/// La cha�ne repr�sentant le type de la cible.
	static const std::string NOM_CIBLE;
	/// La cha�ne repr�sentant le type de la palette gauche du joueur 1.
	static const std::string NOM_PALETTEGAUCHEJ1;	
	/// La cha�ne repr�sentant le type de la palette droite du joueur 1.
	static const std::string NOM_PALETTEDROITJ1;
	/// La cha�ne repr�sentant le type de la palette gauche du joueur 2.
	static const std::string NOM_PALETTEGAUCHEJ2;
	/// La cha�ne repr�sentant le type de la palette droite du joueur 2.
	static const std::string NOM_PALETTEDROITJ2;
	/// La cha�ne repr�sentant le type du portail.
	static const std::string NOM_PORTAIL;
	/// La cha�ne repr�sentant le type du mur.
	static const std::string NOM_MUR;
	/// La cha�ne repr�sentant le type d'une bille.
	static const std::string NOM_BILLE;

	static const std::string NOM_CHAMPFORCE;

	static const std::string NOM_PLATEAUDARGENT;

	static bool estNomDePalette(const std::string NomObjet)
	{
		return NomObjet == NOM_PALETTEDROITJ1 ||
			NomObjet == NOM_PALETTEDROITJ2 ||
			NomObjet == NOM_PALETTEGAUCHEJ1 ||
			NomObjet == NOM_PALETTEGAUCHEJ2;
	}
};


#endif // __ARBRE_ARBRERENDUINF2990_H__


///////////////////////////////////////////////////////////////////////////////
/// @}
///////////////////////////////////////////////////////////////////////////////
