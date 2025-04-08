#pragma once
#include <string>

struct SolarSystem {
	int planetNum;
	std::string planetName;
	double planetDiameter;
	SolarSystem* next;
};

SolarSystem* newList(const int count);
void showList(const SolarSystem* p);
void deleteList(SolarSystem*& head);
void showListElement(const SolarSystem* head, const int place);
SolarSystem* insertToList(SolarSystem* head,
	const int place,
	const int pNum,
	const std::string pName,
	const double pDiam);
void removeItemList(SolarSystem*& head, const int place);
SolarSystem* showMaxValue(SolarSystem* head);
void showElement(SolarSystem* elem);

