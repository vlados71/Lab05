// Lab 5_5, варіант 5
// Кількість розбиттів цілого m на доданки, що не перевищують n
#include <iostream>
#include <iomanip>
using namespace std;

// level - рівень рекурсії (параметр-значення), depth - глибина рекурсії (параметр-посилання)
int Q(const int m, const int n, const int level, int& depth);

int main()
{
	int m, n;
	cout << "m = "; cin >> m;
	cout << "n = "; cin >> n;

	if (m < 1 || n < 1)
	{
		cout << "m and n must be positive numbers" << endl;
		return 1;
	}

	int depth = 0; // початкове значення глибини
	int result = Q(m, n, 1, depth); // 1 - початковий рівень

	cout << endl;
	cout << "Q(" << m << ", " << n << ") = " << result << endl;
	cout << "depth = " << depth << endl;
	return 0;
}

int Q(const int m, const int n, const int level, int& depth)
{
	if (level > depth)
		depth = level;

	cout << "level = " << setw(2) << level
		<< "  Q(" << m << ", " << n << ")" << endl;

	if (m == 1 || n == 1)       // Q(1, n) = 1,  Q(m, 1) = 1
		return 1;
	else if (n > m)             // Q(m, n) = Q(m, m),  n > m
		return Q(m, m, level + 1, depth);
	else if (n == m)            // Q(m, n) = 1 + Q(m, n - 1),  n = m
		return 1 + Q(m, n - 1, level + 1, depth);
	else                        // Q(m, n) = Q(m, n - 1) + Q(m - n, n),  n < m
		return Q(m, n - 1, level + 1, depth) + Q(m - n, n, level + 1, depth);
}