#ifndef _ARBRE_VISITEUR_VISITEURREINIT_H_
#define _ARBRE_VISITEUR_VISITEURREINIT_H_
#include "VisiteurAbstrait.h"

class VisiteurReinit : public VisiteurAbstrait
{
public:
	/// Constructeur
	VisiteurReinit();
	/// Destructeur
	~VisiteurReinit(){};

	/// Traitement des noeuds

	/// M�thode virtuelle de traitement d'un butoir circulaire
	virtual void traiterNoeudButoirCirculaire(NoeudButoirCirculaire*);
	/// M�thode virtuelle de traitement d'une cible
	virtual void traiterNoeudCible(NoeudCible*);
	/// M�thode virtuelle de traitement de la palette droite du joueur 1
	virtual void traiterNoeudPaletteDroitJ1(NoeudPaletteDroitJ1*);
	/// M�thode virtuelle de traitement de la palette droite du joueur 2
	virtual void traiterNoeudPaletteDroitJ2(NoeudPaletteDroitJ2*);
	/// M�thode virtuelle de traitement de la palette gauche du joueur 1
	virtual void traiterNoeudPaletteGaucheJ1(NoeudPaletteGaucheJ1*);
	/// M�thode virtuelle de traitement de la palette gauche du joueur 2
	virtual void traiterNoeudPaletteGaucheJ2(NoeudPaletteGaucheJ2*);
	/// M�thode virtuelle de traitement du ressort
	virtual void traiterNoeudRessort(NoeudRessort*);
	/// M�thode virtuelle de traitement de portails
	virtual void traiterNoeudPortail(NoeudPortail*);

	virtual void traiterNoeudPlateauDArgent(NoeudPlateauDArgent*);
};
#endif //_ARBRE_VISITEUR_VISITEURREINIT_H_