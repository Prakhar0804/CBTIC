//EXPENSE TRACKER 

#include <stdio.h>
#include <string.h>

#define MAX_EXPENSES 100

// Data structure to represent an expense
typedef struct {
    char date[10];         // date of expense (YYYY-MM-DD)
    char category[20];     // category of expense (e.g., "Food", "Transportation")
    float amount;          // expense amount
} Expense;

// Array to store expenses
Expense expenses[MAX_EXPENSES];
int numExpenses = 0;

// Function to display menu
void displayMenu() {
    printf("Expense Tracker\n");
    printf("1. Add Expense\n");
    printf("2. View Expenses\n");
    printf("3. Generate Report\n");
    printf("4. Exit\n");
    printf("Choose an option: ");
}

// Function to add expense
void addExpense() {
    if (numExpenses >= MAX_EXPENSES) {
        printf("Expense limit reached. Please delete some expenses before adding new ones.\n");
        return;
    }

    printf("Enter date (YYYY-MM-DD): ");
    scanf("%s", expenses[numExpenses].date);

    printf("Enter category: ");
    scanf("%s", expenses[numExpenses].category);

    printf("Enter amount: ");
    scanf("%f", &expenses[numExpenses].amount);

    numExpenses++;
}

// Function to view expenses
void viewExpenses() {
    printf("Expenses:\n");

    for (int i = 0; i < numExpenses; i++) {
        printf("%s - %s: $%.2f\n", expenses[i].date, expenses[i].category, expenses[i].amount);
    }
}

// Function to generate report
void generateReport() {
    float total = 0;
    float maxCategoryAmount = 0;
    char maxCategory[20];

    for (int i = 0; i < numExpenses; i++) {
        total += expenses[i].amount;

        if (expenses[i].amount > maxCategoryAmount) {
            maxCategoryAmount = expenses[i].amount;
            strcpy(maxCategory, expenses[i].category);
        }
    }

    printf("Total expenses: $%.2f\n", total);
    printf("Max category: %s ($%.2f)\n", maxCategory, maxCategoryAmount);
}

int main() {
    int choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addExpense();
                break;
            case 2:
                viewExpenses();
                break;
            case 3:
                generateReport();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
