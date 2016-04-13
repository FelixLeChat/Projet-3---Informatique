//////////////////////////////////////////////////////////////////////////////
/// @file ProjectionOrthoTest.h
/// @author Konstantin Fedorov
/// @date 2015-02-15
/// @version 1.0
///
/// @addtogroup inf2990 INF2990
/// @{
//////////////////////////////////////////////////////////////////////////////

#ifndef _TESTS_ProjectionOrthoTEST_H
#define _TESTS_ProjectionOrthoTEST_H

#include <cppunit/extensions/HelperMacros.h>
#include <memory>
#include "ProjectionOrtho.h"

///////////////////////////////////////////////////////////////////////////
/// @class ProjectionOrthoTest
/// @brief Classe de test cppunit pour tester le bon fonctionnement des
///        m�thodes de la classe ProjectionOrtho
///
/// @author Konstantin Fedorov
/// @date 2015-02-15
///////////////////////////////////////////////////////////////////////////
class ProjectionOrthoTest : public CppUnit::TestFixture
{

	// =================================================================
	// D�claration de la suite de tests et des m�thodes de tests
	//
	// Important, vous devez d�finir chacun de vos cas de tests � l'aide
	// de la macro CPPUNIT_TEST sinon ce dernier ne sera pas ex�cut� !
	// =================================================================
	CPPUNIT_TEST_SUITE(ProjectionOrthoTest);
	CPPUNIT_TEST(testAjustementRapport);
	CPPUNIT_TEST(testRedimensionnement);
	CPPUNIT_TEST(testZoomSimple);
	CPPUNIT_TEST(testZoomRect);
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
	
	// Tester l'ajustement automatique du rapport d'aspect de la fenetre virtuelle
	void testAjustementRapport();
	// Tester le redimensionnement
	void testRedimensionnement();
	// Tester les deux types de zoom simple
	void testZoomSimple();
	// Tester les deux types de zoom avec le rectangle elastique
	void testZoomRect();

private:
	/// Instance d'un noeud abstrait
	std::unique_ptr<vue::ProjectionOrtho> projection;
};

#endif // _TESTS_ProjectionOrthoTEST_H


///////////////////////////////////////////////////////////////////////////////
/// @}
///////////////////////////////////////////////////////////////////////////////
