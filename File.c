#include"File.h"

FILE* OpenFile(const char* link, const char* mode){
  return fopen(link, mode);
}

int ReadFileNumber(const char* link, const char* delim, int* data){
  FILE* opf;
  char* content;
  int i = 0;

  opf = OpenFile(link, "r");
  if(opf == NULL){
    puts("Not open file!");
  }
  else{
    char* tmp;

    content = (char*)malloc(BUFFER);
    content = fgets(content, BUFFER, opf);
    tmp = strtok(content, delim);

    while(tmp != NULL){
      *(data + i) = atoi(tmp);
      tmp = strtok(NULL, delim);
      i++;
    }

    free(content);
    fclose(opf);
  }

  return i;
}

void ReadFile(const char* link){
  FILE* opf = OpenFile(link, "r");
  int c;

  if(opf != NULL){
    while((c = fgetc(opf)) != EOF){
      putchar(c);
    }
    fclose(opf);
  }
  else{
    puts("Cann't open file!");
  }
}

void ReadFiled4KB(const char* link){
  FILE* opf = OpenFile(link, "r");
  char* content = (char*)malloc(BUFFER);

  while((content = fgets(content, BUFFER, opf)) != NULL){
    fputs(content, stdout);
  }
}

int GetSizeFile(const char* link){
  int size = -1;
  FILE* opf = OpenFile(link, "r");

  if(opf != NULL){
    fseek(opf, 0, SEEK_END);
    size = ftell(opf);
    fseek(opf, 0, SEEK_SET);
    fclose(opf);
  }
  else{
    puts("Cann't open file!");
  }

  return size;
}

#ifdef __linux
int GetSizeFileLinux(const char* link){
  int size = -1;
  FILE* opf = OpenFile(link, "r");

  if(opf != NULL){
    struct stat st;
    stat(link, &st);
    size = st.st_size;
    fclose(opf);
  }
  else{
    puts("File isn't exist");
  }

  return size;
}
#endif

void WriteFile(const char* link, const char* mode){
  char* content = (char*)malloc(BUFFER);
  FILE* opf = OpenFile(link, mode);

  if(opf != NULL){
    while(TRUE){
      if(WriteContent(content)){
        fputs(content, opf);
      }
      else{
        puts("jk inserted!");
        break;
      }
    }
  }
  else{
    fputs("Cann't open file!", stdout);
  }
}

void WriteMethod(const char* link){
  int choose;
  char* mode = (char*)malloc(5);
  char* content = (char*)malloc(BUFFER);

  puts("\t1. Clear content and write. \n\t2. Write append content file.");
  printf("You're choose:");
  fflush(stdin);
  scanf("%d", &choose);
  switch(choose){
    case 1: mode = "w+";
            WriteFile(link, mode);
            break;
    case 2: mode = "a+";
            WriteFile(link, mode);
            break;
    default:
            puts("Number not recognize!");
            break;
  }

  free(mode);
  free(content);
}

int WriteContent(char* content){
  char* tmp = (char*)malloc(BUFFER);
  char* condition = (char*)malloc(4);

  condition[0] = 'j';
  condition[1] = 'k';
  condition[2] = '\n';
  condition[3] = '\0';

  fflush(stdin);
  fgets(tmp, BUFFER, stdin);
  if(strlen(tmp) == 3){
    if(strcmp(tmp, condition) == 0){
      free(condition);
      return FALSE;
    }
  }

  strcpy(content, tmp);
  free(condition);
  free(tmp);

  return TRUE;
}

int DeleteFile(const char* link){
  FILE* opf = OpenFile(link, "r");
  if(opf == NULL){
    puts("File don't exist!");
    return FALSE;
  }
  else{
    remove(link);
  }

  return TRUE;
}

int CopyFile(const char* destination, const char* source){
  FILE* src, *dst;

  if(strcmp(destination, source) == 0){
    return FALSE;
  }
  //continue, create new file(destination) = source + copy

  src = OpenFile(source, "r+");
  dst = OpenFile(destination, "w+");
  if(src == NULL){
    fprintf(stderr, "%s don't exist", source);
    return FALSE;
  }

  if(dst == NULL){
    fprintf(stdout, "%s cann't open file!", destination);
    return FALSE;
  }

  if(GetSizeFile(source) >= BUFFER){
    char* cnt = (char*)malloc(BUFFER);

    if(cnt == NULL){
      return FALSE;
    }

    while((cnt = fgets(cnt, BUFFER, src)) != NULL){
      fputs(cnt, dst);
    }

    free(cnt);
  }
  else{
    int c;
    while((c = fgetc(src)) != EOF){
      fputc(c, dst);
    }
  }

  return TRUE;
}
