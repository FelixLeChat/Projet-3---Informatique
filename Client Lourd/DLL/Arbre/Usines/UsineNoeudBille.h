///////////////////////////////////////////////////////////////////////////
/// @file UsineNoeudBille.h
/// @author Konstantin Fedorov et Jeremie Gagne
/// @date 2015-02-24
/// @version 1.0
///
/// @addtogroup inf2990 INF2990
/// @{
///////////////////////////////////////////////////////////////////////////
#ifndef __ARBRE_USINES_UsineNoeudBille_H__
#define __ARBRE_USINES_UsineNoeudBille_H__


#include "UsineNoeud.h"
#include "Arbre/Noeuds/NoeudBille.h"


///////////////////////////////////////////////////////////////////////////
/// @class UsineNoeudBille
/// @brief Classe qui repr�sente une usine capable de cr�er des noeuds de
///        type NoeudBille.
///
/// @author Konstantin Fedorov et Jeremie Gagne
/// @date 2015-02-24
///////////////////////////////////////////////////////////////////////////
class UsineNoeudBille : public UsineNoeud
{
public:
	/// Constructeur par param�tres.
	inline UsineNoeudBille(const std::string& nom);

	/// Fonction � surcharger pour la cr�ation d'un noeud.
	inline virtual NoeudAbstrait* creerNoeud() const;


};


////////////////////////////////////////////////////////////////////////
///
/// @fn UsineNoeudBille::UsineNoeudBille(const std::string& nom)
///
/// Ce constructeur ne fait qu'appeler la version de la classe et base
/// et donner des valeurs par d�faut aux variables membres..
///
/// @param[in] nom   : Le nom de l'usine qui correspond au type de noeuds cr��s.
///
/// @return Aucune (constructeur).
///
////////////////////////////////////////////////////////////////////////
inline UsineNoeudBille::UsineNoeudBille(const std::string& nom)
: UsineNoeud(nom, std::string{ "media/Bille.obj" })//
{
}


////////////////////////////////////////////////////////////////////////
///
/// @fn NoeudAbstrait* UsineNoeudBille::creerNoeud() const
///
/// Cette fonction retourne un noeud nouvellement cr�� du type produit
/// par cette usine, soit une araign�e.
///
/// @return Le noeud nouvellement cr��.
///
////////////////////////////////////////////////////////////////////////
NoeudAbstrait* UsineNoeudBille::creerNoeud() const
{
	auto noeud = new NoeudBille{ obtenirNom() };
	noeud->assignerObjetRendu(&modele_, &liste_);
	return noeud;
}


#endif // __ARBRE_USINES_UsineNoeudBille_H__


///////////////////////////////////////////////////////////////////////////////
/// @}
///////////////////////////////////////////////////////////////////////////////
