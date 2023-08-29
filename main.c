/*
 *              main.c
 *      Created on: Aug 22, 2023
 *       Author: EBRAHIM BENZEMA
*/

#include <stdio.h>
#include <stdlib.h>
#include "std_types.h"
#include "headers.h"

int main() {
    u32 passwordAttempts = 0;
    int flage = 1, flage1 = 1, flage2 = 1;

    while (flage2) {
        u32 mode;
        printf("\n\n/////////// Welcome to the Clinic Management System!///////////\n\n");
        printf("Choose a mode:\n\n");
        printf("    1. Admin Mode\n");
        printf("    2. User Mode\n");
        printf("    3. Exit:\n\n");
        printf("Enter your choice: ");
        scanf("%u", &mode);

        switch (mode) {
            case 1: {
                char password[20];
                passwordAttempts = 0;

                while (passwordAttempts < 3) {
                    printf("\nEnter password: ");
                    scanf("%s", password);

                    if (strcmp(password, "1234") == 0) {
                        printf("\n      Access granted. Welcome to Admin Mode!\n\n");
                        while (flage) {
                            u32 choice;
                            printf("\n/////////// Admin Menu ///////////\n");
                            printf("    1. Add new patient record\n");
                            printf("    2. Edit patient record\n");
                            printf("    3. Reserve a slot with the doctor\n");
                            printf("    4. Cancel reservation\n");
                            printf("    5. Exit admin mode\n");
                            printf("Enter your choice: ");
                            scanf("%u", &choice);

                            switch (choice) {
                                case 1:
                                    add_new_patient();
                                    break;
                                case 2:
                                    edit_patient();
                                    break;
                                case 3:
                                    reverse_slot();
                                    break;
                                case 4:
                                    cancel_Reservation();
                                    break;
                                case 5:
                                    printf("\n  Exiting Admin Mode...\n");
                                    flage = 0;
                                    flage1=1;
                                    break;
                                default:
                                    printf("\n  Invalid choice. Please try again.\n");
                                    break;
                            }
                        }
                        break;
                    } else {
                        passwordAttempts++;
                        printf("\n  Incorrect password. Attempts remaining: %d\n", 3 - passwordAttempts);
                    }
                }

                if (passwordAttempts == 3) {
                    printf("\n  Too many incorrect attempts. Exiting...\n");
                    break;
                }
                break;
            }
            case 2: {
                printf("\n   /////////// Welcome to User Mode! ///////////\n");
                while (flage1) {
                    u32 choice;
                    printf("\n /////////// User Menu ///////////\n");
                    printf("    1. View patient record\n");
                    printf("    2. View today's reservations\n");
                    printf("    3. Exit user mode\n");
                    printf("Enter your choice: ");
                    scanf("%u", &choice);

                    switch (choice) {
                        case 1:
                            viewPatientRecord();
                            break;
                        case 2:
                            viewTodayReservations();
                            break;
                        case 3:
                            printf("\n  Exiting User Mode...\n");
                            flage1 = 0;
                            flage=1;
                            break;
                        default:
                            printf("\n  Invalid choice. Please try again.\n");
                            break;
                    }
                }
                break;
            }
            case 3:
                printf("\n  thank you \n");
                flage2 = 0;
                break;
            default:
                printf("\n  Invalid choice!\n");
                break;
        }
    }

    return 0;
}
