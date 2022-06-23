#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED

///CLIENTE
class Cliente{
    protected:
        int dni;
        char nombre[30];
        char apellido[30];
        char contrasenia[9];
        int tipo;
        bool estado;
    public:
        int getDNI(){return dni;}
        const char *getNombre(){return nombre;}
        const char *getApellido(){return apellido;}
        const char *getContrasenia(){return contrasenia;}
        int getTipo(){return tipo;}
        bool getEstado(){return estado;}

        void setDNI(int d){dni=d;}
        void setNombre(const char *n){strcpy(nombre,n);}
        void setApellido(const char *a){strcpy(apellido,a);}
        void setContrasenia(const char *c){strcpy(contrasenia,c);}
        void setTipo(int t){tipo=t;}
        void setEstado(bool e){estado=e;}

        void Cargar(int);
        void Mostrar();

        int grabarEnDisco();
        int leerDeDisco(int);
};

void Cliente::Cargar(int tip){
    cout<<"NOMBRE: ";
    cargarCadena(nombre,29);
    cout<<"APELLIDO: ";
    cargarCadena(apellido,29);
    cout<<"CONTRASEÑA: ";
    cargarCadena(contrasenia,14);
    tipo=tip;
    estado=true;
}

void Cliente::Mostrar(){
    cout<<"DNI: "<<dni<<endl;
    cout<<"NOMBRE: "<<nombre<<endl;
    cout<<"APELLIDO: "<<apellido<<endl;
    cout<<"TIPO: "<<tipo<<endl;
    cout<<"ESTADO: "<<estado<<endl;
}

int Cliente::leerDeDisco(int pos){
    FILE *p;
    p=fopen("cliente.dat", "rb");
    if(p==NULL) return -1;
    fseek(p, sizeof(Cliente)*pos,0);
    int leyo=fread(this, sizeof *this,1, p);
    fclose(p);
    return leyo;
}

int Cliente::grabarEnDisco(){
    FILE *p;
    p=fopen("cliente.dat", "ab");
    if(p==NULL) return -1;
    int grabo=fwrite(this, sizeof *this,1, p);
    fclose(p);
    return grabo;
}

///EMPLEADO
class Empleado:public Cliente{
    public:
        int grabarEnDisco();
        int leerDeDisco(int);
};

int Empleado::leerDeDisco(int pos){
    FILE *p;
    p=fopen("empleado.dat", "rb");
    if(p==NULL) return -1;
    fseek(p, sizeof(Empleado)*pos,0);
    int leyo=fread(this, sizeof *this,1, p);
    fclose(p);
    return leyo;
}

int Empleado::grabarEnDisco(){
    FILE *p;
    p=fopen("empleado.dat", "ab");
    if(p==NULL) return -1;
    int grabo=fwrite(this, sizeof *this,1, p);
    fclose(p);
    return grabo;
}

class Admin:public Cliente{
    public:
        int grabarEnDisco();
        int leerDeDisco(int);
};

int Admin::leerDeDisco(int pos){
    FILE *p;
    p=fopen("admin.dat", "rb");
    if(p==NULL) return -1;
    fseek(p, sizeof(Admin)*pos,0);
    int leyo=fread(this, sizeof *this,1, p);
    fclose(p);
    return leyo;
}

int Admin::grabarEnDisco(){
    FILE *p;
    p=fopen("admin.dat", "ab");
    if(p==NULL) return -1;
    int grabo=fwrite(this, sizeof *this,1, p);
    fclose(p);
    return grabo;
}
#endif // PERSONA_H_INCLUDED
