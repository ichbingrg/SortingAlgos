/**
 * Prozedurale Programmierung
 *
 * Sortieralgorithmen
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sort.h"
#include "sort.c"
// include sort library

#define BUFFER_LEN 100  // Laenge des Eingabepuffers



/**
 * Fuellt ein Array mit N ganzen Zahlen zwischen 1 und 1000 von der Tastatur.
 *
 * A - Zu fuellendes Array
 * N - Laenge von A
 */
void read_fill(int* A, int N) {
  printf("Bitte geben Sie %d ganze Zahlen zwischen 1 und 1000 ein.\n", N);
  char buffer[BUFFER_LEN];
  for (int i = 0; i < N; i++) {
    do {
      printf("[%d / %d] = ", i + 1, N);
      fgets(buffer, BUFFER_LEN, stdin);
      sscanf(buffer, "%d", A + i);
      if ((A[i] < 1) || (A[i] > 1000)) {
        printf("Geben Sie eine ganze Zahl zwischen 1 und 1000 ein!\n");
      }
    } while ((A[i] < 1) || (A[i] > 1000));
  }
}



/**
 * Fuellt ein Array mit N ganzen Zahlen zwischen 1 und 1000 mit Zufallszahlen.
 *
 * A - Zu fuellendes Array
 * N - Laenge von A
 */
void rand_fill(int* A, int N) {
  printf("Ganze Zufallszahlen zwischen 1 und 1000 werden erzeugt ...\n");
  for (int i = 0; i < N; i++) {
    A[i] = rand() % 1000 + 1;
  }
}



/**
 * Gibt die N Eintraege von A auf der Konsole aus.
 *
 * A - Zu fuellendes Array
 * N - Laenge von A
 */
void display(int* A, int N) {
  printf("\n\nIm Moment sieht das Array so aus:\n");
  printf("(%d", A[0]);
  for (int i = 1; i < N; i++) {
    printf(",%d", A[i]);
  }
  printf(")\n\n");
}



/**
 * Hauptprogramm
 */
int main(void) {
  int N = 10;
  int* A = (int *) malloc(N * sizeof(int));
  char buffer[BUFFER_LEN];

  srand(time(NULL)); // Initialisiere Zufallsgenerator

  // Array mit Nullen initialisieren
  for (int i = 0; i < N; i++) {
    A[i] = 0;
  }

  printf("\n\n*** Sortieren von Arrays mit ganzen Zahlen zwischen ");
  printf("1 und 1000 in aufsteigender Reihenfolge\n\n");

  char option = '0';
  do {
    // Menue anzeigen
    printf("1) Array-Groesse festlegen       4) Bubblesort (downwards)\n");
    printf("2) Zahlen von Tastatur einlesen  5) Mergesort\n");
    printf("3) Zufallszahlen erzeugen        6) Programm beenden\n\n");

    // Option einlesen
    printf("Auswahl:\t");
    fgets(buffer, BUFFER_LEN, stdin);
    sscanf(buffer, "%c", &option);

    switch (option) {
    case '1':
      printf("Wieviele Zahlen sollen sortiert werden?\n");
      fgets(buffer, BUFFER_LEN, stdin);
      sscanf(buffer, "%d", &N);
      free(A);
      A = (int *) malloc(N * sizeof(int));
      display(A, N);
      break;
    case '2':
      read_fill(A, N);
      display(A, N);
      break;
    case '3':
      rand_fill(A, N);
      display(A, N);
      break;
    case '4':
      // Aufruf BubbleSort
      BubbleSort(A, N);
      display(A, N);
      break;
    case '5':
      MergeSort(A,N);
      printf("*****************MERGE_SORTING*******************\n");
      display(A, N);
      break;
    case '6':
      printf("\nProgrammende\n");
      break;
    default:
      printf("\nBitte Optionen von 1 bis 6 auswaehlen.\n\n\n");
    }
  } while (option != '6');

  free(A);
  return 0;
}
