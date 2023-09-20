
#include <iostream>
#include <bitset>

using namespace std;


bitset<4> complemento_2(bitset<4> num)
{
	bool carry = 1;
	for (int i = 0; i < num.size(); i++)
	{
		num[i] = !num[i]; if (carry) {
			if (num[i] == 0) {
				carry = 0;
			}
			num[i] = !num[i];
		}
	}
	return num;
}




bitset<4> izquierda(bitset<4> num)
{
	bool sign = num[num.size() - 1]; num >>= 1;
	num[num.size() - 1] = sign;

	return num;
}

bitset<4> suma_b(bitset<4> a, bitset<4> b)
{
	bitset<4> res; bool carr = 0;
	for (int i = 0; i < a.size(); i++)
	{
		bool sum = a[i] ^ b[i] ^ carr;
		carr = (a[i] & b[i]) | (carr & (a[i] ^ b[i])); res[i] = sum;
	}
	return res;
}




int main()
{
	int n;
	cout << "Ingrese la cantidad de bits (n): "; cin >> n;

	bitset<4> multi, Q, q_1;
	cout << "Ingrese el multiplicando: "; cin >> multi;
	cout << "Ingrese el multiplicador: "; cin >> Q;


	q_1[0] = Q[0];
	for (int i = 1; i < n; i++)
	{
		q_1[i] = 0;
	}

	bitset<4> A;
	for (int i = 0; i < n; i++)
	{
		if (Q[0] == 1 && q_1[0] == 0)
		{
			A = suma_b(A, multi);
		}
		else if (Q[0] == 0 && q_1[0] == 1)
		{
			A = suma_b(A, complemento_2(multi));
		}

		A = izquierda(A);

		q_1 = Q;
		Q >>= 1;
	}

	cout << "El resultado de la multiplicación en binario es: " << A << endl;
	;

	return 0;
}
