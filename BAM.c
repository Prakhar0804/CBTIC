// Bank Account Management System

#include <stdio.h>
#include <string.h>

// Define a structure to represent a bank account
typedef struct {
    char accountNumber[20];  // Unique account number
    char accountHolder[50];  // Name of the account holder
    float balance;           // Current balance in the account
    char accountType[20];    // Type of account (Savings or Current)
    float interestRate;      // Interest rate for Savings account
} BankAccount;

// Function to create a new bank account
void createAccount(BankAccount* account) {
    // Get account details from the user
    printf("Enter account number: ");
    scanf("%s", account->accountNumber);
    printf("Enter account holder's name: ");
    scanf("%s", account->accountHolder);
    printf("Enter initial balance: ");
    scanf("%f", &account->balance);
    printf("Enter account type (Savings/Current): ");
    scanf("%s", account->accountType);

    // Set interest rate for Savings account
    if (strcmp(account->accountType, "Savings") == 0) {
        account->interestRate = 0.05;  // 5% interest rate for Savings account
    } else {
        account->interestRate = 0.0;  // No interest rate for Current account
    }
}

// Function to deposit funds into an account
void deposit(BankAccount* account, float amount) {
    // Add the deposit amount to the account balance
    account->balance += amount;
    printf("Deposit successful. New balance: %.2f\n", account->balance);
}

// Function to withdraw funds from an account
void withdraw(BankAccount* account, float amount) {
    // Check if the account has sufficient balance
    if (account->balance >= amount) {
        // Subtract the withdrawal amount from the account balance
        account->balance -= amount;
        printf("Withdrawal successful. New balance: %.2f\n", account->balance);
    } else {
        printf("Insufficient balance\n");
    }
}

// Function to check account balance
void checkBalance(BankAccount* account) {
    printf("Account balance: %.2f\n", account->balance);
}

// Function to calculate interest for a Savings account
void calculateInterest(BankAccount* account) {
    // Check if the account is a Savings account
    if (strcmp(account->accountType, "Savings") == 0) {
        // Calculate the interest amount
        float interest = account->balance * account->interestRate;
        // Add the interest amount to the account balance
        account->balance += interest;
        printf("Interest added. New balance: %.2f\n", account->balance);
    } else {
        printf("No interest applicable for Current account\n");
    }
}

int main() {
    BankAccount account;
    int choice;

    // Create a new bank account
    createAccount(&account);

    while (1) {
        // Display the menu options
        printf("Bank Account Management System\n");
        printf("1. Deposit\n");
        printf("2. Withdraw\n");
        printf("3. Check Balance\n");
        printf("4. Calculate Interest\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Handle the user's choice
        switch (choice) {
            case 1:
                // Deposit funds into the account
                float depositAmount;
                printf("Enter amount to deposit: ");
                scanf("%f", &depositAmount);
                deposit(&account, depositAmount);
                break;
            case 2:
                // Withdraw funds from the account
                float withdrawAmount;
                printf("Enter amount to withdraw: ");
                scanf("%f", &withdrawAmount);
                withdraw(&account, withdrawAmount);
                break;
            case 3:
                // Check the account balance
                checkBalance(&account);
                break;
            case 4:
                // Calculate interest for the Savings account
                calculateInterest(&account);
                break;
            case 5:
                // Exit the program
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}