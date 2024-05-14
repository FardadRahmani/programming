#include <iostream>
#include <string>

using namespace std;
template <typename T>
int LinearSearch(T dataArray[], int arraySize, T searchItem)
{
	// Search through array.
	for (int i = 0; i < arraySize; ++i)
	{
		// Find it?
		if (dataArray[i] == searchItem)
		{
			// Yes, return the index we found it at.
			return i;
		}
	}
	// Did not find it, return -1.
	return -1;
}
template <typename T>
void Print(T data[], int arraySize)
{
	for (int i = 0; i < arraySize; ++i)
		cout << data[i] << " ";
	cout << endl;
}


int main()
{
	string sArray[8] =
	{
	"delta",
	"lambda",
	"alpha",
	"beta",
	"pi",
	"omega",
	"epsilon",
	"phi"
	};
	int numStrings = 8;
	int iArray[14] = { 7,3,32,2,55,34,6,13,29,22,11,9,1,5 };
	int numInts = 14;
	int index = -1;
	bool quit = false;
	while (!quit)
	{
		//=======================================
		// String search.
		Print(sArray, numStrings);
		string str = "";
		cout << "Enter a string to search for: ";
		cin >> str;
		index = LinearSearch(sArray, numStrings, str);
		if (index != -1)
			cout << str << " found at index " << index << endl;
		else
			cout << str << " not found." << endl;
		cout << endl;
		//=======================================
		// Int search.
		Print(iArray, numInts);
		int integer = 0;
		cout << "Enter an integer to search for: ";
		cin >> integer;
		index = LinearSearch(iArray, numInts, integer);
		if (index != -1)
			cout << integer << " found at index " << index << endl;
		else
			cout << integer << " not found." << endl;
		cout << endl;
		
			//=======================================
			// Search again?
			char input = '\0';
		cout << "Quit? (y)/(n)";
		cin >> input;
		if (input == 'y' || input == 'Y')
			quit = true;
	}
}