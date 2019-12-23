#include <iostream>
#include "Train.h"
#include "RN.h"
#include "Passage.h"
#include "Station.h"

using namespace std;

int main() {

	
	//define railway network
	RN  railwayNetwork1;

	//add train to network
	railwayNetwork1.addTrain("train1");
	railwayNetwork1.addTrain("train2");
	railwayNetwork1.addTrain("train3");
	cout << endl;
	cout << endl;

	//add station to railway network
	railwayNetwork1.addStation("marsesst", "Mardin");
	railwayNetwork1.addStation("BragancaExpresst","Braganca");
	railwayNetwork1.addStation("diyarbakirst", "diyarbakir");
	railwayNetwork1.addStation("Elazigst", "elazig");
	cout << endl;

	//this station for the additional connection to other  station
	railwayNetwork1.addStation("Porto", "Porto");
	railwayNetwork1.addStation("Lizboa", "Lizboa");
	railwayNetwork1.addStation("Braganca", "Braganca");
	cout << endl;

	//add connection station to another
	railwayNetwork1.addConnectionToStation("Porto", "Lizboa");
	railwayNetwork1.addConnectionToStation("Lizboa", "Braganca" );
	cout << endl;


	//add passage to system
	railwayNetwork1.addPassage(1, true, 1, "marsesst", "train1");
	railwayNetwork1.addPassage(2, false, 1, "BragancaExpresst", "train1");
	railwayNetwork1.addPassage(3, true, 2, "diyarbakirst", "train1");
	railwayNetwork1.addPassage(4, false, 1, "Elazigst", "train1");

	
	cout << "Stop station of train1:" << endl;
	railwayNetwork1.printStopsTrain("train1");

	cout << endl;
	railwayNetwork1.printCrossesStation("train1");

	cout << endl;
	railwayNetwork1.crossTrainByStation("train1", "marsesst", 1, true);

	return 0;
}