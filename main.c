#include <stdio.h>
#include <stdlib.h>

#define max (50)
#define max_basis (1)

void logic(char buffer[], int choose_basis) {
  long int desimal = strtol(buffer, NULL, 10);
  int hasil[max];
  char heksadesimal[max];

  int biner_idx = 0;
  int octal_idx = 0;
  int heksadesimal_idx = 0;
  switch (choose_basis) {
  case 2:
    while (desimal > 0) {
      if (desimal % 2 == 0) {
        hasil[biner_idx] = 0;
      } else {
        hasil[biner_idx] = desimal % 2;
      }

      desimal = desimal / 2;
      biner_idx++;
    }

    for (int j = biner_idx - 1; j >= 0; j--) {
      printf("%d", hasil[j]);
    }
    printf("\n");
    break;
  case 8:
    while (desimal > 0) {
      if (desimal % 8 == 0) {
        hasil[octal_idx] = 0;
      } else {
        hasil[octal_idx] = desimal % 8;
      }

      desimal = desimal / 8;
      octal_idx++;
    }

    for (int j = octal_idx - 1; j >= 0; j--) {
      printf("%d", hasil[j]);
    }
    printf("\n");
    break;
  case 16:
    while (desimal > 0) {
      int sisa = desimal % 16;
      if (sisa < 10) {
        heksadesimal[heksadesimal_idx] = sisa + '0';
      } else {
        heksadesimal[heksadesimal_idx] = (sisa - 10) + 'A';
      }

      desimal = desimal / 16;
      heksadesimal_idx++;
    }

    for (int j = heksadesimal_idx - 1; j >= 0; j--) {
      printf("%c", heksadesimal[j]);
    }
    printf("\n");
    break;
  }
}

int main() {
  char buffer[max];
  int choose_basis = 0;

  printf("Masukan bilangan desimal (max 50): ");
  fgets(buffer, sizeof(buffer), stdin);

  printf("\n");
  printf("Masukan basis(int) (2).biner (8).oktal (16). heksadesimal: ");
  scanf("%d", &choose_basis);
  logic(buffer, choose_basis);

  return 0;
}
