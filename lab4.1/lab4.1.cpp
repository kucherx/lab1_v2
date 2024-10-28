#include <iostream>
#include <windows.h>
#include <string>

int calculate(int quantityValue, std::string* valueArr, std::string value, std::string partOfValue, std::string valueRepeat, int n, int firstNumber)
{
	//Обчислення
	int j = 0;
	char x = ' ';
	bool stan = true;
	for (int i = 0; i < quantityValue; i++)
	{
		//Запис нового значення в масив
		valueArr[i] = value;

		//Перестановка сусідніх індексів місцями
		if (j == n - 2)j = 0;
		x = partOfValue[j];
		partOfValue[j] = partOfValue[j + 1];
		j++;
		partOfValue[j] = x;

		//З'єднання складових в значення
		value = std::to_string(firstNumber) + partOfValue;

		//Перевірка на повторення рядка
		if (value == valueRepeat)
		{
			firstNumber++;
			if (!stan) valueRepeat = value;
			for (int l = 0; l <= n - 2; l++)
			{
				if (partOfValue[l] == static_cast<char>(firstNumber + '0')) partOfValue[l] = static_cast<char>((firstNumber - 1) + '0');
			}
			value = std::to_string(firstNumber) + partOfValue;
			valueRepeat = value;
		}
	}

	//Сортування масиву
	std::string save = "";
	for (int i = 0; i < quantityValue; i++)
	{
		for (int j = 0; j < quantityValue; j++)
		{
			if (valueArr[i] < valueArr[j])
			{
				save = valueArr[i];
				valueArr[i] = valueArr[j];
				valueArr[j] = save;
			}
		}
	}
	return 0;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	//Ініціалізація змінних
	int n = 0, quantityValue = 1;
	std::string value = "";

	//Отримання інформації від користувача
	std::cout << "Введіть значення n: \n";
	std::cin >> n;

	for (int i = 1; i <= n; i++)
	{
		quantityValue *= i;
		value += std::to_string(i);
	}

	std::cout << "\n______Всі можливі перестановки______\n";

	//Ініціалізація змінних які потрібні для Обчислення
	std::string* valueArr = new std::string[quantityValue];
	std::string firstNumberS = "";
	firstNumberS += value[0];
	int firstNumber = std::stoi(firstNumberS);					//Ініціалізація першого символу значення
	std::string partOfValue = "", valueRepeat = value;
	for (int i = 1; i < n; i++)									//Запис змінюваної частини значення
	{
		partOfValue += value[i];
	}

	calculate(quantityValue, valueArr, value, partOfValue, valueRepeat, n, firstNumber);

	for (int i = 0; i < quantityValue; i++)
	{
		std::cout << valueArr[i] << std::endl;
	}
	return 0;
}
