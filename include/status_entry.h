#ifndef GITSTATUSENTRY_H
#define GITSTATUSENTRY_H
// generated from class_header.h
#include <nan.h>
#include <string>
#include <queue>

extern "C" {
#include <git2.h>
}

#include "../include/diff_delta.h"

using namespace node;
using namespace v8;

class GitStatusEntry : public Nan::ObjectWrap {
  public:

    static Nan::Persistent<Function> constructor_template;
    static void InitializeComponent (Local<v8::Object> target);

    git_status_entry *GetValue();
    git_status_entry **GetRefValue();
    void ClearValue();

    static Local<v8::Value> New(void *raw, bool selfFreeing);
    bool selfFreeing;

 

  private:


    GitStatusEntry(git_status_entry *raw, bool selfFreeing);
    ~GitStatusEntry();
 
    static NAN_METHOD(JSNewFunction);

    static NAN_METHOD(Status);
    static NAN_METHOD(HeadToIndex);
    static NAN_METHOD(IndexToWorkdir);
    git_status_entry *raw;
};

#endif
