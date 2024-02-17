#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
void printUsage()
{
    std::cout << "Usage: calculator -o <operation> <operand1> <operand2> ... <operandN>\n"
              << "Options:\n" << " -o, --operation Specify the operation to perform (sum, average, median)\n"
              << " <operand1> <operand2> ... <operandN> Operands for the calculation\n";
}
// Функция для вычисления суммы
double calculateSum(const std::vector<double>& operands)
{
    double sum = 0.0;
    for (double operand : operands) {
        sum += operand;
    }
    return sum;
}
// Функция для вычисления среднего арифметического
double calculateAverage(const std::vector<double>& operands)
{
    double sum = calculateSum(operands);
    return sum / operands.size();
}
// Функция для вычисления медианы
double calculateMedian(std::vector<double> operands)
{
    std::sort(operands.begin(), operands.end());
    size_t size = operands.size();
    if (size % 2 == 0) {
// Если количество элементов четное, берем среднее двух центральных элементов
        return (operands[size / 2 - 1] + operands[size / 2]) / 2.0;
    } else {
// Если количество элементов нечетное, берем центральный элемент
        return operands[size / 2];
    }
}
int main(int argc, char *argv[])
{
// Проверка наличия параметров
    if (argc < 4) {
        printUsage();
        return 1;
    }
    std::string operation;
    std::vector<double> operands;

// Обработка параметров командной строки
    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        if (arg == "-o" || arg == "--operation") {
// Получаем операцию из следующего параметра
            if (i + 1 < argc) {
                operation = argv[i + 1];
                ++i; // Пропускаем следующий параметр
            } else {
                std::cerr << "Error: Operation parameter is missing.\n";
                printUsage();
                return 1;
            }
        } else {
// Получаем операнды
            double operand;
            try {
                operand = std::stod(arg);
            } catch (const std::invalid_argument&) {
                std::cerr << "Error: Invalid operand '" << arg << "'.\n";
                printUsage();
                return 1;
            }
            operands.push_back(operand);
        }
    }
// Выполнение операции в зависимости от заданной операции
    if (operation == "sum") {
        std::cout << "Sum: " << calculateSum(operands) << "\n";

    } else if (operation == "average") {
        std::cout << "Average: " << calculateAverage(operands) << "\n";
    } else if (operation == "median") {
        std::cout << "Median: " << calculateMedian(operands) << "\n";
    } else {
        std::cerr << "Error: Invalid operation '" << operation << "'.\n";
        printUsage();
        return 1;
    }
    return 0;
}
