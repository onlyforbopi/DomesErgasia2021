#include <stdio.h>
// Η λειτουργία retrieve(S, c, i) αναθέτει στη μεταβλητή c την τιμή της συνιστώσας του πίνακα array που αντιστοιχεί στην τιμή δείκτη i.
void retrieve(double array[], double *pe, int i){
    *pe = array[i];
}
//Η λειτουργία update(S, c, i) αναθέτει την τιμή της μεταβλητής c στη συνιστώσα του πίνακα array που αντιστοιχεί στην τιμή δείκτη i.
void update(double array[], double e, int i){
    array[i] = e;
}
//Η πρόσθεση δύο μονοδιάστατων πινάκων (B,C) είναι η πρόσθεση των στοιχείων τους και έπειτα η τοποθέτησή τους σε έναν νέο πίνακα (Α).
int main(){

    double B[10] = {1.8, 1.1, 2.3, 3.4, 4.2, 2.6, 1.2, 0.8, 1.9, 3.0};
    double C[10] = {2.1, 2.2, 2.9, 2.1, 2.5, 2.6, 2.7, 2.4, 2.9, 3.0};
    double A[10];
    int i;
    double a,b,c;
    for(i=0; i<10; i++){
        retrieve(B, &b, i);
        retrieve(C, &c, i);
        a=b+c;
        update(A, a, i);
    }
    

    for( i=0; i<10; i++){
        printf("B[%d] %.2f \nC[%d] %.2f \nA[%d] %.2f\n\n",i,B[i],i,C[i],i,A[i]);
        printf("\n");
    }
    printf("Array A =  ");
    for( i=0; i<10; i++){
        printf("%.2f ",A[i]);
    }
    printf("\n");
}