#include <iostream>

using namespace std;

float* get_tab(int size)
{
	float* tab = new float[size];
	for (int i = 0; i < size; i++)
	{
		tab[i] = 0;
	}
	return tab;
}

float interpolate(float* x, float* y, int size, float& interpolation_point)
{
	float p, interpolation_value = 0;
	for (int i = 0; i < size; i++)
	{
		p = 1;
		for (int j = 0; j < size; j++)
		{
			if (i != j)
			{
				p = p * (interpolation_point - x[j]) / (x[i] - x[j]);
			}
		}
		interpolation_value += p * y[i];
	}
	return interpolation_value;
}

float find_min_value(float* tab, int size)
{
	float tmp = tab[0];
	for (int i = 0; i < size; i++)
	{
		if (tmp > tab[i]) tmp = tab[i];
	}
	return tmp;
}

float find_max_value(float* tab, int size)
{
	float tmp = tab[0];
	for (int i = 0; i < size; i++)
	{
		if (tmp < tab[i]) tmp = tab[i];
	}
	return tmp;
}

int main()
{
	int n = 0;
	float* x;
	float* y;
	float interpolation_point;
	float result;
	float min, max;
	cout << "Podaj ilosc punktow: ";
	cin >> n;
	x = get_tab(n);
	y = get_tab(n);
	cout << "x: " << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> x[i];
	}
	cout << "\ny: \n";
	for (int i = 0; i < n; i++)
	{
		cin >> y[i];
	}
	cout << "Podaj punkt interpolacyjny: ";
	cin >> interpolation_point;
	result = interpolate(x, y, n, interpolation_point);

	max = find_max_value(x, n);
	min = find_min_value(x, n);

	if (interpolation_point > max || interpolation_point < min)
	{
		cout << "Wartosc ekstrapolowana w punkcie " << interpolation_point << " wynosi " << result;
	}
	else
	{
		cout << "Wartosc interpolowana w punkcie " << interpolation_point << " wynosi " << result;
	}
	delete[] x;
	delete[] y;
}