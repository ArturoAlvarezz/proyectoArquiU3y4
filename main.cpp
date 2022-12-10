#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> leerTxt(string nombreArchivo){
    vector<string> datos;
    ifstream archivo;
    string texto;
    archivo.open(nombreArchivo); //Abrir el archivo en modo lectura

    if(archivo.fail()){
        cout<<"No se pudo abrir el archivo";
        exit(1);
    }

    while(!archivo.eof()){ //mientras no sea el final del archivo
        getline(archivo,texto);
        datos.push_back(texto);
    }

    archivo.close();
    return datos;
}

void verificadorDeSintaxis(vector<vector<string>> datos, vector<string> setDeInstrucciones){
    vector<vector<string>> datosFinal;
    for (int i = 0; i < datos.size(); i++){
        if (find(setDeInstrucciones.begin(), setDeInstrucciones.end(), datos[i][0]) != setDeInstrucciones.end()){
        }else{
            cout<<"Error de sintaxis en la linea "<<i+1<<endl;
            exit(1);
        }
    }
}

vector<vector<string>> separadorDeDatos(vector<string> datos){
    vector<vector<string>> datosFinal;
    for (int i = 0; i < datos.size(); i++){
        vector<string> datosTemp;
        string temp = "";
        for (int j = 0; j < datos[i].size(); j++){
            if(datos[i][j] == ' '){
                datosTemp.push_back(temp);
                temp = "";
            }else{
                temp += datos[i][j];
            }
        }
        datosTemp.push_back(temp);
        datosFinal.push_back(datosTemp);
    }
    return datosFinal;
}

int main() {
    vector<string> setDeInstruciones{"add","sub","mul","div","mod","and","or","not","mov","cmp","lsl","lsr","asr","nop","ld","st","beq","bgt","b","call","ret"};
    verificadorDeSintaxis(separadorDeDatos(leerTxt("prueba.txt")),setDeInstruciones);

    vector<vector<string>> pruebas = separadorDeDatos(leerTxt("prueba.txt"));
    for (int i = 0; i < pruebas.size(); i++){
        for (int j = 0; j < pruebas[i].size(); ++j) {
            cout<<pruebas[i][j]<<" ";
        }
        cout<<endl;
    }
    cout << "Hello, World!" << endl;
    return 0;
}
