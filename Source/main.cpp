#include "appointments.h"

Appointment a;
void userInterface();

//main function
int main() 
{

Node* phead = NULL; 
Node* dhead = NULL;
Node* aHead = NULL;

userInterface();


return 0;
} 

void userInterface()
{
	a: 
	int input, input2;
	do{
		
		cout<<endl<<"-----Main Menu-------"<<endl;
		cout<<"To add a doctor to the database, enter 1"<<endl;
		cout<<"To display all available doctors, enter 2"<<endl;
		cout<<"To display all of today's patients, enter 3"<<endl;
		cout<<"To create an appointment, enter 4"<<endl;
		cout<<"To search for a doctor, enter 5"<<endl;
		cout<<"To search for a patient, enter 6"<<endl;
		cout<<"To delete a doctor from the database, enter 7"<<endl;
		cout<<"To delete an appointment, enter 8"<<endl;
		cin >> input;

		if(input==1)
		{	
			do {
				d.createDoctor();
				cout<<"To add another doctor, enter 1"<<endl<<"Enter anything else to go back"<<endl;
				cin >> input2;

				if(input2 != 1) goto a;

			}while(input2==1);
		} 
		else if(input==2) 
		{
			d.displayAll();
			goto a;
		}
			else if(input==3)
			{
				p.displayAll();
				goto a;
			}
			else if(input==4)
			{
				a.createAppointment();
				goto a;
			} 
			else if(input==5)
			{
				int id;
				cout<<"Enter the ID of the doctor you would like to search for: ";
				cin >> id;
				d.displayInfo(d.dhead, id);
				goto a;
			}
			else if(input==6)
			{
				int id;
				cout<<"Enter the ID of the patient you would like to search for: ";
				cin >> id;
				p.displayInfo(p.phead, id);
				goto a;
			}
			else if(input==7)
			{
				int id;
				cout<<"Enter the ID of the doctor you would like to delete: ";
				d.deleteDoctor(&d.dhead, id);
				goto a;
			} 
			else if(input==8)
			{
				int id;
				cout<<"Enter the ID of the patient you would like to delete: ";
				cin >> id;
				p.deletePatient(&p.phead, id);
				cout<<"Appointment with patient of ID "<<id<<" has been deleted"<<endl;
				goto a;
			}
	}while(input!=1 || input!=2 || input!=3 || input!=4 || input!=5 || input!=6 || input!=7);
}