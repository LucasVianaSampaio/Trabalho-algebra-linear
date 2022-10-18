#include <stdio.h>

int main(void)
{
  int i, j, base1, base2;
  float deta, detb;
  float inv[base1][base1];
  float mud_base[base1][base1];

  printf("Digite a ordem da matriz : ");
  scanf("%d", &base1);

  float a[base1][base1];

  printf("Digite os elementos da base 1: \n");

  // loop para receber os valores da primeira base
  for (i = 1; i <= base1; i++)
  {
    for (j = 1; j <= base1; j++)
    {
      printf("A[%d] [%d]: ", i, j);
      scanf("%f", &a[i][j]);
    }
  }

  base2 = base1;

  float b[base2][base2];

  printf("Digite os elementos da base 2: \n");

  // loop para receber os valores da primeira base
  for (i = 1; i <= base2; i++)
  {
    for (j = 1; j <= base2; j++)
    {
      printf("B[%d] [%d]: ", i, j);
      scanf("%f", &b[i][j]);
    }
  }

  switch (base1)
  {

  case 2:
    // Determinante da matriz 2x2
    deta = (a[1][1] * a[2][2]) - (a[1][2] * a[2][1]);
    detb = (b[1][1] * b[2][2]) - (b[1][2] * b[2][1]);

    printf("\nDeterminante da base1=%.1f\nDeterminante da base2= %.1f\n\n",
           deta, detb);

    if (deta != 0 && detb != 0)
    {
      // Cálculo da matriz inversa da primeira base(2x2)
      inv[1][1] = b[2][2] * (1 / detb);
      inv[1][2] = (-b[1][2]) * (1 / detb);
      inv[2][1] = (-b[2][1]) * (1 / detb);
      inv[2][2] = b[1][1] * (1 / detb);

      printf("A matriz inversa da base2 é: \n");
      printf("%.2f  %.2f\n", inv[1][1], inv[1][2]);
      printf("%.2f  %.2f\n", inv[2][1], inv[2][2]);

      // Cálculo da matriz de mudança de base 2x2
      mud_base[1][1] = (inv[1][1] * a[1][1]) + (inv[1][2] * a[2][1]);
      mud_base[1][2] = (inv[1][1] * a[1][2]) + (inv[1][2] * a[2][2]);
      mud_base[2][1] = (inv[2][1] * a[1][1]) + (inv[2][2] * a[2][1]);
      mud_base[2][2] = (inv[2][1] * a[1][2]) + (inv[2][2] * a[2][2]);

      printf("\n\n A matriz de mudança de base é: \n");
      printf(" %.2f  %.2f \n", mud_base[1][1], mud_base[1][2]);
      printf(" %.2f  %.2f \n", mud_base[2][1], mud_base[2][2]);
    }
    else
    {
      printf("\nA matriz digitada não corresponde a uma base!");
    }
    break;

  case 3:
    deta = (a[3][1] * a[1][2] * a[2][3]) + (a[1][1] * a[2][2] * a[3][3]) +
           (a[2][1] * a[3][2] * a[1][3]) - (a[3][3] * a[1][2] * a[2][1]) -
           (a[1][3] * a[2][2] * a[3][1]) - (a[2][3] * a[3][2] * a[1][1]);

    detb = (b[3][1] * b[1][2] * b[2][3]) + (b[1][1] * b[2][2] * b[3][3]) +
           (b[2][1] * b[3][2] * b[1][3]) - (b[3][3] * b[1][2] * b[2][1]) -
           (b[1][3] * b[2][2] * b[3][1]) - (b[2][3] * b[3][2] * b[1][1]);

    printf("\nDeterminante da base1=%.1f\nDeterminante da base2= %.1f\n\n",
           deta, detb);

    if (deta != 0 && detb != 0)
    {

      inv[1][1] = ((b[2][2] * b[3][3]) - (b[2][3] * b[3][2])) * (1 / detb);
      inv[1][2] = ((b[3][2] * b[1][3]) - (b[3][3] * b[1][2])) * (1 / detb);
      inv[1][3] = ((b[1][2] * b[2][3]) - (b[1][3] * b[2][2])) * (1 / detb);
      inv[2][1] = ((b[2][3] * b[3][1]) - (b[2][1] * b[3][3])) * (1 / detb);
      inv[2][2] = ((b[3][3] * b[1][1]) - (b[3][1] * b[1][3])) * (1 / detb);
      inv[2][3] = ((b[1][3] * b[2][1]) - (b[1][1] * b[2][3])) * (1 / detb);
      inv[3][1] = ((b[2][1] * b[3][2]) - (b[2][2] * b[3][1])) * (1 / detb);
      inv[3][2] = ((b[3][1] * b[1][2]) - (b[3][2] * b[1][1])) * (1 / detb);
      inv[3][3] = ((b[1][1] * b[2][2]) - (b[1][2] * b[2][1])) * (1 / detb);

      printf("\nA matriz inversa da base1 é: \n");
      printf("%.2f  %.2f %.2f\n", inv[1][1], inv[1][2], inv[1][3]);
      printf("%.2f  %.2f %.2f\n", inv[2][1], inv[2][2], inv[2][3]);
      printf("%.2f  %.2f %.2f\n", inv[3][1], inv[3][2], inv[3][3]);

      mud_base[1][1] =
          (inv[1][1] * a[1][1]) + (inv[1][2] * a[2][1]) + (inv[1][3] * a[3][1]);
      mud_base[1][2] =
          (inv[1][1] * a[1][2]) + (inv[1][2] * a[2][2]) + (inv[1][3] * a[3][2]);
      mud_base[1][3] =
          (inv[1][1] * a[1][3]) + (inv[1][2] * a[2][3]) + (inv[1][3] * a[3][3]);
      mud_base[2][1] =
          (inv[2][1] * a[1][1]) + (inv[2][2] * a[2][1]) + (inv[2][3] * a[3][1]);
      mud_base[2][2] =
          (inv[2][1] * a[1][2]) + (inv[2][2] * a[2][2]) + (inv[2][3] * a[3][2]);
      mud_base[2][3] =
          (inv[2][1] * a[1][3]) + (inv[2][2] * a[2][3]) + (inv[2][3] * a[3][3]);
      mud_base[3][1] =
          (inv[3][1] * a[1][1]) + (inv[3][2] * a[2][1]) + (inv[3][3] * a[3][1]);
      mud_base[3][2] =
          (inv[3][1] * a[1][2]) + (inv[3][2] * a[2][2]) + (inv[3][3] * a[3][2]);
      mud_base[3][3] =
          (inv[3][1] * a[1][3]) + (inv[3][2] * a[2][3]) + (inv[3][3] * a[3][3]);

      printf("\nA matriz de mudança de base é: \n");
      printf("%.2f  %.2f %.2f\n", mud_base[1][1], mud_base[1][2],
             mud_base[1][3]);
      printf("%.2f  %.2f %.2f\n", mud_base[2][1], mud_base[2][2],
             mud_base[2][3]);
      printf("%.2f  %.2f %.2f\n", mud_base[3][1], mud_base[3][2],
             mud_base[3][3]);
    }
    else
    {
      printf("A matriz digitada não corresponde a uma base!");
    }

    break;

  case 4:

    detb = 1 * b[1][1] *
               ((b[4][2] * b[2][3] * b[3][4]) + (b[2][2] * b[3][3] * b[4][4]) +
                (b[3][2] * b[4][3] * b[2][4]) - (b[4][4] * b[2][3] * b[3][2]) -
                (b[2][4] * b[3][3] * b[4][2]) - (b[3][4] * b[4][3] * b[2][2])) +
           (-1) * b[2][1] *
               ((b[4][2] * b[1][3] * b[3][4]) + (b[1][2] * b[3][3] * b[4][4]) +
                (b[3][2] * b[4][3] * b[1][4]) - (b[4][4] * b[1][3] * b[3][2]) -
                (b[1][4] * b[3][3] * b[4][2]) - (b[3][4] * b[4][3] * b[1][2])) +
           1 * b[3][1] *
               ((b[4][2] * b[1][3] * b[2][4]) + (b[1][2] * b[2][3] * b[4][4]) +
                (b[2][2] * b[4][3] * b[1][4]) - (b[4][4] * b[1][3] * b[2][2]) -
                (b[1][4] * b[2][3] * b[4][2]) - (b[2][4] * b[4][3] * b[1][2])) +
           (-1) * b[4][1] *
               ((b[3][2] * b[1][3] * b[2][4]) + (b[1][2] * b[2][3] * b[3][4]) +
                (b[2][2] * b[3][3] * b[1][4]) - (b[3][4] * b[1][3] * b[2][2]) -
                (b[1][4] * b[2][3] * b[3][2]) - (b[2][4] * b[3][3] * b[1][2]));

    deta = 1 * a[1][1] *
               ((a[4][2] * a[2][3] * a[3][4]) + (a[2][2] * a[3][3] * a[4][4]) +
                (a[3][2] * a[4][3] * a[2][4]) - (a[4][4] * a[2][3] * a[3][2]) -
                (a[2][4] * a[3][3] * a[4][2]) - (a[3][4] * a[4][3] * a[2][2])) +
           (-1) * a[2][1] *
               ((a[4][2] * a[1][3] * a[3][4]) + (a[1][2] * a[3][3] * a[4][4]) +
                (a[3][2] * a[4][3] * a[1][4]) - (a[4][4] * a[1][3] * a[3][2]) -
                (a[1][4] * a[3][3] * a[4][2]) - (a[3][4] * a[4][3] * a[1][2])) +
           1 * a[3][1] *
               ((a[4][2] * a[1][3] * a[2][4]) + (a[1][2] * a[2][3] * a[4][4]) +
                (a[2][2] * a[4][3] * a[1][4]) - (a[4][4] * a[1][3] * a[2][2]) -
                (a[1][4] * a[2][3] * a[4][2]) - (a[2][4] * a[4][3] * a[1][2])) +
           (-1) * a[4][1] *
               ((a[3][2] * a[1][3] * a[2][4]) + (a[1][2] * a[2][3] * a[3][4]) +
                (a[2][2] * a[3][3] * a[1][4]) - (a[3][4] * a[1][3] * a[2][2]) -
                (a[1][4] * a[2][3] * a[3][2]) - (a[2][4] * a[3][3] * a[1][2]));

    printf("\nDeterminante da base1=%.1f\nDeterminante da base2= %.1f\n\n",
           deta, detb);

    if (deta != 0 && detb != 0)
    {

      inv[1][1] =
          (((b[4][2] * b[2][3] * b[3][4]) + (b[2][2] * b[3][3] * b[4][4]) +
            (b[3][2] * b[4][3] * b[2][4]) - (b[4][4] * b[2][3] * b[3][2]) -
            (b[2][4] * b[3][3] * b[4][2]) - (b[3][4] * b[4][3] * b[2][2])) *
           (1 / detb));

      inv[1][2] =
          ((-(b[4][2] * b[1][3] * b[3][4]) - (b[1][2] * b[3][3] * b[4][4]) -
            (b[3][2] * b[4][3] * b[1][4]) + (b[4][4] * b[1][3] * b[3][2]) +
            (b[1][4] * b[3][3] * b[4][2]) + (b[3][4] * b[4][3] * b[1][2])) *
           (1 / detb));

      inv[1][3] =
          (((b[4][2] * b[1][3] * b[2][4]) + (b[1][2] * b[2][3] * b[4][4]) +
            (b[2][2] * b[4][3] * b[1][4]) - (b[4][4] * b[1][3] * b[2][2]) -
            (b[1][4] * b[2][3] * b[4][2]) - (b[2][4] * b[4][3] * b[1][2])) *
           (1 / detb));

      inv[1][4] =
          ((-(b[3][2] * b[1][3] * b[2][4]) - (b[1][2] * b[2][3] * b[3][4]) -
            (b[2][2] * b[3][3] * b[1][4]) + (b[3][4] * b[1][3] * b[2][2]) +
            (b[1][4] * b[2][3] * b[3][2]) + (b[2][4] * b[3][3] * b[1][2])) *
           (1 / detb));

      inv[2][1] =
          ((-(b[4][1] * b[2][3] * b[3][4]) - (b[2][1] * b[3][3] * b[4][4]) -
            (b[3][1] * b[4][3] * b[2][4]) + (b[4][4] * b[2][3] * b[3][1]) +
            (b[2][4] * b[3][3] * b[4][1]) + (b[3][4] * b[4][3] * b[2][1])) *
           (1 / detb));

      inv[2][2] =
          (((b[4][1] * b[1][3] * b[3][4]) + (b[1][1] * b[3][3] * b[4][4]) +
            (b[3][1] * b[4][3] * b[1][4]) - (b[4][4] * b[1][3] * b[3][1]) -
            (b[1][4] * b[3][3] * b[4][1]) - (b[3][4] * b[4][3] * b[1][1])) *
           (1 / detb));

      inv[2][3] =
          ((-(b[4][1] * b[1][3] * b[2][4]) - (b[1][1] * b[2][3] * b[4][4]) -
            (b[2][1] * b[4][3] * b[1][4]) + (b[4][4] * b[1][3] * b[2][1]) +
            (b[1][4] * b[2][3] * b[4][1]) + (b[2][4] * b[4][3] * b[1][1])) *
           (1 / detb));

      inv[2][4] =
          (((b[3][1] * b[1][3] * b[2][4]) + (b[1][1] * b[2][3] * b[3][4]) +
            (b[2][1] * b[3][3] * b[1][4]) - (b[3][4] * b[1][3] * b[2][1]) -
            (b[1][4] * b[2][3] * b[3][1]) - (b[2][4] * b[3][3] * b[1][1])) *
           (1 / detb));

      inv[3][1] =
          (((b[4][1] * b[2][2] * b[3][4]) + (b[2][1] * b[3][2] * b[4][4]) +
            (b[3][1] * b[4][2] * b[2][4]) - (b[4][4] * b[2][2] * b[3][1]) -
            (b[2][4] * b[3][2] * b[4][1]) - (b[3][4] * b[4][2] * b[2][1])) *
           (1 / detb));

      inv[3][2] =
          ((-(b[4][1] * b[1][2] * b[3][4]) - (b[1][1] * b[3][2] * b[4][4]) -
            (b[3][1] * b[4][2] * b[1][4]) + (b[4][4] * b[1][2] * b[3][1]) +
            (b[1][4] * b[3][2] * b[4][1]) + (b[3][4] * b[4][2] * b[1][1])) *
           (1 / detb));

      inv[3][3] =
          (((b[4][1] * b[1][2] * b[2][4]) + (b[1][1] * b[2][2] * b[4][4]) +
            (b[2][1] * b[4][2] * b[1][4]) - (b[4][4] * b[1][2] * b[2][1]) -
            (b[1][4] * b[2][2] * b[4][1]) - (b[2][4] * b[4][2] * b[1][1])) *
           (1 / detb));

      inv[3][4] =
          (((b[3][1] * b[1][2] * b[2][4]) + (b[1][1] * b[2][2] * b[3][4]) +
            (b[2][1] * b[3][2] * b[1][4]) - (b[3][4] * b[1][2] * b[2][1]) -
            (b[1][4] * b[2][2] * b[3][1]) - (b[2][4] * b[3][2] * b[1][1])) *
           (-1 / detb));

      inv[4][1] =
          ((-(b[4][1] * b[2][2] * b[3][3]) - (b[2][1] * b[3][2] * b[4][3]) -
            (b[3][1] * b[4][2] * b[2][3]) + (b[4][3] * b[2][2] * b[3][1]) +
            (b[2][3] * b[3][2] * b[4][1]) + (b[3][3] * b[4][2] * b[2][1])) *
           (1 / detb));

      inv[4][2] =
          (((b[4][1] * b[1][2] * b[3][3]) + (b[1][1] * b[3][2] * b[4][3]) +
            (b[3][1] * b[4][2] * b[1][3]) - (b[4][3] * b[1][2] * b[3][1]) -
            (b[1][3] * b[3][2] * b[4][1]) - (b[3][3] * b[4][2] * b[1][1])) *
           (1 / detb));

      inv[4][3] =
          ((-(b[4][1] * b[1][2] * b[2][3]) - (b[1][1] * b[2][2] * b[4][3]) -
            (b[2][1] * b[4][2] * b[1][3]) + (b[4][3] * b[1][2] * b[2][1]) +
            (b[1][3] * b[2][2] * b[4][1]) + (b[2][3] * b[4][2] * b[1][1])) *
           (1 / detb));

      inv[4][4] =
          (((b[3][1] * b[1][2] * b[2][3]) + (b[1][1] * b[2][2] * b[3][3]) +
            (b[2][1] * b[3][2] * b[1][3]) - (b[3][3] * b[1][2] * b[2][1]) -
            (b[1][3] * b[2][2] * b[3][1]) - (b[2][3] * b[3][2] * b[1][1])) *
           (1 / detb));

      printf("\nA matriz inversa da base2 é: \n");
      printf("%.3f  %.3f %.3f %.3f\n", inv[1][1], inv[1][2], inv[1][3],
             inv[1][4]);
      printf("%.3f  %.3f %.3f %.3f\n", inv[2][1], inv[2][2], inv[2][3],
             inv[2][4]);
      printf("%.3f  %.3f %.3f %.3f\n", inv[3][1], inv[3][2], inv[3][3],
             inv[3][4]);
      printf("%.3f  %.3f %.3f %.3f\n", inv[4][1], inv[4][2], inv[4][3],
             inv[4][4]);

      mud_base[1][1] = ((inv[1][1] * a[1][1]) + (inv[1][2] * a[2][1]) +
                        (inv[1][3] * a[3][1]) + (inv[1][4] * a[4][1]));

      mud_base[1][2] = ((inv[1][1] * a[1][2]) + (inv[1][2] * a[2][2]) +
                        (inv[1][3] * a[3][2]) + (inv[1][4] * a[4][2]));

      mud_base[1][3] = (inv[1][1] * a[1][3]) + (inv[1][2] * a[2][3]) +
                       (inv[1][3] * a[3][3]) + (inv[1][4] * a[4][3]);

      mud_base[1][4] = ((inv[1][1] * a[1][4]) + (inv[1][2] * a[2][4]) +
                        (inv[1][3] * a[3][4]) + (inv[1][4] * a[4][4]));

      mud_base[2][1] = ((inv[2][1] * a[1][1]) + (inv[2][2] * a[2][1]) +
                        (inv[2][3] * a[3][1]) + (inv[2][4] * a[4][1]));

      mud_base[2][2] = ((inv[2][1] * a[1][2]) + (inv[2][2] * a[2][2]) +
                        (inv[2][3] * a[3][2]) + (inv[2][4] * a[4][2]));

      mud_base[2][3] = ((inv[2][1] * a[1][3]) + (inv[2][2] * a[2][3]) +
                        (inv[2][3] * a[3][3]) + (inv[2][4] * a[4][3]));

      mud_base[2][4] = ((inv[2][1] * a[1][4]) + (inv[2][2] * a[2][4]) +
                        (inv[2][3] * a[3][4]) + (inv[2][4] * a[4][4]));

      mud_base[3][1] = ((inv[3][1] * a[1][1]) + (inv[3][2] * a[2][1]) +
                        (inv[3][3] * a[3][1]) + (inv[3][4] * a[4][1]));

      mud_base[3][2] = ((inv[3][1] * a[1][2]) + (inv[3][2] * a[2][2]) +
                        (inv[3][3] * a[3][2]) + (inv[3][4] * a[4][2]));

      mud_base[3][3] = ((inv[3][1] * a[1][3]) + (inv[3][2] * a[2][3]) +
                        (inv[3][3] * a[3][3]) + (inv[3][4] * a[4][3]));

      mud_base[3][4] = ((inv[3][1] * a[1][4]) + (inv[3][2] * a[2][4]) +
                        (inv[3][3] * a[3][4]) + (inv[3][4] * a[4][4]));

      mud_base[4][1] = ((inv[4][1] * a[1][1]) + (inv[4][2] * a[2][1]) +
                        (inv[4][3] * a[3][1]) + (inv[4][4] * a[4][1]));

      mud_base[4][2] = ((inv[4][1] * a[1][2]) + (inv[4][2] * a[2][2]) +
                        (inv[4][3] * a[3][2]) + (inv[4][4] * a[4][2]));

      mud_base[4][3] = ((inv[4][1] * a[1][3]) + (inv[4][2] * a[2][3]) +
                        (inv[4][3] * a[3][3]) + (inv[4][4] * a[4][3]));

      mud_base[4][4] = ((inv[4][1] * a[1][4]) + (inv[4][2] * a[2][4]) +
                        (inv[4][3] * a[3][4]) + (inv[4][4] * a[4][4]));

      printf("\nA matriz de mudança de base é: \n");
      printf("%.3f  %.3f %.3f %.3f\n", mud_base[1][1], mud_base[1][2],
             mud_base[1][3], mud_base[1][4]);
      printf("%.3f  %.3f %.3f %.3f\n", mud_base[2][1], mud_base[2][2],
             mud_base[2][3], mud_base[2][4]);
      printf("%.3f  %.3f %.3f %.3f\n", mud_base[3][1], mud_base[3][2],
             mud_base[3][3], mud_base[3][4]);
      printf("%.3f  %.3f %.3f %.3f\n", mud_base[4][1], mud_base[4][2],
             mud_base[4][3], mud_base[4][4]);
    }
    else
    {
      printf("A matriz digitada não corresponde a uma base!");
    }
  }

  return 0;
}