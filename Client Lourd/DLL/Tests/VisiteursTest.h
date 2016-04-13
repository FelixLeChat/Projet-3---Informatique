//////////////////////////////////////////////////////////////////////////////
/// @file VisiteursTest.h
/// @author J�r�mie Gagn�
/// @date 2015-02-15
/// @version 1.0
///
/// @addtogroup inf2990 INF2990
/// @{
//////////////////////////////////////////////////////////////////////////////

#ifndef _TESTS_VisiteursTEST_H
#define _TESTS_VisiteursTEST_H

#include <cppunit/extensions/HelperMacros.h>
#include <memory>

#include "../Arbre/ArbreRenduINF2990.h"

///////////////////////////////////////////////////////////////////////////
/// @class VisiteursTest
/// @brief Classe de test cppunit pour tester le bon fonctionnement des
///        m�thodes de la classe Visiteurs
///
/// @author J�r�mie Gagn�
/// @date 2015-02-15
///////////////////////////////////////////////////////////////////////////
class VisiteursTest : public CppUnit::TestFixture
{

	// =================================================================
	// D�claration de la suite de tests et des m�thodes de tests
	//
	// Important, vous devez d�finir chacun de vos cas de tests � l'aide
	// de la macro CPPUNIT_TEST sinon ce dernier ne sera pas ex�cut� !
	// =================================================================
	CPPUNIT_TEST_SUITE(VisiteursTest);
	CPPUNIT_TEST(testDeplacement);
	CPPUNIT_TEST(testRotation);
	CPPUNIT_TEST(testMiseAEchelle);
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

	/// Test le visiteur de deplacement
	void testDeplacement();
	/// Test le visiteur de rotation
	void testRotation();
	/// Test le visiteur de mise a l'echelle
	void testMiseAEchelle();

private:
	std::unique_ptr<ArbreRenduINF2990> arbre;

};

#endif // _TESTS_VisiteursTEST_H


///////////////////////////////////////////////////////////////////////////////
/// @}
///////////////////////////////////////////////////////////////////////////////
