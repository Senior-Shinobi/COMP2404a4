
#include "Aircraft.h"
//constructor
Aircraft::Aircraft(string t, string r){
	type = t;
	registration = r;
	flighthours = 0;
}
//destructor
Aircraft::~Aircraft(){

}

//getters
string Aircraft::getRegistration(){
	return registration;
}

//other
void Aircraft::install(Part* p, Date& d){
	parts.add(p);
	p->install(d);
}

void Aircraft::takeFlight(int hours){
	flighthours += hours;
	for (int i = 0;i<parts.getSize();i++){
		parts[i]->addFlightHours(hours);
	}
}

void Aircraft::inspectionReport(Date& d,Array<Part*>& a){
	for (int i = 0;i<parts.getSize();i++){
		if (parts[i]->inspection(d)){
			a.add(parts[i]);
		}
	}
}
//overloaded ostream
ostream& operator<<(ostream& out, Aircraft& d){
	return out <<"type: "<<d.type<<endl
	<< "registration: "<<d.getRegistration()<<endl
	<< "flighthours: "<< d.flighthours<<endl;
}
