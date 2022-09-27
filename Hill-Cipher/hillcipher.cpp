/*
Nama Program : Program Hill Cipher
Nama : Rheza Pandya Andhikaputra
NPM : 140810200023
Kelas : A
Tanggal Buat : 26 September 2022
*/

#include <iostream>
#include <math.h>

using namespace std;

float encrypt[3][1], decrypt[3][1], a[3][3], b[3][3], mes[3][1], c[3][3];

void encryption();
void decryption();
void inverse();

int main()
{
    int i, j;
    char msg[3];

    cout << "Input matriks key 3x3 (Invers Matriks != 0)\n";

    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
        {
            cout << "Input Nilai Matriks Key (" << i + 1 << "," << j + 1 << ") : ";
            cin >> a[i][j];
            c[i][j] = a[i][j];
        }

    cout << "\nInput 3 huruf yang mau dienkripsi : ";
    cin >> msg;

    for (i = 0; i < 3; i++)
        mes[i][0] = msg[i] - 97;

    cout << "\nPlainteks Awal : " << msg;
    cout << "\nCipherteks : ";
    encryption();
    cout << "\nPlainteks Akhir : ";
    decryption();
}

void encryption()
{
    int i, j, k;

    for (i = 0; i < 3; i++)
        for (j = 0; j < 1; j++)
            for (k = 0; k < 3; k++)
                encrypt[i][j] = encrypt[i][j] + a[i][k] * mes[k][j];

    for (i = 0; i < 3; i++)
        cout << (char)(fmod(encrypt[i][0], 26) + 97);
}

void decryption()
{
    int i, j, k;

    inverse();

    for (i = 0; i < 3; i++)
        for (j = 0; j < 1; j++)
            for (k = 0; k < 3; k++)
                decrypt[i][j] = decrypt[i][j] + b[i][k] * encrypt[k][j];

    for (i = 0; i < 3; i++)
        cout << (char)(fmod(decrypt[i][0], 26) + 97);
}

void inverse()
{
    int i, j, k;
    float p, q;

    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
        {
            if (i == j)
                b[i][j] = 1;
            else
                b[i][j] = 0;
        }

    for (k = 0; k < 3; k++)
    {
        for (i = 0; i < 3; i++)
        {
            p = c[i][k];
            q = c[k][k];

            for (j = 0; j < 3; j++)
            {
                if (i != k)
                {
                    c[i][j] = c[i][j] * q - p * c[k][j];
                    b[i][j] = b[i][j] * q - p * b[k][j];
                }
            }
        }
    }

    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            b[i][j] = b[i][j] / c[i][i];
}