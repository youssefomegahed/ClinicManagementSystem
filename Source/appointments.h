#ifndef APPOINTMENTS_H
#define APPOINTMENTS_H
#include "common.h"
#include "doctors.h"
#include "patients.h"

Doctor d;
Patient p;

//forward declarations
struct Node;
class Doctor;
class Patient;

class Appointment : public Doctor, public Patient
{
public: 
int hour = 9; //time starts at 9am
int dCount=1; //initial doctor ID
int appCount=48; //appointment count (subtracts by 1 in the function below until it meets with the number of available doctors (maximum case))
char input;



void createAppointment() //function that creates an appointment, or more than one at once
{
	if(d.searchID(d.dhead, dCount)==false) //if no doctors are found in the system, uses bool function from doctors.h
	{
		cout<<"No doctors in the system. Please add a doctor first"<<endl;
		return;
	}

do {
	int x = p.createPatient(); //createPatient function returns an integer (the ID of the patient), this stores it in x.
	
	if(x>appCount) //if the patient ID (number of patients since the IDs are in order) is greater than the number of possible appointments, exit the function.
	{
			cout<<"No availability..";
			return;
	}

	do{	

		if(d.checkAvail(d.dhead, dCount) == true) { //check if doctor is available using bool function from doctors.h
			cout<<"Appointment created."<<endl //if true, create appointment.
			<<"Patient "<<p.getPName(p.phead, x) <<" with ID "<<x<<" is scheduled with Dr. "<<d.getDName(d.dhead,dCount) <<" with ID "<<dCount<<" from "<<hour<<" O'Clock to "<<hour+1<<" O'Clock."<<endl;
			d.checkAvail(d.dhead,dCount)==false; //doctor is now unavailable in this hour!
			dCount++; //the doctor that is next in line will now be dCount.
			break; //breaks out of the loop
		}
		else 
		{
			dCount++; //the doctor that is next in line

			if((dCount == appCount)|| (d.searchID(d.dhead,dCount)==false)) //if all available doctors run out in an hour, move patients to the next hour.
			{
				hour++; //next hour
				if(hour>23) //if we got all the way to 11pm, return
				{
					cout<<"No availability";
					return;
				}
			
			} 
			
		}


	}while(d.checkAvail(d.dhead, dCount) == false); //keep repeating until all doctors have been occupied in the hour

		appCount--; //countdown appointment count

		if(d.searchID(d.dhead,dCount)==false) //if doctors run out in an hour, move to the next hour
		{
			hour++;
			if(hour>11)
			{
				cout<<"No availability";
				return;
			}
			dCount = 1; // start occupying doctor with ID 1 again.
		}
	
		cout<<endl<<"Would you like to create another appointment? Y/N"<<endl; //option to add another appointment quickly
		
		cin >> input;

		if(input != 'Y' && input != 'y') return;


} while (input == 'Y' || input == 'y');
	}



};

#endif