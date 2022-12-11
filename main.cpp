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

void verificadorDeSintaxis(vector<vector<string>> datos){
    for (int i = 0; i < datos.size(); i++){
        if (datos[i][0] == "add" || datos[i][0] == "sub" || datos[i][0] == "mul" || datos[i][0] == "div" || datos[i][0] == "mod" || datos[i][0] == "and" || datos[i][0] == "or" || datos[i][0] == "lsl" || datos[i][0] == "lsr" || datos[i][0] == "asr"){
            if (datos[1].size() == 4){

            }else{
                cout<<"Error de sintaxis en la linea "<<i+1<<endl;
            }
        }else if (datos[i][0] == "cmp" || datos[i][0] == "not" || datos[i][0] == "mov"){
            if (datos[1].size() == 3){

            }else{
                cout<<"Error de sintaxis en la linea "<<i+1<<endl;
            }
        }else if (datos[i][0] == "nop" || datos[i][0] == "ret"){
            if (datos[1].size() == 1){

            }else{
                cout<<"Error de sintaxis en la linea "<<i+1<<endl;
            }
        }else if (datos[i][0] == "ld" || datos[i][0] == "st"){
            if (datos[1].size() == 3){

            }else{
                cout<<"Error de sintaxis en la linea "<<i+1<<endl;
            }
        }else if (datos[i][0] == "beq" || datos[i][0] == "bgt" || datos[i][0] == "b" || datos[i][0] == "call"){
            if (datos[1].size() == 2){

            }else{
                cout<<"Error de sintaxis en la linea "<<i+1<<endl;
            }
        }else{
            cout<<"Error de sintaxis en la linea "<<i+1<<endl;
            exit(1);
        }
    }
    cout << "Sintaxis correcta" << endl;
}

vector<vector<string>> separadorDeDatos(vector<string> datos){
    vector<vector<string>> datosFinal;
    for (int i = 0; i < datos.size(); i++){
        vector<string> datosTemp;
        string temp = "";
        for (int j = 0; j < datos[i].size(); j++){
            if(datos[i][j] == ' ' || datos[i][j] == ','){
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

vector<vector<string>> numerarProcesos(vector<vector<string>> datos){
    vector<vector<string>> datosFinal;
    for (int i = 0; i < datos.size(); i++){
        vector<string> datosTemp;
        for (int j = 0; j < datos[i].size(); j++){
            if (j == 0){
                datosTemp.push_back(to_string(i+1));
            }
            datosTemp.push_back(datos[i][j]);
        }
        datosFinal.push_back(datosTemp);
    }
    return datosFinal;
}

void pipeline(vector<vector<string>> datos){
    int j = 0, i = 0, ciclo = 0;
    vector<string> estapas{"IF", "ID", "EX", "MEM", "WB"};
    vector<string> procesos{"0", "0", "0", "0", "0"};
    cout << "Ciclo\tIF\tID\tEX\tMEM\tWB" << endl;
    while (j == 0){
        procesos[4] = procesos[3];
        procesos[3] = procesos[2];
        procesos[2] = procesos[1];
        procesos[1] = procesos[0];
        procesos[0] = datos[i][0];
        i+=1, ciclo+=1;
        cout << ciclo << "\t" << "\t" << procesos[0] << "\t" << procesos[1] << "\t" << procesos[2] << "\t" << procesos[3] << "\t" << procesos[4] << endl;
        if (i == datos.size()){
            j = 1;
        }
    }
}

void algoritmoDeConflictos(vector<vector<string>> datos){
    for (int i = 0; i < datos.size(); i++){
        if (datos[i][1] == "add" || datos[i][1] == "sub" || datos[i][1] == "mul" || datos[i][1] == "div" || datos[i][1] == "mod" || datos[i][1] == "and" || datos[i][1] == "or" || datos[i][1] == "lsl" || datos[i][1] == "lsr" || datos[i][1] == "asr"){
            if(i+1 < datos.size()){
                if (datos[i+1][1] == "add" || datos[i+1][1] == "sub" || datos[i+1][1] == "mul" || datos[i+1][1] == "div" || datos[i+1][1] == "mod" || datos[i+1][1] == "and" || datos[i+1][1] == "or" || datos[i+1][1] == "lsl" || datos[i+1][1] == "lsr" || datos[i+1][1] == "asr") {
                    if (datos[i+1][3] == datos[i][2] || datos[i+1][4] == datos[i][2]) {
                        cout << "Error de dependencia de datos en la linea " << i + 2 << endl;
                    }
                }else if(datos[i+1][1] == "cmp" || datos[i+1][1] == "not" || datos[i+1][1] == "mov"){
                    if (datos[i+1][3] == datos[i][2]) {
                        cout << "Error de dependencia de datos en la linea " << i + 2 << endl;
                    }
                }else if(datos[i+1][1] == "ld" || datos[i+1][1] == "st"){
                    //falta
                }else if(datos[i+1][1] == "beq" || datos[i+1][1] == "bgt" || datos[i+1][1] == "b" || datos[i+1][1] == "call"){
                    //falta
                }
            }
            if(i+2 < datos.size()){
                if (datos[i+2][1] == "add" || datos[i+2][1] == "sub" || datos[i+2][1] == "mul" || datos[i+2][1] == "div" || datos[i+2][1] == "mod" || datos[i+2][1] == "and" || datos[i+2][1] == "or" || datos[i+2][1] == "lsl" || datos[i+2][1] == "lsr" || datos[i+2][1] == "asr") {
                    if (datos[i+2][3] == datos[i][2] || datos[i+2][4] == datos[i][2]) {
                        cout << "Error de dependencia de datos en la linea " << i + 3 << endl;
                    }
                }else if(datos[i+2][1] == "cmp" || datos[i+2][1] == "not" || datos[i+2][1] == "mov"){
                    if (datos[i+2][3] == datos[i][2]) {
                        cout << "Error de dependencia de datos en la linea " << i + 3 << endl;
                    }
                }else if(datos[i+2][1] == "ld" || datos[i+2][1] == "st"){
                    //falta
                }else if(datos[i+2][1] == "beq" || datos[i+2][1] == "bgt" || datos[i+2][1] == "b" || datos[i+2][1] == "call"){
                    //falta
                }
            }
            if(i+3 < datos.size()){
                if (datos[i+3][1] == "add" || datos[i+3][1] == "sub" || datos[i+3][1] == "mul" || datos[i+3][1] == "div" || datos[i+3][1] == "mod" || datos[i+3][1] == "and" || datos[i+3][1] == "or" || datos[i+3][1] == "lsl" || datos[i+3][1] == "lsr" || datos[i+3][1] == "asr") {
                    if (datos[i+3][3] == datos[i][2] || datos[i+3][4] == datos[i][2]) {
                        cout << "Error de dependencia de datos en la linea " << i + 4 << endl;
                    }
                }else if(datos[i+3][1] == "cmp" || datos[i+3][1] == "not" || datos[i+3][1] == "mov"){
                    if (datos[i+3][3] == datos[i][2]) {
                        cout << "Error de dependencia de datos en la linea " << i + 4 << endl;
                    }
                }else if(datos[i+3][1] == "ld" || datos[i+3][1] == "st"){
                    //falta
                }else if(datos[i+3][1] == "beq" || datos[i+3][1] == "bgt" || datos[i+3][1] == "b" || datos[i+3][1] == "call"){
                    //falta
                }
            }
        }else if (datos[i][1] == "cmp" || datos[i][1] == "not" || datos[i][1] == "mov"){
            if(i+1 < datos.size()){
                if (datos[i+1][1] == "add" || datos[i+1][1] == "sub" || datos[i+1][1] == "mul" || datos[i+1][1] == "div" || datos[i+1][1] == "mod" || datos[i+1][1] == "and" || datos[i+1][1] == "or" || datos[i+1][1] == "lsl" || datos[i+1][1] == "lsr" || datos[i+1][1] == "asr") {
                    if (datos[i+1][3] == datos[i][2] || datos[i+1][4] == datos[i][2]) {
                        cout << "Error de dependencia de datos en la linea " << i + 2 << endl;
                    }
                }else if(datos[i+1][1] == "cmp" || datos[i+1][1] == "not" || datos[i+1][1] == "mov"){ //cmp no tiene dependencia de datos?
                    if (datos[i+1][3] == datos[i][2]) {
                        cout << "Error de dependencia de datos en la linea " << i + 2 << endl;
                    }
                }else if(datos[i+1][1] == "ld" || datos[i+1][1] == "st"){
                    //falta
                }else if(datos[i+1][1] == "beq" || datos[i+1][1] == "bgt" || datos[i+1][1] == "b" || datos[i+1][1] == "call"){
                    //falta
                }
            }
            if(i+2 < datos.size()){
                if (datos[i+2][1] == "add" || datos[i+2][1] == "sub" || datos[i+2][1] == "mul" || datos[i+2][1] == "div" || datos[i+2][1] == "mod" || datos[i+2][1] == "and" || datos[i+2][1] == "or" || datos[i+2][1] == "lsl" || datos[i+2][1] == "lsr" || datos[i+2][1] == "asr") {
                    if (datos[i+2][3] == datos[i][2] || datos[i+2][4] == datos[i][2]) {
                        cout << "Error de dependencia de datos en la linea " << i + 3 << endl;
                    }
                }else if(datos[i+2][1] == "cmp" || datos[i+2][1] == "not" || datos[i+2][1] == "mov"){ //cmp no tiene dependencia de datos?
                    if (datos[i+2][3] == datos[i][2]) {
                        cout << "Error de dependencia de datos en la linea " << i + 2 << endl;
                    }
                }else if(datos[i+2][1] == "ld" || datos[i+2][1] == "st"){
                    //falta
                }else if(datos[i+2][1] == "beq" || datos[i+2][1] == "bgt" || datos[i+2][1] == "b" || datos[i+2][1] == "call"){
                    //falta
                }
            }
            if (i+3 < datos.size()) {
                if (datos[i+3][1] == "add" || datos[i+3][1] == "sub" || datos[i+3][1] == "mul" || datos[i+3][1] == "div" || datos[i+3][1] == "mod" || datos[i+3][1] == "and" || datos[i+3][1] == "or" || datos[i+3][1] == "lsl" || datos[i+3][1] == "lsr" || datos[i+3][1] == "asr") {
                    if (datos[i+3][3] == datos[i][2] || datos[i+3][4] == datos[i][2]) {
                        cout << "Error de dependencia de datos en la linea " << i + 4 << endl;
                    }
                }else if(datos[i+3][1] == "cmp" || datos[i+3][1] == "not" || datos[i+3][1] == "mov"){ //cmp no tiene dependencia de datos?
                    if (datos[i+3][3] == datos[i][2]) {
                        cout << "Error de dependencia de datos en la linea " << i + 2 << endl;
                    }
                }else if(datos[i+3][1] == "ld" || datos[i+3][1] == "st"){
                    //falta
                }else if(datos[i+3][1] == "beq" || datos[i+3][1] == "bgt" || datos[i+3][1] == "b" || datos[i+3][1] == "call"){
                    //falta
                }
            }
        }else if (datos[i][1] == "nop" || datos[i][1] == "ret"){

        }else if (datos[i][1] == "ld" || datos[i][1] == "st"){

        }else if (datos[i][1] == "beq" || datos[i][1] == "bgt" || datos[i][1] == "b" || datos[i][1] == "call"){

        }else{
            cout<<"Error en el programa "<<endl;
            exit(1);
        }
    }
}


int main() {
    //verificadorDeSintaxis(separadorDeDatos(leerTxt("prueba.txt")));
    vector<vector<string>> pruebas = numerarProcesos(separadorDeDatos(leerTxt("prueba.txt")));
    pipeline(pruebas);
    cout << endl << endl;
    algoritmoDeConflictos(pruebas);
    cout << endl << endl;
    for (int i = 0; i < pruebas.size(); i++){
        for (int j = 0; j < pruebas[i].size(); ++j) {
            cout<<pruebas[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
