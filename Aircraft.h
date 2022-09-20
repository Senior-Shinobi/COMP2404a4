
#ifndef AIRCRAFT_H
#define AIRCRAFT_H

#include <iostream>
#include <string>
#include <iomanip>
#include "Part.h"
#include "Array.h"
#include "Date.h"

using namespace std;

class Aircraft {

	friend ostream& operator<<(ostream& out, Aircraft&);

	public:
		//constructor
		Aircraft(string,string);
		~Aircraft();

		//getters
		string getRegistration();

		//other
		void install(Part*,Date&);
		void takeFlight(int);
		void inspectionReport(Date&,Array<Part*>&);

	private:
		//variables
		int flighthours;
		string type;
		string registration;
		Array<Part*> parts;

};
#endif
