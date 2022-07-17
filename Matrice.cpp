#include <bits/stdc++.h>
using namespace std;

void luDecomposition(float mat[][4], int n)

{
    float B[4] = {0};

    // Matrice L
    float lower[n][n];
    // Matrice U
    float upper[n][n];

    memset(lower, 0, sizeof(lower));
    memset(upper, 0, sizeof(upper));

    // Matrices solutions
    float X[3] = {0}, Y[3] = {0};

    // Saisie de la matrice A
    cout << "\nMatrice A\n"
         << endl;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("Valeur[%d][%d]: ", i, j);
            cin >> mat[i][j];
        }
    }

    // Saisie de la matrice b
    cout << "\n\nMatrice B\n"
         << endl;
    for (int i = 0; i < 4; i++)
    {
        printf("Valeur[%d]: ", i);
        cin >> B[i];
    }

    // Affichage de A
    cout << "\nMatrice A:\n\n";
    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < n; j++)
            printf("\t%9f\t", mat[i][j]);
        cout << endl;
    }
    printf("\n\n");

    // Affichage de B
    cout << "Matrice B:\n\n";
    for (int i = 0; i < n; i++)
    {
        printf("\t%9f\t", B[i]);
        cout << endl;
    }

    // Decomposition LU
    for (int i = 0; i < n; i++)
    {
        // Matrice L
        for (int k = i; k < n; k++)
        {
            // Somme de L(i, j) * U(j, k)
            float sum = 0;
            for (int j = 0; j < i; j++)
                sum += (lower[i][j] * upper[j][k]);

            //  U(i, k)
            upper[i][k] = mat[i][k] - sum;
        }

        // Matrice U
        for (int k = i; k < n; k++)
        {
            if (i == k)
                lower[i][i] = 1; // Diagonal
            else
            {
                // Summe de L(k, j) * U(j, i)
                float sum = 0;
                for (int j = 0; j < i; j++)
                    sum += (lower[k][j] * upper[j][i]);

                //  L(k, i)
                lower[k][i] = (mat[k][i] - sum) / upper[i][i];
            }
        }
    }

    // Affihage de la matrice L
    cout << "\nMatrice L:\n"
         << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("\t%9f\t", lower[i][j]);
        cout << endl;
    }

    // Affihage de la matrice U
    cout << "\nMatrice U:\n"
         << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("\t%9f\t", upper[i][j]);
        cout << endl;
    }

    for (int i = 0; i < n; i++)
    {
        Y[i] = B[i];
        for (int j = 0; j < i; j++)
        {
            Y[i] -= (lower[i][j] * Y[j]);
        }
    }

    // Détermination de la matrice U
    printf("\n\n");
    for (int i = n - 1; i >= 0; i--)
    {
        X[i] = Y[i];
        for (int j = i + 1; j < n; j++)
        {
            X[i] -= (upper[i][j] * X[j]);
        }
        X[i] /= (upper[i][i]);
    }

    printf("\nMatrice solution [X]: \n\n");
    for (int i = 0; i < n; i++)
    {
        cout << "\t" << X[i] << "\t";
    }
    printf("\n\n");
}

int main()
{
    // Matrice A
    float mat[][4] = {0};

    luDecomposition(mat, 4);
    system("PAUSE");

    return 0;
}
