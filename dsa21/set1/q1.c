#include <stdio.h>

int main(){
	int arr[10];
	int i;
	printf("Enter 10 elements: ");
	for(i=0;i<10;i++) scanf("%d",&arr[i]);
	for(i=2;i<4;i++) arr[i]=arr[i+1];
	for(i=4;i<8;i++) arr[i]=arr[i+2];
	printf("5th element of resulting array: %d\n",arr[4]);
	return 0;
}
