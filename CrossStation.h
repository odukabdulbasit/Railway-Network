#pragma once
#include <iostream>
#include "Train.h"
#include "TDataHora.h"

class CrossStation
{
public:
	CrossStation(TDataHora *tDataHora, Train *tr, int line, bool withStop);
	bool operator<(const CrossStation&) const;
	TDataHora *getTDataHora();
	Train *getTrain();
	bool getCsWithStop();
	int getcsLine();
	void printCrossStation();
	~CrossStation();

private:
	
	Train* csTr;
	TDataHora *csTDataHora;
	bool csWithStop;
	int csLine;
};

