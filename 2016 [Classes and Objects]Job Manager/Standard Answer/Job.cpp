#include<iostream>
#include<sstream>
#include "Job.h"
/*
 * definition for class Job..
 */
int Job::number = 0;

Job::Job(int priority) {
    nextJob = NULL;
    this->priority = priority;
    id = number++;
}

void Job::setId(int id) {
    this->id = id;
}

int Job::getId() const {
    return id;
}

void Job::setPriority(int priority) {
    this->priority = priority;
}

int Job::getPriority() const {
    return priority;
}

void Job::setNext(Job *job) {
    nextJob = job;
}

Job* Job::getNext() const {
    return nextJob;
}

string Job::toString() {
    stringstream ss;
    ss << "[" << id << ":" << priority << "]";
    return ss.str();
}

