
#ifndef PART_H
#define PART_H

#include <iostream>
#include <string>
#include <iomanip>
#include "Date.h"
using namespace std;


class Part {

	friend ostream& operator<<(ostream& out, Part&);

	public:
		//constructor
		Part(string);
		virtual ~Part();


		//getters
		string getName();

		//other
		void addFlightHours(int);
		void install(Date&);

		//virtual
		virtual bool inspection(Date)=0;

	protected:

		string name;
		Date installationDate;
		int flighthours;

};

class FH_Part : virtual public Part {

	public:
		//constructor
		FH_Part(string,int);
		~FH_Part();
		//virtual
		virtual bool inspection(Date);

	protected:

		int fh_inspect;

};

class IT_Part : virtual public Part {

	public:
		//constructor
		IT_Part(string,int);
		~IT_Part();
		//virtual
		virtual bool inspection(Date);

	protected:

		int it_inspect;

};

class FHIT_Part : public FH_Part , public IT_Part {

	public:
		//constructor
		FHIT_Part(string,int,int);
		~FHIT_Part();
		//virtual
		virtual bool inspection(Date);

};
#endif
