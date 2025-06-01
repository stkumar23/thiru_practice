// Sample systemd service program
// Service to log a message to a file at every 10 seconds
// Create an executable for this program
// Create a service file like below and copy it in /lib/systemd/system
// Use the service file (simpleservice.service) from this repo
// Run the below commands to start the service
//    sudo systemctl daemon-reload
//    sudo systemctl enable simpleservice.service
//    sudo systemctl start simpleservice.service

#include <iostream>
#include <chrono>
#include <thread>
#include <fstream>

void createAndUpdateLog() {
  std::ofstream logfile("/tmp/simpleservice.log", std::ios::app);
  if (!logfile.is_open()) {
    std::cerr << " Could not open sample service log file" <<std::endl;
    return;
  }

  const auto now = std::chrono::system_clock::now();
  const std::time_t currenttime = std::chrono::system_clock::to_time_t(now);
  logfile << "Simple Service ran on " << std::ctime(&currenttime) << std::endl;
}

// main
int main()
{
  while (true) {
    createAndUpdateLog();
    std::this_thread::sleep_for(std::chrono::seconds(10));
  }
  return 0;
}
