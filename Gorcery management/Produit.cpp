//Ce programme simule une petite application de gestion de stock d'un magasin

#include "Produit.h"
#include<iostream>
#include <fstream>
#include<sstream>
#include<string>
#include<ctime>
#include <limits>

using namespace std;



ofstream fichierData("data.csv", ios:: app);
void Produit::ajouterProduit()
{
	
	int sortie;
	do {
		
		cout << endl;
		cout << "Entrez le nom du produit: ";
		getline(cin, nom);

		cout << "Entrez le prix du produit ($) : ";
		getline(cin, prix);

		cout << "Entrez la quantite en stock du produit: ";
		getline(cin, quantite);

		fichierData << nom << ";" << genererID() << ";" << prix << ";" << quantite << endl;
		cout << "Voulez-vous rajouter un produit en stock ? (1.OUI / 2. NON ): ";
		cin >> sortie;

		while (sortie < 1 || sortie >2)
		{
			cout << "Le choix ne peut etre que soit 1 ou 2." << endl;
			cout << "Voulez-vous rajouter un produit en stock ? (1.OUI / 2. NON ): ";
			cin >> sortie;
		}
		cin.ignore();
	} while (sortie == 1);
}

	
	

//Genere un ID random pour chaque produit 
int Produit::genererID()
{
	
	srand(time(0));
	 ID = 1+rand() % 101;
	 return ID;
	
}


//rechercher produit 
void Produit::afficherStock()
{
	ifstream fichierData("data.csv");
	string ligne;
	int sortie;
	string nom, id, prix, quantite;
	while (getline(fichierData, ligne))
	{
		stringstream ss(ligne);
		getline(ss, nom, ';');
		getline(ss, id, ';');
		getline(ss, prix, ';');
		getline(ss, quantite, ';');
		cout << "Nom du produit:" << nom << endl;
		cout << "ID:" << id << endl;
		cout << "Prix:" << prix << " $" << endl;
		cout<<"Quantite disponible:" << quantite << endl;
	

	}

}

//Fonction qui fait la recherche de produit 
void Produit::rechercherProduit()
{
	
	int sortie;
	string nomRecherche;
	
	string ligne;
	string nomEnregistre, id, prix, quantite;
	if (!fichierData.is_open())
	{
		cerr << "Erreur, pas d'acces au fichier" << endl;

	}
	
	do {
		ifstream fichierData("data.csv", ios::_Nocreate);
		bool nomTrouve = false;
		cout << "Entrez le nom du produit recherche: ";
		getline(cin, nomRecherche);


		while (getline(fichierData, ligne))
		{
			
			stringstream ss(ligne);
			getline(ss, nomEnregistre, ';');

			if (nomEnregistre == nomRecherche)
			{
				nomTrouve = true;
				getline(ss, id, ';');
				getline(ss, prix, ';');
				getline(ss, quantite, ';');
				
				cout << endl;
				cout << "Produit retrouve avec succes !" << endl;
				cout << "Nom du produit:" << nomEnregistre << endl;
				cout << "ID:" << id << endl;
				cout << "Prix:" << prix << " $" << endl;
				cout << "Quantite disponible:" << quantite << endl;
				
			}

			
		}
		if (nomTrouve == false)
		{
			cout << "Produit introuvable !" << endl;
			
		}
		
		cout << "Voulez-vous trouver un autre produit ? ( 1.Oui/ 2. Non ): ";
		
		cin >> sortie;
		
		while (sortie < 1 || sortie>2)
		{
			cout << "Vous devez choisir entre 1 et 2: ";
			cin >> sortie;
			
		}
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

	} while (sortie == 1);
	
	fichierData.close();
}
