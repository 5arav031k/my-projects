#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

#include "erproc.h"

int main() {
    int fd = Socket(AF_INET, SOCK_STREAM, 0);
    
    struct sockaddr_in adr = {0};
    adr.sin_family = AF_INET;
    adr.sin_port = htons(34543);
    Inet_pton(AF_INET, "127.0.0.1", &adr.sin_addr);
    
    Connect(fd, (struct sockaddr *) &adr, sizeof(adr));
    while (1) {
        char text[256];
        fgets(text, sizeof(text), stdin);
        size_t length = strlen(text);
        write(fd, text, length);
    }
    close(fd);
    return 0;
}