////////////////////////////////////////////////////////////////////////////////////
/// @file NoeudMurTest.cpp
/// @author J�r�mie Gagn�
/// @date 2015-02-15
/// @version 1.0
///
/// @addtogroup inf2990 INF2990
/// @{
////////////////////////////////////////////////////////////////////////////////////

#include "NoeudMurTest.h"
#include "../Arbre/Noeuds/NoeudMur.h"


// Enregistrement de la suite de tests au sein du registre
CPPUNIT_TEST_SUITE_REGISTRATION(NoeudMurTest);


////////////////////////////////////////////////////////////////////////
///
/// @fn void NoeudMurTest::setUp()
///
/// Effectue l'initialisation pr�alable � l'ex�cution de l'ensemble des
/// cas de tests de cette suite de tests (si n�cessaire).
/// 
/// Si certains objets doivent �tre construits, il est conseill� de le
/// faire ici.
///
/// @return Aucune.
///
////////////////////////////////////////////////////////////////////////
void NoeudMurTest::setUp()
{
	arbre = std::make_unique<ArbreRenduINF2990>();
	
	NoeudAbstrait* nouveauNoeud;
	glm::dvec3 position;
	// On vide l'arbre
	arbre->vider();

	// On ajoute un noeud bidon seulement pour que quelque chose s'affiche.
	NoeudAbstrait* noeud = arbre->creerNoeud(ArbreRenduINF2990::NOM_ZONEDEJEU);
	noeud->assignerEstSelectionnable(false);

	nouveauNoeud = arbre->creerNoeud(ArbreRenduINF2990::NOM_TROU);
	position = glm::dvec3(0, -75, 0);
	nouveauNoeud->assignerPositionRelative(position);
	noeud->ajouter(nouveauNoeud);

	nouveauNoeud = arbre->creerNoeud(ArbreRenduINF2990::NOM_RESSORT);
	position = glm::dvec3(42, -70, 0);
	nouveauNoeud->assignerPositionRelative(position);
	noeud->ajouter(nouveauNoeud);

	nouveauNoeud = arbre->creerNoeud(ArbreRenduINF2990::NOM_GENERATEURBILLE);
	position = glm::dvec3(35, -45, 0);
	nouveauNoeud->assignerPositionRelative(position);
	noeud->ajouter(nouveauNoeud);

	arbre->ajouter(noeud);
}

////////////////////////////////////////////////////////////////////////
///
/// @fn void NoeudMurTest::tearDown()
///
/// Effectue les op�rations de finalisation n�cessaires suite � l'ex�cution
/// de l'ensemble des cas de tests de cette suite de tests (si n�cessaire).
/// 
/// Si certains objets ont �t� allou�s � l'initialisation, ils doivent �tre
/// d�sallou�s, et il est conseill� de le faire ici.
///
/// @return Aucune.
///
////////////////////////////////////////////////////////////////////////
void NoeudMurTest::tearDown()
{
	arbre->vider();
}



////////////////////////////////////////////////////////////////////////
///
/// @fn void NoeudMurTest::testAssignerDeuxiemePoint()
///
/// Cas de test: Assigner le deuxieme point du mur et verifier 
/// les differentes transformations associees
///
/// @return Aucune.
///
////////////////////////////////////////////////////////////////////////
void NoeudMurTest::testAssignerDeuxiemePoint()
{
	NoeudMur* mur = dynamic_cast<NoeudMur*> (arbre->creerNoeud(ArbreRenduINF2990::NOM_MUR));
	double hauteurBase = mur->obtenirBornes().coinMax.y - mur->obtenirBornes().coinMin.y;

	mur->assignerPositionRelative(glm::dvec3(0,0,0));

	arbre->chercher(ArbreRenduINF2990::NOM_ZONEDEJEU)->ajouter(mur);

	mur->assignerDeuxiemePoint(3.0, 4.0);


	CPPUNIT_ASSERT(mur->obtenirLongueur()*hauteurBase == 5.0);
	CPPUNIT_ASSERT(mur->obtenirPositionRelative().x == 1.5);
	CPPUNIT_ASSERT(mur->obtenirPositionRelative().y == 2.0);

	mur->assignerDeuxiemePoint(6*cos(utilitaire::DEG_TO_RAD(30)), 3);

	CPPUNIT_ASSERT(mur->obtenirRotation() == 90+30);
}




///////////////////////////////////////////////////////////////////////////////
/// @}
///////////////////////////////////////////////////////////////////////////////
