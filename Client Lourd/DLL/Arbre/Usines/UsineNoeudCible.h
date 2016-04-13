///////////////////////////////////////////////////////////////////////////
/// @file UsineNoeudCible.h
/// @author Julien Gascon-Samson
/// @date 2011-05-19
/// @version 1.0
///
/// @addtogroup inf2990 INF2990
/// @{
///////////////////////////////////////////////////////////////////////////
#ifndef __ARBRE_USINES_UsineNoeudCible_H__
#define __ARBRE_USINES_UsineNoeudCible_H__


#include "UsineNoeud.h"
#include "Arbre/Noeuds/NoeudCible.h"


///////////////////////////////////////////////////////////////////////////
/// @class UsineNoeudCible
/// @brief Classe qui repr�sente une usine capable de cr�er des noeuds de
///        type NoeudCible.
///
/// @author Julien Gascon-Samson
/// @date 2011-05-19
///////////////////////////////////////////////////////////////////////////
class UsineNoeudCible : public UsineNoeud
{
public:
	/// Constructeur par param�tres.
	inline UsineNoeudCible(const std::string& nom);

	/// Fonction � surcharger pour la cr�ation d'un noeud.
	inline virtual NoeudAbstrait* creerNoeud() const;
};


////////////////////////////////////////////////////////////////////////
///
/// @fn UsineNoeudCible::UsineNoeudCible(const std::string& nom)
///
/// Ce constructeur ne fait qu'appeler la version de la classe et base
/// et donner des valeurs par d�faut aux variables membres..
///
/// @param[in] nom   : Le nom de l'usine qui correspond au type de noeuds cr��s.
///
/// @return Aucune (constructeur).
///
////////////////////////////////////////////////////////////////////////
inline UsineNoeudCible::UsineNoeudCible(const std::string& nom)
: UsineNoeud(nom, std::string{ "media/Cible.obj" })//
{
}


////////////////////////////////////////////////////////////////////////
///
/// @fn NoeudAbstrait* UsineNoeudCible::creerNoeud() const
///
/// Cette fonction retourne un noeud nouvellement cr�� du type produit
/// par cette usine, soit une araign�e.
///
/// @return Le noeud nouvellement cr��.
///
////////////////////////////////////////////////////////////////////////
NoeudAbstrait* UsineNoeudCible::creerNoeud() const
{
	auto noeud = new NoeudCible{ obtenirNom() };
	noeud->assignerObjetRendu(&modele_, &liste_);
	return noeud;
}


#endif // __ARBRE_USINES_UsineNoeudCible_H__


///////////////////////////////////////////////////////////////////////////////
/// @}
///////////////////////////////////////////////////////////////////////////////
