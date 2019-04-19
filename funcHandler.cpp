//
// Created by Михаил Терентьев on 2019-04-18.
//

#include "funcHandler.h"
#include <unistd.h>
#include <sys/mman.h>
#include <iostream>

using namespace std;
funcHandler::funcHandler(const unsigned char* code, size_t sz) {
    this->commandsLength = sz;
    this->mmapedFunc = mmap(nullptr, sz, PROT_WRITE | PROT_READ,MAP_PRIVATE | MAP_ANONYMOUS, -1 ,0);
    if (this->mmapedFunc == MAP_FAILED) {
        cerr << "Allocation error: error caused in allocating memory" << strerror(errno) << endl;
        allocationCorrectness = false;
        return;
    }
    memcpy(this->mmapedFunc, code, sz);
    modifyAccess();

}

funcHandler::~funcHandler(){
    munmap(this->mmapedFunc,this->commandsLength);
}

void funcHandler::modifyAccess() {
    if (mprotect(this->mmapedFunc, this->commandsLength , PROT_READ | PROT_EXEC) == -1) {
        cerr << "Can't change access to executable: " << strerror(errno) <<endl;
    }
}
int funcHandler::apply(int arg){
    if(arg == 0){
        throw runtime_error("Opppsss division by zero is outlaw");
    } else{
        return ((int (*)(int))this->mmapedFunc)(arg);
    }

}