
#include <iostream>
#include <vector>
using namespace std;

//como si fuera la inyectable
class Ilistable{
	public:
		virtual void iniciar(string *texto) = 0;
		virtual void terminar(string *texto)= 0;
		virtual void agregarElementos(string *texto, vector<string> lista)= 0;
};

//creacion de diferentes dosis

class FormateadorPorVinetas : public Ilistable
{
	public:
		void iniciar(string *texto)
		{
			
		}
		void terminar(string *texto)
		{
			
		}
		void agregarElementos(string *texto, vector<string> lista){
			
			//cout<<"listando";
			for(int i = 0; i< lista.size(); i++)
			{
				//texto =  texto +  vector[i];
				texto->append("\n\t * ");
				texto->append(lista[i]);
				
			}
		}
};

class FormateadorHTML : public Ilistable
{
	public:
		 void iniciar(string *texto)
		{
			//cout<<"iniciando";
			texto->append("\n<ul>");
		}
		void terminar(string *texto)
		{
			//cout<<"culminando";
			texto->append("\n</ul>");
		}
		 void agregarElementos(string *texto, vector<string> lista){
			
			//cout<<"listando";
			for(int i = 0; i< lista.size(); i++)
			{
				texto->append("\n\t<li> ");
				texto->append(lista[i]);
				texto->append(" </li> ");
					
			}
		}
};

class ProcesadorTexto{
	public:
		Ilistable *listador; //es la herramienta inyectable
		string texto;
		ProcesadorTexto(Ilistable *inye)
		{
			listador = inye;
			texto = "";
		}
		
		
		
		void formatearLista(vector<string> lista)
		{
			
			listador->iniciar(&texto);
			
			listador->agregarElementos(&texto,lista);
			
			listador->terminar(&texto);
		}
		
		void agregarLista(vector<string> lista)
		{
			
		}
		
		void limpiar()
		{
			texto.clear();
		}
		
		void imprimir(){
			cout<<texto;
		}
		
};



int main(int argc, char *argv[]) {
	
	
	FormateadorHTML *fhtml = new FormateadorHTML();
	FormateadorPorVinetas *fpv = new FormateadorPorVinetas();
	
//	ProcesadorTexto *pt1;
//	pt1 = new ProcesadorTexto(fhtml);
	ProcesadorTexto pt1(fpv);
	//pt1.listador = fpv;
	
	vector<string> elementos;
	elementos.push_back("Programacion Avanzada");
	elementos.push_back("Estructura de Datos");
	elementos.push_back("Base de datos");
	
	pt1.formatearLista(elementos);
	pt1.imprimir();
	
	return 0;
}

