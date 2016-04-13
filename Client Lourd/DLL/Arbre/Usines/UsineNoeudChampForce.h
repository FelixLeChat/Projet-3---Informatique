///////////////////////////////////////////////////////////////////////////
/// @file UsineNoeudChampForce.h
/// @author Julien Gascon-Samson
/// @date 2011-05-19
/// @version 1.0
///
/// @addtogroup inf2990 INF2990
/// @{
///////////////////////////////////////////////////////////////////////////
#ifndef __ARBRE_USINES_NOEUDCHAMPFORCE_H__
#define __ARBRE_USINES_NOEUDCHAMPFORCE_H__


#include "UsineNoeud.h"
#include "Arbre/Noeuds/NoeudChampForce.h"
#include "UsineNoeudFleche.h"


///////////////////////////////////////////////////////////////////////////
/// @class UsineNoeudChampForce
/// @brief Classe qui repr�sente une usine capable de cr�er des noeuds de
///        type NoeudChampForce.
///
/// @author Julien Gascon-Samson
/// @date 2011-05-19
///////////////////////////////////////////////////////////////////////////
class UsineNoeudChampForce : public UsineNoeud
{
public:
	/// Constructeur par param�tres.
	inline UsineNoeudChampForce(const std::string& nom);

	inline virtual ~UsineNoeudChampForce()
	{
		liste_.storageRelacher();
		delete usineFleche_;
	}

	/// Fonction � surcharger pour la cr�ation d'un noeud.
	inline virtual NoeudAbstrait* creerNoeud() const;

private:
	UsineNoeudFleche* usineFleche_;
};


////////////////////////////////////////////////////////////////////////
///
/// @fn UsineNoeudChampForce::UsineNoeudChampForce(const std::string& nom)
///
/// Ce constructeur ne fait qu'appeler la version de la classe et base
/// et donner des valeurs par d�faut aux variables membres..
///
/// @param[in] nom   : Le nom de l'usine qui correspond au type de noeuds cr��s.
///
/// @return Aucune (constructeur).
///
////////////////////////////////////////////////////////////////////////
inline UsineNoeudChampForce::UsineNoeudChampForce(const std::string& nom)
	: UsineNoeud(nom, std::string{ "media/ChampForce.obj" })//
{
	usineFleche_ = new UsineNoeudFleche("FLECHE");
}


////////////////////////////////////////////////////////////////////////
///
/// @fn NoeudAbstrait* UsineNoeudChampForce::creerNoeud() const
///
/// Cette fonction retourne un noeud nouvellement cr�� du type produit
/// par cette usine, soit une araign�e.
///
/// @return Le noeud nouvellement cr��.
///
////////////////////////////////////////////////////////////////////////
NoeudAbstrait* UsineNoeudChampForce::creerNoeud() const
{
	auto noeud = new NoeudChampForce{ obtenirNom() };
	noeud->assignerObjetRendu(&modele_, &liste_);
	noeud->ajouter(usineFleche_->creerNoeud());
	return noeud;
}


#endif // __ARBRE_USINES_NOEUDCHAMPFORCE_H__


///////////////////////////////////////////////////////////////////////////////
/// @}
///////////////////////////////////////////////////////////////////////////////
