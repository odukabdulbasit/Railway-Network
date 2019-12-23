#pragma once
#include <iostream>
#include"Colecao.h"
#include "Station.h"
#include "Train.h"
#include "Passage.h"

using namespace std;

class Station;
class Train;


class RN
{
	
public:
	RN();
	bool addTrain(string);
	bool addStation(string, string);
	bool addConnectionToStation(string, string);
	bool crossTrainByStation(string, string, int, bool);
	bool printCrossesStation(string);
	bool printStopsTrain(string);

	bool addPassage(int, bool, int, string, string);


	~RN();

private:
	Colecao<Train>  Trainsler;
	Colecao<Station>  Stationslar;
	Colecao<Passage>  Passagesler;

	Station  *findStation(string);
	Train *findTrain(string);

};