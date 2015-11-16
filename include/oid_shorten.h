#ifndef GITOIDSHORTEN_H
#define GITOIDSHORTEN_H
// generated from class_header.h
#include <nan.h>
#include <string>
#include <queue>

extern "C" {
#include <git2.h>
}

// Forward declaration.
struct git_oid_shorten {
};

using namespace node;
using namespace v8;

class GitOidShorten : public Nan::ObjectWrap {
  public:

    static Nan::Persistent<Function> constructor_template;
    static void InitializeComponent (Local<v8::Object> target);

    git_oid_shorten *GetValue();
    git_oid_shorten **GetRefValue();
    void ClearValue();

    static Local<v8::Value> New(void *raw, bool selfFreeing);
    bool selfFreeing;

 

  private:


    GitOidShorten(git_oid_shorten *raw, bool selfFreeing);
    ~GitOidShorten();
 
    static NAN_METHOD(JSNewFunction);

    git_oid_shorten *raw;
};

#endif
