#include <iostream>

#include "MyList.h"

int main() {
	// Init head for List
	SolarSystem* headPlanets;
	// Create List
	headPlanets = newList(9);
	// Add elem to list
	insertToList(headPlanets, 3, 140, "Underfined Planet", 144.86);
	// Show elem in list
	showListElement(headPlanets, 3);
	// delete elem from list
	removeItemList(headPlanets, 3);
	// Show List
	showList(headPlanets);
	// Unique Function]
	SolarSystem* maxVal = showMaxValue(headPlanets);
	showElement(maxVal);
	// Delete List
	deleteList(headPlanets);
	
	return 0;
}