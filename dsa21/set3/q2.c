#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int val;
	struct Node* left;
	struct Node* right;
}Node;

Node* createNode(int x){
	Node* root = (Node *)malloc(sizeof(Node));
	root->val = x;
	root->left=NULL;
	root->right=NULL;
	return root;
}

int search(int arr[], int key,int n){
	//int n = sizeof(arr)/4;
	int i=0;
	for(i=0;i<n;i++){
	       	if(arr[i]==key) 
			return i;
	}
	return -1;
}

Node* postorder(Node* root){
	if(root==NULL) return NULL;
	postorder(root->left);
	postorder(root->right);
	printf("%d ",root->val);
}

Node* buildTree(int* inorder, int* preorder, int preStart, int inStart, int inEnd,int n){
	if(inStart > inEnd || inStart < 0 || inEnd < 0) return NULL;
	int currVal = preorder[preStart];
	Node* root = createNode(currVal);
	if(inStart==inEnd) return root;
	int currInd = search(inorder, currVal,n);
	int leftSize = currInd - inStart;
	root->left = buildTree(inorder,preorder,preStart+1,inStart,currInd-1,n);
	root->right = buildTree(inorder,preorder,preStart+leftSize+1,currInd+1,inEnd,n);
	return root;
}

int main(){
	int n;
	printf("Enter number of nodes: ");
	scanf("%d",&n);
	int* inorder = (int*)malloc(4*n);
	int* preorder = (int*)malloc(4*n);
	printf("Enter inorder traversal: ");
	int i;
	for(i=0;i<n;i++) scanf("%d",&inorder[i]);
	printf("Enter preorder traversal: ");
	for(i=0;i<n;i++) scanf("%d",&preorder[i]);
	Node* root = buildTree(inorder,preorder,0,0,n-1,n);
	printf("Postorder: ");
	postorder(root);
	printf("\n");
	return 0;
}
