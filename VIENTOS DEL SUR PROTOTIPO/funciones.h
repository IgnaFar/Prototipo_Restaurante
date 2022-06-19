#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

///PROTOTIPOS GLOBALES
bool buscarPlato(const char *);

bool buscarCliente(int);

bool buscarClienteContra(const char *);

bool buscarEmpleado(int);

bool buscarEmpleadoContra(const char *);
///


///PROTOTIPOS

///MENU ADMIN
void crearEmpleado();
///

///MENU PLATOS
void menuPlatos();

void agregarPlato();

void mostrarPorCodigo();

void mostrarPlatos();

void eliminarPlato();

void restablecerPlato();
///


///MENU EMPLEADOS
void menuEmpleados();

void mostrarEmpleados();

void mostrarClientesRegistrados();
///


///MENU CLIENTES
void menuCliente();

void registrarCliente();

void crearPedido(int);
int generarIDVenta();
void traerPlato();
float importePlato(const char *,int);

void cancelarPedido(int);

///


///MENU VENTAS Y PEDIDOS
void menuVentasPedidos();

void menuVentasCliente(int);
void mostrarPedido(int);

void menuVentasEmpleado(int);
void mostrarVentas();
bool clienteNoAtendido(int);
int traerCliente(int);
void atenderCliente(int);
void atenderAlCliente(int,int);

///


///FUNCIONES GLOBALES
bool buscarPlato(const char *codPlat){
    Plato reg;
    int pos=0;
    while(reg.leerDeDisco(pos)==1){
        if(strcmp(reg.getCodigoPlato(),codPlat)==0){
            return true;
        }
        pos++;
    }
    return false;
}

bool buscarCliente(int dni){
    Cliente reg;
    int pos=0;
    while(reg.leerDeDisco(pos)==1){
        if(reg.getDNI()==dni){
            return true;
        }
        pos++;
    }
    return false;
}

bool buscarClienteContra(const char *contrasenia){
    Cliente reg;
    int pos=0;
    while(reg.leerDeDisco(pos)==1){
        if(strcmp(reg.getContrasenia(),contrasenia)==0){
            return true;
        }
        pos++;
    }
    return false;
}

bool buscarEmpleado(int dniEmp){
    Empleado reg;
    int pos=0;
    while(reg.leerDeDisco(pos)==1){
        if(reg.getDNI()==dniEmp){
            return true;
        }
        pos++;
    }
    return false;
}

bool buscarEmpleadoContra(const char *contrasenia){
    Empleado reg;
    int pos=0;
    while(reg.leerDeDisco(pos)==1){
        if(strcmp(reg.getContrasenia(),contrasenia)==0){
            return true;
        }
        pos++;
    }
    return false;
}
///


///FUNCIONES

///MENU ADMIN
void crearEmpleado(){
    Empleado reg;
    int dni,pos=0;
    bool existeEmpleado=false;
    cout<<"**************************"<<endl;
    cout<<"*      ACCESO ADMIN      *"<<endl;
    cout<<"**************************"<<endl<<endl;
    cout<<"<<<REGISTRAR NUEVO EMPLEADO>>>"<<endl;
    cout<<"DNI: ";
    cin>>dni;
    if(dni==0){
        return;
    }
    while(reg.leerDeDisco(pos)==1){
        if(reg.getDNI()==dni){
            existeEmpleado=true;
        }
        pos++;
    }
    if(existeEmpleado==false){
        reg.Cargar();
        reg.setDNI(dni);
        reg.grabarEnDisco();
    }
    else{
        cout<<"EL EMPLEADO YA EXISTE."<<endl;
        system("pause");
    }
}
///


///MENU PLATOS
void agregarPlato(){
    system("cls");
    Plato reg;
    char codPlat[6];
    bool existePlato;
    cout<<"*************************"<<endl;
    cout<<"*                       *"<<endl;
    cout<<"*     AGREGAR PLATO     *"<<endl;
    cout<<"*                       *"<<endl;
    cout<<"*************************"<<endl<<endl;
    cout<<"CÓDIGO DE PLATO: ";
    cargarCadena(codPlat,5);
    existePlato=buscarPlato(codPlat);
    if(existePlato==false){
        reg.setCodigoPlato(codPlat);
        reg.Cargar();
        reg.grabarEnDisco();
    }
    else{
        cout<<"EL CÓDIGO DE PLATO NO EXISTE O NO ES CORRECTO."<<endl;
        system("pause");
    }
}

void mostrarPorCodigo(){
    system("cls");
    Plato reg;
    int pos=0;
    char codPlat[6];
    bool existePlato;
    cout<<"****************************"<<endl;
    cout<<"*                          *"<<endl;
    cout<<"*    MOSTRAR POR CÓDIGO    *"<<endl;
    cout<<"*                          *"<<endl;
    cout<<"****************************"<<endl<<endl;
    cout<<"CÓDIGO DE PLATO: ";
    cargarCadena(codPlat,5);
    cout<<endl;
    existePlato=buscarPlato(codPlat);
    if(existePlato==true){
        while(reg.leerDeDisco(pos)==1){
            if(strcmp(reg.getCodigoPlato(),codPlat)==0){
                reg.Mostrar();
                cout<<"----------------------------------"<<endl;
            }
            pos++;
        }
    }
    if(existePlato==false) cout<<"EL CÓDIGO NO EXISTE O NO ES CORRECTO."<<endl;
    system("pause");
}

void mostrarPlatos(){
    system("cls");
    Plato reg;
    int pos=0;
    cout<<"****************************"<<endl;
    cout<<"*                          *"<<endl;
    cout<<"*      MOSTRAR PLATOS      *"<<endl;
    cout<<"*                          *"<<endl;
    cout<<"****************************"<<endl<<endl;
    while(reg.leerDeDisco(pos)==1){
        reg.Mostrar();
        cout<<"----------------------------------"<<endl;
        pos++;
    }
    system("pause");
}

void eliminarPlato(){
    system("cls");
    Plato reg;
    int pos=0;
    char codPlat[6];
    bool existePlato;
    cout<<"****************************"<<endl;
    cout<<"*                          *"<<endl;
    cout<<"*      ELIMINAR PLATO      *"<<endl;
    cout<<"*                          *"<<endl;
    cout<<"****************************"<<endl<<endl;
    while(reg.leerDeDisco(pos)==1){
        reg.Mostrar();
        cout<<"----------------------------------"<<endl;
        pos++;
    }
    cout<<"CÓDIGO DE PLATO: ";
    cargarCadena(codPlat,5);
    existePlato=buscarPlato(codPlat);
    if(existePlato==true){
        pos=0;
        while(reg.leerDeDisco(pos)==1){
            if(strcmp(reg.getCodigoPlato(),codPlat)==0 && reg.getEstado()==1){
                reg.setEstado(0);
                reg.modificarEnDisco(pos);
                cout<<"<<<PLATO ELIMINADO>>>"<<endl;
            }
            pos++;
        }
    }
    if(existePlato==false) cout<<"EL CÓDIGO NO EXISTE O NO ES CORRECTO."<<endl;
    system("pause");
}

void restablecerPlato(){
    system("cls");
    Plato reg;
    int pos=0;
    char codPlat[6];
    bool existePlato;
    cout<<"*****************************"<<endl;
    cout<<"*                           *"<<endl;
    cout<<"*     RESTABLECER PLATO     *"<<endl;
    cout<<"*                           *"<<endl;
    cout<<"*****************************"<<endl<<endl;
    while(reg.leerDeDisco(pos)==1){
        reg.Mostrar();
        cout<<"----------------------------------"<<endl;
        pos++;
    }
    cout<<"CÓDIGO DE PLATO: ";
    cargarCadena(codPlat,5);
    existePlato=buscarPlato(codPlat);
    if(existePlato==true){
        pos=0;
        while(reg.leerDeDisco(pos)==1){
            if(strcmp(reg.getCodigoPlato(),codPlat)==0 && reg.getEstado()==0){
                reg.setEstado(1);
                reg.modificarEnDisco(pos);
                cout<<"<<<PLATO RESTABLECIDO>>>"<<endl;
            }
            pos++;
        }
    }
    if(existePlato==false) cout<<"EL CÓDIGO NO EXISTE O NO ES CORRECTO."<<endl;
    system("pause");
}
///


///MENU EMPLEADO
void mostrarEmpleados(){
    system("cls");
    Empleado reg;
    int pos=0;
    cout<<"*****************************"<<endl;
    cout<<"*                           *"<<endl;
    cout<<"*   EMPLEADOS REGISTRADOS   *"<<endl;
    cout<<"*                           *"<<endl;
    cout<<"*****************************"<<endl<<endl;
    while(reg.leerDeDisco(pos)==1){
        if(reg.getEstado()==true){
            reg.Mostrar();
            cout<<"----------------------------------"<<endl;
        }
        pos++;
    }
    system("pause");
}

void mostrarClientesRegistrados(){
    system("cls");
    Cliente reg;
    int pos=0;
    cout<<"******************************"<<endl;
    cout<<"*                            *"<<endl;
    cout<<"*    CLIENTES REGISTRADOS    *"<<endl;
    cout<<"*                            *"<<endl;
    cout<<"******************************"<<endl<<endl;
    while(reg.leerDeDisco(pos)==1){
        if(reg.getEstado()==true){
            reg.Mostrar();
            cout<<"----------------------------------"<<endl;
        }
        pos++;
    }
    system("pause");
}
///


///MENU CLIENTES
void registrarCliente(){
    system("cls");
    Cliente reg;
    int dni;
    bool existeCliente;
    cout<<"*****************************"<<endl;
    cout<<"*                           *"<<endl;
    cout<<"*     REGISTRAR CLIENTE     *"<<endl;
    cout<<"*                           *"<<endl;
    cout<<"*****************************"<<endl<<endl;
    cout<<"DNI DEL CLIENTE: ";
    cin>>dni;
    existeCliente=buscarCliente(dni);
    if(existeCliente==false){
        reg.setDNI(dni);
        reg.Cargar();
        reg.grabarEnDisco();
        cout<<endl;
        cout<<"<<<CLIENTE REGISTRADO>>>"<<endl;
    }
    if(existeCliente==true) cout<<"EL CLIENTE YA EXISTE."<<endl;
    system("pause");
}

void crearPedido(int dniCliente){
    VentaCabecera reg;
    VentaDetalle aux;
    int idventa=0,otroPedido=1,opc,cantidad;
    char codPlat[6];
    float importe;
    bool repetir=false,pedido=true,existePlato;
    while(otroPedido==1){
        system("cls");
        cout<<"******************************"<<endl;
        cout<<"*                            *"<<endl;
        cout<<"*        CREAR PEDIDO        *"<<endl;
        cout<<"*                            *"<<endl;
        cout<<"******************************"<<endl<<endl;
        if(repetir==false){
            idventa=generarIDVenta();
            reg.Cargar(idventa,dniCliente);
            cout<<endl;
            while(pedido==true){
                system("cls");
                traerPlato();
                cout<<"CÓDIGO DE PLATO: ";
                cargarCadena(codPlat,5);
                existePlato=buscarPlato(codPlat);
                if(existePlato==true){
                    cout<<"CANTIDAD: ";
                    cin>>cantidad;
                    while(cantidad<=0){
                        cout<<"LA CANTIDAD DEBE SER MAYOR A 0."<<endl;
                        cout<<"CANTIDAD: ";
                        cin>>cantidad;
                    }
                    importe=importePlato(codPlat,cantidad);
                    pedido=false;
                    reg.setImporte(importe);
                    reg.grabarEnDisco();
                    aux.Cargar(idventa,dniCliente,codPlat,cantidad,importe);
                    aux.grabarEnDisco();
                    repetir=true;
                }
                else{
                    cout<<"EL CÓDIGO DE PLATO NO ES CORRECTO."<<endl;
                    system("pause");
                }
            }
        }
        else{
            idventa+=1;
            pedido=true;
            while(pedido==true){
                system("cls");
                traerPlato();
                cout<<"CÓDIGO DE PLATO: ";
                cargarCadena(codPlat,5);
                existePlato=buscarPlato(codPlat);
                if(existePlato==true){
                    cout<<"CANTIDAD: ";
                    cin>>cantidad;
                    while(cantidad<=0){
                        cout<<"LA CANTIDAD DEBE SER MAYOR A 0."<<endl;
                        cout<<"CANTIDAD: ";
                        cin>>cantidad;
                    }
                    importe=importePlato(codPlat,cantidad);
                    reg.setIDVenta(idventa);
                    reg.setImporte(importe);
                    reg.grabarEnDisco();
                    aux.setIDVenta(idventa);
                    aux.setCantidad(cantidad);
                    aux.setImporte(importe);
                    aux.grabarEnDisco();
                    pedido=false;
                }
                else{
                    cout<<"EL CÓDIGO DE PLATO NO ES CORRECTO."<<endl;
                    system("pause");
                }
            }
        }
        cout<<"¿QUIÉRE AGREGAR ALGO MÁS? SI(1)/NO(0)"<<endl;
        cout<<"OPCIÓN -> ";
        cin>>opc;
        switch(opc){
            case 1: repetir=true;
                break;
            case 0: otroPedido=0;
                break;
            default: cout<<"OPCIÓN INCORRECTA."<<endl;
                    system("pause");
                break;
        }
    }
    cout<<"<<<DETALLE GENERADO>>>"<<endl;
}

int generarIDVenta(){
    VentaCabecera reg;
    int pos=0,idventa=1;
    while(reg.leerDeDisco(pos)==1){
        idventa++;
        pos++;
    }
    return idventa;
}

void traerPlato(){
    Plato reg;
    int pos=0;
    while(reg.leerDeDisco(pos)==1){
        if(reg.getEstado()==1){
            reg.Mostrar();
            cout<<"----------------------------------"<<endl;
        }
        pos++;
    }
}

float importePlato(const char *codPlat,int cantidad){
    Plato reg;
    int pos=0;
    float importe;
    while(reg.leerDeDisco(pos)==1){
        if(strcmp(reg.getCodigoPlato(),codPlat)==0){
            importe=reg.getPrecio()*cantidad;
        }
        pos++;
    }
    return importe;
}

void cancelarPedido(int dni){
    system("cls");
    VentaCabecera reg;
    int pos=0,idventa,opc,leerRegistro=0;
    bool cancelarOtro=true;
    while(cancelarOtro==true){
        cout<<"*******************************"<<endl;
        cout<<"*                             *"<<endl;
        cout<<"*       CANCELAR PEDIDO       *"<<endl;
        cout<<"*                             *"<<endl;
        cout<<"*******************************"<<endl<<endl;
        while(reg.leerDeDisco(pos)==1){
            if(reg.getDNICliente()==dni){
                reg.Mostrar();
                cout<<"----------------------------------"<<endl;
                pos++;
                leerRegistro++;
            }
            else{
                if(leerRegistro==0){
                    cout<<"EL CLIENTE NO TIENE NINGÚN PEDIDO."<<endl;
                    system("pause");
                    return;
                }
            }
            pos++;
        }
        cout<<"ID DE VENTA: ";
        cin>>idventa;
        if(idventa==0){
            cout<<"<<<OPERACIÓN CANCELADA>>>"<<endl;
            return;
        }
        pos=0;
        while(reg.leerDeDisco(pos)==1){
            if(reg.getIDVenta()==idventa){
                reg.setDNIEmpleado(-1);
                reg.modificarEnDisco(pos);
                cout<<"<<<PEDIDO CANCELADO>>>"<<endl;
            }
            pos++;
        }
        cout<<"¿QUIÉRE CANCELAR ALGO MÁS? SI(1)/NO(0)"<<endl;
        cin>>opc;
        switch(opc){
            case 1: cancelarOtro=true;
                break;
            case 0: cancelarOtro=false;
                break;
            default: cout<<"OPCIÓN INCORRECTA."<<endl;
                    system("pause");
                break;
        }
    }
}
///


///MENU VENTAS/PEDIDOS

///MENU VENTAS CLIENTES
void menuVentasCliente(int dni){
    int opc;
    while(true){
        system("cls");
        cout<<"******************************"<<endl;
        cout<<"*                            *"<<endl;
        cout<<"*        MENÚ PEDIDOS        *"<<endl;
        cout<<"*                            *"<<endl;
        cout<<"******************************"<<endl<<endl;
        cout<<"------------------------------"<<endl;
        cout<<"1) MOSTRAR PEDIDO"<<endl;
        cout<<"0) VOLVER"<<endl;
        cout<<"------------------------------"<<endl;
        cout<<"OPCIÓN: -> ";
        cin>>opc;
        switch(opc){
            case 1: mostrarPedido(dni);
                break;
            case 0: return;
                break;
            default: cout<<"OPCIÓN INCORRECTA."<<endl;
                    system("pause");
                break;
        }
    }
}

void mostrarPedido(int dni){
    system("cls");
    VentaCabecera reg;
    int pos=0;
    float acumPrecio=0;
    while(reg.leerDeDisco(pos)==1){
        if(reg.getDNICliente()==dni){
            reg.Mostrar();
            cout<<"----------------------------------"<<endl;
        }
        pos++;
    }
    pos=0;
    while(reg.leerDeDisco(pos)==1){
        if(reg.getDNICliente()==dni){
            acumPrecio+=reg.getImporte();
        }
        pos++;
    }
    cout<<endl;
    cout<<"**************************************"<<endl;
    cout<<"       IMPORTE TOTAL: $"<<acumPrecio<<endl;
    cout<<"**************************************"<<endl;
    system("pause");
}

void menuVentasEmpleado(int dni){
    int opc;
    while(true){
        system("cls");
        cout<<"*******************************"<<endl;
        cout<<"*                             *"<<endl;
        cout<<"*         MENÚ VENTAS         *"<<endl;
        cout<<"*                             *"<<endl;
        cout<<"*******************************"<<endl<<endl;
        cout<<"------------------------------"<<endl;
        cout<<"1) MOSTRAR VENTAS"<<endl;
        cout<<"2) ATENDER CLIENTE"<<endl;
        cout<<"0) VOLVER"<<endl;
        cout<<"------------------------------"<<endl;
        cout<<"OPCIÓN: -> ";
        cin>>opc;
        switch(opc){
            case 1: mostrarVentas();
                break;
            case 2: atenderCliente(dni);
                break;
            case 0: return;
                break;
            default: cout<<"OPCIÓN INCORRECTA."<<endl;
                    system("pause");
                break;
        }
    }
}

void mostrarVentas(){
    system("cls");
    VentaDetalle reg;
    int pos=0,noAtendido;
    bool sinAtender;
    cout<<"********************************"<<endl;
    cout<<"*                              *"<<endl;
    cout<<"*        MOSTRAR VENTAS        *"<<endl;
    cout<<"*                              *"<<endl;
    cout<<"********************************"<<endl<<endl;
    while(reg.leerDeDisco(pos)==1){
        if(reg.getEstado()==true){
            sinAtender=clienteNoAtendido(reg.getIDVenta());
            if(sinAtender==true){
                noAtendido=traerCliente(reg.getIDVenta());
                cout<<"EL CLIENTE "<<noAtendido<<" NO ESTÁ ATENDIDO."<<endl;
                cout<<"----------------------------------"<<endl;
            }
            else{
                reg.Mostrar();
                cout<<"----------------------------------"<<endl;

            }
        }
        pos++;
    }
    system("pause");
}

bool clienteNoAtendido(int idventa){
    VentaCabecera reg;
    int pos=0;
    while(reg.leerDeDisco(pos)==1){
        if(reg.getIDVenta()==idventa){
            if(reg.getDNIEmpleado()==0){
                return true;
            }
        }
        pos++;
    }
    return false;
}

int traerCliente(int idventa){
    VentaCabecera reg;
    int pos=0;
    while(reg.leerDeDisco(pos)==1){
        if(reg.getIDVenta()==idventa){
            return reg.getDNICliente();
        }
        pos++;
    }
}

void atenderCliente(int dniEmp){
    system("cls");
    VentaDetalle reg;
    int pos=0,dniCliente,noHayRegistros=0;
    bool noAtendido,existeCliente;
    while(reg.leerDeDisco(pos)==1){
        noAtendido=clienteNoAtendido(reg.getIDVenta());
        if(noAtendido==true){
            reg.Mostrar();
            cout<<"----------------------------------"<<endl;
            noHayRegistros++;
        }
        pos++;
    }
    if(noHayRegistros==0){
        cout<<"NO HAY VENTAS REGISTRADAS AÚN."<<endl;
        system("pause");
    }
    else{
        cout<<"DNI DEL CLIENTE A ATENDER: ";
        cin>>dniCliente;
        existeCliente=buscarCliente(dniCliente);
        if(existeCliente==true){
            atenderAlCliente(dniCliente,dniEmp);
        }
        else{
            cout<<"EL CLIENTE NO EXISTE O NO ESTA REGISTRADO."<<endl;
            system("pause");
        }
    }
}

void atenderAlCliente(int dniCliente,int dniEmp){
    VentaCabecera reg;
    int pos=0;
    while(reg.leerDeDisco(pos)==1){
        if(reg.getDNICliente()==dniCliente){
            reg.setDNIEmpleado(dniEmp);
            reg.modificarEnDisco(pos);
        }
        pos++;
    }
}
///

#endif // FUNCIONES_H_INCLUDED
