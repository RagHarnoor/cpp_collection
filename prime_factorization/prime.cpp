#include <iostream>
#include <vector>

using namespace std;

vector<int> generatePrimes(int n){
    vector<bool> isPrime(n+1, true);
    isPrime[0] = isPrime[1] = false;

    //mark all multiples of i as non prime
    for (int i=2; i*i<=n; i++){
        if (isPrime[i]){
            for(int j=i*i; j<=n; j+=i){
                isPrime[j]=false;
            }
        }
    }

    //collect all primes into a different vector
    vector<int> primes;
    for(int i=2; i<=n; i++){
        if(isPrime[i]){
            primes.push_back(i);
        }
    }

    return primes;
}

vector<int> primeFactorization(int num, const vector<int>& primes) {
    vector<int> factors;
    for(int prime: primes){

        //only check primes less than sqrt(n)
        if( prime*prime > num){
            break;
        };

        //
        while(num % prime == 0){
            factors.push_back(prime);
            num/=prime;
        }
    }
    if(num>1) factors.push_back(num);

    return factors;

}

int main(){

    int N=30;
    cout<<"Primes up to "<<N<<" : ";
    vector<int> primes = generatePrimes(N);
    for (int p: primes) cout<<p<<" ";
    cout<<endl;

    int num=84;
    cout<<"Prime factors of "<<num<<": ";
    vector<int> factors = primeFactorization(num, primes);
    for(int f: factors) cout<<f<<" ";
    cout<<endl;

    return 0;
}
