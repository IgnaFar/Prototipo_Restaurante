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
bool buscarAdmin(int);

bool buscarAdminContra(const char *);

void menuAdmin();
void crearEmpleado();
void modificarDatosCliente(int);
void modificarDatosEmpleado(int);

///

///MENU PLATOS
void menuPlatos();

void agregarPlato();

void mostrarPorCodigo();

void mostrarPlatos();

void agregarStock();

void modificarNombre();
void cambiarNombre(const char *,const char *);

void modificarDescripcion();
void cambiarDescripcion(const char *,const char *);

void modificarPrecio();
void cambiarPrecio(const char *,float);

void modificarStock();
void cambiarStock(const char *,int);

void eliminarPlato();

void restablecerPlato();
///


///MENU EMPLEADOS
void menuEmpleados(int);

void mostrarEmpleadosRegistrados();

void mostrarClientesRegistrados();

void reportes();
void importeTotalRecaudado();
///


///MENU CLIENTES
void menuCliente(int);

void registrarCliente();

void crearPedido(int);
int generarIDVenta();
int generarIDDetalle();
int traerIDDetalle();
void traerPlato();
int chequearStock(const char *,int);
float importePlato(const char *,int);
void disminuirStock(const char *,int);
void restanteStock(const char *);

void cancelarPedido(int);
void cancelarDetalle(int);
void devolverStock(const char *,int);
///


///MENU VENTAS Y PEDIDOS
void menuVentasPedidos();

void menuVentasCliente(int);
void mostrarPedido(int);

void mostrarVentas();
bool clienteNoAtendido(int);
int traerCliente(int);
void atenderCliente(int);
bool buscarIDDetalle(int);
void atenderAlCliente(int,int);

void cobrarVentas(int);
bool buscarClienteAtendido(int);
void buscarVenta(int,int);

void mostrarVentasCobradas();

void mostrarVentasCanceladas();
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


///MENU ADMIN
bool buscarAdmin(int dni){
    Admin reg;
    int pos=0;
    while(reg.leerDeDisco(pos)==1){
        if(reg.getDNI()==dni){
            return true;
        }
        pos++;
    }
    return false;
}

bool buscarAdminContra(const char *contrasenia){
    Admin reg;
    int pos=0;
    while(reg.leerDeDisco(pos)==1){
        if(strcmp(reg.getContrasenia(),contrasenia)==0){
            return true;
        }
        pos++;
    }
    return false;
}

void crearEmpleado(){
    system("cls");
    Empleado reg;
    int pos=0,dni;
    bool existeEmpleado=false;
    cout<<"**************************"<<endl;
    cout<<"*   REGISTRAR EMPLEADO   *"<<endl;
    cout<<"**************************"<<endl<<endl;
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
        reg.setDNI(dni);
        reg.CargarEmpleado();
        reg.grabarEnDisco();
    }
    else{
        cout<<"EL EMPLEADO YA EXISTE."<<endl;
        system("pause");
    }
}

void modificarDatosCliente(int dniCliente){
    Cliente reg;
    VentaCabecera aux;
    int opc,pos,dniNuevo,dniExtra;
    char nombre[30],apellido[30],contrasenia[9],telefono[15];
    while(true){
        system("cls");
        pos=0;
        cout<<"*************************************"<<endl;
        cout<<"*    MODIFICAR DATOS DEL CLIENTE    *"<<endl;
        cout<<"*************************************"<<endl<<endl;
        cout<<"------------------------------"<<endl;
        cout<<"1) MODIFICAR DNI"<<endl;
        cout<<"2) MODIFICAR NOMBRE"<<endl;
        cout<<"3) MODIFICAR APELLIDO"<<endl;
        cout<<"4) MODIFICAR CONTRASE�A"<<endl;
        cout<<"5) MODIFICAR TEL�FONO"<<endl;
        cout<<"0) VOLVER"<<endl;
        cout<<"------------------------------"<<endl;
        cout<<"OPCI�N: -> ";
        cin>>opc;
        switch(opc){
            case 1: cout<<endl;
                    cout<<"NU�VO DNI: ";
                    cin>>dniNuevo;
                    while(aux.leerDeDisco(pos)==1){
                        if(aux.getDNICliente()==dniCliente){
                            aux.setDNICliente(dniNuevo);
                            aux.modificarEnDisco(pos);
                        }
                        pos++;
                    }
                    pos=0;
                    while(reg.leerDeDisco(pos)==1){
                        if(reg.getDNI()==dniCliente){
                            dniExtra=reg.getDNI();
                            reg.setDNI(dniNuevo);
                            reg.modificarEnDisco(pos);
                        }
                        pos++;
                    }
                    cout<<endl;
                    cout<<"<<<DNI ACTUALIZADO>>>"<<endl;
                    system("pause");
                break;
            case 2: cout<<endl;
                    cout<<"NU�VO NOMBRE: ";
                    cargarCadena(nombre,29);
                    while(reg.leerDeDisco(pos)==1){
                        if(reg.getDNI()==dniCliente || reg.getDNI()==dniExtra){
                            reg.setNombre(nombre);
                            reg.modificarEnDisco(pos);
                        }
                        pos++;
                    }
                    cout<<endl;
                    cout<<"<<<NOMBRE ACTUALIZADO>>>"<<endl;
                    system("pause");
                break;
            case 3: cout<<endl;
                    cout<<"NU�VO APELLIDO: ";
                    cargarCadena(apellido,29);
                    while(reg.leerDeDisco(pos)==1){
                        if(reg.getDNI()==dniCliente || reg.getDNI()==dniExtra){
                            reg.setApellido(apellido);
                            reg.modificarEnDisco(pos);
                        }
                        pos++;
                    }
                    cout<<endl;
                    cout<<"<<<APELLIDO ACTUALIZADO>>>"<<endl;
                    system("pause");
                break;
            case 4: cout<<endl;
                    cout<<"NU�VA CONTRASE�A: ";
                    cargarCadena(contrasenia,8);
                    while(reg.leerDeDisco(pos)==1){
                        if(reg.getDNI()==dniCliente || reg.getDNI()==dniExtra){
                            reg.setContrasenia(contrasenia);
                            reg.modificarEnDisco(pos);
                        }
                        pos++;
                    }
                    cout<<endl;
                    cout<<"<<<CONTRASE�A ACTUALIZADO>>>"<<endl;
                    system("pause");
                break;
            case 5: cout<<endl;
                    cout<<"NU�VO N�MERO DE TEL�FONO (CARACTERES): ";
                    cargarCadena(telefono,14);
                    while(reg.leerDeDisco(pos)==1){
                        if(reg.getDNI()==dniCliente || reg.getDNI()==dniExtra){
                            reg.setTelefono(telefono);
                            reg.modificarEnDisco(pos);
                        }
                        pos++;
                    }
                    cout<<endl;
                    cout<<"<<<TEL�FONO ACTUALIZADO>>>"<<endl;
                    system("pause");
                break;
            case 0: return;
                break;
            default: cout<<"OPCION INCORRECTA"<<endl;
                    system("pause");
                break;
        }
    }
}

void modificarDatosEmpleado(int dniEmpleado){
    Empleado reg;
    VentaCabecera aux;
    int opc,pos,dniNuevo,dniExtra;
    char nombre[30],apellido[30],contrasenia[9];
    while(true){
        system("cls");
        pos=0;
        cout<<"**************************************"<<endl;
        cout<<"*    MODIFICAR DATOS DEL EMPLEADO    *"<<endl;
        cout<<"**************************************"<<endl<<endl;
        cout<<"------------------------------"<<endl;
        cout<<"1) MODIFICAR DNI"<<endl;
        cout<<"2) MODIFICAR NOMBRE"<<endl;
        cout<<"3) MODIFICAR APELLIDO"<<endl;
        cout<<"4) MODIFICAR CONTRASE�A"<<endl;
        cout<<"0) VOLVER"<<endl;
        cout<<"------------------------------"<<endl;
        cout<<"OPCI�N: -> ";
        cin>>opc;
        switch(opc){
            case 1: cout<<endl;
                    cout<<"NU�VO DNI: ";
                    cin>>dniNuevo;
                    while(aux.leerDeDisco(pos)==1){
                        if(aux.getDNIEmpleado()==dniEmpleado){
                            aux.setDNIEmpleado(dniNuevo);
                            aux.modificarEnDisco(pos);
                        }
                        pos++;
                    }
                    pos=0;
                    while(reg.leerDeDisco(pos)==1){
                        if(reg.getDNI()==dniEmpleado){
                            dniExtra=reg.getDNI();
                            reg.setDNI(dniNuevo);
                            reg.modificarEnDisco(pos);
                        }
                        pos++;
                    }
                    cout<<endl;
                    cout<<"<<<DNI ACTUALIZADO>>>"<<endl;
                    system("pause");
                break;
            case 2: cout<<endl;
                    cout<<"NU�VO NOMBRE: ";
                    cargarCadena(nombre,29);
                    while(reg.leerDeDisco(pos)==1){
                        if(reg.getDNI()==dniEmpleado || reg.getDNI()==dniExtra){
                            reg.setNombre(nombre);
                            reg.modificarEnDisco(pos);
                        }
                        pos++;
                    }
                    cout<<endl;
                    cout<<"<<<NOMBRE ACTUALIZADO>>>"<<endl;
                    system("pause");
                break;
            case 3: cout<<endl;
                    cout<<"NU�VO APELLIDO: ";
                    cargarCadena(apellido,29);
                    while(reg.leerDeDisco(pos)==1){
                        if(reg.getDNI()==dniEmpleado || reg.getDNI()==dniExtra){
                            reg.setApellido(apellido);
                            reg.modificarEnDisco(pos);
                        }
                        pos++;
                    }
                    cout<<endl;
                    cout<<"<<<APELLIDO ACTUALIZADO>>>"<<endl;
                    system("pause");
                break;
            case 4: cout<<endl;
                    cout<<"NU�VA CONTRASE�A: ";
                    cargarCadena(contrasenia,8);
                    while(reg.leerDeDisco(pos)==1){
                        if(reg.getDNI()==dniEmpleado || reg.getDNI()==dniExtra){
                            reg.setContrasenia(contrasenia);
                            reg.modificarEnDisco(pos);
                        }
                        pos++;
                    }
                    cout<<endl;
                    cout<<"<<<CONTRASE�A ACTUALIZADO>>>"<<endl;
                    system("pause");
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


///FUNCIONES

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
    cout<<"C�DIGO DE PLATO: ";
    cargarCadena(codPlat,5);
    existePlato=buscarPlato(codPlat);
    if(existePlato==false){
        reg.setCodigoPlato(codPlat);
        reg.Cargar();
        reg.grabarEnDisco();
    }
    else{
        cout<<"EL C�DIGO DE PLATO NO EXISTE O NO ES CORRECTO."<<endl;
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
    cout<<"*    MOSTRAR POR C�DIGO    *"<<endl;
    cout<<"*                          *"<<endl;
    cout<<"****************************"<<endl<<endl;
    cout<<"C�DIGO DE PLATO: ";
    cargarCadena(codPlat,5);
    cout<<endl;
    existePlato=buscarPlato(codPlat);
    if(existePlato==true){
        while(reg.leerDeDisco(pos)==1){
            if(strcmp(reg.getCodigoPlato(),codPlat)==0){
                if(reg.getEstado()==1){
                    reg.Mostrar();
                    cout<<"----------------------------------"<<endl;
                }
            }
            pos++;
        }
    }
    if(existePlato==false) cout<<"EL C�DIGO NO EXISTE O NO ES CORRECTO."<<endl;
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
    cout<<"----------------------------------"<<endl;
    while(reg.leerDeDisco(pos)==1){
        if(reg.getEstado()==1){
            reg.Mostrar();
            cout<<"----------------------------------"<<endl;
        }
        pos++;
    }
    system("pause");
}

void agregarStock(){
    Plato reg;
    int pos=0,opc=-1,cantidad,totalCantidad=0;
    char codPlat[6];
    bool existePlato,agregar=true;
    while(opc!=0){
        while(agregar==true){
            system("cls");
            cout<<"*****************************"<<endl;
            cout<<"*                           *"<<endl;
            cout<<"*       AGREGAR STOCK       *"<<endl;
            cout<<"*                           *"<<endl;
            cout<<"*****************************"<<endl<<endl;
            cout<<"----------------------------------"<<endl;
            while(reg.leerDeDisco(pos)==1){
                if(reg.getEstado()==true){
                    reg.Mostrar();
                    cout<<"----------------------------------"<<endl;
                }
                pos++;
            }
            pos=0;
            cout<<"C�DIGO DE PLATO: ";
            cargarCadena(codPlat,5);
            existePlato=buscarPlato(codPlat);
            if(existePlato==true){
                cout<<"CANTIDAD: ";
                cin>>cantidad;
                while(cantidad<=0){
                    system("cls");
                    cout<<"LA CANTIDAD DEBE SER MAYOR A 0."<<endl<<endl;
                    cout<<"CANTIDAD: ";
                    cin>>cantidad;
                }
                while(reg.leerDeDisco(pos)==1){
                    if(strcmp(reg.getCodigoPlato(),codPlat)==0){
                        totalCantidad=reg.getStock()+cantidad;
                        reg.setStock(totalCantidad);
                        reg.modificarEnDisco(pos);
                        cout<<"<<<STOCK AGREGADO.>>>"<<endl;
                        agregar=false;
                    }
                    pos++;
                }
            }
            else{
                cout<<"EL PLATO NO EXISTE O EL C�DIGO NO ES CORRECTO."<<endl;
                agregar=false;
                system("pause");
            }
        }
        cout<<"�QUI�RE MODIFICAR ALGO M�S? SI(1)/NO(0)"<<endl;
        cin>>opc;
        switch(opc){
            case 1: pos=0;
                    agregar=true;
                break;
            case 0: return;
                break;
            default: cout<<"OPCI�N INCORRECTA."<<endl;
                    agregar=false;
                    system("pause");
                break;
        }
    }
}

void modificarNombre(){
    system("cls");
    Plato reg;
    int pos=0;
    char codPlat[6],nuevoNombre[30];
    bool existePlato;
    cout<<"******************************"<<endl;
    cout<<"*                            *"<<endl;
    cout<<"*      MODIFICAR NOMBRE      *"<<endl;
    cout<<"*                            *"<<endl;
    cout<<"******************************"<<endl<<endl;
    cout<<"----------------------------------"<<endl;
    while(reg.leerDeDisco(pos)==1){
        reg.Mostrar();
        cout<<"----------------------------------"<<endl;
        pos++;
    }
    cout<<"C�DIGO DE PLATO: ";
    cargarCadena(codPlat,5);
    existePlato=buscarPlato(codPlat);
    if(existePlato==true){
        pos=0;
        cout<<"NUEVO NOMBRE PARA EL PLATO: ";
        cargarCadena(nuevoNombre,29);
        cambiarNombre(codPlat,nuevoNombre);
        cout<<endl;
        cout<<"<<<NOMBRE MODIFICADO.>>>"<<endl;
    }
    else{
        cout<<"EL PLATO NO EXISTE O EL C�DIGO NO ES CORRECTO."<<endl;
        system("pause");
    }
}

void cambiarNombre(const char *codPlat,const char *nuevoNombre){
    Plato reg;
    int pos=0;
    while(reg.leerDeDisco(pos)==1){
        if(strcmp(reg.getCodigoPlato(),codPlat)==0){
            reg.setNombre(nuevoNombre);
            reg.modificarEnDisco(pos);
        }
        pos++;
    }
}

void modificarDescripcion(){
    system("cls");
    Plato reg;
    int pos=0;
    char codPlat[6],nuevaDescrip[30];
    bool existePlato;
    cout<<"*******************************"<<endl;
    cout<<"*                             *"<<endl;
    cout<<"*    MODIFICAR DESCRIPCI�N    *"<<endl;
    cout<<"*                             *"<<endl;
    cout<<"*******************************"<<endl<<endl;
    cout<<"----------------------------------"<<endl;
    while(reg.leerDeDisco(pos)==1){
        reg.Mostrar();
        cout<<"----------------------------------"<<endl;
        pos++;
    }
    cout<<"C�DIGO DE PLATO: ";
    cargarCadena(codPlat,5);
    existePlato=buscarPlato(codPlat);
    if(existePlato==true){
        pos=0;
        cout<<"NUEVA DESCRIPCI�N PARA EL PLATO: ";
        cargarCadena(nuevaDescrip,29);
        cambiarDescripcion(codPlat,nuevaDescrip);
        cout<<endl;
        cout<<"<<<DESCRIPCI�N MODIFICADA.>>>"<<endl;
    }
    else{
        cout<<"EL PLATO NO EXISTE O EL C�DIGO NO ES CORRECTO."<<endl;
        system("pause");
    }
}

void cambiarDescripcion(const char *codPlat,const char *nuevaDescrip){
    Plato reg;
    int pos=0;
    while(reg.leerDeDisco(pos)==1){
        if(strcmp(reg.getCodigoPlato(),codPlat)==0){
            reg.setDescripcion(nuevaDescrip);
            reg.modificarEnDisco(pos);
        }
        pos++;
    }
}

void modificarPrecio(){
    system("cls");
    Plato reg;
    int pos=0;
    float nuevoPrecio;
    char codPlat[6];
    bool existePlato;
    cout<<"********************************"<<endl;
    cout<<"*                              *"<<endl;
    cout<<"*       MODIFICAR PRECIO       *"<<endl;
    cout<<"*                              *"<<endl;
    cout<<"********************************"<<endl<<endl;
    cout<<"----------------------------------"<<endl;
    while(reg.leerDeDisco(pos)==1){
        reg.Mostrar();
        cout<<"----------------------------------"<<endl;
        pos++;
    }
    cout<<"C�DIGO DE PLATO: ";
    cargarCadena(codPlat,5);
    existePlato=buscarPlato(codPlat);
    if(existePlato==true){
        cout<<"NU�VO PRECIO: ";
        cin>>nuevoPrecio;
        cambiarPrecio(codPlat,nuevoPrecio);
        cout<<endl;
        cout<<"<<<PRECIO ACTUALIZADO>>>"<<endl;
        system("pause");
    }
    else{
        cout<<"EL PLATO NO EXISTE O EL C�DIGO NO ES CORRECTO."<<endl;
        system("pause");
    }
}

void cambiarPrecio(const char *codPlat,float nuevoPrecio){
    Plato reg;
    int pos=0;
    while(reg.leerDeDisco(pos)==1){
        if(strcmp(reg.getCodigoPlato(),codPlat)==0){
            reg.setPrecio(nuevoPrecio);
            reg.modificarEnDisco(pos);
        }
        pos++;
    }
}

void modificarStock(){
    system("cls");
    Plato reg;
    int pos=0,nuevoStock;
    char codPlat[6];
    bool existePlato;
    cout<<"*********************************"<<endl;
    cout<<"*                               *"<<endl;
    cout<<"*        MODIFICAR STOCK        *"<<endl;
    cout<<"*                               *"<<endl;
    cout<<"*********************************"<<endl<<endl;
    cout<<"----------------------------------"<<endl;
    while(reg.leerDeDisco(pos)==1){
        reg.Mostrar();
        cout<<"----------------------------------"<<endl;
        pos++;
    }
    cout<<"C�DIGO DE PLATO: ";
    cargarCadena(codPlat,5);
    existePlato=buscarPlato(codPlat);
    if(existePlato==true){
        cout<<"NU�VA CANTIDAD DE STOCK: ";
        cin>>nuevoStock;
        while(nuevoStock<=0){
            cout<<"LA CANTIDAD DE STOCK TIENE QUE SER MAYOR A 0."<<endl;
            cout<<"NU�VA CANTIDAD DE STOCK: ";
            cin>>nuevoStock;
        }
        cambiarStock(codPlat,nuevoStock);
        cout<<endl;
        cout<<"<<<STOCK ACTUALIZADO>>>"<<endl;
        system("pause");
    }
    else{
        cout<<"EL PLATO NO EXISTE O EL C�DIGO NO ES CORRECTO."<<endl;
        system("pause");
    }
}

void cambiarStock(const char *codPlat,int nuevoStock){
    Plato reg;
    int pos=0;
    while(reg.leerDeDisco(pos)==1){
        if(strcmp(reg.getCodigoPlato(),codPlat)==0){
            if(reg.getEstado()==true){
                reg.setStock(nuevoStock);
                reg.modificarEnDisco(pos);
            }
            else{
                reg.setEstado(true);
                reg.setStock(nuevoStock);
                reg.modificarEnDisco(pos);
            }
        }
        pos++;
    }
}

void eliminarPlato(){
    system("cls");
    Plato reg;
    int pos=0,cantReg=0;
    char codPlat[6];
    bool existePlato;
    cout<<"****************************"<<endl;
    cout<<"*                          *"<<endl;
    cout<<"*      ELIMINAR PLATO      *"<<endl;
    cout<<"*                          *"<<endl;
    cout<<"****************************"<<endl<<endl;
    cout<<"----------------------------------"<<endl;
    while(reg.leerDeDisco(pos)==1){
        if(reg.getEstado()==true){
            reg.Mostrar();
            cout<<"----------------------------------"<<endl;
            cantReg++;
        }
        pos++;
    }
    if(cantReg>0){
        cout<<"C�DIGO DE PLATO: ";
        cargarCadena(codPlat,5);
        existePlato=buscarPlato(codPlat);
        if(existePlato==true){
            pos=0;
            while(reg.leerDeDisco(pos)==1){
                if(strcmp(reg.getCodigoPlato(),codPlat)==0 && reg.getEstado()==1){
                    reg.setEstado(0);
                    reg.modificarEnDisco(pos);
                    cout<<"<<<PLATO ELIMINADO>>>"<<endl;
                    system("pause");
                }
                pos++;
            }
        }
        else{
            cout<<"EL C�DIGO NO EXISTE O NO ES CORRECTO."<<endl;
            system("pause");
        }
    }
    else{
        cout<<"NO HAY PLATOS A ELIMINAR."<<endl;
        system("pause");
    }
}

void restablecerPlato(){
    system("cls");
    Plato reg;
    int pos=0,cantReg=0;
    char codPlat[6];
    bool existePlato;
    cout<<"*****************************"<<endl;
    cout<<"*                           *"<<endl;
    cout<<"*     RESTABLECER PLATO     *"<<endl;
    cout<<"*                           *"<<endl;
    cout<<"*****************************"<<endl<<endl;
    cout<<"----------------------------------"<<endl;
    while(reg.leerDeDisco(pos)==1){
        if(reg.getEstado()==false){
            reg.Mostrar();
            cout<<"----------------------------------"<<endl;
            cantReg++;
        }
        pos++;
    }
    if(cantReg>0){
        cout<<"C�DIGO DE PLATO: ";
        cargarCadena(codPlat,5);
        existePlato=buscarPlato(codPlat);
        if(existePlato==true){
            pos=0;
            while(reg.leerDeDisco(pos)==1){
                if(strcmp(reg.getCodigoPlato(),codPlat)==0 && reg.getEstado()==0){
                    reg.setEstado(1);
                    reg.modificarEnDisco(pos);
                    cout<<"<<<PLATO RESTABLECIDO>>>"<<endl;
                    system("pause");
                }
                pos++;
            }
        }
        else{
            cout<<"EL PLATO NO EXISTE O EL C�DIGO NO ES CORRECTO."<<endl;
            system("pause");
        }
    }
    else{
        cout<<"NO HAY PLATOS PARA RESTABLECER."<<endl;
        system("pause");
    }
}
///


///MENU EMPLEADO
void mostrarEmpleadosRegistrados(){
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
            reg.MostrarEmpleado();
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
    cout<<"----------------------------------"<<endl;
    while(reg.leerDeDisco(pos)==1){
        if(reg.getEstado()==true){
            reg.MostrarCliente();
            cout<<"----------------------------------"<<endl;
        }
        pos++;
    }
    system("pause");
}

void reportes(){
    int opc;
    while(true){
        system("cls");
        cout<<"*******************************"<<endl;
        cout<<"*                             *"<<endl;
        cout<<"*        MEN� REPORTES        *"<<endl;
        cout<<"*                             *"<<endl;
        cout<<"*******************************"<<endl<<endl;
        cout<<"----------------------------------"<<endl;
        cout<<"1) IMPORTE TOTAL RECAUDADO"<<endl;
        cout<<"0) VOLVER"<<endl;
        cout<<"----------------------------------"<<endl;
        cout<<"OPCI�N: -> ";
        cin>>opc;
        switch(opc){
            case 1: importeTotalRecaudado();
                break;
            case 0: return;
                break;
            default: cout<<"OPCION INCORRECTA"<<endl;
                    system("pause");
                break;
        }
    }
}

void importeTotalRecaudado(){
    VentaCabecera reg;
    int pos=0;
    float acumImporte=0;
    while(reg.leerDeDisco(pos)==1){
        if(reg.getDNIEmpleado()==-2){
            acumImporte+=reg.getImporte();
        }
        pos++;
    }
    cout<<endl;
    cout<<"**************************************"<<endl;
    cout<<"       IMPORTE TOTAL: $"<<acumImporte<<endl;
    cout<<"**************************************"<<endl;
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
    if(dni==0){
        return;
    }
    existeCliente=buscarCliente(dni);
    if(existeCliente==false){
        reg.setDNI(dni);
        reg.CargarCliente();
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
    int idventa,otroPedido=1,opc,cantidad,numeroGrande,iddetalle;
    char codPlat[6];
    float importe;
    bool repetir=false,pedido=true,existePlato,sacarStock;
    while(otroPedido==1){
        system("cls");
        cout<<"******************************"<<endl;
        cout<<"*                            *"<<endl;
        cout<<"*        CREAR PEDIDO        *"<<endl;
        cout<<"*                            *"<<endl;
        cout<<"******************************"<<endl<<endl;
        idventa=generarIDVenta();
        sacarStock=false;
        if(repetir==false){
            iddetalle=generarIDDetalle();
            reg.Cargar(idventa,iddetalle,dniCliente);
            cout<<endl;
            while(pedido==true){
                system("cls");
                traerPlato();
                cout<<"C�DIGO DE PLATO: ";
                cargarCadena(codPlat,5);
                existePlato=buscarPlato(codPlat);
                if(existePlato==true){
                    while(sacarStock==false){
                        cout<<"CANTIDAD: ";
                        cin>>cantidad;
                        if(cantidad<=0){
                            cout<<"LA CANTIDAD DEBE SER MAYOR A 0."<<endl<<endl;
                        }
                        else{
                            numeroGrande=chequearStock(codPlat,cantidad);
                            if(numeroGrande<0){
                                cout<<"LA CANTIDAD SOBREPASA EL STOCK."<<endl;
                                system("pause");
                            }
                            else{
                                importe=importePlato(codPlat,cantidad);
                                pedido=false;
                                reg.setImporte(importe);
                                reg.grabarEnDisco();
                                disminuirStock(codPlat,cantidad);
                                aux.Cargar(idventa,iddetalle,codPlat,cantidad,importe);
                                aux.grabarEnDisco();
                                repetir=true;
                                sacarStock=true;
                                restanteStock(codPlat);
                            }
                        }
                    }
                }
                else{
                    cout<<"EL C�DIGO DE PLATO NO ES CORRECTO."<<endl;
                    system("pause");
                }
            }
        }
        else{
            pedido=true;
            while(pedido==true){
                system("cls");
                traerPlato();
                cout<<"C�DIGO DE PLATO: ";
                cargarCadena(codPlat,5);
                existePlato=buscarPlato(codPlat);
                if(existePlato==true){
                    while(sacarStock==false){
                        cout<<"CANTIDAD: ";
                        cin>>cantidad;
                        if(cantidad<=0){
                            cout<<"LA CANTIDAD DEBE SER MAYOR A 0."<<endl<<endl;
                        }
                        else{
                            numeroGrande=chequearStock(codPlat,cantidad);
                            if(numeroGrande<0){
                                cout<<"LA CANTIDAD SOBREPASA EL STOCK."<<endl;
                                system("pause");
                            }
                            else{
                                importe=importePlato(codPlat,cantidad);
                                reg.setIDVenta(idventa);
                                reg.setImporte(importe);
                                reg.grabarEnDisco();
                                disminuirStock(codPlat,cantidad);
                                aux.setIDVenta(idventa);
                                aux.setCantidad(cantidad);
                                aux.setImporte(importe);
                                aux.grabarEnDisco();
                                pedido=false;
                                sacarStock=true;
                                restanteStock(codPlat);
                            }
                        }
                    }
                }
                else{
                    cout<<"EL C�DIGO DE PLATO NO ES CORRECTO."<<endl;
                    system("pause");
                }
            }
        }
        system("cls");
        cout<<"�QUI�RE AGREGAR ALGO M�S? SI(1)/NO(0)"<<endl;
        cout<<"OPCI�N -> ";
        cin>>opc;
        switch(opc){
            case 1: repetir=true;
                break;
            case 0: otroPedido=0;
                break;
            default: cout<<"OPCI�N INCORRECTA."<<endl;
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

int generarIDDetalle(){
    VentaCabecera reg;
    int pos=0,cant=1,iddetalle;
    while(reg.leerDeDisco(pos)==1){
        cant++;
        pos++;
    }
    if(cant==1){
        return cant;
    }
    else{
        iddetalle=traerIDDetalle();
        return iddetalle;
    }
}

int traerIDDetalle(){
    VentaCabecera reg;
    int pos=0,iddetalle;
    while(reg.leerDeDisco(pos)==1){
        iddetalle=reg.getIDDetalle();
        pos++;
    }
    return iddetalle+1;
}

void traerPlato(){
    Plato reg;
    int pos=0;
    while(reg.leerDeDisco(pos)==1){
        if(reg.getEstado()==true){
            reg.Mostrar();
            cout<<"----------------------------------"<<endl;
        }
        pos++;
    }
}

int chequearStock(const char *codPlat,int cantidad){
    Plato reg;
    int pos=0,restarCant;
    while(reg.leerDeDisco(pos)==1){
        if(strcmp(reg.getCodigoPlato(),codPlat)==0){
            restarCant=reg.getStock()-cantidad;
            return restarCant;
        }
        pos++;
    }
    return -1;
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

void disminuirStock(const char *codPlat,int cantidad){
    Plato reg;
    int pos=0,totalStock;
    while(reg.leerDeDisco(pos)==1){
        if(strcmp(reg.getCodigoPlato(),codPlat)==0){
            totalStock=reg.getStock()-cantidad;
            reg.setStock(totalStock);
            reg.modificarEnDisco(pos);
        }
        pos++;
    }
}

void restanteStock(const char *codPlat){
    Plato reg;
    int pos=0;
    while(reg.leerDeDisco(pos)==1){
        if(strcmp(reg.getCodigoPlato(),codPlat)==0){
            if(reg.getStock()==0){
                reg.setEstado(false);
                reg.modificarEnDisco(pos);
            }
        }
        pos++;
    }
}

void cancelarPedido(int dni){
    system("cls");
    VentaCabecera reg;
    int pos=0,iddetalle,opc;
    bool cancelarOtro=true,cantReg,errorDetalle=false;
    while(cancelarOtro==true){
        cantReg=false;
        cout<<"*******************************"<<endl;
        cout<<"*                             *"<<endl;
        cout<<"*       CANCELAR PEDIDO       *"<<endl;
        cout<<"*                             *"<<endl;
        cout<<"*******************************"<<endl<<endl;
        cout<<"----------------------------------"<<endl;
        while(reg.leerDeDisco(pos)==1){
            if(reg.getDNICliente()==dni){
                if(reg.getDNIEmpleado()>=0){
                    reg.Mostrar();
                    cout<<"----------------------------------"<<endl;
                    cantReg=true;
                }
            }
            pos++;
        }
        if(cantReg==false){
            cout<<"EL CLIENTE NO TIENE NING�N PEDIDO."<<endl;
            return;
        }
        else{
            cout<<"ID DE DETALLE: ";
            cin>>iddetalle;
            if(iddetalle==0){
                cout<<"<<<OPERACI�N CANCELADA>>>"<<endl;
                return;
            }
            pos=0;
            while(reg.leerDeDisco(pos)==1){
                if(reg.getIDDetalle()==iddetalle && reg.getDNICliente()==dni){
                    reg.setDNIEmpleado(-1);
                    reg.modificarEnDisco(pos);
                    cancelarDetalle(iddetalle);
                    errorDetalle=true;
                    cout<<"<<<PEDIDO CANCELADO>>>"<<endl;
                }
                pos++;
            }
            if(errorDetalle==false){
                cout<<"EL ID DE DETALLE INGRESADO NO EXISTE."<<endl;
                return;
            }
            cout<<"�QUI�RE CANCELAR ALGO M�S? SI(1)/NO(0)"<<endl;
            cin>>opc;
            switch(opc){
                case 1: cancelarOtro=true;
                    break;
                case 0: cancelarOtro=false;
                    break;
                default: cout<<"OPCI�N INCORRECTA."<<endl;
                        system("pause");
                    break;
            }
        }
    }
}

void cancelarDetalle(int iddetalle){
    VentaDetalle reg;
    int pos=0;
    while(reg.leerDeDisco(pos)==1){
        if(reg.getIDDetalle()==iddetalle){
            devolverStock(reg.getIDPlato(),reg.getCantidad());
            reg.setEstado(false);
            reg.modificarEnDisco(pos);
        }
        pos++;
    }
}

void devolverStock(const char *codPlat,int cantidad){
    Plato reg;
    int pos=0;
    while(reg.leerDeDisco(pos)==1){
        if(strcmp(reg.getCodigoPlato(),codPlat)==0){
            if(reg.getEstado()==true){
                reg.setStock(reg.getStock()+cantidad);
                reg.modificarEnDisco(pos);
            }
            else{
                reg.setEstado(true);
                reg.setStock(reg.getStock()+cantidad);
                reg.modificarEnDisco(pos);
            }
        }
        pos++;
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
        cout<<"*        MEN� PEDIDOS        *"<<endl;
        cout<<"*                            *"<<endl;
        cout<<"******************************"<<endl<<endl;
        cout<<"------------------------------"<<endl;
        cout<<"1) MOSTRAR PEDIDO"<<endl;
        cout<<"0) VOLVER"<<endl;
        cout<<"------------------------------"<<endl;
        cout<<"OPCI�N: -> ";
        cin>>opc;
        switch(opc){
            case 1: mostrarPedido(dni);
                break;
            case 0: return;
                break;
            default: cout<<"OPCI�N INCORRECTA."<<endl;
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
    bool cantReg=false;
    cout<<"********************************"<<endl;
    cout<<"*                              *"<<endl;
    cout<<"*        MOSTRAR PEDIDO        *"<<endl;
    cout<<"*                              *"<<endl;
    cout<<"********************************"<<endl<<endl;
    cout<<"----------------------------------"<<endl;
    while(reg.leerDeDisco(pos)==1){
        if(reg.getDNICliente()==dni && reg.getDNIEmpleado()>=0){
            reg.Mostrar();
            cout<<"----------------------------------"<<endl;
            cantReg=true;
        }
        pos++;
    }
    if(cantReg==true){
        pos=0;
        while(reg.leerDeDisco(pos)==1){
            if(reg.getDNICliente()==dni && reg.getDNIEmpleado()>=0){
                acumPrecio+=reg.getImporte();
            }
            pos++;
        }
        cout<<endl;
        cout<<"**************************************"<<endl;
        cout<<"       IMPORTE TOTAL: $"<<acumPrecio<<endl;
        cout<<"**************************************"<<endl;
    }
    else{
        cout<<"EL CLIENTE NO HA HECHO UN PEDIDO A�N."<<endl;
    }
    system("pause");
}

void mostrarVentas(){
    system("cls");
    VentaDetalle reg;
    int pos=0,noAtendido;
    bool sinAtender,cantReg=false;
    cout<<"********************************"<<endl;
    cout<<"*                              *"<<endl;
    cout<<"*        MOSTRAR VENTAS        *"<<endl;
    cout<<"*                              *"<<endl;
    cout<<"********************************"<<endl<<endl;
    cout<<"----------------------------------"<<endl;
    while(reg.leerDeDisco(pos)==1){
        if(reg.getEstado()==true){
            sinAtender=clienteNoAtendido(reg.getIDVenta());
            if(sinAtender==true){
                noAtendido=traerCliente(reg.getIDVenta());
                cout<<"EL CLIENTE CON DNI "<<noAtendido<<" NO EST� ATENDIDO."<<endl;
                cout<<"----------------------------------"<<endl;
                cantReg=true;
            }
            else{
                reg.Mostrar();
                cout<<"----------------------------------"<<endl;
                cantReg=true;
            }
        }
        pos++;
    }
    if(cantReg==false) cout<<"NO SE HAN REGISTRADO VENTAS A�N."<<endl;
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
    return -1;
}

void atenderCliente(int dniEmp){
    system("cls");
    VentaDetalle reg;
    int pos=0,iddetalle;
    bool noAtendido,existeDetalle,cantReg=false;
    cout<<"*********************************"<<endl;
    cout<<"*                               *"<<endl;
    cout<<"*        ATENDER CLIENTE        *"<<endl;
    cout<<"*                               *"<<endl;
    cout<<"*********************************"<<endl<<endl;
    cout<<"----------------------------------"<<endl;
    while(reg.leerDeDisco(pos)==1){
        noAtendido=clienteNoAtendido(reg.getIDVenta());
        if(noAtendido==true){
            reg.Mostrar();
            cout<<"----------------------------------"<<endl;
            cantReg=true;
        }
        pos++;
    }
    if(cantReg==false){
        cout<<"NO HAY VENTAS REGISTRADAS A�N."<<endl;
        system("pause");
    }
    else{
        cout<<"ID DE DETALLE A ATENDER: ";
        cin>>iddetalle;
        if(iddetalle==0){
            return;
        }
        existeDetalle=buscarIDDetalle(iddetalle);
        if(existeDetalle==true){
            atenderAlCliente(iddetalle,dniEmp);
        }
        else{
            cout<<endl;
            cout<<"LA VENTA NO EXISTE O EL ID NO ES CORRECTO."<<endl;
            system("pause");
        }
    }
}

void atenderAlCliente(int iddetalle,int dniEmp){
    VentaCabecera reg;
    int pos=0;
    while(reg.leerDeDisco(pos)==1){
        if(reg.getIDDetalle()==iddetalle){
            reg.setDNIEmpleado(dniEmp);
            reg.modificarEnDisco(pos);
        }
        pos++;
    }
}

bool buscarIDDetalle(int iddetalle){
    VentaDetalle reg;
    int pos=0;
    while(reg.leerDeDisco(pos)==1){
        if(reg.getIDDetalle()==iddetalle){
            return true;
        }
        pos++;
    }
    return false;
}

void cobrarVentas(int dniEmp){
    system("cls");
    VentaDetalle reg;
    int pos=0,iddetalle;
    bool existeDetalle,noAtendido,cantReg=false,clienteAtendido;
    cout<<"*********************************"<<endl;
    cout<<"*                               *"<<endl;
    cout<<"*         COBRAR VENTAS         *"<<endl;
    cout<<"*                               *"<<endl;
    cout<<"*********************************"<<endl<<endl;
    cout<<"         VENTAS ATENDIDAS         "<<endl;
    cout<<"----------------------------------"<<endl;
    while(reg.leerDeDisco(pos)==1){
        if(reg.getEstado()==true){
            noAtendido=clienteNoAtendido(reg.getIDVenta());
            if(noAtendido==true){
                cout<<"LA VENTA CON ID DE DETALLE "<<reg.getIDDetalle()<<" NO FUE ATENDIDA."<<endl;
                cout<<"----------------------------------"<<endl;
            }
            else{
                reg.Mostrar();
                cout<<"----------------------------------"<<endl;
                cantReg=true;
            }
        }
        pos++;
    }
    if(cantReg==true){
        cout<<"ELIJA EL ID DE DETALLE A COBRAR: ";
        cin>>iddetalle;
        clienteAtendido=buscarClienteAtendido(iddetalle);
        existeDetalle=buscarIDDetalle(iddetalle);
        if(existeDetalle==true && clienteAtendido==true){
            cout<<endl;
            buscarVenta(iddetalle,dniEmp);
            pos=0;
            while(reg.leerDeDisco(pos)==1){
                if(reg.getIDDetalle()==iddetalle){
                    reg.setEstado(false);
                    reg.modificarEnDisco(pos);
                }
                pos++;
            }
            cout<<"<<<LA VENTA SE COBR� CON �XITO>>>"<<endl;
            system("pause");
        }
        else{
            cout<<"LA VENTA NO EXISTE O NO HA SIDO ATEDIDA A�N."<<endl;
            system("pause");
        }
    }
    else{
        cout<<endl;
        cout<<"NO SE ENCONTR� NINGUNA VENTA O ESTA NO FUE ATENDIDA."<<endl;
        system("pause");
        return;
    }
}

bool buscarClienteAtendido(int iddetalle){
    VentaCabecera reg;
    int pos=0;
    while(reg.leerDeDisco(pos)==1){
        if(reg.getIDDetalle()==iddetalle){
            if(reg.getDNIEmpleado()>0){
                return true;
            }
        }
        pos++;
    }
    return false;
}

void buscarVenta(int iddetalle,int dniEmp){
    VentaCabecera reg;
    int pos=0;
    while(reg.leerDeDisco(pos)==1){
        if(reg.getIDDetalle()==iddetalle){
            reg.setDNIEmpleado(-2);
            reg.modificarEnDisco(pos);
        }
        pos++;
    }
}

void mostrarVentasCobradas(){
    system("cls");
    VentaCabecera reg;
    int pos=0;
    bool cantReg=false;
    cout<<"*************************"<<endl;
    cout<<"*                       *"<<endl;
    cout<<"*    VENTAS COBRADAS    *"<<endl;
    cout<<"*                       *"<<endl;
    cout<<"*************************"<<endl<<endl;
    cout<<"----------------------------------"<<endl;
    while(reg.leerDeDisco(pos)==1){
        if(reg.getDNIEmpleado()==-2){
            reg.Mostrar();
            cout<<"----------------------------------"<<endl;
            cantReg=true;
        }
        pos++;
    }
    if(cantReg==false) cout<<"NO HAY VENTAS COBRADAS."<<endl;
    system("pause");
}

void mostrarVentasCanceladas(){
    system("cls");
    VentaCabecera reg;
    int pos=0;
    bool cantReg=false;
    cout<<"***************************"<<endl;
    cout<<"*                         *"<<endl;
    cout<<"*    VENTAS CANCELADAS    *"<<endl;
    cout<<"*                         *"<<endl;
    cout<<"***************************"<<endl<<endl;
    cout<<"----------------------------------"<<endl;
    while(reg.leerDeDisco(pos)==1){
        if(reg.getDNIEmpleado()==-1){
            reg.Mostrar();
            cout<<"----------------------------------"<<endl;
            cantReg=true;
        }
        pos++;
    }
    if(cantReg==false) cout<<"NO HAY VENTAS CANCELADAS."<<endl;
    system("pause");
}
///

#endif // FUNCIONES_H_INCLUDED
