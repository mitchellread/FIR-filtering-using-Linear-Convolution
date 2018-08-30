#include <stdio.h>
#include <stdlib.h>

double* read(FILE* file, int size){
    int i;
    if(file){
        double* buffer = (double*)calloc(sizeof(double), size);
        if(feof(file)){
            return NULL;
        }
        for (i=0; i<size; i++){
            fscanf(file, "%lf", &buffer[i]);
        }
        return buffer;
    }

    else{
        return NULL;
    }

}


int main()
{
    //general initializations
    int i, length;


    //file handling
    FILE* filter_file = fopen("filter.dat", "r");
    FILE* input_file = fopen("input.dat", "r");
    FILE* output_file = fopen("output.dat", "w");


    //value holders
    //filter
    printf("Enter the length of the filter/ kernel:");
    scanf("%d", &length);
    double* kernel = (double*)calloc(sizeof(double), length);
    kernel = read(filter_file, length);
    if(kernel==NULL){
            printf("\nError reading the file!!\n");
    }

    //input
    double* input = (double*)calloc(sizeof(double), length);
    double* start=&input[0];
    double* end=&input[length-1];
    double* now=start;//to hold the address of current location after reading each data
    double* temp;
    int count=0;

    while(1){
        //counter for record
        double output = 0;

        //data acquisition
        temp = read(input_file, 1);
        if(temp==NULL){
            printf("\nError reading the file!!\n");
            break;
        }
        input[count%length] = *temp; //store the value at the pointer to a location in an array
        now=&input[count%length];//temp;

        //processing (filtering)
        for(i=0; i<length; i++){
            output+=(*now--)*kernel[i];
            //go to the last element after the 0th element

            if(now < start){
                now = end;
            }

        }



        //providing the output
        fprintf(output_file, "%lf\n", output);

        //escape condition
        if(feof(input_file)){
            break;
        }


        count++;
        }


    //file closing
    fclose(filter_file);
    fclose(input_file);
    fclose(output_file);

    return 0;
}
