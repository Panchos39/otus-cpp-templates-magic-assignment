#pragma once

#include <ostream>
#include <iostream>
#include <vector>
#include <list>
#include <tuple>

/*!
\file
\brief Заголовочный файл, содержащий различные вариации вывода ip адреса
Данный файл содержит в себе различные реализации одной и той же функции,
используя концепцию SFINAE.
Функция print_ip для строчного входа
Функция print_ip для целочисленного входа
Функция print_ip для данных в формате std::vector и std::list
Функция print_ip для данных в формте tuple, где все данные одного типа

*/


namespace print_utils {
    /*!
    Шаблон функции, выводящий в поток ip адрес на основе строкого входа
    \param[in] ip Ip адрес, в формате ссылки на строку, где может быть любое содержимое
    \param[in] out Поток, в который необходимо вывести ip адрес
    \return функция не возвращает данные

    */
    template<typename T>
    std::enable_if_t<std::is_same<T, std::basic_string<typename T::value_type>>::value, void>
    print_ip(const T &ip, std::ostream &out = std::cout) {
        out << ip << std::endl;
    }


    /*!
    Шаблон функции print_ip, выводящий в поток ip адрес на основе арифметического типа, где адрес представлен как единственное число
    \param[in] ip Ip адресс, в формате единственного целого числа
    \param[in] out Поток, в который необходимо вывести ip адрес
    \return функция не возвращает данные
    */
    template<typename T>
    typename std::enable_if<std::is_integral<T>::value, void>::type
    print_ip(const T &ip, std::ostream &out = std::cout) {
        for (std::size_t i = 0; i < sizeof(ip); ++i) {
            if (i != 0) out << ".";

            out << (0xFF & (ip >> ((sizeof(ip) - i - 1) * 8)));
        }
        out << std::endl;
    }


    /*!
    Шаблон функции print_ip, выводящий в поток ip адресс на основе массивов, где адрес представлен как std::vector или std::list
    \param[in] ip Ip адресс, в формате ссылки на контейнер, содержащий октеты ip адреса [list, vector]
    \param[in] out Поток, в который необходимо вывести ip адрес
    \return функция не возвращает данные
    */
    template<typename T>
    typename std::enable_if<std::is_same<typename std::vector<typename T::value_type>, T>::value ||
                            std::is_same<typename std::list<typename T::value_type>, T>::value, void>::type
    print_ip(T const &ip, std::ostream &out = std::cout) {

        std::string output;
        for (auto const &octet: ip) {
            if (!output.empty())
                output += ".";
            output += std::to_string(octet);
        }
        out << output << std::endl;
    }


    /*!
    Шаблон функции print_ip, выводящий в поток ip адресс на основе кортежей, где адрес представлен как std::tuple
    Если данные в кортеже будут разного типа, то будет ошибка компиляции
    \param[in] ip Ip адресс, в формате ссылки на контейнер, содержащий октеты ip адреса [list, vector]
    \param[in] out Поток, в который необходимо вывести ip адрес
    \return функция не возвращает данные
    */
    template<typename T,
            typename... Args,
            typename std::enable_if<(std::is_same_v<T, Args> && ...)>::type * = nullptr>
    auto print_ip(std::tuple<T, Args...> ip, std::ostream &out = std::cout) {
        std::string sep;
        std::apply([&out, &sep](auto &&... args) { ((out << sep << args, sep = "."), ...); }, ip);
        out << std::endl;
    }

}


