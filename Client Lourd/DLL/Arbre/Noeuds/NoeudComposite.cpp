////////////////////////////////////////////////
/// @file   NoeudComposite.cpp
/// @author DGI-2990
/// @date   2007-01-25
///
/// @addtogroup inf2990 INF2990
/// @{
////////////////////////////////////////////////


#include <iostream>
#include "NoeudComposite.h"
#include "NoeudPortail.h"

#include <cassert>


////////////////////////////////////////////////////////////////////////
///
/// @fn NoeudComposite::NoeudComposite(const std::string& type)
///
/// Ne fait qu'appeler la version de la classe de base.
///
/// @param[in] type               : Le type du noeud.
///
/// @return Aucune (constructeur).
///
////////////////////////////////////////////////////////////////////////
NoeudComposite::NoeudComposite(
	const std::string& type //= std::string{ "" }
	) :
	NoeudAbstrait{ type }
{
}


////////////////////////////////////////////////////////////////////////
///
/// @fn NoeudComposite::~NoeudComposite()
///
/// Destructeur qui d�truit tous les enfants du noeud.
///
/// @return Aucune (destructeur).
///
////////////////////////////////////////////////////////////////////////
NoeudComposite::~NoeudComposite()
{
	vider();
}


////////////////////////////////////////////////////////////////////////
///
/// @fn unsigned int NoeudComposite::calculerProfondeur() const
///
/// Cette fonction calcule la profondeur de l'arbre incluant le noeud
/// courant ainsi que tous ses enfants.
///
/// Cette fonction retourne toujours 1 de plus que la profondeur de son
/// enfants le plus profond.
///
/// @return La profondeur de l'arbre sous ce noeud.
///
////////////////////////////////////////////////////////////////////////
unsigned int NoeudComposite::calculerProfondeur() const
{
	unsigned int profondeurEnfantMax{ 0 };

	for (NoeudAbstrait const* enfant : enfants_)
	{
		const unsigned int profondeurEnfant{ enfant->calculerProfondeur() };
		if (profondeurEnfantMax < profondeurEnfant)
			profondeurEnfantMax = profondeurEnfant;
	}

	return profondeurEnfantMax + 1;
}


////////////////////////////////////////////////////////////////////////
///
/// @fn void NoeudComposite::vider()
///
/// Cette fonction vide le noeud de tous ses enfants.  Elle effectue une
/// it�ration prudente sur les enfants afin d'�tre assez robuste pour
/// supporter la possibilit� qu'un enfant en efface un autre dans son
/// destructeur, par exemple si deux objets ne peuvent pas exister l'un
/// sans l'autre.  Elle peut toutefois entrer en boucle infinie si un
/// enfant ajoute un nouveau noeud lorsqu'il se fait effacer.
///
/// @return Aucune.
///
////////////////////////////////////////////////////////////////////////
void NoeudComposite::vider()
{
	// L'it�ration doit �tre faite ainsi pour �viter les probl�mes lorsque
	// le desctructeur d'un noeud modifie l'arbre, par exemple en retirant
	// d'autres noeuds.  Il pourrait y avoir une boucle infinie si la
	// desctruction d'un enfant entra�nerait l'ajout d'un autre.
	while (!enfants_.empty()) {
		NoeudAbstrait* enfantAEffacer{ enfants_.front() };
		enfants_.erase(enfants_.begin());
		delete enfantAEffacer;
	}
}

////////////////////////////////////////////////////////////////////////
///
/// @fn void NoeudComposite::accepterVisiteur(VisiteurAbstrait* visiteur)
///
/// Cette fonction accepte un visiteur.
///
/// @param[in] visiteur : le visiteur � accepter.
///
/// @return Aucune
///
////////////////////////////////////////////////////////////////////////
void NoeudComposite::accepterVisiteur(VisiteurAbstrait* visiteur)
{
	for (int i = 0; i < enfants_.size(); i++)
	{
		enfants_[i]->accepterVisiteur(visiteur);
	}
}

////////////////////////////////////////////////////////////////////////
///
/// @fn void NoeudComposite::effacer( const NoeudAbstrait* noeud )
///
/// Efface un noeud qui est un enfant ou qui est contenu dans un des
/// enfants.
///
/// @param[in] noeud : Le noeud � effacer.
///
/// @return Aucune
///
////////////////////////////////////////////////////////////////////////
void NoeudComposite::effacer(const NoeudAbstrait* noeud)
{
	for (conteneur_enfants::iterator it{ enfants_.begin() };
	it != enfants_.end();
		it++) {
		if (*it == noeud) {
			// On a trouv� le noeud � effacer
			NoeudAbstrait* noeudAEffacer{ (*it) };
			enfants_.erase(it);
			delete noeudAEffacer;
			noeudAEffacer = nullptr;
			return;
		}
		else {
			// On cherche dans les enfants.
			(*it)->effacer(noeud);
		}
	}
}


////////////////////////////////////////////////////////////////////////
///
/// @fn const NoeudAbstrait* NoeudComposite::chercher( const std::string& typeNoeud ) const
///
/// Recherche un noeud d'un type donn� parmi le noeud courant et ses
/// enfants.  Version constante de la fonction.
///
/// @param[in] typeNoeud : Le type du noeud cherch�.
///
/// @return Noeud recherch� ou 0 si le noeud n'est pas trouv�.
///
////////////////////////////////////////////////////////////////////////
const NoeudAbstrait* NoeudComposite::chercher(
	const std::string& typeNoeud
	) const
{
	if (typeNoeud == type_) {
		return this;
	}
	else {
		for (NoeudAbstrait const* enfant : enfants_)
		{
			NoeudAbstrait const* noeud{ enfant->chercher(typeNoeud) };
			if (noeud != nullptr) {
				return noeud;
			}
		}
	}

	return nullptr;
}


////////////////////////////////////////////////////////////////////////
///
/// @fn NoeudAbstrait* NoeudComposite::chercher( const std::string& typeNoeud )
///
/// Recherche un noeud d'un type donn� parmi le noeud courant et ses
/// enfants.
///
/// @param[in] typeNoeud : Le type du noeud cherch�.
///
/// @return Noeud recherch� ou 0 si le noeud n'est pas trouv�.
///
////////////////////////////////////////////////////////////////////////
NoeudAbstrait* NoeudComposite::chercher(const std::string& typeNoeud)
{
	if (typeNoeud == type_) {
		return this;
	}
	else {
		for (NoeudAbstrait * enfant : enfants_)
		{
			NoeudAbstrait * noeud{ enfant->chercher(typeNoeud) };
			if (noeud != nullptr) {
				return noeud;
			}
		}
	}

	return nullptr;
}


////////////////////////////////////////////////////////////////////////
///
/// @fn const NoeudAbstrait* NoeudComposite::chercher( unsigned int indice ) const
///
/// Retourne le i-�me enfant, o� i est l'indice pass� � la fonction.
/// Version constante de la fonction.
///
/// @param[in] indice : L'indice de l'enfant cherch�.
///
/// @return Noeud recherch� ou 0 si le noeud n'est pas trouv�.
///
////////////////////////////////////////////////////////////////////////
const NoeudAbstrait* NoeudComposite::chercher(unsigned int indice) const
{
	if ((indice >= 0) && (indice < enfants_.size())) {
		return enfants_[indice];
	}
	else {
		return nullptr;
	}
}


////////////////////////////////////////////////////////////////////////
///
/// @fn NoeudAbstrait* NoeudComposite::chercher( unsigned int indice )
///
/// Retourne le i-�me enfant, o� i est l'indice pass� � la fonction.
///
/// @param[in] indice : L'indice de l'enfant cherch�.
///
/// @return Noeud recherch� ou 0 si le noeud n'est pas trouv�.
///
////////////////////////////////////////////////////////////////////////
NoeudAbstrait* NoeudComposite::chercher(unsigned int indice)
{
	if ((indice >= 0) && (indice < enfants_.size())) {
		return enfants_[indice];
	}
	else {
		return nullptr;
	}
}


////////////////////////////////////////////////////////////////////////
///
/// @fn bool NoeudComposite::ajouter( NoeudAbstrait* enfant )
///
/// Ajoute un noeud enfant au noeud courant.
///
/// @param[in] enfant: Noeud � ajouter.
///
/// @return Vrai si l'ajout a r�ussi, donc en tout temps pour cette classe.
///
////////////////////////////////////////////////////////////////////////
bool NoeudComposite::ajouter(NoeudAbstrait* enfant)
{
	enfant->assignerParent(this);
	enfants_.push_back(enfant);

	return true;
}


////////////////////////////////////////////////////////////////////////
///
/// @fn unsigned int NoeudComposite::obtenirNombreEnfants() const
///
/// Retourne le nombre d'enfants directement sous ce noeud.  Elle ne
/// donne pas le nombre total de descendants, mais bien le nombre de
/// ceux qui sont directement sous ce noeud.
///
/// @return Le nombre d'enfants directement sous ce noeud.
///
////////////////////////////////////////////////////////////////////////
unsigned int NoeudComposite::obtenirNombreEnfants() const
{
	// La taille ne doit jamais �tre n�gative, sinon le cast plus bas
	// donnera un r�sultat erron�.
	assert(enfants_.size() >= 0);

	return static_cast<unsigned int> (enfants_.size());
}


////////////////////////////////////////////////////////////////////////
///
/// @fn void NoeudComposite::effacerSelection()
///
/// Efface tous les noeuds s�lectionn�s situ�s sous ce noeud.  Elle
/// s'appelle donc r�cursivement sur tous les enfants, avant de retirer
/// les enfants s�lectionn�s.
///
/// @return Aucune
///
////////////////////////////////////////////////////////////////////////
void NoeudComposite::effacerSelection()
{
	// On efface tous les noeuds s�lectionn�s descendants des enfants.
	for (NoeudAbstrait * enfant : enfants_) {
		enfant->effacerSelection();
	}

	// On efface les enfants s�lectionn�s.  On effectue ce traitement
	// dans une seconde boucle pour �viter de faire des assomptions
	// sur la robustesse des it�rateurs lorsque le conteneur est
	// modifi� pendant une it�ration.
	for (conteneur_enfants::iterator it{ enfants_.begin() };
	it != enfants_.end();
		) {
		if ((*it)->estSelectionne()) {
			NoeudAbstrait* enfant{ (*it) };
			enfants_.erase(it);
			if (enfant->obtenirType() == "portail")
			{
				NoeudPortail* frere = ((NoeudPortail*)enfant)->obtenirFrere();
				effacer(frere);
			}

			delete enfant;

			// On ram�ne l'it�ration au d�but de la boucle, car le destructeur
			// de l'enfant pourrait �ventuellement avoir retir� d'autres
			// enfants de l'arbre, ce qui briserait l'it�ration.  Pourrait
			// �ventuellement �tre �vit� avec des it�rateurs plus robustes.
			// Peut-�tre une liste cha�n�e?
			it = enfants_.begin();
		}
		else {
			++it;
		}
	}
}

////////////////////////////////////////////////////////////////////////
///
/// @fn void NoeudComposite::effacerEtampes()
///
/// Efface tous les noeuds �tampes situ�s sous ce noeud.  Elle
/// s'appelle donc r�cursivement sur tous les enfants, avant de retirer
/// les enfants �tampes.
///
/// @return Aucune
///
////////////////////////////////////////////////////////////////////////
void NoeudComposite::effacerEtampes()
{
	// On efface tous les noeuds �tampes descendants des enfants.
	for (NoeudAbstrait * enfant : enfants_) {
		enfant->effacerEtampes();
	}

	// On efface les enfants �tampes.  On effectue ce traitement
	// dans une seconde boucle pour �viter de faire des assomptions
	// sur la robustesse des it�rateurs lorsque le conteneur est
	// modifi� pendant une it�ration.
	for (conteneur_enfants::iterator it{ enfants_.begin() };
	it != enfants_.end();
		) {
		if ((*it)->estEtampe()) {
			NoeudAbstrait* enfant{ (*it) };
			enfants_.erase(it);
			if (enfant->obtenirType() == "portail")
			{
				NoeudPortail* frere = ((NoeudPortail*)enfant)->obtenirFrere();
				effacer(frere);
			}

			delete enfant;

			// On ram�ne l'it�ration au d�but de la boucle, car le destructeur
			// de l'enfant pourrait �ventuellement avoir retir� d'autres
			// enfants de l'arbre, ce qui briserait l'it�ration.  Pourrait
			// �ventuellement �tre �vit� avec des it�rateurs plus robustes.
			// Peut-�tre une liste cha�n�e?
			it = enfants_.begin();
		}
		else {
			++it;
		}
	}
}


////////////////////////////////////////////////////////////////////////
///
/// @fn void NoeudComposite::selectionnerTout()
///
/// S�lectionne tous les noeuds qui sont s�lectionn�s parmis les
/// les descendants de ce noeud, lui-m�me �tant inclus.
///
/// @return Aucune
///
////////////////////////////////////////////////////////////////////////
void NoeudComposite::selectionnerTout()
{
	NoeudAbstrait::selectionnerTout();

	for (NoeudAbstrait * enfant : enfants_) {
		enfant->selectionnerTout();
	}
}


////////////////////////////////////////////////////////////////////////
///
/// @fn void NoeudComposite::deselectionnerTout()
///
/// D�s�lectionne tous les noeuds qui sont s�lectionn�s parmis les
/// les descendants de ce noeud, lui-m�me �tant inclus.
///
/// @return Aucune
///
////////////////////////////////////////////////////////////////////////
void NoeudComposite::deselectionnerTout()
{
	selectionne_ = false;

	for (NoeudAbstrait * enfant : enfants_) {
		enfant->deselectionnerTout();
	}
}

////////////////////////////////////////////////////////////////////////
///
/// @fn void NoeudComposite::deEtamperTout()
///
/// Retire l'�tampe de tous les noeuds qui sont �tampes parmi les
/// les descendants de ce noeud, lui-m�me �tant inclus.
///
/// @return Aucune
///
////////////////////////////////////////////////////////////////////////
void NoeudComposite::deEtamperTout()
{
	etampe_ = false;

	for (NoeudAbstrait * enfant : enfants_) {
		enfant->deEtamperTout();
	}
}

////////////////////////////////////////////////////////////////////////
///
/// @fn bool NoeudComposite::selectionExiste() const
///
/// V�rifie si le noeud ou un de ses descendants est s�lectionn� en
/// s'appelant de mani�re r�cursive sur les enfants du noeud.
///
/// @return Vrai s'il existe un noeud s�lectionn�, faux autrement.
///
////////////////////////////////////////////////////////////////////////
bool NoeudComposite::selectionExiste() const
{
	if (selectionne_)
	{
		return true;
	}

	for (NoeudAbstrait const* enfant : enfants_)
	{
		if (enfant->selectionExiste())
			return true;
	}

	return false;
}


////////////////////////////////////////////////////////////////////////
///
/// @fn void NoeudComposite::changerModePolygones( bool estForce )
///
/// Change le mode d'affichage des polygones pour ce noeud et ses
/// enfants.
///
/// @param[in] estForce : Si vrai, le mode est chang� pour ce noeud et
///                       tous ses descendants.  Sinon, seuls les noeuds
///                       s�lectionn�s verront leur mode changer.
///
/// @return Aucune
///
////////////////////////////////////////////////////////////////////////
void NoeudComposite::changerModePolygones(bool estForce)
{
	NoeudAbstrait::changerModePolygones(estForce);
	const bool forceEnfant = ((estForce) || (estSelectionne()));

	// Applique le changement r�cursivement aux enfants.
	for (NoeudAbstrait * enfant : enfants_) {
		enfant->changerModePolygones(forceEnfant);
	}
}


////////////////////////////////////////////////////////////////////////
///
/// @fn void NoeudComposite::assignerModePolygones( GLenum modePolygones )
///
/// Cette fonction assigne le mode de rendu des polygones du noeud et
/// de ses enfants.
///
/// @return Aucune.
///
////////////////////////////////////////////////////////////////////////
void NoeudComposite::assignerModePolygones(GLenum modePolygones)
{
	// Appel � la version de la classe de base.
	NoeudAbstrait::assignerModePolygones(modePolygones);

	// Applique le changement r�cursivement aux enfants.
	for (NoeudAbstrait * enfant : enfants_) {
		enfant->assignerModePolygones(modePolygones);
	}
}


////////////////////////////////////////////////////////////////////////
///
/// @fn void NoeudComposite::afficherConcret() const
///
/// Cette fonction effectue le v�ritable rendu de l'objet.  Elle est
/// appel�e par la template method (dans le sens du patron de conception,
/// et non des template C++) afficher() de la classe de base.
///
/// Pour cette classe, elle affiche chacun des enfants du noeud.
///
/// @return Aucune.
///
////////////////////////////////////////////////////////////////////////
void NoeudComposite::afficherConcret() const
{

	NoeudAbstrait::afficherConcret();

	for (int i = 0; i < enfants_.size(); ++i)
	{
		glPushName(i);
		enfants_[i]->afficher();
		glPopName();
	}

}


////////////////////////////////////////////////////////////////////////
///
/// @fn void NoeudComposite::animer( float dt )
///
/// Anime tous les enfants de ce noeud.
///
/// @param[in] dt : Intervalle de temps sur lequel faire l'animation.
///
/// @return Aucune
///
////////////////////////////////////////////////////////////////////////
void NoeudComposite::animer(float dt)
{
	for (NoeudAbstrait * enfant : enfants_) {
		enfant->animer(dt);
	}
}


////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////