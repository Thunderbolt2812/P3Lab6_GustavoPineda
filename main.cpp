#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include "Cancion.hpp"
#include "Album.hpp"
#include "Genero.hpp"
#include "Playlist.hpp"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int main(int argc, char** argv) {
	vector<Cancion*> canciones;
	vector<Genero*> generos;
	vector<Album*> albumes;
	vector<Playlist*> playlists;
	int opcion1 = 0;
	while(opcion1!=5){
		cout << "Bem Vindo" << endl;
		cout<< "Ingrese una opcion"<<endl;
		cout<<"1) Mantenimiento"<<endl;
		cout<<"2) Operador *"<<endl;
		cout<<"3) Operador +"<<endl;
		cout<<"4) Operador -"<<endl;
		cout<<"5) Salir Corriendo"<<endl;
		cout << "Opcion: ";
    	cin >> opcion1;
    	switch(opcion1){
    		case 1:{
    			int opcion2 = 0;
    			while(opcion2!=7){
    				cout<< "Ingrese una opcion"<<endl;
					cout<<"1) Agregar Cancion"<<endl;
					cout<<"2) Modificar una Cancion"<<endl;
					cout<<"3) Eliminar una Cancion"<<endl;
					cout<<"4) Listar Canciones"<<endl;
					cout<<"5) Listar Albumes"<<endl;
					cout<<"6) Listar Playlists"<<endl;
					cout<<"7) Regresar al Menu anterior"<<endl;
					cout<<"Opcion: ";
					cin>>opcion2;
					cout<<endl;
					switch(opcion2){
						case 1:{
							string nombre,artista,duracion,genero;
							cout<<"Ingrese el nombre de la cancion: ";
							cin>>nombre;
							cout<<endl;
							cout<<"Ingrese el artista de la cancion: ";
							cin>>artista;
							cout<<endl;
							cout<<"Ingrese el genero de la cancion: ";
							cin>>genero;
							cout<<endl;
							Genero* g = new Genero(genero);
							cout<<"Ingrese la duracion de la cancion en formato (2:30): ";
							cin>>duracion;
							cout<<endl;
							canciones.push_back(new Cancion(nombre,artista,g,duracion));
							generos.push_back(g);
							break;
						}
						case 2:{
							for(int i = 0;i<canciones.size();i++){
								Cancion* aux = canciones.at(i);
								cout<<(i+1)<<") "<<aux->getNombre();
							}
							int pos;
							cout<<"Ingrese el numero de posicion de la cancion que desea modificar: ";
							cin>>pos;
							while(pos>canciones.size()||pos<=0){
								cout<<"La posicion que ingreso es invalida porfavor ingrese una posicion valida."<<endl;
								cout<<"Ingrese la posicion: ";
								cin>>pos;
							}
							int opcion3 = 0;
							while(opcion3!=5){
								cout<< "Ingrese una opcion"<<endl;
								cout<<"1) Modificar Nombre"<<endl;
								cout<<"2) Modificar Artista"<<endl;
								cout<<"3) Modificar Genero"<<endl;
								cout<<"4) Modificar Duracion"<<endl;
								cout<<"5) Regresar al Menu anterior"<<endl;
								cout<<"Opcion: ";
								cin>>opcion3;
								cout<<endl;
								switch(opcion3){
									case 1:{
										string nombre_n;
										cout<<"Ingrese el nuevo nombre de la cancion: ";
										cin>>nombre_n;
										Cancion* modi = canciones.at(pos-1);
										modi->setNombre(nombre_n);
										cout<<"Modificacion de nombre exitosa "<<endl;
										break;
									}
									case 2:{
										string artista_n;
										cout<<"Ingrese el nuevo artista de la cancion: ";
										cin>>artista_n;
										Cancion* modi = canciones.at(pos-1);
										modi->setArtistaC(artista_n);
										cout<<"Modificacion de artista exitosa "<<endl;
										cout<<endl;
										break;
									}
									case 3:{
										Genero* g2;
										bool existe = false;
										string genero_n;
										cout<<"Ingrese el nuevo genero de la cancion: ";
										cin>>genero_n;
										for(int i = 0;i<generos.size();i++){
											Genero* g1 = generos.at(i);
											string gn = g1->getNombre();
											if(gn==genero_n){
												existe = true;
												g2 = g1;
											}
										}
										if(!existe){
											Genero* nuevo_g = new Genero(genero_n);
											generos.push_back(nuevo_g);
											Cancion* modi = canciones.at(pos-1);
											modi->setGenero_c(nuevo_g);
										}else{
											Cancion* modi = canciones.at(pos-1);
											modi->setGenero_c(g2);
										}
										cout<<"Modificacion de genero exitosa "<<endl;
										cout<<endl;
										break;
									}
									case 4:{
										string duracion_n;
										cout<<"Ingrese la nueva duracion de la cancion en formato (2:30): ";
										cin>>duracion_n;
										cout<<endl;
										Cancion* modi = canciones.at(pos-1);
										modi->setDuracion(duracion_n);
										cout<<"Modificacion de Duracion exitosa"<<endl;
										break;
									}
								}
							}
							break;
						}
						case 3:{
							for(int i = 0;i<canciones.size();i++){
								Cancion* aux = canciones.at(i);
								cout<<(i+1)<<") "<<aux->getNombre();
							}
							int pos;
							cout<<"Ingrese el numero de posicion de la cancion que desea eliminar: ";
							cin>>pos;
							while(pos>canciones.size()||pos<=0){
								cout<<"La posicion que ingreso es invalida porfavor ingrese una posicion valida."<<endl;
								cout<<"Ingrese la posicion: ";
								cin>>pos;
							}
							delete canciones.at(pos-1);
							canciones.erase(canciones.begin()+(pos-1));
							break;
						}
						case 4:{
							for(int i = 0; i<canciones.size();i++){
								Cancion* cancion = canciones.at(i);
								cout<<(i+1)<<") "<<	cancion->getNombre()<<endl;
							}
							break;
						}
						case 5:{
							if(!albumes.empty()){
								for(int i = 0;i<albumes.size();i++){
									Album* A = new Album();
									string nombreA = A->getNombre();
									string artista = A->getArtistaA();
									cout<<"Nombre del Album: "<<nombreA<<setw(5)<<"Artista: "<<artista;
									for(int j =0;j<A->getCanciones().size();j++){
										Cancion* c = canciones.at(j);
										cout<<(j+1)<<") "<<c->getNombre()<<endl;
									}
									cout<<endl;
								}
							}else{
								cout<<"No hay albumes creados, porfavor cree un album primero";
								cout<<endl;
							}
							break;
						}
						case 6:{
							if(!playlists.empty()){
								for(int i = 0;i<playlists.size();i++){
									Playlist* P = playlists.at(i);
									string nombreP = P->getNombre();
									cout<<"Nombre de la Playlist: "<<nombreP<<endl<<endl;
									for(int j =0;j<P->getCanciones().size();j++){
										Cancion* c = canciones.at(j);
										cout<<(j+1)<<") "<<c->getNombre()<<endl;
									}
									cout<<endl;
								}
							}else{
								cout<<"No hay playlists creadas, porfavor cree una primero";
								cout<<endl;
							}
							break;
						}
					}
					cout<<endl;
				}
				break;
			}
			case 2:{
				bool existe = false;
				string albumd;
				if(!albumes.empty()){
					for(int i = 0;i<albumes.size();i++){
						Album* Al = albumes.at(i);;
						string nombreA = Al->getNombre();
						cout<<(i+1)<<") "<<nombreA;
					}
					cout<<"Ingrese el nombre del album que desea usar y el numero de veces que quiere agregar las canciones del album en formato (nombre*veces) (las veces tiene que ser mayor a 1): ";
					cin>>albumd;
					int veces,cont;
					string aux1,string1,stringNum;
					for(int i =0;i<albumd.length();i++){
						char aux = albumd.at(i);
						if(aux=='*'){
							string1 = aux1; 
							cont=i+1;
						}
						aux1+=aux;
						if(cont>i){
						 	stringNum+=aux;
						 	cont++;
						}
					}
					Album* Alb = new Album();
					for(int i = 0;i<albumes.size();i++){
						Album* A1 = albumes.at(i);
						string nombre = A1->getNombre();
						if(string1==nombre){
							existe = true;
							Album Alb = *A1;
						}
					}
					veces = stoi(stringNum);
					if(existe){
						Playlist* pla = new Playlist();
						*Alb = *Alb * veces;
						pla->setNombre(Alb->getNombre()+" "+stringNum+" veces");
						for(int i = 0;i<Alb->getCanciones().size();i++){
							pla->agregarCancion(Alb->getCanciones().at(i));
						}
						playlists.push_back(pla);
					}else{
						cout<<"Ese album no existe porfavor ingrese uno valido";
					}
				}else{
					cout<<"No hay almbumes creados, cree un album primero"<<endl;
				}
				break;
			}
			case 3:{
				int opcion4 = 0;
				while(opcion4!=5){
					cout<< "Ingrese una opcion"<<endl;
					cout<<"1) Playlist + Cancion"<<endl;
					cout<<"2) Playlist + Album"<<endl;
					cout<<"3) Album + Cancion"<<endl;
					cout<<"4) Playlist + Playlist"<<endl;
					cout<<"5) Regresar al Menu anterior"<<endl;
					cout<<"Opcion: ";
					cin>>opcion4;
					cout<<endl;
					switch(opcion4){
						case 1:{
							if(!canciones.empty()){
								char resp = 's';
								while(resp=='s'||resp=='S'){
									if(!playlists.empty()){
										for(int i = 0;i<playlists.size();i++){
											Playlist* aux = playlists.at(i);
											cout<<(i+1)<<") "<<aux->getNombre();
											cout<<endl;
										}
										int posp;
										cout<<"Ingrese la posicion de la playlist que desea agregarle canciones: ";
										cin>>posp;
										cout<<endl;
										Playlist* Pl = playlists.at(posp-1);
										string nombreP = Pl->getNombre();
										for(int i = 0;i<canciones.size();i++){
											Cancion* aux = canciones.at(i);
											cout<<(i+1)<<") "<<aux->getNombre();
										}
										int pos;
										cout<<"Ingrese la posicion de la cancion que desea agregar a su playlist "<<nombreP<<": ";
										cin>>pos;
										while(pos>canciones.size()||pos<=0){
											cout<<"La posicion que ingreso es invalida porfavor ingrese una posicion valida."<<endl;
											cout<<"Ingrese la posicion: ";
											cin>>pos;
										}
										Cancion* caux = canciones.at(pos-1);
										*Pl = *Pl + *caux;
										Pl->setNombre(nombreP);
										cout<<"Cancion Agregada exitosamente";
										playlists.push_back(Pl);
										cout<<"Desea agregar otra cancion a la playlist? (s/n)";
										cin>>resp;
									}else{
										string nombreP;
										cout<<"Lista de playlists vacia, cree una nueva";
										cout<<endl;
										cout<<"Ingrese el nombre de la nueva playlist: ";
										cin>>nombreP;
									}
								}
							}else{
							cout<<"Cree almenos una cancion";
							cout<<endl;
						}
						break;
					}
						case 2:{
							if(!albumes.empty()){
								if(!playlists.empty()){
									for(int i = 0;i<playlists.size();i++){
											Playlist* aux = playlists.at(i);
											cout<<(i+1)<<") "<<aux->getNombre();
										}
									int posp;
									cout<<endl;
									cout<<"Ingrese la posicion de la playlist que desea agregarle el album: ";
									cin>>posp;
									while(posp>playlists.size()||posp<=0){
										cout<<"La posicion que ingreso es invalida porfavor ingrese una posicion valida."<<endl;
										cout<<"Ingrese la posicion: ";
										cin>>posp;
									}
									Playlist* Pl = playlists.at(posp-1);
									string nombreP = Pl->getNombre();
									char resp = 's';
									cout<<endl;
									while(resp=='s'||resp=='S'){
										for(int i = 0;i<albumes.size();i++){
											Album* aux = albumes.at(i);
											cout<<(i+1)<<") "<<aux->getNombre();
										}
										int pos;
										cout<<endl;
										cout<<"Ingrese la posicion del album que desea agregar a su playlist "<<nombreP<<": ";
										cin>>pos;
										while(pos>canciones.size()||pos<=0){
											cout<<"La posicion que ingreso es invalida porfavor ingrese una posicion valida."<<endl;
											cout<<"Ingrese la posicion: ";
											cin>>pos;
										}
										Album* caux = albumes.at(pos-1);
										cout<<"Album agregado exitosamente";
										cout<<"Desea agregar otro album a la playlist? (s/n)";
										cin>>resp;
									}
								}else{
									cout<<"No hay playlists creadas asi que creara una nueva ahorita: "<<endl;
									string nombreP;
									char resp = 's';
									cout<<endl<<"Ingrese el nombre de la playlist: ";
									cin>>nombreP;
									Playlist* Pl = new Playlist();
									while(resp=='s'||resp=='S'){
										for(int i = 0;i<albumes.size();i++){
											Album* aux = albumes.at(i);
											cout<<(i+1)<<") "<<aux->getNombre();
										}
										int pos;
										cout<<"Ingrese la posicion del album que desea agregar a su playlist "<<nombreP<<": ";
										cin>>pos;
										while(pos>albumes.size()||pos<=0){
											cout<<"La posicion que ingreso es invalida porfavor ingrese una posicion valida."<<endl;
											cout<<"Ingrese la posicion: ";
											cin>>pos;
										}
										cout<<endl;
										Album* caux = albumes.at(pos-1);
										Pl->setNombre(nombreP);
										playlists.push_back(Pl);
										cout<<"Album Agregado exitosamente"<<endl;
										cout<<"Desea agregar otro album a la playlist? (s/n)";
										cin>>resp;
										cout<<endl;
									}
								}
							}else{
								cout<<"Cree almenos un album";
								cout<<endl;
							}
							break;
						}
						case 3:{
							if(!canciones.empty()){	
								if(!playlists.empty()){
									string nombreAl;
									for(int i = 0;i<albumes.size();i++){
										Album* aux = albumes.at(i);
										cout<<(i+1)<<") "<<aux->getNombre();
										cout<<endl;
									}
									int posp;
									cout<<"Ingrese la posicion del album que desea agregarle canciones: ";
									cin>>posp;
									string nombreA;
									char resp = 's';
									cout<<endl;
									Album* Al = albumes.at(posp-1);
									nombreA = Al->getNombre();
									while(resp=='s'||resp=='S'){
										for(int i = 0;i<canciones.size();i++){
											Cancion* aux = canciones.at(i);
											cout<<(i+1)<<") "<<aux->getNombre();
										}
										int pos;
										cout<<"Ingrese la posicion de la cancion que desea agregar a su album "<<nombreA<<": ";
										cin>>pos;
										while(pos>canciones.size()||pos<=0){
											cout<<"La posicion que ingreso es invalida porfavor ingrese una posicion valida."<<endl;
											cout<<"Ingrese la posicion: ";
											cin>>pos;
										}
										Cancion* caux = canciones.at(pos-1);
										*Al = *Al + *caux;
										cout<<"Cancion Agregada exitosamente";
										cout<<"Desea agregar otra cancion al Album? (s/n)";
										cin>>resp;
									}
								}else{
									cout<<"No hay albumes creados asi que creara uno nuevo ahorita: "<<endl;
									string nombreA;
									char resp = 's';
									cout<<endl<<"Ingrese el nombre del Album: ";
									cin>>nombreA;
									Album* Al = new Album();
									while(resp=='s'||resp=='S'){
										for(int i = 0;i<canciones.size();i++){
											Cancion* aux = canciones.at(i);
											cout<<(i+1)<<") "<<aux->getNombre();
											cout<<endl;
										}
										cout<<endl;
										int pos;
										cout<<"Ingrese la posicion de la cancion que desea agregar a su album "<<nombreA<<": ";
										cin>>pos;
										while(pos>canciones.size()||pos<=0){
											cout<<"La posicion que ingreso es invalida porfavor ingrese una posicion valida."<<endl;
											cout<<"Ingrese la posicion: ";
											cin>>pos;
										}
										cout<<endl;
										Cancion* caux = canciones.at(pos-1);
										*Al = *Al + *caux;
										Al->setNombre(nombreA);
										albumes.push_back(Al);
										cout<<"Cancion Agregada exitosamente"<<endl;
										cout<<"Desea agregar otra cancion al Album? (s/n)";
										cin>>resp;
										cout<<endl;
									}
								}
							}else{
								cout<<"Cree almenos una cancion";
								cout<<endl;
							}
							break;
						}
						case 4:{
							if(!playlists.empty()){
								int posp;
								for(int i = 0;i<playlists.size();i++){
									Playlist* aux = playlists.at(i);
									cout<<(i+1)<<") "<<aux->getNombre();
								}
								cout<<"Ingrese la posicion de la playlist que desea agregarle otra playlist: ";
								cin>>posp;
								string nombreP;
								char resp = 's';
								cout<<endl;
								Playlist* Pl = playlists.at(posp);
								nombreP = Pl->getNombre();
								while(resp=='s'||resp=='S'){
									for(int i = 0;i<canciones.size();i++){
										Cancion* aux = canciones.at(i);
										cout<<(i+1)<<") "<<aux->getNombre();
									}
									int pos;
									cout<<"Ingrese la posicion de la playlist que desea agregar a su playlist "<<nombreP<<": ";
									cin>>pos;
									while(pos>playlists.size()||pos<=0){
										cout<<"La posicion que ingreso es invalida porfavor ingrese una posicion valida."<<endl;
										cout<<"Ingrese la posicion: ";
										cin>>pos;
									}
									Playlist* caux = playlists.at(pos-1);
									*Pl = *Pl + *caux;
									cout<<"Cancion Agregada exitosamente";
									cout<<"Desea agregar otra cancion al Album? (s/n)";
									cin>>resp;
								}
							}
							break;
						}
					}
				}
				break;
			}
			case 4:{
				int opcion5 = 0;
				while(opcion5!=3){
					cout<<"Ingrese una opcion"<<endl;
					cout<<"1) Playlist - Cancion"<<endl;
					cout<<"2) Playlist - Genero"<<endl;
					cout<<"3) Volver al menu anterior"<<endl;
					cout<<"Opcion: ";
					cin>>opcion5;
					switch(opcion5){
						case 1:{
							bool existe = false;
							bool existe1 = false;
							string plad;
							if(!playlists.empty()){
								for(int i = 0;i<playlists.size();i++){
									Playlist* Pl = playlists.at(i);;
									string nombreP = Pl->getNombre();
									cout<<(i+1)<<") "<<nombreP;
								}
								cout<<"Ingrese el nombre de la playlist y cancion que desea eliminarle en formato (nombre*cancion): ";
								cin>>plad;
								int cont;
								string aux1,stringPlay,stringCan;
								for(int i = 0;i<plad.length();i++){
									char aux = plad.at(i);
									if(aux=='-'){
										stringPlay = aux1; 
										cont=i+1;
									}
									aux1+=aux;
									if(cont>i){
										stringCan+=aux;
									}
								}
								Playlist Play;
								for(int i = 0;i<playlists.size();i++){
									Playlist* P1 = playlists.at(i);
									string nombre = P1->getNombre();
									if(stringPlay==nombre){
										existe = true;
										Playlist Play = *P1;
									}
								}
								Cancion Can;
								for(int i = 0;i<canciones.size();i++){
									Cancion* C1 = canciones.at(i);
									string nombre = C1->getNombre();
									if(stringCan==nombre){
										existe1 = true;
										Cancion Can = *C1;
									}
								}
								if(existe){
									Play = Play - Can;
								}else{
									cout<<"Ese album no existe porfavor ingrese uno valido";
								}
							}else{
								cout<<"No hay playlists creadas, cree una playlist primero"<<endl;
							}
							break;
						}
						case 2:{
							bool existe = false;
							bool existe1 = false;
							string plad;
							if(!playlists.empty()){
								for(int i = 0;i<playlists.size();i++){
									Playlist* Pl = playlists.at(i);;
									string nombreP = Pl->getNombre();
									cout<<(i+1)<<") "<<nombreP;
								}
								cout<<"Ingrese el nombre de la playlist y genero que desea eliminarle en formato (nombre-genero): ";
								cin>>plad;
								int cont;
								string aux1,stringPlay,stringGenero;
								for(int i = 0;i<plad.length();i++){
									char aux = plad.at(i);
									if(aux=='-'){
										stringPlay = aux1; 
										cont=i+1;
									}
									aux1+=aux;
									if(cont>i){
										stringGenero+=aux;
									}
								}
								Playlist Play;
								for(int i = 0;i<playlists.size();i++){
									Playlist* P1 = playlists.at(i);
									string nombre = P1->getNombre();
									if(stringPlay==nombre){
										existe = true;
										Playlist Play = *P1;
									}
								}
								Genero Gen;
								for(int i = 0;i<generos.size();i++){
									Genero* G1 = generos.at(i);
									string nombre = G1->getNombre();
									if(stringGenero==nombre){
										existe1 = true;
										Genero Gen = *G1;
									}
								}
								if(existe&&existe1){
									Play = Play - Gen;
								}else{
									cout<<"Ese album no existe porfavor ingrese uno valido";
								}
							}else{
								cout<<"No hay playlists creadas, cree una playlist primero"<<endl;
							}
							break;
						}
					}
			 	}
			 	break;
			}
		}
	}
	for(int i = 0;i<canciones.size();i++){
		delete canciones.at(i);
	}	
	for(int i = 0;i<generos.size();i++){
		delete generos.at(i);
	}		
	for(int i = 0;i<albumes.size();i++){
    	delete albumes.at(i);
	}
	for(int i = 0;i<playlists.size();i++){
    	delete playlists.at(i);
	}
    cout<<endl;
	return 0;
}