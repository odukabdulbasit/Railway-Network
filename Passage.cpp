#include "Passage.h"
#include "Colecao.h"
#include "Station.h"
#include "Train.h"

Passage::Passage(int id, bool para, int lin, Station* e, Train* c)
{
	this->id = id;
	this->line = lin;
	this->withStop = para;
	passSt = e;
	passTr = c;
	datahour = TDataHora::hoje_agora();

	//add satation datahour and withstop or not at the train
	passTr->addPassagesStation(passSt, &datahour, withStop);

	//add train, datahour, line and withstop or not at the station
	passSt->addPassagesTrain(passTr, &datahour, line, withStop);
}


bool Passage::operator<(const  Passage& p)const {

	return id < p.id;
}

Passage::~Passage()
{
}
