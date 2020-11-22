/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: esauzavaleta
 *
 */

int creaArchivo();
int escribirArchivo();
int escrituraAlFinal(); 
int leerArchivo();
int modificacionArchivo();

int main(int argc, char** argv) {

int n, opcion;

    do
    {
        printf( "\n   1. Creacion de archivo");
        printf( "\n   2. Escritura en archivo nuevo" );
        printf( "\n   3. escritura al final en archivo existente");
        printf( "\n   4. lectura de archivo");
        printf( "\n   5. Modificacion de archivo");
        printf( "\n   6. Salir." );
        printf( "\n\n   Introduzca opcion (1-6): ");

        scanf( "%d", &opcion );

        switch ( opcion )
        {
            case 1: creaArchivo();
                    break;

            case 2: escribirArchivo();
                    break;

            case 3: escrituraAlFinal();
                    break;
                    
            case 4: leerArchivo();
                    break;
                    
            case 5: modificacionArchivo();
                    break;
         }

       

    } while ( opcion != 6 );

    
    return (EXIT_SUCCESS);
}

int creaArchivo(){
    FILE *fp;
	fp = fopen ( "hola.rtf", "wb" );        
	if (fp==NULL) {fputs ("File error",stderr); exit (1);}
	fclose ( fp );

	return 0;
}

int escribirArchivo(){
    FILE *fp;
 	
 	char cadena[] = "Hola como estan.\n";
 	
 	fp = fopen ( "hola.rtf", "r+b" );
 	
 	fwrite( cadena, sizeof(char), sizeof(cadena), fp ); 
 	
 	fclose ( fp );
        return 0;
}

int escrituraAlFinal(){
    char cadena1 [] = "hola a todos, espero esten bien.\n";
        
    FILE* fichero;
    fichero = fopen("hola.rtf", "w+b");
    fputs(cadena1, fichero);
    fclose(fichero);
    printf("Proceso completado");
    return 0;
}

int leerArchivo(){
    char caracter;
    FILE*archivo;
    
    archivo=fopen("/Users/esauzavaleta/Desktop/hola.rtf", "rb");
    
    if(archivo!=NULL){
        printf("");
        
        fscanf(archivo,"%s", &caracter);
        printf("%s", caracter);
        
        
    }else{
        printf("El archivo no existe \n");
    }
    fclose(archivo);
    return 0;
}

int modificacionArchivo(){
    FILE *fp;
 	
 	char buffer[100] = "hola de nuevo.";
 	
 	fp = fopen ( "hola.rtf", "r+b" );
 	
 	fprintf(fp, buffer);
 	fprintf(fp, "%s", "\nSeguimos escribiendo en el archivo.");
 	
 	fclose ( fp );
        return 0;
}
