//Ce fichier contient toutes les declarations et les constructeurs concernant les Utilisateurs 

#pragma once
#include <fstream>
#include<sstream>
#include<string>
#include<ctime>

using namespace std;

//Onjet Administrateur
class Admin
{
private:
	string Id;
	string titre="Administrateur";

public:
	string email;
	string motDePass;
	string nom;

	//Constructeur par defaut 
	Admin();

	//Methodes 
	void creerCompte();
	void connexion();
	void calculerRecettesDuJour();
	void hsitoriqueDesVentes();
	void gestionDeStock();
	void genrerID();

};


class Client
{
private:
	string titre = "Client";
public:
	string email;
	string motDePasse;
	string nom;

	//constructeur
	Client();

	//Methodes
	void creerCompte();
	void connexion();
	void voirLesProduits();
	void passerCommande();
	void historiqueDachat();
	void boiteDerecption();
};