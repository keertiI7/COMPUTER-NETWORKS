#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>   // for sleep()
#include <time.h>

#define BUCKET_SIZE 512

int main() {
    int outputRate, packetSize;
    srand(time(0));  // random number seed

    printf("Enter output rate: ");
    scanf("%d", &outputRate);

    // Simulate 5 incoming packets
    for (int i = 1; i <= 5; i++) {
        sleep(rand() % 2);  // random delay before each packet
        packetSize = rand() % 1000;  // random packet size

        printf("\nPacket %d -> Size: %d bytes", i, packetSize);

        if (packetSize > BUCKET_SIZE) {
            printf("\n\tBucket overflow! Packet discarded.\n");
            continue;
        }

        printf("\n\tProcessing packet...");
        while (packetSize > 0) {
            if (packetSize >= outputRate) {
                printf("\n\t%d bytes sent.", outputRate);
                packetSize -= outputRate;
            } else {
                printf("\n\tLast %d bytes sent.", packetSize);
                packetSize = 0;
            }
            sleep(1);  // simulate delay
        }

        printf("\n\tBucket output successful!\n");
    }

    return 0;
}
