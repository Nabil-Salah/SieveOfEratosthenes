#include <iostream>
#include <array>
using namespace std;

//Approach for Sieve of Eratosthenes
/*Which is intersted in finding prime numbers in an easierand faster way which
  with one prime founding, i exclude hundreds
  I recommende to watch this for visuals: en.wikipedia.org/wiki/Sieve_of_Eratosthenes*/
void SieveOfEratosthenes() {
    //array that its index indiactes numbers from 0 t 1000
    //if 2 is prime then sieve[2] will be assigned to 1 and others index numbers that accept division by 2
    //will be assigned to 0 indiacting they are not prime cause they accepted division by another number(2)
    //other that itself orby 1
    array<short, 1000> sieve{};
    for (int x = 0; x < sieve.size(); x++)//declaring my array elements to 1, assuming all numbers to be primes
        sieve[x] = 1;
    for (size_t i = 2; i < sieve.size(); i++)//sieve algorithm
        if (sieve[i] != 0)//finding others that accept division by my element consider 2
            for (size_t j = i * 2; j < sieve.size(); j += i)//then 4,6,8.. will be assigned to 0
                sieve[j] = 0;
    //printing founded prime number 
    //notice i print the index
    for (int i = 2; i < sieve.size(); i++)
        if (sieve[i] == 1)
            cout << i << " ";
}
//The traditional way discovering whether a number is prime not
//you can use to check that Sieve numbers are prime
bool isPrime(int num) {
	for (int i = 2; i < 10; i++)
	{
		if (i != num)
			if (num % i == 0)
				return false;
	}
	return true;
}

int main()
{
    SieveOfEratosthenes();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
