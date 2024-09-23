#include <iostream>
using namespace std;

int alldata;
int par;
int innum[100];
int code[100];
int rd[100];
int parity(int, int);                  
void ham(int input[], int);  
int parity(int, int);                  

void main(){
	int number;
	cout << "PLease Enter the # of bits here: " ;
	cin >> number;
	cout << "\n " << "Please Enter the data of bits here:" << "\n";
	for (int i = 0; i < number; i++)
		cin >> innum[i];
	ham(innum, number);
	cout << "\n" << "Please Enter The Reseved Data (RD) here:" << "\n";
	for (int i = 0; i < alldata; i++) {
		cin >> rd[i];}

	int b = 0, numerror = 0;
	for (int i = 0; i < alldata; i++) {
		if (code[i] != rd[i])
			numerror++;}
	float perresult = (((float)numerror / (float)alldata) * 100);

	if (numerror == 2) {
		cout << "There are 2 error in (RD)." << "\n";
		cout << "\n" << " The percent of error is =" << "  " << perresult << "%";}

	else if (numerror == 1){	
		for (int i = 0; i < alldata; i++) {
			if (code[i] != rd[i])
			{b = i; break;}}

		cout << "ONE error in bit:" << "  " << b << "\n";
		rd[b] = code[b];
		cout << " The percent of error is=" << "  " << perresult << "%" << "\n";
		cout << "The correct data is" << "\n";
		for (int i = 0; i < alldata; i++)
			cout << rd[i];}
	else if (numerror > 2) {
		cout << "\n" << "The # of error is greater than 2." << "\n";
		cout << "\n" << " The percent of error  is=" << "  " << perresult << "%" << "\n";
	}
	else if (numerror == 0) cout << "\n" << "There are no error, the result is right.";
}

int parity(int p, int td){
	int counter = 0;
	int i, j;
	i = p - 1;
	while (i < td) {
		for (j = i; j < i + p; j++) {
			if (code[j] == 1)
				counter++;}
		i = i + 2 * p;
		i = i + 2 * p;}
	if (counter % 2 == 0) return 0;
	else return 1;}

void ham(int input[], int m){
	int i, j, k;
	i = 0;
	par = 0;
	while (m > (int)pow(2, i) - (i + 1)){
		par++;
		i++;}
	alldata = par + m;
	j = k = 0;
	for (i = 0; i < alldata; i++) {
		if (i == ((int)pow(2, k) - 1)){
			code[i] = 0;
			k++;}
		else {
			code[i] = input[j];
			j++;}}
	for (i = 0; i < par; i++) {
		int po = (int)pow(2, i);
		int value = parity(po, alldata);
		code[po - 1] = value;}
	cout << "\nThe result of hamming function is: ";
	for (i = 0; i < alldata; i++) {
		cout << code[i];}
}