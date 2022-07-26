#ifndef DOCTORS_H
#define DOCTORS_H
#include "common.h"


struct Node 
{
//data
	int id, bday, bmonth, byear;
	string mobile, first_name, last_name, email, lastVisitDate ;
	string full_name = first_name + " " + last_name;

//pointer to the next node in the list
	Node* next;
};

class Doctor
{

public:
	Node *dhead, *dtail;
	bool avail = true;
	Doctor() {
	dhead = NULL;
	dtail = NULL;
	}


	 int createDoctor() //creates a doctor by asking user for information
	{
		Node *temp = new Node;
		

		//user entered data
		cout<<"Doctor's Information: "<<endl;
 		cout<<endl<<"First name: ";
 		cin >> temp -> first_name;
 		cout<<endl
 		<<"Last name: ";
 		cin >> temp -> last_name;
 		cout<<endl;
 		cout<<"Mobile: ";
 		cin >> temp -> mobile;
 		cout<<endl
 		<<"Birth month (ex. 12): ";
 		cin >> temp -> bmonth;
 		cout<<endl
 		<<"Birth day (Ex. 6): ";
 		cin >> temp->bday;
 		cout<<endl
 		<<"Birth year (ex. 1998): ";
 		cin >> temp -> byear; 
 		cout<<endl<<"Dr. " << temp -> first_name << " " << temp -> last_name <<" has been created with ID ";
		
		int code = 0;
		Node* current = dhead;

		temp -> next = NULL;

		if(dhead==NULL){
			dhead = temp;
			dtail = temp;
			temp = NULL;
			code = 1;
			dhead -> id = code;
			cout<<dhead->id<<endl<<endl;
		} else{

			dtail -> next = temp;
			dtail = temp;
         
        while(current != NULL)
		{
			code++;
			if(current == temp) 
			{
			temp -> id = code;
			cout<<temp->id<<endl<<endl;
			}	

			current = current->next;
		}                                                                     
		}
		return code;
	}

string getDName(struct Node* dhead, int x) //function that returns the doctor's name given their ID
{
	Node *temp = dhead;
	while(temp != NULL)
	{
		if(temp -> id == x){
		string name = temp -> first_name + " " + temp->last_name;
		return name;
		} 
		temp = temp->next;
	}
} 

bool checkAvail(struct Node* dhead, int id) //checks if Dr. is free, true until falsified in the appointments class
{
	return true;
}

int getCount() //gets the number of doctors in the system
{
	int count =0;
	Node* current = dhead;
	while(current!=NULL)
	{
		count++;
		current = current -> next;
	}
	return count;
}
int doctorN = getCount();


/*	bool checkID(struct Node* dhead, int x) //checks if entered ID already exists, again extra
	{ 
		Node *temp = dhead;
		
		if(dhead == NULL) return true;

		while(temp!=NULL){
		if(temp->id == x){
			cout<<"ID already exists, try again."<<endl;
			return false;
		}
		temp = temp->next;
		}
		return true;
	}
*/	


	bool searchID(struct Node* dhead, int x) //does doctor exist?
	{ 
		if(dhead == NULL) {
		return false;
		}	

		if (dhead -> id == x) {
			return true;
		}

			searchID(dhead->next, x);
	}


	void displayInfo(struct Node* dhead, int x) //displays all information available on a doctor
	{ 
		
		if (dhead -> id == x) {
			cout<<endl<<"Name: "<<dhead->first_name <<" "<<dhead -> last_name<<endl;
			cout<<"ID: "<<dhead->id<<endl;
			cout<<"Mobile: "<<dhead->mobile<<endl;
			cout<<"Birthday: "<<dhead->bday<<"/"<<dhead->bmonth<<"/"<<dhead->byear<<endl;
			cout<<"Age: "<<2020-dhead->byear<<endl<<endl;
			
			return;
		}
		if(dhead->next==NULL)
		{
			cout<<"Doctor with ID "<<x<<" is not on the system";
			return;
		}
		displayInfo(dhead->next, x); //recursion
		}



	void deleteDoctor(struct Node **dhead_ref, int key) //deletes a doctor
	{
		struct Node *temp = *dhead_ref, *prev;
		if(temp != NULL && temp->id == key)
		{
			*dhead_ref = temp->next;
			free(temp);
			return;
		}
		while(temp != NULL && temp->id != key){
			prev = temp;
			temp = temp->next;
		}
		if(temp == NULL)
			return;

		prev -> next = temp -> next;
		free(temp);

	}

	
	void deleteDuplicate() //extra. could be used to ensure IDs aren't repeated
	{
		Node *ptr1, *ptr2, *duplicate;
		ptr1 = dhead;

		while(ptr2->next != NULL)
		{
			if(ptr1->id == ptr2->next->id) {
				duplicate = ptr2 -> next;
				ptr2->next = ptr2->next->next;
				delete(duplicate);
			} else {
				ptr2 = ptr2 -> next;
			}
			ptr1=ptr1->next;
		}
	}

	void displayAll() //displays all available doctors
	{ 
		Node *temp = new Node;
		temp = dhead;

		if(temp == NULL){
			cout<<endl<<"No doctors to display."<<endl;
		}
		while(temp != NULL){
			cout<<endl<<"ID: "<<temp->id<<endl;
			cout<<"Name: "<<temp->first_name <<" "<<temp->last_name<<endl;

			temp = temp -> next;
		}
	}

	
};


#endif
