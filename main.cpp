#include <iostream>
#include <vector>
using namespace std;

class TresN{
private:
    int inicio, fin, lenCiclo=0;
    vector <int> *lenCiclos;

public:
    TresN (int i, int f){
        inicio = i;
        fin = f;
        lenCiclos = new vector <int>();
    }
    void cycles_length (int n){
        lenCiclo = 0;
        while (n > 0) {
            lenCiclo += 1;
            if ( n == 1)
                break;
            else if (n % 2 != 0)
                n = (3 * n) + 1;
            else
                n = n / 2;
        }
        lenCiclos->push_back(lenCiclo);
    }
    void iterador(int i, int f){
        if (i>f){
            for (f; f<=i; f++)
                cycles_length(f);
        }else {
            for (i; i<=f; i++)
                cycles_length(i);
    }
    }
    int get_max(){
        int max = 0;
        for(auto len:*lenCiclos)
            if (len > max)
                max = len;
        return max;
    }
    void ejecutar(){
        iterador(inicio, fin);
        cout << inicio <<" " << fin <<" " <<get_max() << endl;
    }

};




int main() {

    int inicio, fin;

    while ( cin >>inicio>>fin ) {
        TresN algoritmo = TresN(inicio, fin);
        algoritmo.ejecutar();
    }
    return 0;
}
