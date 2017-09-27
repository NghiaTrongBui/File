#include"File.h"

int main(int argc, char* argv[]){
  const char* link = "./Argument1.txt";
  /* int* data = (int*)malloc(1024); */

  /* int n = ReadFileNumber(link, " ", data); */
  /* for(int i = 0; i < n; i++){ */
    /* printf("%d, ", data[i]); */
  /* } */

  /* WriteMethod(link); */
  /* DeleteFile("./tmp.txt"); */
  printf("%d\n", GetSizeFile("LICENSE"));

  return 0;
}
