#include <iostream>
#include"Colecao.h"
#include "RN.h"
#include "Station.h"
#include "Train.h"


using namespace std;

RN::RN()
{
}

bool RN::addTrain(string acr) {

	Train tren(acr);
	cout << acr << "is added to trains succesfully." << endl;
	return Trainsler.insert(tren);
}

bool RN::addStation(string acr, string loc) {

	Station station(acr, loc);
	cout << acr << "is added to stations succesfully." << endl;
	return Stationslar.insert(station);
}


bool RN::addConnectionToStation(string st, string stOfConnection) {

	Station *stCon = findStation(stOfConnection);
	Station *station = findStation(st);

	if (station != NULL)
	{
		return station->addConnectionToStation(stCon);
	}
	else
	{
		cout << "Station: " << st << "don't existing" << endl;
		return false;
	}
}

bool RN::addPassage(int id,bool withStop, int line, string acrSt, string acrTr ) {

	Station* stt = findStation(acrSt);
	Train* trn = findTrain(acrTr);

	if (stt != NULL && trn != NULL)
	{
		Passage ps(id, withStop, line, stt, trn);

		return Passagesler.insert(ps);
	}
	
}

//-------
//Should return t->crossByStastion(s, lin, to); if the trains pass in certain station
//Otherwise return FALSE
bool RN::crossTrainByStation(string tra, string sta, int lin, bool to) {
	
	Station* stt = findStation(sta);
	Train* trn = findTrain(tra);
	
	if (stt != NULL && trn != NULL)
	{
		stt->getCrossesByStation(trn, lin, to);
		return true;
	}
	else
	{
		cout << tra <<" or "<< sta<< " is not existing! Please check your entered information" << endl;
		return false;
	}
}

//Prints all the stations where the train pass
bool RN::printCrossesStation(string acr) {
	
	Train* tr = findTrain(acr);
	if (tr != NULL)
	{
		cout << "Pass Station of " << acr << ":" << endl;
		tr->printCrossStation();
		return true;
	}
	else
	{
		cout << acr << "is not existing!" << endl;
		return false;
	}
	
}


bool RN::printStopsTrain(string acr) {

	Train* tr = findTrain(acr); 
	if (tr !=NULL)
	{
		tr->printStops();
		return true;
	}
	else
	{
		cout << "Train not existing." << endl;
		return false;
	}
	
}


Train *RN::findTrain(string acr) {

	Train t(acr);
	return Trainsler.find(t);
}
Station *RN::findStation(string acr) {

	Station st(acr, "");
	return Stationslar.find(st);
}
RN::~RN()
{
}


/*
The idea it's to develop an application to manage the registration of the trains crossing the various
stations of a railway network (RN). 

1) Each station is characterized by an acronym, which identifies it, by its
location and connections to other stations on the network. 

2) A train is only characterized by the acronym that identifies it.

3) With regard to the passage of a train through a given station, it should be recorded in
the system, the station, the train, the number of the line the train pass through, the date/time (from the
operating system) that the train pass and if, the trains stopped or not on that station.

4) In addition to ensuring the registration of train crossings by a set of stations, the application should
allow to add new trains, new stations and add connections to the existing stations. 

5) The system, should also be able to show all the stop locations of a given train and all train passages by a given station, with
date/time indication, line number, acronym of the train and whether or not there was a stop at this
station.


Fikir bir demiryolu a��n�n �e�itli istasyonlar�ndan ge�en trenlerin kayd�n� y�netmek i�in bir uygulama geli�tirmek.

+1) Her istasyon, konumu ve a�daki di�er istasyonlara ba�lant�lar� ile onu tan�mlayan bir k�saltma ile karakterize edilir.

+2) Bir tren sadece onu tan�mlayan k�saltma ile karakterize edilir.


PASSAGES
3) Bir trenin belirli bir istasyondan ge�i�iyle ilgili olarak,
	sisteme, 
	istasyona, 
	trene,
	trenin ge�ti�i hat say�s�na, 
	trenin �al��t��� tarih / saate kaydedilmelidir.
	ge�ip giderse, trenler o istasyonda durdu veya durmad�.

4) Tren ge�itlerinin bir dizi istasyon taraf�ndan kaydedilmesini 
sa�laman�n yan� s�ra,
+ uygulama yeni trenlerin, yeni istasyonlar�n eklenmesine ve
+ mevcut istasyonlara ba�lant�lar eklenmesine izin vermelidir.

5) Sistem ayr�ca belirli bir trenin 
	t�m durma yerlerini ve 
	t�m tren ge�itlerini belirli bir istasyonla,
	tarih / saat g�stergesi,
	hat numaras�, 
	trenin k�saltmas� ve 
	bu istasyonda bir duraklama olup olmad���n� g�sterebilmelidir.

*/