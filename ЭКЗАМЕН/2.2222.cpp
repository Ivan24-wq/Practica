#include <iostream>
using namespace std;

void bubbleSort(int list[], int listLength)
{
	while(listLength--)
	{
		bool swapped = false;
		
		for(int i = 0; i < listLength; i++)
		{
			if(list[i] > list[i + 1])
			{
				swap(list[i], list[i + 1]);
				swapped = true;
			}
		}
		
		if(swapped == false)
			break;
	}
}

int main()
{
    setlocale(LC_ALL, "RU");
	int list[5] = {3,19,8,0,48};
	cout << "Исходный массив: " << endl;
	for(int i = 0; i < 5; i++)
		cout << list[i] << '\t';
	cout << endl;
	
	bubbleSort(list, 5);
	
	cout << "отсортированный массив: " << endl;
	for(int i = 0; i < 5; i++)
		cout << list[i] << '\t';
	cout << endl;
}