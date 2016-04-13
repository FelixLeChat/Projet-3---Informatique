#ifndef __GAMELOGIC_PARTIE_CAMPAGNE_H__
#define __GAMELOGIC_PARTIE_CAMPAGNE_H__
////////////////////////////////////////////////
/// @file   PartieCampagne.h
/// @author Nicolas Blais, J�r�me Daigle
/// @date   2014-03-17
///
/// @addtogroup inf2990 INF2990
/// @{
////////////////////////////////////////////////

#include "PartieRapide.h"

class PartieCampagne : public PartieRapide
{
public:

	/// Constructeur
	PartieCampagne(int nbJoueurs, bool humain, string chemin);
	PartieCampagne( vector<string> playerIds, vector<string> paths, int nb_ai, bool estHost, string matchId, bool estRejoin = false);
	~PartieCampagne();
	///M�thodes virtuelles

	/// M�thode virtuelle d'analyse du pointage
	virtual void analyserPointage();
	/// M�thode virtuelle d'obtention du nom du fichier XML
	virtual string obtenirNomFichierXml(int i);
	/// M�thode virtuelle de r�initialisation de la partie
	virtual void reinitialiser();
	/// M�thode virtuelle de d�marrage de la partie
	virtual bool demarrerPartie();
	virtual void tick(double dt);

	virtual void afficher();

	//Fonctions appellees uniquement pour PartieCampagne

	/// M�thode virtuelle d'envoi du nom du fichier
	virtual  bool envoyerNomFichier(char* nomFichier, int longueur);
	/// M�thode virtuelle d'affichage des informations de la partie
	virtual void afficherInformation();
	/// M�thode virtuelle de tri de parties par difficult�
	virtual void finReceptionNomFichiers();
	/// M�thode virtuelle donnant le nombre de joueurs et leur nature humaine
	virtual void recevoirJoueursHumain(int nbJoueurs, bool humain);

	bool obtenirEstHumain();
	int obtenirNbFichiers();
	int obtenirNbJoueurs();

	void update(IEvent* e);
	void toutSynchroniser(SyncAllEvent* SyncEvent) override;
	void envoiSynchronisationGlobale() override;


	bool obtenirRondeGagnee() const override;
	int obtenirDifficulteZone() const override;
	int obtenirPointsAAtteindre() const override;

private:
	/// M�thode d'obtention de la r�ussite ou non du chargement du fichier XML 
	bool XMLCampagneBienLu;
	/// M�thode d'assignation d'un nom de fichier � l'arbre
	string nomFichierCampagne;
	/// M�thode d'�criture sur XML
	bool ecrireFichierCampagneXML(string cheminFichier);
	/// M�thode de lecture sur XML
	bool lireFichierCampagneXML(string cheminFichier);

	//Puisque partie campagne recoit les noms de fichiers, il faut vider le vieil arbre s'il n,en a pas encore recu (donc le savoir via nombreFichiersRecus == 0)
	int nombreFichiersRecus = 0;
	/// La partie actuelle
	int partieActuelle_;
	/// Si la ronde actuelle est gagn�e
	bool rondeGagnee;

	double tempsAffichage_;

	//Config de campage
	int nbJoueurs_;
	bool humain_;


	vector<ZoneDeJeu*> zones_;

};
#endif // !__GAMELOGIC_PARTIE_CAMPAGNE_H__
