#include <iostream>

using namespace std;

int main() {
    cout << "p\tq\tr\t(p AND q)\t(p AND r)\t(p AND q) XOR (p AND r)" << endl;
    cout << "--------------------------------------------" << endl;


    for (int p = 0; p <= 1; p++) {
        for (int q = 0; q <= 1; q++) {
            for (int r = 0; r <= 1; r++) {
               
                int pq = p && q;
                int pr = p && r;

                int result = pq ^ pr; 

                cout << p << "\t" << q << "\t" << r << "\t" << pq << "\t\t" << pr << "\t\t" << result << endl;
            }
        }
    }

    return 0;
}
