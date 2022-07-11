#include <iostream>
#include <cstdio>
#include <cstring>
#include <clocale>

using namespace std;

#include "fecha.h"
#include "ventaDetalle.h"
#include "ventaCabecera.h"
#include "usuario.h"
#include "plato.h"
#include "funciones.h"

int main(){
    setlocale(LC_ALL, "Spanish");
    int opc,dni,registrar,acceso;
    char contrasenia[9];
    bool existeContra,existeEmpleado,existeAdmin,existeCliente;
    while(true){
        system("cls");
        cout<<"******************************"<<endl;
        cout<<"*                            *"<<endl;
        cout<<"*       MEN� PRINCIPAL       *"<<endl;
        cout<<"*                            *"<<endl;
        cout<<"******************************"<<endl<<endl;
        cout<<"------------------------------"<<endl;
        cout<<"1) MEN� CLIENTES"<<endl;
        cout<<"2) MEN� EMPLEADOS"<<endl;
        cout<<"3) MEN� ADMIN"<<endl;
        cout<<"0) SALIR"<<endl;
        cout<<"------------------------------"<<endl;
        cout<<"OPCI�N: -> ";
        cin>>opc;
        switch(opc){
            case 1: system("cls");
                    cout<<"�YA EST� REGISTRADO? SI(1)/NO(0)"<<endl;
                    cin>>acceso;
                    if(acceso==1){
                        system("cls");
                        cout<<"<<<LOGIN CLIENTE>>>"<<endl;
                        cout<<"DNI DEL CLIENTE: ";
                        cin>>dni;
                        if(dni!=0){
                            existeCliente=buscarCliente(dni);
                            if(existeCliente==true){
                                cout<<"CONTRASE�A: ";
                                cargarCadena(contrasenia,8);
                                existeContra=buscarClienteContra(contrasenia);
                                if(existeContra==true){
                                    menuCliente(dni);
                                }
                                else{
                                    cout<<"LA CONTRASE�A NO ES CORRECTA."<<endl;
                                    system("pause");
                                }
                            }
                            else{
                                cout<<"EL DNI NO SE ENCUENTRA REGISTRADO."<<endl;
                                system("pause");
                            }
                        }
                    }
                    else{
                        system("cls");
                        cout<<"�DESEA REGISTRARLO? SI(1)/NO(0)"<<endl;
                        cin>>registrar;
                        if(registrar==1){
                            registrarCliente();
                        }
                    }
                break;
            case 2: system("cls");
                    cout<<"<<<LOGIN EMPLEADO>>>"<<endl;
                    cout<<"DNI DEL EMPLEADO: ";
                    cin>>dni;
                    existeEmpleado=buscarEmpleado(dni);
                    if(existeEmpleado==true){
                        cout<<"CONTRASE�A: ";
                        cargarCadena(contrasenia,8);
                        existeContra=buscarEmpleadoContra(contrasenia);
                        if(existeContra==true){
                            menuEmpleados(dni);
                        }
                        else{
                            cout<<"LA CONTRASE�A NO ES CORRECTA."<<endl;
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
                    cout<<"DNI: ";
                    cin>>dni;
                    existeAdmin=buscarAdmin(dni);
                    if(existeAdmin==true){
                        cout<<"CONTRASE�A: ";
                        cargarCadena(contrasenia,8);
                        existeContra=buscarAdminContra(contrasenia);
                        if(existeContra==true){
                            menuAdmin(dni);
                        }
                        else{
                            cout<<"LA CONTRASE�A NO EXISTE"<<endl;
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
            default: cout<<"OPCI�N INCORRECTA."<<endl;
                    system("pause");
                break;
        }
    }
}

///MENU CLIENTES
void menuCliente(int dniCliente){
    Usuario reg;
    int opc,pos;
    while(true){
        system("cls");
        pos=0;
        cout<<"*****************************"<<endl;
        cout<<"*                           *"<<endl;
        cout<<"*       MEN� CLIENTES       *"<<endl;
        cout<<"*                           *"<<endl;
        cout<<"*****************************"<<endl<<endl;
        cout<<"-------CLIENTE LOGEADO-------"<<endl;
        while(reg.leerDeDisco(pos)){
            if(reg.getDNI()==dniCliente && reg.getTipo()==3){
                reg.MostrarLogeado();
                cout<<"------------------------------"<<endl;
            }
            pos++;
        }
        cout<<"------------------------------"<<endl;
        cout<<"1) CREAR PEDIDO"<<endl;
        cout<<"2) CANCELAR PEDIDO"<<endl;
        cout<<"3) MEN� PEDIDOS"<<endl;
        cout<<"0) VOLVER"<<endl;
        cout<<"------------------------------"<<endl;
        cout<<"OPCI�N: -> ";
        cin>>opc;
        switch(opc){
            case 1: crearPedido(dniCliente);
                break;
            case 2: cancelarPedido(dniCliente);
                break;
            case 3: menuVentasCliente(dniCliente);
                break;
            case 0: return;
                break;
            default: cout<<"OPCI�N INCORRECTA."<<endl;
                    system("pause");
                break;
        }
    }
}
///

///MENU EMPLEADOS
void menuEmpleados(int dniEmpleado){
    Usuario reg;
    int opc,pos,dniAdmin;
    char contrasenia[9];
    bool existeAdmin,existeContra;
    while(true){
        system("cls");
        pos=0;
        cout<<"******************************"<<endl;
        cout<<"*                            *"<<endl;
        cout<<"*       MEN� EMPLEADOS       *"<<endl;
        cout<<"*                            *"<<endl;
        cout<<"******************************"<<endl<<endl;
        cout<<"-------EMPLEADO LOGEADO-------"<<endl;
        while(reg.leerDeDisco(pos)){
            if(reg.getDNI()==dniEmpleado && reg.getTipo()==2){
                reg.MostrarLogeado();
                cout<<"------------------------------"<<endl;
            }
            pos++;
        }
        cout<<endl;
        cout<<"------------------------------"<<endl;
        cout<<"1) MEN� PLATOS"<<endl;
        cout<<"2) MOSTRAR VENTAS"<<endl;
        cout<<"3) ATENDER CLIENTE"<<endl;
        cout<<"4) COBRAR VENTAS"<<endl;
        cout<<"5) MOSTRAR VENTAS COBRADAS"<<endl;
        cout<<"6) MOSTRAR VENTAS CANCELADAS"<<endl;
        cout<<"7) MOSTRAR CLIENTES REGISTRADOS"<<endl;
        cout<<"8) REPORTES"<<endl;
        cout<<"------------------------------"<<endl;
        cout<<"9) MEN� ADMIN"<<endl;
        cout<<"------------------------------"<<endl;
        cout<<"0) VOLVER"<<endl;
        cout<<"------------------------------"<<endl;
        cout<<"OPCI�N: -> ";
        cin>>opc;
        pos=0;
        switch(opc){
            case 1: menuPlatos();
                break;
            case 2: mostrarVentas();
                break;
            case 3: atenderCliente(dniEmpleado);
                break;
            case 4: cobrarVentas(dniEmpleado);
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
                    cout<<"DNI: ";
                    cin>>dniAdmin;
                    existeAdmin=buscarAdmin(dniAdmin);
                    if(existeAdmin==true){
                        cout<<"CONTRASE�A: ";
                        cargarCadena(contrasenia,8);
                        existeContra=buscarAdminContra(contrasenia);
                        if(existeContra==true){
                            menuAdmin(dniAdmin);
                        }
                        else{
                            cout<<"LA CONTRASE�A NO EXISTE"<<endl;
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
void menuAdmin(int dniAdmin){
    Usuario reg;
    int opc,dniCliente,pos,dniEmpleado;
    bool existeCliente,existeEmpleado;
    while(true){
        system("cls");
        pos=0;
        cout<<"**************************"<<endl;
        cout<<"*      ACCESO ADMIN      *"<<endl;
        cout<<"**************************"<<endl<<endl;
        cout<<"--------ADMIN LOGEADO--------"<<endl;
        while(reg.leerDeDisco(pos)){
            if(reg.getDNI()==dniAdmin && reg.getTipo()==1){
                reg.MostrarLogeado();
                cout<<"------------------------------"<<endl;
            }
            pos++;
        }
        cout<<"------------------------------"<<endl;
        cout<<"1) MOSTRAR EMPLEADOS REGISTRADOS"<<endl;
        cout<<"2) REGISTRAR NUEVO EMPLEADO"<<endl;
        cout<<"3) MODIFICAR DATOS DEL CLIENTE"<<endl;
        cout<<"4) MODIFICAR DATOS DEL EMPLEADO"<<endl;
        cout<<"0) VOLVER"<<endl;
        cout<<"------------------------------"<<endl;
        cout<<"OPCI�N: -> ";
        cin>>opc;
        pos=0;
        switch(opc){
            case 1: mostrarEmpleadosRegistrados();
                break;
            case 2: crearEmpleado();
                break;
            case 3: system("cls");
                    cout<<"------------------------------"<<endl;
                    while(reg.leerDeDisco(pos)==1){
                        if(reg.getEstado()==true && reg.getTipo()==3){
                            reg.Mostrar();
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
                    while(reg.leerDeDisco(pos)==1){
                        if(reg.getEstado()==true && reg.getTipo()==2){
                            reg.Mostrar();
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
        cout<<"*         MEN� PLATOS         *"<<endl;
        cout<<"*                             *"<<endl;
        cout<<"*******************************"<<endl<<endl;
        cout<<"------------------------------"<<endl;
        cout<<"1) AGREGAR PLATO"<<endl;
        cout<<"2) MOSTRAR PLATO POR CODIGO"<<endl;
        cout<<"3) MOSTRAR TODOS LOS PLATOS"<<endl;
        cout<<"4) AGREGAR STOCK"<<endl;
        cout<<"5) MODIFICAR NOMBRE DEL PLATO"<<endl;
        cout<<"6) MODIFICAR DESCRIPCI�N DEL PLATO"<<endl;
        cout<<"7) MODIFCAR PRECIO DEL PLATO"<<endl;
        cout<<"8) MODIFICAR STOCK"<<endl;
        cout<<"9) ELIMINAR PLATO"<<endl;
        cout<<"10) RESTABLECER PLATO"<<endl;
        cout<<"0) VOLVER"<<endl;
        cout<<"------------------------------"<<endl;
        cout<<"OPCI�N: -> ";
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
