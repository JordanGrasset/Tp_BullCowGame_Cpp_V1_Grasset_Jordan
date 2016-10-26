#include "stdafx.h"
#include "Bull.h"
#include <map>

#define TMAP std::map
CBullCowGame::CBullCowGame() {
	
	Reset();
}

/*CBullCowGame::CBullCowGame(int nEssai, int nMaxEssai) {
	this->essaiCourant = nEssai;
	this->MaxEssai = nMaxEssai;
	
}*/

CBullCowGame::~CBullCowGame() {

}

int32 CBullCowGame::getEssaiCourant() const
{
	return this->essaiCourant;
}

int32 CBullCowGame::getMaxEssai() const
{
	TMAP<int32, int32> LgMotEssaiMax{ {3,4},{ 4,7 } ,{ 5,10 } ,{ 6,16 } ,{ 7,20 } };
	return LgMotEssaiMax[MotCache.length()];
}

void CBullCowGame::SetEssaiCourant(int32 nEssai)
{
	this->essaiCourant = nEssai;
}

void CBullCowGame::SetMaxEssai(int32 nEssai)
{
	//this->MaxEssai = nEssai;
}

void CBullCowGame::Reset()
{
	//constexpr int32 MAX_ESSAI = 8;
	//this->MaxEssai = MAX_ESSAI;
	
	const FString MOTCACHE = "hilare";
	MotCache = MOTCACHE;
	this->essaiCourant = 1;
	gagne = false;


}

bool CBullCowGame::Gagne()const
{
	return gagne;
}

EWordStatus CBullCowGame::TestValideMot(FString Mot) const
{

	if (!estIsogram(Mot)) {//si pas isogram
		return EWordStatus::Not_Isogram;
	}
	else if (!estMini(Mot)) {//si pas minuscule
		return EWordStatus::Mot_Lowercase;
	}
	else if (Mot.length() != getLongMotCache()) {
		return EWordStatus::Wrong_Lenght;
	}
	else {
	return EWordStatus::Ok;
	}
}

/*bool CBullCowGame::TestValideMot(FString)const
{
	return false;
}*/

BullCowCount CBullCowGame::valideEssai(FString Mot)
{
	essaiCourant++;
	BullCowCount BullCowCount;

	int32 longMot = Mot.length();
	for (int32 i = 0;i < longMot;i++) {
		for (int32 j = 0;j < longMot;j++) {
			if (Mot[i] == MotCache[j]) {
				if (i == j) {
					BullCowCount.bulls++;
				}
				else BullCowCount.cows++;
			}
		}
	}

	if (BullCowCount.bulls == getLongMotCache()) {
		gagne = true;
	}
	else {
		gagne = false;
	}

	return BullCowCount;
}

int32 CBullCowGame::getLongMotCache() const
{
	return MotCache.length();
}

int32 CBullCowGame::getEWordStatus()
{
	return (int32)status;
}

bool CBullCowGame::estIsogram(FString Mot) const
{
	if (Mot.length() <= 1) { return true; }

	TMAP<char, bool>lettreMot;

	for (auto lettre : Mot) {
		lettre = tolower(lettre);
		if (lettreMot[lettre]) {
			return false;
		}
		else {
			lettreMot[lettre] = true;
		}
	}

	return true;
}

bool CBullCowGame::estMini(FString Mot) const
{ 
	
	for (auto lettre : Mot) {

		if (islower(lettre)) {
			return true;
		}
		else { return false; }
	}
	
}


