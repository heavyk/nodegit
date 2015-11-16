#ifndef GITTRANSACTION_H
#define GITTRANSACTION_H
// generated from class_header.h
#include <nan.h>
#include <string>
#include <queue>

extern "C" {
#include <git2.h>
}

// Forward declaration.
struct git_transaction {
};

using namespace node;
using namespace v8;

class GitTransaction : public Nan::ObjectWrap {
  public:

    static Nan::Persistent<Function> constructor_template;
    static void InitializeComponent (Local<v8::Object> target);

    git_transaction *GetValue();
    git_transaction **GetRefValue();
    void ClearValue();

    static Local<v8::Value> New(void *raw, bool selfFreeing);
    bool selfFreeing;

 

  private:


    GitTransaction(git_transaction *raw, bool selfFreeing);
    ~GitTransaction();
 
    static NAN_METHOD(JSNewFunction);

    git_transaction *raw;
};

#endif
