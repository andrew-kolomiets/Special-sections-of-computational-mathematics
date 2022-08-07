#pragma once

#include <string>
#include <cstdint>
#include <cmath>
using namespace std;

#define string_number ((int)'0')
#define int_ int
#define ____________________________________________________________________________________ cout<<endl<<"-------------------------------------------------------------------"<<endl;


// function first-labs

int_ hex_string_to_decimal(char symbol_of_string)
{

	if (symbol_of_string == '0') { return 0; }
	if (symbol_of_string == '1') { return 1; }
	if (symbol_of_string == '2') { return 2; }
	if (symbol_of_string == '3') { return 3; }
	if (symbol_of_string == '4') { return 4; }
	if (symbol_of_string == '5') { return 5; }
	if (symbol_of_string == '6') { return 6; }
	if (symbol_of_string == '7') { return 7; }
	if (symbol_of_string == '8') { return 8; }
	if (symbol_of_string == '9') { return 9; }
	if (symbol_of_string == 'A') { return 10; }
	if (symbol_of_string == 'B') { return 11; }
	if (symbol_of_string == 'C') { return 12; }
	if (symbol_of_string == 'D') { return 13; }
	if (symbol_of_string == 'E') { return 14; }
	if (symbol_of_string == 'F') { return 15; }

}

string decimal_int_to_hex(int_ symbol_of_string)
{

	if (symbol_of_string == 0) { return "0"; }
	if (symbol_of_string == 1) { return "1"; }
	if (symbol_of_string == 2) { return "2"; }
	if (symbol_of_string == 3) { return "3"; }
	if (symbol_of_string == 4) { return "4"; }
	if (symbol_of_string == 5) { return "5"; }
	if (symbol_of_string == 6) { return "6"; }
	if (symbol_of_string == 7) { return "7"; }
	if (symbol_of_string == 8) { return "8"; }
	if (symbol_of_string == 9) { return "9"; }
	if (symbol_of_string == 10) { return "A"; }
	if (symbol_of_string == 11) { return "B"; }
	if (symbol_of_string == 12) { return "C"; }
	if (symbol_of_string == 13) { return "D"; }
	if (symbol_of_string == 14) { return "E"; }
	if (symbol_of_string == 15) { return "F"; }

}

string revers_big_string_(string mass, int_ number_of_symbols)
{
	int_ temp, i, j;

	for (i = 0, j = number_of_symbols - 1; i < j; i++, j--)
	{
		temp = mass[i];
		mass[i] = mass[j];
		mass[j] = temp;
	}

	return mass;
}

string input_big_number_() // we must to input the data start
{
	string big_number;
	cout << "Input big number :" << endl;
	cin >> big_number;

	return revers_big_string_(big_number, big_number.length());

}

string input_big_number_distributivity() // we must to input the data start
{
	string big_number;
	cout << endl << "-input big number for distributivity :" << endl;
	cin >> big_number;

	return revers_big_string_(big_number, big_number.length());

}

void check_reversing_string(string big_number_1, string big_number_2, string modules)
{
	cout << "Check the converting string:" << endl;

	cout << endl << big_number_1 << endl;

	cout << endl << big_number_2 << endl;

	cout << endl << modules << endl;

}

int_ max_(int_ big_number_1, int_ big_number_2)
{
	if (big_number_1 > big_number_2)
	{
		return big_number_1;
	}
	else
	{
		return big_number_2;
	}
}

int_ number_of_massive_which_is_max(string big_number_1, string big_number_2)
{
	int_ max_number = max_(big_number_1.length(), big_number_2.length());

	return max_number;
}

int_* null_(int_* mass, int_ max)
{
	for (int_ i = 0; i < max; i++)
	{
		mass[i] = 0;
	}
	return mass;
}

string output_big_number_for_null(int_ *mass, int_ size_mass)
{
	string big_number = "";
	for (int_ i = size_mass - 1; i != -1; i--)
	{
		big_number = big_number + (char)(mass[i] + string_number) + ' ';
	}
	return big_number;
}

int_* convert_big_number_(string big_number, int_* mass)
{
	for (int i = 0; big_number[i] != '\0'; i++)
	{
		mass[i] = hex_string_to_decimal(big_number[i]);
	}


	return mass;
}

string output_big_number_revers(int_ *mass, int_ size_mass)
{
	string result = "";

	for (int i = size_mass - 1; i >= 0; i--)
	{
		result = result + (decimal_int_to_hex(mass[i]) + " ");
	}

	return result;
}

int_* copy_array(int_* mass_1, int_* mass_2, int_ size)
{
	for (int_ i = 0; i < size; i++)
	{
		mass_1[i] = mass_2[i];
	}

	return mass_1;
}

string hex_bin_string_revers(string big_number_revers)
{
	string binary_revers_big_number = "";
	for (int_ i = 0; i < (big_number_revers.length()); i++)
	{
		if (big_number_revers[i] == '0') { binary_revers_big_number += "0000"; }
		if (big_number_revers[i] == '1') { binary_revers_big_number += "1000"; }
		if (big_number_revers[i] == '2') { binary_revers_big_number += "0100"; }
		if (big_number_revers[i] == '3') { binary_revers_big_number += "1100"; }
		if (big_number_revers[i] == '4') { binary_revers_big_number += "0010"; }
		if (big_number_revers[i] == '5') { binary_revers_big_number += "1010"; }
		if (big_number_revers[i] == '6') { binary_revers_big_number += "0110"; }
		if (big_number_revers[i] == '7') { binary_revers_big_number += "1110"; }
		if (big_number_revers[i] == '8') { binary_revers_big_number += "0001"; }
		if (big_number_revers[i] == '9') { binary_revers_big_number += "1001"; }
		if (big_number_revers[i] == 'A') { binary_revers_big_number += "0101"; }
		if (big_number_revers[i] == 'B') { binary_revers_big_number += "1101"; }
		if (big_number_revers[i] == 'C') { binary_revers_big_number += "0011"; }
		if (big_number_revers[i] == 'D') { binary_revers_big_number += "1011"; }
		if (big_number_revers[i] == 'E') { binary_revers_big_number += "0111"; }
		if (big_number_revers[i] == 'F') { binary_revers_big_number += "1111"; }

	}

	int_ i = binary_revers_big_number.length() - 1;

	while (binary_revers_big_number[i] == '0')
	{
		binary_revers_big_number.erase(i, 1);
		i--;
	}

	return binary_revers_big_number;
}

int_* string_to_integer(string hex_bin, int_* mass_bin, int_ size)
{
	for (int_ i = 0; i < size; i++)
	{
		mass_bin[i] = (((int)hex_bin[i]) - (int)'0');
	}
	return mass_bin;
}

int_ size_number(int_* mass, int_ size) // help function
{
	int_ nulls = 0, digits = 0;

	int_ count = size - 1;

	while (mass[count] == 0)
	{
		nulls++;
		count--;
	}

	digits = size - nulls;

	return digits;
}


// function second-labs

string input_number_for_degree_or_mod_(string number_moduls)
{
	cout << endl << "Input module number for operation:" << endl;

	cin >> number_moduls;

	number_moduls = revers_big_string_(number_moduls, number_moduls.length());

	return  number_moduls;
}

char small_to_big(char symbol_of_string)
{
	
		if (symbol_of_string == '0') { return 0; }
		if (symbol_of_string == '1') { return 1; }
		if (symbol_of_string == '2') { return 2; }
		if (symbol_of_string == '3') { return 3; }
		if (symbol_of_string == '4') { return 4; }
		if (symbol_of_string == '5') { return 5; }
		if (symbol_of_string == '6') { return 6; }
		if (symbol_of_string == '7') { return 7; }
		if (symbol_of_string == '8') { return 8; }
		if (symbol_of_string == '9') { return 9; }
		if (symbol_of_string == 'a') { return 10; }
		if (symbol_of_string == 'b') { return 11; }
		if (symbol_of_string == 'c') { return 12; }
		if (symbol_of_string == 'd') { return 13; }
		if (symbol_of_string == 'e') { return 14; }
		if (symbol_of_string == 'f') { return 15; }
	
}

int_* binary_hex(int_ number, int_* hex_)
{
	int_* binary = new int_[sizeof(number) * 8 - 1];

	for (int_ i = 0; i < (sizeof(number) * 8 - 1); i++)
	{
		binary[i] = (int_)((number >> i) & 1);
	}

	int_** temp = new int_*[sizeof(number) * 2];

	for (int_ i = 0; i < sizeof(number) * 2; i++)
	{
		temp[i] = new int_[4];
	}

	for (int_ i= 0; i < (sizeof(number) * 2); i++)
	{
		for (int_ j = 0; j < 4; j++)
		{
			temp[i][j] = 0;
		}
	}
	///////////////////////////////////////////////////////

	for (int_ i = 0; i < (sizeof(number) * 2); i++)
	{
		for (int_ j = 0; j < 4; j++)
		{
			if (i * 4 + j != sizeof(number) * 8 - 1)
			{
				temp[i][j] = binary[i * 4 + j];
			}
			if (i * 4 + j == sizeof(number) * 8 - 1)
			{
				break;
			}

		}

	}

	for (int_ i = 0; i < (sizeof(number) * 2); i++)
	{
		for (int_ j = 0; j < 4; j++)
		{
			hex_[i] = hex_[i] + ((int_)pow(2, j))*temp[i][j];
		}
	}

	//////////////////////////////////////////////////////

	for (int_ i = 0; i < sizeof(number) * 2; i++)
	{
		delete[] temp[i];
	}

	delete[] temp;

	delete[] binary;

	return hex_;
}

int_* binary_(int_ number, int_*mass)
{
	int_* binary = new int_[sizeof(number) * 8 - 1];

	for (int_ i = 0; i < (sizeof(number) * 8 - 1); i++)
	{
		binary[i] = (int_)((number >> i) & 1);
	}

	copy_array(mass, binary, sizeof(number) * 8 - 1);

	delete[] binary;

	return mass;
}


// total_comander is common

void total_comander()
{

	cout << "Input operation whith we want:" << endl;
	cout << endl;
	
	cout << "[m] \tGive the number by (x)mod(n);" << endl;
	cout << "[+] \tAdd number by (a+b)mod(n);" << endl;
	cout << "[-] \tSubstraction number by (a-b)mod(n);" << endl;
	cout << "[*] \tMultiplication by (a*b)mod(n);" << endl;
	cout << "[^] \tElevation to multi-digit degree by (a^b)mod(n);" << endl;
	cout << "[L] \tLeast common multiple;" << endl;
	cout << "[G] \tThe largest common divisor;" << endl;
	cout << "[D] \tDistributivity testing (A+B)*C=C*(A+B)=A*C+B*C for moduls;" << endl;
	cout << "[C] \t Complexyty testing for moduls;" << endl;
	
	cout << endl;
	cout << "In other case  you to receive an error." << endl;
}


//operation on big number first-labs

int_ ask_null_or_not(int_* mass, int_ max)
{
	int_ task = 0;
	for (int_ i = 0; i < max; i++)
	{
		if (mass[i] == 0)
		{
			task = 0;
		}
		else
		{
			task = 1;
			break;
		}

	}

	return task;
}

int_* constant_null(int_* mass, int_ size) { return null_(mass, size); }

int_* constant_one(int_* mass, int_ size) { null_(mass, size); mass[0] = 1; return mass; }

int_* long_add(int_ *mass_1, int_ *mass_2, int_ *mass_, int_ max, int_ system_base)
{
	int_ temp;
	int_ carry = 0;
	int_ digit = pow(2, system_base) - 1;
	for (int i = 0; i < max; i++)
	{
		temp = mass_1[i] + mass_2[i] + carry;
		mass_[i] = temp & digit;
		carry = temp >> system_base;
	}

	if (carry != 0) { mass_[max] = carry; }

	return mass_;
}

int_* long_sub(int_ *mass_1, int_*  mass_2, int_* mass_, int_ max, int_ system_base)
{
	int_ temp;
	int_ borrow = 0;
	int_ digit = pow(2, system_base);

	for (int i = 0; i < max; i++)
	{
		temp = mass_1[i] - mass_2[i] - borrow;
		if (temp >= 0)
		{
			mass_[i] = temp;
			borrow = 0;
		}
		else
		{
			mass_[i] = digit + temp;
			borrow = 1;
		}

	}
	return mass_;
}

int_ long_compare(int_ *mass_1, int_*  mass_2, int_ max)
{
	int i = max - 1;

	while (mass_1[i] == mass_2[i] && i >= 0) { i = i - 1; }

	if (i == -1) { return 0; }
	else
	{
		if (mass_1[i] > mass_2[i]) { return 1; }
		else { return -1; }
	}
}

int_* long_mul_one_digit(int_*mass_1, int_*mass_2, int_* mass_, int_ system_base, int_ index, int_ max) //here is ok
{
	int_ carry = 0;
	int_ temp = 0;


	int_ digit = ((pow(2, system_base)) - 1);


	for (int i = 0; i < max / 2; i++)
	{
		temp = mass_1[i] * mass_2[index] + carry;
		mass_[i] = temp & digit;
		carry = temp >> system_base;
	}
	mass_[max / 2] = carry;

	return mass_;
}

int_* long_shift_digits_to_high(int_* mass_, int_ max, int_ shiftBy)
{
	int_* _mass = new int_[shiftBy];

	int_ j = 0;


	for (int_ i = max - shiftBy; i < max; i++)
	{
		_mass[j] = mass_[i];
		j++;
	}

	for (int_ i = 0; i < max - shiftBy; i++)
	{
		mass_[(max - 1) - i] = mass_[(max - shiftBy - 1) - i];
	}

	for (int_ i = 0; i < shiftBy; i++)//ok
	{
		mass_[i] = _mass[i];
	}


	delete[] _mass;

	return mass_;
}

int_* long_mul(int_*mass_1, int_*mass_2, int_* result, int_ system_base, int_ max)
{

	int_* mass_ = new int_[max - 1];

	null_(mass_, max - 1);

	for (int i = 0; i < (max - 1) / 2; i++)
	{

		mass_ = long_mul_one_digit(mass_1, mass_2, mass_, system_base, i, (max - 1));

		long_shift_digits_to_high(mass_, max - 1, i);

		long_add(result, mass_, result, max - 1, system_base); //here is problem maybi for elevation to degree

		null_(mass_, max - 1);
	}

	delete[] mass_;

	return result;
}

int_ number_of_nulls(int_* mass_, int_ max)
{
	int number = 0;
	int count = max - 1;
	while (mass_[count] == 0)
	{
		number++;
		count = count - 1;
	}

	return number;
}

int_* long_shift_digits_to_high_for_division(int_* mass_, int_ max, int_ shiftBy)
{
	/*int_ temp;

	for (int i = 0; i < shiftBy; i++)
	{
		temp = mass_[max - 1];

		for (int j = max - 2; j >= 0; j--)
		{
			mass_[j + 1] = mass_[j];
		}

		m
ass_[0] = temp;
	}

	return mass_;*/

	int_* _mass = new int_[shiftBy];

	int_ j = 0;


	for (int_ i = max - shiftBy; i < max; i++)
	{
		_mass[j] = mass_[i];
		j++;
	}

	for (int_ i = 0; i < max - shiftBy; i++)
	{
		mass_[(max - 1) - i] = mass_[(max - shiftBy - 1) - i];
	}

	for (int_ i = 0; i < shiftBy; i++)//ok
	{
		mass_[i] = _mass[i];
	}


	delete[] _mass;

	return mass_;
}

void long_division(int_* mass_1, int_* dividor, int_* quotien, int_*remainder, int_ system_base, int_ max)
{

	int_ size_dividor = 0;
	int_ size_remainder = 0;

	size_dividor = max - number_of_nulls(dividor, max);

	remainder = copy_array(remainder, mass_1, max);

	while ((long_compare(remainder, dividor, max) == 0) || (long_compare(remainder, dividor, max) == 1))
	{

		size_remainder = max - number_of_nulls(remainder, max);

		int_* array_for_substraction = new int_[max];
		null_(array_for_substraction, max);
		array_for_substraction = copy_array(array_for_substraction, dividor, max);

		array_for_substraction = long_shift_digits_to_high_for_division(array_for_substraction, max, (size_remainder - size_dividor));

		if (long_compare(remainder, array_for_substraction, max) == -1)
		{
			size_remainder = size_remainder - 1;
			null_(array_for_substraction, max);
			array_for_substraction = copy_array(array_for_substraction, dividor, max);
			array_for_substraction = long_shift_digits_to_high_for_division(array_for_substraction, max, (size_remainder - size_dividor));
		}

		int_* save_the_result_1 = new int_[max];
		int_* save_the_result_2 = new int_[max];
		int_* bit_go = new int_[max];

		null_(save_the_result_1, max);
		null_(save_the_result_2, max);

		long_sub(remainder, array_for_substraction, save_the_result_1, max, system_base);

		copy_array(remainder, save_the_result_1, max);

		bit_go = null_(bit_go, max);

		bit_go[size_remainder - size_dividor] = 1;

		long_add(quotien, bit_go, save_the_result_2, max, system_base);
		copy_array(quotien, save_the_result_2, max);

		delete[] bit_go;
		delete[] save_the_result_2;
		delete[] save_the_result_1;
		delete[] array_for_substraction;
	}


}

int_* long_power(int_* lower, int_* upper, int_ down, int_ up, int_* result, int_ size_result, int_ system_base)
{

	int_ _down = down, down_ = down;

	int_* _temp = new int_[size_result];
	int_* temp_ = new int_[size_result];

	null_(_temp, size_result);
	null_(temp_, size_result);

	_temp = copy_array(_temp, lower, down);
	temp_ = copy_array(temp_, lower, down);

	int_ j = 0;

	for (int_ i = 0; i < up; i++)
	{


		if (i == 0) { j = 1; }

		if (upper[i] == 1)
		{
			_down = 2 * down_ + 1;

			int_* mass_ = new int_[_down];

			null_(mass_, _down);
			copy_array(mass_, result, _down);
			null_(result, _down);

			if (j == 1) { null_(mass_, _down); mass_[0] = 1; j = 0; }

			result = long_mul(mass_, temp_, result, system_base, _down);

			delete[] mass_;

		}

		if (i != up - 1)
		{
			down_ = 2 * (down_)+1;
			int_* temp = new int_[down_];
			null_(temp, down_);
			temp = long_mul(_temp, temp_, temp, system_base, down_);
			_temp = copy_array(_temp, temp, down_);
			temp_ = copy_array(temp_, temp, down_);
			delete[] temp;
		}

	}


	delete[] temp_;
	delete[] _temp;

	return result;

}

void test_distributivity(int_* mass_1, int_* mass_2, int_* mass_3, int_ old_size, int_ new_size, int_ size_result, int_ system_base)
{
	int_* _mass_1 = new int_[size_result];
	int_* _mass_2 = new int_[size_result];
	int_* _mass_3 = new int_[size_result];
	int_* mass_ = new int_[size_result];
	int_* _mass = new int_[size_result];
	int_* result = new int_[size_result];

	null_(_mass_1, size_result);
	null_(_mass_2, size_result);
	null_(_mass_3, size_result);
	null_(mass_, size_result);
	null_(_mass, size_result);
	null_(result, size_result);

	copy_array(_mass_1, mass_1, old_size);
	copy_array(_mass_2, mass_2, old_size);
	copy_array(_mass_3, mass_3, new_size);


	cout << endl << "-result addition (A+B):" << endl;
	mass_ = long_add(_mass_1, _mass_2, mass_, size_result, system_base);
	cout << output_big_number_revers(mass_, size_result) << endl;

	cout << endl << "-result multiplication C*(A+B):" << endl;

	result = long_mul(mass_, _mass_3, result, system_base, size_result);
	cout << output_big_number_revers(result, size_result) << endl;
	null_(result, size_result);

	cout << endl << "-result multiplication (A+B)*C:" << endl;

	result = long_mul(_mass_3, mass_, result, system_base, size_result);
	cout << output_big_number_revers(result, size_result) << endl;
	null_(result, size_result);

	cout << endl << "-result multiplication A*C:" << endl;

	null_(mass_, size_result);
	mass_ = long_mul(_mass_1, _mass_3, mass_, system_base, size_result);
	cout << output_big_number_revers(mass_, size_result) << endl;

	cout << endl << "-result multiplication B*C:" << endl;

	_mass = long_mul(_mass_2, _mass_3, _mass, system_base, size_result);
	cout << output_big_number_revers(_mass, size_result) << endl;

	cout << endl << "-result addition A*C+B*C:" << endl;

	int_* mass = new int_[size_result + 1];
	null_(mass, size_result + 1);
	cout << output_big_number_revers(long_add(mass_, _mass, mass, size_result, system_base), size_result + 1) << endl;
	delete[] mass;


	delete[] result;
	delete[] _mass;
	delete[] mass_;
	delete[] _mass_3;
	delete[] _mass_2;
	delete[] _mass_1;



}

void test_complexity(int_* mass_1, int_* mass_2, int_ max, int_ system_base)
{
	int_* remainder = new int_[max]; null_(remainder, max);
	int_* quotient = new int_[max]; null_(quotient, max);

	long_division(mass_1, mass_2, quotient, remainder, system_base, max);

	cout << endl << "Result division A\B:" << endl;

	cout << endl << "-quotient:" << endl;
	cout << output_big_number_revers(quotient, max) << endl;
	cout << endl << "-remainder:" << endl;
	cout << output_big_number_revers(remainder, max) << endl;

	cout << endl << "Result revers operation B*Q+R=A:" << endl;

	int_* temp = new int_[2 * max + 1]; null_(temp, 2 * max + 1);

	long_mul(mass_2, quotient, temp, system_base, 2 * max + 1);

	cout << endl << "-multiply B*Q:" << endl;

	cout << output_big_number_revers(temp, 2 * max + 1) << endl;

	int_ size_temp = size_number(temp, 2 * max + 1);
	int_ size_remainder = size_number(remainder, max);

	size_temp = max_(size_temp, size_remainder);

	int_* result = new int_[max]; null_(result, max);

	long_add(remainder, temp, result, max, system_base);

	cout << endl << "-addition B*Q+R:" << endl;

	cout << output_big_number_revers(result, max) << endl;

	delete[] result;
	delete[] temp;

	delete[] quotient;
	delete[] remainder;


}


//operation on big number second-labs

/// ~brute force - start

int_* operation_mod_(int_* long_number, int_* module, int_* result, int_ system_base, int_ max) // size result , modele, and number is iqual
{
	// size of all array we make similar

	if (long_compare(long_number, module, max) == 0 || long_compare(long_number, module, max) == 1)
	{
		int_* quotient = new int_[max]; null_(quotient, max);
		int_* remainder = new int_[max]; null_(remainder, max);

		long_division(long_number, module, quotient, remainder, system_base, max); ////here problem

		copy_array(result, remainder, max);

		delete[] remainder;
		delete[] quotient;

	}
	else
	{
		copy_array(result, long_number, max);
	}

	return result;
}

int_* add_mod_(int_* first, int_* second, int_* mod, int_* result, int_ system_base, int_ max)
{

	int_* mass_ = new int_[max];

	null_(mass_, max);

	mass_ = long_add(first, second, mass_, max - 1, system_base);

	operation_mod_(mass_, mod, result, system_base, max);

	delete[] mass_;

	return result;
}

int_* substract_mod_(int_* first, int_* second, int_* mod, int_* result, int_ system_base, int_ max)
{

	int_* mass_ = new int_[max];

	null_(mass_, max);

	if (long_compare(first, second, max) == 0 || long_compare(first, second, max) == 1)
	{
		mass_ = long_sub(first, second, mass_, max, system_base);
		operation_mod_(mass_, mod, result, system_base, max);
	}
	else
	{
		int_* _mass = new int_[max];
		null_(_mass, max);

		mass_ = long_sub(first, second, mass_, max, system_base);
		_mass = operation_mod_(mass_, mod, _mass, system_base, max);
		long_sub(mod, _mass, result, max, system_base);
		delete[] _mass;
	}
	delete[] mass_;
	return result;
}

int_* multiplication_mod_(int_* first, int_* second, int_* mod, int_* result, int_ system_base, int_ max)
{

	int_* mass_ = new int_[max];

	null_(mass_, max);

	long_mul(first, second, mass_, system_base, max);

	operation_mod_(mass_, mod, result, system_base, max);

	delete[] mass_;

	return result;
}

/// ~brute force - end


/// ~reduction block-start

int_* function_kill_digit(int_* mass, int_ size, int_ number_kill_digit) // testing is ok for critical space
{
	for (int_ i = 0; i < size - number_kill_digit; i++)
	{
		mass[i] = mass[number_kill_digit + i];
	}

	for (int_ i = size - number_kill_digit; i < size; i++)
	{
		mass[i] = 0;
	}

	return mass;
}

bool lenth_is_ok_or_not(int_* _mass, int_* module, int_ size, int_ system_base) // help function
{
	int_* mass_ = new int_[2 * size + 1]; null_(mass_, 2 * size + 1); copy_array(mass_, _mass, size);

	int_* module_ = new int_[size]; null_(module_, size); copy_array(module_, module, size);

	int_* result = new int_[2 * size + 1]; null_(result, 2 * size + 1);

	result = long_mul(module, module_, result, system_base, 2 * size + 1);

	if (long_compare(mass_, result, 2 * size + 1) == -1)
	{
		delete[] module_;
		delete[] result;
		delete[] mass_;

		return true;
	}

	else
	{
		delete[] module_;
		delete[] result;
		delete[] mass_;

		return false;
	}
}

int_* coefitient_barrett_(int_* module_number, int_* coefitient_barrett, int_ size, int_ system_base)
{

	int_ size_coeficient = 2 * size_number(module_number, size) + 1;

	for (int_ i = 0; i < size_coeficient; i++)
	{
		coefitient_barrett[i] = 0;
	}

	coefitient_barrett[size_coeficient - 1] = 1;

	int_* quotient = new int_[size_coeficient]; null_(quotient, size_coeficient);
	int_* remainder = new int_[size_coeficient]; null_(remainder, size_coeficient);

	int_* _module = new int_[size_coeficient]; null_(_module, size_coeficient); copy_array(_module, module_number, size_number(module_number, size));

	long_division(coefitient_barrett, _module, quotient, remainder, system_base, size_coeficient);

	copy_array(coefitient_barrett, quotient, size_coeficient);

	delete[] _module;
	delete[] remainder;
	delete[] quotient;

	return coefitient_barrett;
}

int_* algorithm_barrett_(int_* long_number, int_* module_number, int_* coefitient_barrett, int_* result, int_ size, int_ system_base, int_ max_for_coeficient)
{
	int_ max = max_(size, max_for_coeficient);

	int_* quotient_ = new int_[max];           null_(quotient_, max);
	int_* quotient = new int_[max];            null_(quotient, max);
	int_* remainder = new int_[max];           null_(remainder, max);

	int_* long_number_ = new int[max];          null_(long_number_, max);          copy_array(long_number_, long_number, size);
	int_* module_number_ = new int[max];        null_(module_number_, max);        copy_array(module_number_, module_number, size);
	int_* coefitient_barrett_ = new int[max];   null_(coefitient_barrett_, max);   copy_array(coefitient_barrett_, coefitient_barrett, size_number(coefitient_barrett, max_for_coeficient));

	copy_array(quotient_, function_kill_digit(long_number_, max, size_number(module_number_, max) - 1), max);

	int_* quitient_temp = new int_[2 * max + 1]; null_(quitient_temp, 2 * max + 1);

	long_mul(quotient_, coefitient_barrett_, quitient_temp, system_base, 2 * max + 1);

	function_kill_digit(quitient_temp, 2 * max + 1, size_number(module_number_, max) + 1);

	null_(quotient_, max);

	copy_array(quotient_, quitient_temp, size_number(quitient_temp, 2 * max + 1));

	delete[] quitient_temp;


	int_* temp_ = new int_[2 * max + 1]; null_(temp_, 2 * max + 1);

	long_mul(quotient_, module_number_, temp_, system_base, 2 * max + 1);
	copy_array(quotient, temp_, size_number(temp_, 2 * max + 1));

	delete[] temp_;

	int_* _long_number = new int_[max];  null_(_long_number, max);   copy_array(_long_number, long_number, size);

	remainder = long_sub(_long_number, quotient, remainder, max, system_base);

	delete[] _long_number;

	while (long_compare(remainder, module_number_, max) == 0 || long_compare(remainder, module_number_, max) == 1)
	{
		int_* temp = new int_[max]; null_(temp, max);
		long_sub(remainder, module_number_, temp, max, system_base);
		copy_array(remainder, temp, max);
		delete[] temp;
	}

	copy_array(result, remainder, size_number(remainder, max));

	delete[] coefitient_barrett_;
	delete[] module_number_;
	delete[] long_number_;

	delete[] remainder;
	delete[] quotient;
	delete[] quotient_;

	return result;
}

int_* barrett_reduction_(int_* long_number, int_* module_number, int_* coefitient_barrett, int_* result, int_ size, int_ system_base, int_ max_for_coeficient)
{
	if (long_compare(long_number, module_number, size) == -1)
	{
		result = copy_array(result, long_number, size);
		return result;
	}

	if (lenth_is_ok_or_not(long_number, module_number, size, system_base) == false || long_compare(long_number, module_number, size) == 0) //ok
	{
		operation_mod_(long_number, module_number, result, system_base, size);
		return result;
	}

	else
	{
		algorithm_barrett_(long_number, module_number, coefitient_barrett, result, size, system_base, max_for_coeficient);
		return result;
	}
}

int_* add_mod_reduction(int_* first, int_* second, int_* mod, int_* coefitient_barrett, int_* result, int_ system_base, int_ max, int_ max_for_coeficient)
{

	int_* first_ = new int_[max];  null_(first_, max);
	int_* second_ = new int_[max]; null_(second_, max);

	barrett_reduction_(first, mod, coefitient_barrett, first_, max, system_base, max_for_coeficient);
	barrett_reduction_(second, mod, coefitient_barrett, second_, max, system_base, max_for_coeficient);

	int_* mass_ = new int_[max + 1]; 	null_(mass_, max + 1);     mass_ = long_add(first_, second_, mass_, max, system_base);

	int_* mod_ = new int_[max + 1]; null_(mod_, max + 1); copy_array(mod_, mod, max);

	int_* result_ = new int_[max + 1]; null_(result_, max + 1);

	barrett_reduction_(mass_, mod_, coefitient_barrett, result_, max + 1, system_base, max_for_coeficient);

	copy_array(result, result_, size_number(result_, max + 1));

	delete[] result_;
	delete[] mod_;
	delete[] mass_;
	delete[] second_;
	delete[] first_;

	return result;
}

int_* substract_mod_reduction(int_* first, int_* second, int_* mod, int_* coefitient_barrett, int_* result, int_ system_base, int_ max, int_ max_for_coeficient)
{
	int_* mass_ = new int_[max]; null_(mass_, max);

	if (long_compare(first, second, max) == 0 || long_compare(first, second, max) == 1)
	{
		mass_ = long_sub(first, second, mass_, max, system_base);
		barrett_reduction_(mass_, mod, coefitient_barrett, result, max, system_base, max_for_coeficient);
	}
	else
	{
		int_* _mass = new int_[max]; null_(_mass, max);

		mass_ = long_sub(second, first, mass_, max, system_base);
		_mass = barrett_reduction_(mass_, mod, coefitient_barrett, _mass, max, system_base, max_for_coeficient);
		long_sub(mod, _mass, result, max, system_base);
		delete[] _mass;
	}

	delete[] mass_;

	return result;
}

int_* multiplication_mod_reduction(int_* first, int_* second, int_* mod, int_* coefitient_barrett, int_* result, int_ system_base, int_ max, int_ max_for_coeficient)
{
	int_* first_ = new int_[max];  null_(first_, max);
	int_* second_ = new int_[max]; null_(second_, max);

	barrett_reduction_(first, mod, coefitient_barrett, first_, max, system_base, max_for_coeficient);
	barrett_reduction_(second, mod, coefitient_barrett, second_, max, system_base, max_for_coeficient);

	int_* mass_ = new int_[2 * max + 1]; null_(mass_, 2 * max + 1);

	long_mul(first_, second_, mass_, system_base, 2 * max + 1);

	int_ * mod_ = new int_[2 * max + 1]; null_(mod_, 2 * max + 1); copy_array(mod_, mod, max);

	int_ * result_ = new int_[2 * max + 1]; null_(result_, 2 * max + 1);

	barrett_reduction_(mass_, mod_, coefitient_barrett, result_, 2 * max + 1, system_base, max_for_coeficient);

	copy_array(result, result_, size_number(result_, 2 * max + 1));

	delete[] result_;

	delete[] mod_;

	delete[] mass_;

	delete[] second_;
	delete[] first_;

	return result;
}

int_* elevation_mod_reduction(int_* lower, int_* upper, int_* mod, int_* coefitient_barrett, int_* result, int_ down, int_ up, int_ size_result, int_ max_for_coeficient, int_ system_base)
{

	/// make number by module in start

	int_* lower_ = new int_[down];    null_(lower_, down);

	barrett_reduction_(lower, mod, coefitient_barrett, lower_, down, system_base, max_for_coeficient);

	int_* _temp = new int_[down];     null_(_temp, down);    _temp = copy_array(_temp, lower_, down);
	int_* temp_ = new int_[down];     null_(temp_, down);    temp_ = copy_array(temp_, lower_, down);

	int_* mod_ = new int_[2 * down + 1];  null_(mod_, 2 * down + 1);  copy_array(mod_, mod, down);



	int_ j = 0;

	for (int_ i = 0; i < up; i++)
	{

		if (i == 0)
		{
			j = 1;
		}

		if (upper[i] == 1)
		{


			int_* mass_ = new int_[down]; null_(mass_, down); copy_array(mass_, result, down); null_(result, down);

			if (j == 1) { null_(mass_, down); mass_[0] = 1; j = 0; }

			int_* result_ = new int_[2 * down + 1];

			null_(result_, 2 * down + 1);

			long_mul(mass_, temp_, result_, system_base, 2 * down + 1);

			algorithm_barrett_(result_, mod_, coefitient_barrett, result, 2 * down + 1, system_base, max_for_coeficient);

			delete[] result_;

			delete[] mass_;

		}

		if (i != up - 1) // we don`t make no need step in the end
		{

			int_* temp = new int_[2 * down + 1]; null_(temp, 2 * down + 1);

			long_mul(_temp, temp_, temp, system_base, 2 * down + 1);

			int_* result_ = new int_[down]; null_(result_, down);

			algorithm_barrett_(temp, mod_, coefitient_barrett, result_, 2 * down + 1, system_base, max_for_coeficient);

			_temp = copy_array(_temp, result_, down);

			temp_ = copy_array(temp_, result_, down);

			delete[] result_;

			delete[] temp;
		}

	}

	delete[] mod_;
	delete[] temp_;
	delete[] _temp;
	delete[] lower_;

	return result;
}

/// ~reduction block-end 

/// gcd/lcm-start

int_* gcd_(int_* first, int_* second, int_* result, int_ max, int_ system_base)
{
	/*Pseudo Code of the Algorithm -
		Step 1:  Let  a, b  be the two numbers
		Step 2 : a mod b = R
		Step 3 : Let  a = b and b = R
		Step 4 : Repeat Steps 2 and 3 until  a mod b  is greater than 0
		Step 5 : GCD = b
		Step 6 : Finish*/

	while (long_compare(first, second, max) != 0 && ask_null_or_not(first, max) != 0 && ask_null_or_not(second, max) != 0)
	{
		while (long_compare(first, second, max) == 1 && ask_null_or_not(first, max) != 0 && ask_null_or_not(second, max) != 0) //a>b
		{

			int_* remainder = new int_[max]; null_(remainder, max);
			int_* quotient = new int_[max];  null_(quotient, max);
			
			long_division(first, second, quotient, remainder, system_base, max);

			null_(first, max);
			copy_array(first, remainder, max);

			delete[] quotient;
			delete[] remainder;

		}
		while (long_compare(first, second, max) == -1 && ask_null_or_not(first, max) != 0 && ask_null_or_not(second, max) != 0) //a<b
		{

			int_* remainder = new int_[max]; null_(remainder, max);
			int_* quotient = new int_[max];  null_(quotient, max);
			

			long_division(second, first, quotient, remainder, system_base, max);

			null_(second, max);
			copy_array(second, remainder, max);

			delete[] quotient;
			delete[] remainder;
		}
	}

	if (long_compare(first, second, max) == 1)
	{
		copy_array(result, first, max);
	}
	else
	{
		copy_array(result, second, max);
	}

	return result;




	//while (long_compare(first,second, max)!=0)
	//{
	//	while (long_compare(first, second, max) == 1) //a>b
	//	{
	//		
	//		int_* mass_ = new int_[max];
	//		null_function(mass_, max);
	//		mass_ = long_sub(first, second, mass_, max, system_base); //c = a – b;	
	//		null_function(first, max);
	//		copy_array(first, mass_, max);   //a = c;
	//		delete[] mass_;
	//	}
	//	while (long_compare(first, second, max) == -1) //a<b
	//	{
	//		int_* mass_ = new int_[max];
	//		null_function(mass_, max);
	//		mass_ = long_sub(second, first, mass_, max, system_base); 	//c = b – a;	
	//		null_function(second, max);
	//		copy_array(second, mass_, max);  // b = c;
	//		delete[] mass_;
	//	}
	//}
	//
	//if (long_compare(first, second, max) == 1)
	//{
	//	copy_array(result,first,max);
	//}
	//else
	//{
	//	copy_array(result,second,max);
	//}
	//return result;
}

int_* lcm_(int_* first, int_* second, int_* result, int_ max_result, int_ system_base)
{
	int_* remainder = new int_[max_result];  null_(remainder, max_result);
	int_* quotient = new int_[max_result];   null_(quotient, max_result);
	int_* mass_ = new int_[max_result];	     null_(mass_, max_result);
	int_* _mass = new int_[max_result];      null_(_mass, max_result);

	
	long_mul(first, second, mass_, system_base, max_result);

	gcd_(first, second, _mass, (max_result - 1) / 2, system_base);

	long_division(mass_, _mass, quotient, remainder, system_base, max_result);

	result = copy_array(result, quotient, max_result);

	delete[] _mass;
	delete[] mass_;
	delete[] quotient;
	delete[] remainder;

	return result;
}

/// gcd/lcm-end

/// testing block start

void test_distributivity_reduction(int_* mass_1, int_* mass_2, int_* mass_3,int_* mod,int_* coefitient_barrett,int_ max_with_moduls,int_ system_base,int_ max_for_coeficient)
{
	
	int_* mass_ = new int_[max_with_moduls];    null_(mass_, max_with_moduls);
	int_* _mass = new int_[max_with_moduls];    null_(_mass, max_with_moduls);
	int_* result = new int_[max_with_moduls];   null_(result, max_with_moduls);



	cout << endl << "-result addition (A+B):" << endl;
	mass_ =add_mod_reduction(mass_1, mass_2, mod, coefitient_barrett, mass_, system_base, max_with_moduls, max_for_coeficient);
	cout << output_big_number_revers(mass_, max_with_moduls) << endl;

	cout << endl << "-result multiplication C*(A+B):" << endl;

	multiplication_mod_reduction(mass_, mass_3, mod, coefitient_barrett, result, system_base, max_with_moduls, max_for_coeficient);
	cout << output_big_number_revers(result, max_with_moduls) << endl;
	null_(result, max_with_moduls);

	cout << endl << "-result multiplication (A+B)*C:" << endl;

	multiplication_mod_reduction(mass_3, mass_, mod, coefitient_barrett, result, system_base, max_with_moduls, max_for_coeficient);
	cout << output_big_number_revers(result, max_with_moduls) << endl;
	null_(result, max_with_moduls);

	cout << endl << "-result multiplication A*C:" << endl;

	null_(mass_, max_with_moduls);
	multiplication_mod_reduction(mass_1, mass_3, mod, coefitient_barrett, mass_, system_base, max_with_moduls, max_for_coeficient);
	cout << output_big_number_revers(mass_, max_with_moduls) << endl;

	cout << endl << "-result multiplication B*C:" << endl;

	multiplication_mod_reduction(mass_2, mass_3, mod, coefitient_barrett, _mass, system_base, max_with_moduls, max_for_coeficient);
	cout << output_big_number_revers(_mass, max_with_moduls) << endl;

	cout << endl << "-result addition A*C+B*C:" << endl;

	int_* mass = new int_[max_with_moduls];
	null_(mass, max_with_moduls);
	add_mod_reduction(mass_, _mass, mod, coefitient_barrett, mass, system_base, max_with_moduls, max_for_coeficient);
	cout << output_big_number_revers(mass, max_with_moduls) << endl;
	delete[] mass;


	delete[] result;
	delete[] _mass;
	delete[] mass_;
}

void test_complexity_reduction(int_* mass, int_* mod, int_* coefitient_barrett, int_ max_with_moduls, int_ system_base, int_ max_for_coeficient)
{
	int_* result = new int_[max_with_moduls]; 

	cout << endl << "-input number of addition in decimal system:" << endl;
	int number;
	cin >> number;

	int_* number_ = new int_[max_with_moduls]; null_(number_, max_with_moduls);

	binary_hex(number, number_);
	
	cout << endl << "-result of N*A:" << endl;

	null_(result, max_with_moduls);

	multiplication_mod_reduction(mass, number_, mod, coefitient_barrett, result, system_base, max_with_moduls, max_for_coeficient);

	cout << output_big_number_revers(result, max_with_moduls) << endl;

	delete[] number_;

	cout << endl << "-result of addition of numbers:" << endl;

	null_(result, max_with_moduls);

	for (int_ i=0;i<number;i++)
	{
		int_* temp = new int_[max_with_moduls]; null_(temp, max_with_moduls);
		add_mod_reduction(mass, result, mod, coefitient_barrett, temp, system_base, max_with_moduls, max_for_coeficient);
		copy_array(result, temp, max_with_moduls);
		delete[] temp;
	}

	cout << output_big_number_revers(result, max_with_moduls) << endl;

	delete[] result;

}

//
//void special_testing_using_degree(int_* mass, int_ max_with_moduls, int_ system_base)
//{
//
//}


//void special_testing_using_degree(int_* mass,int_ max_with_moduls, int_ system_base)
//{
//	int_ degree;
//
//	cout << endl << "-input degree k of number n=3^k, for counting function Oiler(n):" << endl;	
//
//	cin >> degree;
//
//	int_ number = pow(3, degree);
//
//	int_ number_ = number;
//	int_ _number = number;
//
//	degree = 2 * pow(3, degree - 1);
//
//	max_with_moduls=max_(sizeof(number) * 8-1, max_with_moduls);
//
//	int_* _number_ = new int_[max_with_moduls];         null_(_number_, max_with_moduls);
//
//	int_* binary_number = new int_[max_with_moduls];   null_(binary_number, max_with_moduls);
//
//	int_* mass_ = new int_[max_with_moduls];           null_(mass_, max_with_moduls);            copy_array(mass_, mass, max_with_moduls);
//	int_* _mass = new int_[max_with_moduls];           null_(_mass, max_with_moduls);            copy_array(_mass, mass, max_with_moduls);
//
//	int_* result_ = new int_[max_with_moduls];         null_(result_, max_with_moduls);
//	int_* result = new int_[max_with_moduls];          null_(result, max_with_moduls);
//
//
//	int_* one = new int_[max_with_moduls];             
//	null_(one, max_with_moduls);              
//	one[0] = 1;
//	
//	binary_(degree, binary_number);  binary_hex(_number, _number_);
//	
//	gcd_(mass_, _number_, result_, max_with_moduls, system_base);
//
//	if (long_compare(one,result_, max_with_moduls)==0)
//	{
//		cout << endl << "-we have gcd(a,n)=1 , and we can to calculate a^Oiler(n)=1 mod n :" << endl;
//
//		//////////////////////////////
//		int_ max_for_coeficient = 2 * size_number(_number_, max_with_moduls) + 1;
//		int_* coefitient_barrett = new int_[max_for_coeficient];   null_(coefitient_barrett, max_for_coeficient);
//		coefitient_barrett_(_number_, coefitient_barrett, max_with_moduls, system_base);
//		//////////////////////////////
//
//		elevation_mod_reduction(_mass, binary_number, _number_,coefitient_barrett, result, max_with_moduls, (sizeof(number) * 8 - 1), max_with_moduls, max_for_coeficient, system_base);
//		cout << output_big_number_revers(result, max_with_moduls) << endl;
//
//		///////////////////////////////
//		delete[] coefitient_barrett;
//		///////////////////////////////
//	}
//	else
//	{
//		cout << endl << "-have problem gcd(a,n)!=1 need reload program!" << endl;
//	}
//
//	delete[] binary_number;
//	delete[] one;
//	delete[] result_;
//	delete[] _number_;
//	delete[] result;
//	delete[] mass_;
//
//}
/// testing block end
