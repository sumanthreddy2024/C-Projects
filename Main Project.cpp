#include <stdio.h>
#include <string.h>

#define MAX_FRIENDS 100
#define MAX_NAME_LENGTH 50
#define MAX_EXPENSES 100
#define MAX_CATEGORIES 5
#define MAX_DESCRIPTION_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    float initialAmount;
    float totalSpent;
    float remainingBalance;
} Friend;

typedef struct {
    char category[MAX_DESCRIPTION_LENGTH];
    float amount;
    float individualShare[MAX_FRIENDS];
    char description[MAX_DESCRIPTION_LENGTH];
} Expense;

void inputFriendDetails(Friend friends[], int *friendCount);
void inputExpenseDetails(Friend friends[], int friendCount, Expense expenses[], int *expenseCount);
void displayFriendDetails(Friend friends[], int friendCount);
void displayExpenses(Expense expenses[], int expenseCount);
float calculateTotalExpenses(Expense expenses[], int expenseCount);
void setExpenseLimits(float limits[], int *categoryCount);
void generateSummaryReport(Friend friends[], int friendCount, Expense expenses[], int expenseCount, float limits[], int categoryCount);
void exportSummaryReport(Friend friends[], int friendCount, Expense expenses[], int expenseCount, float limits[], int categoryCount);
void compareWithBudget(float totalExpenses, float budget);

int main() {
    Friend friends[MAX_FRIENDS];
    Expense expenses[MAX_EXPENSES];
    int friendCount = 0, expenseCount = 0;
    int choice;
    float limits[MAX_CATEGORIES] = {0};
    int numDays;
    char place[MAX_DESCRIPTION_LENGTH];

    printf("Enter the number of friends: ");
    scanf("%d", &friendCount);
    getchar();

    if (friendCount > MAX_FRIENDS) {
        printf("Maximum number of friends allowed is %d.\n", MAX_FRIENDS);
        return 1;
    }

    inputFriendDetails(friends, &friendCount);

    printf("Enter the number of days you are staying: ");
    scanf("%d", &numDays);
    getchar();

    printf("Enter the place of your trip: ");
    fgets(place, MAX_DESCRIPTION_LENGTH, stdin);
    place[strcspn(place, "\n")] = '\0'; // Remove newline character

    while (1) {
        printf("\n--- Trip Expense Calculator ---\n");
        printf("1. Input Expense Details\n");
        printf("2. View Friends Details\n");
        printf("3. View All Expenses\n");
        printf("4. Calculate Total Trip Expenses\n");
        printf("5. Set Expense Limits\n");
        printf("6. Generate Summary Report\n");
        printf("7. Export Summary Report\n");
        printf("8. Compare with Budget\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                inputExpenseDetails(friends, friendCount, expenses, &expenseCount);
                break;
            case 2:
                displayFriendDetails(friends, friendCount);
                break;
            case 3:
                displayExpenses(expenses, expenseCount);
                break;
            case 4:
                printf("Total Trip Expenses: %.2f\n", calculateTotalExpenses(expenses, expenseCount));
                break;
            case 5:
                setExpenseLimits(limits, &expenseCount);
                break;
            case 6:
                generateSummaryReport(friends, friendCount, expenses, expenseCount, limits, MAX_CATEGORIES);
                break;
            case 7:
                exportSummaryReport(friends, friendCount, expenses, expenseCount, limits, MAX_CATEGORIES);
                break;
            case 8:
                printf("Enter your budget: ");
                float budget;
                scanf("%f", &budget);
                compareWithBudget(calculateTotalExpenses(expenses, expenseCount), budget);
                break;
            case 9:
                printf("Exiting program...\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

void inputFriendDetails(Friend friends[], int *friendCount) {
    for (int i = 0; i < *friendCount; i++) {
        printf("\nEnter details for Friend %d:\n", i + 1);
        printf("Name: ");
        fgets(friends[i].name, MAX_NAME_LENGTH, stdin);
        friends[i].name[strcspn(friends[i].name, "\n")] = '\0';

        printf("Amount of money they have: ");
        scanf("%f", &friends[i].initialAmount);
        friends[i].totalSpent = 0.0;
        friends[i].remainingBalance = friends[i].initialAmount;
        getchar();
    }
}

void inputExpenseDetails(Friend friends[], int friendCount, Expense expenses[], int *expenseCount) {
    if (*expenseCount >= MAX_EXPENSES) {
        printf("You have reached the maximum number of expenses.\n");
        return;
    }

    printf("\nEnter details for Expense %d:\n", *expenseCount + 1);
    printf("Enter the expense category (1. Transportation, 2. Food, 3. Accommodation, 4. Entertainment, 5. Miscellaneous): ");
    int categoryChoice;
    scanf("%d", &categoryChoice);
    getchar();
    char *categories[] = {"Transportation", "Food", "Accommodation", "Entertainment", "Miscellaneous"};
    strcpy(expenses[*expenseCount].category, categories[categoryChoice - 1]);

    printf("Enter description for the expense: ");
    fgets(expenses[*expenseCount].description, MAX_DESCRIPTION_LENGTH, stdin);
    expenses[*expenseCount].description[strcspn(expenses[*expenseCount].description, "\n")] = '\0';

    printf("Enter the amount for this expense: ");
    scanf("%f", &expenses[*expenseCount].amount);
    getchar();

    float share = expenses[*expenseCount].amount / friendCount;
    for (int i = 0; i < friendCount; i++) {
        expenses[*expenseCount].individualShare[i] = share;
        friends[i].totalSpent += share;
        friends[i].remainingBalance -= share;
    }

    (*expenseCount)++;
    printf("Expense added successfully!\n");
}

void displayFriendDetails(Friend friends[], int friendCount) {
    printf("\n--- Friends' Details ---\n");
    for (int i = 0; i < friendCount; i++) {
        printf("Friend: %s, Initial Amount: %.2f, Total Spent: %.2f, Remaining Balance: %.2f\n",
               friends[i].name, friends[i].initialAmount, friends[i].totalSpent, friends[i].remainingBalance);
    }
}

void displayExpenses(Expense expenses[], int expenseCount) {
    printf("\n--- All Expenses ---\n");
    for (int i = 0; i < expenseCount; i++) {
        printf("Category: %s\n", expenses[i].category);
        printf("Description: %s\n", expenses[i].description);
        printf("Amount: %.2f\n", expenses[i].amount);
        printf("-----------------------\n");
    }
}

float calculateTotalExpenses(Expense expenses[], int expenseCount) {
    float total = 0.0;
    for (int i = 0; i < expenseCount; i++) {
        total += expenses[i].amount;
    }
    return total;
}

void setExpenseLimits(float limits[], int *categoryCount) {
    printf("Set budget limits for each category (up to %d categories):\n", MAX_CATEGORIES);
    for (int i = 0; i < MAX_CATEGORIES; i++) {
        printf("Enter the limit for category %d: ", i + 1);
        scanf("%f", &limits[i]);
    }
}

void generateSummaryReport(Friend friends[], int friendCount, Expense expenses[], int expenseCount, float limits[], int categoryCount) {
    printf("\n--- Summary Report ---\n");
    float totalExpenses = calculateTotalExpenses(expenses, expenseCount);
    printf("Total Trip Expenses: %.2f\n", totalExpenses);

    for (int i = 0; i < categoryCount; i++) {
        printf("Category %d Limit: %.2f\n", i + 1, limits[i]);
    }

    for (int i = 0; i < friendCount; i++) {
        printf("Friend: %s, Remaining Balance: %.2f\n", friends[i].name, friends[i].remainingBalance);
    }
}

void exportSummaryReport(Friend friends[], int friendCount, Expense expenses[], int expenseCount, float limits[], int categoryCount) {
    FILE *file = fopen("trip_summary.txt", "w");
    if (file == NULL) {
        printf("Error opening file for export.\n");
        return;
    }

    fprintf(file, "--- Summary Report ---\n");
    float totalExpenses = calculateTotalExpenses(expenses, expenseCount);
    fprintf(file, "Total Trip Expenses: %.2f\n", totalExpenses);

    for (int i = 0; i < categoryCount; i++) {
        fprintf(file, "Category %d Limit: %.2f\n", i + 1, limits[i]);
    }

    for (int i = 0; i < friendCount; i++) {
        fprintf(file, "Friend: %s, Remaining Balance: %.2f\n", friends[i].name, friends[i].remainingBalance);
    }

    fclose(file);
    printf("Summary report exported successfully to 'trip_summary.txt'.\n");
}

void compareWithBudget(float totalExpenses, float budget) {
    printf("\nTotal Trip Expenses: %.2f\n", totalExpenses);
    printf("Budget: %.2f\n", budget);

    if (totalExpenses > budget) {
        printf("You have exceeded your budget by %.2f!\n", totalExpenses - budget);
    } else if (totalExpenses < budget) {
        printf("You are within your budget! You saved %.2f.\n", budget - totalExpenses);
    } else {
        printf("You have exactly matched your budget!\n");
    }
}

