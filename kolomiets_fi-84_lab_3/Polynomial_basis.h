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
	cout <<endl<< "Input degree in binary view:" << endl;
	cin >> vector;

	return revers_big_string(vector, vector.length());
}

string input_vector()
{
	string vector;
	cout <<endl<< "Input vector :" << endl;
	cin >> vector;

	return revers_big_string(vector, vector.length());
}

string input_generator()
{
	string vector;
	vector = "100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001000000001";
	cout <<endl<< "Input vector-generator :" << endl;
	cout << vector;
	/*cin >> vector;*/
	
	return revers_big_string(vector, vector.length());

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

string output_big_number_revers(int *mass, int size_mass)
{
	string result = "";

	for (int i = size_mass - 1; i >= 0; i--)
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
	cout << "[w] \tTesting block;" << endl;
	cout<< "[A] \t Output all operation;" << endl;
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
	mass[0] = 1;

	for (int i = 1; i < max; i++)
	{
		mass[i] = 0;
	}
	return mass;
}

int* add_vector(int* vector_1, int* vector_2, int* result, int size)
{
	for (int i=0;i<size;i++)
	{
		result[i] = (vector_1[i] + vector_2[i])%2;
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

int deg(int* vector,int size)
{
	int temp = size - 1;

	while (vector[temp]==0)
	{
		temp--;
	}
	return temp;
}

int* mod_by_generator(int* vector, int* generator, int* result, int size_first, int size_second)
{
	int* vector_ = new int[size_first];        null_(vector_, size_first);     copy_array(vector_, vector, size_first);
	int* generator_ = new int[size_first];     null_(generator_, size_first);  copy_array(generator_, generator, size_second);
	int* result_ = new int[size_first];        null_(result_, size_first);

	while (deg(vector_, size_first)>=deg(generator_, size_first)) 
	{
		int temp = deg(vector_, size_first) - deg(generator_, size_first);

		long_shift_digits_to_high(generator_, size_first, temp);

		add_vector(vector_, generator_, result_, size_first);

		null_(generator_, size_first);  copy_array(generator_, generator, size_second);

		copy_array(vector_, result_, size_first);

		null_(result_, size_first);

	}

	result=copy_array(result, vector_, size_second - 1);

	delete[] result_;
	delete[] generator_;
	delete[] vector_;

	return result;
}

int* multiplicative_vector(int* vector_1, int* vector_2, int* generator, int* result, int size)
{
	int* result_= new int[2*size+1];      null_(result_, 2 * size + 1);

	for (int i=0;i<size;i++)
	{
		for (int j=0;j<size;j++)
		{
			result_[i + j] = (result_[i + j] + vector_1[i] * vector_2[j])%2;
		}
	}

	mod_by_generator(result_, generator, result, 2 * size + 1, size + 1);

	delete[] result_;

	return result;
}

int* degree_elevation_in_two(int* vector, int* generator, int* result, int size)
{
	int* result_ = new int[2 * size + 1];      null_(result_, 2 * size + 1);

	for (int i = 0; i < size; i++)
	{
		result_[2*i] = vector[i];
	}

	mod_by_generator(result_, generator, result, 2 * size + 1, size + 1);

	delete[] result_;

	return result;

}

int* elevation_to_milty_degree(int* vector, int* degree, int* generator, int* result, int size)
{
	int* vector_ = new int[size]; copy_array(vector_, vector, size);
	int* _result = new int[size]; one_(_result, size);

	for (int i = 0; i < size; i++)
	{

		if (degree[i]==1)
		{
			multiplicative_vector(_result,vector_,generator, result, size);
			copy_array(_result, result, size); null_(result, size);
		}

		int* result_ = new int[size];
		degree_elevation_in_two(vector_,generator,result_,size);
		copy_array(vector_, result_, size);
		delete[] result_;
	}

	copy_array(result, _result, size);

	delete[] _result;
	delete[] vector_;

	return result;
}

int* trace_polynomial(int* vector, int* generator, int* result,int size)
{
	int* vector_ = new int[size]; copy_array(vector_, vector, size);
	int* _result = new int[size]; null_(_result, size); copy_array(_result, vector, size);


	for (int i = 0; i <=size; i++)
	{

		int* result_ = new int[size]; null_(result_, size);

		degree_elevation_in_two(vector_, generator, result_, size);

		add_vector(vector_, _result, _result, size);

		copy_array(vector_, result_, size);
		
		delete[] result_;

	}

	copy_array(result, _result, size);

	delete[] _result;
	delete[] vector_;

	return result;
}

int* inverse_vector(int* vector, int* generator, int* result, int size)
{
	int* degree = new int[size]; null_(degree, size);

	degree[0] = 0;

	for (int i = 1; i < size; i++)
	{
		degree[i] = 1;
	}

	elevation_to_milty_degree(vector, degree, generator, result, size);

	delete[] degree;

	return result;
}

int* test_evelation(int* vector, int* generator, int* result, int size)
{
	int* degree = new int[size];

	for (int i = 0; i < size; i++)
	{
		degree[i] = 1;
	}

	elevation_to_milty_degree(vector, degree, generator, result, size);

	delete[] degree;

	return result;
}


void testing(int* _vector_1,int* _vector_2,int* _generator, int expansion)
{
	cout << endl << "-first vector testing A^(2^m-1)=1:" << endl;
	int* result = new int[expansion - 1]; null_(result, expansion - 1);

	cout << output_big_number_revers(test_evelation(_vector_1, _generator, result, expansion - 1), expansion - 1) << endl;
	delete[] result;

	cout << endl << "-second vector testing  B^(2^m-1)=1:" << endl;
	int* result_ = new int[expansion - 1]; null_(result_, expansion - 1);
	cout << output_big_number_revers(test_evelation(_vector_2, _generator, result_, expansion - 1), expansion - 1) << endl;
	delete[] result_;


	_____________________________________________________

	string _vector_ = input_vector();

	int* _vector = new int[expansion - 1];    null_(_vector, expansion - 1);  convert_to_bin(_vector_, _vector);

	cout << endl << "-distriburtive operation testing (A+B)*C=B*C+C*A:" << endl;

	int* space = new int[expansion-1]; 
	int* space_ = new int[expansion - 1];
	int* _space = new int[expansion - 1];


	cout << endl << "-result (A+B)*C:" << endl;

	null_(space, expansion - 1);
	null_(space_, expansion - 1);

	add_vector(_vector_1, _vector_2, space, expansion - 1);

	multiplicative_vector(space, _vector, _generator, space_, expansion - 1);

	cout << output_big_number_revers(space_, expansion - 1) << endl;


	cout << endl << "-result B*C+C*A:" << endl;

	null_(space, expansion - 1);
	null_(space_, expansion - 1);
	null_(_space, expansion - 1);


	multiplicative_vector(_vector_1, _vector, _generator, space, expansion - 1);
	multiplicative_vector(_vector_2, _vector, _generator, space_, expansion - 1);

	add_vector(space, space_, _space, expansion - 1);

	cout << output_big_number_revers(_space, expansion - 1) << endl;

	delete[] _space;
	delete[] space_;
	delete[] space;

	delete[] _vector;

}

// algorithms block-end
