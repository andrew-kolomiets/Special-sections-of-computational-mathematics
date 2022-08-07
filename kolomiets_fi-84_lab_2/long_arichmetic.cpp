// Long module arichmetics.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cmath>
#include <ctime>
#include "library.h"


using namespace std;

//start main function

int main()
{

	string big_number_1, big_number_2, number_moduls;    int_ size_big_number_1, size_big_number_2, size_number_moduls;  int_ system_base;

	char answer;
	____________________________________________________________________________________

		big_number_1 = input_big_number_(); size_big_number_1 = big_number_1.length();
	
	____________________________________________________________________________________

		big_number_2 = input_big_number_(); size_big_number_2 = big_number_2.length();

	____________________________________________________________________________________

		number_moduls = input_number_for_degree_or_mod_(number_moduls); size_number_moduls = number_moduls.length();
	
	____________________________________________________________________________________

		check_reversing_string(big_number_1, big_number_2, number_moduls);

	____________________________________________________________________________________

	cout << "Now program choose the maximum number:" << endl;

	int_ max = number_of_massive_which_is_max(big_number_1, big_number_2);

	cout << max << endl;

	cout << "Now program choose the maximum number include module:" << endl;

	int_ max_with_moduls = max_(max, size_number_moduls);

	cout << max_with_moduls << endl;

	____________________________________________________________________________________

		cout << "Process of convertation with string to array of int..." << endl;

	int_* mass_1 = new int_[max]; null_(mass_1, max);
	cout << endl << output_big_number_for_null(mass_1, max) << endl;
	mass_1 = convert_big_number_(big_number_1, mass_1);

	int_* mass_2 = new int_[max]; null_(mass_2, max);
	cout << endl << output_big_number_for_null(mass_2, max) << endl;
	mass_2 = convert_big_number_(big_number_2, mass_2);


	int_* moduls = new int_[max_with_moduls]; null_(moduls, max_with_moduls);
	cout << endl << output_big_number_for_null(moduls, max_with_moduls) << endl;
	moduls = convert_big_number_(number_moduls, moduls);

	____________________________________________________________________________________

	cout << "Check the process of conveting in revers order:" << endl;
	cout << endl << output_big_number_revers(mass_1, max) << endl;
	cout << endl << output_big_number_revers(mass_2, max) << endl;
	cout << endl << output_big_number_revers(moduls, max_with_moduls) << endl;

	____________________________________________________________________________________

	total_comander();

	____________________________________________________________________________________

	cout << "Input index system of base n for 2^n number system:" << endl;
	cin >> system_base;

	____________________________________________________________________________________

	cout << "Input your choose:" << endl;
	cin >> answer;

	____________________________________________________________________________________


	double start_time = clock(); 

	cout << "Result of your choose:" << endl;

	if (answer!='P')
	{
		switch (answer)
		{

		case 'm':
		{
			int_* mass_1_ = new int_[max_with_moduls];    null_(mass_1_, max_with_moduls);      copy_array(mass_1_, mass_1, max);
			int_* mass_2_ = new int_[max_with_moduls];    null_(mass_2_, max_with_moduls);      copy_array(mass_2_, mass_2, max);

			int_* result = new int_[max_with_moduls];

			///~ coeficient block

			int_ max_for_coeficient = 2 * size_number(moduls, max_with_moduls) + 1;

			int_* coefitient_barrett = new int_[max_for_coeficient];   null_(coefitient_barrett, max_for_coeficient);

			coefitient_barrett_(moduls, coefitient_barrett, max_with_moduls, system_base);

			cout << endl << "-coeficient Barrett:" << endl;

			cout << output_big_number_revers(coefitient_barrett, max_for_coeficient) << endl;

			///  coeficient block~

			cout << endl << "-first number by mod(n):" << endl; null_(result, max_with_moduls);

			barrett_reduction_(mass_1_, moduls, coefitient_barrett, result, max_with_moduls, system_base, max_for_coeficient);
			cout << output_big_number_revers(result, max_with_moduls) << endl;

			cout << endl << "-second number by mod(n):" << endl; null_(result, max_with_moduls);

			barrett_reduction_(mass_2_, moduls, coefitient_barrett, result, max_with_moduls, system_base, max_for_coeficient);
			cout << output_big_number_revers(result, max_with_moduls) << endl;

			delete[] coefitient_barrett;
			delete[] result;
			delete[] mass_2_;
			delete[] mass_1_;
		}
		break;

		case '+':
		{

			int_* mass_1_ = new int_[max_with_moduls];    null_(mass_1_, max_with_moduls);      copy_array(mass_1_, mass_1, max);
			int_* mass_2_ = new int_[max_with_moduls];    null_(mass_2_, max_with_moduls);      copy_array(mass_2_, mass_2, max);

			int_* result = new int_[max_with_moduls];

			int_ max_for_coeficient = 2 * size_number(moduls, max_with_moduls) + 1;

			int_* coefitient_barrett = new int_[max_for_coeficient];   null_(coefitient_barrett, max_for_coeficient);

			coefitient_barrett_(moduls, coefitient_barrett, max_with_moduls, system_base);

			cout << endl << "-coeficient Barrett:" << endl;

			cout << output_big_number_revers(coefitient_barrett, max_for_coeficient) << endl;

			cout << endl << "-result addition by module:" << endl;

			null_(result, max_with_moduls);

			add_mod_reduction(mass_1_, mass_2_, moduls, coefitient_barrett, result, system_base, max_with_moduls, max_for_coeficient);

			cout << output_big_number_revers(result, max_with_moduls) << endl;

			delete[] coefitient_barrett;
			delete[] result;
			delete[] mass_2_;
			delete[] mass_1_;

		}

		break;

		case '-':
		{
			int_* mass_1_ = new int_[max_with_moduls];    null_(mass_1_, max_with_moduls);      copy_array(mass_1_, mass_1, max);
			int_* mass_2_ = new int_[max_with_moduls];    null_(mass_2_, max_with_moduls);      copy_array(mass_2_, mass_2, max);

			int_* result = new int_[max_with_moduls];

			int_ max_for_coeficient = 2 * size_number(moduls, max_with_moduls) + 1;

			int_* coefitient_barrett = new int_[max_for_coeficient];   null_(coefitient_barrett, max_for_coeficient);

			coefitient_barrett_(moduls, coefitient_barrett, max_with_moduls, system_base);

			cout << endl << "-coeficient Barrett:" << endl;

			cout << output_big_number_revers(coefitient_barrett, max_for_coeficient) << endl;

			cout << endl << "-result substracrion by module:" << endl;

			null_(result, max_with_moduls);

			substract_mod_reduction(mass_1_, mass_2_, moduls, coefitient_barrett, result, system_base, max_with_moduls, max_for_coeficient);

			cout << output_big_number_revers(result, max_with_moduls) << endl;

			delete[] coefitient_barrett;
			delete[] result;
			delete[] mass_2_;
			delete[] mass_1_;
		}

		break;

		case '*':
		{
			int_* mass_1_ = new int_[max_with_moduls];    null_(mass_1_, max_with_moduls);      copy_array(mass_1_, mass_1, max);
			int_* mass_2_ = new int_[max_with_moduls];     null_(mass_2_, max_with_moduls);      copy_array(mass_2_, mass_2, max);

			int_* result = new int_[max_with_moduls];

			int_ max_for_coeficient = 2 * size_number(moduls, max_with_moduls) + 1;

			int_* coefitient_barrett = new int_[max_for_coeficient];   null_(coefitient_barrett, max_for_coeficient);

			coefitient_barrett_(moduls, coefitient_barrett, max_with_moduls, system_base);

			cout << endl << "-coeficient Barrett:" << endl;

			cout << output_big_number_revers(coefitient_barrett, max_for_coeficient) << endl;

			cout << endl << "-result multiplication by module:" << endl;

			null_(result, max_with_moduls);

			multiplication_mod_reduction(mass_1_, mass_2_, moduls, coefitient_barrett, result, system_base, max_with_moduls, max_for_coeficient);

			cout << output_big_number_revers(result, max_with_moduls) << endl;

			delete[] coefitient_barrett;
			delete[] result;
			delete[] mass_2_;
			delete[] mass_1_;
		}

		break;

		case '^':
		{
			/////////////////////////////////////////////////////////////
			// Algorithm:                                              //
			//-convert to binary upper number;                         //
			//-make array on size maximum of three inputting number;   //
			//-using algorithm Gorner to elevation to the degree;      //
			//-modify the algorithm Gornera to reducrion by bod N;     //
			/////////////////////////////////////////////////////////////

			int_* mass_1_ = new int_[max_with_moduls];    null_(mass_1_, max_with_moduls);      copy_array(mass_1_, mass_1, max);
			int_* mass_2_ = new int_[max_with_moduls];     null_(mass_2_, max_with_moduls);      copy_array(mass_2_, mass_2, max);

			int_* result = new int_[max_with_moduls]; null_(result, max_with_moduls);

			int_ max_for_coeficient = 2 * size_number(moduls, max_with_moduls) + 1;

			int_* coefitient_barrett = new int_[max_for_coeficient];   null_(coefitient_barrett, max_for_coeficient);

			coefitient_barrett_(moduls, coefitient_barrett, max_with_moduls, system_base);

			cout << endl << "-coeficient Barrett:" << endl;

			cout << output_big_number_revers(coefitient_barrett, max_for_coeficient) << endl;

			string mass_upper_ = hex_bin_string_revers(big_number_2);// (A^B)mod n

			int_* mass_upper = new int_[mass_upper_.length()];

			mass_upper = string_to_integer(mass_upper_, mass_upper, mass_upper_.length());

			cout << endl << "-result converting hex to binary:" << endl;

			cout << output_big_number_revers(mass_upper, mass_upper_.length()) << endl;

			cout << endl << "-result elevation to the degree:" << endl;

			elevation_mod_reduction(mass_1_, mass_upper, moduls, coefitient_barrett, result, max_with_moduls, mass_upper_.length(), max_with_moduls, max_for_coeficient, system_base);

			cout << output_big_number_revers(result, max_with_moduls) << endl;


			delete[] mass_upper;

			delete[] coefitient_barrett;
			delete[] result;
			delete[] mass_2_;
			delete[] mass_1_;

		}

		break;

		case 'G':
		{
			int_* mass_1_ = new int_[max_with_moduls];    null_(mass_1_, max_with_moduls);      copy_array(mass_1_, mass_1, max);
			int_* mass_2_ = new int_[max_with_moduls];     null_(mass_2_, max_with_moduls);      copy_array(mass_2_, mass_2, max);

			int_* result = new int_[max];
			null_(result, max);
			cout << output_big_number_revers(gcd_(mass_1_, mass_2_, result, max, system_base), max) << endl;
			delete[] result;

			delete[] mass_2_;
			delete[] mass_1_;
		}
		break;

		case 'L':
		{
			int_* mass_1_ = new int_[max_with_moduls];    null_(mass_1_, max_with_moduls);      copy_array(mass_1_, mass_1, max);
			int_* mass_2_ = new int_[max_with_moduls];     null_(mass_2_, max_with_moduls);      copy_array(mass_2_, mass_2, max);

			int_* result = new int_[2 * max + 1];
			null_(result, 2 * max + 1);
			cout << output_big_number_revers(lcm_(mass_1_, mass_2_, result, 2 * max + 1, system_base), 2 * max + 1) << endl;
			delete[] result;
			delete[] mass_2_;
			delete[] mass_1_;
		}

		break;

		case 'D':
		{

			string number = input_big_number_distributivity();

			max_with_moduls = max_(max_with_moduls, number.length());

			int_* number_ = new int_[max_with_moduls]; number_ = null_(number_, max_with_moduls); number_ = convert_big_number_(number, number_);


			int_* mass_1_ = new int_[max_with_moduls];     null_(mass_1_, max_with_moduls);      copy_array(mass_1_, mass_1, max);
			int_* mass_2_ = new int_[max_with_moduls];     null_(mass_2_, max_with_moduls);      copy_array(mass_2_, mass_2, max);
			int_* module_ = new int_[max_with_moduls];      null_(module_, max_with_moduls);      copy_array(module_, moduls, max);

			int_ max_for_coeficient = 2 * size_number(module_, max_with_moduls) + 1;

			int_* coefitient_barrett = new int_[max_for_coeficient];   null_(coefitient_barrett, max_for_coeficient);

			coefitient_barrett_(module_, coefitient_barrett, max_with_moduls, system_base);

			cout << endl << "-coeficient Barrett:" << endl;

			cout << output_big_number_revers(coefitient_barrett, max_for_coeficient) << endl;

			test_distributivity_reduction(mass_1_, mass_2_, number_, module_, coefitient_barrett, max_with_moduls, system_base, max_for_coeficient);

			delete[] coefitient_barrett;
			delete[] module_;
			delete[] mass_2_;
			delete[] mass_1_;
			delete[] number_;
		}
		break;

		case 'C':
		{
			int_* mass_1_ = new int_[max_with_moduls];    null_(mass_1_, max_with_moduls);      copy_array(mass_1_, mass_1, max);
			int_* mass_2_ = new int_[max_with_moduls];     null_(mass_2_, max_with_moduls);      copy_array(mass_2_, mass_2, max);

			int_ max_for_coeficient = 2 * size_number(moduls, max_with_moduls) + 1;

			int_* coefitient_barrett = new int_[max_for_coeficient];   null_(coefitient_barrett, max_for_coeficient);

			coefitient_barrett_(moduls, coefitient_barrett, max_with_moduls, system_base);

			cout << endl << "-coeficient Barrett:" << endl;

			cout << output_big_number_revers(coefitient_barrett, max_for_coeficient) << endl;

			test_complexity_reduction(mass_1_, moduls, coefitient_barrett, max_with_moduls, system_base, max_for_coeficient);

			test_complexity_reduction(mass_2_, moduls, coefitient_barrett, max_with_moduls, system_base, max_for_coeficient);

			delete[] coefitient_barrett;
			delete[] mass_2_;
			delete[] mass_1_;
		}
		break;

		/*case'W':
		{
			int_* mass_1_ = new int_[max_with_moduls];     null_(mass_1_, max_with_moduls);      copy_array(mass_1_, mass_1, max);
			int_* mass_2_ = new int_[max_with_moduls];     null_(mass_2_, max_with_moduls);      copy_array(mass_2_, mass_2, max);

			special_testing_using_degree(mass_1_,  max_with_moduls, system_base);
			special_testing_using_degree(mass_2_, max_with_moduls, system_base);

			delete[] mass_2_;
			delete[] mass_1_;
		}

		break;
	*/
		default:
			cout << "You incorect enter your choose!" << endl;
			break;
		}
	}
	if (answer == 'P')
	{
		{
			int_* mass_1_ = new int_[max_with_moduls];    null_(mass_1_, max_with_moduls);      copy_array(mass_1_, mass_1, max);
			int_* mass_2_ = new int_[max_with_moduls];    null_(mass_2_, max_with_moduls);      copy_array(mass_2_, mass_2, max);

			int_* result = new int_[max_with_moduls];

			///~ coeficient block

			int_ max_for_coeficient = 2 * size_number(moduls, max_with_moduls) + 1;

			int_* coefitient_barrett = new int_[max_for_coeficient];   null_(coefitient_barrett, max_for_coeficient);

			coefitient_barrett_(moduls, coefitient_barrett, max_with_moduls, system_base);

			cout << endl << "-coeficient Barrett:" << endl;

			cout << output_big_number_revers(coefitient_barrett, max_for_coeficient) << endl;

			///  coeficient block~

			cout << endl << "-first number by mod(n):" << endl; null_(result, max_with_moduls);

			barrett_reduction_(mass_1_, moduls, coefitient_barrett, result, max_with_moduls, system_base, max_for_coeficient);
			cout << output_big_number_revers(result, max_with_moduls) << endl;

			cout << endl << "-second number by mod(n):" << endl; null_(result, max_with_moduls);

			barrett_reduction_(mass_2_, moduls, coefitient_barrett, result, max_with_moduls, system_base, max_for_coeficient);
			cout << output_big_number_revers(result, max_with_moduls) << endl;

			delete[] coefitient_barrett;
			delete[] result;
			delete[] mass_2_;
			delete[] mass_1_;
		}
		

		
		{

			int_* mass_1_ = new int_[max_with_moduls];    null_(mass_1_, max_with_moduls);      copy_array(mass_1_, mass_1, max);
			int_* mass_2_ = new int_[max_with_moduls];    null_(mass_2_, max_with_moduls);      copy_array(mass_2_, mass_2, max);

			int_* result = new int_[max_with_moduls];

			int_ max_for_coeficient = 2 * size_number(moduls, max_with_moduls) + 1;

			int_* coefitient_barrett = new int_[max_for_coeficient];   null_(coefitient_barrett, max_for_coeficient);

			coefitient_barrett_(moduls, coefitient_barrett, max_with_moduls, system_base);

			cout << endl << "-coeficient Barrett:" << endl;

			cout << output_big_number_revers(coefitient_barrett, max_for_coeficient) << endl;

			cout << endl << "-result addition by module:" << endl;

			null_(result, max_with_moduls);

			add_mod_reduction(mass_1_, mass_2_, moduls, coefitient_barrett, result, system_base, max_with_moduls, max_for_coeficient);

			cout << output_big_number_revers(result, max_with_moduls) << endl;

			delete[] coefitient_barrett;
			delete[] result;
			delete[] mass_2_;
			delete[] mass_1_;

		}

		

		
		{
			int_* mass_1_ = new int_[max_with_moduls];    null_(mass_1_, max_with_moduls);      copy_array(mass_1_, mass_1, max);
			int_* mass_2_ = new int_[max_with_moduls];    null_(mass_2_, max_with_moduls);      copy_array(mass_2_, mass_2, max);

			int_* result = new int_[max_with_moduls];

			int_ max_for_coeficient = 2 * size_number(moduls, max_with_moduls) + 1;

			int_* coefitient_barrett = new int_[max_for_coeficient];   null_(coefitient_barrett, max_for_coeficient);

			coefitient_barrett_(moduls, coefitient_barrett, max_with_moduls, system_base);

			cout << endl << "-coeficient Barrett:" << endl;

			cout << output_big_number_revers(coefitient_barrett, max_for_coeficient) << endl;

			cout << endl << "-result substracrion by module:" << endl;

			null_(result, max_with_moduls);

			substract_mod_reduction(mass_1_, mass_2_, moduls, coefitient_barrett, result, system_base, max_with_moduls, max_for_coeficient);

			cout << output_big_number_revers(result, max_with_moduls) << endl;

			delete[] coefitient_barrett;
			delete[] result;
			delete[] mass_2_;
			delete[] mass_1_;
		}

		

		
		{
			int_* mass_1_ = new int_[max_with_moduls];    null_(mass_1_, max_with_moduls);      copy_array(mass_1_, mass_1, max);
			int_* mass_2_ = new int_[max_with_moduls];     null_(mass_2_, max_with_moduls);      copy_array(mass_2_, mass_2, max);

			int_* result = new int_[max_with_moduls];

			int_ max_for_coeficient = 2 * size_number(moduls, max_with_moduls) + 1;

			int_* coefitient_barrett = new int_[max_for_coeficient];   null_(coefitient_barrett, max_for_coeficient);

			coefitient_barrett_(moduls, coefitient_barrett, max_with_moduls, system_base);

			cout << endl << "-coeficient Barrett:" << endl;

			cout << output_big_number_revers(coefitient_barrett, max_for_coeficient) << endl;

			cout << endl << "-result multiplication by module:" << endl;

			null_(result, max_with_moduls);

			multiplication_mod_reduction(mass_1_, mass_2_, moduls, coefitient_barrett, result, system_base, max_with_moduls, max_for_coeficient);

			cout << output_big_number_revers(result, max_with_moduls) << endl;

			delete[] coefitient_barrett;
			delete[] result;
			delete[] mass_2_;
			delete[] mass_1_;
		}

		

		
		{
			/////////////////////////////////////////////////////////////
			// Algorithm:                                              //
			//-convert to binary upper number;                         //
			//-make array on size maximum of three inputting number;   //
			//-using algorithm Gorner to elevation to the degree;      //
			//-modify the algorithm Gornera to reducrion by bod N;     //
			/////////////////////////////////////////////////////////////

			int_* mass_1_ = new int_[max_with_moduls];    null_(mass_1_, max_with_moduls);      copy_array(mass_1_, mass_1, max);
			int_* mass_2_ = new int_[max_with_moduls];     null_(mass_2_, max_with_moduls);      copy_array(mass_2_, mass_2, max);

			int_* result = new int_[max_with_moduls]; null_(result, max_with_moduls);

			int_ max_for_coeficient = 2 * size_number(moduls, max_with_moduls) + 1;

			int_* coefitient_barrett = new int_[max_for_coeficient];   null_(coefitient_barrett, max_for_coeficient);

			coefitient_barrett_(moduls, coefitient_barrett, max_with_moduls, system_base);

			cout << endl << "-coeficient Barrett:" << endl;

			cout << output_big_number_revers(coefitient_barrett, max_for_coeficient) << endl;

			string mass_upper_ = hex_bin_string_revers(big_number_2);// (A^B)mod n

			int_* mass_upper = new int_[mass_upper_.length()];

			mass_upper = string_to_integer(mass_upper_, mass_upper, mass_upper_.length());

			cout << endl << "-result converting hex to binary:" << endl;

			cout << output_big_number_revers(mass_upper, mass_upper_.length()) << endl;

			cout << endl << "-result elevation to the degree:" << endl;

			elevation_mod_reduction(mass_1_, mass_upper, moduls, coefitient_barrett, result, max_with_moduls, mass_upper_.length(), max_with_moduls, max_for_coeficient, system_base);

			cout << output_big_number_revers(result, max_with_moduls) << endl;


			delete[] mass_upper;

			delete[] coefitient_barrett;
			delete[] result;
			delete[] mass_2_;
			delete[] mass_1_;

		}


		
		{
			int_* mass_1_ = new int_[max_with_moduls];    null_(mass_1_, max_with_moduls);      copy_array(mass_1_, mass_1, max);
			int_* mass_2_ = new int_[max_with_moduls];     null_(mass_2_, max_with_moduls);      copy_array(mass_2_, mass_2, max);

			int_* result = new int_[max];
			null_(result, max);
			cout << output_big_number_revers(gcd_(mass_1_, mass_2_, result, max, system_base), max) << endl;
			delete[] result;

			delete[] mass_2_;
			delete[] mass_1_;
		}
		

		
		{
			int_* mass_1_ = new int_[max_with_moduls];    null_(mass_1_, max_with_moduls);      copy_array(mass_1_, mass_1, max);
			int_* mass_2_ = new int_[max_with_moduls];     null_(mass_2_, max_with_moduls);      copy_array(mass_2_, mass_2, max);

			int_* result = new int_[2 * max + 1];
			null_(result, 2 * max + 1);
			cout << output_big_number_revers(lcm_(mass_1_, mass_2_, result, 2 * max + 1, system_base), 2 * max + 1) << endl;
			delete[] result;
			delete[] mass_2_;
			delete[] mass_1_;
		}

		

	
		{

			string number = input_big_number_distributivity();

			max_with_moduls = max_(max_with_moduls, number.length());

			int_* number_ = new int_[max_with_moduls]; number_ = null_(number_, max_with_moduls); number_ = convert_big_number_(number, number_);


			int_* mass_1_ = new int_[max_with_moduls];     null_(mass_1_, max_with_moduls);      copy_array(mass_1_, mass_1, max);
			int_* mass_2_ = new int_[max_with_moduls];     null_(mass_2_, max_with_moduls);      copy_array(mass_2_, mass_2, max);
			int_* module_ = new int_[max_with_moduls];      null_(module_, max_with_moduls);      copy_array(module_, moduls, max);

			int_ max_for_coeficient = 2 * size_number(module_, max_with_moduls) + 1;

			int_* coefitient_barrett = new int_[max_for_coeficient];   null_(coefitient_barrett, max_for_coeficient);

			coefitient_barrett_(module_, coefitient_barrett, max_with_moduls, system_base);

			cout << endl << "-coeficient Barrett:" << endl;

			cout << output_big_number_revers(coefitient_barrett, max_for_coeficient) << endl;

			test_distributivity_reduction(mass_1_, mass_2_, number_, module_, coefitient_barrett, max_with_moduls, system_base, max_for_coeficient);

			delete[] coefitient_barrett;
			delete[] module_;
			delete[] mass_2_;
			delete[] mass_1_;
			delete[] number_;
		}
		

		
		{
			int_* mass_1_ = new int_[max_with_moduls];    null_(mass_1_, max_with_moduls);      copy_array(mass_1_, mass_1, max);
			int_* mass_2_ = new int_[max_with_moduls];     null_(mass_2_, max_with_moduls);      copy_array(mass_2_, mass_2, max);

			int_ max_for_coeficient = 2 * size_number(moduls, max_with_moduls) + 1;

			int_* coefitient_barrett = new int_[max_for_coeficient];   null_(coefitient_barrett, max_for_coeficient);

			coefitient_barrett_(moduls, coefitient_barrett, max_with_moduls, system_base);

			cout << endl << "-coeficient Barrett:" << endl;

			cout << output_big_number_revers(coefitient_barrett, max_for_coeficient) << endl;

			test_complexity_reduction(mass_1_, moduls, coefitient_barrett, max_with_moduls, system_base, max_for_coeficient);

			test_complexity_reduction(mass_2_, moduls, coefitient_barrett, max_with_moduls, system_base, max_for_coeficient);

			delete[] coefitient_barrett;
			delete[] mass_2_;
			delete[] mass_1_;
		}
		

		/*case'W':
		{
			int_* mass_1_ = new int_[max_with_moduls];     null_(mass_1_, max_with_moduls);      copy_array(mass_1_, mass_1, max);
			int_* mass_2_ = new int_[max_with_moduls];     null_(mass_2_, max_with_moduls);      copy_array(mass_2_, mass_2, max);

			special_testing_using_degree(mass_1_,  max_with_moduls, system_base);
			special_testing_using_degree(mass_2_, max_with_moduls, system_base);

			delete[] mass_2_;
			delete[] mass_1_;
		}

		break;
	*/
		
	}
	

	double end_time = clock(); double search_time = (end_time - start_time) / 60000;
	____________________________________________________________________________________
		cout << "Time of working: " << search_time << " minutes" << endl;
	____________________________________________________________________________________

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
