// BullCowGame.cpp : définit le point d'entrée pour l'application console.
//
#include "stdafx.h"
#include <iostream>
#include <string>
#include "Bull.h"

using namespace std;

using FTEXT = string;
using int32 = int;
//Prototypes
void AfficheIntro(CBullCowGame joueur);
FTEXT VotreMot(CBullCowGame joueur);
void Jouer(CBullCowGame joueur);
bool JouerEncore();


int32 main()
{

	CBullCowGame joueur;
	//cout << joueur.getEssaiCourant() << endl;
	//cout << joueur.getMaxEssai() << endl;

	//bool JEncore = false;

	do {

		AfficheIntro(joueur);
		/*constexpr int NombreTours = 5;
		for(int i = 0;i<NombreTours;i++)
		VotreMot();*/
		Jouer(joueur);
		//JEncore = JouerEncore();

	} while (JouerEncore());
	system("pause");

    return 0;
}

void AfficheIntro(CBullCowGame joueur) {

	constexpr int32 WORLD_LENGTH = 9; // une constante local a la procedure

	cout << "Bienvenue dans le jeu Bull and Cow Game" << endl;
	cout << "Nombre de lettre du mot cache : " << joueur.getLongMotCache() << endl;
	cout << "Status : " << joueur.getEWordStatus() << endl;
	cout << "Nombre de possibilite " << joueur.getMaxEssai()<< endl;



}

FTEXT VotreMot(CBullCowGame joueur) {
	EWordStatus status = EWordStatus::Ok;
	do {
		
		int32 EssaiCourant = joueur.getEssaiCourant();
		FTEXT mot = "";
		cout << "Essai " << EssaiCourant << endl;
		cout << "Saisir votre mot : " << endl;
		getline(cin, mot);

		status = joueur.TestValideMot(mot);
		switch (status) {
				case EWordStatus::Wrong_Lenght: cout << "Entrez un mot de max : " << joueur.getLongMotCache() << " lettres" << endl;break;
				case EWordStatus::Not_Isogram:cout << "Entrez un mot sans lettres repetées " << endl;break;
				case EWordStatus::Mot_Lowercase:cout << "Entrez un mot minuscule" << endl;break;
				default:return mot;break;
		}
	} while (status != EWordStatus::Ok);
	
}

bool JouerEncore() {

	cout << "Voulez-vous rejouer o ou O ?" << endl;
	FTEXT Reponse = "";
	getline(cin, Reponse);
	return (Reponse[0] == 'o') || (Reponse[0] == 'O');

}



void Jouer(CBullCowGame joueur) {

	

	joueur.Reset();
	int32 MaxEssai = joueur.getMaxEssai();
	while(!joueur.Gagne() && joueur.getEssaiCourant()<=MaxEssai){
	//for (int32 i = 1; i <= MaxEssai;i++) {
		FTEXT mot = VotreMot(joueur);
		EWordStatus status = joueur.TestValideMot(mot);

		BullCowCount BullCowCount = joueur.valideEssai(mot);
		cout << "Votre mot est : " << mot << endl;
		cout << "Bulls = "<<BullCowCount.bulls << endl;
		cout << "Cows = "<<BullCowCount.cows << endl;
		cout << endl;
	}
	if (joueur.Gagne()) {
		cout << "Bravo" << endl;

	}
	else { cout << " perdu" << endl; }

	

}

