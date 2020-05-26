#include<bits/stdc++.h>
#include "Aircrew.h"
using namespace std;

Aircrew::Aircrew(string n_m):nm(n_m),flightsTaken(0),hoursWorked(0.0){
}

Aircrew* Aircrew::makeAircrew(char ch, std::string name_str){
	if(ch=='P'){
		return new Pilot(name_str);
	}
	else if(ch=='A'){
		return new Attendant(name_str);
	}
	else if(ch=='T'){
		return new TaggedAttendant(name_str);
	}
	else{
		return NULL;
	}
}

void Aircrew::setFlights(int i){
	flightsTaken=i;
	return;
}

void Aircrew::setHours(double h){
	hoursWorked = h;
	return ;
}

const std::string Aircrew::name(void) const{
	return nm;
}


const double Aircrew::maxHours(void) const
{
	double val=60.0;
	return val;
}

void Aircrew::print(void) const{
	cout<<type()<<": "<<name()<<" "<<"has operated "<<flightsTaken<<" flights for a total of "
	<<hoursWorked<<" hours this week"<<endl;
	cout<<"Available flights: "<<maxFlights()-flightsTaken<<endl;
	cout<<"Available hours: "<<maxHours()-hoursWorked<<endl;
}

void Aircrew::scheduleFlight(int f, double h) const{
	cout<<"Attempting to schedule for "<<f<<" stop(s) "<<h<<" hours flight..."<<endl;
	if((f+1)<=(maxFlights()-flightsTaken) and (h)<=(maxHours()-hoursWorked)){
		cout<<"This crew member can be scheduled"<<endl;
	}
	else{
		cout<<"This crew member should be replaced"<<endl;
	}
}

Aircrew::~Aircrew(void){

}

//Pilot,Attendant,TaggedAttendant
Pilot::Pilot(std::string name_str):Aircrew(name_str){
}
Attendant::Attendant(std::string name_str):Aircrew(name_str){
}
TaggedAttendant::TaggedAttendant(std::string name_str):Aircrew(name_str){
}
const std::string Pilot::type(void) const{
	return "Pilot";
}
const std::string Attendant::type(void) const{
	return "Attendant";
}
const std::string TaggedAttendant::type(void) const{
	return "TaggedAttendant";
}
const int Pilot::maxFlights(void) const{
	int m = 5;
	return m;
}

const int Attendant::maxFlights(void) const{
	int m = 8;
	return m;
}
const int TaggedAttendant::maxFlights(void) const{
	int m = 8;
	return m;
}

void TaggedAttendant::scheduleFlight(int f, double h) const{
	cout<<"Attempting to schedule for "<<f<<" stop(s) "<<h<<" hours flight..."<<endl;
	if((f+1)<=(maxFlights()-flightsTaken) and (h/2)<=(maxHours()-hoursWorked)){
		cout<<"This crew member can be scheduled"<<endl;
	}
	else{
		cout<<"This crew member should be replaced"<<endl;
	}
}