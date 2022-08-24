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
    std::string CurrenntTime();

    private:
        char goToTheNextLine();
        std::string removeNextLineCharacter(std::string stringToFix);
        std::mutex mlocker;
        std::ofstream mloggerFile;
        std::string mFileName;

};

std::string Logger::removeNextLineCharacter(std::string stringToFix){
    *(stringToFix.end()-1) = ' ';
    return stringToFix;
}

std::string Logger::CurrenntTime(){
    time_t now = time(NULL);
    char* timeNow = ctime(&now);
    return removeNextLineCharacter(std::string(timeNow));
}
char Logger::goToTheNextLine(){
    return '\n';
}

void Logger::logMessage(std::string message){
    std::scoped_lock lockMessage(mlocker);
    std::string finalMessage = CurrenntTime() + message + goToTheNextLine();
    mloggerFile.open(mFileName,std::ios_base::app);
    mloggerFile.write(finalMessage.data(),finalMessage.size());
    mloggerFile.close();
}


