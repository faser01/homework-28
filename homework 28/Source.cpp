#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <algorithm>



template <typename T> void showArr(T arr, int length);

template <typename T> T addArr(T arr1[], int length1, T arr2[], int length2, T arr3[], int length3);

template <typename T> T* resizeArr(T arr[], int length, int newLength);


int main() {
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));

	//Задача 1
	std::cout << "задача 1\nВведите длину массива A: ";
	unsigned int a;
	std::cin >> a;
	int* arrA = new int[a];
	std::cout << "Введите длину массива B: ";
	unsigned int b;
	std::cin >> b;
	int* arrB = new int[b];
	for (int i = 0; i < a; i++) {
		arrA[i] = rand() % 10;
	}
	for (int j = 0; j < b; j++) {
		arrB[j] = rand() % (20 - 10) + 10;
	}
	std::cout << "Массив А:\n";
	showArr(arrA, a);
	std::cout << "Массив B:\n";
	showArr(arrB, b);
	std::cout << "Массив С:\n";

	unsigned int c = a + b;
	int* arrC = new int[c];
	addArr(arrA, a, arrB, b, arrC, c);
	showArr(arrC, c);

	delete[] arrA;
	delete[] arrB;

	//Задача 2
	std::cout << "Задача 2\nВведите длину массива: ";
	std::cin >> a;
	int* arr = new int[a];
	std::cout << "Введите новую длину массива: ";
	std::cin >> b;
	for (int i = 0; i < a; i++)
		arr[i] = i + 1;
	std::cout << "Изначальный массив:\n";
	showArr(arr, a);
	std::cout << "Массив с новой длинной:\n";
	resizeArr(arr, a, b);

	return 0;
}
template <typename T> T* resizeArr(T arr[], int length, int newLength) {
	if (newLength <= 0)
		return arr;
	T* tmp = new T[length];
	for (int i = 0; i < length; i++)
		tmp[i] = arr[i];
	delete[] arr;

	arr = new T[newLength];
	for (int i = 0; i < newLength; i++) {
		arr[i] = tmp[i];
		if (i >= length)
			arr[i] = 0;
	}
	delete[] tmp;
	showArr(arr, newLength);
}

template <typename T> T addArr(T arr1[], int length1, T arr2[], int length2, T arr3[], int length3) {
	for (int i = 0; i < length1; i++)
		arr3[i] = arr1[i];
	for (int i = length3 - length2; i < length3; i++)
		arr3[i] = arr2[i - length1];
	return arr3[length3];
}

template <typename T> void showArr(T arr, int length) {
	std::cout << "[";
	for (int i = 0; i < length; i++) {
		std::cout << arr[i] << ", ";
	}
	std::cout << "\b\b.]\n\n";
}
