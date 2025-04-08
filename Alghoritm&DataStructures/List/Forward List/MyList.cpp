#include <cstdlib>
#include <fstream>
#include <iostream>

#include "myList.h"


// Creating new list
SolarSystem* newList(const int count) {
    SolarSystem* last = nullptr; // Pointer to the last element of list
    SolarSystem* p = nullptr; // Pointer for working with structure

    std::string line;
    std::fstream f;
    
    // Working with file
    f.open("planets.txt", std::ios::in);
    if (!f.is_open()) {
        std::cerr << "ERROR! FILE DIDNT OPEN!\n";
        f.close();
        return nullptr;
    }

    for (int i = 0; i < count; i++) {
        p = new SolarSystem; // Create new elem of structure in 

        // Writing data to the structure
        // Getting structure's fields by pointers
        std::getline(f, line);
        p->planetNum = std::stoi(line);
        std::getline(f, line);
        p->planetName = line;
        std::getline(f, line);
        p->planetDiameter = std::stof(line);

        p->next = last; // Next element refers to (nullptr)
        last = p; // Back pointer
    }
    f.close();
    return last;
}

// Showing List
void showList(const SolarSystem* p) {
    std::cout << "#SHOWING LIST\n";
    while (p != nullptr) {
        std::cout << "\taddress: " << std::hex << p << " | "
            << "N_" << std::dec << p->planetNum << " | "
            << "Name: " << std::dec << p->planetName << " | "
            << "D = " << std::dec << p->planetDiameter << " |\n";

        p = p->next; // Going to next element
    }
    return;
}

void deleteList(SolarSystem* &head) {
    SolarSystem* cur = head;
    SolarSystem* del = head;

    while (cur != nullptr) {
        cur = cur->next;
        delete del;
        del = cur;
    }
    head = nullptr;
}

void showListElement(const SolarSystem* head, const int place) {
    int i = 0;
    while (i < place && head != nullptr) {
        head = head->next; // Going to next element
        i++;
    }
    if (head != nullptr)
        std::cout << "#" << place << "-th ELEMENT OF LIST \n"
        << "\taddress: " << std::hex << head << " | "
        << "N_" << std::dec << head->planetNum << " | "
        << "Name: " << std::dec << head->planetName << " | "
        << "D = " << std::dec << head->planetDiameter << " |\n";
    return;
}

SolarSystem* insertToList(SolarSystem* head, 
                        const int place, 
                        const int pNum, 
                        const std::string pName, 
                        const double pDiam) 
{
    SolarSystem* item = new SolarSystem;

    item->planetNum = pNum;
    item->planetName = pName;
    item->planetDiameter = pDiam;
    item->next = nullptr;

    if (head == nullptr) { // empty list
        head = item; // Creating first elem
    } else { // list isn't empty
        SolarSystem* cur = head;
        // run over elements before reach place position
        int i = 0;
        while (i < place - 1 && cur->next != nullptr) {
            cur = cur->next;
            i++;
        }
        if (place == 0) { // Add element in list as first
            item->next = head;
            head = item;
        }
        else { // Add an element to any position except the first
            item->next = cur->next;
            cur->next = item;
        }
    }
    return head;
}

// Remove Elem from list by num
void removeItemList(SolarSystem *&head, const int place) {
    SolarSystem* pc = head;
    SolarSystem* pp = head;
    if (place == 0) {
        pp = pc->next;
        head = pp; // shifting head
    }
    else {
        int i = 0;
        while (i < place && pc != nullptr) {
            pp = pc;
            pc = pc->next; // going to next
            i++;
        }
        if (pc != nullptr)
            pp->next = pc->next;
    }
    delete pc;
    return;
}

SolarSystem* showMaxValue(SolarSystem* head) {
    SolarSystem* p = head;
    SolarSystem* cur = nullptr;
    double maxValue = head->planetDiameter + head->planetNum;

    while (p->next != nullptr) {
        p = p->next;
        if (maxValue < p->planetDiameter + p->planetNum) {
            maxValue = p->planetDiameter + p->planetNum;
            cur = p;
        } else {
            continue;
        }
    }
    return cur;
}

void showElement(SolarSystem* elem) {
    std::cout << "# MAX VALUE IS \n"
        << "\taddress: " << std::hex << elem << " | "
        << "N_" << std::dec << elem->planetNum << " | "
        << "Name: " << std::dec << elem->planetName << " | "
        << "D = " << std::dec << elem->planetDiameter << " |\n";
}