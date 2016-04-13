///////////////////////////////////////////////////////////////////////////
/// @file UsineNoeudRessort.h
/// @author Julien Gascon-Samson
/// @date 2011-05-19
/// @version 1.0
///
/// @addtogroup inf2990 INF2990
/// @{
///////////////////////////////////////////////////////////////////////////
#ifndef __ARBRE_USINES_UsineNoeudRessort_H__
#define __ARBRE_USINES_UsineNoeudRessort_H__


#include "UsineNoeud.h"
#include "Arbre/Noeuds/NoeudRessort.h"


///////////////////////////////////////////////////////////////////////////
/// @class UsineNoeudRessort
/// @brief Classe qui repr�sente une usine capable de cr�er des noeuds de
///        type NoeudRessort.
///
/// @author Julien Gascon-Samson
/// @date 2011-05-19
///////////////////////////////////////////////////////////////////////////
class UsineNoeudRessort : public UsineNoeud
{
public:
	/// Constructeur par param�tres.
	inline UsineNoeudRessort(const std::string& nom);

	/// Fonction � surcharger pour la cr�ation d'un noeud.
	inline virtual NoeudAbstrait* creerNoeud() const;


};


////////////////////////////////////////////////////////////////////////
///
/// @fn UsineNoeudRessort::UsineNoeudRessort(const std::string& nom)
///
/// Ce constructeur ne fait qu'appeler la version de la classe et base
/// et donner des valeurs par d�faut aux variables membres..
///
/// @param[in] nom   : Le nom de l'usine qui correspond au type de noeuds cr��s.
///
/// @return Aucune (constructeur).
///
////////////////////////////////////////////////////////////////////////
inline UsineNoeudRessort::UsineNoeudRessort(const std::string& nom)
: UsineNoeud(nom, std::string{ "media/Ressort.obj" })
{
}


////////////////////////////////////////////////////////////////////////
///
/// @fn NoeudAbstrait* UsineNoeudRessort::creerNoeud() const
///
/// Cette fonction retourne un noeud nouvellement cr�� du type produit
/// par cette usine, soit une araign�e.
///
/// @return Le noeud nouvellement cr��.
///
////////////////////////////////////////////////////////////////////////
NoeudAbstrait* UsineNoeudRessort::creerNoeud() const
{
	auto noeud = new NoeudRessort{ obtenirNom() };
	noeud->assignerObjetRendu(&modele_, &liste_);
	return noeud;
}


#endif // __ARBRE_USINES_UsineNoeudRessort_H__


///////////////////////////////////////////////////////////////////////////////
/// @}
///////////////////////////////////////////////////////////////////////////////
