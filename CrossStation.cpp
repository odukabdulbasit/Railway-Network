#include <iostream>
#include "CrossStation.h"
#include "Train.h"
#include "TDataHora.h"


CrossStation::CrossStation(TDataHora *tDataHora, Train* Tr, int line, bool withStop)
{
	this->csLine = line;
	this->csTr = Tr;
	this->csTDataHora = tDataHora;
	this->csWithStop = withStop;
}

bool CrossStation::operator<(const  CrossStation& csSt)const {

	return csTDataHora < csSt.csTDataHora;
}


void CrossStation::printCrossStation() {

	cout << "Data Time: "<< this->csTDataHora->getData() <<", ";
	cout <<"train name: " << this->csTr->getName() << "  ";
	cout << "line: "<< this->csLine << ",  ";
	if (csWithStop == true)
	{
		cout << "with stop in this station" << "  " << endl;
	}
	else
	{
		cout << "without stop in this station" << "  " << endl;
	}
}

Train *CrossStation::getTrain() {

	return csTr;
}

TDataHora *CrossStation::getTDataHora() {

	return csTDataHora;
}

int CrossStation::getcsLine() {

	return csLine;
}

bool CrossStation::getCsWithStop() {

	return csWithStop;
}


CrossStation::~CrossStation()
{
}