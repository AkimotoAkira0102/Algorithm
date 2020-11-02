#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

void print(int[],int);

int main(void){
	int array[] = {5,8,1,3,4,6,7,2,10,9};
	
	int arrayLength = sizeof(array)/sizeof(*array);
	
	for(int i = 0;i < arrayLength;i++){
		for(int j = i + 1;j < arrayLength + 1;j++){
			if(array[i] > array[j]){
				int temp;
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				
		print(array,arrayLength);
		cout << endl;
			}
		}
		cout << "=====" << endl;
	}
	
	print(array,arrayLength);
	
	return 0;
	system("PAUSE");
}

void print(int array[],int length){
	for(int i = 0;i < length;i++){
		cout << array[i] << setw(3);
	}
}
