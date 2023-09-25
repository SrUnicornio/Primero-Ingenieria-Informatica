/*
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica 2022-2023
 *
 * @file Add_one_segundos.cc
 * @author Alvao Perez Ramos alu0101574042@ull.edu.es
 * @date Oct 20 2022
 * @brief Write a program that adds one segundos to a clock time, given its hours,
 *minutes and segundoss. Input consists of three natural numbers h, m and s that
 *represent a clock time, that is, such that h<24, m<60 and s<60. Print the new
 *clock time defined by h, m and s plus one segundos in the format “HH:MM:SS”.
 * @bug There are no known bugs
 * @see https://jutge.org/problems/P34279
 */
#include <iostream>
using namespace std;

int main() {
  int hora, minutos, segundos;
  cin >> hora >> minutos >> segundos;

  while (hora >= 24 || minutos >= 60 || segundos >= 60) {
    if (segundos >= 60) {
		cin >> segundos;
    }
    if (minutos >= 60) {
      cin >> minutos;
    }
    if (hora >= 24) {
      cin >> hora;
    }
  }
  segundos += 1;
  if (segundos >= 60) {
    minutos = minutos + (segundos / 60);
    segundos = segundos % 60;
  }
  if (minutos >= 60) {
    hora = hora + (minutos / 60);
    minutos = minutos % 60;
  }
  if (hora >= 24) {
    hora = hora % 24;
  }
  printf("%02d:%02d:%02d", hora, minutos, segundos);
  return 0;
}
