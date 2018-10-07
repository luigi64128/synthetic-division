#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double coef; //coefficient
    double cons; //constant
    
    // lengths and indexes (set later on in the script)
    double coefLength = 0.0;
    double coefIndex = 0.0;
    double consLength = 0.0;
    double consIndex = 0.0;

    //Length
    cout << "Enter the length of the polynomial: ";
    int length; // length of polynomial
    cin >> length;
    //Polynomial Values
    cout << "Enter " << length << " values of the polynomal (enter after each): \n\n";
    double a[length]; //= { 1, -3, 3, 2, -1 }; // a is the polynomial
    for (int i = 0; i < length; i++) { cin >> a[i]; } 
    coef = abs(a[0]);
    cons = abs(a[length-1]);
    
    // coefficient 
    for (double i = 1; i <= coef; i++) {
        if (fmod(coef,i) == 0) {
            coefLength++;   
        }
    }    
    //set coefficient array w/ length
    double arrCoef[(int)coefLength];
    for (double i = 1.0; i <= coef; i++) {
        if (fmod(coef,i) == 0) {
            arrCoef[(int)coefIndex] = i;
            coefIndex++;
        }
    }

    // constant 
    for (double i = 1; i <= cons; i++) {
        if (fmod(cons,i) == 0) {
            consLength++;   
        }
    }    
    //set constant array w/ length
    double arrCons[(int)consLength];
    for (double i = 1.0; i <= cons; i++) {
        if (fmod(cons,i) == 0) {
            arrCons[(int)consIndex] = i;
            consIndex++;
        }
    }
    //RESULT
    int resultLength = coefLength*consLength;
    double arrResult[resultLength];
    double j = 0;
    for (double resultIndex = 0; resultIndex < consLength; resultIndex++) {
        for (double i = 0; i < coefLength; i++) {
            j++;
            arrResult[(int)j] = arrCons[(int)resultIndex]/arrCoef[(int)i];
        }
        
    }
    arrCons[0] = 1; //fixes a glitch that reset the first thing to the last thing
    //output factor
    cout << endl << "Factor the coefficient: \n";
    for (int i = 0; i < coefLength; i++) { cout << i << " | " << arrCoef[i] << endl; }
    cout << endl << "Factor the constant: \n"; 
    for (int i = 0; i < consLength; i++) { cout << i << " | " << arrCons[i] << endl; }
    cout << endl; 
    //for (int i = 1; i <= resultLength; i++) { cout << i-1 << " | " << arrResult[i] << endl; }

    /// ------ Synthetic Division Time
    //Zero Value, stored in arrResult[] (h)
    double n[length], x[length]; // n = middle section, x = resulting polynomial
    cout << endl << "Result:" << endl;
    int zeroNum = 0;
    double arrZero[zeroNum];
    for (int q = 0; q < resultLength*2; q++) {
        //initialize [0]
        x[0] = a[0];
        n[0] = 0;
        if (q <= floor(resultLength)) {
            for (int i = 1; i < length; i++) {
                n[i] = arrResult[q]*x[i-1];
                x[i] = a[i] + n[i];
            }
            if (x[length-1] == 0) {
                cout << arrResult[q] << " is a zero" << endl;
                arrZero[zeroNum] = arrResult[q];
                for (int i = 0; i < length; i++) { cout << a[i] << " "; }
                cout << " | " << arrZero[zeroNum] << endl;
                for (int i = 0; i < length; i++) { cout << n[i] << " "; }
                cout << endl;
                cout << a[0] << " ";
                for (int i = 1; i < length; i++) { cout << x[i] << " "; }
                cout << endl << endl;
                zeroNum++;
            }
        }
        if (q > floor(resultLength)) {
            for (int i = 1; i < length; i++) {
                n[i] = -arrResult[q]*x[i-1];
                x[i] = a[i] + n[i];
            }
            if (x[length-1] == 0) {
                cout << -arrResult[q] << " is a zero" << endl;
                arrZero[zeroNum] = -arrResult[q];
                for (int i = 0; i < length; i++) { cout << a[i] << " "; }
                cout << " | " << arrZero[zeroNum] << endl;
                for (int i = 0; i < length; i++) { cout << n[i] << " "; }
                cout << endl;
                cout << a[0] << " "; //since x[0] broke too, but don't need it anyway
                for (int i = 1; i < length; i++) { cout << x[i] << " "; }
                cout << endl << endl;   
                zeroNum++;
            }
        }
    }

    return 0;
}
