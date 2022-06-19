#ifndef PLATO_H_INCLUDED
#define PLATO_H_INCLUDED

class Plato{
    private:
        char codigoPlato[6];
        char nombre[30];
        char descripcion[30];
        float precio;
        bool estado;
    public:
        const char *getCodigoPlato(){return codigoPlato;}
        const char *getNombre(){return nombre;}
        const char *getDescripcion(){return descripcion;}
        float getPrecio(){return precio;}
        bool getEstado(){return estado;}

        void setCodigoPlato(const char *cod){strcpy(codigoPlato,cod);}
        void setNombre(const char *n){strcpy(nombre,n);}
        void setDescripcion(const char *d){strcpy(descripcion,d);}
        void setPrecio(float p){precio=p;}
        void setEstado(bool e){estado=e;}

        void Cargar();
        void Mostrar();

        int grabarEnDisco();
        int modificarEnDisco(int);
        int leerDeDisco(int);
};

void Plato::Cargar(){
    cout<<"NOMBRE DEL PLATO: ";
    cargarCadena(nombre,29);
    cout<<"DESCRIPCION DEL PLATO: ";
    cargarCadena(descripcion,29);
    cout<<"PRECIO DEL PLATO: $";
    cin>>precio;
    estado=true;
}

void Plato::Mostrar(){
    cout<<"CODIGO DE PLATO: "<<codigoPlato<<endl;
    cout<<"NOMBRE DEL PLATO: "<<nombre<<endl;
    cout<<"DESCRIPCION DEL PLATO: "<<descripcion<<endl;
    cout<<"PRECIO DEL PLATO: $"<<precio<<endl;
    cout<<"ESTADO: "<<estado<<endl;
}

int Plato::grabarEnDisco(){
    FILE *p;
    p=fopen("plato.dat", "ab");
    if(p==NULL) return -1;
    int escribio=fwrite(this,sizeof(Plato),1,p);
    fclose(p);
    return escribio;
}

int Plato::modificarEnDisco(int pos){
    FILE *p;
    p = fopen("plato.dat", "rb+");
    if(p==NULL) return -1;
    fseek(p, sizeof(Plato)*pos,0);
    int escribio = fwrite(this, sizeof(Plato), 1, p);
    fclose(p);
    return escribio;
}

int Plato::leerDeDisco(int pos){
    FILE *p;
    p=fopen("plato.dat", "rb");
    if(p==NULL) return -1;
    fseek(p,sizeof(Plato)*pos,0);
    int leyo=fread(this,sizeof(Plato),1,p);
    fclose(p);
    return leyo;
}

#endif // PLATO_H_INCLUDED
