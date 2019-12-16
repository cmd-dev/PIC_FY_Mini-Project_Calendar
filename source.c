#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int valid_date(int dd, int mm, int yy);
void daytoweek();

int i,y, m, d, n=0, j, k, l,q,counter,c=0,w;
int year;

int get_1st_weekday(int year);


struct Note
{ 
int d;
int m;
int y;
char note[100];
  };
  struct Note nt[20];
 
void calendar_disp(int year, struct Note nt[]);
int note_indication(struct Note nt[],int year,int month , int day);
void add_note(struct Note a[]);

int main()
       
       
    
{

int choice;

while(1) {

    printf("\n\n1. Add note(s) to specific dates \n");
   
    printf("2. Print monthly calendar of a year with indication of when a note is saved \n");
   

   printf("3.Find the day for a given date \n");
  

   printf("4. Display notes in tabular form \n");
  
   printf("5. Exit \n");
  

   printf("Enter your choice:\n ");
     
   scanf("\n%d", &choice);
     
    if(choice==1)    
       { printf("Enter the number of notes to be added\n ");
       scanf("%d",&n );}
    
   
        
      switch(choice) {
         
         

        case 1:
       
        
           add_note(nt);
       
     
       
   
      
        break;

        case 2:
     
     
        printf ("\nEnter your desired year:");
        scanf (" %d", &year) ;
        fflush(stdin);
        calendar_disp(year, nt);
        //printf("Please enter 's' to see the notes\n Press any other key to continue\n");
        break;
       
        case 3:
            


         daytoweek();
    
            break;
           
           
        case 4:
       
            for(q=0;q<n;q++)
            {
              printf("\nIn the year %d\n\n",nt[q].y);
             
                for(w=0;w<n;w++)
                {
                    if(nt[q].y==nt[w].y)
                     counter++;
                }
               
               printf("You have saved %d notes\n\n",counter);
               while(c!=n)
 
               {
                  if(nt[q].y==nt[c].y)



	printf("Note no. %d , Dated:%d/%d/%d Message : %s\n",c+1,nt[c].d,nt[c].m,nt[c].y,nt[c].note);
           
                   c++;
              
               }
   			counter=0;
			c=0;
      
            }
          
          break;
        case 5:

            goto Endwhile;
          

           break;

        default:

           printf("Not a valid option\n");

           break;

}

}
Endwhile:;
   
return 0;
}
  

///////////////
void calendar_disp(int year, struct Note nt[])
{
    
    
int month, day, daysInMonth, weekDay=0,startingDay;

char *months []={"January", "February", "March", "April", "May", "June", "July", "August", "September","October","November","December"} ;

int monthDay []={ 31,28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

if ( (year%4==0&&year%100!=0)|| year%400==0)

monthDay[1]= 29;

startingDay=get_1st_weekday(year);

for (month=0; month<12;month++) {

daysInMonth=monthDay[month];

printf("\n\n-----------------%s---------------- \n",months [month]);

printf("\n  Sun  Mon  Tue  Wed Thurs  Fri Sat\n \n");

for (weekDay=0;weekDay<startingDay;weekDay++) {

printf ("     ");
}


for (day=1;day<=daysInMonth;day++)
{

note_indication(nt,year,month ,day);

if (++weekDay>6){

printf("\n");

weekDay=0;

}

startingDay=weekDay;

}

}
}

/////////////////
void add_note(struct Note nt[])
   {for(i=0;i<n;i++)
    {
       
   
     printf("Enter the year for note number %d \n", i+1);
     scanf("%d",&nt[i].y );
     printf("Enter the month for note number %d\n", i+1);
     scanf("%d",&nt[i].m );
     printf("Enter the day for note number %d\n", i+1);
     scanf("%d",&nt[i].d);
     printf("Enter the note/reminder to be saved for note number %d\n", i+1);
     scanf("%s", nt[i].note);
    }
   
   
   
   
    printf("Your notes have been saved successfully ");}
///////////////
int note_indication(struct Note nt[],int year,int month , int day)
{
    int isnote=0;

                 
    for(j=0;j<n;j++)
     {  if(year==nt[j].y && (month+1)==nt[j].m && day-1==nt[j].d)          
             {printf("*");
              isnote=1;    }
     }
if(isnote==0)         
printf("%5d", day);
else
  printf("%4d", day);
   
   
   return 0;
}

////////////
int valid_date(int dd, int mm, int yy) {
    if (mm < 1 || mm > 12) {
        return 0;
    }
    if (dd < 1) {
        return 0;
    }

    int days = 31;
    if (mm == 2) {
        days = 28;
        if (yy % 400 == 0 || (yy % 4 == 0 && yy % 100 != 0)) {
            days = 29;
        }
    } else if (mm == 4 || mm == 6 || mm == 9 || mm == 11) {
        days = 30;
    }

    if (dd > days) {
        return 0;
    }
    return 1;
}
/////////////////////
int get_1st_weekday(int year)
{

int d;

d = (((year - 1) * 365) + ((year - 1) / 4) - ((year - 1) / 100) + ((year) / 400) + 1)%7;

return d;
}
/////////////
void daytoweek()
{
int month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
char week[7][10] ;
int day, mon, year, i, s = 0 ;
strcpy(week[0], "Sunday") ;
strcpy(week[1], "Monday") ;
strcpy(week[2], "Tuesday") ;
strcpy(week[3], "Wednesday") ;
strcpy(week[4], "Thursday") ;
strcpy(week[5], "Friday") ;
strcpy(week[6], "Saturday") ;
printf("Enter a valid date (dd/mm/yyyy) : ") ; 
scanf("%d / %d / %d", &day, &mon, &year) ;
int x=valid_date(day,mon,year);
if(x==1)
{//if ( (year%4==0&&year%100!=0)|| year%400==0)

//month[1]= 29;

// if( (year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0)) )
//{month[1] = 29 ;}
for(i = 0 ; i < mon - 1 ; i++)
{ s = s + month[i] ;
}
s = s + (day + year + (year / 4) - 2) ;
s = s % 7 ;
printf("\nThe day is : %s", week[s]) ;
}

else
printf("Invalid Date");}
///////////
