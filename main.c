#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // Pour sleep() sous Unix/Linux, utilisez <windows.h> pour Windows

void asciiART()
{
    printf("\n\n\n\n\n\n\n");
    printf("\t\t\t      #    #####   #     #           #####     #    #     # #   #\n");
    printf("\t\t\t     # #   #    #  #     #           #    #   # #   ##    # #  #\n");
    printf("\t\t\t    #   #  #    #  #     #           #    #  #   #  # #   # # #\n");
    printf("\t\t\t   ####### #####   ####### ********* #####  ####### #  #  # ##\n");
    printf("\t\t\t   #     # #   #   #     #           #    # #     # #   # # # #\n");
    printf("\t\t\t   #     # #    #  #     #           #    # #     # #    ## #  #\n");
    printf("\t\t\t   #     # #     # #     #           #####  #     # #     # #   #\n");

    sleep(2);

    printf("\n\n\n\t\t\t\t[");
    for(int i = 0; i < 3; i++)
    {
        printf("##############");
        sleep(1);
    }
    printf("]");
    system("cls");
}

typedef struct
{
  int jour;
  int mois; //structure date
  int annee;
}date;

//////////////////////////////

typedef struct
{
 char nom[99];
 char prenom[100];
 char tele[100];
 char code[100];                    //structure des infos d'utilisateur
 char CIN[100];
 char ville[100];
 char sex[10];
 char email[100];
 float solde;
 date date_naissance,date_aujourd_hui;
}utilisateur;
typedef struct
{
    utilisateur user;
    struct liste *suivant;
}liste;

////////////////////////////////

typedef struct
{
    char CIN[10],ID[99],type[50],Motif[50];
    date d;
    float Montant;
}sauvg;
date time()
{
    date d;
    SYSTEMTIME Time;            //fonction determine la date d aujourd'hui
    GetLocalTime(&Time);
    d.jour=Time.wDay;
    d.mois=Time.wMonth;
    d.annee=Time.wYear;
    return d;
}

////////////////////////////////

void creation_compte()
{
   FILE *fp;
    int i=0,j=0;
    char temp[99];
    utilisateur L,l; //CREATION DE COMPTE.
    fp=fopen("paiment.txt","a+");
    if(fp==NULL)
    {
        printf("\t\tErreur d'ouverture de fichier");
        exit(1);
}
system("COLOR 4");
    system("cls");
    printf("\t\tDONNEZ VOUS INFORMATION\n");
    sleep(2);
    printf("\t\t\tVOTRE CIN : ");
    getchar();
    gets(L.CIN);
    while(fscanf(fp,"%s\n%s\n%s\n%s\n%s\n%s\n%s\n%f\n%d\t%d\t%d\n%d\t%d\t%d\n",l.CIN,l.nom,l.prenom,l.tele,l.ville,l.email,l.code,&l.solde,&l.date_naissance.jour,&l.date_naissance.mois,&L.date_naissance.annee,&l.date_aujourd_hui.jour,&l.date_aujourd_hui.mois,&l.date_aujourd_hui.annee)==14)
    {
        if (strcmp(L.CIN,l.CIN)==0)
        {
            printf("\t\t\tDEJA IL Y A UN COMPTE AVEC CE CIN !\n");
             exit(1);
        }
     }
    do {
    	printf("\t\t\tSAISIR UN MOT DE PASSE : ");
        gets(L.code);
        printf("\t\t\tVEUILLEZ CONFIRMER LE MOT DE PASSE :");
        gets(temp);
        if(strcmp(L.code,temp)!=0)
            printf("\t\t\tMOT DE PASSE PAS IDENTIQUE !!\n");
    } while(strcmp(L.code,temp)!=0);

    printf("\t\t\tVOTRE NOM : ");
    gets(L.nom);
    printf("\t\t\tVOTRE PRENOM : ");
    gets(L.prenom);
    printf("\t\t\tVOTRE NUMERO DE TELEPHONE : ");
    gets(L.tele);
    printf("\t\t\tVOTRE VILLE : ");
    gets(L.ville);
    printf("\t\t\tVOTRE EMAIL : ");
    gets(L.email);
    printf("\t\t\tVOTRE SEX : ");
    gets(L.sex);
    printf("\t\t\tVOTRE DATE DE NAISSANCE : ");
    scanf("%d",&L.date_naissance.jour);printf("\t\t\t\t\t\t  ");scanf("%d",&L.date_naissance.mois);printf("\t\t\t\t\t\t    ");scanf("%d",&L.date_naissance.annee);
    L.date_aujourd_hui=time();
    printf("Merci d'avoir inscrir chez nous :) \n");
    L.solde=0;
    fprintf(fp,"%s\n%s\n%s\n%s\n%s\n%s\n%s\n%f\n%d\t%d\t%d\n%d\t%d\t%d\n",L.CIN,L.nom,L.prenom,L.tele,L.ville,L.email,L.code,L.solde,L.date_naissance.jour,L.date_naissance.mois,L.date_naissance.annee,L.date_aujourd_hui.jour,L.date_aujourd_hui.mois,L.date_aujourd_hui.annee);


    fclose(fp);
}
void sauvgarder(sauvg M)
{
FILE *sauv;
    sauv=fopen("historique.txt","a+");
    if(sauv==NULL)                                                    //sauvogarder
    {
       printf("Erreur");
       exit(0);
    }
fprintf(sauv,"%s\n%s\n%s\n%s\n%d\n%d\n%d\n%f\n",M.CIN,M.ID,M.type,M.Motif,M.d.jour,M.d.mois,M.d.annee,M.Montant);
fclose(sauv);
}
///////////////////////////

void Acceder(char C[10])
{   utilisateur L;
FILE *fp;
    fp=fopen("paiment.txt","at+");
    if(fp==NULL)
    {
      printf("error");
      exit(1);
}
    else {

           while(fscanf(fp,"%s\n%s\n%s\n%s\n%s\n%s\n%s\n%f\n%d\t%d\t%d\n%d\t%d\t%d\n",L.CIN,L.nom,L.prenom,L.tele,L.ville,L.email,L.code,&L.solde,&L.date_naissance.jour,&L.date_naissance.mois,&L.date_naissance.annee,&L.date_aujourd_hui.jour,&L.date_aujourd_hui.mois,&L.date_aujourd_hui.annee)==14)
           {
             if(strcmp(C,L.CIN)==0)
             {

                printf("\n\n\t\tVos informations sont :\n\n ");
                printf("\t\t\tLe CIN est: %s  \n",C);
                printf("\t\t\tVOTRE CODE EST : %s \n",L.code);
                printf("\t\t\tVOTRE NOM EST: %s  \n",L.nom);
                printf("\t\t\tVOTRE PRENOM est: %s  \n",L.prenom);
                printf("\t\t\tVOTRE NUMERO DE TELEPHONE est: %s \n",L.tele);
                printf("\t\t\tVOTRE DATE DE NAISSANCE EST:%d / %d / %d\n ",L.date_naissance.jour,L.date_naissance.mois,L.date_naissance.annee);
                printf("\t\t\tDATE DE CREATION EST :%d / %d /%d\n ",L.date_aujourd_hui.jour,L.date_aujourd_hui.mois,L.date_aujourd_hui.annee);
                printf("\t\t\tVOTRE SOLD DISPONIBLE EST : %f DH \n",L.solde);
             }
           }

        }

    fclose(fp);

}
//////////////////////////////

liste*lire(liste*tete)
{   utilisateur L;
    FILE *fp;
    liste*donnee;
    fp=fopen("paiment.txt","rt");
    if(fp==NULL)
      exit(1);
     while(fscanf(fp,"%s\n%s\n%s\n%s\n%s\n%s\n%s\n%f\n%d\t%d\t%d\n%d\t%d\t%d\n",L.CIN,L.nom,L.prenom,L.tele,L.ville,L.email,L.code,&L.solde,&L.date_naissance.jour,&L.date_naissance.mois,&L.date_naissance.annee,&L.date_aujourd_hui.jour,&L.date_aujourd_hui.mois,&L.date_aujourd_hui.annee)==14)
    {
        donnee=(liste*)malloc(sizeof(liste));
        donnee->user=L;
        donnee->suivant=tete;
        tete=donnee;
    }
    fclose(fp);
    return tete;
}
void ecriture(liste*tete)               ////////ecrire dans un fichier
{   liste *temporaire;
    FILE *fp;
    fp=fopen("paiment.txt","wt+");
    if(fp==NULL)
    {
        printf("Impossible d'ouvrir le fichier !");
        exit(1);
    }
     temporaire=tete;
    while(temporaire!=NULL)
    {
        fprintf(fp,"%s\n%s\n%s\n%s\n%s\n%s\n%s\n%f\n%d\t%d\t%d\n%d\t%d\t%d\n",temporaire->user.CIN,temporaire->user.nom,temporaire->user.prenom,temporaire->user.tele,temporaire->user.ville,temporaire->user.email,temporaire->user.code,temporaire->user.solde,temporaire->user.date_naissance.jour,temporaire->user.date_naissance.mois,temporaire->user.date_naissance.annee,temporaire->user.date_aujourd_hui.jour,temporaire->user.date_aujourd_hui.mois,temporaire->user.date_aujourd_hui.annee);
        temporaire=temporaire->suivant;
    }
    fclose(fp);

}
void modification(char C[10])
{   int choix;
    char temp_code[10];
    FILE *fp;
    liste *l=NULL;
    liste *temporaire;
    l=lire(l);
    temporaire=l;
    while(temporaire!=NULL && strcmp(C,temporaire->user.CIN)!=NULL)
    {
        temporaire=temporaire->suivant;
    }

    if(temporaire!=NULL)
     {
                        printf("\t\tCHOISIR VOTRE CHOIX :\n");
                        printf("\t\t\t[1]CHANGER LE MOT DE PASSE\n");
                        printf("\t\t\t[2]CHANGER LE NUMERO DE TELEPHONE\n");
                        do
{
                            printf("\t\tVOTRE CHOIX EST :");
                            scanf("%d",&choix);
                        }while(choix!=1 && choix!=2);
                        if(choix==1)
                        {
                            printf("\t\tVEUILLEZ ENTRER VOTRE CODE ACTUEL : ");
                            scanf("%s",&temp_code);
                            printf("\n");
                            while(strcmp(temp_code,temporaire->user.code)!=0)
                            {
                                printf("\t\tCODE ERRONE !\n");
                                printf("\t\tVEUILLEZ ENTRER VOTRE CODE ACTUEL : ");
                                scanf("%s",&temp_code);
                            }
                            printf("\t\tSAISIR LE NOUVEAU CODE : ");
                            scanf("%s",temporaire->user.code);
                            printf("\t\tL'Operation est bien effectuer (: ");
                        }
                        else
                        {
                            printf("\t\tSAISIR VOTRE NOUVELLE NUMERO DE TELE : ");
                            scanf("%s",temporaire->user.tele);
                            printf("\t\tL'Operation est bien effectuer (: ");
                        }

                    }
    ecriture(l);

}
void recharge(char C[10],date d)
{    liste *temporaire,*l=NULL;
     utilisateur L;
     int tr=0,choix;
     sauvg M;
     l=lire(l);

    temporaire=l;
    while(temporaire!=NULL && strcmp(C,temporaire->user.CIN)!=NULL)
    {
        temporaire=temporaire->suivant;
    }

    if(temporaire!=NULL)
     {
        printf("\n\t\tLISTE DES OPERATIONS\n\n");
        printf("\t\t\t[1] Maroc Telecom\n");
        printf("\t\t\t[2] Orange\n");
        printf("\t\t\t[3] Inwi\n");
       do{
        printf("\t\tSaisir Votre Choix : ");
        scanf("%d",&choix);
         }while(choix!=1 && choix!=2 && choix!=3);
          switch(choix)
          {
          case 1:   {
                     do
                      {
                      printf("\n\t\tSaisir la valeur de recharge : ");
                      scanf("%f",&M.Montant);
                      }while(M.Montant<=0);
                      if(temporaire->user.solde>=M.Montant)
                      {     printf("\t\tNUMERO DE TELEPHONE : \n");
                      printf("\t\t\t\t\t");
                         getchar();
                         gets(M.ID);
                         printf("\t\tSaisir le motif : ");gets(M.Motif);
                            temporaire->user.solde=temporaire->user.solde-M.Montant;
                            strcpy(M.type,"recharge");
                            M.d=d;
                            strcpy(M.CIN,temporaire->user.CIN);
                            sauvgarder(M);
                            tr=1;
                       }
                      else
                      {
                        printf("\t\tSOLDE INSUFFISANT!!");
                        exit(1);
                       }
                break;}
          case 2:    {
                     do
                      {
                      printf("\n\t\tSaisir la valeur de recharge ");
                      scanf("%f",&M.Montant);
                      }while(M.Montant<=0);
                      if(temporaire->user.solde>=M.Montant)
                      {     printf("\t\tNUMERO DE TELEPHONE : \n");
                      printf("\t\t\t\t\t");
                         getchar();
                         gets(M.ID);
                         printf("\t\tSaisir le motif : ");gets(M.Motif);
                            temporaire->user.solde=temporaire->user.solde-M.Montant;
                            strcpy(M.type,"recharge");
                            M.d=d;
                            strcpy(M.CIN,temporaire->user.CIN);
                            sauvgarder(M);
                            tr=1;
                       }
                      else
                      {
                        printf("\t\tSOLDE INSUFFISANT!!");
                        exit(1);
                       }
                break;}
        case 3:    {
                     do
                      {
                      printf("\n\t\tSaisir la valeur de recharge ");
                      scanf("%f",&M.Montant);
                      }while(M.Montant<=0);
                      if(temporaire->user.solde>=M.Montant)
                      {     printf("\t\tNUMERO DE TELEPHONE : \n");
                      printf("\t\t\t\t\t");
                         getchar();
                         gets(M.ID);
                         printf("\t\tSaisir le motif : ");gets(M.Motif);
                            temporaire->user.solde=temporaire->user.solde-M.Montant;
                            strcpy(M.type,"recharge");
                            M.d=d;
                            strcpy(M.CIN,temporaire->user.CIN);
                            sauvgarder(M);
                            tr=1;
                       }
                      else
                      {
                        printf("\t\tSOLDE INSUFFISANT!!");
                        exit(1);
                       }
                break;}

}
     }
     if(tr==1);
      printf("\t\tOPERATION EST BIEN EFFECTUER\n ");
      ecriture(l);
}
/////////////////////////////////

void deposer (char C[10],date d)
{   liste *l,*temporaire;
    l=NULL;
    utilisateur L;
    sauvg M;
    l=lire(l);
    temporaire=l;
        while(temporaire!=NULL && strcmp(C,temporaire->user.CIN)!=NULL)
    {
        temporaire=temporaire->suivant;
    }

    if(temporaire!=NULL)
                {
                do {
                    printf("\t\tCOMBIEN VOULLEZ VOUS DEPOSER : ");
                    scanf("%f",&M.Montant);}
                    while(M.Montant<0);

                 temporaire->user.solde=temporaire->user.solde+M.Montant;
                 strcpy(M.CIN,temporaire->user.CIN);
                 strcpy(M.ID,temporaire->user.CIN);
                 strcpy(M.type,"depot");
                 strcpy(M.Motif,"--------");
                 M.d=d;
                 sauvgarder(M);
                }


    printf("\t\tL'OPERATION EST BIEN EFFECTUE (: ");
    ecriture(l);

}
///////////////////////////////////

void retrait(char C[10],date d)
{
    liste *temporaire,*l=NULL;
    utilisateur L;
    int tr=0;
    sauvg M;
    l=lire(l);

    temporaire=l;
    while(temporaire!=NULL && strcmp(C,temporaire->user.CIN)!=NULL)
    {
        temporaire=temporaire->suivant;
    }

    if(temporaire!=NULL)
     {
                do {printf("\t\tCOMBIEN VOULLEZ VOUS TIRER : ");scanf("%f",&M.Montant);}while(M.Montant<0);
                if(temporaire->user.solde>=M.Montant)
                {
                 tr=1;
                 temporaire->user.solde=temporaire->user.solde-M.Montant;
                 M.Montant=M.Montant;
                 strcpy(M.CIN,temporaire->user.CIN);
                 strcpy(M.ID,M.CIN);
                 strcpy(M.type,"retrait");
                 strcpy(M.Motif,"--------");
                 M.d=d;
                 sauvgarder(M);
                 }
                else
                    printf("\t\tSOLD INSIFISANT ): ");
            }

    ecriture(l);
        if(tr==1)
        printf("\t\tL'OPERATION EST BIEN EFFECTUER (: ");

}
////////////////////////////////

void virement(char C[10],date d)
{
    liste *temporaire,*l=NULL;
    utilisateur L;
    sauvg M;
    FILE *fp,*temp;
    int tr=0;
    l=lire(l);
    temporaire=l;
    while(temporaire!=NULL && strcmp(C,temporaire->user.CIN)!=NULL)
    {
        temporaire=temporaire->suivant;
    }

    if(temporaire!=NULL)
     {

                do{printf("\t\t\tCOMBIEN VOULLEZ VOUS TRANSMETTRE : ");scanf("%f",&M.Montant);}while(M.Montant<0);
                if(temporaire->user.solde>=M.Montant)
                {
                 tr=1;
                 printf("\t\t\tDONNER LE CIN DU DESTINATAIRE : ");
                 getchar();
                 gets(M.ID);
                 printf("\t\t\tSAISIR LE MOTIF : \n");printf("\t\t\t\t\t  ");gets(M.Motif);
                 temporaire->user.solde=temporaire->user.solde-M.Montant;
                 strcpy(M.type,"virement");
                 strcpy(M.CIN,temporaire->user.CIN);
                 M.d=d;
                 sauvgarder(M);
                 }
                else
                    printf("\t\t\tSOLD INSIFISANT !!!): ");
    }


        if(tr==1)
        printf("\t\t\tL'OPERATION EST BIEN EFFECTUER (: ");

ecriture(l);
}

////////////////////////////////////////////

void paye_facteur(char C[10],date d)
{   liste *temporaire,*l=NULL;
    sauvg N;
    utilisateur L;
    int tr=0,choix;
    FILE *fp;
    char fact[50];
    l=lire(l);
    temporaire=l;
    while(temporaire!=NULL && strcmp(C,temporaire->user.CIN)!=NULL)
    {
        temporaire=temporaire->suivant;
    }

    if(temporaire!=NULL)
     {

                      printf("\t\tPAYEZ VOUS FACTURE  ONLINE\n\n");
                      printf("\t\t\t[1] Telephonie et Internet \n");
                      printf("\t\t\t[2] Eau et Electricite \n");
                      printf("\t\t\t[3] Transport et Billetterie\n");
                      printf("\t\t\t[4] Associations\n");
                      printf("\t\t\t[5] Ecoles et Universites\n");
                      printf("\t\tSAISIR VOTRE CHOIX : ");scanf("%d",&choix);
                      printf("\n");
                      switch(choix)
                        {
                            case 1:{
                                   do{ printf("\t\tSAISIR LE MONTANT A PAYER : ");scanf("%f",&N.Montant);}while(N.Montant<0);
                                    if(temporaire->user.solde>=N.Montant)
                                    {    tr=1;
                                    strcpy(N.ID,temporaire->user.tele);
                                    strcpy(N.Motif,"Telephonie_et_Internet");
                                    strcpy(N.type,"Payment_facture");
                                    strcpy(N.CIN,temporaire->user.CIN);
                                    temporaire->user.solde=temporaire->user.solde-N.Montant;
                                    N.d=d;
                                    sauvgarder(N);
                                    }
                                   else
                                    {
                                     printf("\t\tSOLD INSUFISSANT !\n");
                                     exit(0);
                                    }
                                    break;}
                            case 2: {
                                   do{ printf("\t\tSAISIR LE MONTANT A PAYER : ");scanf("%f",&N.Montant);}while(N.Montant<0);
                                    if(temporaire->user.solde>=N.Montant)
                                    {    tr=1;

                                    strcpy(N.ID,temporaire->user.CIN);
                                    strcpy(N.Motif,"\t\tEau_et_Electricit ");
                                    strcpy(N.type,"Payment_facture");
                                    strcpy(N.CIN,temporaire->user.CIN);
                                    temporaire->user.solde=temporaire->user.solde-N.Montant;
                                    N.d=d;
                                    sauvgarder(N);
                                    }
                                   else
                                    {
                                     printf("\t\tSOLD INSUFISSANT !\n");
                                     exit(0);
                                    }
                                    break;}


                          case 3: {
                                    do{ printf("\t\tSAISIR LE MONTANT A PAYER : ");scanf("%f",&N.Montant);}while(N.Montant<0);
                                    if(temporaire->user.solde>=N.Montant)
                                    {    tr=1;
                                    printf("\t\tSAISIR LE NOM DE L AGENCE DE TRANSPORT : ");
                                    getchar();
                                    gets(N.ID);
                                    strcpy(N.Motif,"Transport_et_Billetterie");
                                    strcpy(N.type,"Payment_facture");
                                    strcpy(N.CIN,temporaire->user.CIN);
                                    temporaire->user.solde=temporaire->user.solde-N.Montant;
                                    N.d=d;
                                    sauvgarder(N);
                                    }
                                   else
                                    {
                                     printf("\t\tSOLD INSUFISSANT !\n");
                                     exit(0);
                                    }
                                    break;}
                         case 4:  {
                                   do{ printf("\t\tSAISIR LE MONTANT A PAYER : ");scanf("%f",&N.Montant);}while(N.Montant<0);
                                    if(temporaire->user.solde>=N.Montant)
                                    {    tr=1;
                                    printf("\t\tSAISIR LE NOM DE L ASSOCIATION : " );
                                    getchar();
                                    gets(N.ID);
                                    strcpy(N.Motif,"ASSOCIATION");
                                    strcpy(N.type,"Payment_facture");
                                    strcpy(N.CIN,temporaire->user.CIN);
                                    temporaire->user.solde=temporaire->user.solde-N.Montant;
                                    N.d=d;
                                    sauvgarder(N);
                                    }
                                   else
                                    {
                                     printf("\t\tSOLD INSUFISSANT !\n");
                                     exit(0);
                                    }
                                    break;}

                        case 5 :{
                                   do{ printf("\t\tSAISIR LE MONTANT A PAYER : ");scanf("%f",&N.Montant);}while(N.Montant<0);
                                    if(temporaire->user.solde>=N.Montant)
                                    {    tr=1;
                                    printf("\t\tSAISIR LE NOM DE L ECOLE OU DE L UNIVERSITE : " );
                                    getchar();
                                    gets(N.ID);
                                    strcpy(N.Motif,"ECOLE_OU_UNIVERSITE");
                                    strcpy(N.type,"Payment_facture");
                                    strcpy(N.CIN,temporaire->user.CIN);
                                    temporaire->user.solde=temporaire->user.solde-N.Montant;
                                    N.d=d;
                                    sauvgarder(N);
                                    }
                                   else
                                    {
                                     printf("\t\tSOLD INSUFISSANT !\n");
                                     exit(0);
                                    }
                                    break;}
                            default : {printf("\t\tCHOIX INTROUVABLE" );break;}

                        }




        if(tr==1)
        printf("\t\tPAIMENT BIEN EFFECTUER");
    ecriture(l);

}

///////////////////////////////////

}
void historique(char C[10])
{
    FILE *sauv;
    sauvg M;
    int tr=0;
    sauv=fopen("historique.txt","rt");
    if(sauv==NULL)
    {
        printf("erreur");
        exit(1);
    }
    while(fscanf(sauv,"%s\n%s\n%s\n%s\n%d\n%d\n%d\n%f\n",M.CIN,M.ID,M.type,M.Motif,&M.d.jour,&M.d.mois,&M.d.annee,&M.Montant)==8)
{
    if(strcmp(C,M.CIN)==0)
    {
         printf("\t\t\tCIN OU ID : %s\n\t\t\tTYPE : %s\n\t\t\tMOTIF : %s\n\t\t\tDATE : %d/%d/%d\n\t\t\tMONTANT : %f\n",M.ID,M.type,M.Motif,M.d.jour,M.d.mois,M.d.annee,M.Montant);
         printf("\n\t\t\txcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n\n");

    }
}

fclose(sauv);
}

/////////////////////////////

void connecter()
{

     system("COLOR 4");
    char c[10],p[10];
    int i=0,t;
    date d;
    utilisateur L;
    int choix;
    FILE *fp;
    fp=fopen("paiment.txt","rt");
    if(fp==NULL)
    {
        printf("erreur ");
        exit(1);
    }
    system("cls");
        printf("\n\t\tAUTHENTIFICATION \n");
        printf("\t\t    CIN : ");
        getchar();
        scanf("%s",c);

           while(fscanf(fp,"%s\n%s\n%s\n%s\n%s\n%s\n%s\n%f\n%d\t%d\t%d\n%d\t%d\t%d\n",L.CIN,L.nom,L.prenom,L.tele,L.ville,L.email,L.code,&L.solde,&L.date_naissance.jour,&L.date_naissance.mois,&L.date_naissance.annee,&L.date_aujourd_hui.jour,&L.date_aujourd_hui.mois,&L.date_aujourd_hui.annee)==14 && strcmp(c,L.CIN)!=0)
               continue;
        if(strcmp(c,L.CIN)==0 )
        {    connecter:
             printf("\t\t    mote de passe : ");
            getchar();
            scanf("%s",p);
            if(strcmp(p,L.code)==0)
            {
                     system("cls");
                     printf("\n\n\t\tBIENVENUE %s %s",L.nom,L.prenom);
                     printf("\n\t\t\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n\n");
                     printf("\t\t\t[1]  ACCEDER AUX MES INFORMATIONS\n");
                     printf("\t\t\t[2]  EFFECTUEZ UN VIREMENT\n");
                     printf("\t\t\t[3]  EFFECTUEZ UNE RECHARGE \n");
                     printf("\t\t\t[4]  PAYEZ VOS FACTURE \n");
                     printf("\t\t\t[5]  DEPOSER \n");
                     printf("\t\t\t[6]  RETRAIT \n");
                     printf("\t\t\t[7]  MODIFIER MES INFORMATION \n");
                     printf("\t\t\t[8]  HISTORIQUE DE MES PAIMENTS \n");
                     printf("\t\t\t[9]  EXIT\n");
                     d=time();
                     do{
                        printf("\n\t\tVeuillez choisir le numero correspond a votre desir : ");
                        scanf("%d",&choix);
                        switch(choix)
                               {


                                     case 1: {Acceder(L.CIN);break;}
                                     case 2: {virement(L.CIN,d);break;}
                                     case 3: {recharge(L.CIN,d);break;}
                                     case 4: {paye_facteur(L.CIN,d);break;}
                                     case 5: {deposer(L.CIN,d);break;}
                                     case 6: {retrait(L.CIN,d);break;}
                                     case 7: {modification(L.CIN);break;}
                                     case 8: {historique(L.CIN);break;}
                                     case 9: {printf("\t\tA BIENTOT %s %s ",L.nom,L.prenom);exit(0);}
                                }
                                    }while(choix!=9);
                       }
                    else
                    {   printf("\t\t      MOTE DE PASSE INCORRECTE !\n");
                                    i++;
                                if(i==4)
                            {
                                printf("\t\t      VOUS AVEZ DEPASSER LE NOMBRE MAXIMAL DE TENTATIVE ! A BIENTOT \n");
                                    exit(1);
                            }
                                goto connecter;
                    }

                }
            else
            {
                printf("\t\t  AUCUNE COMPTE CORRESPANT A CE CIN !" );
                exit(1);
            }


}



int main()
{
    int choix;
    asciiART();
    debut:
system("COLOR 9");
    printf("\n\n\t\tBIENVENUE");
    printf("\n\t\t\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n\n");
    printf("\t\t   [1] CONNECTION \n");
    printf("\t\t   [2] CREER UN COMPTE\n");
    printf("\t\t   [3] EXIT\n\n");
            printf("\t\tVeuillez choisir votre choix : ");scanf("%d",&choix);
            switch(choix)
            {
          case 1: {connecter();break;}
          case 2: {creation_compte();break;}
          case 3: exit(1);
          default: {printf("\t\tVeuillez saisir un nombre convenable !!\n");
                    goto debut;}


            }




return 0;
}
