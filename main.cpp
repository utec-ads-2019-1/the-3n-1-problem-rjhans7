#include <iostream>
#include <vector>
using namespace std;

class TresN{
private:
    int inicio, fin, contador=0;
    vector <int> *contadores;

public:
    TresN (int i, int f){
        inicio = i;
        fin = f;
        contadores = new vector <int>();
    }
    void cycles_length (int n){
        contador = 0;
        while (n > 0) {
            contador += 1;
            if ( n == 1)
                break;
            else if (n % 2 != 0)
                n = (3 * n) + 1;
            else
                n = n / 2;
        }
        contadores->push_back(contador);
    }
    void iterador(int i, int f){
        for (i; i<f; i++){
            cycles_length(i);
        }
    }
    int get_max(){
        int max = 0;
        for(auto cont:*contadores)
            if (cont > max)
                max = cont;
        return max;
    }
    void ejecutar(){
        iterador(inicio, fin);
        cout << inicio <<" " << fin <<" " <<get_max() << endl;
    }

};




int main() {
    int inicio, fin;
    cin >> inicio >> fin;
    TresN algoritmo = TresN(inicio,fin);
    algoritmo.ejecutar();

    return 0;
}
