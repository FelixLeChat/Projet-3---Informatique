///////////////////////////////////////////////////////////////////////////
/// @file UsineNoeudTrone.h
/// @author Jeremie Gagne
/// @date 2016-03-10
/// @version 1.0
///
/// @addtogroup inf2990 INF2990
/// @{
///////////////////////////////////////////////////////////////////////////
#ifndef __ARBRE_USINES_NOEUDPOWERUPGROSSEPALETTE_H__
#define __ARBRE_USINES_NOEUDPOWERUPGROSSEPALETTE_H__


#include "UsineNoeud.h"
#include "../Noeuds/PowerUp/NoeudPowerUpGrossissementPalette.h"


///////////////////////////////////////////////////////////////////////////
/// @class UsineNoeudTrone
/// @brief Classe qui repr�sente une usine capable de cr�er des noeuds de
///        type NoeudTrone.
///
/// @author Jeremie Gagne
/// @date 2016-03-10
///////////////////////////////////////////////////////////////////////////
class UsineNoeudPowerUpGrossissementPalette : public UsineNoeud
{
public:
	/// Constructeur par param�tres.
	inline UsineNoeudPowerUpGrossissementPalette(const std::string& nom);

	/// Fonction � surcharger pour la cr�ation d'un noeud.
	inline virtual NoeudAbstrait* creerNoeud() const;


};


////////////////////////////////////////////////////////////////////////
///
/// @fn UsineNoeudTrone::UsineNoeudTrone(const std::string& nom)
///
/// Ce constructeur ne fait qu'appeler la version de la classe et base
/// et donner des valeurs par d�faut aux variables membres..
///
/// @param[in] nom   : Le nom de l'usine qui correspond au type de noeuds cr��s.
///
/// @return Aucune (constructeur).
///
////////////////////////////////////////////////////////////////////////
inline UsineNoeudPowerUpGrossissementPalette::UsineNoeudPowerUpGrossissementPalette(const std::string& nom)
	: UsineNoeud(nom, std::string{ "media/PowerUp_GrossePalette.obj" })//
{
}


////////////////////////////////////////////////////////////////////////
///
/// @fn NoeudAbstrait* UsineNoeudTrone::creerNoeud() const
///
/// Cette fonction retourne un noeud nouvellement cr�� du type produit
/// par cette usine, soit une araign�e.
///
/// @return Le noeud nouvellement cr��.
///
////////////////////////////////////////////////////////////////////////
NoeudAbstrait* UsineNoeudPowerUpGrossissementPalette::creerNoeud() const
{
	auto noeud = new NoeudPowerUpGrossissementPalette{ obtenirNom() };
	noeud->assignerObjetRendu(&modele_, &liste_);
	return noeud;
}


#endif // __ARBRE_USINES_NOEUDPOWERUPGROSSEPALETTE_H__


///////////////////////////////////////////////////////////////////////////////
/// @}
///////////////////////////////////////////////////////////////////////////////

