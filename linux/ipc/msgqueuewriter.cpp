/* Linux Inter Process Communication - Message Queue
  msgqueuewriter. Use this program with msgqueuereader.
  Compile using: -lrt

  Author: Thiru
*/

#include <iostream>
#include <mqueue.h>
#include <string>
#include <fcntl.h>
#include <sys/stat.h>

int main() {
    // Create or open a message queue
    mqd_t mq = mq_open("/my_msgqueue", O_CREAT | O_WRONLY, 0644, nullptr);
    if (mq == (mqd_t)-1) {
        std::cout<<"Could not open message queue"<<std::endl;
        return 1;
    }

    // Send a message
    std::string message = "Hello message from writer!";
    if (mq_send(mq, message.c_str(), message.length() + 1, 0) == -1) {
        std::cout<<"Could not send msg - mq_send"<<std::endl;
        mq_close(mq);
        return 2;
    }

    std::cout << "Message sent successfully." << std::endl;

    // Close the msg queue
    mq_close(mq);

    return 0;
}
