#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;

void printArray(int [],int,int);

int main(void){
	bool debug = false;
	cout << "Start with default array?(y/n):";
	char ans;
	cin >> ans;
	if(ans == 'y'){
		debug = true;
	}
	
	int array[10] = {0},target;
	int arrayLength = sizeof(array)/sizeof(*array);
	if(debug == true){
		goto defaultArray;
	}
	
	for(int i = 0;i < arrayLength; i++){
		cout << i+1 << ":";
		cin >> array[i];
	}
	
	cout << "Which is your target?";
	cin >> target;
	
	defaultArray:{
		if(debug == true){
			array[0] = 8;array[1] = 7;array[2] = 10;array[3] = 6;array[4] = 9;array[5] = 4;array[6] = 1;array[7] = 3;array[8] = 2;array[9] = 5;
			target = 7;
		}
	}
	
	printArray(array,0,arrayLength - 1);
	
	/*
	** bubble sort
	*/
	for(int i = 0; i < arrayLength; i++){
		for(int j = i + 1; j < arrayLength; j++){
			int temp;
			if(array[i] > array[j]){
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
		}
	}
	
	cout << "After sort:" << endl;
	printArray(array,0,arrayLength - 1);
	
	int indexMid;
	bool find = true;
	int indexLeft = 0,indexRight = arrayLength - 1;
	int count = 0;
	cout << "\n=======\n";
	while(find){
		indexMid = (indexLeft + indexRight)/2;
		cout << "Between " << array[indexLeft] << " and " << array[indexRight] << endl;
		printArray(array,indexLeft,indexRight);
		
		count ++;
		if(indexLeft < 0 || indexRight > arrayLength || (indexLeft == indexRight && array[indexMid] != target)){
			cout << "Target isn't in array." << endl;
			break;
		}
		if(array[indexMid] > target){
			indexRight = indexMid;
		}
		else if(array[indexMid] < target){
			indexLeft = indexMid;
		}
		else if(array[indexMid] == target){
			cout << "complete" << endl;
			cout << "" << indexMid + 1 << endl;
			find = false;
		}
	}
	
	cout << "count = " << count << endl;
	system("PAUSE");
	return 0;
}

void printArray(int array[],int idxL,int idxR){
	for(int i = idxL;i <= idxR;i++){
		cout << array[i];
		if(i < idxR){
			cout << ",";
		}
	}
	cout << endl;
}
