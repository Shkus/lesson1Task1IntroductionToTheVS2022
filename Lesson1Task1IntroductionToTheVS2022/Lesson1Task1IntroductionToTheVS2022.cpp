// Lesson1Task1IntroductionToTheVS2022.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>

int main(int argx, char** argv) {

	setlocale(LC_ALL, "Russian");

	std::ifstream originDate("in.txt");

	if (originDate.is_open()) {

		int sizeArr_1;
		int sizeArr_2;

		originDate >> sizeArr_1;

		int* arr_1 = new int[sizeArr_1];

		for (int i = 0; i < sizeArr_1; ++i) {
			originDate >> arr_1[i];
		}

		originDate >> sizeArr_2;

		int* arr_2 = new int[sizeArr_2];

		for (int i = 0; i < sizeArr_2; ++i) {
			originDate >> arr_2[i];
		}

		std::ofstream recordedDate("out.txt");

		if (recordedDate.is_open()) {

			recordedDate << sizeArr_2 << std::endl;

			recordedDate << arr_2[sizeArr_2 - 1] << " ";

			for (int i = 0; i < sizeArr_2 - 1; ++i) {

				recordedDate << "\t" << arr_2[i];
			}

			recordedDate << std::endl;

			recordedDate << sizeArr_1 << std::endl;

			for (int i = 1; i < sizeArr_1; ++i) {

				recordedDate << arr_1[i] << "\t" ;
			}

			recordedDate << " " << arr_1[0];

			recordedDate.close();
			originDate.close();

			delete[] arr_1;
			delete[] arr_2;
		}
		else {

			std::cout << "Не получилось открыть файл для записи!" << std::endl;

		}
	}

	else {

		std::cout << "Не получилось открыть файл с исходными данными!" << std::endl;
	}

}