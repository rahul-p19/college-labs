#include <stdio.h>

typedef struct term{
	float coeff;
	int expo;
}term;

typedef struct poly{
	term a[1000];
	int no_of_terms;
}poly;

void inputPolynomial(poly* p){
	int i;
	printf("Enter the number of terms: ");
	scanf("%d",&p->no_of_terms);
	for(i=0;i<p->no_of_terms;i++){
		printf("Enter coefficient and exponent for term %d: ",i+1);
		scanf("%f %d",&p->a[i].coeff,&p->a[i].expo);
	}
}

void displayPolynomial(poly p){
	int i;
	for(i=0;i<p.no_of_terms;i++){
		if(i>0 && p.no_of_terms>0) printf(" + ");
		if(p.a[i].expo != 0) printf("%.2fx^%d",p.a[i].coeff,p.a[i].expo);
		else printf("%.2f",p.a[i].coeff);
	}
	printf("\n");
}

void addPolynomials(poly p1, poly p2, poly* result){
	int i=0,j=0,k=0;
	result->no_of_terms=0;
	while(i<p1.no_of_terms && j<p2.no_of_terms){
		if(p1.a[i].expo<p2.a[j].expo) result->a[k++]=p1.a[i++];
		else if(p1.a[i].expo>p2.a[j].expo) result->a[k++] = p2.a[j++];
		else{
			if(p1.a[i].coeff + p2.a[j].coeff!=0){
				result->a[k].expo = p1.a[i].expo;
				result->a[k].coeff=p1.a[i].coeff + p2.a[j].coeff;
				k++;}
			i++;
			j++;
		}
	}
	while(i<p1.no_of_terms) result->a[k++]=p1.a[i++];
	while(j<p2.no_of_terms) result->a[k++]=p2.a[j++];
	result->no_of_terms=k;
}

int main(){
	poly p1,p2,result;
	printf("Enter polynomial 1:\n");
	inputPolynomial(&p1);
	printf("Enter polynomial 2:\n");
	inputPolynomial(&p2);
	addPolynomials(p1,p2,&result);
	printf("Polynomial 1: ");
	displayPolynomial(p1);
	printf("Polynomial 2: ");
	displayPolynomial(p2);
	printf("Result: ");
	displayPolynomial(result);
	return 0;
}
