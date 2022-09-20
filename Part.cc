
#include "Part.h"

//part class
Part::Part(string n){
	name = n;
	flighthours = 0;

}

Part::~Part(){

}

void Part::addFlightHours(int d){
	flighthours+=d;
}

void Part::install(Date& d){
	installationDate = d;
}

//getters
string Part::getName(){
	return name;
}

//other
ostream& operator<<(ostream& out, Part& d){
	return out <<"Part: "<< d.getName()<<endl
	<<"flighthours: "<<d.flighthours<<", "<<endl
	<<"inspection date: " << d.installationDate<<endl;
}

//FH_Part class

FH_Part::FH_Part(string n, int i): Part(n){
	name = n;
	fh_inspect = i;
}

FH_Part::~FH_Part(){

}

bool FH_Part::inspection(Date d){
	return (flighthours>= fh_inspect);
}

//IT_Part class

IT_Part::IT_Part(string n, int i) : Part(n){
	name = n;
	it_inspect = i;
}

IT_Part::~IT_Part(){

}

bool IT_Part::inspection(Date d){

	return ((d.toDays() - installationDate.toDays()) >= it_inspect);
}

//FHIT_Part class

FHIT_Part::FHIT_Part(string n, int f, int i) : Part(n),FH_Part(n,f),IT_Part(n,i){
	name = n;
	fh_inspect = f;
	it_inspect = i;
}

FHIT_Part::~FHIT_Part(){

}

bool FHIT_Part::inspection(Date d){

	return (FH_Part::inspection(d) || IT_Part::inspection(d));
}
