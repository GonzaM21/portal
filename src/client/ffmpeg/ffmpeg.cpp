#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <unistd.h>
#include <cstdio>
#include "ffmpeg.h"

std::string getNUmberFile(){
}

std::string getinfo(){
    std::ifstream resolution_arch("resolution.txt");
    std::string text;
    std::string info("0");
    size_t i = 0;
    while (std::getline(resolution_arch,text)){
        if(text.length() !=  0) info = text;
    }
    return info;
}

void savedFIle(int fileNmber){
    std::ofstream out_file;
    out_file.open("resolution.txt",std::ofstream::out|std::ofstream::trunc);
    out_file << fileNmber;
    out_file.close();
}


void Ffmpeg::recordScreen() {
    std::string fileCount = getinfo();
    savedFIle(0);
    system("xdpyinfo | awk '/dimensions/{print $2}' >> resolution.txt");
    std::string resolution = getinfo();
    std::string command = "ffmpeg -threads auto -f x11grab -r 30 -s " + resolution + " -i :0.0+0,0 -vcodec libx264 output"+ fileCount +".mp4";
    savedFIle(std::stol(fileCount) + 1);
    pid_t ffmpeg_process_id = fork();

    if (ffmpeg_process_id == 0) {
        system(command.c_str());
    }
}

void Ffmpeg::stopRecording() {
    //kill(ffmpeg_process_id,SIGKILL);
    system("kill -2 $(pgrep ffmpeg)");
}