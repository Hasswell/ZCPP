#include <mutex>
#include <thread>
#include <fstream>
#include <filesystem>


//one global object of Logger
class Logger{
    public:
    Logger(const std::string fileName) : mFileName(fileName.c_str()){

    }
    void logMessage(std::string message);


    private:
        std::mutex mlocker;
        std::ofstream mloggerFile;
        std::string mFileName;

};


void Logger::logMessage(std::string message){
    std::scoped_lock lockMessage(mlocker);
    message += '\n';
    mloggerFile.open(mFileName,std::ios_base::app);
    mloggerFile.write(message.data(),message.size());
    mloggerFile.close();
}
