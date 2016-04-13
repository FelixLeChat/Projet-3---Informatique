////////////////////////////////////////////////
/// @file   FacadeInterfaceNative.cpp
/// @author INF2990
/// @date   2014-08-16
///
/// @addtogroup inf2990 INF2990
/// @{
////////////////////////////////////////////////
#include "FacadeInterfaceNative.h"
#include "Application/FacadeModele.h"

#include "AideGL.h"
#include "Vue.h"
#include "CompteurAffichage.h"

#include "Tests/BancTests.h"

#include "Configuration/Config.h"

#include "Event/EventManager.h"
#include "Event/KeyPressEvent.h"
#include "Event/TimeEvent.h"

#include "Affichage/Affichage.h"
#include "Sons/ClasseSons.h"
#include "Reseau/NetworkManager.h"

extern "C"
{
	////////////////////////////////////////////////////////////////////////
	///
	/// __declspec(dllexport) void __cdecl initialiserOpenGL(int* handle)
	///
	/// Cette fonction initialise un contexte OpenGL dans la fen�tre
	/// identifi�e par le handle pass� en param�tre.  Cette fonction doit
	/// �tre la premi�re � �tre appel�e, car la cr�ation de l'objet du mod�le
	/// C++ s'attend � avoir un contexte OpenGL valide.
	///
	/// @param[in] handle : Le handle.
	///
	/// @return Aucune.
	///
	////////////////////////////////////////////////////////////////////////
	__declspec(dllexport) void __cdecl initialiserOpenGL(int* handle, char* s, int l)
	{
		if (handle == nullptr)
			return;

		FacadeModele::obtenirInstance()->initialiserOpenGL(HWND(handle), s, l);
	}


	////////////////////////////////////////////////////////////////////////
	///
	/// @fn __declspec(dllexport) void __cdecl libererOpenGL()
	///
	/// Cette fonction lib�re le contexte OpenGL.
	///
	/// @return Aucune.
	///
	////////////////////////////////////////////////////////////////////////
	__declspec(dllexport) void __cdecl libererOpenGL()
	{
		FacadeModele::obtenirInstance()->libererOpenGL();

		// D�sinitialisation de la fa�ade.  Le fait de le faire apr�s la
		// d�sinitialisation du contexte OpenGL aura pour cons�quence que la
		// lib�ration des listes d'affichages, par exemple, sera faite une fois que
		// le contexte n'existera plus, et sera donc sans effet.
		//FacadeModele::libererInstance();
	}

	////////////////////////////////////////////////////////////////////////
	///
	/// @fn __declspec(dllexport) void __cdecl libererModele()
	///
	///Cette fonction doit �tre la derni�re � �tre appel�e, car elle lib�re l'objet du mod�le
	/// C++.
	///
	/// @return Aucune.
	///
	////////////////////////////////////////////////////////////////////////
	__declspec(dllexport) void __cdecl libererModele()
	{
		FacadeModele::libererInstance();
	}


	////////////////////////////////////////////////////////////////////////
	///
	/// @fn __declspec(dllexport) void __cdecl arreterSon()
	///
	///Cette fonction arrete le son qui est jou�
	///
	/// @return Aucune.
	///
	////////////////////////////////////////////////////////////////////////
	__declspec(dllexport) void arreterSons(){
		FacadeModele::obtenirInstance()->arreterSons();
	}


	////////////////////////////////////////////////////////////////////////
	///
	/// @fn __declspec(dllexport) void __cdecl dessinerOpenGL()
	///
	/// Cette fonction affiche la sc�ne.
	///
	/// @return Aucune.
	///
	////////////////////////////////////////////////////////////////////////
	__declspec(dllexport) void __cdecl dessinerOpenGL()
	{
		// Affiche la sc�ne.
		FacadeModele::obtenirInstance()->afficher();

		// Temporaire: pour d�tecter les erreurs OpenGL
		//aidegl::verifierErreurOpenGL();
	}


	////////////////////////////////////////////////////////////////////////
	///
	/// __declspec(dllexport) void __cdecl redimensionnerFenetre(int largeur, int hauteur)
	///
	/// Cette fonction doit �tre appel�e lorsque la fen�tre est
	/// redimensionn�e afin d'ajuster les param�tres de la machine � �tats
	/// d'OpenGL pour correspondre aux nouvelles dimensions de la fen�tre.
	///
	/// @param[in] largeur : La nouvelle largeur de la fen�tre.
	/// @param[in] hauteur : La nouvelle hauteur de la fen�tre.
	///
	/// @return Aucune.
	///
	////////////////////////////////////////////////////////////////////////
	__declspec(dllexport) void __cdecl redimensionnerFenetre(int largeur, int hauteur)
	{
		Affichage::obtenirInstance()->obtenirVue()->redimensionnerFenetre(
			glm::ivec2{ 0, 0 },
			glm::ivec2{ largeur, hauteur }
		);
	}




	////////////////////////////////////////////////////////////////////////
	///
	/// __declspec(dllexport) void __cdecl redimensionnerSelection(int y1, int y2)
	///
	/// Cette fonction doit �tre appel�e lorsque l'utilisateur
	/// redimensionne different objets selectionnes
	///
	/// @param[in] y1 : La premiere valeur de la souris en y
	/// @param[in] y2 : La seconde valeur de la souris en y
	///
	/// @return Aucune.
	///
	////////////////////////////////////////////////////////////////////////
	__declspec(dllexport) void __cdecl redimensionnerSelection(int y1, int y2)
	{
		FacadeModele::obtenirInstance()->redimensionnerSelection(y1, y2);
	}



	////////////////////////////////////////////////////////////////////////
	///
	/// __declspec(dllexport) void rotaterSelection(int y1, int y2)
	///
	/// Cette fonction doit �tre appel�e lorsque l'utilisateur
	/// rotate different objets selectionnes
	///
	/// @param[in] y1 : La premiere valeur de la souris en y
	/// @param[in] y2 : La seconde valeur de la souris en y
	///
	/// @return Aucune.
	///
	////////////////////////////////////////////////////////////////////////
	__declspec(dllexport) void rotaterSelection(int y1, int y2)
	{
		FacadeModele::obtenirInstance()->rotaterSelection(y1, y2);
	}

	////////////////////////////////////////////////////////////////////////
	///
	/// __declspec(dllexport) void assignerCentreSelection()
	///
	/// Cette fonction doit �tre appel�e pour le centre de la s�lection.
	///
	///
	/// @return Aucune.
	///
	////////////////////////////////////////////////////////////////////////
	__declspec(dllexport) void assignerCentreSelection()
	{
		FacadeModele::obtenirInstance()->assignerCentreSelection();
	}


	////////////////////////////////////////////////////////////////////////
	///
	/// @fn __declspec(dllexport) void __cdecl animer(double temps)
	///
	/// Cette fonction effectue les diff�rents calculs d'animations
	/// n�cessaires pour le mode jeu, tel que les diff�rents calculs de
	/// physique du jeu.
	///
	/// @param[in] temps : Intervalle de temps sur lequel effectuer le calcul.
	///
	/// @return Aucune.
	///
	////////////////////////////////////////////////////////////////////////
	__declspec(dllexport) void __cdecl animer(double temps)
	{
		EventManager::GetInstance()->throwEvent(&TimeEvent(temps));
	}

	////////////////////////////////////////////////////////////////////////
	///
	/// @fn __declspec(dllexport) void annulerCreation()
	///
	/// Cette fonction annule la creation d'un mur ou d'un portail.
	///
	///
	/// @return Aucune.
	///
	////////////////////////////////////////////////////////////////////////
	__declspec(dllexport) void annulerCreation()
	{
		FacadeModele::obtenirInstance()->annulerCreation();
	}


	////////////////////////////////////////////////////////////////////////
	///
	/// @fn __declspec(dllexport) void __cdecl zoomIn()
	///
	/// Cette fonction applique un zoom avant sur le pr�sent volume de vision.
	///
	/// @return Aucune.
	///
	////////////////////////////////////////////////////////////////////////
	__declspec(dllexport) void __cdecl zoomIn()
	{
		Affichage::obtenirInstance()->obtenirVue()->zoomerIn();
	}


	////////////////////////////////////////////////////////////////////////
	///
	/// @fn __declspec(dllexport) void __cdecl zoomOut()
	///
	/// Cette fonction applique un zoom arri�re sur le pr�sent volume de vision.
	///
	/// @return Aucune.
	///
	////////////////////////////////////////////////////////////////////////
	__declspec(dllexport) void __cdecl zoomOut()
	{
		Affichage::obtenirInstance()->obtenirVue()->zoomerOut();
	}

	////////////////////////////////////////////////////////////////////////
	///
	/// @fn __declspec(dllexport) void __cdecl zoomInRect(int posX1, int posY1, int posX2, int posY2)
	///
	/// Cette fonction applique un zoom avant sur le pr�sent volume de vision
	/// avec le rectangle �leastique.
	///
	/// @param[in] posX1 : position en x du premier coin du rectangle �lastique.
	/// @param[in] posY1 : position en y du premier coin du rectangle �lastique.
	/// @param[in] posX2 : position en x du deuxi�me coin du rectangle �lastique.
	/// @param[in] posY2 : position en y du deuxi�me coin du rectangle �lastique.
	///
	/// @return Aucune.
	///
	////////////////////////////////////////////////////////////////////////
	__declspec(dllexport) void __cdecl zoomInRect(int posX1, int posY1, int posX2, int posY2)
	{
		Affichage::obtenirInstance()->obtenirVue()->zoomerInElastique(glm::ivec2(posX1, posY1), glm::ivec2(posX2, posY2));
	}

	////////////////////////////////////////////////////////////////////////
	///
	/// @fn __declspec(dllexport) void __cdecl zoomOutRect(int posX1, int posY1, int posX2, int posY2)
	///
	/// Cette fonction applique un zoom arri�re sur le pr�sent volume de vision
	/// avec le rectangle �lastique.
	///
	/// @param[in] posX1 : position en x du premier coin du rectangle �lastique.
	/// @param[in] posY1 : position en y du premier coin du rectangle �lastique.
	/// @param[in] posX2 : position en x du deuxi�me coin du rectangle �lastique.
	/// @param[in] posY2 : position en y du deuxi�me coin du rectangle �lastique.
	///
	/// @return Aucune.
	///
	////////////////////////////////////////////////////////////////////////
	__declspec(dllexport) void __cdecl zoomOutRect(int posX1, int posY1, int posX2, int posY2)
	{
		Affichage::obtenirInstance()->obtenirVue()->zoomerOutElastique(glm::ivec2(posX1, posY1), glm::ivec2(posX2, posY2));
	}


	////////////////////////////////////////////////////////////////////////
	///
	/// @fn __declspec(dllexport) int __cdecl obtenirAffichagesParSeconde()
	///
	/// Cette fonction permet d'obtenir le nombre d'affichages par seconde.
	///
	/// @return Le nombre d'affichage par seconde.
	///
	////////////////////////////////////////////////////////////////////////
	__declspec(dllexport) int __cdecl obtenirAffichagesParSeconde()
	{
		return utilitaire::CompteurAffichage::obtenirInstance()->obtenirAffichagesSeconde();
	}


	////////////////////////////////////////////////////////////////////////
	///
	/// @fn __declspec(dllexport) bool __cdecl executerTests()
	///
	/// Cette fonction permet d'ex�cuter l'ensemble des tests unitaires
	///
	/// @return 0 si tous les tests ont r�ussi, 1 si au moins un test a �chou�
	///
	////////////////////////////////////////////////////////////////////////
	__declspec(dllexport) bool __cdecl executerTests()
	{
		bool reussite = BancTests::obtenirInstance()->executer();
		return reussite ? 0 : 1;
	}

	////////////////////////////////////////////////////////////////////////
	///
	/// @fn __declspec(dllexport) void __cdecl deplacerCamera(double dx, double dy)
	///
	/// Cette fonction permet de d�placer la cam�ra avec le clavier (pourcentage de la taille de l'�cran)
	///
	/// @param[in] dx : la variation de positions en x.
	/// @param[in] dy : la variation de positions en y.
	///
	/// @return Aucune. 
	///
	////////////////////////////////////////////////////////////////////////
	__declspec(dllexport) void __cdecl deplacerCamera(double dx, double dy)
	{
		Affichage::obtenirInstance()->obtenirVue()->deplacerXY(dx, dy);
	}

	////////////////////////////////////////////////////////////////////////
	///
	/// @fn __declspec(dllexport) void __cdecl deplacerCameraInt(int dx, int dy)
	///
	/// Cette fonction permet de d�placer la cam�ra avec la souris.
	///
	/// @param[in] dx : la variation de positions en x.
	/// @param[in] dy : la variation de positions en y.
	///
	/// @return Aucune.
	///
	////////////////////////////////////////////////////////////////////////
	__declspec(dllexport) void __cdecl deplacerCameraInt(int dx, int dy)
	{
		Affichage::obtenirInstance()->obtenirVue()->deplacerXY(glm::ivec2(dx, dy));
	}

	////////////////////////////////////////////////////////////////////////
	///
	/// @fn __declspec(dllexport) void __cdecl initRectangle(int dx, int dy)
	///
	/// Cette fonction initialise le rectangle �lastique.
	/// 
	/// @param[in] dx : la variation de positions en x.
	/// @param[in] dy : la variation de positions en y.
	/// 
	/// @return Aucune.
	///
	////////////////////////////////////////////////////////////////////////
	__declspec(dllexport) void __cdecl initRectangle(int dx, int dy)
	{
		aidegl::initialiserRectangleElastique(glm::ivec2(dx, dy));
	}

	////////////////////////////////////////////////////////////////////////
	///
	/// @fn __declspec(dllexport) void __cdecl miseAJourRectangle(int posOrigX, int posOrigY, int posPrecX, int posPrecY, int posX, int posY)
	///
	/// Cette fonction met � jour le rectangle �lastique.
	///
	/// @param[in] posOrigX : la position originale en x.
	/// @param[in] posOrigY : la position originale en y.
	/// @param[in] posPrecX : la position pr�c�dente en x.
	/// @param[in] posPrecY : la position pr�c�dente en y.
	/// @param[in] posX : la position courante en x.
	/// @param[in] posY : la position courante en y.
	/// 
	/// @return Aucune.
	///
	////////////////////////////////////////////////////////////////////////
	__declspec(dllexport) void __cdecl miseAJourRectangle(int posOrigX, int posOrigY, int posPrecX, int posPrecY, int posX, int posY)
	{
		aidegl::mettreAJourRectangleElastique(glm::ivec2(posOrigX, posOrigY), glm::ivec2(posPrecX, posPrecY), glm::ivec2(posX, posY));
	}

	////////////////////////////////////////////////////////////////////////
	///
	/// @fn __declspec(dllexport) void __cdecl terminerRectangle(int posOrigX, int posOrigY, int posX, int posY)
	///
	/// Cette fonction compl�te le rectangle �lastique.
	///
	/// @param[in] posOrigX : la position originale en x.
	/// @param[in] posOrigY : la position originale en y.
	/// @param[in] posX : la position courante en x.
	/// @param[in] posY : la position courante en y.
	///
	/// @return Aucune.
	///
	////////////////////////////////////////////////////////////////////////
	__declspec(dllexport) void __cdecl terminerRectangle(int posOrigX, int posOrigY, int posX, int posY)
	{
		aidegl::terminerRectangleElastique(glm::ivec2(posOrigX, posOrigY), glm::ivec2(posX, posY));
	}


	__declspec(dllexport) int __cdecl getNiveauCarte()
	{
		return FacadeModele::obtenirInstance()->obtenirNiveauCarte();
	}

	////////////////////////////////////////////////////////////////////////
	///
	/// @fn __declspec(dllexport) bool __cdecl creerObjet(char* objet, int longueur, int x, int y)
	///
	/// Cette fonction cr�e un objet.
	///
	/// @param[in] objet : le nom de l'objet � cr�er.
	/// @param[in] longueur : la longueur du nom de l'objet � cr�er.
	/// @param[in] x : la position en x o� il faut cr�er l'objet.
	/// @param[in] y : la position en y o� il faut cr�er l'objet.
	///
	/// @return Si l'objet a �t� cr�� avec succ�s ou non.
	///
	////////////////////////////////////////////////////////////////////////
	__declspec(dllexport) bool __cdecl creerObjet(char* objet, int longueur, int x, int y)
	{
		return FacadeModele::obtenirInstance()->creerObjet(string(objet, longueur), x, y);
	}

	////////////////////////////////////////////////////////////////////////
	///
	/// @fn __declspec(dllexport) void __cdecl murFantome(int x, int y)
	///
	/// Cette fonction compl�te la cr�ation d'un mur.
	///
	/// @param[in] x : la position en x o� il faut fermer le mur.
	/// @param[in] y : la position en y o� il faut fermer le mur.
	///
	/// @return Aucune.
	///
	////////////////////////////////////////////////////////////////////////
	__declspec(dllexport) void __cdecl murFantome(int x, int y)
	{
		FacadeModele::obtenirInstance()->murFantome(x, y);
	}

	////////////////////////////////////////////////////////////////////////
	///
	/// @fn __declspec(dllexport) void __cdecl deplacerSlection(int x1, int x2, int y1, int y2, bool force)
	///
	/// @param[in] x1 : la position initiale en x de la s�lection.
	/// @param[in] x2 : la position finale en x de la s�lection.
	/// @param[in] y1 : la position initiale en y de la s�lection.
	/// @param[in] y2 : la position finale en y  de la s�lection.
	/// @param[in] force : si l'objet doit rester dans les bornes de la table ou non.
	///
	/// @return Aucune.
	///
	////////////////////////////////////////////////////////////////////////
	__declspec(dllexport) void __cdecl deplacerSelection(int x1, int x2, int y1, int y2, bool force)
	{
		FacadeModele::obtenirInstance()->deplacerSelection(x1, x2, y1, y2, force);
	}

	////////////////////////////////////////////////////////////////////////
	///
	/// @fn __declspec(dllexport) void chargerFichierXML(char* nomFichier, int longueur)
	///
	/// Cette fonction charge le fichier XML.
	///
	/// @param[in] nomFichier : le nom du fichier qu'il faut chercher.
	/// @param[in] longueur : la longueur du nom du fichier.
	///
	/// @return Aucune. 
	///
	////////////////////////////////////////////////////////////////////////
	__declspec(dllexport) void __cdecl chargerFichierXML(char* nomFichier, int longueur)
	{
		FacadeModele::obtenirInstance()->chargerFichierXML(nomFichier, longueur);
	}

	////////////////////////////////////////////////////////////////////////
	///
	/// @fn __declspec(dllexport) void enregistrerFichierXML(char* nomFichier, int longueur)
	///
	/// Cette fonction enregistre le fichier XML.
	///
	/// @param[in] nomFichier : le nom du fichier qu'il faut chercher.
	/// @param[in] longueur : la longueur du nom du fichier.
	///
	/// @return Aucune. 
	///
	////////////////////////////////////////////////////////////////////////
	__declspec(dllexport) void __cdecl enregistrerFichierXML(char* nomFichier, int longueur)
	{
		FacadeModele::obtenirInstance()->enregistrerFichierXML(nomFichier, longueur);
	}

	////////////////////////////////////////////////////////////////////////
	///
	/// @fn __declspec(dllexport) void mettreAJourProprietes(int collisionButoirCirculaire, int collisionButoirTriangulaire, int collisionCible, int pointBilleGratuite, int pointChangerNiveau, int difficulte)
	///
	/// Cette fonction met � jour les propri�t�s du jeu.
	///
	/// @param[in] collisionButoirCirculaire : le pointage d'un butoir circulaire.
	/// @param[in] collisionButoirTriangle : le pointage d'un butoir triangulaire.
	/// @param[in] collisionCible : le pointage d'une cible.
	/// @param[in] pointBilleGratuite : le pointage requis pour avoir une bille gratuite.
	/// @param[in] pointChangerNiveau : le pointage requis pour changer de niveau en mode campagne.
	/// @param[in] difficulte : le niveau de difficult�.
	///
	/// @return Aucune.
	///
	////////////////////////////////////////////////////////////////////////
	__declspec(dllexport) void __cdecl mettreAJourProprietes(int collisionButoirCirculaire, int collisionButoirTriangulaire, int collisionCible, int pointBilleGratuite, int pointChangerNiveau, int difficulte)
	{
		FacadeModele::obtenirInstance()->mettreAJourProprietes(collisionButoirCirculaire, collisionButoirTriangulaire, collisionCible, pointBilleGratuite, pointChangerNiveau, difficulte);
	}

	////////////////////////////////////////////////////////////////////////
	///
	/// @fn __declspec(dllexport) void mettreAJourConfiguration(int paletteGJ1, int paletteDJ1, int paletteGJ2, int paletteDJ2, int ressort, int nbBille, bool mode2Bille, bool forceRebond, bool debog, bool genBille, bool collision, bool eclairage, bool limitePortail)
	///
	/// Cette fonction met � jour la configuration du jeu.
	///
	/// @param[in] paletteGJ1 : la touche de contr�le de la palette gauche du joueur 1
	/// @param[in] paletteDJ1 : la touche de contr�le de la palette droite du joueur 1
	/// @param[in] paletteGJ2 : la touche de contr�le de la palette gauche du joueur 2
	/// @param[in] paletteDJ2 : la touche de contr�le de la palette droite du joueur 2
	/// @param[in] ressort : la touche de contr�le du ressort
	/// @param[in] nbBille : le nombre de billes par partie
	/// @param[in] mode2Bille : l'activation ou non du mode deux billes
	/// @param[in] forceRebond : l'activation ou non de la force de rebond suppl�mentaire des butoirs
	/// @param[in] debog : l'activation ou non de l'affichage de d�bogage
	///
	/// @return Aucune.
	///
	////////////////////////////////////////////////////////////////////////
	__declspec(dllexport) void __cdecl mettreAJourConfiguration(int paletteGJ1, int paletteDJ1, int paletteGJ2, int paletteDJ2, int ressort, int nbBille, bool mode2Bille, bool forceRebond, bool debog, bool genBille, bool collision, bool eclairage, bool limitePortail)
	{
		Config::obtenirInstance()->mettreAJourConfiguration(paletteGJ1, paletteDJ1, paletteGJ2, paletteDJ2, ressort, nbBille, mode2Bille,  forceRebond,  debog, genBille, collision, eclairage, limitePortail);
	}

	////////////////////////////////////////////////////////////////////////
	///
	/// @fn __declspec(dllexport) int selectionner(int x, int y, int longueur, int hauteur, bool ajout)
	///
	/// Cette fonction effectue la s�lection d'objets.
	///
	/// @param[in] x : la position centrale en x de la s�lection.
	/// @param[in] y : la position centrale en y de la s�lection.
	/// @param[in] longueur : la longueur de la s�lection.
	/// @param[in] largeur : la largeur de la s�lection.
	/// @param[in] ajout : sp�cifie si l'objet � s�lectionner est ajouter ou non
	///					   � la s�lection courante.
	///
	/// @return Le nombre d'objets s�lectionn�s. 
	///
	////////////////////////////////////////////////////////////////////////
	__declspec(dllexport) int __cdecl selectionner(int x, int y, int longueur, int hauteur, bool ajout)
	{
		return FacadeModele::obtenirInstance()->selectionner(x, y, longueur, hauteur, ajout);
	}

	////////////////////////////////////////////////////////////////////////
	///
	/// @fn __declspec(dllexport) void supprimerSelection()
	///
	/// Cette fonction effectue la suppression d'une s�lection.
	///
	/// @return Aucune. 
	///
	////////////////////////////////////////////////////////////////////////
	__declspec(dllexport) void __cdecl supprimerSelection()
	{
		FacadeModele::obtenirInstance()->supprimerSelection();
	}

	////////////////////////////////////////////////////////////////////////
	///
	/// @fn __declspec(dllexport) bool initialiserDuplication(int x, int y)
	///
	/// Cette fonction effectue l'initialisation de la duplication.
	///
	/// @param[in] x : la position centrale en x de la s�lection.
	/// @param[in] y : la position centrale en y de la s�lection.
	///
	/// @return Si la duplication a �t� effectu�e avec succ�s ou non. 
	///
	////////////////////////////////////////////////////////////////////////
	__declspec(dllexport) bool __cdecl initialiserDuplication(int x, int y)
	{
		return FacadeModele::obtenirInstance()->initDuplication(x, y);
		
	}

	////////////////////////////////////////////////////////////////////////
	///
	/// @fn __declspec(dllexport) void finirDuplication()
	///
	/// Cette fonction termine la duplication.
	///
	///
	/// @return Aucune. 
	///
	////////////////////////////////////////////////////////////////////////
	__declspec(dllexport) void __cdecl finirDuplication()
	{
		FacadeModele::obtenirInstance()->finirDuplication();
	}

	////////////////////////////////////////////////////////////////////////
	///
	/// @fn __declspec(dllexport) int getDifficulte()
	///
	/// Cette fonction obtient le niveau de difficult� du niveau.
	///
	///
	/// @return le niveau de difficult� du niveau. 
	///
	////////////////////////////////////////////////////////////////////////
	__declspec(dllexport) int __cdecl getDifficulte()
	{
		return FacadeModele::obtenirInstance()->getDifficulte();
	}

	////////////////////////////////////////////////////////////////////////
	///
	/// @fn __declspec(dllexport) int getPointBilleGratuite()
	///
	/// Cette fonction obtient le pointage n�cessaire pour avoir une bille gratuite.
	///
	///
	/// @return le pointage n�cessaire pour avoir une bille gratuite. 
	///
	////////////////////////////////////////////////////////////////////////
	__declspec(dllexport) int __cdecl getPointBilleGratuite()
	{
		return FacadeModele::obtenirInstance()->getPointBilleGratuite();
	}

	////////////////////////////////////////////////////////////////////////
	///
	/// @fn __declspec(dllexport) int getPointButoirCercle()
	///
	/// Cette fonction obtient le pointage d'un butoir circulaire.
	///
	///
	/// @return le pointage d'un butoir circulaire.
	///
	////////////////////////////////////////////////////////////////////////
	__declspec(dllexport) int __cdecl getPointButoirCercle()
	{
		return FacadeModele::obtenirInstance()->getPointButoirCercle();
	}

	////////////////////////////////////////////////////////////////////////
	///
	/// @fn __declspec(dllexport) int getPointButoirTriangle()
	///
	/// Cette fonction obtient le pointage d'un butoir triangulaire.
	///
	///
	/// @return le pointage d'un butoir triangulaire.
	///
	////////////////////////////////////////////////////////////////////////
	__declspec(dllexport) int __cdecl getPointButoirTriangle()
	{
		return FacadeModele::obtenirInstance()->getPointButoirTriangle();
	}

	////////////////////////////////////////////////////////////////////////
	///
	/// @fn __declspec(dllexport) int getPointCampagne()
	///
	/// Cette fonction obtient le pointage n�cessaire pour passer au niveau suivant en mode campagne.
	///
	///
	/// @return le pointage n�cessaire pour passer au niveau suivant en mode campagne.
	///
	////////////////////////////////////////////////////////////////////////
	__declspec(dllexport) int __cdecl getPointCampagne()
	{
		return FacadeModele::obtenirInstance()->getPointCampagne();
	}

	////////////////////////////////////////////////////////////////////////
	///
	/// @fn __declspec(dllexport) int getPointCible()
	///
	/// Cette fonction obtient le pointage d'une cible.
	///
	///
	/// @return le pointage d'une cible.
	///
	////////////////////////////////////////////////////////////////////////
	__declspec(dllexport) int __cdecl getPointCible()
	{
		return FacadeModele::obtenirInstance()->getPointCible();
	}

	////////////////////////////////////////////////////////////////////////
	///
	/// @fn __declspec(dllexport) double obtenirEchelleSelection()
	///
	/// Cette fonction obtient l'�chelle d'aggrandissement de la s�lection.
	///
	///
	/// @return l'�chelle d'aggrandissement de la s�lection.
	///
	////////////////////////////////////////////////////////////////////////
	__declspec(dllexport) double __cdecl obtenirEchelleSelection()
	{
		return FacadeModele::obtenirInstance()->obtenirEchelleSelection();
	}

	////////////////////////////////////////////////////////////////////////
	///
	/// @fn __declspec(dllexport) double obtenirRotationSelection()
	///
	/// Cette fonction obtient le degr� de rotation de la s�lection.
	///
	///
	/// @return le degr� de rotation de la s�lection.
	///
	////////////////////////////////////////////////////////////////////////
	__declspec(dllexport) double __cdecl obtenirRotationSelection()
	{
		return FacadeModele::obtenirInstance()->obtenirRotationSelection();
	}

	////////////////////////////////////////////////////////////////////////
	///
	/// @fn __declspec(dllexport) double obtenirPosXSel()
	///
	/// Cette fonction obtient la position en x de la s�lection.
	///
	///
	/// @return la position en x de la s�lection.
	///
	////////////////////////////////////////////////////////////////////////
	__declspec(dllexport) double __cdecl obtenirPosXSel()
	{
		return FacadeModele::obtenirInstance()->obtenirPosXSel();
	}

	////////////////////////////////////////////////////////////////////////
	///
	/// @fn __declspec(dllexport) double obtenirPosYSel()
	///
	/// Cette fonction obtient la position en y de la s�lection.
	///
	///
	/// @return la position en y de la s�lection.
	///
	////////////////////////////////////////////////////////////////////////
	__declspec(dllexport) double __cdecl obtenirPosYSel()
	{
		return FacadeModele::obtenirInstance()->obtenirPosYSel();
	}

	////////////////////////////////////////////////////////////////////////
	///
	/// @fn __declspec(dllexport) void assignerSelPosition(double x, double y)
	///
	/// Cette fonction assigne la position relative � la s�lection.
	///
	/// @param[in] x : la position en x.
	/// @param[in] y : la position en y.
	///
	/// @return Aucune.
	///
	////////////////////////////////////////////////////////////////////////
	__declspec(dllexport) void __cdecl assignerSelPosition(double x, double y)
	{
		FacadeModele::obtenirInstance()->assignerSelPosition(x, y);
	}

	////////////////////////////////////////////////////////////////////////
	///
	/// @fn __declspec(dllexport) bool getPointBilleGratuite()
	///
	/// Cette fonction v�rifie si la position donn�e est dans les bornes de la table de jeu.
	///
	///
	/// @return si la position donn�e est dans les bornes de la table de jeu. 
	///
	////////////////////////////////////////////////////////////////////////
	__declspec(dllexport) bool __cdecl positionDansBornes(double x, double y)
	{
		return FacadeModele::obtenirInstance()->positionDansBornes(int(x), int(y));
	}

	////////////////////////////////////////////////////////////////////////
	///
	/// @fn __declspec(dllexport) void finirCreationMur()
	///
	/// Cette fonction termine la creation d'un mur
	///
	/// @return si la position donn�e est dans les bornes de la table de jeu. 
	///
	////////////////////////////////////////////////////////////////////////
	__declspec(dllexport) void __cdecl finirCreationMur()
	{
		return FacadeModele::obtenirInstance()->finirCreationMur();
	}

	////////////////////////////////////////////////////////////////////////
	///
	/// @fn __declspec(dllexport) void toucheDefaut()
	///
	/// Cette fonction remet les touches de contr�le � leur valeur par d�faut
	///
	/// @return Aucune. 
	///
	////////////////////////////////////////////////////////////////////////
	__declspec(dllexport) void __cdecl toucheDefaut()
	{
		Config::obtenirInstance()->toucheDefaut();
	}

	////////////////////////////////////////////////////////////////////////
	///
	/// @fn __declspec(dllexport) void getPg1()
	///
	/// Cette fonction permet d'obtenir la valeur de la touche de contr�le de la palette gauche du joueur 1.
	///
	/// @return la valeur de la touche de contr�le de la palette gauche du joueur 1. 
	///
	////////////////////////////////////////////////////////////////////////
	__declspec(dllexport) int __cdecl getPg1()
	{
		return Config::obtenirInstance()->getPg1();
	}

	////////////////////////////////////////////////////////////////////////
	///
	/// @fn __declspec(dllexport) void getPg2()
	///
	/// Cette fonction permet d'obtenir la valeur de la touche de contr�le de la palette gauche du joueur 2.
	///
	/// @return la valeur de la touche de contr�le de la palette gauche du joueur 2. 
	///
	////////////////////////////////////////////////////////////////////////
	__declspec(dllexport) int __cdecl getPg2()
	{
		return Config::obtenirInstance()->getPg2();
	}
	

	////////////////////////////////////////////////////////////////////////
	///
	/// @fn __declspec(dllexport) void ouvrirPartieCampagne()
	///
	/// Cette fonction ouvre une campagne dans la fen�tre de jeu. Elle est appellee depuis le menu principal.
	///
	///
	////////////////////////////////////////////////////////////////////////
	__declspec(dllexport) void __cdecl ouvrirPartieCampagne(int nbJoueurs, bool humain, char* chemin){
		FacadeModele::obtenirInstance()->ouvrirPartieCampagne(nbJoueurs, humain, string(chemin));
	}



	////////////////////////////////////////////////////////////////////////
	///
	/// @fn __declspec(dllexport) void ouvrirPartieRapide()
	///
	/// Cette fonction ouvre une partie rapide dans la fen�tre de jeu. Elle est appellee depuis le menu principal.
	///
	///
	////////////////////////////////////////////////////////////////////////
	__declspec(dllexport) void __cdecl ouvrirPartieRapide(int nbJoueurs, bool humain, char* chemin, int longueurChemin){
		FacadeModele::obtenirInstance()->ouvrirPartieRapide(nbJoueurs, humain, string(chemin, longueurChemin));
	}


	////////////////////////////////////////////////////////////////////////
	///
	/// @fn __declspec(dllexport) void ouvrirPartieTest()
	///
	/// Cette fonction ouvre une partie test dans l'editeur.Elle est appellee depuis le menu principal.
	///
	///
	////////////////////////////////////////////////////////////////////////
	__declspec(dllexport) void __cdecl ouvrirPartieTest(char* chemin, int longueurChemin){
		string s = string(chemin, longueurChemin);
		FacadeModele::obtenirInstance()->ouvrirPartieTest(s);
	}

	////////////////////////////////////////////////////////////////////////
	///
	/// @fn __declspec(dllexport) void getPd1()
	///
	/// Cette fonction permet d'obtenir la valeur de la touche de contr�le de la palette droite du joueur 1.
	///
	/// @return la valeur de la touche de contr�le de la palette droite du joueur 1. 
	///
	////////////////////////////////////////////////////////////////////////
	__declspec(dllexport) int __cdecl getPd1()
	{
		return Config::obtenirInstance()->getPd1();
	}

	////////////////////////////////////////////////////////////////////////
	///
	/// @fn __declspec(dllexport) void getPd2()
	///
	/// Cette fonction permet d'obtenir la valeur de la touche de contr�le de la palette droite du joueur 2.
	///
	/// @return la valeur de la touche de contr�le de la palette droite du joueur 2. 
	///
	////////////////////////////////////////////////////////////////////////
	__declspec(dllexport) int __cdecl getPd2()
	{
		return Config::obtenirInstance()->getPd2();
	}

	////////////////////////////////////////////////////////////////////////
	///
	/// @fn __declspec(dllexport) int getRes()
	///
	/// Cette fonction permet d'obtenir la valeur de la touche de contr�le des ressorts.
	///
	/// @return la valeur de la touche de contr�le des ressorts. 
	///
	////////////////////////////////////////////////////////////////////////
	__declspec(dllexport) int __cdecl getRes()
	{
		return Config::obtenirInstance()->getRes();
	}

	////////////////////////////////////////////////////////////////////////
	///
	/// @fn __declspec(dllexport) int getNbBilles()
	///
	/// Cette fonction obtient le nombre de billes dans la partie
	///
	/// @return le nombre de billes dans la partie
	///
	////////////////////////////////////////////////////////////////////////
	__declspec(dllexport) int __cdecl getNbBilles()
	{
		return Config::obtenirInstance()->getNbBilles();
	}
	////////////////////////////////////////////////////////////////////////
	///
	/// @fn __declspec(dllexport) bool getMode2Billes()
	///
	/// Cette fonction obtient si le mode deux billes est activ�
	///
	/// @return si le mode deux billes est activ�
	///
	////////////////////////////////////////////////////////////////////////
	__declspec(dllexport) bool __cdecl getMode2Billes()
	{
		return Config::obtenirInstance()->getMode2Billes();
	}
	////////////////////////////////////////////////////////////////////////
	///
	/// @fn __declspec(dllexport) bool getForceRebond()
	///
	/// Cette fonction obtient si la force de rebond est ajout�e aux butoirs
	///
	/// @return si la force de rebond est ajout� aux butoirs
	///
	////////////////////////////////////////////////////////////////////////
	__declspec(dllexport) bool __cdecl getForceRebond()
	{
		return Config::obtenirInstance()->getForceRebond();
	}
	////////////////////////////////////////////////////////////////////////
	///
	/// @fn __declspec(dllexport) bool getDebog()
	///
	/// Cette fonction obtient si l'affichage de d�bogage est activ� ou non
	///
	/// @return si l'affichage de d�bogage est activ� ou non
	///
	////////////////////////////////////////////////////////////////////////
	__declspec(dllexport) bool __cdecl getDebog()
	{
		return Config::obtenirInstance()->getDebog();
	}

	////////////////////////////////////////////////////////////////////////
	///
	/// @fn __declspec(dllexport) bool getGenBille()
	///
	/// Cette fonction obtient si l'affichage de g�n�ration de bille est activ� ou non
	///
	/// @return si l'affichage de g�n�ration de bille est activ� ou non
	///
	////////////////////////////////////////////////////////////////////////
	__declspec(dllexport) bool __cdecl getGenBille()
	{
		return Config::obtenirInstance()->getGenBille();
	}

	////////////////////////////////////////////////////////////////////////
	///
	/// @fn __declspec(dllexport) bool getVitBilles()
	///
	/// Cette fonction obtient si l'affichage de la vitesse des billes apr�s collision est activ� ou non
	///
	/// @return si l'affichage de la vitesse des billes apr�s collision est activ� ou non
	///
	////////////////////////////////////////////////////////////////////////
	__declspec(dllexport) bool __cdecl getVitBilles()
	{
		return Config::obtenirInstance()->getVitBilles();
	}

	////////////////////////////////////////////////////////////////////////
	///
	/// @fn __declspec(dllexport) bool getEclairage()
	///
	/// Cette fonction obtient si l'affichage de l'activation ou non de l'�clairage  est activ� ou non
	///
	/// @return si l'affichage de l'activation ou non de l'�clairage  est activ� ou non
	///
	////////////////////////////////////////////////////////////////////////
	__declspec(dllexport) bool __cdecl getEclairage()
	{
		return Config::obtenirInstance()->getEclairage();
	}

	////////////////////////////////////////////////////////////////////////
	///
	/// @fn __declspec(dllexport) bool getLimitesPortails()
	///
	/// Cette fonction obtient si l'affichage de la limite d'attraction des portails est activ� ou non
	///
	/// @return si l'affichage de la limite d'attraction des portails est activ� ou non
	///
	////////////////////////////////////////////////////////////////////////
	__declspec(dllexport) bool __cdecl getLimitesPortails()
	{
		return Config::obtenirInstance()->getLimitesPortails();
	}

	////////////////////////////////////////////////////////////////////////
	///
	/// @fn __declspec(dllexport) bool creerConfig()
	///
	/// Cette fonction lit les valeurs de la configuration � partir d'un �l�ment
	/// XML.
	///
	/// @return Aucune.
	///
	////////////////////////////////////////////////////////////////////////

	__declspec(dllexport) bool __cdecl creerConfig()
	{
		ClasseSons::obtenirInstance();
		return Config::obtenirInstance()->lireConfig("donn�es\\config.xml",19, true);
	}

	////////////////////////////////////////////////////////////////////////
	///
	/// @fn void appuyerBouton(int keycode)
	///
	/// Cette fonction appele simplement la methode appuyerBouton de facade modele
	///
	///  @param[in] keycode : le code de la touche
	///
	////////////////////////////////////////////////////////////////////////
	__declspec(dllexport) void __cdecl appuyerBouton(int keycode)
	{
 		EventManager::GetInstance()->throwEvent(&KeyPressEvent(keycode, true));
	}

	////////////////////////////////////////////////////////////////////////
	///
	/// @fn void relacherBouton(int keycode)
	///
	/// Cette fonction appele simplement la methode relacherBouton de facade modele
	///
	///  @param[in] keycode : le code de la touche
	///
	////////////////////////////////////////////////////////////////////////
	__declspec(dllexport) void __cdecl relacherBouton(int keycode)
	{
		EventManager::GetInstance()->throwEvent(&KeyPressEvent(keycode, false));
	}

	////////////////////////////////////////////////////////////////////////
	///
	/// @fn void obtenirFichiers(int nb)
	///
	/// Cette fonction assigne les zones de jeu � la campagne
	///  @param[in] int - l'id du fichier a avoir
	///
	///  @return les fichiers de la campagne.
	///
	////////////////////////////////////////////////////////////////////////

	__declspec(dllexport) void obtenirFichier(char *str, int len, int i)

	{
		string s = FacadeModele::obtenirInstance()->obtenirFichierCampagne(i);
		strcpy(str, s.c_str());
	}
	
	////////////////////////////////////////////////////////////////////////
	///
	/// @fn bool demarrerPartie()
	///
	/// Cette fonction demarre une partie
	///
	///  @param[in] Aucune.
	///
	///  @return si la partie s'est bien demarree
	///
	////////////////////////////////////////////////////////////////////////
	__declspec(dllexport) bool __cdecl demarrerPartie()
	{
		return FacadeModele::obtenirInstance()->demarrerPartie();
	}

	////////////////////////////////////////////////////////////////////////
	///
	/// @fn void reinitialiser()
	///
	/// Reinitialise la zone de jeu
	///
	///  @param[in] Aucune.
	///
	///  @return Aucune
	///
	////////////////////////////////////////////////////////////////////////
	__declspec(dllexport) void __cdecl reinitialiser()
	{
		FacadeModele::obtenirInstance()->reinitialiser();
	}

	////////////////////////////////////////////////////////////////////////
	///
	/// @fn void obtenirEstHumain(bool humain)
	///
	/// Cette fonction assigne si le deuxi�me joueur est un humain ou un ordinateur
	///
	///  @param[in] Aucun.
	///
	///  @return si le deuxi�me joueur est un humain ou non.
	///
	////////////////////////////////////////////////////////////////////////
	__declspec(dllexport) bool __cdecl obtenirEstHumain()
	{
		return FacadeModele::obtenirInstance()->getEstHumainCampagne();
	}

	////////////////////////////////////////////////////////////////////////
	///
	/// @fn void obtenirNombreJoueur()
	///
	/// Cette fonction obtient le nombre de joueurs 
	///
	///  @param[in] Aucune.
	///
	///  @return le nombre de joueur.
	///
	////////////////////////////////////////////////////////////////////////
	__declspec(dllexport) bool __cdecl obtenirNombreJoueur()
	{
		return FacadeModele::obtenirInstance()->getNbJoueursCampagne();
	}
	////////////////////////////////////////////////////////////////////////
	///
	/// @fn int obtenirNombreFichiers()
	///
	/// Envoie le nombre de Fichiers XML lus dans le fichier de campagne
	/// Est utilis�e par la feenetre qui s'ouvre lors d'une nouvelle partie campagne 
	/// pour savoir combien de nom de fichier elle va recevoir via la fonction obtenirFichiers().
	///
	///  @param[in] Aucune.
	///
	///  @return int
	///
	////////////////////////////////////////////////////////////////////////
	__declspec(dllexport) int __cdecl obtenirNombreFichiers()
	{
		return FacadeModele::obtenirInstance()->getNbFichiersCampagne();
	}

	////////////////////////////////////////////////////////////////////////
	///
	/// @fn bool envoyerNomFichier(char* nomFichier, int longueur)
	///
	///	 Envoie le nom d'un fichier xml a charger pour une campagne.
	///  La fonction est n�cessaire car contrairement a partieRapide, on ne sait pas combien de fichier il faudra charger
	///
	///  @param[in] nomFichier : Nom du fichier xml a charger
	///  @param[in] longueur : longueur du chemin transmis
	///
	///  @return bool : Echec ou reussite du chargement du fichier par c++
	///
	////////////////////////////////////////////////////////////////////////
	__declspec(dllexport) bool __cdecl envoyerNomFichier(char* nomFichier, int longueur)
	{
		return FacadeModele::obtenirInstance()->envoyerNomFichierCampagne(nomFichier, longueur);
	}


	////////////////////////////////////////////////////////////////////////
	///
	/// @fn __declspec(dllexport) bool __cdecl obtenirEstTerminee()
	///
	///	 Obtient si la partie est termin�e ou non
	///
	///  @param[in]
	///
	///  @return bool : si la partie est termin�e ou non
	///
	////////////////////////////////////////////////////////////////////////
	__declspec(dllexport) bool __cdecl obtenirEstTerminee()
	{
		return FacadeModele::obtenirInstance()->obtenirPartieEstTerminee();
	}

	////////////////////////////////////////////////////////////////////////
	///
	/// @fn __declspec(dllexport) bool __cdecl obtenirEstGagnee()
	///
	///	 Obtient si la partie est gagn�e ou non
	///
	///  @param[in]
	///
	///  @return bool : si la partie est gagn�e ou non
	///
	////////////////////////////////////////////////////////////////////////
	__declspec(dllexport) bool __cdecl obtenirEstGagnee()
	{
		return FacadeModele::obtenirInstance()->obtenirPartieEstGagnee();
	}

	/// @fn void finReceptionNomFichiers()
	///
	///	 Fonction appellee lors du debut d'une partie campagne pour dire au c++ qu'il a recu les noms 
	///
	////////////////////////////////////////////////////////////////////////
	__declspec(dllexport) void finReceptionNomFichiers()
	{
		FacadeModele::obtenirInstance()->finReceptionNomFichiersCampagne();
	}


	////////////////////////////////////////////////////////////////////////
	///
	/// @fn void transmettreJoueursHumain(bool nbJoueurs, bool humain);
	///
	///	 Fonction appellee lors du debut d'une partie campagne pour dire au c++ 
	///  le nb de joueur et si le 2eme joueur sera un humain ou AI
	///
	///  @param[in] nbJoueurs : Nombre de joueurs (true = 1, false = 2)
	///  @param[in] humain : Le second joueur est un: (true = humain, false = AI)
	///
	////////////////////////////////////////////////////////////////////////
	__declspec(dllexport) void transmettreJoueursHumain(bool nbJoueurs, bool humain)
	{
		int nJoueurs = 2;
		if (nbJoueurs) nJoueurs = 1;
		FacadeModele::obtenirInstance()->assignerTypeJoueursCampagne(nJoueurs, humain);
	}

	////////////////////////////////////////////////////////////////////////
	///
	/// @fn void basculerDebug();
	///
	///	 Baslcule l'�tat de d�bogage
	///
	///  @param[in] Aucun
	///
	////////////////////////////////////////////////////////////////////////
	__declspec(dllexport) void basculerDebug()
	{
		Config::obtenirInstance()->setDebog(!Config::obtenirInstance()->getDebog());
	}

	////////////////////////////////////////////////////////////////////////
	///
	/// @fn void cameraOrbite();
	///
	///	 Change la cam�ra � une cameraOrbite
	///
	///  @param[in] Aucun
	///
	////////////////////////////////////////////////////////////////////////
	__declspec(dllexport) void cameraOrbite()
	{
		FacadeModele::obtenirInstance()->changerCamera(true);
	}
	////////////////////////////////////////////////////////////////////////
	///
	/// @fn void cameraOrtho();
	///
	///	 change la cam�ra � une cameraOrtho
	///
	///  @param[in] Aucun
	///
	////////////////////////////////////////////////////////////////////////
	__declspec(dllexport) void cameraOrtho()
	{
		FacadeModele::obtenirInstance()->changerCamera(false);
	}

	__declspec(dllexport) void bloquerSons()
	{
		ClasseSons::bloquerSons();
	}
}

__declspec(dllexport) void creerPartieCampagneEnLigne(bool estCoop, int nbJoueurs, int nbAi, char* matchId, int matchIdLength, char** playerIds, int* playerIdLength, int nbZones, char** zonePath, int* zonePathLength, bool estHost, bool estRejoin)
{
	string matchId_s = string(matchId, matchIdLength);
	vector<string> playerIds_s;
	for (int i = 0; i < nbJoueurs; i++)
	{
		playerIds_s.push_back(string(playerIds[i], playerIdLength[i]));
	}
	vector<string> zonePaths_s;
	for (int i = 0; i < nbZones; i++)
	{
		zonePaths_s.push_back(string(zonePath[i], zonePathLength[i]));
	}
	FacadeModele::obtenirInstance()->creerPartieCampagneEnLigne(estCoop, playerIds_s, zonePaths_s, nbAi, estHost, matchId_s, estRejoin);
}
__declspec(dllexport) void creerPartieSimpleEnLigne(bool estCoop, int nbJoueurs, int nbAi, char* matchId, int matchIdLength, char** playerIds, int* playerIdLength, char* zonePath, int zonePathLength, bool estHost, bool estRejoin)
{
	string matchId_s = string(matchId, matchIdLength);
	vector<string> playerIds_s;
	for (int i = 0; i < nbJoueurs; i++)
	{
		playerIds_s.push_back(string(playerIds[i], playerIdLength[i]));
	}
	string zonePath_s = string(zonePath, zonePathLength);
	FacadeModele::obtenirInstance()->creerPartieSimpleEnLigne(estCoop, playerIds_s, zonePath_s, nbAi, estHost, matchId_s, estRejoin);
}

__declspec(dllexport) void quitterPartie()
{
	NetworkManager::getInstance()->quitMatch();
}


__declspec(dllexport) void connexion(char* userToken, int tokenLength, char* userId, int userIdLength)
{
	NetworkManager::getInstance()->connexion(string(userToken, tokenLength), string(userId, userIdLength));
}

__declspec(dllexport) void deconnexion()
{
	NetworkManager::getInstance()->deconnexion();
}


__declspec(dllexport) int obtenirNbBillesJoueur(int joueur)
{
	return FacadeModele::obtenirInstance()->obtenirBillesRestantesJoueur(joueur);
}

__declspec(dllexport) int obtenirMonPointage()
{
	return FacadeModele::obtenirInstance()->obtenirMonPointage();
}

__declspec(dllexport) int obtenirMeilleurPointage()
{
	return FacadeModele::obtenirInstance()->obtenirMeilleurPointage();

}



__declspec(dllexport) int obtenirMonNbBilles()
{
	return FacadeModele::obtenirInstance()->obtenirMonNbBille();
}

__declspec(dllexport) int obtenirPointageJoueur(int joueur)
{
	return FacadeModele::obtenirInstance()->obtenirPointageJoueur(joueur);
}






__declspec(dllexport) bool obtenirRondeGagnee()
{
	return FacadeModele::obtenirInstance()->obtenirRondeGagnee();
}
__declspec(dllexport) int obtenirDifficulteZone()
{
	return FacadeModele::obtenirInstance()->obtenirDifficulteZone();
}
__declspec(dllexport) int obtenirPointsAAtteindre()
{
	return FacadeModele::obtenirInstance()->obtenirPointsAAtteindre();
}

__declspec(dllexport) void obtenirNomZone(char* nom)
{
	string s = FacadeModele::obtenirInstance()->obtenirNomZone();
	strcpy(nom, s.c_str());
}
///////////////////////////////////////////////////////////////////////////////
/// @}
///////////////////////////////////////////////////////////////////////////////

