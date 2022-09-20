
#include "Airline.h"
//constructor
Airline::Airline(string t){
	name = t;
}
//destructor
Airline::~Airline(){
	for (int i = 0; i < parts.getSize();i++){
		delete parts[i];
	}
	for (int i = 0; i < air.getSize();i++){
		delete air[i];
	}
}

//getters
Aircraft* Airline::getAircraft(string s){
	for (int i = 0; i < air.getSize();i++){
		if (s == air[i]->getRegistration()){
			return air[i];
		}
	}
	return NULL;
}

Part* Airline::getPart(string s){
	for (int i = 0; i < parts.getSize();i++){
		if (s == parts[i]->getName()){
			return parts[i];
		}
	}
	return NULL;
}
//other
void Airline::addAircraft(string t, string r){
	Aircraft* a = new Aircraft(t,r);
	air.add(a);
}

void Airline::addPart(const string& part,int fh_inspect,int it_inspect){
	if (fh_inspect != 0 && it_inspect != 0){
		Part* p = new FHIT_Part(part,fh_inspect,it_inspect);
		parts.add(p);
	} else if (fh_inspect != 0){
		Part* p = new FH_Part(part,fh_inspect);
		parts.add(p);
	} else if (it_inspect != 0){
		Part* p = new IT_Part(part,it_inspect);
		parts.add(p);
	}
}

void Airline::takeFlight(string reg,int hours){
	for (int i = 0;i<air.getSize();i++){
		if (air[i]->getRegistration()==reg){
			air[i]->takeFlight(hours);
			return;
		}
	}
}


bool Airline::install(string reg,string n,Date& d){

	for (int i = 0;i<air.getSize();i++){
		if (air[i]->getRegistration()==reg){
			for (int j = 0;j<parts.getSize();j++){
				if (parts[j]->getName()==n){
					air[i]->install(parts[j],d);
					return true;
				}
			}
		}
	}
	return false;
}

//print functions
void Airline::printAircraft(){
	for (int i = 0; i < air.getSize();i++){
		cout << *air[i];
	}
}

void Airline::printParts(){
	for (int i = 0; i < parts.getSize();i++){
		cout << *parts[i];
	}
}

void Airline::inspectionReport(string reg, Date& d){
	for (int i = 0;i<air.getSize();i++){
		if (air[i]->getRegistration()==reg){
			Array<Part*> a;
			air[i]->inspectionReport(d,a);
			cout<< "inspection required for parts from "<< reg<<endl;
			for (int j = 0; j<a.getSize();j++){
				cout << *a[j];
			}
		}
	}
}
