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

bool buscarTipo(int,const char *);

void menuAdmin();
void crearEmpleado();

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

void eliminarPlato();

void restablecerPlato();
///


///MENU EMPLEADOS
void menuEmpleados(int);

void mostrarEmpleadosRegistrados();

void mostrarClientesRegistrados();

void reportes();
///


///MENU CLIENTES
void menuCliente();

void registrarCliente();

void crearPedido(int);
int generarIDVenta();
void traerPlato();
int chequearStock(const char *,int);
float importePlato(const char *,int);
void disminuirStock(const char *,int);

void cancelarPedido(int);

///


///MENU VENTAS Y PEDIDOS
void menuVentasPedidos();

void menuVentasCliente(int);
void mostrarPedido(int);

void mostrarVentas();
bool clienteNoAtendido(int);
int traerCliente(int);
void atenderCliente(int);
void atenderAlCliente(int,int);

void cobrarVentas(int);
int buscarVenta(int,int);

void mostrarVentasCobradas();
///


///FUNCIONES GLOBALES
bool buscarPlato(const char *codPlat){
    Plato reg;
    int pos=0;
    while(reg.leerDeDisco(pos)){
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
    while(reg.leerDeDisco(pos)){
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
    while(reg.leerDeDisco(pos)){
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
    while(reg.leerDeDisco(pos)){
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
    while(reg.leerDeDisco(pos)){
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
    while(reg.leerDeDisco(pos)){
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
    while(reg.leerDeDisco(pos)){
        if(strcmp(reg.getContrasenia(),contrasenia)==0){
            return true;
        }
        pos++;
    }
    return false;
}

bool buscarTipo(int dni,const char *contrasenia){
    Admin reg;
    int pos=0;
    while(reg.leerDeDisco(pos)){
        if(reg.getDNI()==dni && strcmp(reg.getContrasenia(),contrasenia)==0){
            if(reg.getTipo()==1){
                return true;
            }
        }
        pos++;
    }
    return false;
}

void crearEmpleado(){
    system("cls");
    Empleado reg;
    int pos=0,tipo=2,dni;
    bool existeEmpleado=false;
    cout<<"**************************"<<endl;
    cout<<"*   REGISTRAR EMPLEADO   *"<<endl;
    cout<<"**************************"<<endl<<endl;
    cout<<"DNI: ";
    cin>>dni;
    if(dni==0){
        return;
    }
    while(reg.leerDeDisco(pos)){
        if(reg.getDNI()==dni){
            existeEmpleado=true;
        }
        pos++;
    }
    if(existeEmpleado==false){
        reg.Cargar(tipo);
        reg.setDNI(dni);
        reg.grabarEnDisco();
    }
    else{
        cout<<"EL EMPLEADO YA EXISTE."<<endl;
        system("pause");
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
        while(reg.leerDeDisco(pos)){
            if(strcmp(reg.getCodigoPlato(),codPlat)==0){
                if(reg.getEstado()==1){
                    reg.Mostrar();
                    cout<<"----------------------------------"<<endl;
                }
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
    cout<<"----------------------------------"<<endl;
    while(reg.leerDeDisco(pos)){
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
            while(reg.leerDeDisco(pos)){
                if(reg.getEstado()==true){
                    reg.Mostrar();
                    cout<<"----------------------------------"<<endl;
                }
                pos++;
            }
            pos=0;
            cout<<"CÓDIGO DE PLATO: ";
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
                while(reg.leerDeDisco(pos)){
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
                cout<<"EL PLATO NO EXISTE O EL CÓDIGO NO ES CORRECTO."<<endl;
                agregar=false;
                system("pause");
            }
        }
        cout<<"¿QUIÉRE MODIFICAR ALGO MÁS? SI(1)/NO(0)"<<endl;
        cin>>opc;
        switch(opc){
            case 1: pos=0;
                    agregar=true;
                break;
            case 0: return;
                break;
            default: cout<<"OPCIÓN INCORRECTA."<<endl;
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
    while(reg.leerDeDisco(pos)){
        reg.Mostrar();
        cout<<"----------------------------------"<<endl;
        pos++;
    }
    cout<<"CÓDIGO DE PLATO: ";
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
        cout<<"EL PLATO NO EXISTE O EL CÓDIGO NO ES CORRECTO."<<endl;
        system("pause");
    }
}

void cambiarNombre(const char *codPlat,const char *nuevoNombre){
    Plato reg;
    int pos=0;
    while(reg.leerDeDisco(pos)){
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
    cout<<"*    MODIFICAR DESCRIPCIÓN    *"<<endl;
    cout<<"*                             *"<<endl;
    cout<<"*******************************"<<endl<<endl;
    while(reg.leerDeDisco(pos)){
        reg.Mostrar();
        cout<<"----------------------------------"<<endl;
        pos++;
    }
    cout<<"CÓDIGO DE PLATO: ";
    cargarCadena(codPlat,5);
    existePlato=buscarPlato(codPlat);
    if(existePlato==true){
        pos=0;
        cout<<"NUEVA DESCRIPCIÓN PARA EL PLATO: ";
        cargarCadena(nuevaDescrip,29);
        cambiarDescripcion(codPlat,nuevaDescrip);
        cout<<endl;
        cout<<"<<<DESCRIPCIÓN MODIFICADA.>>>"<<endl;
    }
    else{
        cout<<"EL PLATO NO EXISTE O EL CÓDIGO NO ES CORRECTO."<<endl;
        system("pause");
    }
}

void cambiarDescripcion(const char *codPlat,const char *nuevaDescrip){
    Plato reg;
    int pos=0;
    while(reg.leerDeDisco(pos)){
        if(strcmp(reg.getCodigoPlato(),codPlat)==0){
            reg.setDescripcion(nuevaDescrip);
            reg.modificarEnDisco(pos);
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
    while(reg.leerDeDisco(pos)){
        if(reg.getEstado()==true){
            reg.Mostrar();
            cout<<"----------------------------------"<<endl;
            cantReg++;
        }
        pos++;
    }
    if(cantReg>0){
        cout<<"CÓDIGO DE PLATO: ";
        cargarCadena(codPlat,5);
        existePlato=buscarPlato(codPlat);
        if(existePlato==true){
            pos=0;
            while(reg.leerDeDisco(pos)){
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
            cout<<"EL CÓDIGO NO EXISTE O NO ES CORRECTO."<<endl;
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
    while(reg.leerDeDisco(pos)){
        if(reg.getEstado()==false){
            reg.Mostrar();
            cout<<"----------------------------------"<<endl;
            cantReg++;
        }
        pos++;
    }
    if(cantReg>0){
        cout<<"CÓDIGO DE PLATO: ";
        cargarCadena(codPlat,5);
        existePlato=buscarPlato(codPlat);
        if(existePlato==true){
            pos=0;
            while(reg.leerDeDisco(pos)){
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
            cout<<"EL PLATO NO EXISTE O EL CÓDIGO NO ES CORRECTO."<<endl;
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
    while(reg.leerDeDisco(pos)){
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
    while(reg.leerDeDisco(pos)){
        if(reg.getEstado()==true){
            reg.Mostrar();
            cout<<"----------------------------------"<<endl;
        }
        pos++;
    }
    system("pause");
}

void reportes(){

}
///


///MENU CLIENTES
void registrarCliente(){
    system("cls");
    Cliente reg;
    int dni,tipo=3;
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
        reg.Cargar(tipo);
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
    int idventa=0,otroPedido=1,opc,cantidad,numeroGrande;
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
        sacarStock=false;
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
                                aux.Cargar(idventa,dniCliente,codPlat,cantidad,importe);
                                aux.grabarEnDisco();
                                repetir=true;
                                sacarStock=true;
                            }
                        }
                    }
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
                                aux.setIDVenta(idventa);
                                aux.setCantidad(cantidad);
                                aux.setImporte(importe);
                                aux.grabarEnDisco();
                                pedido=false;
                                sacarStock=true;

                            }
                        }
                    }
                }
                else{
                    cout<<"EL CÓDIGO DE PLATO NO ES CORRECTO."<<endl;
                    system("pause");
                }
            }
        }
        system("cls");
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
    while(reg.leerDeDisco(pos)){
        idventa++;
        pos++;
    }
    return idventa;
}

void traerPlato(){
    Plato reg;
    int pos=0;
    while(reg.leerDeDisco(pos)){
        if(reg.getEstado()==1){
            reg.Mostrar();
            cout<<"----------------------------------"<<endl;
        }
        pos++;
    }
}

int chequearStock(const char *codPlat,int cantidad){
    Plato reg;
    int pos=0,restarCant;
    while(reg.leerDeDisco(pos)){
        if(strcmp(reg.getCodigoPlato(),codPlat)==0){
            cout<<reg.getStock()<<endl;
            cout<<cantidad<<endl;
            restarCant=reg.getStock()-cantidad;
            cout<<restarCant<<endl;
            return restarCant;
        }
        pos++;
    }
}

float importePlato(const char *codPlat,int cantidad){
    Plato reg;
    int pos=0;
    float importe;
    while(reg.leerDeDisco(pos)){
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
    while(reg.leerDeDisco(pos)){
        if(strcmp(reg.getCodigoPlato(),codPlat)==0){
            totalStock=reg.getStock()-cantidad;
            reg.setStock(totalStock);
            reg.modificarEnDisco(pos);
        }
        pos++;
    }
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
        while(reg.leerDeDisco(pos)){
            if(reg.getDNICliente()==dni){
                reg.Mostrar();
                cout<<"----------------------------------"<<endl;
                leerRegistro++;
                pos++;
            }
            pos++;
        }
        if(leerRegistro==0){
            cout<<"EL CLIENTE NO TIENE NINGÚN PEDIDO."<<endl;
            return;
        }
        else{
            cout<<"ID DE VENTA: ";
            cin>>idventa;
            if(idventa==0){
                cout<<"<<<OPERACIÓN CANCELADA>>>"<<endl;
                return;
            }
            pos=0;
            while(reg.leerDeDisco(pos)){
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
    while(reg.leerDeDisco(pos)){
        if(reg.getDNICliente()==dni){
            reg.Mostrar();
            cout<<"----------------------------------"<<endl;
        }
        pos++;
    }
    pos=0;
    while(reg.leerDeDisco(pos)){
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
    while(reg.leerDeDisco(pos)){
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
    while(reg.leerDeDisco(pos)){
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
    while(reg.leerDeDisco(pos)){
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
    while(reg.leerDeDisco(pos)){
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
    while(reg.leerDeDisco(pos)){
        if(reg.getDNICliente()==dniCliente){
            reg.setDNIEmpleado(dniEmp);
            reg.modificarEnDisco(pos);
        }
        pos++;
    }
}

void cobrarVentas(int dniEmp){
    system("cls");
    VentaDetalle reg;
    int pos=0,dniCliente,idDeVenta;
    bool existeCliente;
    cout<<"*********************************"<<endl;
    cout<<"*                               *"<<endl;
    cout<<"*         COBRAR VENTAS         *"<<endl;
    cout<<"*                               *"<<endl;
    cout<<"*********************************"<<endl<<endl;
    cout<<"----------------------------------"<<endl;
    while(reg.leerDeDisco(pos)){
        if(reg.getEstado()==true){
            reg.Mostrar();
            cout<<"----------------------------------"<<endl;
        }
        pos++;
    }
    cout<<"ELIJA EL DNI DEL CLIENTE A COBRAR: ";
    cin>>dniCliente;
    existeCliente=buscarCliente(dniCliente);
    if(existeCliente==true){
        cout<<endl;
        idDeVenta=buscarVenta(dniCliente,dniEmp);
        if(idDeVenta==-1){
            return;
        }
        pos=0;
        while(reg.leerDeDisco(pos)){
            if(reg.getIDVenta()==idDeVenta){
                reg.setEstado(false);
                reg.modificarEnDisco(pos);
            }
            pos++;
        }
        cout<<"<<<LA VENTA SE COBRÓ CON ÉXITO>>>"<<endl;
        system("pause");
    }
    else{
        cout<<"EL CLIENTE NO EXISTE O EL DNI NO ES CORRECTO."<<endl;
        system("pause");
    }
}

int buscarVenta(int dniCliente,int dniEmp){
    system("cls");
    VentaCabecera reg;
    int pos=0,idventa,cantReg=0;
    while(reg.leerDeDisco(pos)){
        if(reg.getDNICliente()==dniCliente){
            if(reg.getDNIEmpleado()==dniEmp){
                reg.Mostrar();
                cout<<"----------------------------------"<<endl;
                cantReg++;
            }
        }
        pos++;
    }
    if(cantReg==0){
        cout<<"NO HAY REGISTROS O LOS CLIENTES NO ESTÁN ATENDIDOS."<<endl;
        system("pause");
        return -1;
    }
    else{
        cout<<"ESCOJA EL ID DE VENTA A COBRAR: ";
        cin>>idventa;
        pos=0;
        while(reg.leerDeDisco(pos)){
            if(reg.getIDVenta()==idventa){
                reg.setDNIEmpleado(-2);
                reg.modificarEnDisco(pos);
                return idventa;
            }
            pos++;
        }
    }
}

void mostrarVentasCobradas(){
    system("cls");
    VentaDetalle reg;
    VentaCabecera aux;
    int pos1=0,pos2=0,cantReg=0;
    cout<<"*********************************"<<endl;
    cout<<"*                               *"<<endl;
    cout<<"*    MOSTRAR VENTAS COBRADAS    *"<<endl;
    cout<<"*                               *"<<endl;
    cout<<"*********************************"<<endl<<endl;
    cout<<"----------------------------------"<<endl;
    while(reg.leerDeDisco(pos1)){
        if(reg.getEstado()==false){
            while(aux.leerDeDisco(pos2)){
                if(aux.getDNIEmpleado()==-2){
                    reg.Mostrar();
                    cout<<"----------------------------------"<<endl;
                    cantReg++;
                }
                pos2++;
            }
        }
        pos1++;
        pos2=0;
    }
    if(cantReg==0) cout<<"NO HAY VENTAS COBRADAS."<<endl;
    system("pause");
}
///

#endif // FUNCIONES_H_INCLUDED
