#pragma once
#include "Colecao.h"
#include "TDataHora.h"
#include "Station.h"
#include "Train.h"

class Station;
class Train;

class Passage
{
public:
	Passage(int, bool, int, Station*, Train*);
	bool operator<(const Passage&) const;	
	~Passage();

private:
	Station *passSt;
	Train *passTr;
	int id;
	TDataHora datahour;
	bool withStop;
	int line;
};
