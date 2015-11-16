#ifndef GITERROR_H
#define GITERROR_H
// generated from class_header.h
#include <nan.h>
#include <string>
#include <queue>

extern "C" {
#include <git2.h>
}


using namespace node;
using namespace v8;

class GitError : public Nan::ObjectWrap {
  public:

    static Nan::Persistent<Function> constructor_template;
    static void InitializeComponent (Local<v8::Object> target);

    git_error *GetValue();
    git_error **GetRefValue();
    void ClearValue();

    static Local<v8::Value> New(void *raw, bool selfFreeing);
    bool selfFreeing;

 

  private:


    GitError(git_error *raw, bool selfFreeing);
    ~GitError();
 
    static NAN_METHOD(JSNewFunction);

    static NAN_METHOD(Message);
    static NAN_METHOD(Klass);
    git_error *raw;
};

#endif
