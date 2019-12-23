#pragma once
#include "Colecao.h"
#include "Station.h"
#include <iostream>

using namespace std;
class Station;

class Train
{

public:
	
	Train(string);
	bool operator< (const Train &) const;
	bool addPassagesStation(Station *stopSt, TDataHora *tDataHora, bool withStop);
	string getName();
	void printStops();
	void printCrossStation();
	~Train();

private:

	
	Colecao <Station*> passageStations;
	Colecao <TDataHora*> stopDataHora;
	Colecao<bool> withStops;

	//if train will stop at the station add to here
	Colecao<Station*> stopSts;
	
	string acronym;
};

