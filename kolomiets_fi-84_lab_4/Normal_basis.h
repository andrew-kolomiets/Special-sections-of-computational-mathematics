#pragma once
#include <string>
using namespace std;

#define _____________________________________________________ cout<<endl<<"-------------------------------------------------------"<<endl;

// functional block-start

string revers_big_string(string mass, int number_of_symbols)
{
	int temp, i, j;

	for (i = 0, j = number_of_symbols - 1; i < j; i++, j--)
	{
		temp = mass[i];
		mass[i] = mass[j];
		mass[j] = temp;
	}

	return mass;
}

string input_degree()
{
	string vector;
	cout << "-input degree in binary view:" << endl;
	cin >> vector;

	return revers_big_string(vector, vector.length());
}

string input_vector()
{
	string vector;
	cout << "Input vector :" << endl;
	cin >> vector;

	return vector;
}

int string_to_bin(char symbol_of_string)
{

	if (symbol_of_string == '0') { return 0; }
	if (symbol_of_string == '1') { return 1; }

}

int* convert_to_bin(string vector, int* mass)
{
	for (int i = 0; vector[i] != '\0'; i++)
	{
		mass[i] = string_to_bin(vector[i]);
	}


	return mass;
}

string bin_to_string(int symbol_of_string)
{

	if (symbol_of_string == 0) { return "0"; }
	if (symbol_of_string == 1) { return "1"; }

}

string output_(int *mass, int size_mass)
{
	string result = "";

	for (int i = 0;i<size_mass; i++)
	{
		result = result + (bin_to_string(mass[i]) + " ");
	}

	return result;
}

int* copy_array(int* mass_1, int* mass_2, int size)
{
	for (int i = 0; i < size; i++)
	{
		mass_1[i] = mass_2[i];
	}

	return mass_1;
}

void total_comander()
{
	cout << "Input operation whith we want:" << endl;
	cout << endl;

	cout << "[0] \tConstant 0;" << endl;
	cout << "[1] \tConstant 1;" << endl;
	cout << "[+] \tAdd;" << endl;
	cout << "[*] \tMultiplication;" << endl;
	cout << "[^] \tElevation to multi-digit degree;" << endl;
	cout << "[s] \tElevation to degree equel two;" << endl;
	cout << "[i] \tInverted element;" << endl;
	cout << "[t] \tTrace;" << endl;
	cout << "[w] \tTesting block;" << endl;;
}

// functional block-end


// algorithms block-start

int* null_(int* mass, int max)
{
	for (int i = 0; i < max; i++)
	{
		mass[i] = 0;
	}
	return mass;
}

int* one_(int* mass, int max)
{
	for (int i = 0; i < max; i++)
	{
		mass[i] = 1;
	}

	return mass;
}

int* add_vector(int* vector_1, int* vector_2, int* result, int size)
{
	for (int i = 0; i < size; i++)
	{
		result[i] = (vector_1[i] + vector_2[i]) % 2;
	}

	return result;
}

int* long_shift_digits_to_high(int* mass_, int max, int shiftBy)
{
	int* _mass = new int[shiftBy];

	int j = 0;


	for (int i = max - shiftBy; i < max; i++)
	{
		_mass[j] = mass_[i];
		j++;
	}

	for (int i = 0; i < max - shiftBy; i++)
	{
		mass_[(max - 1) - i] = mass_[(max - shiftBy - 1) - i];
	}

	for (int i = 0; i < shiftBy; i++)
	{
		mass_[i] = _mass[i];
	}


	delete[] _mass;

	return mass_;
}

int* long_shift_digits_to_lower(int* mass_, int max, int shiftBy)
{
	int* _mass = new int[shiftBy];

	int j = 0;


	for (int i =0; i < shiftBy; i++)
	{
		_mass[j] = mass_[i];
		j++;
	}

	for (int i = shiftBy; i <max; i++)
	{
		mass_[i-shiftBy] = mass_[i];
	}

	for (int i = 0; i < shiftBy; i++)
	{
		mass_[max - shiftBy+i] = _mass[i];
	}

	delete[] _mass;

	return mass_;
}

int trace_polynomial(int* vector,int size)
{
	int result = 0;

	for (int i = 0; i < size; i++)
	{
		result = result + vector[i];
	}

	return (result%2);
}

int* elevation_in_square(int* vector,int* result, int size)
{
	return long_shift_digits_to_high(copy_array(result, vector, size),size,1);
}

int mod(int number,int module)
{
	

	if (number <0)
	{
		while (number<0)
		{
			number = module - abs(number);
		}

		return number;
	}
	else
	{
		return (number % module);
	}
 
}

int gorner_mod(int number,int degree,int module)
{
	int result = 1;

	for (int i = 0; i < (sizeof(degree) * 8 - 1); i++)
	{
		int temp=(int)((degree>> i) & 1);

		if (temp==1)
		{
			result = (result *number)%module;
		}
		number = (number * number)%module;
	}

	return result;
}

int coefitient_matrix(int i, int j, int module)
{

	int temp_1 = gorner_mod(2,i,module);
	int temp_2 = gorner_mod(2, j, module);

	if (mod(temp_1+temp_2,module)  == 1)
	{
		return 1;
	}
	if (mod(temp_1 - temp_2, module) == 1)
	{
		return 1;
	}
	if (mod(-temp_1 + temp_2, module) == 1)
	{
		return 1;
	}
	if (mod(-temp_1 - temp_2, module) == 1)
	{
		return 1;
	}
	else
	{
		return 0;
	}

}

int** initialization_multiplicative_matrix(int** matrix,int size)
{
	int module = (2 * size + 1);

	for (int i=0;i<size;i++)
	{
		for (int j=0;j<size;j++)
		{
			matrix[i][j] = coefitient_matrix(i,j, module);
		}
	}

	return matrix;
}

int multiplication_matrix(int* _vector,int** matrix,int* vector_, int size)
{
	int coefitient=0;

	int* temp = new int[size]; null_(temp, size);

	for (int j = 0; j < size; j++)
	{
		for (int i = 0; i < size; i++)
		{
			temp[j] = (temp[j]+(_vector[i] * matrix[i][j]))%2;
		}
	}

	for (int i = 0; i < size; i++)
	{
		coefitient = (coefitient + (temp[i] * vector_[i]))%2;
	}

	delete[] temp;

	return coefitient;
}

int* multiplication(int* _vector, int** matrix, int* vector_, int* result, int size)
{
	int* first = new int[size];  copy_array(first, _vector,size);
	int* second = new int[size]; copy_array(second, vector_, size);

	int* temp_ = new int[size];

	for (int i = 0; i < size; i++)
	{
		
		temp_[i]=multiplication_matrix(first,matrix, second,size);
		long_shift_digits_to_lower(first, size, 1);
		long_shift_digits_to_lower(second, size, 1);
	}

	copy_array(result, temp_, size);

	delete[] temp_;

	delete[] second;
	delete[] first;

	return result;
}

int* elevation_to_milty_degree(int* vector, int* degree, int** matrix, int* result, int size)
{
	int* _result = new int[size]; one_(_result, size);

	for (int i = 0; i < size; i++)
	{

		if (degree[i] == 1)
		{
			multiplication(_result, matrix, vector, result, size);
			copy_array(_result, result, size); null_(result, size);
		}

		int* result_ = new int[size];
        elevation_in_square(vector, result_,size);
		copy_array(vector, result_, size);
		delete[] result_;
	}

	copy_array(result, _result, size);

	delete[] _result;

	return result;
}

int* inverse_vector(int* vector,int**matrix, int* result, int size)
{
	int* degree = new int[size]; null_(degree, size);

	degree[0] = 0;

	for (int i = 1; i < size; i++)
	{
		degree[i] = 1;
	}

	elevation_to_milty_degree(vector, degree, matrix, result, size);

	delete[] degree;

	return result;
}

int* test_evelation(int* vector, int**matrix, int* result, int size)
{
	int* degree = new int[size];

	for (int i = 0; i < size; i++)
	{
		degree[i] = 1;
	}

	elevation_to_milty_degree(vector, degree, matrix, result, size);

	delete[] degree;

	return result;
}

void testing(int* _vector_1, int* _vector_2, int**matrix, int expansion)
{
	cout << endl << "First vector testing A^(2^m-1)=1:" << endl;
	int* result = new int[expansion]; null_(result, expansion);

	cout << output_(test_evelation(_vector_1, matrix, result, expansion), expansion) << endl;
	delete[] result;

	cout << endl << "Second vector testing  B^(2^m-1)=1:" << endl;
	int* result_ = new int[expansion]; null_(result_, expansion);
	cout << output_(test_evelation(_vector_2, matrix, result_, expansion), expansion) << endl;
	delete[] result_;


	_____________________________________________________

	string _vector_ = input_vector();

	int* _vector = new int[expansion];    null_(_vector, expansion);  convert_to_bin(_vector_, _vector);

	cout << endl << "Distriburtive operation testing (A+B)*C=B*C+C*A:" << endl;

	int* space = new int[expansion];
	int* space_ = new int[expansion];
	int* _space = new int[expansion];


	cout << endl << "-result (A+B)*C:" << endl;

	add_vector(_vector_1, _vector_2, space, expansion);

	multiplication(space, matrix, _vector, space_, expansion);

	cout << output_(space_, expansion) << endl;


	cout << endl << "-result B*C+C*A:" << endl;

	multiplication(_vector_1, matrix, _vector, space, expansion);
	multiplication(_vector_2, matrix, _vector, space_, expansion);

	add_vector(space, space_, _space, expansion);

	cout << output_(_space, expansion) << endl;

	delete[] _space;
	delete[] space_;
	delete[] space;

	delete[] _vector;

}


// algorithms block-end