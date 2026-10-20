// Лабораторна робота № 5.4
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

// ітераційний спосіб
double S0(const int K, const int N)
{
	double s = 1; 
	for (int i = K; i <= N; i++)
		s *= (pow(sin(i), 2) + pow(cos(1. / i), 2)) / (i * i);
	return s;
}

// рекурсивний спосіб (зростання)
double S1(const int K, const int N, const int i)
{
	if (i > N)
		return 1;
	else
		return (pow(sin(i), 2) + pow(cos(1. / i), 2)) / (i * i) * S1(K, N, i + 1);
}

// рекурсивний спосіб (спадання)
double S2(const int K, const int N, const int i)
{
	if (i < K)
		return 1;
	else
		return (pow(sin(i), 2) + pow(cos(1. / i), 2)) / (i * i) * S2(K, N, i - 1);
}

// на рекурсивному спуску, значення параметра в
// рекурсивних викликах – зростає;
double S3(const int K, const int N, const int i, double t)
{
	t = t * (pow(sin(i), 2) + pow(cos(1. / i), 2)) / (i * i);
	if (i >= N)
		return t;
	else
		return S3(K, N, i + 1, t);
}

// на рекурсивному спуску, значення параметра в
// рекурсивних викликах – спадає;
double S4(const int K, const int N, const int i, double t)
{
	t = t * (pow(sin(i), 2) + pow(cos(1. / i), 2)) / (i * i);
	if (i <= K)
		return t;
	else
		return S4(K, N, i - 1, t);
}
int main()
{
	int K, N;
	cout << "K = "; cin >> K;
	cout << "N = "; cin >> N;
	cout << "(iter) S0 = " << S0(K, N) << endl;
	cout << "(rec up ++) S1 = " << S1(K, N, K) << endl;
	cout << "(rec up --) S2 = " << S2(K, N, N) << endl;
	cout << "(rec down ++) S3 = " << S3(K, N, K, 1) << endl;
	cout << "(rec down --) S4 = " << S4(K, N, N, 1) << endl;
	cout << scientific << setprecision(15);
	return 0;
}