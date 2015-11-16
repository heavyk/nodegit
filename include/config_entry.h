#ifndef GITCONFIGENTRY_H
#define GITCONFIGENTRY_H
// generated from class_header.h
#include <nan.h>
#include <string>
#include <queue>

extern "C" {
#include <git2.h>
}


using namespace node;
using namespace v8;

class GitConfigEntry : public Nan::ObjectWrap {
  public:

    static Nan::Persistent<Function> constructor_template;
    static void InitializeComponent (Local<v8::Object> target);

    git_config_entry *GetValue();
    git_config_entry **GetRefValue();
    void ClearValue();

    static Local<v8::Value> New(void *raw, bool selfFreeing);
    bool selfFreeing;

 

  private:


    GitConfigEntry(git_config_entry *raw, bool selfFreeing);
    ~GitConfigEntry();
 
    static NAN_METHOD(JSNewFunction);

    static NAN_METHOD(Name);
    static NAN_METHOD(Value);
    static NAN_METHOD(Level);
    git_config_entry *raw;
};

#endif
