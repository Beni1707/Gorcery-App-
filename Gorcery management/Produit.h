//Ce fichier va contenir les objets que nous allons creer 

#pragma once
#include <iostream>
#include<string>
#include<sstream>
#include<fstream>
#include<ctime>

using namespace std;

class Produit
{
private:
	int  ID;

public :
	string quantite;
	string prix;
	string nom;

	//Constructeur par defaut 

	Produit() {};
	
		

	//Definition des methodes 
	void rechercherProduit();
	void ajouterProduit();
	int genererID();
	void afficherStock();

};

