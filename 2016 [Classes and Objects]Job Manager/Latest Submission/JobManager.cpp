 #include "JobManager.h"
using namespace std;
JobManager* JobManager::instance = NULL;
JobManager* JobManager::getInstance() {
  if (!instance)
    instance = new JobManager;
  return instance;
}
bool JobManager::deleteInstance() {
  if (!instance)
    return false;
  else {
    instance -> ~JobManager();
    delete instance;
    instance = NULL;
  }
  return true;
}
JobManager::~JobManager() {
  clear();
}
JobManager::JobManager() {
  jobFrontPointer = NULL;
}
void JobManager::addJob(int priority) {
  if (!jobFrontPointer) {
    jobFrontPointer = new Job(priority);
  } else {
    Job *ptr = jobFrontPointer;
    while (ptr -> getNext()) {
      ptr = ptr -> getNext();
    }
    Job *newjob = new Job(priority);
    ptr -> setNext(newjob);
  }
}
void JobManager::finishOneJob() {
  if (jobFrontPointer) {
    Job *ptr = jobFrontPointer;
    jobFrontPointer = jobFrontPointer -> getNext();
    delete ptr;
  }
}
void sort(Job *ptr, Job *next) {
  int temp = ptr -> getPriority();
  ptr -> setPriority(next -> getPriority());
  next -> setPriority(temp);
  temp = ptr -> getId();
  ptr -> setId(next -> getId());
  next -> setId(temp);
}
void JobManager::sortJob() {
  for (Job *ptr = jobFrontPointer; ptr; ptr = ptr -> getNext()) {
    for (Job *next = ptr -> getNext(); next; next = next -> getNext()) {
      if (ptr -> getPriority() < next -> getPriority()) {
        sort(ptr, next);
      } else if (ptr -> getId() > next -> getId()) {
        sort(ptr, next);
      }
    }
  }
}
void JobManager::printJob() {
  Job *ptr = jobFrontPointer;
  if (!ptr)
    cout << "empty!";
  while (ptr) {
    cout << ptr -> toString();
    ptr = ptr -> getNext();
    cout << (ptr ? "->" : "");
  }
  cout << endl;
}
int JobManager::getNumOfJob() {
  int index = 0;
  Job *ptr = jobFrontPointer;
  while (ptr && ptr -> getNext()) {
    ptr = ptr -> getNext();
    ++index;
  }
  return jobFrontPointer ? (index + 1) : 0;
}
void JobManager::clear() {
  if (jobFrontPointer) {
    Job *ptr = jobFrontPointer;
    Job *next = ptr;
    while (ptr) {
      next = ptr -> getNext();
      delete ptr;
      ptr = next;
    }
  }
  jobFrontPointer = NULL;
}