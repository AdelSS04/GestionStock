#include <stdio.h>
#include <string.h>
#include<stdlib.h>
struct stock
{
    char nom[20];
    char adrs[20];
    int nbr;
    int nb_max;
};
struct produit
{    char mrq[20];
    char taille[20];
    int prix;
    int nbr;
};
void ajt_stock ()// cree un stocke
{char s[20],cpy[20]="stk_";
      FILE * f=NULL;

      printf("donne le nom de stock a cree ");
      scanf("%s",&s);
      strcat(cpy,s);
      f=fopen(cpy,"rb+");
      if(f!=NULL)
       {
        printf("stock deja existe\n");
        fclose(f);}
      else
        {f=fopen(cpy,"ab");
  fclose(f);
  printf("stock cree\n");}

}

int verf_car_ex(char s[20], char c[20])
{struct stock st;
  FILE * stk=fopen(s,"rb+");
  if (stk!=NULL)
  {
      fread(&st,sizeof(struct stock),1,stk);
      while(!feof(stk) )
      {
      if(strcmp(st.nom,c)==0 )
      {fclose(stk);
            return 0 ;
      }
      else
                fread(&st,sizeof(struct stock),1,stk);


}} fclose(stk);
 return 1 ;}


void ajt_cat_stk()// ajoute un category pour stock
{ char s[20],cpy[20]="stk_",cc[20]="cat_";
   struct stock st;
printf("donneé le nom de sotck a le qualle vous ajoute cat ");
scanf ("%s",s);
strcat(cpy, s);
FILE *stk=NULL;
stk=fopen(cpy,"rb+");
if(stk!=NULL){
    printf ("donne le nom de category a ajoute ");

    scanf("%s",&st.nom);
    if(verf_car_ex(cpy,st.nom)==1){
    printf(" adress : ");
    scanf("%s",&st.adrs);
    st.nbr=0;
    printf(" nombre max : ");
    scanf("%d",&st.nb_max);
        fseek(stk,0,SEEK_END);

    fwrite(&st,sizeof(struct stock),1,stk);
    strcat(cc,st.nom);
    FILE *ccc=NULL;
ccc=fopen(cc,"ab");
fclose(ccc);
printf("categorie ajouteé\n");
    }
    else
        printf("category deja existe\n");
fclose(stk);
    }
    else
        printf("stock n'existe pas\n");
}

void aff_cat_stk()//    affichiez les element des stock
{
    {char s[20],cpy[20]="stk_";
    printf ("donne le nom de stock a afficie ");
    scanf("%s",&s);
    strcat(cpy, s);
    FILE * f=NULL;
  f=fopen(cpy,"rb+");
  struct stock st;

  if (f!=NULL)
  {
      fread(&st,sizeof(struct stock),1,f);
      while(!feof(f))
      {
      printf("\n nom  = %s\n emplacement =%s\n nombre res=%d\n nombre max = %d\n\n",st.nom,st.adrs,st.nbr,st.nb_max);
      fread(&st,sizeof(struct stock),1,f);
      }
        fclose(f);

  }
 else
    printf("stock n'existe pas");
}

}

void ajt_pro_cat()
{char s[20],n[20];
char ss[20]="tmp";
char cpy[20]="cat_";
    printf ("donne le nom de category a le quelle vous ajoute ");
    scanf("%s",&s);
        printf("saisir le nom du stocke de cette category : ");
    scanf("%s",&n);

    strcat(cpy, s);
    FILE * f=NULL;
  f=fopen(cpy,"rb+");
    if (f!=NULL)
    {if (verif(s,n)==1)
       {
           if (verif_cap(s,n)==1)
        {
            int ex=0;
            char noo[20];int i;
    struct produit p;
    struct stock stt;
    printf(" marque : ");
    scanf("%s",&noo);

   /* for (i=0;p.mrq[i];i++)
    {noo[i]=p.mrq[i];}*/
        fseek(f,0,SEEK_SET);
    fread(&p,sizeof(struct produit),1,f);
      while( !feof(f) )
    {
        if (strcmp(p.mrq,noo)==0)
        {
            ex=1;
                fread(&p,sizeof(struct produit),1,f);

        }
        else
            fread(&p,sizeof(struct produit),1,f);

    }
    if(ex==0)
   {     for (i=0;noo[i];i++)
    {p.mrq[i]=noo[i];}
   printf(" taille : ");
    scanf("%s",&p.taille);
    printf(" prix : ");
    scanf("%d",&p.prix);
    do{
    printf(" nombre : ");
    scanf("%d",&p.nbr);}while(p.nbr<=0);
    fseek(f,0,SEEK_END);
    fwrite(&p,sizeof(struct produit),1,f);
 fclose(f);
     rechercher(s,n);
printf("produit ajoute !!");
    }else
    printf("produit existe");
       }
    else
        printf( " category pliene") ; }
        else
            printf("categorie n'existe pas dans cette stock");
}
else
    printf("category n'existe pas");

}

int verif(char s[20],char n[20])
{
    {
        struct stock st;
    char cpy[20]="stk_";
    strcat(cpy, n);

  FILE * stk=NULL;
  stk=fopen(cpy,"rb+");
  if (stk!=NULL)
  {
      fread(&st,sizeof(struct stock),1,stk);
      while(!feof(stk) )
      {
      if(strcmp(st.nom,s)==0 )
      {fclose(stk);
            return 1 ;
      }
      else
                fread(&st,sizeof(struct stock),1,stk);


}
}
fclose(stk);
 return 0 ;}
}

int verif_cap (char s[20],char n[20])
{
        struct stock st;
    char cpy[20]="stk_";
    strcat(cpy, n);

  FILE * stk=NULL;
  stk=fopen(cpy,"rb+");
  if (stk!=NULL)
  {
      fread(&st,sizeof(struct stock),1,stk);
      while(!feof(stk) )
      {
      if(strcmp(st.nom,s)==0 && ((st.nbr+1)>st.nb_max))
      {fclose(stk);
            return 0 ;
      }
      else
                fread(&st,sizeof(struct stock),1,stk);


} }else if(stk==NULL){
printf("sotck n'exicte pas ");
return 0;}
fclose(stk);
 return 1 ;}
void rechercher(char s[20],char n[20])
{char ss[20]="tmp_rech",cpy[20]="stk_";
int r1,r2;
    struct stock st;
    strcat(cpy, n);

  FILE *tmp=fopen("tmp_rech","ab");
  FILE * stk=NULL;
  stk=fopen(cpy,"rb+");
  if (stk!=NULL)
  {
      fread(&st,sizeof(struct stock),1,stk);
      while(!feof(stk) )
      {
      if(strcmp(st.nom,s)==0 && ((st.nbr+1)<=st.nb_max))
      {
            st.nbr++;
                    fseek(tmp,0,SEEK_END);

          fwrite(&st,sizeof(struct stock),1,tmp);
        fread(&st,sizeof(struct stock),1,stk);
      }
      else
        {        fseek(tmp,0,SEEK_END);

                  fwrite(&st,sizeof(struct stock),1,tmp);
        fread(&st,sizeof(struct stock),1,stk);
      }
      }
  }
  fclose(stk);
    fclose(tmp);
    char vr[20]="azz";
        r1=rename(cpy,vr);
        r2=rename(ss,cpy);
remove("azz");
remove("tmp_rech");
}

void aff_pro_cat()
{char s[20],cpy[20]="cat_";
    printf ("donne le nom de category a afficie ");
    scanf("%s",&s);
    strcat(cpy, s);

    FILE * f=NULL;
  f=fopen(cpy,"rb");
  struct produit p;

  if (f!=NULL)
  {   rewind(f);
      fread(&p,sizeof(struct produit),1,f);
      while(!feof(f))
      {
      printf("\n nom produit = %s\n taille =%s\n prix=%d\n nombre = %d\n\n",p.mrq,p.taille,p.prix,p.nbr);
      fread(&p,sizeof(struct produit),1,f);
      }
        fclose(f);

  }
else
    printf("category n'existe pas");
}



void mod_stk(){
   struct stock st;
   char ss[20]="tmp",cpy[20]="stk_";
char s[20],c[20];int r1,r2,ver=0;
FILE *tmpo=NULL;
tmpo=fopen(ss,"ab");
printf("le nom de stock a modifie :") ; scanf("%s",s);
strcat(cpy, s);
FILE *stk=NULL;
stk=fopen(cpy,"rb+");
if(stk!=NULL){
printf("saise le nom de category modife dans le stock :");scanf("%s",c);
if(verif(c,s)==1)


{fread(&st,sizeof(struct stock),1,stk);
      while(!feof(stk) ){
        if(strcmp(st.nom,c)==0 )
      {ver=1;
      printf("\n nom  = %s\n emplacement =%s\n nombre res=%d\n nombre max = %d\n\n",st.nom,st.adrs,st.nbr,st.nb_max);
printf (" dooneé le nv contenu \n");

    printf(" adress : ");
    scanf("%s",&st.adrs);
    do{
    printf(" nombre max : ");
    scanf("%d",&st.nb_max);}while(st.nb_max<st.nbr);
            fseek(tmpo,0,SEEK_END);

    fwrite(&st,sizeof(struct stock),1,tmpo);
      fread(&st,sizeof(struct stock),1,stk);
      printf("modification terminue");
      }
      else
        {        fseek(tmpo,0,SEEK_END);

                  fwrite(&st,sizeof(struct stock),1,tmpo);
        fread(&st,sizeof(struct stock),1,stk);
      }



}
if (ver==0)
    printf("category n'existe pas");

fclose(stk);

    fclose(tmpo);
    char vr[20]="azz";
        r1=rename(cpy,vr);
        r2=rename(ss,cpy);

remove("azz");
remove("tmp");
}else
printf("categorie n'exixste pas dans le stock");


}else
    {printf("stock n'existe pas");
    fclose(tmpo);
remove("tmp");}
}

void mod_pro(){
struct produit p;
char ss[20]="tmp",cpy[20]="cat_";
char s[20],c[20];int r1,r2,ver=0;
FILE *tmpo=NULL;
tmpo=fopen(ss,"ab");
printf("le nom de categorie a modifie :") ; scanf("%s",s);strcat(cpy, s);

FILE *stk=NULL;
stk=fopen(cpy,"rb+");
if(stk!=NULL){
printf("saise le nom de produit modife dans le category :");scanf("%s",c);

fread(&p,sizeof(struct produit),1,stk);
      while(!feof(stk) ){
        if(strcmp(p.mrq ,c)==0)
      {ver=1;
      printf("\n marque  = %s\n taille =%s\n nombre prix=%d\n quantite = %d\n\n",p.mrq,p.taille,p.prix,p.nbr);
printf (" dooneé le nv contenu \n");
    printf(" taille : ");
    scanf("%s",&p.taille);
    printf(" prix : ");
    scanf("%d",&p.prix);
       do{ printf(" quantite : ");
    scanf("%d",&p.nbr);}while(p.nbr==0);
        fseek(stk,0,SEEK_END);

    fwrite(&p,sizeof(struct produit),1,tmpo);
      fread(&p,sizeof(struct produit),1,stk);
          printf("fait!!\n");

      }
      else
        {        fseek(stk,0,SEEK_END);

                  fwrite(&p,sizeof(struct produit),1,tmpo);
        fread(&p,sizeof(struct produit),1,stk);
      }
}if (ver==0)
    printf("produit n'existe pas\n");

fclose(stk);
    fclose(tmpo);
    char vr[20]="azz";
        r1=rename(cpy,vr);
        r2=rename(ss,cpy);

remove("azz");
remove("tmp");
}
    else
	{printf("categorie n'existe pas\n");
    fclose(tmpo);
	remove("tmp");}
}

void sup_pro()
{
    struct produit p;
char ss[20]="tmp",cpy[20]="cat_";
char s[20],n[20],stock[20],c[20];int r1,r2,ver=0,proo=0;
FILE *tmpo=NULL;
tmpo=fopen(ss,"ab");
printf("le nom de category a modifie :") ; scanf("%s",s);strcat(cpy, s);

FILE *stk=NULL;
stk=fopen(cpy,"rb+");
if(stk!=NULL){
printf("saise le nom de produit supprime dans le category :");scanf("%s",c);

fread(&p,sizeof(struct produit),1,stk);
      while(!feof(stk) ){
        if(strcmp(p.mrq ,c)==0)
      {ver=1;
        p.nbr--;
    if(p.nbr==0)
    {
        //printf("saise le nom de stock  prencipale :");scanf("%s",stock);

       do{ printf("saise le nom de stock  prencipale :");scanf("%s",n);
             proo=sup_cat_auto(s,n);
       }while(proo==0);

            fread(&p,sizeof(struct produit),1,stk);
    }
    else {
                    fseek(stk,0,SEEK_END);
printf("fait");
    fwrite(&p,sizeof(struct produit),1,tmpo);
    fread(&p,sizeof(struct produit),1,stk);
printf("fait!!");

    }
      }
      else
        {        fseek(stk,0,SEEK_END);

                  fwrite(&p,sizeof(struct produit),1,tmpo);
        fread(&p,sizeof(struct produit),1,stk);
      }
if (ver==0)
    printf("produit n'existe pas");}

fclose(stk);
    fclose(tmpo);
    char vr[20]="azz";
        r1=rename(cpy,vr);
        r2=rename(ss,cpy);

remove("azz");
remove("tmp");
}else
    printf("category n'existe pas");
    fclose(tmpo);
remove(ss);
}
int sup_cat_auto(char s[20],char n[20])
{char ss[20]="tmp_rech",cpy[20]="stk_";

int r1,r2;
    struct stock st;

    strcat(cpy, n);

  FILE *tmp1=fopen("tmp_rech","ab");
  FILE * stk1=NULL;
  stk1=fopen(cpy,"rb+");
  if (stk1!=NULL)
  {if(verif(s,n)==1)
     {fread(&st,sizeof(struct stock),1,stk1);
      while(!feof(stk1) )
      {
      if(strcmp(st.nom,s)==0 )
      {
            st.nbr=st.nbr-1;
                    fseek(tmp1,0,SEEK_END);

          fwrite(&st,sizeof(struct stock),1,tmp1);
        fread(&st,sizeof(struct stock),1,stk1);

      }
      else
        {        fseek(tmp1,0,SEEK_END);

                  fwrite(&st,sizeof(struct stock),1,tmp1);
        fread(&st,sizeof(struct stock),1,stk1);

      }
      }
      fclose(stk1);
    fclose(tmp1);
    char vr[20]="azz";
        r1=rename(cpy,vr);
        r2=rename(ss,cpy);
remove("azz");
remove("tmp_rech");
printf("2\n");
return 1;
      }
      else
          printf("category n'existe pas dans cette stock\n");
          return 0;
  }
  printf("stock n'existe pas\n");
  fclose(stk1);
    fclose(tmp1);
   remove("tmp_rech");
   return 0;
}
int sup_cat_stk(char cat[20])
{
       struct stock st;
char ss[20]="tmp",cpy[20]="stk_";
char s[20],stock[20],c[20];int r1,r2,ver=0;
FILE *tmpo=NULL;
tmpo=fopen(ss,"ab");
    printf("saise le nom de stock principale"); scanf("%s",s);
 strcat(cpy, s);

FILE *stk=NULL;
stk=fopen(cpy,"rb+");
if(stk!=NULL){
if(verif(cat,s)==1)
{fread(&st,sizeof(struct stock),1,stk);
      while(!feof(stk) ){
        if(strcmp(st.nom ,cat)==0)
      {
            fread(&st,sizeof(struct stock),1,stk);
            printf("fait!!");
      }
      else
        {        fseek(tmpo,0,SEEK_END);

                  fwrite(&st,sizeof(struct stock),1,tmpo);
        fread(&st,sizeof(struct stock),1,stk);
      }
      }
      }
      else
     {
         printf("categorie n'existe pas dans le stock");
      fclose(stk);
    fclose(tmpo);
remove("tmp");
return 0;}
fclose(stk);
    fclose(tmpo);
    char vr[20]="azz";
        r1=rename(cpy,vr);
        r2=rename(ss,cpy);

remove("azz");
remove("tmp");
return 1;
}
else
{

 printf("stock n'existe pas");
  fclose(tmpo);
  remove("tmp");
 return 0;}
}




void sup_cat()
{struct stock st;
char cat[20],cpy[20]="cat_";


printf("saise le nom de category a supprime");
scanf("%s",&cat);
strcat(cpy,cat);
  FILE * stk1=NULL;
  stk1=fopen(cpy,"rb+");
  if (stk1!=NULL)
  {fclose(stk1);

  if(sup_cat_stk(cat)==1)
    remove(cpy);



}
else
    printf("category n'existe pas");
}
void cap()
{
    struct stock st;
    char cpy[20]="stk_",s[20];
    int capp;
    printf("saise le nom de stock :");scanf("%s",s);
    strcat(cpy,s);
    FILE *stk=NULL;
    stk=fopen(cpy,"rb+");
    if(stk!=NULL)
    {fread(&st,sizeof(struct stock),1,stk);
      while(!feof(stk) ){
            capp=st.nb_max-st.nbr;
      printf(" pour %s il y encore %d place\n",st.nom,capp);
        fread(&st,sizeof(struct stock),1,stk);
    }
}
else
    printf("stock n'existe pas ");}

   /* int pro_ex(char s[20];char n[20])
    {

    }
*/
main ()

{
int choix ;
do {

    printf("\n******  Menu  ******\n");
    printf("1- Ajouter category\n");
    printf("2- ajoute produit\n");
    printf("3- Afficher stock\n");
    printf("4- affiche category\n");
    printf("5- modifie un category\n");
    printf("6- modifie un produit\n");
    printf("7- Sup category\n");
    printf("8- Sup produit\n");
    printf("9- cree stock\n");
    printf("10- aff le capacite\n");
        printf("11- A propos\n");

    printf("12- exit\n");
    printf("Faites votre choix : ");
    scanf("%d",&choix);
    switch(choix)
    {
    case 1 :

        ajt_cat_stk();
break;
    case 2 :
ajt_pro_cat();
        break;
    case 3 :
         aff_cat_stk();
        break;
    case 4 :
        aff_pro_cat();
        break;
    case 5 :
        mod_stk();
        break;
    case 6 :
           mod_pro();
                      break;
    case 7 :
            sup_cat();

                        break;

    case 8 :
            sup_pro();
                        break;
    case 9 :
                          ajt_stock();
            break;
    case 10:
            cap();
            break;
    case 11:
        printf("programme devolope par\nLajil Adel-Saleh Nabil\nGSIL-C 2017/2018\nversion Beta 1.0 \nEmail : ajiladel@gmail.com\n");
break;
/*    default:
        printf("Rectifiez votre choix\n");
        break;*/
        }
    }
    while(choix !=12);

}

