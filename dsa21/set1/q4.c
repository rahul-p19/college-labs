#include <stdio.h>
#include <math.h>

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
double evaluate(poly p,int x){
	double ans=0;
	int i;
	for(i=0;i<p.no_of_terms;i++) ans+=p.a[i].coeff*pow(x,p.a[i].expo);
	return ans;
}

int main(){
	poly p;
	printf("Enter polynomial:\n");
	inputPolynomial(&p);
	int x;
	printf("Enter value of x: ");
	scanf("%d",&x);
	printf("Polynomial: ");
	displayPolynomial(p);
	printf("Result: %lf\n",evaluate(p,x));
	return 0;
}
