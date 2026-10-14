// Lab 5_3
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double h(const double x); // прототип

int main()
{
	double rp, rk;
	int n;
	cout << "rp = "; cin >> rp;
	cout << "rk = "; cin >> rk;
	cout << "n = "; cin >> n;

	double dr = (rk - rp) / n; // крок

	cout << fixed;
	cout << "z(r) = h(r+1) + h^2(r^2+1) + 1" << endl;
	cout << "------------------------------" << endl;
	cout << "|" << setw(10) << "r" << " |"
		<< setw(15) << "z" << " |" << endl;
	cout << "------------------------------" << endl;
	for (int i = 0; i <= n; i++)
	{
		double r = rp + i * dr;
		double z = h(r + 1) + pow(h(r * r + 1), 2) + 1;
		cout << "|" << setw(10) << setprecision(4) << r << " |"
			<< setw(15) << setprecision(6) << z << " |" << endl;
	}
	cout << "------------------------------" << endl;
	return 0;
}

double h(const double x) // визначення
{
	if (fabs(x) >= 1 || x == 0)
		return (cos(x) + 1) / exp(x);
	else
	{
		int k = 0;
		double a = x * x;  // перший доданок (n = 0)
		double S = a;
		do {
			k++;
			double R = pow(x, 4) / (2. * k * (2. * k + 1)); // коефіцієнт рекурентності
			a *= R;
			S += a;
		} while (k < 6);
		return S / sin(x * x);
	}
}