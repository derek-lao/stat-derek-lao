#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>
#include <time.h>

int main()
{
  struct stat file;
  stat("HelloWorld.txt", &file);
  int bytes = file.st_size;

  printf("size(bytes): %d\n", file.st_size);
  printf("mode: %o\n", file.st_mode);
  printf("time: %s\n", ctime(&file.st_mtime));

  printf("size(kilobytes): %f\n", ((double) bytes)/((double)1024));
  printf("size(megabytes): %f\n", ((double) bytes)/((double)1048576));
  printf("size(gigabytes): %f\n", ((double) bytes)/((double)1073741824));

  mode_t permissions = file.st_mode - 0100000;
  printf("permissions:\n");

  int permissionsArray[3];
  permissionsArray[0] = permissions % 010;
  permissionsArray[1] = (permissions % 0100) / 010;
  permissionsArray[2] = permissions / 0100;
  int index;

  for(index = 2 ; index >= 0 ; index --)
  {
    if(permissionsArray[index] - 4 >= 0)
    {
      printf("r");
      permissionsArray[index] -= 4;
    }
    else
    printf("-");

    if(permissionsArray[index] - 2 >= 0)
    {
      printf("w");
      permissionsArray[index] -= 2;
    }
    else
    printf("-");

    if(permissionsArray[index] - 1 >= 0)
    {
      printf("x");
      permissionsArray[index] -= 1;
    }
    else
    printf("-");
  }

  printf("\n");


  return 0;
}
