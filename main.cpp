#include <iostream>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wuninitialized"
struct set{
    int nr_elem = 0;
    double *elem;
};

void initializare(int n,set *&set1){
    set1 = new set;
    set1->nr_elem = n;

    set1->elem = new double[n];

    for(int i=0;i<n;i++)
        set1->elem[i]=0;
}

void copiere(set *&s1,set *&s2){
    set s3 = *s2;
    *s2 = *s1;
    *s1 = s3;

}

void dealocare(set *&s1){
    s1->nr_elem=0;
    delete s1->elem;
}


int cautare(double c,set *s){
    for(int i=0;i<s->nr_elem;i++){
        if(c==s->elem[i]) return i;
    }

    return -1;
}

void citire(set *&s1){
    printf("\nIntroduceti %d elemente reale separate prin ENTER:\n",s1->nr_elem);
    for(int i=0;i<s1->nr_elem;i++){
        double c;

        printf("Elem %d=",i);
        scanf("%lf",&c);

        while(cautare(c,s1)!=-1){
            printf("Numarul %lf exista in acest sir. Va rugam introduceti o alta valoare.\n",c);
            printf("Elem %d=",i);
            scanf("%lf",&c);
        }
        s1->elem[i] =c;
    }
}

void afisare(set *p){
    for(int i=0;i<p->nr_elem;i++){
        printf("%3.2lf ",p->elem[i]);
    }
}

set* suma(set *s1,set *s2){
    set *s3;

    initializare(s1->nr_elem+s2->nr_elem,s3);

    s3->elem = s1->elem;


    for(int i=0;i<s2->nr_elem;i++){
        s3->elem[s1->nr_elem+i] = s2->elem[i];
    }



    return s3;
}



int main() {


    set *s1,*s2,*s3;
    initializare(2,s1);
    initializare(2,s2);
    initializare(3,s3);
    citire(s1);
    citire(s2);
    s3 = suma(s1,s2);
    printf("\nElementele din s3: ");
    afisare(s3);
    printf("\nIntroduceti o valoare reala:");
    double c;
    scanf("%lf",&c);
    int r = cautare(c,s3);
    if(r>=0)
        printf("Elementul %3.2lf a fost gasit pe pozitia %d.",c,r);
    else
        printf("Elementul %3.2lf nu a fost gasit.",c);

    return 0;
}



#pragma clang diagnostic pop