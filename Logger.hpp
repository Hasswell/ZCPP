#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <mutex>
#include <thread>
#include <fstream>
#include <filesystem>
#include <ctime>
#include <chrono>


//one global object of Logger
template<typename T>
class Logger{
    public:
    Logger(const T fileName) : mFileName(fileName.c_str()){

    }
    void logMessage(T message);
    T CurrenntTime();

    private:
        char goToTheNextLine();
        T removeNextLineCharacter(T stringToFix);
        std::mutex mlocker;
        std::ofstream mloggerFile;
        T mFileName;

};

template<typename T>
T Logger<T>::removeNextLineCharacter(T stringToFix){
    *(stringToFix.end()-1) = ' ';
    return stringToFix;
}
template<typename T>
T Logger<T>::CurrenntTime(){
    time_t now = time(NULL);
    char* timeNow = ctime(&now);
    return removeNextLineCharacter(std::string(timeNow));
}

template<typename T>
char Logger<T>::goToTheNextLine(){
    return '\n';
}

template<typename T>
void Logger<T>::logMessage(T message){
    std::scoped_lock lockMessage(mlocker);
    std::string finalMessage = CurrenntTime() + message + goToTheNextLine();
    mloggerFile.open(mFileName,std::ios_base::app);
    mloggerFile.write(finalMessage.data(),finalMessage.size());
    mloggerFile.close();
}

std::string removeNextLineCharacter(std::string stringToFix){
    *(stringToFix.end()-1) = ' ';
    return stringToFix;
}

std::string CurrenntTime(){
    time_t now = time(NULL);
    char* timeNow = ctime(&now);
    return removeNextLineCharacter(std::string(timeNow));
}

char goToTheNextLine(){
    return '\n';
}

void logMessage(std::string message){
    std::ofstream mloggerFile;
    std::string finalMessage = CurrenntTime() + message + goToTheNextLine();
    mloggerFile.open("Logs_temp.txt",std::ios_base::app);
    mloggerFile.write(finalMessage.data(),finalMessage.size());
    mloggerFile.close();
}


#endif