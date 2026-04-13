#include <stdio.h>

#define EURO_TO_EGP 55
#define USD_TO_EGP 47.5
#define EURO_TO_USD 1.16


void currency_conversion();
void calculator();

int main()
{
    int choice;

    do {
        printf("\n MAIN MENU \n");
        printf("1 Currency Conversion\n");
        printf("2 Calculator\n");
        printf("3 Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                currency_conversion();
                break;

            case 2:
                calculator();
                break;

            case 3:
                printf("Exiting program\n");
                break;

            default:
                printf("Invalid choice\n");
        }

    } while(choice != 3);

    return 0;
}


void currency_conversion()
{
    int option;
    float amount;
    printf("\n--- Currency Conversion ---\n");
    printf("1= EGP to Euro\n");
    printf("2= EGP to Dollar\n");
    printf("3= Euro to Dollar\n");
    printf("4= Dollar to Euro\n");
    printf("5= Euro to EGP\n");
    printf("6= Dollar to EGP\n");
    printf("7= Percentage Euro to Dollar\n");
    printf("Enter option: ");
    scanf("%d", &option);

    if(option < 1 || option > 7) {
        printf("Invalid option!\n");
        return;
    }

    printf("Enter amount: ");
    scanf("%f", &amount);

    switch(option)
    {
        case 1:
            printf("Euro = %.2f\n", amount / EURO_TO_EGP);
            break;

        case 2:
            printf("Dollar = %.2f\n", amount / USD_TO_EGP);
            break;

        case 3:
            printf("Dollar = %.2f\n", amount * EURO_TO_USD);
            break;

        case 4:
            printf("Euro = %.2f\n", amount / EURO_TO_USD);
            break;

        case 5:
            printf("EGP = %.2f\n", amount * EURO_TO_EGP);
            break;

        case 6:
            printf("EGP = %.2f\n", amount * USD_TO_EGP);
            break;

        case 7: {
            float percent, euro_part, dollars;

            printf("Enter percentage: ");
            scanf("%f", &percent);

            euro_part = (amount * percent) / 100;
            dollars = euro_part * EURO_TO_USD;

            printf("%.2f%% of %.2f Euro = %.2f Dollars\n",
                   percent, amount, dollars);
            break;
        }
    }
}

void calculator()
{
    float num1, num2;
    int operation;

    printf("\n Calculator \n");
    printf("Enter two numbers: ");
    scanf("%f %f", &num1, &num2);

    printf("1= Addition\n");
    printf("2= Subtraction\n");
    printf("3= Multiplication\n");
    printf("4= Division\n");

    printf("Choose operation: ");
    scanf("%d", &operation);

    switch(operation)
    {
        case 1:
            printf("Result: %.2f\n", num1 + num2);
            break;

        case 2:
            printf("Result: %.2f\n", num1 - num2);
            break;

        case 3:
            printf("Result: %.2f\n", num1 * num2);
            break;

        case 4:
            if(num2 != 0)
                printf("Result: %.2f\n", num1 / num2);
            else
                printf("Error: Division by zero\n");
            break;

        default:
            printf("Invalid operationn\n");
    }
}