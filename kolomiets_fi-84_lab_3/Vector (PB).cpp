// Vector (PB).cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <ctime>
#include "Polynomial_basis.h"
#define time_ double start_time = clock(); 
#define _time double end_time = clock(); double search_time = (end_time - start_time) / 60000; cout << "Time of working: " << search_time << " minutes" << endl;
int main()
{
	_____________________________________________________

		string vector_1 = input_vector();
	_____________________________________________________

		string vector_2 = input_vector();
	_____________________________________________________

		string generator = input_generator();
	_____________________________________________________

	int expansion = generator.length();

	cout << endl << "Expansion of field: " << expansion << ";"<< endl;
	_____________________________________________________
	cout << "Process of convertation with string to array of int..." << endl;


	int* _vector_1 = new int[expansion-1];    null_(_vector_1, expansion-1);  convert_to_bin(vector_1, _vector_1);
	int* _vector_2 = new int[expansion-1];    null_(_vector_2, expansion-1);  convert_to_bin(vector_2, _vector_2);
	int* _generator = new int[expansion];     null_(_generator, expansion); convert_to_bin(generator, _generator);
	
	cout << endl << "First vector revers:" << endl;
	cout<<output_big_number_revers(_vector_1, expansion - 1);
	cout << endl << "Second vector revers:" << endl;
	cout<<output_big_number_revers(_vector_2, expansion - 1);
	cout << endl << "Generator vector revers:" << endl;
	cout<<output_big_number_revers(_generator, expansion);

	_____________________________________________________
	total_comander();
	_____________________________________________________
	cout << "Input your choose:" << endl;
	char answer;
	cin >> answer;
	_____________________________________________________

	double start_time_ = clock(); // начальное время

	cout << "Result of your choose:" << endl;

	if (answer != 'A')
	{
		switch (answer)
		{

		case'0':
		{

			int* result = new int[expansion - 1];
			cout << output_big_number_revers(null_(result, expansion - 1), expansion - 1) << endl;
			delete[] result;

		}
		break;

		case'1':
		{
			int* result = new int[expansion - 1];
			cout << output_big_number_revers(one_(result, expansion - 1), expansion - 1) << endl;
			delete[] result;
		}
		break;

		case'+':
		{
			int* result = new int[expansion - 1]; null_(result, expansion - 1);
			cout << output_big_number_revers(add_vector(_vector_1, _vector_2, result, expansion - 1), expansion - 1) << endl;
			delete[] result;
		}
		break;

		case'*':
		{
			int* result = new int[expansion - 1]; null_(result, expansion - 1);
			cout << output_big_number_revers(multiplicative_vector(_vector_1, _vector_2, _generator, result, expansion - 1), expansion - 1) << endl;
			delete[] result;
		}
		break;

		case'^':
		{

			string degree = input_degree(); int size_degree = degree.length();

			int* _degree = new int[size_degree];   null_(_degree, size_degree);  convert_to_bin(degree, _degree);

			///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			cout << endl << "First vector elevation:" << endl;

			int* result = new int[expansion - 1]; null_(result, expansion - 1);
			cout << output_big_number_revers(elevation_to_milty_degree(_vector_1, _degree, _generator, result, expansion - 1), expansion - 1) << endl;
			delete[] result;

			///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			cout << endl << "First vector elevation:" << endl;

			int* result_ = new int[expansion - 1]; null_(result_, expansion - 1);
			cout << output_big_number_revers(elevation_to_milty_degree(_vector_2, _degree, _generator, result_, expansion - 1), expansion - 1) << endl;
			delete[] result_;


			delete[] _degree;

		}
		break;

		case's':
		{
			///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			cout << endl << "First squers vector:" << endl;

			int* result = new int[expansion - 1]; null_(result, expansion - 1);
			cout << output_big_number_revers(degree_elevation_in_two(_vector_1, _generator, result, expansion - 1), expansion - 1) << endl;
			delete[] result;

			///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			cout << endl << "Second squers vector:" << endl;

			int* result_ = new int[expansion - 1]; null_(result_, expansion - 1);
			cout << output_big_number_revers(degree_elevation_in_two(_vector_2, _generator, result_, expansion - 1), expansion - 1) << endl;
			delete[] result_;
		}
		break;

		case't':
		{
			///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			cout << endl << "Trace for first vector:" << endl;

			int* result = new int[expansion - 1]; null_(result, expansion - 1);
			cout << output_big_number_revers(trace_polynomial(_vector_1, _generator, result, expansion - 1), expansion - 1) << endl;
			delete[] result;

			///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			cout << endl << "Trace for second vector:" << endl;

			int* result_ = new int[expansion - 1]; null_(result_, expansion - 1);
			cout << output_big_number_revers(trace_polynomial(_vector_2, _generator, result_, expansion - 1), expansion - 1) << endl;
			delete[] result_;

		}
		break;

		case'i':
		{
			cout << endl << "First vector inverse:" << endl;
			int* result = new int[expansion - 1]; null_(result, expansion - 1);
			cout << output_big_number_revers(inverse_vector(_vector_1, _generator, result, expansion - 1), expansion - 1) << endl;
			delete[] result;

			cout << endl << "Second vector inverse:" << endl;
			int* result_ = new int[expansion - 1]; null_(result_, expansion - 1);
			cout << output_big_number_revers(inverse_vector(_vector_2, _generator, result_, expansion - 1), expansion - 1) << endl;
			delete[] result_;
		}
		break;

		case 'w':
		{
			testing(_vector_1, _vector_2, _generator, expansion);

		}
		break;

		default:
			cout << "You incorect enter your choose!" << endl;
			break;

		}
	}
	if (answer == 'A')
	{
		
		
		{
			time_
			cout << endl << "-null:" << endl;
			int* result = new int[expansion - 1];
			cout << output_big_number_revers(null_(result, expansion - 1), expansion - 1) << endl;
			delete[] result;
			_time
		}
		
		
		{
			time_
			cout << endl << "-one:" << endl;
			int* result = new int[expansion - 1];
			cout << output_big_number_revers(one_(result, expansion - 1), expansion - 1) << endl;
			delete[] result;
			_time

		}
		

		
		{
			time_
			cout << endl << "-addition:" << endl;
			int* result = new int[expansion - 1]; null_(result, expansion - 1);
			cout << output_big_number_revers(add_vector(_vector_1, _vector_2, result, expansion - 1), expansion - 1) << endl;
			delete[] result;
			_time

		}
		

		
		{
			time_
			cout << endl << "-multiplication:" << endl;
			int* result = new int[expansion - 1]; null_(result, expansion - 1);
			cout << output_big_number_revers(multiplicative_vector(_vector_1, _vector_2, _generator, result, expansion - 1), expansion - 1) << endl;
			delete[] result;
			_time

		}
		

		
		{
			time_

			string degree = input_degree(); int size_degree = degree.length();

			int* _degree = new int[size_degree];   null_(_degree, size_degree);  convert_to_bin(degree, _degree);

			///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			cout << endl << "-first vector elevation:" << endl;

			int* result = new int[expansion - 1]; null_(result, expansion - 1);
			cout << output_big_number_revers(elevation_to_milty_degree(_vector_1, _degree, _generator, result, expansion - 1), expansion - 1) << endl;
			delete[] result;

			///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			cout << endl << "-second vector elevation:" << endl;

			int* result_ = new int[expansion - 1]; null_(result_, expansion - 1);
			cout << output_big_number_revers(elevation_to_milty_degree(_vector_2, _degree, _generator, result_, expansion - 1), expansion - 1) << endl;
			delete[] result_;


			delete[] _degree;

			_time
			

		}
		
		
		{
			time_
			///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			cout << endl << "-first squers vector:" << endl;

			int* result = new int[expansion - 1]; null_(result, expansion - 1);
			cout << output_big_number_revers(degree_elevation_in_two(_vector_1, _generator, result, expansion - 1), expansion - 1) << endl;
			delete[] result;

			///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			cout << endl << "-second squers vector:" << endl;

			int* result_ = new int[expansion - 1]; null_(result_, expansion - 1);
			cout << output_big_number_revers(degree_elevation_in_two(_vector_2, _generator, result_, expansion - 1), expansion - 1) << endl;
			delete[] result_;
			_time
		}
		

		
		{
			time_
			///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			cout << endl << "-trace for first vector:" << endl;

			int* result = new int[expansion - 1]; null_(result, expansion - 1);
			cout << output_big_number_revers(trace_polynomial(_vector_1, _generator, result, expansion - 1), expansion - 1) << endl;
			delete[] result;

			///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			cout << endl << "-trace for second vector:" << endl;

			int* result_ = new int[expansion - 1]; null_(result_, expansion - 1);
			cout << output_big_number_revers(trace_polynomial(_vector_2, _generator, result_, expansion - 1), expansion - 1) << endl;
			delete[] result_;
			_time

		}
		

		
		{
			time_
			cout << endl << "-first vector inverse:" << endl;
			int* result = new int[expansion - 1]; null_(result, expansion - 1);
			cout << output_big_number_revers(inverse_vector(_vector_1, _generator, result, expansion - 1), expansion - 1) << endl;
			delete[] result;

			cout << endl << "-second vector inverse:" << endl;
			int* result_ = new int[expansion - 1]; null_(result_, expansion - 1);
			cout << output_big_number_revers(inverse_vector(_vector_2, _generator, result_, expansion - 1), expansion - 1) << endl;
			delete[] result_;
			_time
		}
		

		
		{
			time_
			testing(_vector_1, _vector_2, _generator, expansion);
			_time
		}
		
	}
	_____________________________________________________

	double end_time_ = clock(); // конечное время
	double search_time_ = (end_time_ - start_time_) / 60000; // искомое время
	cout << "Time of working program: " << search_time_ << " minutes" << endl;
	_____________________________________________________

	delete[] _generator;
	delete[] _vector_2;
	delete[] _vector_1;

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
