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
    int opc,dni;
    char contrasenia[9];
    bool existeCliente,existeContra,existeEmpleado,existeAdmin,esTipo1;
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
        cout<<"4) MENÚ PEDIDOS"<<endl;
        cout<<"0) VOLVER"<<endl;
        cout<<"------------------------------"<<endl;
        cout<<"OPCIÓN: -> ";
        cin>>opc;
        switch(opc){
            case 1: registrarCliente();
                break;
            case 2: cout<<endl;
                    cout<<"DNI DEL CLIENTE: ";
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
            case 3: cout<<endl;
                    cout<<"DNI DEL CLIENTE: ";
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
            case 4: cout<<endl;
                    cout<<"DNI DEL CLIENTE: ";
                    cin>>dni;
                    existeCliente=buscarCliente(dni);
                    if(existeCliente==true){
                        cout<<"CONTRASEÑA: ";
                        cargarCadena(contrasenia,8);
                        existeContra=buscarClienteContra(contrasenia);
                        if(existeContra==true){
                            menuVentasCliente(dni);
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
            case 0: system("cls");
                cout<<"HASTA LUEGO."<<endl;
                return 0;
                break;
            case -8: system("cls");
                    cout<<"<<<LOGIN ADMIN>>>"<<endl;
                    cout<<"DNI: ";
                    cin>>dni;
                    existeAdmin=buscarAdmin(dni);
                    if(existeAdmin==true){
                        cout<<"CONTRASEÑA: ";
                        cargarCadena(contrasenia,8);
                        existeContra=buscarAdminContra(contrasenia);
                        if(existeContra==true){
                            esTipo1=buscarTipo(dni,contrasenia);
                            if(esTipo1==true){
                                menuAdmin();
                            }
                        }
                        else{
                            cout<<"LA CONTRASEÑA NO EXISTE"<<endl;
                            system("pause");
                        }
                    }
                    else{
                        cout<<"EL DNI NO EXISTE"<<endl;
                        system("pause");
                    }
                break;
            case -9: system("cls");
                    cout<<"<<<LOGIN EMPLEADO>>>"<<endl;
                    cout<<"DNI DEL EMPLEADO: ";
                    cin>>dni;
                    existeEmpleado=buscarEmpleado(dni);
                    if(existeEmpleado==true){
                        cout<<"CONTRASEÑA: ";
                        cargarCadena(contrasenia,8);
                        existeContra=buscarEmpleadoContra(contrasenia);
                        if(existeContra==true){
                            menuEmpleados(dni);
                        }
                        else{
                            cout<<"LA CONTRASEÑA NO ES CORRECTA."<<endl;
                            system("pause");
                        }
                    }
                    else{
                        cout<<"EL DNI NO ES CORRECTO."<<endl;
                        system("pause");
                    }
                break;
            default: cout<<"OPCIÓN INCORRECTA."<<endl;
                    system("pause");
                break;
        }
    }
}

///MENU EMPLEADOS
void menuEmpleados(int dni){
    int opc,dniAdmin;
    char contrasenia[9];
    bool existeAdmin,existeContra,esTipo1;
    while(true){
        system("cls");
        cout<<"******************************"<<endl;
        cout<<"*                            *"<<endl;
        cout<<"*       MENÚ EMPLEADOS       *"<<endl;
        cout<<"*                            *"<<endl;
        cout<<"******************************"<<endl<<endl;
        cout<<"------------------------------"<<endl;
        cout<<"1) MENÚ PLATOS"<<endl;
        cout<<"2) MOSTRAR VENTAS"<<endl;
        cout<<"3) ATENDER CLIENTE"<<endl;
        cout<<"4) MOSTRAR CLIENTES REGISTRADOS"<<endl;
        cout<<"0) VOLVER"<<endl;
        cout<<"------------------------------"<<endl;
        cout<<"OPCIÓN: -> ";
        cin>>opc;
        switch(opc){
            case 1: menuPlatos();
                break;
            case 2: mostrarVentas();
                break;
            case 3: atenderCliente(dni);
                break;
            case 4: mostrarClientesRegistrados();
                break;
            case 0: return;
                break;
            case -9: system("cls");
                    cout<<"<<<LOGIN ADMIN>>>"<<endl;
                    cout<<"DNI: "<<endl;
                    cin>>dniAdmin;
                    existeAdmin=buscarAdmin(dniAdmin);
                    if(existeAdmin==true){
                        cout<<"CONTRASEÑA: "<<endl;
                        cargarCadena(contrasenia,8);
                        existeContra=buscarAdminContra(contrasenia);
                        if(existeContra==true){
                            esTipo1=buscarTipo(dniAdmin,contrasenia);
                            if(esTipo1==true){
                                menuAdmin();
                            }
                        }
                        else{
                            cout<<"LA CONTRASEÑA NO EXISTE"<<endl;
                            system("pause");
                        }
                    }
                    else{
                        cout<<"EL DNI NO EXISTE"<<endl;
                        system("pause");
                    }
                break;
            default: cout<<"OPCION INCORRECTA"<<endl;
                    system("pause");
                break;
        }
    }
}
///


///MENU ADMIN
void menuAdmin(){
    int opc;
    while(true){
        system("cls");
        cout<<"**************************"<<endl;
        cout<<"*      ACCESO ADMIN      *"<<endl;
        cout<<"**************************"<<endl<<endl;
        cout<<"------------------------------"<<endl;
        cout<<"1) MOSTRAR EMPLEADOS REGISTRADOS"<<endl;
        cout<<"2) REGISTRAR NUEVO EMPLEADO"<<endl;
        cout<<"3) VOLVER"<<endl;
        cout<<"------------------------------"<<endl;
        cout<<"OPCIÓN: -> "<<endl;
        cin>>opc;
        switch(opc){
            case 1: mostrarEmpleadosRegistrados();
                break;
            case 2: crearEmpleado();
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
        cout<<"OPCIÓN: -> ";
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
