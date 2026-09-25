#include <stdio.h>

void deposit(float *balance) {
    float amount;
    printf("Enter amount to deposit: ");
    scanf("%f", &amount);
    if (amount > 0) {
        *balance += amount;
        printf("Rs. %.2f deposited!\n", amount);
    }
}

void withdraw(float *balance) {
    float amount;
    printf("Enter amount to withdraw: ");
    scanf("%f", &amount);
    if (amount > 0 && amount <= *balance) {
        *balance -= amount;
        printf("Rs. %.2f withdrawn!\n", amount);
    } else {
        printf("Insufficient balance!\n");
    }
}

void changePin(int *pin) {
    int oldPin, newPin;
    printf("Enter old PIN: ");
    scanf("%d", &oldPin);
    if (oldPin == *pin) {
        printf("Enter new PIN: ");
        scanf("%d", &newPin);
        *pin = newPin;
        printf("PIN changed!\n");
    }
}

int main() {
    float balance = 10000.0;
    int pin = 1234, choice, enteredPin;
    printf("Enter PIN: ");
    scanf("%d", &enteredPin);
    if (enteredPin != pin) {
        printf("Wrong PIN!\n");
        return 0;
    }
    do {
        printf("\n1.Balance 2.Deposit 3.Withdraw 4.Change PIN 5.Exit\nChoice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: printf("Balance: Rs. %.2f\n", balance); break;
            case 2: deposit(&balance); break;
            case 3: withdraw(&balance); break;
            case 4: changePin(&pin); break;
            case 5: printf("Thank you!\nHave a nice day\n"); break;
            default: printf("Invalid choice! Please try again\n"); break;
        }
    } while (choice != 5);
    return 0;
}
