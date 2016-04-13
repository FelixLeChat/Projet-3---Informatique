///////////////////////////////////////////////////////////////////////////////
/// @file ArbreRendu.h
/// @author Martin Bisson
/// @date 2007-01-28
/// @version 1.0
///
/// @addtogroup inf2990 INF2990
/// @{
///////////////////////////////////////////////////////////////////////////////
#ifndef __ARBRE_ARBRERENDU_H__
#define __ARBRE_ARBRERENDU_H__


#include "Arbre/Noeuds/NoeudComposite.h"
#include <map>


class NoeudAbstrait;
class UsineNoeud;


///////////////////////////////////////////////////////////////////////////
/// @class ArbreRendu
/// @brief Classe d'arbre de rendu qui contient la racine de l'arbre de
///        rendu avec les usines qui permettent d'ajouter des noeuds �
///        cet arbre.
///
///        La profondeur de cet arbre est limit�e par la taille de la pile
///        des matrices et la taille de la pile des noms pour la s�lection
///        OpenGL, �tant donn� que chaque niveau de l'arbre effectue un
///        "push" sur chacune de ces piles lors du rendu.  L'arbre ne
///        v�rifie pas que la profondeur reste sous la limite, mais il
///        offre des fonctions permettant de le v�rifier ais�ment.
///
/// @author Martin Bisson
/// @date 2007-01-28
///////////////////////////////////////////////////////////////////////////
class ArbreRendu : public NoeudComposite
{
public:
   /// Constructeur par d�faut.
   ArbreRendu();
   /// Destructeur.
   virtual ~ArbreRendu();

   /// Ajoute une usine associ�e � un type de noeud.
   inline void ajouterUsine(
      const std::string& type, const UsineNoeud* usine
      );

   /// Cr�e un nouveau noeud.
   NoeudAbstrait* creerNoeud(
      const std::string& typeNouveauNoeud
      ) const;

   /// Cr�e et ajoute un nouveau noeud � l'arbre.
   NoeudAbstrait* ajouterNouveauNoeud(
      const std::string& nomParent,
      const std::string& typeNouveauNoeud
      );

   //Cherche les noeuds s�lectionn�s
   int chercherSelection(int x, int y, bool ajout, bool clic);

   //V�rifier que la s�lection est dans els bornes de la table de jeu
   bool estDansBornes(bool selected = true);

   //V�rifie que le noeud est dans les bornes de la table de jeu
   bool estDansBornes(NoeudAbstrait * noeud);

   //V�rifie que les �l�ments de base du jeu sont s�lectionn�s
   bool tousEssentielSelectionne();

   /// Calcule la profondeur maximale possible pour l'arbre de rendu.
   static unsigned int calculerProfondeurMaximale();

   /// Calcule le centre de selection 
   void calculerCentreSelection();

   //Obtention du centre de la zone de s�lection
   glm::dvec3& obtenirCentreSelection();

   //Obtention du d�passement de la s�lection par rapport aux bornes de la table de jeu
   glm::dvec2 obtenirDepassement();





private:
   /// D�finition du type pour l'association du nom d'un type vers l'usine
   /// correspondante.
	using RegistreUsines = std::map< std::string, const UsineNoeud* >;
   /// Association du nom d'un type vers l'usine correspondante.
   RegistreUsines usines_;
   //Le nombre d'objets s�lectionn�s
   int nbObjSel;
   //Le centre de la zone de s�lection
   glm::dvec3 centreSelection_;

};


////////////////////////////////////////////////////////////////////////
///
/// @fn inline void ArbreRendu::ajouterUsine(const std::string& type, const UsineNoeud* usine)
///
/// Cette fonction permet d'ajouter une usine qui sera ensuite utilis�e
/// pour cr�er de nouveaux noeuds.
///
/// @param[in] type  : La cha�ne qui identifie le type de noeuds � cr�er
///                    avec cette usine.
/// @param[in] usine : L'usine ajout�e.
///
/// @return Aucune.
///
////////////////////////////////////////////////////////////////////////
inline void ArbreRendu::ajouterUsine(
   const std::string& type, const UsineNoeud* usine
   )
{
   usines_[type] = usine;
}


#endif // __ARBRE_ARBRERENDU_H__


///////////////////////////////////////////////////////////////////////////////
/// @}
///////////////////////////////////////////////////////////////////////////////
