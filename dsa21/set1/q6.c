#include <stdio.h>
#include <string.h>
int i,j;
typedef struct term {
    int digit;
    int position; // Exponent here represents the position of the digit
} term;

typedef struct poly {
    term a[1000];
    int no_of_terms;
} poly;

void inputLargeNumber(poly *p) {
    char number[1000];
    printf("Enter a large number: ");
    scanf("%s", number);

    p->no_of_terms = strlen(number);
    for (i = 0; i < p->no_of_terms; i++) {
        p->a[i].digit = number[p->no_of_terms - 1 - i] - '0'; // Store digits in reverse order
        p->a[i].position = i;
    }
}

void displayLargeNumber(poly p) {
    for (i = p.no_of_terms - 1; i >= 0; i--) {
        printf("%d", p.a[i].digit);
    }
    printf("\n");
}

void addLargeNumbers(poly p1, poly p2, poly* result) {
    int carry = 0, k = 0;
    i = 0, j = 0;

    while (i < p1.no_of_terms || j < p2.no_of_terms || carry) {
        int digit1 = (i < p1.no_of_terms) ? p1.a[i].digit : 0;
        int digit2 = (j < p2.no_of_terms) ? p2.a[j].digit : 0;
        int sum = digit1 + digit2 + carry;
        result->a[k].digit = sum % 10;
        carry = sum / 10;

        result->a[k].position = k;
        k++;
        if (i < p1.no_of_terms) i++;
        if (j < p2.no_of_terms) j++;
    }

    result->no_of_terms = k;
}

int main() {
    poly p1, p2, result;

    printf("Enter the first large number:\n");
    inputLargeNumber(&p1);

    printf("Enter the second large number:\n");
    inputLargeNumber(&p2);

    addLargeNumbers(p1, p2, &result);

    printf("Sum: ");
    displayLargeNumber(result);

    return 0;
}
