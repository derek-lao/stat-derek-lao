#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>
#include <time.h>

int main()
{
  struct stat file;
  stat("HelloWorld.txt", &file);//this file contains 12 characters
  int bytes = file.st_size;

  printf("size(bytes): %d\n", file.st_size);
  printf("mode: %o\n", file.st_mode);
  printf("time: %s\n", ctime(&file.st_mtime));

  return 0;
}
