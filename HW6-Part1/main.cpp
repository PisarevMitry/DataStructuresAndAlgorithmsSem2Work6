#include "main.h"

// Рекурсивная функция подсчета среднего значения элементов массива
// Предусловие: массив не пуст, n > 0
// Постусловие: функция возвращает среднее значение элементов массива
float count_average(float* array, int n) {
	cout << n;
	if (n == 1) {
		return array[n - 1];
	}
	else
	{
		return ((n - 1) * count_average(array, n - 1) + array[n - 1]) / n;
	}
}

// Функция заполнения массива случайными числами
// Предусловие: массив не пуст, n > 0
// Постусловие: функция изменяет содержание элементов массива
void fill_array(float* array, int n) {
	for (int i = 0;i < n;i++) {
		array[i] = rand() % 100;
	}
}

// Функция вывода массива
// Предусловие: массив не пуст, n > 0
// Постусловие: функция выводит содержание элементов массива
void print_array(float* array, int n) {
	for (int i = 0;i < n;i++) {
		cout << setw(4) << array[i];
	}
}

// Структура узла стека
struct stask {
	float data;
	stask* next;
};

// Рекурсивная функция создания связанного стека из n элементов
// Предусловие: на вход поступает ссыла на вершину стека и размер стека (n > 0)
// Постусловие: функция последовательно создает n узлов и наполняет их случайными числами
void build_stask(int n, stask* topNode) {
	if (n > 0) {
		stask* node = new stask;
		topNode->next = node;
		topNode->data = rand() % 100;
		build_stask(n - 1, node);
	}
	else {
		topNode->next = nullptr;
		topNode->data = rand() % 100;
	}
}

// Функция вывода стека
// Предусловие: стек не пуст
// Постусловие: функция последовательно выводит содержание узлов стека
void print_stask(stask* topNode) {
	stask* node = topNode;
	while (node->next != nullptr) {
		cout << setw(4) << node->data;
		node = node->next;
	}
}

int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "Rus");

	cout << "Тестирование рекурсивной функции подсчета среднего значения элементов массива из n элементов." << endl;
	int n = 12;
	cout << "n = " << n << endl;
	float* array;
	array = new float[n];
	fill_array(array, n);
	cout << "Массив:" << endl;
	print_array(array, n);
	cout << "\nСреднее значение последовательности: " << count_average(array, n) << endl;

	cout << "Тестирование рекурсивной функции создания связанного стека из n элементов." << endl;
	n = 10;
	cout << "n = " << n << endl;
	stask* topNode;
	topNode = new stask;
	build_stask(n, topNode);
	cout << "Стек:" << endl;
	print_stask(topNode);
}