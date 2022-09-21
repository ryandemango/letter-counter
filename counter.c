#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

//CS 2600 project 1
//Ryan Mangilin

int main(){
  //reading from file
  char c,file[100];
  printf("Please Enter File Name: ");
  scanf("%s",file);//takes user input
  
  FILE *fp=fopen(file,"r");//creates pointer as well as opens given file name in reading mode

  if (fp==NULL){//prompts error message if file could not be loaded
    printf("Error Reading File, Please Try Again");
  }
  //declarations grouped in there respective roles 
  int a=0,e=0, i=0, o=0, u=0;
  int cons=0;
  int punct=0;
  int total=0;
  while ((c=getc(fp))!=EOF) {//read character by character unitl EOF or end of file
    printf("%c",c);//prints the contents of the file for reference
    if (isalpha(c)){//checks if the given character is alphabetical
      total++;//increments the total in a loop no matter the given character
	if (c=='a'|| c=='A'){//checks if the character is an a or A then increments a counter
	  a++;
	}
	else if (c =='e'||c=='E'){//checks if the character is an e or E then increments e counter
	  e++;
	}
	else if (c =='i'||c=='I'){//checks if the character is an i or Ithen increments i counter
          i++;
        }
	else if (c =='o'||c=='O'){//checks if the character is an o or O then increments o counter
          o++;
        }
	else if (c =='u'||c=='U'){//checks if the character is an u or U then increments u counter
          u++;
        }
	else{//if the character does not match any of the vowels it is a consonant and therefore increments the cons counter
	  cons++;
	}
      }
       
    else if (ispunct(c)){//checks if the given character is punctuation anf therefore will increment the punct as well as the total counter
	punct++;
	total++;
      }
  }
  fclose(fp);
  printf("total characters=%d; a=%d%%; e=%d%%; i=%d%%; o=%d%%; u=%d%%; consonants=%d%%; punctuation=%d%%\n", total,(a*100)/total,(e*100)/total,(i*100)/total,(o*100)/total,(u*100)/total,(cons*100)/total,(punct*100)/total);//prints each value to the console, multiplies each variable by 100 then divides by the total number of characters in order to get propper percentages

  FILE* out;//writes the same output into file called counterOutput.txt, if that file does not exist, it will create one
  out=fopen("counterOutput.txt","w");
  fprintf(out,"total characters=%d; a=%d%%; e=%d%%; i=%d%%; o=%d%%; u=%d%%; consonants=%d%%; punctuation=%d%%\n", total,(a*100)/total,(e*100)/total,(i*100)/total,(o*100)/total,(u*100)/total,(cons*100)/total,(punct*100)/total);
   fclose(out);
  return 0;
}
