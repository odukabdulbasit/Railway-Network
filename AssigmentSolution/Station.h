#pragma once
#include "Colecao.h" 
#include "Passage.h"
#include "Train.h"
#include "TDataHora.h"
#include "CrossStation.h"
#include <iostream>

using namespace std;

class CrossStation;

class Station
{
	
public:
	Station(string, string);
	bool operator<(const Station &) const;
	string getName();
	bool crossTrainByStation(Train tra);
	bool addPassagesTrain(Train* Tr, TDataHora *tDataHora, int lin, bool withStop);
	bool getCrossesByStation(Train *t, int line, bool to);
	bool addConnectionToStation(Station *acr);
	~Station();

private:

	//for add train, datahour, line and withstop or not at the Colecao list
	Colecao<CrossStation> crossStationDetail;

	Colecao <Station> ConStation;
	string acronym;
	string local;
};
