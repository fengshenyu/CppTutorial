#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <netinet/in.h>

void print_flags(struct addrinfo *aip) {
    printf("flags");
    if (aip->ai_flags == 0) {
        printf(" 0");
    } else {
        if (aip->ai_flags & AI_PASSIVE) {
            printf(" passive");
        }
        if (aip->ai_flags & AI_CANONNAME) {
            printf(" canon");
        }
        if (aip->ai_flags & AI_NUMERICHOST) {
            printf(" numhost");
        }
        if (aip->ai_flags & AI_NUMERICSERV) {
            printf(" numserv");
        }
        if (aip->ai_flags & AI_V4MAPPED) {
            printf(" v4mapped");
        }
        if (aip->ai_flags & AI_ALL) {
            printf(" all");
        }
    }
}

int main(int argc, char *argv[]) {
    struct addrinfo *ailist, *aip;//addrinfo defined in netdb.h
    struct addrinfo hint;
    struct sockaddr_in *sinp;
    const char *addr;
    int err;
    char abuf[INET_ADDRSTRLEN];//INET_ADDRSTRLEN defined in netinet/in.h
    if (argc != 3) {
        printf("usage: %s nodename service", argv[0]);
        exit(0);
    }
    hint.ai_flags = AI_CANONNAME;
    hint.ai_family = 0;
    hint.ai_socktype = 0;
    hint.ai_protocol = 0;
    hint.ai_addrlen = 0;
    hint.ai_canonname = NULL;
    hint.ai_addr = NULL;
    hint.ai_next = NULL;
    if ((err = getaddrinfo(argv[1], argv[2], &hint, &ailist)) != 0) {
        printf("getaddrinfo error:%s\n", gai_strerror(err));
    }
    for (aip = ailist; aip != NULL; aip = aip->ai_next) {
        print_flags(aip);
        printf("\n");
    }
    printf("\nend\n");
    return 0;
}
