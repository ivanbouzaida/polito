#include <iostream>
#include <cmath>

int main()
{
    static const int N = 10;

    double arr[N] = {3.2, 5.1, 1.7, 8.4, 2.9, 6.6, 4.0, 7.3, 9.5, 0.8};

    double minimo = arr[0];
    double massimo = arr[0];
    double somma = 0.0;

    for (int i = 0; i < N; i++)
    {
        if (arr[i] < minimo)
            minimo = arr[i];

        if (arr[i] > massimo)
            massimo = arr[i];

        somma += arr[i];
    }

    double media = somma / N;

    double somma_quad = 0.0;
    for (int i = 0; i < N; i++)
    {
        double diff = arr[i] - media;
        somma_quad += diff * diff;
    }

    double dev_std = std::sqrt(somma_quad / N);

    std::cout << "Minimo = " << minimo << "\n";
    std::cout << "Massimo = " << massimo << "\n";
    std::cout << "Media = " << media << "\n";
    std::cout << "Deviazione standard = " << dev_std << "\n";
	
	std::cout << "\nPrima dell'ordinamento:\n";
	for (int i = 0; i < N; i++)
		std::cout << arr[i] << " ";
	std::cout << "\n";

	// Bubble sort
	bool scambiato;
	do
	{
	scambiato = false;
	for (int i = 0; i < N - 1; i++)
		{
			if (arr[i] > arr[i + 1])
			{
				double temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
				scambiato = true;
			}
		}
	} while (scambiato);

	std::cout << "Dopo il bubble sort:\n";
	for (int i = 0; i < N; i++)
		std::cout << arr[i] << " ";
	std::cout << "\n";

    return 0;
}