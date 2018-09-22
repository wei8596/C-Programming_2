#include <iostream>
using namespace std;

namespace arr
{
	typedef double* DoubleArrayPtr;
	
	class TwoD //two-dimensional arr 
	{
	public:
		TwoD(); // Default constructor
		TwoD(int rows, int columns); // Parametirzed constructor
		void setValue(int row, int column, int maxRows, int maxColumns, double value); // Set
		double getValue(int row, int column); // Retrieve
		// PointerValue is the "position" in the arr.
		friend const TwoD operator+ (const TwoD& arrA, const TwoD& arrB); // Overload + as friend to add to matrices of the same size
		TwoD& operator =(const TwoD& arr); // Overload =
		TwoD(const TwoD& object); // Copy constructor
		~TwoD(); // Destructor
	private:
		DoubleArrayPtr *m;
		int maxRows, maxColumns;
	};
}

int main()
{
	using namespace arr;
	
	int d1, d2;
	cout << "Enter the row and column dimensions of the array\n";
	cin >> d1 >> d2;

	TwoD arrA(d1, d2);
	int i, j;
	double num;
	cout << "Enter " << d1 << " rows of "
		 << d2 << " doubles each:\n";
	for (i = 0; i < d1; i++)
	{
		for (j = 0; j < d2; j++)
		{
			cin >> num;
			arrA.setValue(i, j, d1, d2, num);
		}
	}
	
	cout << "Echoing the 2 dim. array, matrix1\n";
	for (i = 0; i < d1; i++)
	{
		for(j = 0; j < d2; j++)
			cout << arrA.getValue(i, j) << " ";
		cout << endl;
	}
	
	
	/*cout << "\nEnter the row and column dimensions of the array\n";
	cin >> d1 >> d2;

	TwoD arrB(d1, d2);
	cout << "Enter " << d1 << " rows of "
		 << d2 << " doubles each:\n";
	for (i = 0; i < d1; i++)
	{
		for (j = 0; j < d2; j++)
		{
			cin >> num;
			arrB.setValue(i, j, d1, d2, num);
		}
	}
	
	cout << "Echoing the 2 dim. array, matrix2\n";
	for (i = 0; i < d1; i++)
	{
		for(j = 0; j < d2; j++)
			cout << arrB.getValue(i, j) << " ";
		cout << endl;
	}
	
	TwoD arrC;
	arrC = arrA + arrB;
	
	cout << "\nmatrix3 = matrix1 + matrix2(Overload + test)\n";
	for (i = 0; i < d1; i++)
	{
		for(j = 0; j < d2; j++)
			cout << arrC.getValue(i, j) << " ";
		cout << endl;
	}
	
	arrB = arrC;
	cout << "\nmatrix2 = matrix3(Overload = test)\n";
	for (i = 0; i < d1; i++)
	{
		for(j = 0; j < d2; j++)
			cout << arrB.getValue(i, j) << " ";
		cout << endl;
	}
	
	TwoD arrD(arrC);
	cout << "\n(Copy constructor test)\n";
	for (i = 0; i < d1; i++)
	{
		for(j = 0; j < d2; j++)
			cout << arrD.getValue(i, j) << " ";
		cout << endl;
	}*/

	return 0;
}

namespace arr
{
	TwoD::TwoD() // Default constuctor
	{
		maxRows = 3;
		maxColumns = 4;
		m = new DoubleArrayPtr[maxRows]; // dynamic arr of double.

		for (int i = 0; i < maxRows; i++)
			m[i] = new double[maxColumns];
		// m is now a 3-by-4 array.
	}

	TwoD::TwoD(int rows, int columns) // Parameterized Constructor.
	{
		maxRows = rows;
		maxColumns = columns;
		m = new DoubleArrayPtr[maxRows]; // dynamically allocated arr of double of setRows length

		for (int i = 0; i < maxRows; i++)
			m[i] = new double[maxColumns];
		// m is now a rows-by-columns array.
	}

	void TwoD::setValue(int row, int column, int maxRows, int maxColumns, double value) // Set
	{
		if (row >= maxRows)
			cout << "row should less than" << maxRows << endl;
		else if (column >= maxColumns)
			cout << "column should less than" << maxColumns << endl;
		else
			m[row][column] = value;
	}

	double TwoD::getValue(int row, int column) // Retrievie
	{
		return m[row][column];
	}

	const TwoD operator+ (const TwoD& arrA, const TwoD& arrB) // Overload +
	{
		TwoD arrSum(arrA.maxRows, arrA.maxColumns);

		for (int i = 0; i < arrA.maxRows; i++)
		{
			for (int j = 0; j < arrA.maxColumns; j++)
				arrSum.m[i][j] = arrA.m[i][j] + arrB.m[i][j];
		}

		return arrSum;
	}

	TwoD& TwoD::operator =(const TwoD& arr) // Overload =
	{
		if (maxRows != arr.maxRows || maxColumns != arr.maxColumns)
		{
			for (int i = 0; i < maxRows; i++)
				delete[] m[i];
			delete[] m;
		
			m = new DoubleArrayPtr[maxRows];
		}

		maxRows = arr.maxRows;
		maxColumns = arr.maxColumns;

		for (int i = 0; i < maxRows; i++)
			m[i] = new double[maxColumns];

		for (int i = 0; i < maxRows; i++)
		{
			for (int j = 0; j < maxColumns; j++)
				m[i][j] = arr.m[i][j];
		}

		return *this;
	}

	TwoD::TwoD(const TwoD &object) // Copy constructor
	{
		maxRows = object.maxRows;
		maxColumns = object.maxColumns;

		m = new DoubleArrayPtr[maxRows];

		for (int i = 0; i < maxRows; i++)
			m[i] = new double[maxColumns];

		for (int i = 0; i < maxRows; i++)
		{
			for (int j = 0; j < maxColumns; j++)
				m[i][j] = object.m[i][j];
		}
	}

	TwoD::~TwoD() // Destructor
	{
		for (int i = 0; i < maxRows; i++)
			delete[] m[i];	
		delete[] m;
	}
}
