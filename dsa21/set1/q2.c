#include <stdio.h>
void swap(int *a, int*b){
	int temp=*a;
	*a=*b;
	*b=temp;}

	int main(){
		int arr[100];
		int i,n;
		printf("Enter the number of elements: ");
		scanf("%d",&n);
		printf("Enter array elements: ");
		for(i=0;i<n;i++) scanf("%d",&arr[i]);
		for(i=0;i<n/2;i++) swap(&arr[i],&arr[n-1-i]);
		printf("Reversed array: ");
		for(i=0;i<n;i++) printf("%d ",arr[i]);
		printf("\n");
		return 0;
	}
