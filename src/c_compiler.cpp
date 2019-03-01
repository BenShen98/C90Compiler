#include "ast.hpp"

#include <iostream>
#include <fstream>
#include <string>
#include <string.h>

std::ofstream ffout;
extern FILE *yyin;


//debug dummy
void dd(){
    int x;
}


int  main(int argc, char* argv[]){

    // check input format is correct
    if(argc!=5){
        std::cerr<<"Expecting 4 arguments\n--translate [source-file.c] -o [dest-file.py]\nOR\nbin/c_compiler -S [source-file.c] -o [dest-file.s]\n";
        exit(-1);
    }

    //phrase arguments and set up the tree
    yyin = fopen(argv[2], "r");         //input pointer for flex
    ffout.open(argv[4]);  //output file setup

    const ast_abs * root = parseAST();  //phrase tree

    dd();

    if( strcmp(argv[1],"--translate")==0 ){
        //logic to translate to python
        std::string pyFile;
        root->py(pyFile);
        ffout<<pyFile;

        // add entry to the python file
        ffout<<"\n\n# Invoke main as the starting point\n"
               "if __name__ == \"__main__\":\n"
               "    import sys\n"
               "    ret=main()\n"
               "    sys.exit(ret)\n";

    }else if( strcmp(argv[1],"-S")==0 || strcmp(argv[1],"-s")==0 ){
        //logic for compile to MIPS I assembly

    }else{
        std::cerr<<argv[1]<<" is not a valid option, only support --translate for translate OR -S for compile\n";
        exit(-1);
    }


    //clean up
    fclose(yyin);
    ffout.close();
    delete root;


    return 0;
}

