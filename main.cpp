// CC0 1.0 Universal (CC0 1.0)
// Public Domain Dedication
// https://github.com/nmrr

#include <iostream>
#include <random>
#include <gmpxx.h>

using namespace std;

mpz_class getPrime(size_t size, bool checksize=false)
{
    random_device rnd;
    uniform_int_distribution<> dist(0, 1);
    mpz_class prime;
    if (size <2) size = 2;

    while(1)
    {
        string numberString = "1";
        for (size_t i=1; i<size; i++)
        {
            numberString += to_string(dist(rnd));
        }

        mpz_class n(numberString,2);
        if (mpz_probab_prime_p(n.get_mpz_t(), 50) != 0)
        {
            prime = n;
        }
        else
        {
            mpz_nextprime(prime.get_mpz_t(), n.get_mpz_t());
        }

        if (checksize == true)
        {
            if (mpz_sizeinbase(prime.get_mpz_t(), 2) == size) break;
        }
        else break;
    }

    return prime;
}

int main(int argc, char **argv)
{
    cout << "== BIG PRIME ==" << endl;

    for (int i=0; i<10; i++)
    {
        mpz_class prime(getPrime(2048, true));
        cout << prime.get_mpz_t() << endl;
    }
    
    return 0;
}