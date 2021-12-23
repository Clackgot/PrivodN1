#include <iostream>
#include <ctime> 
#include <iomanip> 
#include <chrono>

using namespace std;
template <typename T> void Shift(T* Array, T value);
template <typename T> void Shift2(T* Array, T value);
int getIntRand();

template <typename T>  void Print(T  arr[8]);

template <typename T> double Func1(int iters, T arr[8]);
template <typename T> double Func2(int iters, T arr[8]);
double getDoubleRand(double max, double min);
//void Func2(int iters, int  arr[8]);


class Timer
{
private:
	// Псевдонимы типов используются для удобного доступа к вложенным типам
	using clock_t = chrono::high_resolution_clock;
	using second_t = chrono::duration<double, ratio<1> >;

	chrono::time_point<clock_t> m_beg;

public:
	Timer() : m_beg(clock_t::now())
	{
	}

	void reset()
	{
		m_beg = clock_t::now();
	}

	double elapsed() const
	{
		return chrono::duration_cast<second_t>(clock_t::now() - m_beg).count();
	}
};



int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(0));//Установка зерна рандомизации
	int arr[8] = { 0, 1, 2, 3, 4, 5, 6, 7 }; //Начальный массив
	double arr2[8];
	for (size_t i = 0; i < 8; i++)
	{
		arr2[i] = getDoubleRand(0,1);
	}
	int iters = 200000;//Кол-во итераций

	
	cout << Func2(iters, arr2);
}

//void Func2(int iters, int  arr[8])
//{
//	clock_t start = clock();//Время начала выполнения цикла
//							//Цикл, который N раз выполняет сдвиг массива
//	for (size_t i = 0; i < iters; i++)
//	{
//		Shift2(arr, getIntRand()); //Сдвиг
//		//Print(arr);
//	}
//	clock_t end = clock();//Конец выполнения цикла
//	double seconds = (double)(end - start) / CLOCKS_PER_SEC;//Вычисление времени выполнения
//	printf("Время выполнения цикла вторым способом из %d элементов: %f секунд\n", iters, seconds);//Вывод времени выполнения
//}


template <typename T> double Func1(int iters, T arr[8])
{
	Timer t;
	for (size_t i = 0; i < iters; i++)
	{
		if (is_same<T, int>::value)
		{
			Shift<T>(arr, getIntRand()); //Сдвиг
		}
		else if (is_same<T, double>::value)
		{
			Shift<T>(arr, getDoubleRand(0,1));
		}
		//Print(arr);
	}
	return t.elapsed();
	//printf("Время выполнения цикла первым способом из %d элементов: %f секунд\n", iters, seconds);//Вывод времени выполнения
}


template <typename T> double Func2(int iters, T arr[8])
{
	Timer t;

	//Цикл, который N раз выполняет сдвиг массива
	for (size_t i = 0; i < iters; i++)
	{
		if (is_same<T, int>::value)
		{
			Shift2<T>(arr, getIntRand()); //Сдвиг
			Print(arr);
		}
		else if (is_same<T, double>::value)
		{
			Shift2<T>(arr, getDoubleRand(0, 1));
		}
		//Print(arr);
	}
	//printf("Время выполнения цикла первым способом из %d элементов: %f секунд\n", iters, seconds);//Вывод времени выполнения
	return t.elapsed();
}



/// <summary>
/// Вывод массива
/// </summary>
/// <param name="arr">Массив</param>
template <typename T> void Print(T  arr[8])
{
	for (size_t i = 0; i < 8; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}




#pragma region Рандомизаторы



/// <summary>
/// Метод генерации случайного числа [0..9]
/// </summary>
/// <returns>Случайное число</returns>
int getIntRand()
{
	return rand() % 10;
}
double getDoubleRand(double max, double min)
{
	return min + double(rand()) / RAND_MAX * (max - min);
}

#pragma endregion


/// <summary>
/// Сдвиг массива
/// </summary>
/// <param name="Array">Массив</param>
/// <param name="value">Новое значение, подставляемое в конец массива</param>
template <typename T> void Shift(T* Array, T value)
{
	rotate(Array, Array + 1, Array + 8); // Сдвиг массива
	Array[7] = value; //Подстановка значения в конец массива
}
template <typename T> void Shift2(T* Array, T value)
{
	for (size_t i = 0; i < 7; i++)
	{
		Array[i] = Array[i + 1];
	}
	Array[7] = value;
}