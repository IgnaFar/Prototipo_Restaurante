#include <iostream>
#include <cstdio>
#include <cstring>
#include <clocale>

using namespace std;

#include "fecha.h"
#include "ventaDetalle.h"
#include "ventaCabecera.h"
#include "persona.h"
#include "plato.h"
#include "funciones.h"

int main(){
    setlocale(LC_ALL, "Spanish");
    Empleado aux;
    Admin obj;
    int opc,pos,dni;
    char contrasenia[9];
    bool existeContra,existeEmpleado,existeAdmin;
    while(true){
        system("cls");
        pos=0;
        cout<<"******************************"<<endl;
        cout<<"*                            *"<<endl;
        cout<<"*       MENÚ PRINCIPAL       *"<<endl;
        cout<<"*                            *"<<endl;
        cout<<"******************************"<<endl<<endl;
        cout<<"------------------------------"<<endl;
        cout<<"1) MENÚ CLIENTES"<<endl;
        cout<<"2) MENÚ EMPLEADOS"<<endl;
        cout<<"3) MENÚ ADMIN"<<endl;
        cout<<"0) SALIR"<<endl;
        cout<<"------------------------------"<<endl;
        cout<<"OPCIÓN: -> ";
        cin>>opc;
        pos=0;
        switch(opc){
            case 1: menuCliente();
                break;
            case 2: system("cls");
                    cout<<"<<<LOGIN EMPLEADO>>>"<<endl;
                    cout<<"------------------------------"<<endl;
                    while(aux.leerDeDisco(pos)==1){
                        aux.MostrarEmpleado();
                        cout<<"------------------------------"<<endl;
                        pos++;
                    }
                    cout<<"------------------------------"<<endl<<endl;
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
            case 3: system("cls");
                    cout<<"<<<LOGIN ADMIN>>>"<<endl;
                    cout<<"------------------------------"<<endl;
                    while(obj.leerDeDisco(pos)==1){
                        obj.MostrarAdmin();
                        pos++;
                    }
                    cout<<"------------------------------"<<endl<<endl;
                    cout<<"DNI: ";
                    cin>>dni;
                    existeAdmin=buscarAdmin(dni);
                    if(existeAdmin==true){
                        cout<<"CONTRASEÑA: ";
                        cargarCadena(contrasenia,8);
                        existeContra=buscarAdminContra(contrasenia);
                        if(existeContra==true){
                            menuAdmin();
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
            case 0: system("cls");
                cout<<"HASTA LUEGO."<<endl;
                return 0;
                break;
            default: cout<<"OPCIÓN INCORRECTA."<<endl;
                    system("pause");
                break;
        }
    }
}

///MENU CLIENTES
void menuCliente(){
    Cliente reg;
    int opc,dni,pos;
    char contrasenia[9];
    bool existeCliente,existeContra;
    while(true){
        system("cls");
        pos=0;
        cout<<"*****************************"<<endl;
        cout<<"*                           *"<<endl;
        cout<<"*       MENÚ CLIENTES       *"<<endl;
        cout<<"*                           *"<<endl;
        cout<<"*****************************"<<endl<<endl;
        cout<<"------------------------------"<<endl;
        while(reg.leerDeDisco(pos)==1){
            reg.MostrarCliente();
            cout<<"------------------------------"<<endl;
            pos++;
        }
        cout<<endl;
        cout<<"------------------------------"<<endl;
        cout<<"1) REGISTRAR CLIENTE"<<endl;
        cout<<"2) CREAR PEDIDO"<<endl;
        cout<<"3) CANCELAR PEDIDO"<<endl;
        cout<<"4) MENÚ PEDIDOS"<<endl;
        cout<<"0) VOLVER"<<endl;
        cout<<"------------------------------"<<endl;
        cout<<"OPCIÓN: -> ";
        cin>>opc;
        pos=0;
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
                            system("pause");
                        }
                    }
                    else{
                        cout<<"EL DNI NO ES CORRECTO."<<endl;
                        system("pause");
                    }
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

///MENU EMPLEADOS
void menuEmpleados(int dni){
    Admin reg;
    Empleado aux;
    int opc,pos,dniAdmin;
    char contrasenia[9];
    bool existeAdmin,existeContra;
    while(true){
        system("cls");
        pos=0;
        cout<<"******************************"<<endl;
        cout<<"*                            *"<<endl;
        cout<<"*       MENÚ EMPLEADOS       *"<<endl;
        cout<<"*                            *"<<endl;
        cout<<"******************************"<<endl<<endl;
        cout<<"-------EMPLEADO LOGEADO-------"<<endl;
        while(aux.leerDeDisco(pos)){
            if(aux.getDNI()==dni){
                aux.MostrarEmpleadoLogeado();
                cout<<"------------------------------"<<endl;
            }
            pos++;
        }
        cout<<endl;
        cout<<"------------------------------"<<endl;
        cout<<"1) MENÚ PLATOS"<<endl;
        cout<<"2) MOSTRAR VENTAS"<<endl;
        cout<<"3) ATENDER CLIENTE"<<endl;
        cout<<"4) COBRAR VENTAS"<<endl;
        cout<<"5) MOSTRAR VENTAS COBRADAS"<<endl;
        cout<<"6) MOSTRAR VENTAS CANCELADAS"<<endl;
        cout<<"7) MOSTRAR CLIENTES REGISTRADOS"<<endl;
        cout<<"8) REPORTES"<<endl;
        cout<<"------------------------------"<<endl;
        cout<<"9) MENÚ ADMIN"<<endl;
        cout<<"------------------------------"<<endl;
        cout<<"0) VOLVER"<<endl;
        cout<<"------------------------------"<<endl;
        cout<<"OPCIÓN: -> ";
        cin>>opc;
        pos=0;
        switch(opc){
            case 1: menuPlatos();
                break;
            case 2: mostrarVentas();
                break;
            case 3: atenderCliente(dni);
                break;
            case 4: cobrarVentas(dni);
                break;
            case 5: mostrarVentasCobradas();
                break;
            case 6: mostrarVentasCanceladas();
                break;
            case 7: mostrarClientesRegistrados();
                break;
            case 8: reportes();
                break;
            case 9: system("cls");
                    cout<<"<<<LOGIN ADMIN>>>"<<endl;
                    cout<<"------------------------------"<<endl;
                    while(reg.leerDeDisco(pos)==1){
                        reg.MostrarAdmin();
                        pos++;
                    }
                    cout<<"------------------------------"<<endl<<endl;
                    cout<<"DNI: "<<endl;
                    cin>>dniAdmin;
                    existeAdmin=buscarAdmin(dniAdmin);
                    if(existeAdmin==true){
                        cout<<"CONTRASEÑA: "<<endl;
                        cargarCadena(contrasenia,8);
                        existeContra=buscarAdminContra(contrasenia);
                        if(existeContra==true){
                            menuAdmin();
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
            case 0: return;
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
    Cliente reg;
    Empleado aux;
    int opc,dniCliente,pos,dniEmpleado;
    bool existeCliente,existeEmpleado;
    while(true){
        system("cls");
        pos=0;
        cout<<"**************************"<<endl;
        cout<<"*      ACCESO ADMIN      *"<<endl;
        cout<<"**************************"<<endl<<endl;
        cout<<"------------------------------"<<endl;
        cout<<"1) MOSTRAR EMPLEADOS REGISTRADOS"<<endl;
        cout<<"2) REGISTRAR NUEVO EMPLEADO"<<endl;
        cout<<"3) MODIFICAR DATOS DEL CLIENTE"<<endl;
        cout<<"4) MODIFICAR DATOS DEL EMPLEADO"<<endl;
        cout<<"0) VOLVER"<<endl;
        cout<<"------------------------------"<<endl;
        cout<<"OPCIÓN: -> ";
        cin>>opc;
        switch(opc){
            case 1: mostrarEmpleadosRegistrados();
                break;
            case 2: crearEmpleado();
                break;
            case 3: system("cls");
                    cout<<"------------------------------"<<endl;
                    while(reg.leerDeDisco(pos)==1){
                        if(reg.getEstado()==true){
                            reg.MostrarCliente();
                            cout<<"------------------------------"<<endl;
                        }
                        pos++;
                    }
                    cout<<"DNI DEL CLIENTE: ";
                    cin>>dniCliente;
                    existeCliente=buscarCliente(dniCliente);
                    if(existeCliente==true){
                        modificarDatosCliente(dniCliente);
                    }
                    else{
                        cout<<"EL CLIENTE NO EXISTE O EL DNI NO ES CORRECTO."<<endl;
                        system("pause");
                    }
                break;
            case 4: system("cls");
                    cout<<"------------------------------"<<endl;
                    while(aux.leerDeDisco(pos)==1){
                        if(aux.getEstado()==true){
                            aux.MostrarEmpleado();
                            cout<<"------------------------------"<<endl;
                        }
                        pos++;
                    }
                    cout<<"DNI DEL EMPLEADO: ";
                    cin>>dniEmpleado;
                    existeEmpleado=buscarEmpleado(dniEmpleado);
                    if(existeEmpleado==true){
                        modificarDatosEmpleado(dniEmpleado);
                    }
                    else{
                        cout<<"EL EMPLEADO NO EXISTE O EL DNI NO ES CORRECTO."<<endl;
                        system("pause");
                    }
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
        cout<<"*******************************"<<endl;
        cout<<"*                             *"<<endl;
        cout<<"*         MENÚ PLATOS         *"<<endl;
        cout<<"*                             *"<<endl;
        cout<<"*******************************"<<endl<<endl;
        cout<<"------------------------------"<<endl;
        cout<<"1) AGREGAR PLATO"<<endl;
        cout<<"2) MOSTRAR PLATO POR CODIGO"<<endl;
        cout<<"3) MOSTRAR TODOS LOS PLATOS"<<endl;
        cout<<"4) AGREGAR STOCK"<<endl;
        cout<<"5) MODIFICAR NOMBRE DEL PLATO"<<endl;
        cout<<"6) MODIFICAR DESCRIPCIÓN DEL PLATO"<<endl;
        cout<<"7) MODIFCAR PRECIO DEL PLATO"<<endl;
        cout<<"8) MODIFICAR STOCK"<<endl;
        cout<<"9) ELIMINAR PLATO"<<endl;
        cout<<"10) RESTABLECER PLATO"<<endl;
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
            case 4: agregarStock();
                break;
            case 5: modificarNombre();
                break;
            case 6: modificarDescripcion();
                break;
            case 7: modificarPrecio();
                break;
            case 8: modificarStock();
                break;
            case 9: eliminarPlato();
                break;
            case 10: restablecerPlato();
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
