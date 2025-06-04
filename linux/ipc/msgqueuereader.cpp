/* Linux Inter Process Communication - Message Queue
  msgqueuereader. Use this program with msgqueuewriter.
  Compile using: -lrt

  Author: Thiru
*/

#include <iostream>
#include <mqueue.h>
#include <string>
#include <fcntl.h>
#include <sys/stat.h>

int main() {
    // Open the message queue
    mqd_t mq = mq_open("/my_msgqueue", O_RDONLY);
    if (mq == (mqd_t)-1) {
        std::cout<<"Could not open message queue"<<std::endl;
        return 1;
    }

    // Receive a message
    char buffer[8192];
    ssize_t bytes_read = mq_receive(mq, buffer, sizeof(buffer), nullptr);
    if (bytes_read == -1) {
        std::cout<<"Could not read msg from message queue - mq_receive"<<std::endl;
        mq_close(mq);
        return 2;
    }

    std::cout << "Received message: " << buffer << std::endl;

    // Close and unlink the message queue
    mq_close(mq);
    mq_unlink("/test_msgqueue");

    return 0;
}