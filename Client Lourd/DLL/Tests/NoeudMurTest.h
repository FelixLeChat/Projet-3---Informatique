//////////////////////////////////////////////////////////////////////////////
/// @file NoeudMurTest.h
/// @author J�r�mie Gagn�
/// @date 2015-02-15
/// @version 1.0
///
/// @addtogroup inf2990 INF2990
/// @{
//////////////////////////////////////////////////////////////////////////////

#ifndef _TESTS_NoeudMurTEST_H
#define _TESTS_NoeudMurTEST_H

#include <cppunit/extensions/HelperMacros.h>
#include <memory>

#include "../Arbre/Noeuds/NoeudMur.h"
#include "../Arbre/ArbreRenduINF2990.h"

///////////////////////////////////////////////////////////////////////////
/// @class NoeudMurTest
/// @brief Classe de test cppunit pour tester le bon fonctionnement des
///        m�thodes de la classe NoeudMur
///
/// @author J�r�mie Gagn�
/// @date 2015-02-15
///////////////////////////////////////////////////////////////////////////
class NoeudMurTest : public CppUnit::TestFixture
{

	// =================================================================
	// D�claration de la suite de tests et des m�thodes de tests
	//
	// Important, vous devez d�finir chacun de vos cas de tests � l'aide
	// de la macro CPPUNIT_TEST sinon ce dernier ne sera pas ex�cut� !
	// =================================================================
	CPPUNIT_TEST_SUITE(NoeudMurTest);
	CPPUNIT_TEST(testAssignerDeuxiemePoint);
	CPPUNIT_TEST_SUITE_END();

public:

	// =================================================================
	// M�thodes pour initialiser et 'finaliser' la suite de tests
	// =================================================================

	/// Traitement � effectuer pour initialiser cette suite de tests
	void setUp();

	/// Traitement � effectuer pour 'finaliser' cette suite de tests
	void tearDown();


	// =================================================================
	// D�finissez ici les diff�rents cas de tests...
	// =================================================================

	/// Tester l'assignation du deuxieme point d'un mur
	void testAssignerDeuxiemePoint();

private:
	std::unique_ptr<ArbreRenduINF2990> arbre;

};

#endif // _TESTS_NoeudMurTEST_H


///////////////////////////////////////////////////////////////////////////////
/// @}
///////////////////////////////////////////////////////////////////////////////
