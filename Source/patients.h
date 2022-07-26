#ifndef PATIENTS_H
#define PATIENTS_H
#include "common.h"

//forward declaration
struct Node;


class Patient
{
public:
	Node *phead, *ptail;

	Patient(){
		phead = NULL;
		ptail = NULL;
	}


	 int createPatient() //creates a patient by asking user for information. returns ID of patient
	{
		Node *temp = new Node;

		//user entered data
		cout<<"Patient Information: "<<endl;
 		cout<<endl<<"First name: ";
 		cin >> temp -> first_name;
 		cout<<endl
 		<<"Last name: ";
 		cin >> temp -> last_name;
 		cout<<endl
 		<<"Mobile: ";
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
 		cout<<endl
 		<<"E-mail: ";
 		cin >> temp -> email;
 		cout<<endl
 		<<"Last visit data (DD/MM/YYYY): ";
 		cin >> temp -> lastVisitDate; 
 		cout<<endl<<"Patient " << temp -> first_name << " " << temp -> last_name <<" has been created with ID "; //confirmation message, ID is processed below

 		int code = 0;
		Node* current = phead;

		temp -> next = NULL;

		if(phead==NULL){
			phead = temp;
			ptail = temp;
			temp = NULL;
			code = 1; 
			phead -> id = code; //ID in case this is the first patient (head of the linked list)
			cout<<phead->id<<endl<<endl; //output appears as part of the confirmation message
		} else{
			ptail -> next = temp;
			ptail = temp;
       
        while(current != NULL)
		{
			code++;
			if(current == temp) 
			{
			temp -> id = code; //ID in case it is not the head
			cout<<temp->id<<endl<<endl;
			}	

			current = current->next;
		}
                                                                                 
		}
		return code; //function returns the ID of the patient

	}


string getPName(struct Node* phead, int x) //function that returns the patient's name given their ID
{
	Node *temp = phead;
	while(temp != NULL)
	{
		if(temp -> id == x){
		string name = temp -> first_name + " " + temp->last_name;
		return name;
		} 
		temp = temp->next;
	}
} 

	bool checkID(struct Node* phead, int x) //checks if entered ID already exists in the system, extra since the IDs are automated
	{ 
		Node *temp = phead;
		
		if(phead == NULL) return true;

		while(temp!=NULL){
		if(temp->id == x){
			cout<<"ID already exists, try again."<<endl;
			return false;
		}
		temp = temp->next;
		}
		return true;
	}


	void accessByID(struct Node* phead, int x) //accesses a customer given an ID
	{ 
		if(phead == NULL) {
		cout<<"Patient not found"<<endl; //case ID does not exist
		return;
		}	

		if (phead -> id == x) {
			cout<<endl<<"Name: "<<phead->first_name <<" "<<phead -> last_name<<endl;
			cout<<"ID: "<<phead->id<<endl;
			return;
		}

		accessByID(phead->next, x); //recursion
	}


	void displayInfo(struct Node* phead, int x) //displays all information available on a doctor
	{ 
		
		if (phead -> id == x) {
			cout<<endl<<"Name: "<<phead->first_name <<" "<<phead -> last_name<<endl;
			cout<<"ID: "<<phead->id<<endl;
			cout<<"Mobile: "<<phead->mobile<<endl;
			cout<<"Birthday: "<<phead->bday<<"/"<<phead->bmonth<<"/"<<phead->byear<<endl;
			cout<<"Age: "<<2020-phead->byear<<endl;
			cout<<"Last visit date: "<< phead->lastVisitDate<<endl<<endl;
			
			return;
		}
		if(phead->next==NULL)
		{
			cout<<"Patient with ID "<<x<<" is not on the system";
			return;
		}
		displayInfo(phead->next, x); //recursion
		}



	void deletePatient(struct Node **phead_ref, int key) //deletes a patient
	{
		struct Node *temp = *phead_ref, *prev;
		if(temp != NULL && temp->id == key)
		{
			*phead_ref = temp->next;
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
		ptr1 = phead;

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

	void displayAll() //displays all patients
	{ 
		Node *temp = new Node;
		temp = phead;

		if(temp == NULL){
			cout<<endl<<"No patients to display."<<endl;
		}
		while(temp != NULL){
			cout<<endl<<"ID: "<<temp->id<<endl;
			cout<<"Name: "<<temp->first_name <<" "<<temp->last_name<<endl;
			cout<<"Last visit date: "<<temp->lastVisitDate<<endl;

			temp = temp -> next;
		}
	}

	

	
};


#endif