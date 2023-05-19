#include <iostream>
#include <cmath>
#include <vector>
#include <string>

using namespace std;
struct MatrixHandler
{
    std::vector<std::vector<float>> matrizIdentidad = {
        {1,0,0}
        ,{0,1,0}
        ,{0,0,1}
    };

    std::vector<std::vector<float>> matrizTransformar = {
        {0}
        ,{0}
        ,{1}
    };

    std::vector<std::vector<float>> resultado = {
        {0}
        ,{0}
        ,{0}
    };
    void resetearMatrices()
    {
        matrizIdentidad = {
        {1,0,0}
        ,{0,1,0}
        ,{0,0,1}
        };
        matrizTransformar = {
        {0}
        ,{0}
        ,{1}
        };
        resultado = {
        {0}
        ,{0}
        ,{0}
        };

    }


    std::vector<std::vector<float>> crearEstructura()
    {
        return resultado;
    }


    void identidadTraslacion(float x, float y) 
    {
        matrizIdentidad[0][2] = x;
        matrizIdentidad[1][2] = y;
    }

    void identidadRotacion(float angulo) {
        const float PI = 3.14159;
        float rad = angulo * PI / 180;
        float cosAng = std::cos(rad);
        float sinAng = std::sin(rad);

        matrizIdentidad[0][0] = cosAng;
        matrizIdentidad[0][1] = -sinAng;
        matrizIdentidad[1][0] = sinAng;
        matrizIdentidad[1][1] = cosAng;
    }

    void identidadEscala(float x, float y) 
    {
        matrizIdentidad[0][0] = x;
        matrizIdentidad[1][1] = y;
    }
    //________________________________________________________________________
    void imprimirMatriz(string opcion) {
        if (opcion == "A") {

            std::cout << "Matriz A (Identidad):" << std::endl;
            for (const auto& row : matrizIdentidad) {
                for (float element : row) {
                    std::cout << element << " ";
                }
                std::cout << std::endl;
            }
        }
        else if (opcion == "B") {

            std::cout << "Matriz B (Transformar):" << std::endl;
            for (const auto& row : matrizTransformar) {
                for (float element : row) {
                    std::cout << element << " ";
                }
                std::cout << std::endl;
            }
        }
        else if (opcion == "C") {

            std::cout << "Matriz C (Resultado):" << std::endl;
            for (const auto& row : resultado) {
                for (float element : row) {
                    std::cout << element << " ";
                }
                std::cout << std::endl;
            }
            // Imprimir matriz resultado (vacía en este caso)
        }
        else {
            std::cout << "Opción inválida. Por favor, elija A, B o C." << std::endl;
        }
    }
    //______________________________________________________________________________________
    void multiplicarMatrices()
    {
        for (size_t i = 0; i < matrizIdentidad.size(); i++) {
            for (size_t j = 0; j < matrizTransformar[0].size(); j++) {
                for (size_t k = 0; k < matrizIdentidad[0].size(); k++) {
                    resultado[i][j] += matrizIdentidad[i][k] * matrizTransformar[k][j];
                }
            }
        }
    }
    //_____________________________________________________________________________________
    void elementoModificar(float x, float y) {
        // Modificar la matriz en sus respectivos lugares
        matrizTransformar[0][0] = x;
        matrizTransformar[1][0] = y;
    }
    //_____________________________________________________________________________________
    void trasladar2D(float trasladarx,float trasladarY,float X, float Y)
    {
        identidadTraslacion(trasladarx, trasladarY);
        imprimirMatriz("A");
        elementoModificar(X,Y);
        imprimirMatriz("B");
        multiplicarMatrices();
        imprimirMatriz("C");
        
    }
    void rotar2D(float angulo, float X, float Y)
    {
        identidadRotacion(angulo);
        imprimirMatriz("A");
        elementoModificar(X, Y);
        imprimirMatriz("B");
        multiplicarMatrices();
        imprimirMatriz("C");
        
    }
    void escala2D(float trasladarx, float trasladarY, float X, float Y)
    {
        identidadEscala(trasladarx, trasladarY);
        imprimirMatriz("A");
        elementoModificar(X, Y);
        imprimirMatriz("B");
        multiplicarMatrices();
        imprimirMatriz("C");
        
    }

};