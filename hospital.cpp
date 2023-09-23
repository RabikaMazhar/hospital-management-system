#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#define MAX_PATIENTS 100
typedef struct {
char name[50];
int id;
int age;
char gender[10];
char address[100];
char phone[15];
char checkInTime[20];
char checkOutTime[20];
char appointment[50];
} Patient;
Patient patients[MAX_PATIENTS];
int patientCount = 0;
int isNumeric(const char* str) {
for (int i = 0; str[i] != '\0'; i++) {
if (!isdigit(str[i])) {
return 0;
}
}
return 1;
}
void registerPatient() {
if (patientCount >= MAX_PATIENTS) {
printf("Maximum patient capacity reached.\n");
return;
}
Patient newPatient;
printf("Enter patient name: ");
scanf("%s", newPatient.name);
for (int i = 0; newPatient.name[i] != '\0'; i++) {
if (!isalpha(newPatient.name[i])) {
printf("Invalid name. Name should only contain alphabetic characters.\n");
return;
}
}
printf("Enter patient ID: ");
while (scanf("%d", &(newPatient.id)) != 1) {
printf("Invalid input. Please enter a numeric ID.\n");
// Clear input buffer
while (getchar() != '\n')
continue;
}
printf("Enter patient age: ");
while (scanf("%d", &(newPatient.age)) != 1) {
printf("Invalid input. Please enter a numeric age.\n");
// Clear input buffer
while (getchar() != '\n')
continue;
}
printf("Enter patient gender: ");
scanf("%s", newPatient.gender);
printf("Enter patient address: ");
getchar();
fgets(newPatient.address, sizeof(newPatient.address), stdin);
newPatient.address[strcspn(newPatient.address, "\n")] = '\0';
printf("Enter patient phone number: ");
while (scanf("%s", newPatient.phone) != 1) {
printf("Invalid input. Please enter a numeric phone number.\n");
// Clear input buffer
while (getchar() != '\n')
continue;
}
patients[patientCount++] = newPatient;
printf("Patient registered successfully.\n");
}
void savePatientData() {
FILE *file = fopen("patient_data.txt", "w");
if (file == NULL) {
printf("Error opening file.\n");
return;
}
for (int i = 0; i < patientCount; i++) {
fprintf(file, "Patient Name: %s\n", patients[i].name);
fprintf(file, "Patient ID: %d\n", patients[i].id);
fprintf(file, "Patient Age: %d\n", patients[i].age);
fprintf(file, "Patient Gender: %s\n", patients[i].gender);
fprintf(file, "Patient Address: %s\n", patients[i].address);
fprintf(file, "Patient Phone: %s\n", patients[i].phone);
fprintf(file, "Check-in Time: %s", patients[i].checkInTime);
fprintf(file, "Appointment: %s\n", patients[i].appointment);
fprintf(file, "Check-out Time: %s", patients[i].checkOutTime);
fprintf(file, "\n");
}
fclose(file);
printf("Patient data saved successfully.\n");
}
void checkInPatient(int patientId) {
for (int i = 0; i < patientCount; i++) {
if (patients[i].id == patientId) {
time_t currentTime;
time(&currentTime);
strcpy(patients[i].checkInTime, ctime(&currentTime));
printf("Patient checked in at: %s", patients[i].checkInTime);
return;
}
}
printf("Patient not found.\n");
}
void scheduleAppointment(int patientId) {
for (int i = 0; i < patientCount; i++) {
if (patients[i].id == patientId) {
printf("Enter appointment details: ");
getchar();
fgets(patients[i].appointment, sizeof(patients[i].appointment), stdin);
patients[i].appointment[strcspn(patients[i].appointment, "\n")] = '\0';
printf("Appointment scheduled successfully for patient %s.\n", patients[i].name);
return;
}
}
printf("Patient not found.\n");
}
void processPayment(int patientId) {
for (int i = 0; i < patientCount; i++) {
if (patients[i].id == patientId) {
printf("Payment processed successfully for patient %s.\n", patients[i].name);
return;
}
}
printf("Patient not found.\n");
}
void checkOutPatient(int patientId) {
for (int i = 0; i < patientCount; i++) {
if (patients[i].id == patientId) {
time_t currentTime;
time(&currentTime);
strcpy(patients[i].checkOutTime, ctime(&currentTime));
printf("Patient checked out at: %s", patients[i].checkOutTime);
return;
}
}
printf("Patient not found.\n");
}
void generatePatientReport(int patientId) {
for (int i = 0; i < patientCount; i++) {
if (patients[i].id == patientId) {
printf("Patient Name: %s\n", patients[i].name);
printf("Patient ID: %d\n", patients[i].id);
printf("Patient Age: %d\n", patients[i].age);
printf("Patient Gender: %s\n", patients[i].gender);
printf("Patient Address: %s\n", patients[i].address);
printf("Patient Phone: %s\n", patients[i].phone);
printf("Check-in Time: %s", patients[i].checkInTime);
printf("Appointment: %s\n", patients[i].appointment);
printf("Check-out Time: %s", patients[i].checkOutTime);
return;
}
}
printf("Patient not found.\n");
}
int main() {
int choice;
int patientId;
printf("\n--- Hospital Management System ---\n");
do {
printf("1. Register a new patient\n");
printf("2. Check in a patient\n");
printf("3. Schedule an appointment\n");
printf("4. Process payment\n");
printf("5. Check out a patient\n");
printf("6. Generate patient report\n");
printf("7. Save patient data\n");
printf("8. Exit\n");
printf("Enter your choice: ");
// Input validation for integer choice
while (scanf("%d", &choice) != 1) {
printf("Invalid choice. Please enter a valid integer.\n");
// Clear input buffer
while (getchar() != '\n')
continue;
}
switch (choice) {
case 1:
registerPatient();
break;
case 2:
printf("Enter patient ID: ");
while (scanf("%d", &patientId) != 1) {
printf("Invalid input. Please enter a numeric ID.\n");
// Clear input buffer
while (getchar() != '\n')
continue;
}
checkInPatient(patientId);
break;
case 3:
printf("Enter patient ID: ");
while (scanf("%d", &patientId) != 1) {
printf("Invalid input. Please enter a numeric ID.\n");
// Clear input buffer
while (getchar() != '\n')
continue;
}
scheduleAppointment(patientId);
break;
case 4:
printf("Enter patient ID: ");
while (scanf("%d", &patientId) != 1) {
printf("Invalid input. Please enter a numeric ID.\n");
// Clear input buffer
while (getchar() != '\n')
continue;
}
processPayment(patientId);
break;
case 5:
printf("Enter patient ID: ");
while (scanf("%d", &patientId) != 1) {
printf("Invalid input. Please enter a numeric ID.\n");
// Clear input buffer
while (getchar() != '\n')
continue;
}
checkOutPatient(patientId);
break;
case 6:
printf("Enter patient ID: ");
while (scanf("%d", &patientId) != 1) {
printf("Invalid input. Please enter a numeric ID.\n");
// Clear input buffer
while (getchar() != '\n')
continue;
}
generatePatientReport(patientId);
break;
case 7:
savePatientData();
break;
case 8:
printf("Exiting...\n");
break;
default:
printf("Invalid choice. Please try again.\n");
break;
}
} while (choice != 8);
return 0;
}
