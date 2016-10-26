#pragma once
#include <string>
using namespace std;


using FString = std::string;
using int32 = int;

typedef struct BullCowCount{
	int32 bulls = 0;
	int32 cows = 0;
};

enum class EWordStatus {
	Ok,
	Not_Isogram,
	Wrong_Lenght,
	Mot_Lowercase
};



class CBullCowGame {


private:
	int32 essaiCourant = 0;
	//int32 MaxEssai = 0;
	FString MotCache;
	EWordStatus status;
	bool gagne = false;

public:

	CBullCowGame();
	~CBullCowGame();

	//get
	int32 getEssaiCourant()const;
	int32 getMaxEssai()const;

	//set

	void SetEssaiCourant(int32 nEssai);
	void SetMaxEssai(int32 nEssai);

	void Reset();

	bool Gagne()const;

	EWordStatus TestValideMot(FString Mot)const;

	//bool TestValideMot(FString)const;

	BullCowCount valideEssai(FString);

	int32 CBullCowGame::getLongMotCache()const;

	int32 getEWordStatus();

	bool estIsogram(FString Mot)const;

	bool estMini(FString Mot)const;
};