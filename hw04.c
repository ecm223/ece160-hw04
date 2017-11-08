#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef enum {
  NAME_ONLY = 0,
  MAJOR_AND_NAME = 1, 
  YEAR_AND_NAME = 2,
  YEARS_LEFT_AND_NAME = 3
} Mode;

typedef struct {
  char *first_name;
  char *last_name;
  char *major;
  int year;
} Student;

void print_student(Mode m, Student s) {
  switch (m) {
    case 0:
      printf("%s %s\n", s.first_name, s.last_name);
      break;
    case 1:
      printf("%s %s %s\n", s.major, s.first_name, s.last_name);
      break;
    case 2:
      printf("%i %s %s\n", s.year, s.first_name, s.last_name);
      break;
    case 3:
      printf("%i %s %s\n", s.year - 2017, s.first_name, s.last_name);      
  }
}


int main(int argc, char *argv[]) {
  char *filename = argv[1];
  FILE *fp = fopen(filename, "r");
  char buffer[256];
  Student students[256];
  int i = 0; 
  while((fgets(buffer, 255, fp)) != NULL) {
    size_t len = strlen(buffer);
    size_t len_bytes = (len + 1) * sizeof(char);
    char *new_string = malloc(len_bytes);
    memcpy(new_string, buffer, len_bytes);
    Student s;
  
    s.first_name = malloc(256);
    s.last_name = malloc(256);
    s.major = malloc(256);
    sscanf(buffer, "%s %s %s %d", s.first_name, s.last_name, s.major, &s.year);
    students[i] = s;
    i++;


    /*s1.first_name = argv[i+2];
    s1.last_name = argv[i+3];
    s1.major = argv[i+4];
    s1.year = atoi(argv[i+5]);
    i = i + 4;
    */
  }
    
  
  while(1){
  int Index, mode;
  fscanf(stdin, "%d %d", &Index, &mode);
  print_student(mode, students[Index]);
}
  // Final loop to clean up memory
  /*
  for (int j = 0; j < i; j++) {
  if (students[j] != NULL) {
    free(students[j]);
}
}
*/

 return 0;
}

