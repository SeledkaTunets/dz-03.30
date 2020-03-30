

#include <iostream>
#include <string>
using namespace std;

int Hamming(string bb1, string bb2) {
    int sch = 0;
    if (bb1.length() != bb2.length()) { return -1; }
    if (bb1.length() == bb2.length()) {
        for (int i = 0; i < bb1.length(); i++) {
            if (bb1[i] != bb2[i]) { sch = sch + 1; }
        }
    }
    return sch;
}

int min3(int a, int b, int c) {
    int min = a;
    if (b < min) { min = b;}
    if (c < min) { min = c;}
    return min;
}

int Levenstein(string bb1, string bb2, int Icost, int Dcost, int Rcost) {
    int n = bb1.length();
    int m = bb2.length();
    int ** D = new int*[n];
    for (int i = 0; i < n; i++) { D[i] = new int[m];}
    D[0][0] = 0;
    for (int j = 1; j < m; j++) { D[0][j] = D[0][j-1] + Icost;}
    for (int i = 1; i < n; i++) { D[i][0] = D[i-1][0] + Dcost;}
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
           if (bb1[i] != bb2[j]) {
               int a = D[i-1][j] + Dcost;
               int b = D[i][j-1] + Icost;
               int c = D[i-1][j-1] + Rcost;
           D[i][j] = min3( a, b, c);
           }
           if (bb1[i] == bb2[j]) { D[i][j] = D[i-1][j-1]; }
        }
    }
    return D[n-1][m-1];
}

int main(int argc)
{
    int resultH = -1;
    int resultL = -1;
    int Icost = 15;
    int Dcost = 20;
    int Rcost = 12;
    string bb1;
    string bb2;
    std::cin >> bb1 >> bb2;
    resultH = Hamming(bb1, bb2);
    std::cout << resultH << std::endl ;
    resultL = Levenstein(bb1, bb2, Icost, Dcost, Rcost);
    std::cout << resultL << std::endl;
}

