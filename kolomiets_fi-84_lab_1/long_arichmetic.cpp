// long_arichmetic.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cmath>
#include <ctime>
#include "library.h"


using namespace std;

//start main function

int main()
{
	
	string big_number_1, big_number_2, number_moduls;

	int_ size_big_number_1,size_big_number_2,size_number_moduls;

	int_ system_base;

	char answer;
	

	line

	big_number_1 = input_big_number_();
	size_big_number_1 = big_number_1.length();

	line

	big_number_2 = input_big_number_();
	size_big_number_2 = big_number_2.length();

	line

	number_moduls = input_number_for_degree_or_mod_(number_moduls);
	size_number_moduls = number_moduls.length();

	line
		
		check_reversing_string(big_number_1, big_number_2, number_moduls); 

	line
	
	cout << "Now program choose the maximum number:" << endl;

	int_ max = number_of_massive_which_is_max(big_number_1, big_number_2);

	cout << max << endl;

	cout << "Now program choose the maximum number include module:" << endl;

	int_ max_with_moduls = max_(max, size_number_moduls);

	cout << max_with_moduls << endl;

	line

	cout << "Process of convertation with string to array of int..." << endl;

	int_* mass_1 = new int_[max];
	mass_1 = null_function(mass_1, max);
	cout << endl << output_big_number_for_null(mass_1, max) << endl;
	mass_1 = convert_big_number_(big_number_1, mass_1);

	int_* mass_2 = new int_[max];
	mass_2 = null_function(mass_2, max);
	cout << endl << output_big_number_for_null(mass_2, max) << endl;
	mass_2 = convert_big_number_(big_number_2, mass_2);


	int_* moduls = new int_[max_with_moduls];
	moduls=null_function(moduls, max_with_moduls);
	cout << endl << output_big_number_for_null(moduls, max_with_moduls) << endl;
	moduls = convert_big_number_(number_moduls, moduls);

	line

	cout << "Check the process of conveting in revers order:" << endl;
	cout << endl << output_big_number_revers(mass_1, max) << endl;
	cout << endl << output_big_number_revers(mass_2, max) << endl;
	cout << endl << output_big_number_revers(moduls, max_with_moduls) << endl;

	line

		total_comander();

	line

	cout << "Input index system of base n for 2^n number system:" << endl;
	cin >> system_base;

	line

	cout << "Input your choose:" << endl;
	cin >> answer;

	line


	double start_time = clock(); // начальное время

	cout << "Result of your choose:" << endl;

	switch (answer)
	{

	//case for lab-1

	case'+':
	{
		int_* mass_ = new int_[max + 1];
		null_function(mass_, max + 1);
		cout << output_big_number_revers(long_add(mass_1, mass_2, mass_, max, system_base), max + 1) << endl;
		delete[] mass_;
	}
	break;

	case'-':
	{
		if (long_compare(mass_1, mass_2, max)==-1)
		{
			cout << "You have negative number!" << endl;
		}
		else
		{
			int_* mass_ = new int_[max];
			cout << output_big_number_revers(long_sub(mass_1, mass_2, mass_, max, system_base), max) << endl;
			delete[] mass_;
		}
		
	}
	break;

	case '<':
		switch (long_compare(mass_1, mass_2, max))
		{
		case 0:
			cout << "Digits is equal! [=]" << endl;
			break;
		case 1:
			cout << "First digit is big then second! [>]" << endl;
			break;
		case -1:
			cout << "Second digit is big then first! [<]" << endl;
			break;
		default:
			cout << "Problem in program! We bad programmer!" << endl;
			break;
		}
		break;

	case '*':
	{
		int_* result = new int_[2 * max + 1];
		null_function(result, 2 * max + 1);
		result = long_mul(mass_1, mass_2, result, system_base, 2 * max + 1);
		cout << output_big_number_revers(result, 2 * max + 1) << endl;
		delete[] result;

	}
	break;

	case '/':
	{
		int_* remainder = new int_[max];
		int_* quotient = new int_[max];
		null_function(remainder, max);
		null_function(quotient, max);
		long_division(mass_1, mass_2, quotient, remainder, system_base, max);
		cout << endl << "-quotient:" << endl;
		cout << output_big_number_revers(quotient, max) << endl;
		cout << endl << "-remainder:" << endl;
		cout << output_big_number_revers(remainder, max) << endl;
		delete[] quotient;
		delete[] remainder;
	}
	break;

	case '^':
	{

		string mass_upper_ = hex_bin_string_revers(big_number_2); // A^B

		int_ size_result = big_number_1.length();

		for (int_ i = 0; i < mass_upper_.length(); i++)
		{
			size_result = 2 * size_result + 1;
		}

		int_* mass_upper = new int_[mass_upper_.length()];

		int_* result = new int_[size_result];

		null_function(result, size_result);

		mass_upper = string_to_integer(mass_upper_, mass_upper, mass_upper_.length());

		cout << endl << "-result converting hex to binary:" << endl;

		cout << output_big_number_revers(mass_upper, mass_upper_.length()) << endl;

		cout << endl << "-result elevation to the degree:" << endl;

		result = long_power(mass_1, mass_upper, big_number_1.length(), mass_upper_.length(), result, size_result, system_base);

		cout << output_big_number_revers(result, size_result) << endl;

		delete[] result;
		delete[] mass_upper;

	}
	break;
	
	case '#':
	{


		int_* result = new int_[2 * max + 1];
		int_* division = new int_[2 * max + 1];
		int_* remainder = new int_[2 * max + 1];
		int_* quotient = new int_[2 * max + 1];



		null_function(result, 2 * max + 1);
		null_function(division, 2 * max + 1);
		null_function(remainder, 2 * max + 1);
		null_function(quotient, 2 * max + 1);

		division = copy_array(division, mass_2, max);

		cout << endl << "-multiplication A*B:" << endl;


		result = long_mul(mass_1, mass_2, result, system_base, 2 * max + 1);

		cout << output_big_number_revers(result, 2 * max + 1) << endl;;

		cout << endl << "-division (A*B)/B:" << endl;

		long_division(result, division, quotient, remainder, system_base, 2 * max + 1);

		cout << endl << "-quotient:" << endl;
		cout << output_big_number_revers(quotient, 2 * max + 1) << endl;
		cout << endl << "-remainder:" << endl;
		cout << output_big_number_revers(remainder, 2 * max + 1) << endl;

		delete[] quotient;
		delete[] remainder;
		delete[] division;
		delete[] result;
	}
	break;

	case 'd': 
	{
		string big_number_3 = input_big_number_distributivity();

		int_ old_max = max;
		max = max_(max, big_number_3.length());
		int_ size_result = (old_max + max) + 3;
		int_* mass_3 = new int_[max];
		mass_3 = null_function(mass_3, max);
		mass_3 = convert_big_number_(big_number_3, mass_3);
		test_distributivity(mass_1, mass_2, mass_3, old_max, max, size_result, system_base);

		delete[] mass_3;
	}

	break;

	case 'c':
	{
		test_complexity(mass_1,mass_2, max, system_base);
	}

	break;


	//case for default state

	default:
		cout << "You incorect enter your choose!" << endl;
		break;
	}

	double end_time = clock(); // конечное время
	double search_time = (end_time - start_time) / 60000; // искомое время
	line
	cout << "Time of working: " << search_time << " minutes" << endl;
	line

	delete[] moduls;
	delete[] mass_2;
	delete[] mass_1;

	return 0;
}
// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
