#include "Station.h"
#include "CrossStation.h"
#include <iostream>

using namespace std;

Station::Station(string sgl, string loc)
{
	this->acronym = sgl;
	this->local = loc;

}

bool Station::addConnectionToStation(Station *stOfConnection) {


	return ConStation.insert(*stOfConnection);
}


bool Station::addPassagesTrain(Train *Tr, TDataHora *tDataHora, int line, bool withStop) {

	CrossStation csDetail(tDataHora, Tr, line, withStop);
	return crossStationDetail.insert(csDetail);
}


bool Station::getCrossesByStation (Train *tr, int line, bool pass) {
	
	Colecao<CrossStation>::iterator it;
	
	
	for (it = crossStationDetail.begin(); it != crossStationDetail.end(); it++)
	{
		CrossStation stDetailIt = (*it);
		if (stDetailIt.getTrain() == tr && stDetailIt.getcsLine() == line && stDetailIt.getCsWithStop() == pass)
		{
			cout << tr->getName() << " is pass from " << this->acronym << "detail is following:" << endl;
			stDetailIt.printCrossStation();
			return true;
		}
	}
	return false;
}

bool Station::crossTrainByStation(Train tr){
	
	Colecao<CrossStation>::iterator it;
	for (it = crossStationDetail.begin(); it != crossStationDetail.end(); it++)
	{
		CrossStation stDetailIt = (*it);
		if (true)
		{

		}
	}
	return true;
}
string Station::getName() {

	return this->acronym;
}

//operator method
bool Station::operator<(const  Station& s)const {

	return acronym < s.acronym;
}

//destructure method
Station::~Station()
{
}