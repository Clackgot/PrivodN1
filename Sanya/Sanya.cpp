#include <iostream>
#include <ctime> 


using namespace std;

void Shift(int* Array, int value);
int getRand();
void Print(int  arr[8]);






int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(0));//Установка зерна рандомизации
	int arr[8] = { 0, 1, 2, 3, 4, 5, 6, 7 }; //Начальный массив
	int iters = 200000;//Кол-во итераций
	clock_t start = clock();//Время начала выполнения цикла
	//Цикл, который N раз выполняет сдвиг массива
	for (size_t i = 0; i < iters; i++)
	{
		Shift(arr, getRand()); //Сдвиг
		//Print(arr);
	}
	clock_t end = clock();//Конец выполнения цикла
	double seconds = (double)(end - start) / CLOCKS_PER_SEC;//Вычисление времени выполнения
	printf("Время выполнения цикла из %d элементов: %f секунд\n", iters, seconds);//Вывод времени выполнения
}

/// <summary>
/// Вывод массива
/// </summary>
/// <param name="arr">Массив</param>
void Print(int  arr[8])
{
	for (size_t i = 0; i < 8; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

/// <summary>
/// Сдвиг массива
/// </summary>
/// <param name="Array">Массив</param>
/// <param name="value">Новое значение, подставляемое в конец массива</param>
void Shift(int* Array, int value)
{
	rotate(Array, Array + 1, Array + 8); // Сдвиг массива
	Array[7] = value; //Подстановка значения в конец массива
}

/// <summary>
/// Метод генерации случайного числа [0..9]
/// </summary>
/// <returns>Случайное число</returns>
int getRand()
{
	return rand() % 10;
}