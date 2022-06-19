#ifndef VENTA_H_INCLUDED
#define VENTA_H_INCLUDED

void cargarCadena(char *pal,int tam){
    int i;
    fflush(stdin);
    for(i=0;i<tam;i++){
        pal[i]=cin.get();
        if(pal[i]=='\n') break;
    }
    pal[i]='\0';
    fflush(stdin);
}

class VentaCabecera{
    private:
        int IDVenta;
        int DNICliente;
        int DNIEmpleado;
        Fecha fecha;
        float importe;
    public:
        int getIDVenta(){return IDVenta;}
        int getDNICliente(){return DNICliente;}
        int getDNIEmpleado(){return DNIEmpleado;}
        Fecha getFecha(){return fecha;}
        float getImporte(){return importe;}

        void setIDVenta(int idv){IDVenta=idv;}
        void setDNICliente(int dnic){DNICliente=dnic;}
        void setDNIEmpleado(int dnie){DNIEmpleado=dnie;}
        void setFecha(Fecha f){fecha=f;}
        void setImporte(float i){importe=i;}

        void Cargar(int,int);
        void Mostrar();

        int grabarEnDisco();
        int modificarEnDisco(int);
        int leerDeDisco(int);
};

void VentaCabecera::Cargar(int idv,int dni){
    cout<<"ID DE VENTA: ";
    IDVenta=idv;
    cout<<IDVenta<<endl;
    cout<<"DNI DEL CLIENTE: ";
    DNICliente=dni;
    cout<<DNICliente<<endl;
    cout<<"DNI DEL EMPLEADO: ";
    DNIEmpleado=0;
    cout<<DNIEmpleado<<endl;
    cout<<"FECHA: ";
    fecha.Cargar();
}

void VentaCabecera::Mostrar(){
    cout<<"ID DE VENTA: "<<IDVenta<<endl;
    cout<<"DNI DEL CLIENTE: "<<DNICliente<<endl;
    cout<<"DNI DEL EMPLEADO: "<<DNIEmpleado<<endl;
    cout<<"FECHA: ";
    fecha.Mostrar();
    cout<<"IMPORTE: $"<<importe<<endl;
}

int VentaCabecera::grabarEnDisco(){
    FILE *p;
    p=fopen("ventaCabecera.dat", "ab");
    if(p==NULL) return -1;
    int escribio=fwrite(this,sizeof(VentaCabecera),1,p);
    fclose(p);
    return escribio;
}

int VentaCabecera::modificarEnDisco(int pos){
    FILE *p;
    p = fopen("ventaCabecera.dat", "rb+");
    if(p==NULL) return -1;
    fseek(p, sizeof(VentaCabecera)*pos,0);
    int escribio = fwrite(this, sizeof(VentaCabecera), 1, p);
    fclose(p);
    return escribio;
}

int VentaCabecera::leerDeDisco(int pos){
    FILE *p;
    p=fopen("ventaCabecera.dat", "rb");
    if(p==NULL) return -1;
    fseek(p,sizeof(VentaCabecera)*pos,0);
    int leyo=fread(this,sizeof(VentaCabecera),1,p);
    fclose(p);
    return leyo;
}

class VentaDetalle{
    private:
        char IDPlato[6];
        int IDVenta;
        int dniCliente;
        int cantidad;
        float importe;
        bool estado;
    public:
        const char *getIDPlato(){return IDPlato;}
        int getIDVenta(){return IDVenta;}
        int getDNIcliente(){return dniCliente;}
        int getCantidad(){return cantidad;}
        float getImporte(){return importe;}
        bool getEstado(){return estado;}

        void setIDPlato(const char *idp){strcpy(IDPlato,idp);}
        void setIDVenta(int idv){IDVenta=idv;}
        void setDNIcliente(int dnic){dniCliente=dnic;}
        void setCantidad(int c){cantidad=c;}
        void setImporte(float i){importe=i;}
        void setEstado(bool e){estado=e;}

        void Cargar(int,int,const char *,int,float);
        void Mostrar();

        int grabarEnDisco();
        int modificarEnDisco(int);
        int leerDeDisco(int);
};

void VentaDetalle::Cargar(int idv,int dnicl,const char *codPlat,int cant,float imp){
    IDVenta=idv;
    dniCliente=dnicl;
    strcpy(IDPlato,codPlat);
    cantidad=cant;
    importe=imp;
    estado=true;
}

void VentaDetalle::Mostrar(){
    cout<<"ID DE VENTA: "<<IDVenta<<endl;
    cout<<"DNI DEL CLIENTE: "<<dniCliente<<endl;
    cout<<"ID DE PLATO: "<<IDPlato<<endl;
    cout<<"CANTIDAD: "<<cantidad<<endl;
    cout<<"IMPORTE: $"<<importe<<endl;
}

int VentaDetalle::grabarEnDisco(){
    FILE *p;
    p=fopen("ventaDetalle.dat", "ab");
    if(p==NULL) return -1;
    int escribio=fwrite(this,sizeof(VentaDetalle),1,p);
    fclose(p);
    return escribio;
}

int VentaDetalle::modificarEnDisco(int pos){
    FILE *p;
    p = fopen("ventaDetalle.dat", "rb+");
    if(p==NULL) return -1;
    fseek(p, sizeof(VentaDetalle)*pos,0);
    int escribio = fwrite(this, sizeof(VentaDetalle), 1, p);
    fclose(p);
    return escribio;
}

int VentaDetalle::leerDeDisco(int pos){
    FILE *p;
    p=fopen("ventaDetalle.dat", "rb");
    if(p==NULL) return -1;
    fseek(p,sizeof(VentaDetalle)*pos,0);
    int leyo=fread(this,sizeof(VentaDetalle),1,p);
    fclose(p);
    return leyo;
}

#endif // VENTA_H_INCLUDED
