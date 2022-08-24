#include <mutex>
#include <thread>
#include <fstream>
#include <filesystem>
#include <ctime>
#include <chrono>


//one global object of Logger
class Logger{
    public:
    Logger(const std::string fileName) : mFileName(fileName.c_str()){

    }
    void logMessage(std::string message);
    std::string CurrenntTime()const;

    private:
        std::mutex mlocker;
        std::ofstream mloggerFile;
        std::string mFileName;

};

std::string Logger::CurrenntTime()const{
    time_t now = 0;
    char* timeNow = ctime(&now);
    std::string convertedToString(timeNow);
    *(convertedToString.end()-1) = ' '; //removing next line character
    return convertedToString;

}

void Logger::logMessage(std::string message){
    std::scoped_lock lockMessage(mlocker);

    //getting the time:


    message += '\n';
    mloggerFile.open(mFileName,std::ios_base::app);
    mloggerFile.write(message.data(),message.size());
    mloggerFile.close();
}
