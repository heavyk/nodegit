#ifndef GITREFLOGENTRY_H
#define GITREFLOGENTRY_H
// generated from class_header.h
#include <nan.h>
#include <string>
#include <queue>

extern "C" {
#include <git2.h>
}

// Forward declaration.
struct git_reflog_entry {
};

using namespace node;
using namespace v8;

class GitReflogEntry : public Nan::ObjectWrap {
  public:

    static Nan::Persistent<Function> constructor_template;
    static void InitializeComponent (Local<v8::Object> target);

    git_reflog_entry *GetValue();
    git_reflog_entry **GetRefValue();
    void ClearValue();

    static Local<v8::Value> New(void *raw, bool selfFreeing);
    bool selfFreeing;

 

  private:


    GitReflogEntry(git_reflog_entry *raw, bool selfFreeing);
    ~GitReflogEntry();
 
    static NAN_METHOD(JSNewFunction);

    git_reflog_entry *raw;
};

#endif
