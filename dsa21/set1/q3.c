#include <stdio.h>

typedef struct term {
  float coeff;
  int expo;
} term;

typedef struct poly {
  term a[1000];
  int no_of_terms;
} poly;

void inputPolynomial(poly *p) {
  int i;
  printf("Enter the number of terms: ");
  scanf("%d", &p->no_of_terms);
  for (i = 0; i < p->no_of_terms; i++) {
    printf("Enter coefficient and exponent for term %d: ", i + 1);
    scanf("%f %d", &p->a[i].coeff, &p->a[i].expo);
  }
}

void displayPolynomial(poly p) {
  int i;
  for (i = 0; i < p.no_of_terms; i++) {
    if (i > 0 && p.no_of_terms > 0)
      printf(" + ");
    if (p.a[i].expo != 0)
      printf("%.2fx^%d", p.a[i].coeff, p.a[i].expo);
    else
      printf("%.2f", p.a[i].coeff);
  }
  printf("\n");
}

void addPolynomials(poly p1, poly p2, poly *result) {
  int j = 0, k = 0, ctr = 0;
  *result = p1;
  ctr = result->no_of_terms;
  for (j = 0; j < p2.no_of_terms; j++) {
    int flag = 0;
    for (k = 0; k < result->no_of_terms; k++) {
      if (result->a[k].expo == p2.a[j].expo) {
        result->a[k].coeff += p2.a[j].coeff;
        flag = 1;
      }
    }
    if (!flag) {
      result->a[ctr].expo = p2.a[j].expo;
      result->a[ctr++].coeff = p2.a[j].coeff;
    }
  }
  result->no_of_terms = ctr;
}

int main() {
  poly p1, p2, result;
  printf("Enter polynomial 1:\n");
  inputPolynomial(&p1);
  printf("Enter polynomial 2:\n");
  inputPolynomial(&p2);
  addPolynomials(p1, p2, &result);
  printf("Polynomial 1: ");
  displayPolynomial(p1);
  printf("Polynomial 2: ");
  displayPolynomial(p2);
  printf("Result: ");
  displayPolynomial(result);
  return 0;
}
