template <typename T>
class Array
{

public:
	// Create a FloatArray with zero elements.
	Array() : mData(nullptr), mSize(0) {}
	// Create a FloatArray with 'size' elements.
	Array(int size) :mData(nullptr), mSize(size) {}
	// Create a FloatArray from another FloatArray--
	// be sure to prevent memory leaks!
	Array(const Array<T>& rhs);
	// Free dynamic memory.
	~Array();
	// Define how a FloatArray shall be assigned to
	// another FloatArray--be sure to prevent memory
	// leaks!
	Array& operator=(const Array<T>& rhs);
	// Resize the FloatArray to a new size.
	void resize(int newSize);
	// Return the number of elements in the array.
	int size();
	// Overload bracket operator so client can index
	// into FloatArray objects and access the elements.
	T& operator[](int i);
private:
	T* mData; // Pointer to array of floats (dynamic memory).
	int mSize; // The number of elements in the array.
};



using namespace std;

template <typename T>
Array<T>::Array(const Array<T>& rhs) : mData(nullptr), mSize(rhs.mSize)
{
	// Allocate memory for the new array
	mData = new T[mSize];
	// Copy elements from rhs to this object
	for (int i = 0; i < mSize; ++i)
	{
		mData[i] = rhs.mData[i];
	}
}



// Free dynamic memory.
template <typename T>
Array<T>::~Array()
{
	// Lösche den dynamisch allokierten Speicher
	delete[] mData;
	// Setze den Zeiger auf nullptr, um auf gelöschten Speicher zu verweisen
	mData = nullptr;
	// Setze die Größe auf 0, da das Objekt zerstört wird
	mSize = 0;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& rhs)
{
	if (this != &rhs)
	{
		resize(rhs.mSize);
		for (int i = 0; i < mSize; ++i)
			mData[i] = rhs.mData[i];
	}
	return *this;

}

// Resize the FloatArray to a new size.
template <typename T>
void Array<T>::resize(int newSize)
{
	T* newArr = new T[newSize];

	//Copy elements to the new array
	if (newSize >= mSize)
	{
		for (int i = 0; i < mSize; ++i)
		{
			newArr[i] = mData[i];
		}
	}
	else //newSize < mSize
	{
		//Copy as many elements as possible
		for (int i = 0; i < newSize; ++i)
			newArr[i] = mData[i];
	}
	delete[] mData;
	mData = newArr;
	mSize = newSize;
}

// Return the number of elements in the array.
template <typename T>
int Array<T>::size()
{
	return mSize;
}

// Overload bracket operator so client can index
// into FloatArray objects and access the elements.
template <typename T>
T& Array<T>::operator[](int i)
{
	if (i<0 || i > mSize)
	{
		cout << "Index out of range";
	}
	return mData[i];

}


template <typename T>
void PrintArray(Array<T>& a)
{
	cout << "{ ";
	for (int i = 0; i < a.size(); ++i)
		cout << a[i] << " ";
	cout << "}" << endl << endl;
}
int main()
{
	Array<float> A;
	A.resize(4);
	A[0] = 1.0f;
	A[1] = 2.0f;
	A[2] = 3.0f;
	A[3] = 4.0f;



	cout << "Printing A: ";
	PrintArray(A);
	Array<float> B(A);
	cout << "Printing B: ";
	PrintArray(B);
	Array<float> C = B = A;
	cout << "Printing C: ";
	PrintArray(C);
	A = A = A = A;
	cout << "Printing A: ";
	PrintArray(A);


	Array<int> zahl;
	zahl.resize(4);
	zahl[0] = 10;
	zahl[1] = 20;
	zahl[2] = 30;
	zahl[3] = 40;



	cout << "Printing zahl: ";
	PrintArray(zahl);


	Array<string> str1;
	str1.resize(4);
	str1[0] = "He";
	str1[1] = "llo";
	str1[2] = " Wor";
	str1[3] = "ld!";



	cout << "Printing str1: ";
	PrintArray(str1);


	Array<char> char1;
	char1.resize(4);
	char1[0] = 'H';
	char1[1] = 'e';
	char1[2] = 'l';
	char1[3] = 'o';



	cout << "Printing char1: ";
	PrintArray(char1);
}


