#include <iostream>
#include <deque>

const int UNDEFINED = 2000000000;

typedef struct {
    int value;
    int currentStackMinimal;
} StackPair;


void addElementBack(std::deque<StackPair> &selfStruct, int newNumber) {
    StackPair newPair;
    if (selfStruct.size() == 0 || newNumber <= selfStruct.back().currentStackMinimal) {
        newPair = {newNumber, newNumber};
    }
    else if (newNumber > selfStruct.back().currentStackMinimal) {
        newPair = {newNumber, selfStruct.back().currentStackMinimal};
    }
    selfStruct.push_back(newPair);
}


void answerRequest(std::deque<StackPair> &stackMinimal) {
    int mode;
    std::cin >> mode;
    if (mode == 1) {
        int newElement;
        std::cin >> newElement;
        addElementBack(stackMinimal, newElement);
    }
    else if (mode == 2) {
        stackMinimal.pop_back();
    }
    else if (mode == 3) {
        std::cout << stackMinimal.back().currentStackMinimal << std::endl;
        std::cout.flush();
    }
}


int main() {
    std::deque<StackPair> stackMinimal;
    int requestsCnt;
    std::cin >> requestsCnt;
    for (int req_id = 0; req_id < requestsCnt; req_id++) {
        answerRequest(stackMinimal);
    }

    return 0;
}
