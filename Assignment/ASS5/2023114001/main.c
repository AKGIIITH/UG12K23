#include"matrix.h"
#include<string.h>

int main(int argc, char* argv[]) {
    int exit=0;
    //int q=argv[1][0]-'0';
    int q;
    scanf("%d",&q);

    while(q>0){
        // int argreader=2;
        // if(strcpy("add_matrix",argv[argreader++]) && strcpy("0",argv[argreader++])){
        //     int num_rows=argv[argreader++][0]-'0';
        //     int num_cols=argv[argreader++][0]-'0';
        //     Matrix* A=create_matrix(num_rows,num_cols);
        //     Matrix* B=create_matrix(num_rows,num_cols);
        //     for(int i=0;i<num_rows;i++){
        //         for(int j=0;j<num_cols;j++){
        //             (A->data[i])[j]=argv[argreader++][0]-'0';
        //         }
        //     }
        //      for(int i=0;i<num_rows;i++){
        //         for(int j=0;j<num_cols;j++){
        //             (B->data[i])[j]=argv[argreader++][0]-'0';
        //         }
        //      }
        //      Matrix* c=add_matrix(A,B);
        //      print_matrix(c);      
        // }
        char cmd[50];
        int parts;
        FILE* history;
        scanf("%s",cmd);
        if(strcmp("history",cmd)==0){
            history=fopen("mx_history","a+");
            fprintf(history,"\nLOG::%s",cmd);
            fclose(history);

            history=fopen("mx_history","r");
            char ch;
            while(ch != EOF){
                ch= fgetc(history);
                printf("%c",ch);
            }
            parts=9;
        }
        else{
            scanf("%d",&parts);
            history=fopen("mx_history.txt","a+");
            fprintf(history,"LOG::%s %d\n",cmd,parts);
            fclose(history);
        }

        if(parts==1){
            if(strcmp(cmd,"add_matrix")==0){
                char file1[1000];
                char file2[1000];
                char output[1000];

                scanf("%s",file1);
                scanf("%s",file2);
                scanf("%s",output);

                strcat(file1,".txt");
                strcat(file2,".txt");
                strcat(output,".txt");

                FILE* First=fopen(file1,"r");
                FILE* Second=fopen(file2,"r");
                FILE* Last=fopen(output,"w");

                Matrix* A=read_matrix_from_file(First);
                Matrix* B=read_matrix_from_file(Second);
                
                Matrix* C=add_matrix(A,B);
                write_matrix_to_file(Last,C);
                fclose(First);
                fclose(Second);
                fclose(Last);
            }
            else if(strcmp(cmd,"mult_matrix")==0){
                char file1[1000];
                char file2[1000];
                char output[1000];

                scanf("%s",file1);
                scanf("%s",file2);
                scanf("%s",output);

                strcat(file1,".txt");
                strcat(file2,".txt");
                strcat(output,".txt");

                FILE* First=fopen(file1,"r");
                FILE* Second=fopen(file2,"r");
                FILE* Last=fopen(output,"w");

                Matrix* A=read_matrix_from_file(First);
                Matrix* B=read_matrix_from_file(Second);
                
                Matrix* C=mult_matrix(A,B);
                write_matrix_to_file(Last,C);
                fclose(First);
                fclose(Second);
                fclose(Last);    
            }
            else if(strcmp(cmd,"transpose_matrix")==0){
                char file1[1000];
                char output[1000];

                scanf("%s",file1);
                scanf("%s",output);

                strcat(file1,".txt");
                strcat(output,".txt");

                FILE* First=fopen(file1,"r");
                FILE* Last=fopen(output,"w");

                Matrix* A=read_matrix_from_file(First);
                
                Matrix* C=transpose_matrix(A);
                write_matrix_to_file(Last,C);
                fclose(First);
                fclose(Last);
            }
            else if(strcmp(cmd,"determinant")==0){
                char file1[1000];
            
                scanf("%s",file1);

                strcat(file1,".txt");

                FILE* First=fopen(file1,"r");

                Matrix* A=read_matrix_from_file(First);
                
                int det=determinant(A);
                fclose(First);
                printf("%d",det);
            }
            else if(strcmp(cmd,"scalar_multiply")){
                long long int s;
                scanf("%lld",&s);

                char file1[1000];
                char output[1000];

                scanf("%s",file1);
                scanf("%s",output);

                strcat(file1,".txt");
                strcat(output,".txt");

                FILE* First=fopen(file1,"r");
                FILE* Last=fopen(output,"w");

                Matrix* A=read_matrix_from_file(First);
                
                Matrix* C=scalar_mult_matrix(s,A);
                write_matrix_to_file(Last,C);
                fclose(First);
                fclose(Last);
            }
            else{
                printf("ERROR: INVALID INPUT");
            }
        }
        else if(parts==0){
            if(strcmp(cmd,"add_matrix")==0){
                int num_rows;
                int num_cols;
                scanf("%d %d",&num_rows,&num_cols);
                Matrix* A= create_matrix(num_rows,num_cols);
                
                int num_rowsB;
                int num_colsB;
                scanf("%d %d",&num_rowsB,&num_colsB);
                Matrix* B=create_matrix(num_rowsB, num_colsB);
                
                A=input_matrix(A);
                B=input_matrix(B);

                // for(int i=0;i<num_rows;i++){
                //     for(int j=0;j<num_cols;j++){
                //         scanf("%d",&(A->data[i])[j]);
                //     }
                // }
                // for(int i=0;i<num_rows;i++){
                //     for(int j=0;j<num_cols;j++){
                //         scanf("%d",&(B->data[i])[j]);
                //     }
                // }
                
                Matrix* C=add_matrix(A,B);
                if(C!=NULL){
                print_matrix(C);}
            }
            else if(strcmp(cmd,"mult_matrix")==0){
                int num_rows;
                int num_cols;
                scanf("%d %d",&num_rows,&num_cols);
                Matrix* A= create_matrix(num_rows,num_cols);
                int num_rowsB;
                int num_colsB;
                scanf("%d %d",&num_rowsB,&num_colsB);
                Matrix* B=create_matrix(num_rowsB, num_colsB);
                
                A=input_matrix(A);
                B=input_matrix(B);
                // for(int i=0;i<num_rows;i++){
                //     for(int j=0;j<num_cols;j++){
                //         scanf("%d",&(A->data[i])[j]);
                //     }
                // }
                // for(int i=0;i<num_rows;i++){
                //     for(int j=0;j<num_cols;j++){
                //         scanf("%d",&(B->data[i])[j]);
                //     }
                // }
                
                Matrix* C=mult_matrix(A,B);
                if(C!=NULL){
                print_matrix(C);}
            }
            else if(strcmp(cmd,"transpose_matrix")==0){
                int num_rows;
                int num_cols;
                scanf("%d %d",&num_rows,&num_cols);
                Matrix* A= create_matrix(num_rows,num_cols);

                A=input_matrix(A);
                Matrix* C=transpose_matrix(A);
                print_matrix(C);
            }
            else if(strcmp(cmd,"determinant")==0){
                int num_rows;
                int num_cols;
                scanf("%d %d",&num_rows,&num_cols);
                Matrix* A= create_matrix(num_rows,num_cols);

                A=input_matrix(A);
                int det=determinant(A);

                printf("%d",det);
            }
            else if(strcmp(cmd,"scalar_multiply")){
                long long int s;
                scanf("%lld",&s);
                int num_rows;
                int num_cols;
                scanf("%d %d",&num_rows,&num_cols);
                Matrix* A= create_matrix(num_rows,num_cols);

                A=input_matrix(A);
                Matrix* C=scalar_mult_matrix(s,A);
            }
            else{
                printf("ERROR: INVALID INPUT");
            }
        }
        else if(parts!=9){
            printf("ERROR: INVALID INPUT");
        }
        
        q--;
        
    }
    

    
    // int num_rows;// row size will be provided as the first arg
    // int num_cols;// col size will be provided as the second arg

    // Matrix* m = create_matrix(num_rows,num_cols);
    
    // for(int i=0;i<num_rows;i++){
    //     for(int j=0;j<num_cols;j++){
    //         (m->data[i])[j]=1;
    //     }
    // }
    // print_matrix(m);
    // for(int i=0;i<argc;i++){
    //     printf("%s",argv[i]);
    // }
    // return 0;

}