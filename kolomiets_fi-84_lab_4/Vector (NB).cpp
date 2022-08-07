// Vector (NB).cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include <ctime>
#include "Normal_basis.h"

int main()
{
	_____________________________________________________

		string vector_1 = input_vector();
	_____________________________________________________

		string vector_2 = input_vector();
	_____________________________________________________

	int expansion = vector_1.length();

	cout << endl << "Expansion of field: " << expansion << ";" << endl;
	_____________________________________________________
	cout << "Process of convertation with string to array of int..." << endl;


	int* _vector_1 = new int[expansion];    null_(_vector_1, expansion);  convert_to_bin(vector_1, _vector_1);
	int* _vector_2 = new int[expansion];    null_(_vector_2, expansion);  convert_to_bin(vector_2, _vector_2);

	cout << endl << "First vector:" << endl;
	cout << output_(_vector_1, expansion);
	cout << endl << "Second vector:" << endl;
	cout << output_(_vector_2, expansion);
	
	_____________________________________________________
		total_comander();
	_____________________________________________________

	cout << "Input your choose:" << endl;
	char answer;
	cin >> answer;
	_____________________________________________________

	double start_time = clock(); // начальное время

	cout << "Result of your choose:" << endl;

	switch (answer)
	{

	case'0':
	{
		int* result = new int[expansion];
		cout << output_(null_(result, expansion), expansion) << endl;
		delete[] result;
	}
	break;

	case'1':
	{
		int* result = new int[expansion];
		cout << output_(one_(result, expansion), expansion) << endl;
		delete[] result;
	}
	break;

	case'+':
	{
		int* result = new int[expansion]; null_(result, expansion);
		cout << output_(add_vector(_vector_1, _vector_2, result, expansion), expansion) << endl;
		delete[] result;
	}
	break;

	case'*':
	{
		// creation matrix-start

		int** matrix = new int*[expansion];

		for (int i = 0; i < expansion; i++)
		{
			matrix[i] = new int[expansion];
		}

		initialization_multiplicative_matrix(matrix, expansion);

		cout << endl << "-check the multiplicative matrix:" << endl;

		for (int i = 0; i < expansion; i++)
		{
			for (int j = 0; j < expansion; j++)
			{
				cout << matrix[i][j];
			}
			cout << endl;
		}

		//creation matrix-end

		//counting-start

		cout << endl << "-result of multiplication:" << endl;
		int* result = new int[expansion]; null_(result, expansion);
		cout << output_(multiplication(_vector_1,matrix,_vector_2, result, expansion), expansion) << endl;
		delete[] result;

		//counting-end

		// deliting matrix-start
		for (int i = 0; i < expansion; i++)
		{
			delete[] matrix[i];
		}
		delete[] matrix;
		// deliting matrix-end
	
	}
	break;

	case 's':
	{
		cout << endl << "-first vector elevation to degree equel two:" << endl;
		int* result = new int[expansion]; null_(result, expansion);
		cout << output_(elevation_in_square(_vector_1,result, expansion), expansion) << endl;
		delete[] result;

		cout << endl << "-second vector elevation to degree equel two:" << endl;
		int* result_ = new int[expansion]; null_(result_, expansion);
		cout << output_(elevation_in_square(_vector_2, result_, expansion), expansion) << endl;
		delete[] result_;
	}
	break;

	case 't':
	{
		cout << endl << "-first vector trace:" << trace_polynomial(_vector_1, expansion) << ";" << endl;
		cout << endl << "-second vector trace:" << trace_polynomial(_vector_2, expansion) << ";" << endl;
	}
	break;

	case'^':
	{
		// creation matrix-start

		int** matrix = new int*[expansion];

		for (int i = 0; i < expansion; i++)
		{
			matrix[i] = new int[expansion];
		}

		initialization_multiplicative_matrix(matrix, expansion);

		//creation matrix-end

		//counting-start

		string degree = input_degree(); int size_degree = degree.length();

		int* _degree = new int[size_degree];   null_(_degree, size_degree);  convert_to_bin(degree, _degree);

		cout << endl << "-first vector elevation to multy-degree:" << endl;
		int* result = new int[expansion]; null_(result, expansion);
		cout << output_(elevation_to_milty_degree(_vector_1, _degree,matrix, result, expansion), expansion) << endl;
		delete[] result;

		cout << endl << "-second vector elevation to multy-degree :" << endl;
		int* result_ = new int[expansion]; null_(result_, expansion);
		cout << output_(elevation_to_milty_degree(_vector_2, _degree, matrix, result_, expansion), expansion) << endl;
		delete[] result_;

		delete[] _degree;

		//counting-end

		// deliting matrix-start
		for (int i = 0; i < expansion; i++)
		{
			delete[] matrix[i];
		}
		delete[] matrix;
		// deliting matrix-end
	}
	break;

	case'i':
	{
		// creation matrix-start

		int** matrix = new int*[expansion];

		for (int i = 0; i < expansion; i++)
		{
			matrix[i] = new int[expansion];
		}

		initialization_multiplicative_matrix(matrix, expansion);

		//creation matrix-end

		//counting-start
		cout << endl << "-first vector inverse:" << endl;
		int* result = new int[expansion]; null_(result, expansion);
		cout << output_(inverse_vector(_vector_1, matrix, result, expansion), expansion) << endl;
		delete[] result;

		cout << endl << "-second vector inverse :" << endl;
		int* result_ = new int[expansion]; null_(result_, expansion);
		cout << output_(inverse_vector(_vector_2,matrix,result_, expansion), expansion) << endl;
		delete[] result_;
		
		//counting-end

		// deliting matrix-start
		for (int i = 0; i < expansion; i++)
		{
			delete[] matrix[i];
		}
		delete[] matrix;
		// deliting matrix-end
	}
	break;

	case'w':
	{
		// creation matrix-start

		int** matrix = new int*[expansion];

		for (int i = 0; i < expansion; i++)
		{
			matrix[i] = new int[expansion];
		}

		initialization_multiplicative_matrix(matrix, expansion);

		//creation matrix-end

		//counting-start

		testing(_vector_1, _vector_2, matrix, expansion);

		//counting-end

		// deliting matrix-start
		for (int i = 0; i < expansion; i++)
		{
			delete[] matrix[i];
		}
		delete[] matrix;
		// deliting matrix-end

	}
	break;

	default:
		cout << "You incorect enter your choose!" << endl;
		break;

	}
	_____________________________________________________

		double end_time = clock(); // конечное время
	double search_time = (end_time - start_time) / 60000; // искомое время
	cout << "Time of working program: " << search_time << " minutes" << endl;
	_____________________________________________________

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
