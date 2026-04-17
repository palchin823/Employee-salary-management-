#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure definition
struct Employee {
    int id;
    char name[50];
    float basic, hra, da, deductions, net;
    struct Employee* next;
};

struct Employee* head = NULL;

// Function to calculate salary
void calculateSalary(struct Employee* emp) {
    emp->hra = 0.2 * emp->basic;
    emp->da = 0.1 * emp->basic;
    emp->deductions = 0.05 * emp->basic;
    emp->net = emp->basic + emp->hra + emp->da - emp->deductions;
}

// Add employee
void addEmployee() {
    struct Employee* newEmp = (struct Employee*)malloc(sizeof(struct Employee));

    printf("Enter ID: ");
    scanf("%d", &newEmp->id);
    printf("Enter Name: ");
    scanf("%s", newEmp->name);
    printf("Enter Basic Salary: ");
    scanf("%f", &newEmp->basic);

    calculateSalary(newEmp);

    newEmp->next = head;
    head = newEmp;

    printf("Employee Added Successfully!\n");
}

// Display employees
void displayEmployees() {
    struct Employee* temp = head;

    if (temp == NULL) {
        printf("No Records Found!\n");
        return;
    }

    while (temp != NULL) {
        printf("\nID: %d", temp->id);
        printf("\nName: %s", temp->name);
        printf("\nBasic: %.2f", temp->basic);
        printf("\nHRA: %.2f", temp->hra);
        printf("\nDA: %.2f", temp->da);
        printf("\nDeductions: %.2f", temp->deductions);
        printf("\nNet Salary: %.2f\n", temp->net);
        printf("-----------------------------\n");

        temp = temp->next;
    }
}

// Search employee
void searchEmployee() {
    int id;
    printf("Enter ID to search: ");
    scanf("%d", &id);

    struct Employee* temp = head;

    while (temp != NULL) {
        if (temp->id == id) {
            printf("\nEmployee Found!\n");
            printf("Name: %s\nNet Salary: %.2f\n", temp->name, temp->net);
            return;
        }
        temp = temp->next;
    }

    printf("Employee Not Found!\n");
}

// Delete employee
void deleteEmployee() {
    int id;
    printf("Enter ID to delete: ");
    scanf("%d", &id);

    struct Employee *temp = head, *prev = NULL;

    if (temp != NULL && temp->id == id) {
        head = temp->next;
        free(temp);
        printf("Employee Deleted!\n");
        return;
    }

    while (temp != NULL && temp->id != id) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Employee Not Found!\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("Employee Deleted!\n");
}

// Main function
int main() {
    int choice;

    while (1) {
        printf("\n==== Employee Salary Management System ====\n");
        printf("1. Add Employee\n");
        printf("2. Display Employees\n");
        printf("3. Search Employee\n");
        printf("4. Delete Employee\n");
        printf("5. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addEmployee(); break;
            case 2: displayEmployees(); break;
            case 3: searchEmployee(); break;
            case 4: deleteEmployee(); break;
            case 5: exit(0);
            default: printf("Invalid Choice!\n");
        }
    }

    return 0;
}