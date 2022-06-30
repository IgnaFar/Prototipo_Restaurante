#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED

///CLIENTE
class Cliente{
    protected:
        int dni;
        char nombre[30];
        char apellido[30];
        char contrasenia[9];
        char telefono[15];
        bool estado;
    public:
        int getDNI(){return dni;}
        const char *getNombre(){return nombre;}
        const char *getApellido(){return apellido;}
        const char *getContrasenia(){return contrasenia;}
        const char *getTelefono(){return telefono;}
        bool getEstado(){return estado;}

        void setDNI(int d){dni=d;}
        void setNombre(const char *n){strcpy(nombre,n);}
        void setApellido(const char *a){strcpy(apellido,a);}
        void setContrasenia(const char *c){strcpy(contrasenia,c);}
        void setTelefono(const char *t){strcpy(telefono,t);}
        void setEstado(bool e){estado=e;}

        void CargarCliente();
        void MostrarCliente();

        int grabarEnDisco();
        int modificarEnDisco(int);
        int leerDeDisco(int);
};

void Cliente::CargarCliente(){
    cout<<"NOMBRE: ";
    cargarCadena(nombre,29);
    cout<<"APELLIDO: ";
    cargarCadena(apellido,29);
    cout<<"CONTRASEÑA: ";
    cargarCadena(contrasenia,14);
    cout<<"TELÉFONO: ";
    cargarCadena(telefono,14);
    estado=true;
}

void Cliente::MostrarCliente(){
    cout<<"DNI: "<<dni<<endl;
    cout<<"NOMBRE: "<<nombre<<endl;
    cout<<"APELLIDO: "<<apellido<<endl;
    cout<<"CONTRASEÑA: "<<contrasenia<<endl;
    cout<<"TELÉFONO: "<<telefono<<endl;
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

int Cliente::modificarEnDisco(int pos){
    FILE *p;
    p=fopen("cliente.dat", "rb+");
    if(p==NULL) return -1;
    fseek(p, sizeof(Cliente)*pos,0);
    int grabo=fwrite(this, sizeof *this,1, p);
    fclose(p);
    return grabo;
}

///EMPLEADO
class Empleado:public Cliente{
    private:
        int telefonoRestaurante;
    public:
        int getTelefonoRestaurante(){return telefonoRestaurante;}

        void setTelefonoRestaurnte(int tr){telefonoRestaurante=tr;}

        void CargarEmpleado();
        void MostrarEmpleado();
        void MostrarEmpleadoLogeado();

        int grabarEnDisco();
        int modificarEnDisco(int);
        int leerDeDisco(int);
};

void Empleado::CargarEmpleado(){
    cout<<"NOMBRE: ";
    cargarCadena(nombre,29);
    cout<<"APELLIDO: ";
    cargarCadena(apellido,29);
    cout<<"CONTRASEÑA: ";
    cargarCadena(contrasenia,14);
    telefonoRestaurante=102453869;
    estado=true;
}

void Empleado::MostrarEmpleado(){
    cout<<"DNI: "<<dni<<endl;
    cout<<"NOMBRE: "<<nombre<<endl;
    cout<<"APELLIDO: "<<apellido<<endl;
    cout<<"CONTRASEÑA: "<<contrasenia<<endl;
    cout<<"TELÉFONO: "<<telefonoRestaurante<<endl;
    cout<<"ESTADO: "<<estado<<endl;
}

void Empleado::MostrarEmpleadoLogeado(){
    cout<<"       "<<nombre<<" "<<apellido<<endl;
}

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

int Empleado::modificarEnDisco(int pos){
    FILE *p;
    p=fopen("empleado.dat", "rb+");
    if(p==NULL) return -1;
    fseek(p, sizeof(Empleado)*pos,0);
    int grabo=fwrite(this, sizeof *this,1, p);
    fclose(p);
    return grabo;
}

class Admin:public Cliente{
    public:
        void MostrarAdmin();

        int grabarEnDisco();
        int leerDeDisco(int);
};

void Admin::MostrarAdmin(){
    cout<<"DNI: "<<dni<<endl;
    cout<<"NOMBRE: "<<nombre<<endl;
    cout<<"APELLIDO: "<<apellido<<endl;
    cout<<"CONTRASEÑA: "<<contrasenia<<endl;
    cout<<"ESTADO: "<<estado<<endl;
}

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
