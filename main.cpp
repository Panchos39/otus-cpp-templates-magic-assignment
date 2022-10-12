#include <iostream>
#include <tuple>
#include "ip_print.h"

/*!
\file
\brief Исполняемый файл, содержащий примеры использования функции print_ip
\example main.cpp
Данный файл содержит примеры использования print_ip для разных типов входа,
используя концепцию SFINAE.\n
функция print_ip для строчного входа;\n
Функция print_ip для целочисленного входа;\n
Функция print_ip для данных в формате std::vector и std::list;\n
Функция print_ip для данных в формте tuple, где все данные одного типа;

*/
int main() {
    print_utils::print_ip( std::int8_t{-1} ); // 255
    print_utils::print_ip( std::int16_t{0} ); // 0.0
    print_utils::print_ip( std::int32_t{2130706433} ); // 127.0.0.1
    print_utils::print_ip( std::int64_t{8875824491850138409});// 123.45.67.89.101.112.131.41
    print_utils::print_ip(std::string("Hello, World!"));
    print_utils::print_ip( std::vector<int>{100, 200, 300, 400} ); // 100.200.300.400
    print_utils::print_ip( std::list<short>{400, 300, 200, 100} ); // 400.300.200.100
    print_utils::print_ip( std::make_tuple(123, 456, 789, 0) ); // 123.456.789.0
    return 0;
}
