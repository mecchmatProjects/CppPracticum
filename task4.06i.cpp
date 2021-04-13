

struct Polynomial {
    int maxPow;
    double *coefficients;
};

Polynomial input(Polynomial polynomial) {
    int n;
    cout << "Input max power\nmaxPow=";
    cin >> n;

    polynomial.maxPow = n;
    polynomial.coefficients = new double[n];
    for (int i = 0; i <= n; ++i) {
        double temp;
        cout << "Input " << i + 1 << " coefficient\n";
        cin >> temp;
        polynomial.coefficients[i] = temp;
    }
    return polynomial;
}

void output(Polynomial polynomial) {
    int max = polynomial.maxPow;
    for (int i = polynomial.maxPow; i >= 0; --i) {
        cout << polynomial.coefficients[max] << setprecision(2);
        if (i != 0) {
            cout << "x^" << max << " + ";
        }
        max--;
    }
}

void deletePolinomial(Polynomial& polynomial){
  delete[] polynomial.coefficients;
}

int main(){
  Polynomial p;
  
  Polynomial q = input(&p);
 
  output(p);
  output(q);

  deletePolinomial(p); 
}
