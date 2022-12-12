#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <bitset>
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

void imprimirDatos(vector<vector<string>> datos){
    cout << endl;
    for (int i = 0; i < datos.size(); i++){
        for (int j = 0; j < datos[i].size(); j++){
            cout << datos[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void verificarSintaxis(vector<vector<string>> datos){
    for (int i = 0; i < datos.size(); i++){
        if (datos[i][0] == "add" || datos[i][0] == "sub" || datos[i][0] == "mul" || datos[i][0] == "div" || datos[i][0] == "mod" || datos[i][0] == "and" || datos[i][0] == "or" || datos[i][0] == "lsl" || datos[i][0] == "lsr" || datos[i][0] == "asr"){
            if (datos[i].size() == 4){

            }else{
                cout<<"Error de sintaxis en la linea "<<i+1<<endl;
            }
        }else if (datos[i][0] == "cmp" || datos[i][0] == "not" || datos[i][0] == "mov"){
            if (datos[i].size() == 3){

            }else{
                cout<<"Error de sintaxis en la linea "<<i+1<<endl;
            }
        }else if (datos[i][0] == "nop" || datos[i][0] == "ret"){
            if (datos[i].size() == 1){

            }else{
                cout<<"Error de sintaxis en la linea "<<i+1<<endl;
            }
        }else if (datos[i][0] == "ld" || datos[i][0] == "st"){
            if (datos[i].size() == 3){

            }else{
                cout<<"Error de sintaxis en la linea "<<i+1<<endl;
            }
        }else if (datos[i][0] == "beq" || datos[i][0] == "bgt" || datos[i][0] == "b" || datos[i][0] == "call"){
            if (datos[i].size() == 2){

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

bool algoritmoDeConflictos(vector<vector<string>> data, int ins1, int ins2){
    string src1, src2, dest;
    bool hasSrc1 = false, hasSrc2 = false;
    if (data[ins1-1][0] == "nop" || data[ins1-1][0] == "b" || data[ins1-1][0] == "beq" || data[ins1-1][0] == "bgt" || data[ins1-1][0] == "call") {
        return false;
    }
    if (data[ins2-1][0] == "nop" || data[ins2-1][0] == "b" || data[ins2-1][0] == "beq" || data[ins2-1][0] == "bgt" || data[ins2-1][0] == "cmp" || data[ins2-1][0] == "st") {
        return false;
    }
    src1 = data[ins1-1][2], src2 = data[ins1-1][3];
    if(data[ins2-1][0] == "ret") {
        hasSrc1 = true;
    }
    if (data[ins1-1][0] == "not" || data[ins1-1][0] == "mov") {
       hasSrc1 = false;
    }
    dest = data[ins2-1][1];
    hasSrc2 = true;
    if(data[ins1-1][0] != "st"){
        hasSrc2 = false;
    }
    if(hasSrc1 == false && src1 == dest){
        return true;
    }else if(hasSrc2 == false && src2 == dest) {
        return true;
    }
    return false;
}

vector<vector<string>> reordenarCodigo(vector<vector<string>> data){
    int iterator = data.size(), j = 0;
    while(iterator > 0) {
        if (j + 1 > data.size() - 1) {
            j++;
        }else if(j + 2 > data.size() - 1){
            if(algoritmoDeConflictos(data, j+2, j+1) && data.size()>3) {
                vector<string> temp = data[j];
                data[j] = data[j-1];
                data[j-1] = data[j-2];
                data[j-2] = temp;
                j = 0;
            }else if(algoritmoDeConflictos(data, j+2, j+1)){
                data.insert(data.begin()+j+1, {"nop"});
                data.insert(data.begin()+j+2, {"nop"});
                j = 0;
            }else{
                j++;
            }
        }else{
            if(algoritmoDeConflictos(data, j+3, j+1)) {
                if(j+4 > data.size()-1){
                    data.insert(data.begin()+j+1, {"nop"});
                    j = 0;
                }else {
                    vector<string> temp = data[j + 2];
                    data[j + 2] = data[j + 3];
                    data[j + 3] = data[j + 4];
                    data[j + 4] = temp;
                    j = 0;
                }
            }else if(algoritmoDeConflictos(data, j+2, j+1)) {
                vector<string> temp = data[j+1];
                data[j+1] = data[j+2];
                data[j+2] = data[j+3];
                data[j+3] = temp;
                j = 0;
            }else{
                j++;
            }
        }
        if(j == data.size()){
            iterator = 0;
        }
    }
    return data;
}

vector<string> recopilaRegistros(string nombreArchivo){
    vector<vector<string>> data = separadorDeDatos(leerTxt(nombreArchivo));
    vector<string> registros;
    for (int i = 0; i < data.size(); i++){
        if(data[i][0] == "add" || data[i][0] == "sub" || data[i][0] == "mul" || data[i][0] == "div" || data[i][0] == "mod" || data[i][0] == "and" || data[i][0] == "or" || data[i][0] == "lsl" || data[i][0] == "lsr" || data[i][0] == "asr" || data[i][0] == "not" || data[i][0] == "mov" || data[i][0] == "ld" || data[i][0] == "st"){
            for (int j = 1; j < data[i].size(); ++j) {
                registros.push_back(data[i][j]);
            }
        }
    }
    return registros;
}

vector<vector<string>> delaySlots(vector<vector<string>> data){
    vector<vector<string>> dataFinal;
    for (int i = 0; i < data.size(); i++){
        if (data[i][0] == "b" || data[i][0] == "beq" || data[i][0] == "bgt" || data[i][0] == "call"){
            vector<string> registros = recopilaRegistros(data[i][1]);
            if(data[i+1][0] == "add" || data[i+1][0] == "sub" || data[i+1][0] == "mul" || data[i+1][0] == "div" || data[i+1][0] == "mod" || data[i+1][0] == "and" || data[i+1][0] == "or" || data[i+1][0] == "lsl" || data[i+1][0] == "lsr" || data[i+1][0] == "asr" || data[i+1][0] == "not" || data[i+1][0] == "mov" || data[i+1][0] == "ld" || data[i+1][0] == "st" || data[i+1][0] == "cmp"){
                for (int j = 1; j < data[i+1].size(); ++j) {
                    if(find(registros.begin(), registros.end(), data[i+1][j]) != registros.end()){
                        dataFinal.push_back(data[i]);
                        dataFinal.push_back({"nop"});
                        dataFinal.push_back({"nop"});
                        break;
                    }else{
                        dataFinal.push_back(data[i]);
                        dataFinal.push_back(data[i+1]);
                        dataFinal.push_back({"nop"});
                        i++;
                        break;
                    }
                }
            }else if(data[i+2][0] == "add" || data[i+2][0] == "sub" || data[i+2][0] == "mul" || data[i+2][0] == "div" || data[i+2][0] == "mod" || data[i+2][0] == "and" || data[i+2][0] == "or" || data[i+2][0] == "lsl" || data[i+2][0] == "lsr" || data[i+2][0] == "asr" || data[i+2][0] == "not" || data[i+2][0] == "mov" || data[i+2][0] == "ld" || data[i+2][0] == "st" || data[i+2][0] == "cmp"){
                for (int j = 1; j < data[i+2].size(); ++j) {
                    if(find(registros.begin(), registros.end(), data[i+2][j]) != registros.end()){
                        dataFinal.push_back(data[i]);
                        dataFinal.push_back({"nop"});
                        break;
                    }else{
                        dataFinal.push_back(data[i]);
                        dataFinal.push_back(data[i+1]);
                        dataFinal.push_back(data[i+2]);
                        i+=2;
                        break;
                    }
                }
            }
        }else{
            dataFinal.push_back(data[i]);
        }
    }
    return dataFinal;
}

string traductor(string dato){
    if(dato == "add") {
        return "00000";
    }else if(dato == "sub") {
        return "00001";
    }else if(dato == "mul") {
        return "00010";
    }else if(dato == "div") {
        return "00011";
    }else if(dato == "mod") {
        return "00100";
    }else if(dato == "cmp"){
        return "00101";
    }else if(dato == "and"){
        return "00110";
    }else if(dato == "or"){
        return "00111";
    }else if(dato == "not"){
        return "01000";
    }else if(dato == "mov"){
        return "01001";
    }else if(dato == "lsl"){
        return "01010";
    }else if(dato == "lsr"){
        return "01011";
    }else if(dato == "asr"){
        return "01100";
    }else if(dato == "nop"){
        return "01101";
    }else if(dato == "ld"){
        return "01110";
    }else if(dato == "st"){
        return "01111";
    }else if(dato == "beq"){
        return "10000";
    }else if(dato == "bgt"){
        return "10001";
    }else if(dato == "b"){
        return "10010";
    }else if(dato == "call"){
        return "10011";
    }else if(dato == "ret"){
        return "10100";
    }else if(dato[0] == 'r') {
        dato.erase(0, 1);
        int numero = stoi(dato);
        return bitset<4>(numero).to_string();
    }else if(dato[0] == '0' || dato[0] == '1' || dato[0] == '2' || dato[0] == '3' || dato[0] == '4' || dato[0] == '5' || dato[0] == '6' || dato[0] == '7' || dato[0] == '8' || dato[0] == '9') {
        return "1";
    }else{
        return "";
    }
}

vector<string> toBinary(vector<vector<string>> data){
    string temp;
    vector<string> dataFinal;
    for(int i = 0; i< data.size(); ++i){
        if( data[i][0] == "add" || data[i][0] == "sub" || data[i][0] == "mul" || data[i][0] == "div" || data[i][0] == "mod" || data[i][0] == "and" || data[i][0] == "or" || data[i][0] == "lsl" || data[i][0] == "lsr" || data[i][0] == "asr") {
            temp.append(traductor(data[i][0]));
            if (traductor(data[i][2]) == "1" || traductor(data[i][3]) == "1") {
                temp.append("1");
            } else {
                temp.append("0");
            }
            temp.append(traductor(data[i][1]));
            temp.append(traductor(data[i][2]));
            if (traductor(data[i][3]) == "1") {
                temp.append(bitset<18>(stoi(data[i][3])).to_string());
            } else {
                temp.append(traductor(data[i][3]));
                temp.append("00000000000000");
            }
            dataFinal.push_back(temp);
            temp.clear();
        }else if (data[i][0] == "mov" || data[i][0] == "ld" || data[i][0] == "st" || data[i][0] == "cmp" || data[i][0] == "not") {
            temp.append(traductor(data[i][0]));
            if (traductor(data[i][2]) == "1") {
                temp.append("1");
            } else {
                temp.append("0");
            }
            temp.append(traductor(data[i][1]));
            if (traductor(data[i][2]) == "1") {
                temp.append(bitset<18>(stoi(data[i][2])).to_string());
            } else {
                temp.append(traductor(data[i][2]));
                temp.append("00000000000000");
            }
            dataFinal.push_back(temp);
            temp.clear();
        }else if(data[i][0] == "beq" || data[i][0] == "bgt" || data[i][0] == "b" || data[i][0] == "call") {
            temp.append(traductor(data[i][0]));
            temp.append("101010101010101010101010101");
            dataFinal.push_back(temp);
            temp.clear();
        }else if(data[i][0] == "ret" || data[i][0] == "nop") {
            temp.append(traductor(data[i][0]));
            temp.append("000000000000000000000000000");
            dataFinal.push_back(temp);
            temp.clear();
        }
    }
    return dataFinal;
}

int main() {
    vector<vector<string>> instrucciones;
    instrucciones = separadorDeDatos(leerTxt("prueba.txt"));
    verificarSintaxis(instrucciones);
    cout << "instrucciones" << endl;
    imprimirDatos(instrucciones);

    cout << endl << "reordenamiento" << endl;
    instrucciones = reordenarCodigo(instrucciones);
    imprimirDatos(instrucciones);

    cout << endl << "Delay Slots" << endl;
    instrucciones = delaySlots(instrucciones);
    imprimirDatos(instrucciones);

    cout << endl << "traduccion" << endl;
    vector<string> instruccionesBinarias = toBinary(instrucciones);
    for (int i = 0; i < instruccionesBinarias.size(); ++i) {
        cout << instruccionesBinarias[i] << endl;
    }

    return 0;
}                                                                                                                                                                                                                                                                                                                                                    