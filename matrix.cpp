#include <iostream>
#include <string>

double all_koef{1};

int matrix(int j, int k, int n, double* parr, int check, int x) {
    double koef;
    for (int i=1; i <= n-1-check; ++i) {
        double element1 = parr[n*i + j];
        double element2 = parr[n*(i-1) + j];
        koef = element2/element1;
        all_koef = all_koef*koef;

        for (int l=0; l<n; ++l) {
            parr[x*n+l] = parr[x*n+l]*koef;
        }
        
        for (int l=n-1; l>=0; --l) {
            parr[l+n*(x-1)] = parr[l+n*(x-1)] - parr[l+n*x];
        }

        ++x;
    }
    return 0;
}

int main() {
    int x = 1;
    int n;
    int k = 0;
    int check = 0;
    double d = 1;
    std::cout << "Введите размер матрицы (n*n): ";
    std::cin >> n;
    double* parr = new double[n*n]{};
    for (int i=0; i<n; ++i) {
        std::cout << "Введите элементы " << i+1 << " строки матрицы: " << '\n';
        for (int j=0; j<n; ++j){
            std::cin >> parr[n*i+j];
        }
    }

    for (int j=n-1; j>0; --j) {
        matrix(j, k, n, parr, check, x);
        ++k;
        ++check;
    }

    
    for (int z=0; z < n; ++z) {
        d = d*parr[(n+1)*z];
    }
    std::cout << "Определитель матрицы: " << d/all_koef;
    return 0;
}
