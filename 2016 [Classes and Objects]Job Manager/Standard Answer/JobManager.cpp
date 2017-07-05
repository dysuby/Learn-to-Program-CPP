#include <iostream>
#include <algorithm>
#include "JobManager.h"

using namespace std;

JobManager* JobManager::instance = NULL;

JobManager* JobManager::getInstance() {
    if (instance == NULL) {
        instance = new JobManager();
    }
    return instance;
}

bool JobManager::deleteInstance() {
    if (instance == NULL) return false;
    delete instance;
    instance = NULL;
    return true;
}

JobManager::JobManager() {
    jobFrontPointer = NULL;
}

JobManager::~JobManager() {
    clear();
}

void JobManager::addJob(int priority) {
    Job *tempPointer = jobFrontPointer;
    if (tempPointer == NULL) {
        jobFrontPointer = new Job(priority);
        return;
    }
    while (tempPointer->getNext() != NULL) {
        tempPointer = tempPointer->getNext();
    }
    tempPointer->setNext(new Job(priority));
}

void JobManager::finishOneJob() {
    if (jobFrontPointer == NULL) return;

    Job *tempPointer = jobFrontPointer;
    jobFrontPointer = jobFrontPointer->getNext();
    delete tempPointer;
}

// user-defined compare function..
bool cmp(Job *job1, Job *job2) {
    if (job1->getPriority() > job2->getPriority()) return true;
    if (job1->getPriority() < job2->getPriority()) return false;
    return (job1->getId() < job2->getId());
}

// sort each job according to their priority, descending..
void JobManager::sortJob() {
    // if no or one item in queue, no need to sort it..
    if (jobFrontPointer == NULL || jobFrontPointer->getNext() == NULL) return;

    int nums = getNumOfJob(), i = 0;
    Job *array[nums];
    Job *flagPointer = jobFrontPointer;
    // store each job in array..
    while (flagPointer != NULL) {
        array[i++] = flagPointer;
        flagPointer = flagPointer->getNext();
    }
    // sort each job..
    sort(array, array + nums, cmp);

    array[nums - 1]->setNext(NULL);

    jobFrontPointer = array[0];
    flagPointer = jobFrontPointer;
    for (i = 1; i < nums; i++) {
        flagPointer->setNext(array[i]);
        flagPointer = flagPointer->getNext();
    }
}

void JobManager::printJob() {
    if (jobFrontPointer == NULL) {
        cout << "empty!" << endl;
        return;
    }
    cout << jobFrontPointer->toString();
    Job *tempPointer = jobFrontPointer->getNext();
    while (tempPointer != NULL) {
        cout << "->" << tempPointer->toString();
        tempPointer = tempPointer->getNext();
    }
    cout << endl;
}

int JobManager::getNumOfJob() {
    int num = 0;
    if (jobFrontPointer == NULL) return num;

    Job *tempPointer = jobFrontPointer;
    while (tempPointer->getNext() != NULL) {
        tempPointer = tempPointer->getNext();
        num++;
    }
    num++;
    return num;
}

void JobManager::clear() {
    while (jobFrontPointer) {
        finishOneJob();
    }
}

