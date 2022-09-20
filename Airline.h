
#ifndef AIRLINE_H
#define AIRLINE_H

#include <iostream>
#include <string>
#include <iomanip>
#include "Part.h"
#include "Array.h"
#include "Date.h"
#include "Aircraft.h"

using namespace std;

class Airline {

	public:
		//constructor
		Airline(string);
		~Airline();

		//getters
		//other
		void addAircraft(string,string);
		void addPart(const string& part,int fh_inspect,int it_inspect);
		void takeFlight(string reg,int hours);
		void printAircraft();
		void printParts();
		void inspectionReport(string reg,Date&);
		bool install(string,string,Date&);

	private:
		//functions
		Aircraft* getAircraft(string);
		Part* getPart(string);
		//variables
		string name;
		Array<Aircraft*> air;
		Array<Part*> parts;

};
#endif
