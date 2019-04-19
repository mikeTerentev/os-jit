//
// Created by Михаил Терентьев on 2019-04-18.
//

#ifndef OS_JIT_FUNCHANDLER_H
#define OS_JIT_FUNCHANDLER_H


#include <cstring>

class funcHandler {
public:
    explicit funcHandler(const unsigned char* code, size_t sz);
    ~funcHandler();
    void modifyAccess();
    int apply(int arg);
private:
    size_t commandsLength;
    void * mmapedFunc;
    bool allocationCorrectness  = true;
};


#endif //OS_JIT_FUNCHANDLER_H
