#include<stdio.h>
//#include<conio.h>

typedef struct node{
	int data;
	struct node *next;
} node;

node *head=NULL;
void rdupl();
void replace(int,int);
void addf(int);
//void alter();
void addafter(int,int);
void create(int);
void print();
void del(int);
int count(int);
int issorted();

main(){
	addafter(10,1);
	addafter(100,2);
	addafter(0,3);
	addafter(0,4);
	addafter(0,5);
	//addafter(5,13);
	//replace(13,49);
	addafter(0,6);
	addafter(6,6);
	addafter(6,6);
	addafter(0,7);
	addf(-1);
	addafter(0,8);
	addafter(0,9);
	addafter(0,10);
	//create(35);
	rdupl();
	//alter();
	//print();
	addf(-1);
	del(7);
	//alter();
	//printf("%d",head->data);
	print();
	int c=count(6);
	int v=issorted();
	printf("\n%d",c);
	printf("\n%d",v);
}

void create(int val){
	if(head!=NULL) return;
	head=(node*)malloc(sizeof(node));
	head->data=val;
	head->next=NULL;
}

void addafter(int b,int val){
	node *temp=head;
	node *nnode=NULL;
	if(head==NULL) {create(val);return;}
	
	while(temp->next!=NULL && temp->data!=b ){
		
		temp=temp->next;
	}
	
	nnode=(node*)malloc(sizeof(node));
	nnode->data=val;
	nnode->next=temp->next;
	temp->next=nnode;
	
}
/*void alter(){
	node *temp=head;
	int i=1;
	
	while(temp->next->next!=NULL){
		addafter(temp->data,temp->next->next->data);
		//addf(temp->next->data);
		temp=temp->next->next;
		}
}
*/

void del(int val){
	node *temp=head;
	while(temp->next!=NULL ){
		if(temp->next->data==val) break;
		temp=temp->next;
	}
	temp->next=temp->next->next;	
}

void addf(int val){
	node *temp=NULL;
	temp=(node*)malloc(sizeof(node));
	temp->data=val;
	temp->next=head;
	head=temp;
	
}

void print(){
	node *temp=head;
	while(temp->next!=NULL){
		printf("%d",temp->data);
		temp=temp->next;
	}
	printf("%d\n",temp->data);
}

int count(int val){
	node *temp=head;
	int count=0;
	while(temp->next!=NULL){
		if(temp->data==val) count++;
		temp=temp->next;

	}
	if(temp->data==val) count++;
	return count;
}

void replace(int val,int nval){
	node *temp=head;
	while(temp->next!=NULL){
		if(temp->data==val) break;
		temp=temp->next;
	}
	if(temp->data==val) temp->data=nval;
	
}
int issorted(){
	node*temp=head;
	printf("%d",temp->data);
	int flag=1;
	while(temp->next!=NULL){
		if((temp->data)<(temp->next->data)) {flag =0;break;}
		temp=temp->next;
	}
	return flag;	
}

void rdupl(){
	node *temp=head;
	while(temp->next!=NULL){
		if(temp->data==temp->next->data){
			del(temp->data);
			rdupl();
		}
		temp=temp->next;
	}
	
}