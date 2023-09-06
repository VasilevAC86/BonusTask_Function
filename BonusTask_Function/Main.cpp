# include <iostream>
#include<ctime>
#include<cstdlib>
#include<string>

// Блок глобальных переменных
int START, END; // Начало и конец диапазона заполнения массивов случайными числами соответственно
const short ROWS = 5, COLS = 6; // Кол-во рядов и столбцов матрицы соответственно
int MATRIX[ROWS][COLS]; 

// Блок прототипов функций
void fill_Array(int arr[], const short length); // Процедура заполнения массива в задаче 1
void range(); // Процедура ввода и проверки диапазона для заполнения массива случайными числами
template<typename T>
void input_Array(T arr[], const short length); // Шаюблонная функция заполнения массива с клавиатуры
template<typename T>
void print_Array(T arr[], short length); // Шаблонная процедура вывода массива в  консоль
void comparison(int arr1[], int arr2[], short size1, short size2); // Процедура сравнения двух массивов
float randomiser(); // Функция для возврата вещественного числа от 0 до 1
template<typename T>
void mirror_Array(T arr[], short length); // Шаблонная процедура зеркалирования массива
double distance(double arr1[], double arr2[]); // Функция расчёта расстояния между точками
bool palindrom(long long number); // Функция проверки числа на палиндром
void print_Matrix(); // Процедура вывода матрицы в консоль в задаче 6
void change_Sign(int arr[], const short length); // Процедура изменения знака элементов массива

int main() {

	// Задача 1. Индексы одинаковых элементов двух массивов
	std::cout << "\033[91mTask 1. Indices of identical elements of two arrays\033[0m\n\n";
	const short size1 = 10, size2 = 15; // Размеры массивов
	int array1[size1], array2[size2]; // Инициализация массивов
	std::cout << "Filling the first array\n";
	fill_Array(array1, size1);
	std::cout << "\nFilling the second array\n\n";
	fill_Array(array2, size2);
	std::cout << "\nFirst source array is: ";
	print_Array(array1, size1);
	std::cout << "\n\nSecond source array is: ";
	print_Array(array2, size2);
	comparison(array1, array2, size1, size2);

	// Задача 2. Случайное вещественное число от 0 до 1 невключительно
	std::cout << "\033[91mTask 2. Random real number from 0 to 1\033[0m\n\n\033[92mRandom real number from 0 to 1 is " << randomiser() << "\033[0m\n\n";

	// Задача 3. Отражённый массив любого типа данных
	std::cout << "\033[91mTask 3. Mirrored array\033[0m\n\nSelect data type:\npress '1' to choose 'short'\npress '2' to choose 'double'\npress any othen key to choose 'char'.\nYour choise -> ";
	const short size3 = 5;
	char my_Choise_Type; // Переменная для хранения выбора пользователя
	std::cin >> my_Choise_Type;
	if (my_Choise_Type == '1') {
		short array[size3];
		input_Array(array, size3);
		std::cout << "\nSource array is: ";
		print_Array(array, size3);
		mirror_Array(array, size3);
		std::cout << "\033[92mMirrored array is: \033[0m";
		print_Array(array, size3);
	}
	else if (my_Choise_Type == '2') {
		double array[size3];
		input_Array(array, size3);
		std::cout << "\nSource array is: ";
		print_Array(array, size3);
		mirror_Array(array, size3);
		std::cout << "\033[93mMirrored array is: \033[0m";
		print_Array(array, size3);
	}
	else {
		char array[size3];
		input_Array(array, size3);
		std::cout << "\nSource array is: ";
		print_Array(array, size3);
		mirror_Array(array, size3);
		std::cout << "\033[92mMirrored array is: \033[0m";
		print_Array(array, size3);
	}

	// Задача 4. Расстояние между тремя точками
	std::cout << "\033\n\n[91mTask 4. Distance between two points\033[0m\n\n";
	double first_Point[3]; // Объявляем массив с координатами первой точки
	double second_Point[3]; // Объявляем массив с координатами второй точки
	std::cout << "Enter the coordinates of the first point (x -> y -> z):\n";
	input_Array(first_Point, 3);
	std::cout << "\nEnter the coordinates of the second point (x -> y -> z):\n";
	input_Array(second_Point, 3);
	std::cout << "\n\n\033[92mDistance between two points is: " << distance(first_Point, second_Point) << "\033[0m\n\n";

	// Задача 5. Проверка на палиндром
	std::cout << "\033[91mTask 5. Checking for a palindrome\033[0m\n\n";
	long long number;
	std::cout << "Enter a number of any length -> ";
	std::cin >> number;
	std::cout.setf(std::ios_base::boolalpha);
	std::cout << "\n\033[92m" << palindrom(number) << "\033[0m\n\n";

	// Задача 6. Изменение знаков элементов в массиве
	std::cout << "\033[91mTask 6. Changing signs of elements in an array\033[0m\n\n";		
	char my_Choise; // Переменная для хранения выбора пользователя	
	std::cout << "Choose how to fill the matrix:\npress '1' for manual filling \033[92m\033[4mor\033[0m press any other key for random filling.\nYour choise -> ";
	std::cin >> my_Choise;
	if (my_Choise == '1')
		for (short i = 0; i < ROWS; i++)
			for (short j = 0; i < COLS; j++) {
				std::cout << "Enter the element of matrix N " << i + j << " ( row N " << i << ", col N " << j;
				std::cin >> MATRIX[i][j];
			}
	else {
		range();
		srand(time(NULL));
		for (short i = 0; i < ROWS; i++)
			for (short j = 0; j < COLS; j++)
				MATRIX[i][j] = rand() % (END - START) + START;
	}
	std::cout << "\nSource matrix is: \n\n";
	print_Matrix();
	for (short i = 0; i < ROWS; i++)
		change_Sign(MATRIX[i], COLS);
	std::cout << "\n\033[92mFinal matrix is: \033[0m\n\n";
	print_Matrix();
	
	return 0;
}

void fill_Array(int arr[], const short length) {
	char my_Choise; // Переменная для хранения выбора пользователя	
	std::cout << "Choose how to fill the array:\npress '1' for manual filling \033[92m\033[4mor\033[0m press any other key for random filling.\nYour choise -> ";
	std::cin >> my_Choise;
	if (my_Choise == '1')
		input_Array(arr, length);
	else {
		range();
		srand(time(NULL));
		for (short i = 0; i < length; i++)
			arr[i] = rand() % (END - START) + START;
	}	
}

template<typename T>
void print_Array(T arr[], short length) {
	for (short i = 0; i < length; i++)
		std::cout << arr[i] << ", ";
	std::cout << "\b\b ";
}

void comparison(int arr1[], int arr2[], short size1, short size2) {
	short length = size1 < size2 ? size1 : size2; // Определяем минимальную из двух длин массивов 
	bool key = false; // Локальная переменная проверки совпадений
	for(short i = 0; i < length; i++)
		if (arr1[i] == arr2[i]) { // Цикл расчёт кол-ва совпадений
			key = true;
		}
	if (key) {
		std::cout << "\n\n\033[92m\nArrays have identical element(-s) by index(-s) : ";
		for (short i = 0; i < length; i++)
			if (arr1[i] == arr2[i]) // Цикл вывода повторяющихся элементов массивов
				std::cout << i << ", ";
		std::cout << "\b\b\ \033[0m\n\n";
	}
	else
		std::cout << "\n\n\033[92mArrays don't have duplicate elements\033[0m\n\n";			
}

float randomiser() {	
	const short size = 50;
	float arr[size];
	srand(time(NULL));
	for (short i = 0; i < size; i++) // Цикл заполнения массива случайными числами
		arr[i] = (float)rand() / RAND_MAX;	
	return arr[rand() % size]; // Возвращаем случайный элемент массива с случайным числом типа float
}

template <typename T>
void mirror_Array(T arr[], short length) {
	for (short i = 1; i < length; i++)
		for (short j = length - 1; j >= i; j--)
			std::swap(arr[j], arr[j - 1]);	
	std::cout << "\n\n";
}

template<typename T>
void input_Array(T arr[], const short length) {
	for (short i = 0; i < length; i++) {
		std::cout << "Enter array element N " << i + 1 << " -> ";
		std::cin >> arr[i];
	}
}

double distance(double arr1[], double arr2[]) {
	double result = 0;
	for (short i = 0; i < 3; i++)
		result += pow((arr2[i] - arr1[i]), 2);
	return pow(result, 0.5);
}

bool palindrom(long long number) {
	if (number == 0)
		return true;
	else
		if (number < 0)
			return false;
		else {
			std::string my_Text = std::to_string(number); // Переводим переданное число в строку
			short length = size(my_Text); // Определяем длину строки в кол-ве символов
			for (short i = 0; i < length / 2; i++) // Цикл проверки строки на соответствие палиндрому
				if (my_Text[i] != my_Text[length - 1 - i])
					return false;
			return true;
		}	
}

void range() {
	std::cout << "Enter a range of numbers to randomly populate the array:\nthe start -> ";
	std::cin >> START;
	std::cout << "the end -> ";
	std::cin >> END;
	while (END < START) {
		std::cout << "Input error! The end of the range cannot be less than the beginning!\nEnter the start of the range -> ";
		std::cin >> START;
		std::cout << "Enter the end of the range -> ";
		std::cin >> END;
	}
}

void change_Sign(int arr[], const short length) {
	for (short i = 0; i < length; i++)
		arr[i] *= -1;
}

void print_Matrix() {
	for (short i = 0; i < ROWS; i++) {
		std::cout << "{ ";
		for (short j = 0; j < COLS; j++)
			std::cout << MATRIX[i][j] << "\t";
		std::cout << "\b\b\b\b }\n";
	}
}