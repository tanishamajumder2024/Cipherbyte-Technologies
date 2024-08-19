#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define MAX_CATEGORY_LENGTH 20

typedef struct {
    char category[MAX_CATEGORY_LENGTH];
    float amount;
} Expense;

void addExpense(Expense expenses[], int *count) {
    if (*count >= MAX_EXPENSES) {
        printf("Expense limit reached.\n");
        return;
    }

    printf("Enter category: ");
    scanf("%s", expenses[*count].category);
    printf("Enter amount: ");
    scanf("%f", &expenses[*count].amount);

    (*count)++;
    printf("Expense added successfully.\n");
}

void displayExpenses(Expense expenses[], int count) {
    if (count == 0) {
        printf("No expenses recorded.\n");
        return;
    }

    printf("\nExpenses:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. Category: %s, Amount: %.2f\n", i + 1, expenses[i].category, expenses[i].amount);
    }
}

void displayCategorySummary(Expense expenses[], int count) {
    if (count == 0) {
        printf("No expenses recorded.\n");
        return;
    }

    float categoryTotal[MAX_EXPENSES] = {0};
    char categories[MAX_EXPENSES][MAX_CATEGORY_LENGTH];
    int categoryCount = 0;

    for (int i = 0; i < count; i++) {
        int found = 0;
        for (int j = 0; j < categoryCount; j++) {
            if (strcmp(expenses[i].category, categories[j]) == 0) {
                categoryTotal[j] += expenses[i].amount;
                found = 1;
                break;
            }
        }
        if (!found) {
            strcpy(categories[categoryCount], expenses[i].category);
            categoryTotal[categoryCount] += expenses[i].amount;
            categoryCount++;
        }
    }

    printf("\nCategory Summary:\n");
    for (int i = 0; i < categoryCount; i++) {
        printf("Category: %s, Total Amount: %.2f\n", categories[i], categoryTotal[i]);
    }
}

int main() {
    Expense expenses[MAX_EXPENSES];
    int count = 0;
    int choice;

    while (1) {
        printf("\nExpense Tracker\n");
        printf("1. Add Expense\n");
        printf("2. Display Expenses\n");
        printf("3. Display Category Summary\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addExpense(expenses, &count);
                break;
            case 2:
                displayExpenses(expenses, count);
                break;
            case 3:
                displayCategorySummary(expenses, count);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0; 
}
