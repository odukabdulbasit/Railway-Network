#include "Train.h"

Train::Train(string acr)
{

	this->acronym = acr;
}

bool Train::operator<(const Train &t) const {

	return acronym < t.acronym;
}

bool Train::addPassagesStation(Station *st, TDataHora *tDataHora, bool withStop) {
	
	if (withStop == true)
	{
		stopSts.insert(st);
	}
	return passageStations.insert(st), stopDataHora.insert(tDataHora), withStops.insert(withStop);
}


void Train::printStops() {

	Colecao<Station*>::iterator it;
	for (it=stopSts.begin(); it!= stopSts.end(); it++)
	{
			cout << (*it)->getName() << endl;

	}
}

void Train::printCrossStation() {

	Colecao<Station*>::iterator it;
	for (it = passageStations.begin(); it != passageStations.end(); it++)
	{
		cout << (*it)->getName() << endl;

	}
}

string Train::getName() {

	return acronym;
}


Train::~Train()
{
	
}