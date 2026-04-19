#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

void mycp(){
    char srcName[100], destName[100];
    printf("Enter Source file: ");
    scanf("%s", srcName);
    printf("Enter Destination file: ");
    scanf("%s", destName);

    int src = open(srcName, O_RDONLY);
    if(src < 0){
        printf("Error opening source file\n");
        return;
    }

    int dest = open(destName, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if(dest < 0){
        printf("Error opening destination file\n");
        return;
    }

    char buffer[1024];
    int bytes;

    while((bytes = read(src, buffer, sizeof(buffer))) > 0){
        write(dest, buffer, bytes);
    }

    close(src);
    close(dest);
}

void mergefiles(){
    char f1name[100], f2name[100];

    printf("Enter file1 (destination): ");
    scanf("%s", f1name);
    printf("Enter file2 (source): ");
    scanf("%s", f2name);

    int f1 = open(f1name, O_WRONLY | O_APPEND | O_CREAT, 0644);
    int f2 = open(f2name, O_RDONLY);

    if(f1 < 0 || f2 < 0){
        printf("Error opening files\n");
        return;
    }

    char buffer[1024];
    int bytes;

    while((bytes = read(f2, buffer, sizeof(buffer))) > 0){
        write(f1, buffer, bytes);
    }

    close(f1);
    close(f2);
}
void mystat(){
    char filename[100];
    printf("Enter file name: ");
    scanf("%s", filename);

    struct stat fileStat;
    stat(filename, &fileStat);

    printf("File Size: %ld bytes\n", fileStat.st_size);
    printf("Inode Number: %ld\n", fileStat.st_ino);
    printf("Permissions: %o\n", fileStat.st_mode & 0777);
}
void mycat(){
    char filename[100];
    printf("Enter file name: ");
    scanf("%s", filename);
    
    int fd = open(filename, O_RDONLY);
    if(fd < 0){
        printf("Error opening file\n");
        return;
    }

    char buffer[1024];
    int bytes;

    while((bytes = read(fd, buffer, sizeof(buffer))) > 0){
        write(1, buffer, bytes); // 1 is for stdout
    }

    close(fd);
}
void mycount(){
    char filename[100];
    printf("Enter file name: ");
    scanf("%s", filename);

    int fd = open(filename, O_RDONLY);
    if(fd < 0){
        printf("Error opening file\n");
        return;
    }

    char ch;
    int charCount = 0, wordCount = 0;
    int inWord = 0;


    while(read(fd, &ch, 1) > 0){
        charCount++;

        if(ch == ' ' || ch == '\n' || ch == '\t'){
            inWord = 0;
        }
        else if(!inWord){
            inWord = 1;
            wordCount++;
        }
    }

    printf("Characters: %d\n", charCount);
    printf("Words: %d\n", wordCount);

    close(fd);
}
int main(){
    while(1){
        printf("FILE MANAGER\n");
        printf("1. Copying a file to another file\n");
        printf("2. Merging of file f2 with file f1\n");
        printf("3. Display info of a file\n");
        printf("4. Display contents of a file\n");
        printf("5. Counting number of words & characters in a file\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        
        int n;
        scanf("%d", &n);
    
        switch(n){
            case 1: mycp(); break;
            case 2: mergefiles(); break;
            case 3: mystat(); break;
            case 4: mycat(); break;
            case 5: mycount(); break;
            case 6: return 0;
            default: printf("Invalid Input\n"); break;
        }
    }
    return 0;
}