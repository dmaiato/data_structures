#include <stdio.h>
#include <stdlib.h>

int main() {
    int number1;
    int number2;
    printf("\nInform a number: ");
    scanf("%d", &number1);
    printf("\nInform another number: ");
    scanf("%d", &number2);
    
    // & shows memory address
    printf("%d is stored at: %x\n", number1, &number1);
    printf("%d is stored at: %x\n", number2, &number2);

}
