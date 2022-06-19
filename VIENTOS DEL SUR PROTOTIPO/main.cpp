#include <iostream>
#include <cstdio>
#include <cstring>
#include <clocale>

using namespace std;

#include "fecha.h"
#include "venta.h"
#include "persona.h"
#include "plato.h"
#include "funciones.h"

int main(){
    setlocale(LC_ALL, "Spanish");
    int opc,dniEmp;
    char contrasenia[9];
    bool existeEmpleado,existeContrasenia;
    while(true){
        system("cls");
        cout<<"--------MENÚ PRINCIPAL--------"<<endl;
        cout<<"1) MENÚ PLATOS"<<endl;
        cout<<"2) MENÚ EMPLEADO"<<endl;
        cout<<"3) MENÚ CLIENTE"<<endl;
        cout<<"4) MENÚ VENTAS/PEDIDOS"<<endl;
        cout<<"0) SALIR"<<endl;
        cout<<"------------------------------"<<endl;
        cout<<"OPCION: -> ";
        cin>>opc;
        switch(opc){
            case 1: system("cls");
                    cout<<"--------MENÚ PLATOS--------"<<endl;
                    cout<<"<<<LOGIN EMPLEADO>>>"<<endl;
                    cout<<"DNI DEL EMPLEADO: ";
                    cin>>dniEmp;
                    existeEmpleado=buscarEmpleado(dniEmp);
                    if(existeEmpleado==true){
                        cout<<"CONTRASEÑA: ";
                        cargarCadena(contrasenia,8);
                        existeContrasenia=buscarEmpleadoContra(contrasenia);
                        if(existeContrasenia==true){
                            menuPlatos();
                        }
                        else{
                            cout<<"LA CONTRASEÑA NO ES CORRECTA"<<endl;
                            system("pause");
                        }
                    }
                    else{
                        cout<<"EL DNI NO EXISTE"<<endl;
                        system("pause");
                    }
                break;
            case 2: system("cls");
                    cout<<"--------MENÚ EMPLEADOS--------"<<endl;
                    cout<<"<<<LOGIN EMPLEADO>>>"<<endl;
                    cout<<"DNI DEL EMPLEADO: ";
                    cin>>dniEmp;
                    existeEmpleado=buscarEmpleado(dniEmp);
                    if(existeEmpleado==true){
                        cout<<"CONTRASEÑA: ";
                        cargarCadena(contrasenia,8);
                        existeContrasenia=buscarEmpleadoContra(contrasenia);
                        if(existeContrasenia==true){
                            menuEmpleados();
                        }
                        else{
                            cout<<"LA CONTRASEÑA NO ES CORRECTA"<<endl;
                            system("pause");
                        }
                    }
                    else{
                        cout<<"EL DNI NO EXISTE"<<endl;
                        system("pause");
                    }
                break;
            case 3: menuCliente();
                break;
            case 4: menuVentasPedidos();
                break;
            case 0: system("cls");
                cout<<"HASTA LUEGO."<<endl;
                return 0;
                break;
            case -9: crearEmpleado();
                break;
            default: cout<<endl;
                cout<<"OPCIÓN INCORRECTA"<<endl;
                system("pause");
                break;
        }
    }
}

///MENU PLATOS
void menuPlatos(){
    int opc;
    while(true){
        system("cls");
        cout<<"--------MENÚ PLATOS--------"<<endl;
        cout<<"1) AGREGAR PLATO"<<endl;
        cout<<"2) MOSTRAR PLATO POR CODIGO"<<endl;
        cout<<"3) MOSTRAR TODOS LOS PLATOS"<<endl;
        cout<<"4) ELIMINAR PLATO"<<endl;
        cout<<"5) RESTABLECER PLATO"<<endl;
        cout<<"0) VOLVER"<<endl;
        cout<<"------------------------------"<<endl;
        cout<<"OPCION: -> ";
        cin>>opc;
        switch(opc){
            case 1: agregarPlato();
                break;
            case 2: mostrarPorCodigo();
                break;
            case 3: mostrarPlatos();
                break;
            case 4: eliminarPlato();
                break;
            case 5: restablecerPlato();
                break;
            case 0: return;
                break;
            default: cout<<"OPCION INCORRECTA"<<endl;
                system("pause");
                break;
        }
    }
}
///


///MENU EMPLEADOS
void menuEmpleados(){
    int opc;
    while(true){
        system("cls");
        cout<<"--------MENÚ EMPLEADOS--------"<<endl;
        cout<<"1) MOSTRAR EMPLEADOS REGISTRADOS"<<endl;
        cout<<"2) MOSTRAR CLIENTES REGISTRADOS"<<endl;
        cout<<"0) VOLVER"<<endl;
        cout<<"------------------------------"<<endl;
        cout<<"OPCION: -> ";
        cin>>opc;
        switch(opc){
            case 1: mostrarEmpleados();
                break;
            case 2: mostrarClientesRegistrados();
                break;
            case 0: return;
                break;
            default: cout<<"OPCION INCORRECTA"<<endl;
                system("pause");
                break;
        }
    }
}
///


///MENU CLIENTES
void menuCliente(){
    int opc,dni;
    char contrasenia[9];
    bool existeCliente,existeContra;
    while(true){
        system("cls");
        cout<<"*****************************"<<endl;
        cout<<"*                           *"<<endl;
        cout<<"*       MENÚ CLIENTES       *"<<endl;
        cout<<"*                           *"<<endl;
        cout<<"*****************************"<<endl<<endl;
        cout<<"------------------------------"<<endl;
        cout<<"1) REGISTRAR CLIENTE"<<endl;
        cout<<"2) CREAR PEDIDO"<<endl;
        cout<<"3) CANCELAR PEDIDO"<<endl;
        cout<<"0) VOLVER"<<endl;
        cout<<"------------------------------"<<endl;
        cout<<"OPCIÓN: -> ";
        cin>>opc;
        switch(opc){
            case 1: registrarCliente();
                break;
            case 2: cout<<"DNI DEL CLIENTE: ";
                    cin>>dni;
                    existeCliente=buscarCliente(dni);
                    if(existeCliente==true){
                        cout<<"CONTRASEÑA: ";
                        cargarCadena(contrasenia,8);
                        existeContra=buscarClienteContra(contrasenia);
                        if(existeContra==true){
                            crearPedido(dni);
                        }
                        else{
                            cout<<"LA CONTRASEÑA NO ES CORRECTA."<<endl;
                        }
                    }
                    else{
                        cout<<"EL DNI NO ES CORRECTO."<<endl;
                    }
                    system("pause");
                break;
            case 3: cout<<"DNI DEL CLIENTE: ";
                    cin>>dni;
                    existeCliente=buscarCliente(dni);
                    if(existeCliente==true){
                        cout<<"CONTRASEÑA: ";
                        cargarCadena(contrasenia,8);
                        existeContra=buscarClienteContra(contrasenia);
                        if(existeContra==true){
                            cancelarPedido(dni);
                        }
                        else{
                            cout<<"LA CONTRASEÑA NO ES CORRECTA."<<endl;
                        }
                    }
                    else{
                        cout<<"EL DNI NO ES CORRECTO."<<endl;
                    }
                    system("pause");
                break;
            case 0: return;
                break;
            default: cout<<"OPCIÓN INCORRECTA."<<endl;
                    system("pause");
                break;
        }
    }
}
///


///MENU VENTAS
void menuVentasPedidos(){
    int opc=-1,dni;
    char contrasenia[9];
    bool existeCliente,existeContrasenia,existeEmpleado;
    while(opc!=0){
        opc=-1;
        system("cls");
        cout<<"*****************************"<<endl;
        cout<<"*                           *"<<endl;
        cout<<"*    MENÚ VENTAS/PEDIDOS    *"<<endl;
        cout<<"*                           *"<<endl;
        cout<<"*****************************"<<endl;
        cout<<"*VOLVER(0)*"<<endl;
        cout<<"***********"<<endl;
        /*
        cout<<"*CLIENTE(1) O EMPLEADO(2)*"<<endl;
        cout<<"**************************"<<endl;
        cout<<"*VOLVER(0)*"<<endl;
        cout<<"***********"<<endl;
        cout<<"OPCIÓN: -> ";
        */
        cout<<"<<<LOGIN>>>"<<endl;
        cout<<"INGRESE DNI: ";
        cin>>dni;
        if(dni==0){
            return;
        }
        existeCliente=buscarCliente(dni);
        if(existeCliente==true){
            cout<<"CONTRASEÑA: ";
            cargarCadena(contrasenia,8);
            existeContrasenia=buscarClienteContra(contrasenia);
            if(existeContrasenia==true){
                opc=1;
            }
        }
        else{
            existeEmpleado=buscarEmpleado(dni);
            if(existeEmpleado==true){
                cout<<"CONTRASEÑA: ";
                cargarCadena(contrasenia,8);
                existeContrasenia=buscarEmpleadoContra(contrasenia);
                if(existeContrasenia==true){
                    opc=2;
                }
            }
        }
        switch(opc){
            case 1: menuVentasCliente(dni);
                    /*
                    cout<<"<<<LOGIN CLIENTE>>>"<<endl;
                    cout<<"DNI DEL CLIENTE: ";
                    cin>>dni;
                    existeCliente=buscarCliente(dni);
                    if(existeCliente==true){
                        cout<<"CONTRASEÑA: ";
                        cargarCadena(contrasenia,8);
                        existeContrasenia=buscarClienteContra(contrasenia);
                        if(existeContrasenia==true){

                        }
                        else{
                            cout<<"LA CONTRASEÑA NO EXISTE O NO ES CORRECTA."<<endl;
                            system("pause");
                        }
                    }
                    else{
                        cout<<"EL DNI NO EXISTE O NO ES CORRECTO."<<endl;
                        system("pause");
                    }
                    */
                break;
            case 2: menuVentasEmpleado(dni);
                    /*
                    cout<<"DNI DEL EMPLEADO: ";
                    cin>>dni;
                    existeEmpleado=buscarEmpleado(dni);
                    if(existeEmpleado==true){
                        cout<<"CONTRASEÑA: ";
                        cargarCadena(contrasenia,8);
                        existeContrasenia=buscarEmpleadoContra(contrasenia);
                        if(existeContrasenia==true){

                        }
                        else{
                            cout<<"LA CONTRASEÑA NO EXISTE O NO ES CORRECTA."<<endl;
                            system("pause");
                        }
                    }
                    else{
                        cout<<"EL DNI NO EXISTE O NO ES CORRECTO."<<endl;
                        system("pause");
                    }
                    */
                break;
            case 0: return;
                break;
            default: cout<<endl;
                    cout<<"EL DNI O CONTRASEÑIA NO SON CORRECTOS."<<endl;
                    system("pause");
                break;
        }
    }
}
///
