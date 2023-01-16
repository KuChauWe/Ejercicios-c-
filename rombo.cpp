#include <iostream>

using namespace std;

void piramide_1(char letra1, char letra2);
void piramide_2(char letra1, char letra2);
void pedirLetras();


int main(){

	pedirLetras();
	
	return 0;
}

void pedirLetras(){
	char letra1, letra2;
	int x, y;
	
		
	do{
		cout<<"Letra de inicio rombo --> "; cin>>letra1;
	    cout<<"Letra intermedia del rombo -->"; cin>>letra2;
	    x=letra1;
	    y=letra2;
	}while((x>y) || (x<65) || (y>90));
	
	piramide_1(letra1,letra2);
    piramide_2(letra1,letra2);
}

void piramide_1(char letra1, char letra2){
	char aux;
	int a=letra1, b=letra2;  //pasar a su numero correspodiente en codigo ASCII
	int i, j, k, cont=0, cont2=(b-a), cont3=1;  //contadores 
	
	for(i=a; i<=b; i++){
		aux=a+cont;       //numero de asignacio ASCII
		
		for(k=cont2; k>=0; k--){ 
			cout<<" ";   //impresion de espacios
		}
		if(cont==0){
			cout<<aux;
		}
		else{
			for(j=1; j<=cont3; j++){
			cout<<aux;   //imprimir letras
		    }
		}
		cont2-=1;    //decremento al contador para que redusca los espacios
		cont+=1;     //aumnetando contador para que cambie de letra el aux
		cont3+=2;    //contador3 aumeta en 2 para que la piramide quede centrada
		cout<<endl;
	}
	
}

void piramide_2(char letra1, char letra2){
	char aux;
	int a=letra1, b=letra2-1;  //le restamos 1 para que no se repita la ultima letra
	int i, j, k, cont=(b-a), cont2=0,cont3;  //en este caso se intercambio el valor de cont y cont2
	
	for(i=b; i>=a; i--){
		aux=a+cont;       //numero de asignacio ASCII
		
		for(k=0; k<=cont2+1; k++){ //se incremento un espacio
			cout<<" ";   //impresion de espacios
		}
		if(cont==0){
			cout<<aux;
		}
		else{
			for(j=5; j<=cont3; j++){ //se inicializo el contador en 5
			cout<<aux;   //imprimir letras
		    }
		}
		cont2+=1;    //decremento al contador para que redusca los espacios
		cont-=1;     //aumnetando contador para que cambie de letra el aux
		cont3-=2;    //contador3 aumeta en 2 para que la piramide quede centrada
		cout<<endl;
	}
