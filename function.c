/*
 *              functions.c
 *      Created on: Aug 22, 2023
 *       Author: EBRAHIM BENZEMA
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"std_types.h"
#include"headers.h"

const char slots[MAX_SLOTS][20] = {"1- 2pm->2:30pm","2- 2:30pm->3pm","3- 3pm->3:30pm","4- 3:30pm->4pm","5- 4pm->4:30pm"};

typedef struct s{
	u32 patientID;
	char slot[20];
} Reservation;

typedef struct p {
	u32 id;
	u32 age;
	char name[MAX_NAME_LENGTH];
	char gender;
} patients;
	patients patientsArray[MAX_PATIENTS];
	Reservation reservationsArray[MAX_SLOTS];

u32 numPatients = 0;

void add_new_patient() {
	if (numPatients == MAX_PATIENTS) {
		printf("\n  Maximum number of patients reached. Cannot add more.\n");
		return;
	}

	patients newpatient;
	printf("\nEnter patient information:\n\n");
	printf("    Name: ");
	scanf(" %s", newpatient.name);
	printf("    Age: ");
	scanf("%u", &newpatient.age);
	printf("    Gender (M/F): ");
	scanf(" %c", &newpatient.gender);
	printf("    ID: ");
	scanf("%u", &newpatient.id);

	for (int i = 0; i < numPatients; i++) {
	if(newpatient.id==patientsArray[i].id){
		printf("\n  ****Patient with the same ID already exists. Cannot add.****\n");
		return;
	}
}

    patientsArray[numPatients] = newpatient;
    numPatients++;
    printf("||  ^_^ Patient record added successfully ^_^ ||.\n");
}

void edit_patient() {
    u32 id;
    printf("\nEnter patient ID to edit: ");
    scanf("%u", &id);

    for (int i = 0; i < numPatients; i++) {
        if (id == patientsArray[i].id) {
            printf("   Patient found. Enter new information:\n");
            printf("        Name: ");
            scanf(" %s", patientsArray[i].name);
            printf("        Age: ");
            scanf("%u", &patientsArray[i].age);
            printf("        Gender (M/F): ");
            scanf(" %c", &patientsArray[i].gender);
            printf("\n  DONE! Patient record updated successfully.\n");
            return;
	}
}
    printf("\nIncorrect patient ID. Patient not found.\n");
}

u32 numReservations = 0;

void reverse_slot() {
	if (numReservations == MAX_SLOTS) {
		printf("\nAll slots are already reserved.\n");
		return;
	}
	printf("\nAvailable slots:\n");
	printAvailableSlots();
	u32 patientID;
	char slot[20];
	printf("\nEnter patient ID for reservation: ");
	scanf("%u", &patientID);
	for (int i = 0; i < numReservations; i++) {
		if (patientID == reservationsArray[i].patientID) {
			printf("\nPatient already has a reservation. Cannot reserve again.\n");
			return;
		}
	}
	for (int i = 0; i < numPatients; i++) {
            u32 choice1;
	if(patientID==patientsArray[i].id){
		printf("\n      Enter your choice : ");
        scanf(" %u", &choice1);
        if (choice1 < 1 || choice1 > MAX_SLOTS) {
		printf("\n      Invalid slot choice. Please choose a slot within the available range.\n");
		return;
	}
        strcpy(slot, slots[choice1 - 1]);
            for (int i = 0; i < numReservations; i++) {
            if (strcmp(slot, reservationsArray[i].slot) == 0) {
                printf("\n      Slot already reserved. Please choose another slot.\n");
                return;
            }
        }
        reservationsArray[numReservations].patientID = patientID;
        strcpy(reservationsArray[numReservations].slot, slot);
        numReservations++;
        printf("\n      Reservation made successfully.\n");
            return;

    }

	}
            printf("\n      ID is not founded\n");
            return;
}


void cancel_Reservation() {
    u32 patientID;
    printf("\n   Enter patient ID to cancel reservation: ");
    scanf("%u", &patientID);

    u32 found = 0;
    for (int i = 0; i < numReservations; i++) {
        if (patientID == reservationsArray[i].patientID) {
            printf("\n      Reservation found and canceled successfully.\n");
            for (int j = i; j < numReservations - 1; j++) {
                reservationsArray[j] = reservationsArray[j + 1];
            }
            numReservations--;
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("\n  No reservation found for the patient ID.\n");
        }
}



void viewTodayReservations() {
    printf("\nToday's Reservations:\n");
    if (numReservations == 0) {
        printf("\n  No reservations for today.\n");
        return;
    }

    for (int i = 0; i < numReservations; i++) {
        printf("\nSlot: %s, Patient ID: %d\n", reservationsArray[i].slot,reservationsArray[i].patientID);
    }
}




void printAvailableSlots() {
    for (int i = 0; i < MAX_SLOTS; i++) {
        u32 reserved = 0;
        for (int j = 0; j < numReservations; j++) {
            if (strcmp(slots[i], reservationsArray[j].slot) == 0) {
                reserved = 1;
                break;
            }
        }
        if (!reserved) {
            printf("%s\n", slots[i]);
        }
    }
}



void viewPatientRecord() {
    u32 id;
    printf("\nEnter patient ID to view record: ");
    scanf("%u", &id);

for (int i = 0; i < numPatients; i++) {
	if (id == patientsArray[i].id) {
		printf("\n  Patient Information:\n");
		printf("        Name: %s\n", patientsArray[i].name);
		printf("        Age: %d\n", patientsArray[i].age);
		printf("        Gender: %c\n", patientsArray[i].gender);
		printf("        ID: %d\n", patientsArray[i].id);
		return;
	}
}

    printf("\n  Incorrect patient ID. Patient not found.\n");
}
