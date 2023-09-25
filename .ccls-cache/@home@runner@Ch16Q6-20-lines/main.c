// Program to print a file to the terminal twenty lines at a time

#include <stdio.h>
#include <stdbool.h>

int main(void) {

  const int numLines = 2;
  const int lineLength = 64;
  char name[lineLength];
  FILE *namePtr;
  
  // Get file name from the terminal
  printf ("Enter the name of the file to print: ");
  scanf ("%63s", name);

  // Open file
  if ( (namePtr = fopen (name, "r")) == NULL) {
    printf ("Can't open %s for reading\n", name);
    return 1;
  }

  // Print lines
  bool isFeof = false;
  while (!isFeof) {
    
    if (getchar() == 'q') // Cannot get input without writing char/space to stdout
      break;

    for (int i = 0; i < numLines; i++) {
      char temp[lineLength];
      fgets (temp, lineLength, namePtr);
      fputs (temp, stdout);

      if (feof(namePtr)) {
        fputc('\n', stdout);
        isFeof = true;
        break;
      } 
    }
  }
  
  return 0;
}