#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;
int usernum =1;
string* addEntry(string* dynamicArray,int size, string newEntry1,string newEntry2);
string* deleteEntry(string* dynamicArray,int &size, string entryToDeltete);
string* create2DArray(int rows,int colmns);
void print(string *dynamicArray,int size);
int main() {
	int nowsize = 0;
	int mode;
	string user,password;
	string* head = create2DArray(usernum,2);
	cout<<"input mode 1.add 2.delete 3.print"<<endl;
	while(cin>>mode) {
		switch (mode) {
			case 1:
				nowsize++;
				cin>>user>>password;
				head = addEntry(head,nowsize,user,password);
				break;
			case 2:
				cin>>user;
				head = deleteEntry(head,nowsize,user);
				break;
			case 3:
				print(head,nowsize);
				break;
			default:
				cout<<"error"<<endl;
		}
		cout<<"input mode 1.add 2.delete 3.print"<<endl;
	}
}
string* create2DArray(int rows,int colmns) {
	string* head = new string [rows*colmns];
	return head;
}
string* addEntry(string* dynamicArray,int size, string newEntry1,string newEntry2) {
	if(size == usernum) { //放大重開 
		usernum *= 2;
		string* head = new string [usernum];
		for(int i=0;i<size-1;i++){
			head[2*i]=dynamicArray[2*i];
			head[2*i+1]=dynamicArray[2*i+1];
		}
		delete [] dynamicArray;
		dynamicArray=head;
	}
	dynamicArray[2*(size-1)]= newEntry1;
	dynamicArray[2*(size-1)+1]= newEntry2;
	return dynamicArray;
}

string* deleteEntry(string* dynamicArray,int &size, string entryToDeltete){
	string* head = new string [usernum*2];
	bool found=0;
	int now=0;
	for(int i=0;i<size;i++){
		if(dynamicArray[2*i]==entryToDeltete){
			found=1;
		}
		else{
			head[2*now]=dynamicArray[2*i];
			head[2*now+1]=dynamicArray[2*i+1];
			now++;
		}
	}
	if(found){
		cout<<"sucessful"<<endl;
		size--;
	}
	else
		cout<<"error"<<endl;
	delete [] dynamicArray;	
	return head;
}
void print(string *dynamicArray,int size){
	for(int i=0;i<size;i++){
		cout<<dynamicArray[2*i]<<" "<<dynamicArray[2*i+1]<<endl;
	}
}
