#include <stdio.h>
#include <string.h>
#include<conio.h>
#include <stdlib.h>
#include <time.h>
//time delay finction with
void delay(int number_of_seconds)
{
    // Converting time into milli_seconds
    int milli_seconds = 1000 * number_of_seconds;

    // Storing start time
    clock_t start_time = clock();

    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds);

}
//vote pattern print function
void e_vote_patter_animation()
{
    printf("\n");
    printf("  ===================");
    printf("                ");
    printf("\\             //");
    printf("   ===================");
    printf("   ===================");
    printf("   ===================");
    printf("\n");
    delay(1);
    printf("  ||                 ");
    printf("                ");
    printf(" \\           // ");
    printf("  ||                ||");
    printf("            ||        ");
    printf("   ||                 ");
    printf("\n");
    delay(1);
    printf("  ||                 ");
    printf("                ");
    printf("  \\         //  ");
    printf("  ||                ||");
    printf("            ||        ");
    printf("   ||                 ");
    printf("\n");
    delay(1);
    printf("  ||                 ");
    printf("                ");
    printf("   \\       //   ");
    printf("  ||                ||");
    printf("            ||        ");
    printf("   ||                 ");
    printf("\n");
    printf("  ===================");
    printf("     =======    ");
    printf("    \\     //    ");
    printf("  ||                ||");
    printf("            ||        ");
    printf("   ===================");
    printf("\n");
    delay(1);
    printf("  ||                 ");
    printf("                ");
    printf("     \\   //     ");
    printf("  ||                ||");
    printf("            ||        ");
    printf("   ||                 ");
    printf("\n");
    delay(1);
    printf("  ||                 ");
    printf("                ");
    printf("      \\ //      ");
    printf("  ||                ||");
    printf("            ||        ");
    printf("   ||                 ");
    printf("\n");
    delay(1);
    printf("  ===================");
    printf("                ");
    printf("       \\/       ");
    printf("   ===================");
    printf("            ||        ");
    printf("   ===================");
    printf("\n");
}

//create new structure for vote admin
struct v_admin
{
    char name[30];
    char pass[30];
};
//create new structure for vote admin
struct v_public
{
    ;
    char id[30];
    int v_choice;
};

struct v_prarthi
{
    char name[30];
    int num_vote;
};

//function Number of line count in file
int file_line_count(FILE *file)
{
    int cnt=0;
    for (char c = getc(file); c != EOF; c = getc(file))
    {
        if (c == '\n')
        {
            cnt = cnt + 1;
        }
    }
    return cnt;
}

//function for voter activity check
int voter_activity(char nid[30],int cnt, struct v_public voter[cnt])
{
    for(int i=0; i<cnt; i++)
    {
        if(strcmp(nid,voter[i].id)==0)
        {
            if( voter[i].v_choice==0)
            {
                return i;
                break;
            }
            else
            {
                return -1;
            }

        }
    }
    return -2;
}

// account verification function.
int password_verification(int cnt,char input[30],char pass[30],struct v_admin ad[cnt])
{
    for(int i=0; i<cnt; i++)
    {
        if (strcmp(input, ad[i].name) == 0)
        {
            if (strcmp(pass, ad[i].pass) == 0)
            {
                //  puts(pass);
                return 1;
            }
            else
            {
                //puts(pass);
                return 0;
            }
        }
    }
    //puts(pass);
    return 0;

}




//function for username existance check
int username_existance_check(char input[30])
{
    int cnt_u=0;
    char in[30];
    FILE *file1;
    file1=fopen("password.txt","r");
    cnt_u=file_line_count(file1);
    fclose(file1);
    file1=fopen("password.txt","r");
    for(int i=0; i<cnt_u*2; i++)
    {
        fscanf(file1,"%s",in);
        if(i%2==0)
        {
            if(strcmp(input,in)==0)
            {
                fclose(file1);
                return 1;
            }
            else
            {
                continue;
            }
        }
    }
    fclose(file1);
    return 0;
}

//function for NID existance check
int nid_existance_check(char input[30])
{
    int cnt_u=0;
    char in[30];
    FILE *file1;
    file1=fopen("voter.txt","r");
    cnt_u=file_line_count(file1);
    fclose(file1);
    file1=fopen("voter.txt","r");
    for(int i=0; i<cnt_u; i++)
    {
        fscanf(file1,"%s",in);
        if(strcmp(input,in)==0)
        {
            fclose(file1);
            return 1;
        }
        else
        {
            continue;
        }
    }
    fclose(file1);
    return 0;
}


int prarthi_existance_check(char input[30])
{
    int cnt_p=0;
    char in[30];
    FILE *file1;
    file1=fopen("prarthi.txt","r");
    cnt_p=file_line_count(file1);
    fclose(file1);
    file1=fopen("prarthi.txt","r");
    for(int i=0; i<cnt_p; i++)
    {
        fscanf(file1,"%s",in);
        if(strcmp(input,in)==0)
        {
            fclose(file1);
            return 1;
        }
        else
        {
            continue;
        }
    }
    fclose(file1);
    return 0;
}

int prarthi_update(char old_prarthi[30])
{
    int cnt_p=0;
    FILE *file1;
    file1=fopen("prarthi.txt","r");
    cnt_p=file_line_count(file1);
    fclose(file1);
    file1=fopen("prarthi.txt","r");

    struct v_prarthi vp[cnt_p];//prarthi structure array
    for(int i=0; i<cnt_p; i++) //prarthi structure array initialization
    {
        fscanf(file1, "%s \n", vp[i].name);
        vp[i].num_vote=0;
        fflush(stdin);
    }
    fclose(file1);// Close the file
    // End of prarthi extraction and insert it to a structure
    for(int i=0; i<cnt_p; i++) //prarthi structure array initialization
    {
        if(strcmp(old_prarthi,vp[i].name)==0)
        {
            printf("Enter the updated prarthi name: \n");
            fflush(stdin);
            gets(vp[i].name);
            if(prarthi_existance_check(vp[i].name)==1)
            {
                printf("Someone already have this name\n");
                return 0;
            }
            else
            {
                file1=fopen("prarthi.txt","w");
                for(int i=0; i<cnt_p; i++) //prarthi structure array initialization
                {
                    fprintf(file1, "%s \n", vp[i].name);
                    vp[i].num_vote=0;
                    fflush(stdin);
                }
                fclose(file1);// Close the file
                printf("Successfully Name updated\n");
                return 0;
            }


        }
        else
        {
            continue;
        }
    }
    printf("\n\nName dont exist \n");
    return 0;

}

int prarthi_partial_search(char partial_prarthi[30])
{
    int cnt_p=0;
    FILE *file1;
    file1=fopen("prarthi.txt","r");
    cnt_p=file_line_count(file1);
    fclose(file1);
    file1=fopen("prarthi.txt","r");

    struct v_prarthi vp[cnt_p];//prarthi structure array
    for(int i=0; i<cnt_p; i++) //prarthi structure array initialization
    {
        fscanf(file1, "%s \n", vp[i].name);
        vp[i].num_vote=0;
        fflush(stdin);
    }
    fclose(file1);// Close the file
    printf("\n\nPartial Searched Result: \n\n");
    for(int i=0; i<cnt_p; i++)
    {
        if(strstr(vp[i].name, partial_prarthi))
        {
            printf("\nPrarthi Name: ");
            puts(vp[i].name);
            printf("\n\n\n");
        }
    }

}


int prarthi_delect(char d_prarthi[30])
{
    int cnt_p=0,z=0;
    FILE *file1;
    file1=fopen("prarthi.txt","r");
    cnt_p=file_line_count(file1);
    fclose(file1);
    file1=fopen("prarthi.txt","r");

    struct v_prarthi vp[cnt_p];//prarthi structure array
    for(int i=0; i<cnt_p; i++) //prarthi structure array initialization
    {
        fscanf(file1, "%s \n", vp[i].name);
        //puts(vp[i].name);
        vp[i].num_vote=0;
        fflush(stdin);
    }
    fclose(file1);// Close the file
    printf("\n\nPartial Searched Result: \n\n");
    for(int i=0; i<cnt_p; i++)
    {
        if(strcmp(vp[i].name,d_prarthi)==0)
        {
            printf("\nPrarthi Found: %s",vp[i].name);
            for(int k=i; k<cnt_p; k++)
            {
                strcpy(vp[k].name,vp[k+1].name);
            }
            printf("\n\n\n");
            printf("\nSuccessfully Deleted");
            file1=fopen("prarthi.txt","w");
            for(int i=0; i<cnt_p-1; i++) //prarthi structure array initialization
            {
                fprintf(file1, "%s \n", vp[i].name);
                vp[i].num_vote=0;
                fflush(stdin);
            }
            fclose(file1);// Close the file
            return 0;

        }
    }
    printf("\nPrarthi Name Not Found\n");


}


void view_prarthi()
{
    int cnt_p=0;
    char prarthi_name[30];
    FILE *file1;
    file1=fopen("prarthi.txt","r");
    cnt_p=file_line_count(file1);
    fclose(file1);
    file1=fopen("prarthi.txt","r");
    for(int i=0; i<cnt_p; i++) //prarthi structure array initialization
    {
        printf("%d Prarthi Name: ",i+1);
        fscanf(file1, "%s \n", prarthi_name);
        puts(prarthi_name);
        printf("\n\n");
    }
    fclose(file1);// Close the file
}



void view_voter()
{
    int cnt_p=0;
    char voter_nid[30];
    FILE *file1;
    file1=fopen("voter.txt","r");
    cnt_p=file_line_count(file1);
    fclose(file1);
    file1=fopen("voter.txt","r");
    for(int i=0; i<cnt_p; i++) //voter structure array initialization
    {
        printf("%d voter nid: ",i+1);
        fscanf(file1, "%s \n", voter_nid);
        puts(voter_nid);
        printf("\n\n");
    }
    fclose(file1);// Close the file
}


int main()
{
    e_vote_patter_animation();
    printf("\n\n                                                    Welcome To The E-Voting System\n");
    int ch=1000;
    getch();
    system("cls");
    while(ch!=0)
    {
        printf("\n\n                                                    Welcome To The E-Voting System\n");
        int i=0;
        char c='\0';
        printf("\n");
        printf("1.Register\n");
        printf("2.Voter List Entry\n");
        printf("3.Login\n");
        printf("4.Enter Prarthi\n");
        printf("5.Prarthi update\n");
        printf("6.Partial Search For Prarthi Name\n");
        printf("7.Prarthi Name Delete\n");
        printf("8.Voter NID Search\n");
        printf("9.Prarthi List View\n");
        printf("10.Voter List View\n");
        printf("0.Exit\n");
        printf("\nEnter The Option: \n");
        scanf("%d",&ch);

        //registration Portion for vote administrator
        if(ch==1)
        {
            system("cls");
            printf("\n-----------------------Admin Register-------------------------\n");
            FILE *file;
            char input[30],pass[30];
            int uname_checker=0;
            file=fopen("password.txt","a");
            printf("Enter the username: \n");//enter username input to console
            fflush(stdin);
            scanf("%s", input);

            if(file==NULL)
            {
                printf("file doesn't exist");
            }
            else
            {
                printf("Enter the Password: \n");
                i = 0;
                c = '\0';
                fflush(stdin);
                while ((c = getch()) !=13)
                {
                    pass[i]=c;
                    printf("*");
                    i++;
                }
                uname_checker=username_existance_check(input);
                if(uname_checker==1)
                {
                    printf("\n\nalready exist\n\n");
                }
                else
                {
                    fprintf(file,"%s %s \n",input,pass);
                    printf("\n\nsucessfully registered\n");
                    fclose(file);
                }
                printf("\n------------------------------------------------\n");
            }
            getch();
            system("cls");
        }
        //End of registration Portion for vote administrator
        else if(ch==2)
        {
            system("cls");
            printf("\n-----------------------Enter Voter List-------------------------\n");
            FILE *file_v;
            int nid_checker=0;
            char nid[10];

            printf("\nPress any key to insert data\n");

            char ext;
            while((ext=getch())!=27)
            {
                file_v=fopen("voter.txt","a");
                if(file_v==NULL)
                {
                    printf("voter.txt file doesn't exist");
                }
                printf("Enter the NID: \n");
                fflush(stdin);
                gets(nid);
                nid_checker=nid_existance_check(nid);
                if(nid_checker==1)
                {
                    printf("already exist");
                }
                else
                {
                    fprintf(file_v,"%s \n",nid);
                    printf("%s Done\n",nid);
                }
                fclose(file_v);
                printf("\nPress Enter again to insert next Data or press Esc to exit\n");
            }


            printf("\n------------------------------------------------\n");
            getch();
            system("cls");

        }//else if for ch==2


        else if(ch==4)
        {
            system("cls");
            printf("\n-----------------------Enter Prarthi List-------------------------\n");
            FILE *filep;
            char prarthi[30],m;
            int prarthi_checker=0;

            printf("Enter any key to insert parthi name: \n");
            while((m=getch())!=27)
            {
                filep=fopen("prarthi.txt","a");
                printf("Enter the parthi name: \n");//enter username input to console
                fflush(stdin);
                scanf("%s", prarthi);
                if(filep==NULL)
                {
                    printf("file doesn't exist");
                }
                else
                {
                    prarthi_checker=prarthi_existance_check(prarthi);
                    if(prarthi_checker==1)
                    {
                        printf("already exist\n");
                    }
                    else
                    {
                        fprintf(filep,"%s \n",prarthi);
                        printf("\n\nsucessfully registered\n");


                    }
                    fclose(filep);
                    printf("Enter any key to insert parthi name or exit pressing ESC button: \n\n");
                }

            }

            printf("\n-------------------------------------------------------------\n");
            getch();
            system("cls");
        }

        //Prarthi Update
        else if(ch==5)
        {
            system("cls");
            printf("\n-----------------------------update parthi name--------------------------------\n");
            char old_prarthi[30];
            printf("Enter the Older Name that you want to replace: \n");
            fflush(stdin);
            scanf("%s", old_prarthi);
            prarthi_update(old_prarthi);
            getch();
            system("cls");

        }

        //prarthi Partial Search
        else if(ch==6)
        {
            system("cls");
            printf("\n-----------------------------Partial Search Of Parthi Name--------------------------------\n");
            char p_prarthi[30];
            printf("Enter the Name for Parthi Partial Search: \n");
            fflush(stdin);
            scanf("%s", p_prarthi);
            prarthi_partial_search(p_prarthi);
            printf("\n------------------------------------------------\n");
            getch();
            system("cls");

        }

        else if(ch==7)
        {
            system("cls");
            printf("\n-----------------------------Parthi Name Delect--------------------------------\n");
            char d_prarthi[30];
            printf("Enter the Name of Parthi for delect: \n");
            fflush(stdin);
            scanf("%s", d_prarthi);
            prarthi_delect(d_prarthi);
            printf("\n------------------------------------------------\n");
            getch();
            system("cls");

        }
        else if(ch==8)
        {
            system("cls");
            printf("\n-----------------------------Voter NID Search--------------------------------\n");
            char find_nid[30];
            int check;
            printf("Enter the NID of voter: \n");
            fflush(stdin);
            scanf("%s", find_nid);
            check=nid_existance_check(find_nid);
            if(check==1)
            {
                printf("\n%s NID number found in the system\n",find_nid);
            }
            else
            {
                printf("\n%s NID number not found in the system\n",find_nid);
            }
            printf("\n------------------------------------------------\n");
            getch();
            system("cls");

        }
        else if(ch==9)
        {
            system("cls");
            printf("-----------------------------List Of Prarthi--------------------------------\n\n");
            view_prarthi();
            printf("\n------------------------------------------------\n");
            getch();
            system("cls");
        }
        else if(ch==10)
        {
            system("cls");
            printf("-----------------------------List Of Voter--------------------------------\n\n");
            view_voter();
            printf("\n------------------------------------------------\n");
            getch();
            system("cls");
        }

        // Login Portin
        else if(ch==3)
        {
            system("cls");
            printf("\n-----------------------Login-------------------------\n");
            FILE *file = fopen("password.txt", "r"); // Open the file in read mode
            int cnt;
            if (file == NULL)
            {
                printf("Error opening file.\n");
                return 1;
            }



            cnt=file_line_count(file);//file line count fuction
            fclose(file);// Close the file


            //username and password extraction and insert it to a structure
            file = fopen("password.txt", "r"); // file open
            struct v_admin ad[cnt];//admin structure array
            for(int i=0; i<cnt; i++) //admin structure array initialization
            {
                fscanf(file, "%s %s", ad[i].name, ad[i].pass);
                fflush(stdin);
            }
            fclose(file);// Close the file
            // End of username and password extraction and insert it to a structure
//-------------------------------------------------------------------okkkokokokkkoko*****************************
            FILE *filep;
            fflush(stdin);
            filep=fopen("prarthi.txt","r");
            int cnt_p=file_line_count(filep);
            int k=cnt_p;
            fclose(filep);

            filep=fopen("prarthi.txt","r");
            struct v_prarthi vp1[cnt_p];//prarthi structure array
            for(int i=0; i<cnt_p; i++) //prarthi structure array initialization
            {
                fscanf(filep, "%s \n", vp1[i].name);
                // puts(vp1[i].name);
                vp1[i].num_vote=0;
                fflush(stdin);
            }
            fclose(filep);
//-------------------------------------------------------------------okokokkokokokokookokkoko****************************
            //enter username & password portion to console
            char input[30],pass[30]= {};
            printf("Enter the username: \n");//enter username input to console
            fflush(stdin);
            scanf("%s", input);
            // Display an asterisk (`*`) character for each character that is entered to console.
            printf("Enter the Password: \n");
            i = 0;
            c='\0';
            fflush(stdin);
            while ((c = getch()) !=13)
            {
                pass[i]=c;
                printf("*");
                i++;
                fflush(stdin);
            }
            printf("\n");// end of password input portion
            //end of enter username & password portion to console
            // account verification.
            int d=password_verification(cnt,input,pass,ad);
            //---------------------------------------------------------------After password verification voting operation starts-------------------------
            if (d == 1)
            {
                FILE *file_v;
                int a=0,b=0,vote_checker,cnt_p=k,v_ch1=0;
                char nid[30],v_ch='-';
                file_v=fopen("voter.txt","r");
                int cnt_v;
                cnt_v=file_line_count(file_v);//file line count fuction
                fclose(file_v);// Close the file
                //-------------------------------------------------------structure array initialization
                file_v=fopen("voter.txt","r"); // file open
                struct v_public voter[cnt_v];//voter strcture array
                if(file_v==NULL)
                {
                    printf("voter.txt file doesn't exist");
                }
                for(int i=0; i<cnt_v; i++) //voter strcture array initialization
                {
                    fscanf(file_v, "%s", voter[i].id);
                    voter[i].v_choice=0;
                }
                fclose(file_v);

                //--------------------------------------------------------------------------------------------------------
                while(v_ch!=27)
                {
                    system("cls");
                    printf("\n\nEnter the NID number or 000 for exit: \n");
                    fflush(stdin);
                    gets(nid);

                    vote_checker= voter_activity(nid,cnt_v,voter);
                    if(strcmp(nid,"000")==0)
                    {
                        break;
                    }
                    if(vote_checker>=0) //start of voter activtity condition
                    {
                        for(int i=0; i<cnt_p; i++) //prarthi structure array initialization
                        {
                            printf("Press %d for %s\n",i,vp1[i].name);
                            fflush(stdin);
                        }
                        fflush(stdin);
                        printf("\n\nEnter the vote\n");
                        scanf("%d",&v_ch1);
                        printf("\n");

                        if(v_ch1<cnt_p)
                        {
                            //voter activity checck
                            vp1[v_ch1].num_vote=vp1[v_ch1].num_vote+1;
                            printf("\nSuccessfully done\n");
                            printf("\n\nEnter any key to insert next\n");
                            voter[vote_checker].v_choice=-1;
                        }
                        else
                        {
                            printf("\n\nPressed the worng key\n\n");
                        }

                    }//end of voter activtity condition
                    else if(vote_checker==-1)
                    {

                        printf("already voted\n");
                        getch();
                    }
                    else if(vote_checker==-2)
                    {

                        printf("invalid Voter or mayebe from other city\n");
                        getch();
                    }
                    //system("cls");
                }//loop end
                FILE *rpw = fopen("report.txt", "w");
                for(int i=0; i<cnt_p; i++)
                {
                    printf("Prarthi %s has %d votes\n",vp1[i].name,vp1[i].num_vote);
                    fprintf(rpw, "Prarthi %s has %d votes\n",vp1[i].name,vp1[i].num_vote);
                }
                int max_num=vp1[0].num_vote,prth_id=0,chk_cnt=0;

                for(int i=0; i<cnt_p; i++)
                {
                    if(vp1[i].num_vote>max_num)
                    {
                        max_num=vp1[i].num_vote;
                        prth_id=i;
                    }

                }
                printf("\nHighest Vote list: \n\n");
                fprintf(rpw, "\nHighest Vote list: \n\n");
                for(int i=0; i<cnt_p; i++)
                {
                    if(vp1[i].num_vote==max_num && max_num!=0)
                    {
                        printf("Prarthi %s has highest vote with %d votes\n",vp1[i].name,max_num);
                        fprintf(rpw, "Prarthi %s has highest vote with %d votes\n",vp1[i].name,max_num);
                        chk_cnt=chk_cnt+1;
                    }

                }
                if(chk_cnt==0)
                {
                    printf("\nResult: \n\n");
                    fprintf(rpw, "\nResult: \n\n");
                    printf("No one voted\n\n");
                    fprintf(rpw, "No one voted\n\n");
                }
                else if(chk_cnt>1)
                {
                    printf("\nResult: \n\n");
                    fprintf(rpw, "\nResult: \n\n");
                    printf("Draw");
                    fprintf(rpw, "Draw");
                }
                else
                {
                    printf("\nResult: \n\n");
                    printf("Prarthi %s Wins with the highest vote of %d votes\n",vp1[prth_id].name,max_num);
                    fprintf(rpw,"\nResult: \n\n");
                    fprintf(rpw,"Prarthi %s Wins with the highest vote of %d votes\n",vp1[prth_id].name,max_num);
                }
                fclose(rpw);
                //------------------------------------------------------------------------------------------voting operation-------------------------
            }
            else
            {
                printf("\nAccess denied.");
            }
            printf("\n------------------------------------------------\n");
            fflush(stdin);
            getch();
            system("cls");
        }// end of account verification
        else
        {
            break;
        }


    }//main while lopp
    //end of login portion

    printf("Thank For Using it\n");

    return 0;
}
